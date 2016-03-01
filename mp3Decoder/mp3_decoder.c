//
//  mp3_decoder.c
//  mp3Decoder
//
//  Created by zykhbl on 16/2/24.
//  Copyright © 2016年 zykhbl. All rights reserved.
//

//http://www.pudn.com/downloads52/sourcecode/multimedia/mpeg/detail181910.html
//http://www.codeforge.cn/read/187196/huffdec.txt__html
//http://www.jianshu.com/p/1d1f893e53e9
//http://www.cnblogs.com/gaozehua/tag/音频编码/
//http://standards.iso.org/ittf/PubliclyAvailableStandards/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "decode.h"

void writeString(FILE *f, char *buf) {
    fwrite(buf, strlen(buf), 1, f);
}

void writeInt(FILE *f, int i) {
    fwrite(&i, sizeof(i), 1, f);
}

void writeShort(FILE *f, short i) {
    fwrite(&i, sizeof(i), 1, f);
}

void writeWAVHeader(FILE *f) {
    int len = 80 * 1024 * 1024;
    short channels = 2;
    
    // 16K、16bit、单声道
    /* RIFF header */
    writeString(f, "RIFF");// riff id
    writeInt(f, len - 8);// riff chunk size *PLACEHOLDER*
    writeString(f, "WAVE");// wave type
    
    /* fmt chunk */
    writeString(f, "fmt ");// fmt id
    writeInt(f, 16);// fmt chunk size
    writeShort(f, 1);// format: 1(PCM)
    writeShort(f, channels);// channels: 1
    writeInt(f, 44100);// samples per second
    writeInt(f, (int) (channels * 44100 * (16 / 8)));// BPSecond
    writeShort(f, (short) (channels * (16 / 8)));// BPSample
    writeShort(f, (short) (16));// bPSample
    
    /* data chunk */
    writeString(f, "data");// data id
    writeInt(f, len - 44);// data chunk size *PLACEHOLDER*
}

