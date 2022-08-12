#include <stdio.h>
#include <string.h>

#define CRC_SIZE_BLOCK  3
#include "crc16.h"
#include "crc32.h"

int main(int argc, char **argv)
{
    char buff[] = "Helloworld";
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
	return 0;
}
