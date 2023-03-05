#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void) {
    FILE *fp;
    BITMAPFILEHEADER* header = createHeader(0x72);

    unsigned char* headerBytes;

    headerBytes = headerToBytes(header);
    


    fp = open("i.bin", O_BINARY);
    write(headerBytes, sizeof (unsigned char), 14, fp);
    fclose(fp);

    free(header);
    free(headerBytes);

    return 0;
}