#include <elf.h>
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>
int main(){
 

    static const size_t BufferSize = 1000;
    int i;
    FILE *ptr;
    unsigned char buffer2[BufferSize];

    ptr = fopen("ptload.bin","rb");
    const size_t fileSize = fread(buffer2, sizeof(unsigned char), BufferSize, ptr);

    printf("File size = %ld bytes\n", fileSize);
    printf("Size of each item in bytes = %ld\n", sizeof(unsigned char));

    for(i = 0; i < (fileSize / sizeof(unsigned char)); i++)
    {
        printf("0x%x ", (int)buffer2[i]);
    }
    fclose (ptr);} 
