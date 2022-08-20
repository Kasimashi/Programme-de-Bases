#include <stdio.h>
#include "benchmark.h"

#define SIZE_CRC16  2
#define SIZE_CRC32  4

int benchmark_crc(int argc, char **argv)
{

    char buff[] = "HelloWorld";
    char crc16[SIZE_CRC16] = {0x60, 0x53};
    char crc32[SIZE_CRC32] = {0x77, 0x77, 0x0c, 0x79};
    
    char *pbuff = buff;
    unsigned short u16Crc16 = 0;
    unsigned long u32Crc32 = 0;
    unsigned int tmp_size, size;
	
	size = strlen(buff);

	do{
	    if (size > CRC_SIZE_BLOCK)
	    {
	        tmp_size = CRC_SIZE_BLOCK;
	    }
	    else
	    {
	        tmp_size = size;
	    }
	    
	    printf("Processing '%.10s',len = %d\n",pbuff, tmp_size);
	    u16Crc16 = crc16(u16Crc16, pbuff, tmp_size);
	    printf("CRC16 is %X \n",u16Crc16);
	    u32Crc32 = crc32(u32Crc32, pbuff, tmp_size);
	    printf("CRC32 is %X \n",u32Crc32);
	    
	    
	    size -= tmp_size;
	    pbuff += tmp_size;
	} while (size > 0);
	
	printf("give me a bottle of rum!\n");
	return 0;
}
