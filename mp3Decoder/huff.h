//
//  huff.h
//  mp3Decoder
//
//  Created by weidong_wu on 16/2/24.
//  Copyright © 2016年 zykhbl. All rights reserved.
//

#ifndef huff_h
#define huff_h

/* these are the huffman tables, rearranged for lookup
 */
unsigned int h0[1]={0x0};
unsigned int h1[4]={0x311, 0x20000301, 0x40000210, 0x80000100};
unsigned int h2[9]={0x622, 0x4000602, 0x8000512, 0x10000521, 0x18000520, 0x20000311, 0x40000301, 0x60000310,
    0x80000100};
unsigned int h3[9]={ 0x622, 0x4000602, 0x8000512, 0x10000521, 0x18000520, 0x20000310, 0x40000211, 0x80000201,
    0xc0000200};
unsigned int h5[16]={0x833, 0x1000823, 0x2000732, 0x4000631, 0x8000713, 0xa000703, 0xc000730, 0xe000722,
    0x10000612, 0x14000621, 0x18000602, 0x1c000620, 0x20000311, 0x40000301, 0x60000310, 0x80000100};
unsigned int h6[16]={0x733, 0x2000703, 0x4000623, 0x8000632, 0xc000630, 0x10000513, 0x18000531, 0x20000522,
    0x28000502, 0x30000412, 0x40000421, 0x50000420, 0x60000301, 0x80000211, 0xc0000310, 0xe0000300};
unsigned int h7[36]={ 0xa55, 0x400a45, 0x800a54, 0xc00a53, 0x1000935, 0x1800944, 0x2000925, 0x2800952,
    0x3000815, 0x4000851, 0x5000905, 0x5800934, 0x6000850, 0x7000943, 0x7800933, 0x8000824,
    0x9000842, 0xa000714, 0xc000741, 0xe000740, 0x10000804, 0x11000823, 0x12000832, 0x13000803,
    0x14000713, 0x16000731, 0x18000730, 0x1a000722, 0x1c000612, 0x20000521, 0x28000602, 0x2c000620,
    0x30000411, 0x40000301, 0x60000310, 0x80000100};
unsigned int h8[36]={0xb55, 0x200b54, 0x400a45, 0x800953, 0x1000a35, 0x1400a44, 0x1800925, 0x2000952,
    0x2800905, 0x3000815, 0x4000851, 0x5000934, 0x5800943, 0x6000950, 0x6800933, 0x7000824,
    0x8000842, 0x9000814, 0xa000741, 0xc000804, 0xd000840, 0xe000823, 0xf000832, 0x10000813,
    0x11000831, 0x12000803, 0x13000830, 0x14000622, 0x18000602, 0x1c000620, 0x20000412, 0x30000421,
    0x40000211, 0x80000301, 0xa0000310, 0xc0000200};
unsigned int h9[36]={ 0x955, 0x800945, 0x1000835, 0x2000853, 0x3000954, 0x3800905, 0x4000844, 0x5000825,
    0x6000852, 0x7000815, 0x8000751, 0xa000734, 0xc000743, 0xe000850, 0xf000804, 0x10000724,
    0x12000742, 0x14000733, 0x16000740, 0x18000614, 0x1c000641, 0x20000623, 0x24000632, 0x28000513,
    0x30000531, 0x38000603, 0x3c000630, 0x40000522, 0x48000502, 0x50000412, 0x60000421, 0x70000420,
    0x80000311, 0xa0000301, 0xc0000310, 0xe0000300};
