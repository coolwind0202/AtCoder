#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "../const/const.h"
#include "../util/bin.h"

BITMAPFILEHEADER* createHeader(DWORD bfSize) {
    BITMAPFILEHEADER* mem;
    mem = (BITMAPFILEHEADER*)malloc(sizeof (BITMAPFILEHEADER));
    
    if (mem == NULL) {
        abort();
        return NULL;
    }

    mem->bfType = 0;
    mem->bfSize = bfSize;
    mem->bfReserved1 = 0;
    mem->bfReserved2 = 0;
    mem->bfOffBits = 0;

    return mem;
}

unsigned char* headerToBytes(BITMAPFILEHEADER* header) {
    if (header == NULL) {
        free(header);
        abort();
    }

    size_t HEADER_BYTE_LENGTH = 14;
    size_t size = HEADER_BYTE_LENGTH * sizeof(unsigned char);

    unsigned char* data = (unsigned char *)malloc(size);

    unsigned char* bfSizeBytes;
    unsigned char* bfOffBitsBytes;

    bfSizeBytes = dwordToBytes(header->bfSize);
    bfOffBitsBytes = dwordToBytes(header->bfOffBits);

    if (data == NULL) {
        abort();
    }

    printf("%ld\n", size);
    memset(data, 0, size);

    data[0] = 'B';
    data[1] = 'M';
    sprintf(data + 2, "%s", bfSizeBytes);
    sprintf(data + 10, "%s", bfOffBitsBytes);
    printf("%s\n", data);

    free(bfSizeBytes);
    free(bfOffBitsBytes);

    return data;
}