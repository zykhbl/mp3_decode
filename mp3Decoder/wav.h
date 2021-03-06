//
//  wav.h
//  mp3Decoder
//
//  Created by zykhbl on 16-2-28.
//  Copyright (c) 2016年 zykhbl. All rights reserved.
//

#ifndef mp3Decoder_wav_h
#define mp3Decoder_wav_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char    riff[4];
    int     riff_size;
    char    wave[4];
    char    fmt[4];
    int     fmt_size;
    short   format;
    short   channels;
    int     frequency;
    int     bitRate;
    short   sampling_frequency;
    short   bits;
    char    data[4];
    int     data_size;
} wav;

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
    
    //RIFF header
    writeString(f, "RIFF");//riff id
    writeInt(f, len - 8);//riff chunk size *PLACEHOLDER*
    writeString(f, "WAVE");//wave type
    
    //fmt chunk
    writeString(f, "fmt ");//fmt id
    writeInt(f, 16);//fmt chunk size
    writeShort(f, 1);//format: 1(PCM)
    writeShort(f, channels);//channels
    writeInt(f, 44100);//samples per second
    writeInt(f, (int) (channels * 44100 * (16 / 8)));//BPSecond
    writeShort(f, (short) (channels * (16 / 8)));//BPSample
    writeShort(f, (short) (16));//bPSample
    
    //data chunk
    writeString(f, "data");//data id
    writeInt(f, len - 44);//data chunk size *PLACEHOLDER*
}

#endif