unsigned int h10[64]={ 0xb77, 0x200b67, 0x400b76, 0x600b57, 0x800b75, 0xa00b66, 0xc00a47, 0x1000a74,
    0x1400a56, 0x1800a65, 0x1c00a37, 0x2000a73, 0x2400a46, 0x2800b55, 0x2a00b54, 0x2c00a63,
    0x3000927, 0x3800972, 0x4000a64, 0x4400a07, 0x4800970, 0x5000962, 0x5800a45, 0x5c00a35,
    0x6000906, 0x6800a53, 0x6c00a44, 0x7000817, 0x8000871, 0x9000936, 0x9800926, 0xa000a25,
    0xa400a52, 0xa800915, 0xb000951, 0xb800a34, 0xbc00a43, 0xc000816, 0xd000861, 0xe000860,
    0xf000905, 0xf800950, 0x10000924, 0x10800942, 0x11000933, 0x11800904, 0x12000814, 0x13000841,
    0x14000840, 0x15000823, 0x16000832, 0x17000803, 0x18000713, 0x1a000731, 0x1c000730, 0x1e000722,
    0x20000612, 0x24000621, 0x28000602, 0x2c000620, 0x30000411, 0x40000301, 0x60000310, 0x80000100};
unsigned int h11[64]={ 0xa77, 0x400a67, 0x800a76, 0xc00a75, 0x1000a66, 0x1400a47, 0x1800a74, 0x1c00b57,
    0x1e00b55, 0x2000a56, 0x2400a65, 0x2800937, 0x3000973, 0x3800946, 0x4000a45, 0x4400a54,
    0x4800a35, 0x4c00a53, 0x5000827, 0x6000872, 0x7000964, 0x7800907, 0x8000771, 0xa000817,
    0xb000870, 0xc000836, 0xd000863, 0xe000860, 0xf000944, 0xf800925, 0x10000952, 0x10800905,
    0x11000815, 0x12000762, 0x14000826, 0x15000806, 0x16000716, 0x18000761, 0x1a000851, 0x1b000834,
    0x1c000850, 0x1d000943, 0x1d800933, 0x1e000824, 0x1f000842, 0x20000814, 0x21000841, 0x22000804,
    0x23000840, 0x24000723, 0x26000732, 0x28000613, 0x2c000631, 0x30000703, 0x32000730, 0x34000622,
    0x38000521, 0x40000412, 0x50000502, 0x58000520, 0x60000311, 0x80000301, 0xa0000310, 0xc0000200};
unsigned int h12[64]={ 0xa77, 0x400a67, 0x800976, 0x1000957, 0x1800975, 0x2000966, 0x2800947, 0x3000974,
    0x3800965, 0x4000856, 0x5000837, 0x6000973, 0x6800955, 0x7000827, 0x8000872, 0x9000846,
    0xa000864, 0xb000817, 0xc000871, 0xd000907, 0xd800970, 0xe000836, 0xf000863, 0x10000845,
    0x11000854, 0x12000844, 0x13000906, 0x13800905, 0x14000726, 0x16000762, 0x18000761, 0x1a000816,
    0x1b000860, 0x1c000835, 0x1d000853, 0x1e000825, 0x1f000852, 0x20000715, 0x22000751, 0x24000734,
    0x26000743, 0x28000850, 0x29000804, 0x2a000724, 0x2c000742, 0x2e000714, 0x30000633, 0x34000641,
    0x38000623, 0x3c000632, 0x40000740, 0x42000703, 0x44000630, 0x48000513, 0x50000531, 0x58000522,
    0x60000412, 0x70000421, 0x80000502, 0x88000520, 0x90000400, 0xa0000311, 0xc0000301, 0xe0000310};
