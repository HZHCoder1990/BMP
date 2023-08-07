//
//  main.c
//  BMP
//
//  Created by mac on 2023/8/4.
//

#include <stdio.h>
#include <stdlib.h>

// 2个字节
struct BMP_HEADER {
    uint16_t header;
};

// 4个字节
struct BMP_INFO {
    uint32_t info;
};

int main(int argc, const char * argv[]) {
    
    FILE *fp = fopen("/Users/mac/Desktop/99.txt", "rb");
    if (fp == NULL) { return 0; }
    
    struct BMP_HEADER header;
    // 读取前2个字节
    fread(&header, sizeof(struct BMP_HEADER), 1, fp);
    // 打印读取的每个字节
    unsigned char *p = (unsigned char *)&header.header;
    for (int i = 0; i < sizeof(header.header); i ++) {
        printf("%c \n", *(p + i));
    }
    fclose(fp);
    return 0;
}
