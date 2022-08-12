#include <stdio.h>
#include <string.h>

#define CRC_SIZE_BLOCK  5
#include "crc16.h"

int main(int argc, char **argv)
{
    char buff[] = "Helloworlddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
    char * pbuff = buff;
    unsigned short crc;
    unsigned int tmp_size, size;
	
	size = strlen(buff);

	do{
	    (size > CRC_SIZE_BLOCK) ? tmp_size = CRC_SIZE_BLOCK 
	    if (size > CRC_SIZE_BLOCK)
	    {
	        tmp_size = CRC_SIZE_BLOCK;
	    }
	    else
	    {
	        tmp_size = size;
	    }
	    
	    printf("Processing '%.5s',len = %d\n",pbuff, tmp_size);
	    crc = crc16(crc, pbuff, tmp_size);
	    printf("CRC16 is %X \n",crc);
	    
	    size -= tmp_size;
	    pbuff += tmp_size;
	} while (size > 0);
	return 0;
}