unsigned int h13[256]={
    0x13fe, 0x33fc, 0x52fd, 0x91ed, 0x110ff, 0x210ef, 0x310df, 0x410ee,
    0x510cf, 0x610de, 0x710bf, 0x810fb, 0x910ce, 0xa10dc, 0xb11af, 0xb91e9,
    0xc0fec, 0xe0fdd, 0x1010fa, 0x1110cd, 0x120fbe, 0x140feb, 0x160f9f, 0x180ff9,
    0x1a0fea, 0x1c0fbd, 0x1e0fdb, 0x200f8f, 0x220ff8, 0x240fcc, 0x2610ae, 0x27109e,
    0x280f8e, 0x2a107f, 0x2b107e, 0x2c0ef7, 0x300eda, 0x340fad, 0x360fbc, 0x380fcb,
    0x3a0ff6, 0x3c0e6f, 0x400ee8, 0x440e5f, 0x480e9d, 0x4c0ed9, 0x500ef5, 0x540ee7,
    0x580eac, 0x5c0ebb, 0x600e4f, 0x640ef4, 0x680fca, 0x6a0fe6, 0x6c0ef3, 0x700d3f,
    0x780e8d, 0x7c0ed8, 0x800d2f, 0x880df2, 0x900e6e, 0x940e9c, 0x980d0f, 0xa00ec9,
    0xa40e5e, 0xa80dab, 0xb00e7d, 0xb40ed7, 0xb80d4e, 0xc00ec8, 0xc40ed6, 0xc80d3e,
    0xd00db9, 0xd80e9b, 0xdc0eaa, 0xe00c1f, 0xf00cf1, 0x1000cf0, 0x1100dba, 0x1180de5,
    0x1200de4, 0x1280d8c, 0x1300d6d, 0x1380de3, 0x1400ce2, 0x1500d2e, 0x1580d0e, 0x1600c1e,
    0x1700ce1, 0x1800de0, 0x1880d5d, 0x1900dd5, 0x1980d7c, 0x1a00dc7, 0x1a80d4d, 0x1b00d8b,
    0x1b80db8, 0x1c00dd4, 0x1c80d9a, 0x1d00da9, 0x1d80d6c, 0x1e00cc6, 0x1f00c3d, 0x2000dd3,
    0x2080d7b, 0x2100c2d, 0x2200cd2, 0x2300c1d, 0x2400cb7, 0x2500d5c, 0x2580dc5, 0x2600d99,
    0x2680d7a, 0x2700cc3, 0x2800da7, 0x2880d97, 0x2900c4b, 0x2a00bd1, 0x2c00c0d, 0x2d00cd0,
    0x2e00c8a, 0x2f00ca8, 0x3000c4c, 0x3100cc4, 0x3200c6b, 0x3300cb6, 0x3400b3c, 0x3600b2c,
    0x3800bc2, 0x3a00b5b, 0x3c00cb5, 0x3d00c89, 0x3e00b1c, 0x4000bc1, 0x4200c98, 0x4300c0c,
    0x4400bc0, 0x4600cb4, 0x4700c6a, 0x4800ca6, 0x4900c79, 0x4a00b3b, 0x4c00bb3, 0x4e00c88,
    0x4f00c5a, 0x5000b2b, 0x5200ca5, 0x5300c69, 0x5400ba4, 0x5600c78, 0x5700c87, 0x5800b94,
    0x5a00c77, 0x5b00c76, 0x5c00ab2, 0x6000a1b, 0x6400ab1, 0x6800b0b, 0x6a00bb0, 0x6c00b96,
    0x6e00b4a, 0x7000b3a, 0x7200ba3, 0x7400b59, 0x7600b95, 0x7800a2a, 0x7c00aa2, 0x8000a1a,
    0x8400aa1, 0x8800b0a, 0x8a00b68, 0x8c00aa0, 0x9000b86, 0x9200b49, 0x9400a93, 0x9800b39,
    0x9a00b58, 0x9c00b85, 0x9e00b67, 0xa000a29, 0xa400a92, 0xa800b57, 0xaa00b75, 0xac00a38,
    0xb000a83, 0xb400b66, 0xb600b47, 0xb800b74, 0xba00b56, 0xbc00b65, 0xbe00b73, 0xc000919,
    0xc800991, 0xd000a09, 0xd400a90, 0xd800a48, 0xdc00a84, 0xe000a72, 0xe400b46, 0xe600b64,
    0xe800928, 0xf000982, 0xf800918, 0x10000a37, 0x10400a27, 0x10800917, 0x11000971, 0x11800a55,
    0x11c00a07, 0x12000a70, 0x12400a36, 0x12800a63, 0x12c00a45, 0x13000a54, 0x13400a26, 0x13800a62,
    0x13c00a35, 0x14000881, 0x15000908, 0x15800980, 0x16000916, 0x16800961, 0x17000906, 0x17800960,
    0x18000a53, 0x18400a44, 0x18800925, 0x19000952, 0x19800905, 0x1a000815, 0x1b000851, 0x1c000934,
    0x1c800943, 0x1d000950, 0x1d800924, 0x1e000942, 0x1e800933, 0x1f000814, 0x20000741, 0x22000804,
    0x23000840, 0x24000823, 0x25000832, 0x26000713, 0x28000731, 0x2a000703, 0x2c000730, 0x2e000722,
    0x30000612, 0x34000621, 0x38000602, 0x3c000620, 0x40000411, 0x50000401, 0x60000310, 0x80000100};