int main(int argc, char**argv) {
    char *mp3_filename = "/Users/weidong_wu/mp3_decode/mymp3.mp3";
    char *pcm_filename = "/Users/weidong_wu/mp3_decode/mypcm.wav";
//    char *mp3_filename = "/Users/zykhbl/mp3/mymp3.mp3";
//    char *pcm_filename = "/Users/zykhbl/mp3/mypcm.wav";
    
    FILE *musicout;
    Bit_stream_struc bs;
    frame_params fr_ps;
    III_side_info_t III_side_info;
    III_scalefac_t III_scalefac;
    unsigned int old_crc;
    layer info;
    int sync, clip;
    int done = FALSE;
    unsigned long frameNum = 0;
    unsigned long bitsPerSlot;
    unsigned long sample_frames;
    
    typedef short PCM[2][SSLIMIT][SBLIMIT];
    PCM *pcm_sample;
    
    pcm_sample = (PCM *) mem_alloc((long) sizeof(PCM), "PCM Samp");
    
    if ((musicout = fopen(pcm_filename, "w+b")) == NULL) {
        printf ("Could not create \"%s\".\n", pcm_filename);
        exit(1);
    }
    
    writeWAVHeader(musicout);
    
    open_bit_stream_r(&bs, mp3_filename, BUFFER_SIZE);
    
    fr_ps.header = &info;
    
    sample_frames = 0;
    while(!end_bs(&bs)) {
        //尝试帧同步
        sync = seek_sync(&bs, SYNC_WORD, SYNC_WORD_LENGTH);
        if (!sync) {
            done = TRUE;
            printf("\nFrame cannot be located\n");
            out_fifo(*pcm_sample, 3, &fr_ps, done, musicout, &sample_frames);
            break;
        }
        //解码帧头
        decode_info(&bs, &fr_ps);
        //将fr_ps.header中的信息解读到fr_ps的相关域中
        hdr_to_frps(&fr_ps);
        //输出相关信息
        if(frameNum == 0) {
            writeHdr(&fr_ps);
        }
        
        printf("\r%05lu", frameNum++);
        
        if (info.error_protection) {
            buffer_CRC(&bs, &old_crc);
        }
        
        switch (info.lay) {
            case 3: {
                //main_data_end 可以不初始化为0，但如果不初始化，它会在使用了栈中上一次循环遗留下的值，虽然不影响结果，但是会使打印信息看起来很怪
                int nSlots, main_data_end = 0, flush_main;
                int bytes_to_discard, gr, ch, ss, sb;
                static int frame_start = 0;
                
                bitsPerSlot = 8;
                
                III_get_side_info(&bs, &III_side_info, &fr_ps);//读取Side信息
                nSlots = main_data_slots(fr_ps);//计算slot个数
                
                for (; nSlots > 0; nSlots--) {//读主数据(Audio Data)
                    hputbuf((unsigned int)getbits(&bs, 8), 8);
                }
                
                main_data_end = (int)(hsstell() / 8);//of privious frame
                if ((flush_main = (int)(hsstell() % bitsPerSlot))) {
                    hgetbits((int)(bitsPerSlot - flush_main));
                    main_data_end++;
                }
                
                bytes_to_discard = frame_start - main_data_end - III_side_info.main_data_begin;
                
                if(main_data_end > 4096) {//环结构，缓存数组从[0, 4095], 不需要>= 4096，因为hputbuf，hgetbits等操作做了求余；不用应该也可以
                    frame_start -= 4096;
                    rewindNbytes(4096);
                }
                
                frame_start += main_data_slots(fr_ps);//当前帧的结尾，同时也是下一帧的开始位置
                
                if (bytes_to_discard < 0) {//TODO: 实现为实时流读取时，可能要在这里控制暂停
                    printf("Not enough main data to decode frame %ld.  Frame discarded.\n", frameNum - 1);
                    break;
                }
                
                for (; bytes_to_discard > 0; bytes_to_discard--) {//丢弃已读或无用的的字节
                    hgetbits(8);
                }
                
                clip = 0;
                for (gr = 0; gr < 2; gr++) {
                    double lr[2][SBLIMIT][SSLIMIT],ro[2][SBLIMIT][SSLIMIT];

                    for (ch = 0; ch < fr_ps.stereo; ch++) {//主解码
                        long int is[SBLIMIT][SSLIMIT];//保存量化数据
                        int part2_start;
                        part2_start = (int)hsstell();//指针位置硬转int，缓存数组buf里的数据开始位置totbit没有增大

                        III_get_scale_factors(&III_scalefac,&III_side_info, gr, ch, &fr_ps);//获取比例因子

                        III_hufman_decode(is, &III_side_info, ch, gr, part2_start, &fr_ps);//Huffman解码

                        III_dequantize_sample(is, ro[ch], &III_scalefac, &(III_side_info.ch[ch].gr[gr]), ch, &fr_ps);//反量化采样
                    }

                    III_stereo(ro, lr, &III_scalefac, &(III_side_info.ch[0].gr[gr]), &fr_ps);//立体声处理
                    
                    for (ch = 0; ch < fr_ps.stereo; ch++) {
                        double re[SBLIMIT][SSLIMIT];
                        double hybridIn[SBLIMIT][SSLIMIT];//Hybrid filter input
                        double hybridOut[SBLIMIT][SSLIMIT];//Hybrid filter out
                        double polyPhaseIn[SBLIMIT];     //PolyPhase Input
                        
                        III_reorder(lr[ch], re, &(III_side_info.ch[ch].gr[gr]), &fr_ps);

                        III_antialias(re, hybridIn, &(III_side_info.ch[ch].gr[gr]), &fr_ps);//抗锯齿处理

                        for (sb = 0; sb < SBLIMIT; sb++) {//IMDCT(Hybrid synthesis)
                            III_hybrid(hybridIn[sb], hybridOut[sb], sb, ch, &(III_side_info.ch[ch].gr[gr]), &fr_ps);
                        }
                        
                        for (ss = 0; ss < 18;ss++) {//多相频率倒置
                            for (sb = 0; sb < SBLIMIT; sb++) {
                                if ((ss % 2) && (sb % 2)) {
                                    hybridOut[sb][ss] = -hybridOut[sb][ss];
                                }
                            }
                        }
                        
                        for (ss = 0; ss < 18; ss++) {//多相合成
                            for (sb = 0; sb < SBLIMIT; sb++) {
                                polyPhaseIn[sb] = hybridOut[sb][ss];
                            }

                            clip += SubBandSynthesis(polyPhaseIn, ch, &((*pcm_sample)[ch][ss][0]));//子带合成
                        }
                    }

                    out_fifo(*pcm_sample, 18, &fr_ps, done, musicout, &sample_frames);//PCM输出(Output PCM sample points for one granule(颗粒))
                }
                
                if(clip > 0) {
                    printf("\n%d samples clipped.\n", clip);
                }
                
                break;
            }
            default: {
                printf("\nOnly layer III supported!\n");   
                exit(1);   
                break;
            }
        }
    }
    
    close_bit_stream_r(&bs);   
    fclose(musicout);   
    printf("\nDecoding done.\n");
    
    return 0;
}

