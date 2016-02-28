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

void writeInt(FILE *f, int i) {
    fwrite(&i, sizeof(i), 1, f);
}

typedef struct {
    char riff[4];
    int riff_size;
    char wave[4];
    char fmt[4];
    int fmt_size;
    short isPcm;
    short channels;
    int samples;
    int bits;
    short re;
    short a;
    char data[4];
    int data_size;
} wav;

void add_header(FILE *f) {
    FILE *wavHeader;
    ssize_t n, m;
    char buf[40];
    if((wavHeader = fopen("/Users/zykhbl/mp3/qingyuyi.wav", "r")) < 0) {
        fprintf(stderr , "can't open file: qingyuyi.wav!\n");
        exit(-1);
    }
    
    n = fread(buf, 40, 1, wavHeader);
    if (n == 1) {
        m = fwrite(buf, 40, 1, f);
        
        if (m != 1) {
            fprintf(stderr , "write to file: test.wav error!\n");
        }
    } else {
        fprintf(stderr , "read file: qingyuyi.wav error!\n");
    };
    
    writeInt(f, 80 * 1024 * 1024);
}

#endif