unsigned int h15[256]={ 0xdff, 0x80def, 0x100dfe, 0x180ddf, 0x200cee, 0x300dfd, 0x380dcf, 0x400dfc,
    0x480dde, 0x500ded, 0x580dbf, 0x600cfb, 0x700dce, 0x780dec, 0x800cdd, 0x900caf,
    0xa00cfa, 0xb00cbe, 0xc00ceb, 0xd00ccd, 0xe00cdc, 0xf00c9f, 0x1000cf9, 0x1100cea,
    0x1200cbd, 0x1300cdb, 0x1400c8f, 0x1500cf8, 0x1600ccc, 0x1700c9e, 0x1800ce9, 0x1900c7f,
    0x1a00cf7, 0x1b00cad, 0x1c00cda, 0x1d00cbc, 0x1e00c6f, 0x1f00dae, 0x1f80d0f, 0x2000bcb,
    0x2200bf6, 0x2400c8e, 0x2500ce8, 0x2600c5f, 0x2700c9d, 0x2800bf5, 0x2a00b7e, 0x2c00be7,
    0x2e00bac, 0x3000bca, 0x3200bbb, 0x3400cd9, 0x3500c8d, 0x3600b4f, 0x3800bf4, 0x3a00b3f,
    0x3c00bf3, 0x3e00bd8, 0x4000be6, 0x4200b2f, 0x4400bf2, 0x4600c6e, 0x4700cf0, 0x4800b1f,
    0x4a00bf1, 0x4c00b9c, 0x4e00bc9, 0x5000b5e, 0x5200bab, 0x5400bba, 0x5600be5, 0x5800b7d,
    0x5a00bd7, 0x5c00b4e, 0x5e00be4, 0x6000b8c, 0x6200bc8, 0x6400b3e, 0x6600b6d, 0x6800bd6,
    0x6a00be3, 0x6c00b9b, 0x6e00bb9, 0x7000b2e, 0x7200baa, 0x7400be2, 0x7600b1e, 0x7800be1,
    0x7a00c0e, 0x7b00ce0, 0x7c00b5d, 0x7e00bd5, 0x8000b7c, 0x8200bc7, 0x8400b4d, 0x8600b8b,
    0x8800ad4, 0x8c00bb8, 0x8e00b9a, 0x9000ba9, 0x9200b6c, 0x9400bc6, 0x9600b3d, 0x9800ad3,
    0x9c00ad2, 0xa000b2d, 0xa200b0d, 0xa400a1d, 0xa800a7b, 0xac00ab7, 0xb000ad1, 0xb400b5c,
    0xb600bd0, 0xb800ac5, 0xbc00a8a, 0xc000aa8, 0xc400a4c, 0xc800ac4, 0xcc00a6b, 0xd000ab6,
    0xd400b99, 0xd600b0c, 0xd800a3c, 0xdc00ac3, 0xe000a7a, 0xe400aa7, 0xe800aa6, 0xec00bc0,
    0xee00b0b, 0xf0009c2, 0xf800a2c, 0xfc00a5b, 0x10000ab5, 0x10400a1c, 0x10800a89, 0x10c00a98,
    0x11000ac1, 0x11400a4b, 0x11800ab4, 0x11c00a6a, 0x12000a3b, 0x12400a79, 0x128009b3, 0x13000a97,
    0x13400a88, 0x13800a2b, 0x13c00a5a, 0x140009b2, 0x14800aa5, 0x14c00a1b, 0x150009b1, 0x15800ab0,
    0x15c00a69, 0x16000a96, 0x16400a4a, 0x16800aa4, 0x16c00a78, 0x17000a87, 0x17400a3a, 0x178009a3,
    0x18000959, 0x18800995, 0x1900092a, 0x198009a2, 0x1a00091a, 0x1a8009a1, 0x1b000a0a, 0x1b400aa0,
    0x1b800968, 0x1c000986, 0x1c800949, 0x1d000994, 0x1d800939, 0x1e000993, 0x1e800a77, 0x1ec00a09,
    0x1f000958, 0x1f800985, 0x20000929, 0x20800967, 0x21000976, 0x21800992, 0x22000891, 0x23000919,
    0x23800990, 0x24000948, 0x24800984, 0x25000957, 0x25800975, 0x26000938, 0x26800983, 0x27000966,
    0x27800947, 0x28000828, 0x29000882, 0x2a000818, 0x2b000881, 0x2c000974, 0x2c800908, 0x2d000980,
    0x2d800956, 0x2e000965, 0x2e800937, 0x2f000973, 0x2f800946, 0x30000827, 0x31000872, 0x32000864,
    0x33000817, 0x34000855, 0x35000871, 0x36000907, 0x36800970, 0x37000836, 0x38000863, 0x39000845,
    0x3a000854, 0x3b000826, 0x3c000862, 0x3d000816, 0x3e000906, 0x3e800960, 0x3f000835, 0x40000761,
    0x42000853, 0x43000844, 0x44000725, 0x46000752, 0x48000715, 0x4a000751, 0x4c000805, 0x4d000850,
    0x4e000734, 0x50000743, 0x52000724, 0x54000742, 0x56000733, 0x58000641, 0x5c000714, 0x5e000704,
    0x60000623, 0x64000632, 0x68000740, 0x6a000703, 0x6c000613, 0x70000631, 0x74000630, 0x78000522,
    0x80000512, 0x88000521, 0x90000502, 0x98000520, 0xa0000311, 0xc0000401, 0xd0000410, 0xe0000300};
