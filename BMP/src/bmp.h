

#ifndef BMP_H
#define BMP_H


/**
 实现BMP格式文件的读写功能
 1. https://geocld.github.io/2021/03/02/bmp/
 2. https://blog.csdn.net/lljss1980/article/details/105003766
 */

#include <stdio.h>

/**
 BMP文件头信息  14个字节
 */
typedef struct BMP_FILE_HEADER_t {
    uint8_t bfType[2];    // 16进制 "42 4D" 转为10进制的ASCII码为"66 77"，即"B M"，表示BMP的类型
    uint32_t bfSize;      // 文件大小
    uint16_t bfReserved1; // 保留字段1，必须设置为0
    uint16_t bfReserved2; // 保留字段2，必须设置为0
    uint32_t bfOffBits;   // 位图数据偏移量(位图的数据从哪个位置开始计算)
}BMP_FILE_HEADER;

/**
 位图信息头  40个字节
 */
typedef struct BMP_INFO_HEADER_t {
    // 位图信息头结构所需字节数
    uint32_t biSize;
    // 图像宽度，单位为像素
    uint32_t biWidth;
    // 图像高度，单位为像素。正数，表示图像是倒向的，图像数据是从图像左下角到右上角排列的
    // 大多数的BMP文件是倒向的位图，也就是说高度值为正数
    // 负数，表示图像是正向的
    uint32_t biHeight;
    
    uint16_t biPlanes; // 颜色平面数，设为1
    uint16_t biBitCount; // 每个像素的比特数，其值为1、4、8、16、24、32
    uint32_t biCompression; // 图像数据压缩的类型
    
    uint32_t biSizeImage;
    
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrused;
    
    uint32_t biClrImportant;
    
}BMP_INFO_HEADER;

typedef struct BMP_COLOR_TBL_t {
    uint8_t B;
    uint8_t G;
    uint8_t R;
    uint8_t A;
}BMP_COLOR_TBL;

typedef struct BMP_DATA_t {
    BMP_FILE_HEADER bmpFileHeader;
    BMP_INFO_HEADER bmpInfoHeader;
    uint8_t *dataPrt;
}BMP_DATA;

void readBMPFromFile(char *path,
                     BMP_FILE_HEADER *bmpFileHeader,
                     BMP_INFO_HEADER *bmpInfoHeader,
                     uint8_t **dataPtr);



#endif /* BMP_H */


