#include <stdio.h>
#include <string.h>
#include "crc.h"

int main(int argc, char **argv)
{
    int ret = CRC_ERROR_UNDEFINED;
    crc_t crc;
    
    /* USER INPUT */
    char buff[] = "HelloWorld";
    crc.buff = &buff[0];
    crc.size = strlen(buff);
    crc.type = CRC32_TYPE;
   
   /* PROCCESS */
    ret = crc_proccess(&crc);
    if ( ret != 0 ) {
        printf("Could not proccess (Error code = 0x%X)\n",ret); 
        return ret;
    }

    /* OUTPUT */
    printf("Processing type %d on '%.10s' datalen = %d\n",crc.type, crc.buff, crc.size);
    printf("Result is 0x%X\n", crc.result);
    
    return ret;
}