unsigned int h16[256]={ 0xbef, 0x200bfe, 0x400bdf, 0x600bfd, 0x800bcf, 0xa00bfc, 0xc00bbf, 0xe00bfb,
    0x1000aaf, 0x1400bfa, 0x1600b9f, 0x1800bf9, 0x1a00bf8, 0x1c00a8f, 0x2000a7f, 0x2400af7,
    0x2800a6f, 0x2c00af6, 0x30008ff, 0x4000a5f, 0x4400af5, 0x480094f, 0x50009f4, 0x58009f3,
    0x60009f0, 0x6800a3f, 0x6c010ce, 0x6c111ec, 0x6c191dd, 0x6c20fde, 0x6c40fe9, 0x6c610ea,
    0x6c710d9, 0x6c80eee, 0x6cc0fed, 0x6ce0feb, 0x6d00ebe, 0x6d40ecd, 0x6d80fdc, 0x6da0fdb,
    0x6dc0eae, 0x6e00ecc, 0x6e40fad, 0x6e60fda, 0x6e80f7e, 0x6ea0fac, 0x6ec0eca, 0x6f00fc9,
    0x6f20f7d, 0x6f40e5e, 0x6f80dbd, 0x70008f2, 0x800092f, 0x880090f, 0x900081f, 0xa0008f1,
    0xb000d9e, 0xb080ebc, 0xb0c0ecb, 0xb100e8e, 0xb140ee8, 0xb180e9d, 0xb1c0ee7, 0xb200ebb,
    0xb240e8d, 0xb280ed8, 0xb2c0e6e, 0xb300de6, 0xb380d9c, 0xb400eab, 0xb440eba, 0xb480ee5,
    0xb4c0ed7, 0xb500d4e, 0xb580ee4, 0xb5c0e8c, 0xb600dc8, 0xb680d3e, 0xb700d6d, 0xb780ed6,
    0xb7c0e9b, 0xb800eb9, 0xb840eaa, 0xb880de1, 0xb900dd4, 0xb980eb8, 0xb9c0ea9, 0xba00d7b,
    0xba80eb7, 0xbac0ed0, 0xbb00ce3, 0xbc00d0e, 0xbc80de0, 0xbd00d5d, 0xbd80dd5, 0xbe00d7c,
    0xbe80dc7, 0xbf00d4d, 0xbf80d8b, 0xc000d9a, 0xc080d6c, 0xc100dc6, 0xc180d3d, 0xc200d5c,
    0xc280dc5, 0xc300c0d, 0xc400d8a, 0xc480da8, 0xc500d99, 0xc580d4c, 0xc600db6, 0xc680d7a,
    0xc700c3c, 0xc800d5b, 0xc880d89, 0xc900c1c, 0xca00cc0, 0xcb00d98, 0xcb80d79, 0xcc00be2,
    0xce00c2e, 0xcf00c1e, 0xd000cd3, 0xd100c2d, 0xd200cd2, 0xd300cd1, 0xd400c3b, 0xd500d97,
    0xd580d88, 0xd600b1d, 0xd800cc4, 0xd900c6b, 0xda00cc3, 0xdb00ca7, 0xdc00b2c, 0xde00cc2,
    0xdf00cb5, 0xe000cc1, 0xe100c0c, 0xe200c4b, 0xe300cb4, 0xe400c6a, 0xe500ca6, 0xe600bb3,
    0xe800c5a, 0xe900ca5, 0xea00b2b, 0xec00bb2, 0xee00b1b, 0xf000bb1, 0xf200c0b, 0xf300cb0,
    0xf400c69, 0xf500c96, 0xf600c4a, 0xf700ca4, 0xf800c78, 0xf900c87, 0xfa00ba3, 0xfc00c3a,
    0xfd00c59, 0xfe00b2a, 0x10000c95, 0x10100c68, 0x10200ba1, 0x10400c86, 0x10500c77, 0x10600b94,
    0x10800c49, 0x10900c57, 0x10a00b67, 0x10c00aa2, 0x11000a1a, 0x11400b0a, 0x11600ba0, 0x11800b39,
    0x11a00b93, 0x11c00b58, 0x11e00b85, 0x12000a29, 0x12400a92, 0x12800b76, 0x12a00b09, 0x12c00a19,
    0x13000a91, 0x13400b90, 0x13600b48, 0x13800b84, 0x13a00b75, 0x13c00b38, 0x13e00b83, 0x14000b66,
    0x14200b28, 0x14400a82, 0x14800b47, 0x14a00b74, 0x14c00a18, 0x15000a81, 0x15400a80, 0x15800b08,
    0x15a00b56, 0x15c00a37, 0x16000a73, 0x16400b65, 0x16600b46, 0x16800a27, 0x16c00a72, 0x17000b64,
    0x17200b55, 0x17400a07, 0x17800917, 0x18000971, 0x18800a70, 0x18c00a36, 0x19000a63, 0x19400a45,
    0x19800a54, 0x19c00a26, 0x1a000962, 0x1a800916, 0x1b000961, 0x1b800a06, 0x1bc00a60, 0x1c000953,
    0x1c800a35, 0x1cc00a44, 0x1d000925, 0x1d800952, 0x1e000851, 0x1f000915, 0x1f800905, 0x20000934,
    0x20800943, 0x21000950, 0x21800924, 0x22000942, 0x22800933, 0x23000814, 0x24000841, 0x25000904,
    0x25800940, 0x26000823, 0x27000832, 0x28000713, 0x2a000731, 0x2c000803, 0x2d000830, 0x2e000722,
    0x30000612, 0x34000621, 0x38000602, 0x3c000620, 0x40000411, 0x50000401, 0x60000310, 0x80000100};
