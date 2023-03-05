#ifndef HEADER_H
#define HEADER_H

#include "../const/const.h"

typedef struct tagBITMAPFILEHEADER {
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
} BITMAPFILEHEADER;

BITMAPFILEHEADER* createHeader(DWORD bfSize);

unsigned char* headerToBytes(BITMAPFILEHEADER* bfHeader);

#endif