unsigned int h24[256]={ 0x8ef, 0x10008fe, 0x20008df, 0x30008fd, 0x40008cf, 0x50008fc, 0x60008bf, 0x70008fb,
    0x80007fa, 0xa0008af, 0xb00089f, 0xc0007f9, 0xe0007f8, 0x1000088f, 0x1100087f, 0x120007f7,
    0x1400076f, 0x160007f6, 0x1800075f, 0x1a0007f5, 0x1c00074f, 0x1e0007f4, 0x2000073f, 0x220007f3,
    0x2400072f, 0x260007f2, 0x280007f1, 0x2a00081f, 0x2b0008f0, 0x2c00090f, 0x2c800bee, 0x2ca00bde,
    0x2cc00bed, 0x2ce00bce, 0x2d000bec, 0x2d200bdd, 0x2d400bbe, 0x2d600beb, 0x2d800bcd, 0x2da00bdc,
    0x2dc00bae, 0x2de00bea, 0x2e000bbd, 0x2e200bdb, 0x2e400bcc, 0x2e600b9e, 0x2e800be9, 0x2ea00bad,
    0x2ec00bda, 0x2ee00bbc, 0x2f000bcb, 0x2f200b8e, 0x2f400be8, 0x2f600b9d, 0x2f800bd9, 0x2fa00b7e,
    0x2fc00be7, 0x2fe00bac, 0x300004ff, 0x40000bca, 0x40200bbb, 0x40400b8d, 0x40600bd8, 0x40800c0e,
    0x40900ce0, 0x40a00b0d, 0x40c00ae6, 0x41000b6e, 0x41200b9c, 0x41400ac9, 0x41800a5e, 0x41c00aba,
    0x42000ae5, 0x42400bab, 0x42600b7d, 0x42800ad7, 0x42c00ae4, 0x43000a8c, 0x43400ac8, 0x43800b4e,
    0x43a00b2e, 0x43c00a3e, 0x44000a6d, 0x44400ad6, 0x44800ae3, 0x44c00a9b, 0x45000ab9, 0x45400aaa,
    0x45800ae2, 0x45c00a1e, 0x46000ae1, 0x46400a5d, 0x46800ad5, 0x46c00a7c, 0x47000ac7, 0x47400a4d,
    0x47800a8b, 0x47c00ab8, 0x48000ad4, 0x48400a9a, 0x48800aa9, 0x48c00a6c, 0x49000ac6, 0x49400a3d,
    0x49800ad3, 0x49c00a2d, 0x4a000ad2, 0x4a400a1d, 0x4a800a7b, 0x4ac00ab7, 0x4b000ad1, 0x4b400a5c,
    0x4b800ac5, 0x4bc00a8a, 0x4c000aa8, 0x4c400a99, 0x4c800a4c, 0x4cc00ac4, 0x4d000a6b, 0x4d400ab6,
    0x4d800bd0, 0x4da00b0c, 0x4dc00a3c, 0x4e000ac3, 0x4e400a7a, 0x4e800aa7, 0x4ec00a2c, 0x4f000ac2,
    0x4f400a5b, 0x4f800ab5, 0x4fc00a1c, 0x50000a89, 0x50400a98, 0x50800ac1, 0x50c00a4b, 0x51000bc0,
    0x51200b0b, 0x51400a3b, 0x51800bb0, 0x51a00b0a, 0x51c00a1a, 0x520009b4, 0x52800a6a, 0x52c00aa6,
    0x53000a79, 0x53400a97, 0x53800ba0, 0x53a00b09, 0x53c00a90, 0x540009b3, 0x54800988, 0x55000a2b,
    0x55400a5a, 0x558009b2, 0x56000aa5, 0x56400a1b, 0x56800ab1, 0x56c00a69, 0x57000996, 0x578009a4,
    0x58000a4a, 0x58400a78, 0x58800987, 0x5900093a, 0x598009a3, 0x5a000959, 0x5a800995, 0x5b00092a,
    0x5b8009a2, 0x5c0009a1, 0x5c800968, 0x5d000986, 0x5d800977, 0x5e000949, 0x5e800994, 0x5f000939,
    0x5f800993, 0x60000958, 0x60800985, 0x61000929, 0x61800967, 0x62000976, 0x62800992, 0x63000919,
    0x63800991, 0x64000948, 0x64800984, 0x65000957, 0x65800975, 0x66000938, 0x66800983, 0x67000966,
    0x67800928, 0x68000982, 0x68800918, 0x69000947, 0x69800974, 0x6a000981, 0x6a800a08, 0x6ac00a80,
    0x6b000956, 0x6b800965, 0x6c000917, 0x6c800a07, 0x6cc00a70, 0x6d000873, 0x6e000937, 0x6e800927,
    0x6f000872, 0x70000846, 0x71000864, 0x72000855, 0x73000871, 0x74000836, 0x75000863, 0x76000845,
    0x77000854, 0x78000826, 0x79000862, 0x7a000816, 0x7b000861, 0x7c000906, 0x7c800960, 0x7d000835,
    0x7e000853, 0x7f000844, 0x80000825, 0x81000852, 0x82000815, 0x83000905, 0x83800950, 0x84000751,
    0x86000834, 0x87000843, 0x88000724, 0x8a000742, 0x8c000733, 0x8e000714, 0x90000741, 0x92000804,
    0x93000840, 0x94000723, 0x96000732, 0x98000613, 0x9c000631, 0xa0000703, 0xa2000730, 0xa4000622,
    0xa8000512, 0xb0000521, 0xb8000602, 0xbc000620, 0xc0000411, 0xd0000401, 0xe0000410, 0xf0000400};
unsigned int hA[16]={ 0x6b0, 0x40006f0, 0x80006d0, 0xc0006e0, 0x10000670, 0x14000650, 0x18000590, 0x20000560,
    0x28000530, 0x300005a0, 0x380005c0, 0x40000420, 0x50000410, 0x60000440, 0x70000480, 0x80000100};
unsigned int hB[16]={  0x4f0, 0x100004e0, 0x200004d0, 0x300004c0, 0x400004b0, 0x500004a0, 0x60000490, 0x70000480,
    0x80000470, 0x90000460, 0xa0000450, 0xb0000440, 0xc0000430, 0xd0000420, 0xe0000410, 0xf0000400};

/* now the cues, remember to change these tables if you change N_CUE
 */
unsigned char h_cue[34][N_CUE]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,2,2,2,2,3,3,3,3,3,3,3,3},
    {0,3,5,5,6,6,7,7,8,8,8,8,8,8,8,8},
    {0,3,5,5,6,6,6,6,7,7,7,7,8,8,8,8},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,8,12,12,13,13,14,14,15,15,15,15,15,15,15,15},
    {0,5,7,9,10,11,12,12,13,13,13,13,14,14,15,15},
    {0,20,29,32,33,33,34,34,35,35,35,35,35,35,35,35},
    {0,23,30,31,32,32,32,32,33,33,34,34,35,35,35,35},
    {0,15,21,24,27,29,30,31,32,32,33,33,34,34,35,35},
    {0,42,56,60,61,61,62,62,63,63,63,63,63,63,63,63},
    {0,30,45,53,57,58,60,60,61,61,62,62,63,63,63,63},
    {0,23,37,46,50,54,56,57,58,60,61,61,62,62,63,63},
    {0,203,238,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,132,178,205,223,233,240,245,248,250,252,252,253,254,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,162,231,248,252,253,254,254,255,255,255,255,255,255,255,255},
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255},
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255},
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255},
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255}, 
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255}, 
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255}, 
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255}, 
    {0,13,22,58,59,131,177,209,226,238,245,249,252,253,254,255}, 
    {0,4,7,9,11,12,13,14,15,15,15,15,15,15,15,15}, 
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} 
}; 

unsigned int *h_tables[34]={h0,h1,h2,h3,0,h5,h6,h7,h8,h9,h10,h11,h12,h13,0,h15, 
    h16,h16,h16,h16,h16,h16,h16,h16,h24,h24,h24,h24,h24,h24,h24,h24,hA,hB};

#endif /* huff_h */
