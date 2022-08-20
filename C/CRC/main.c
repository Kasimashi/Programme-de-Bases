#include <stdio.h>
#include <string.h>

#include "crc16.h"
#include "crc32.h"

#define CRC_SIZE_BLOCK  3

enum CRC_ERROR{
    CRC_ERROR_NONE,
    CRC_ERROR_UNDEFINED,
    CRC_ERROR_UNKNOWN_TYPE
};
enum CRC{
    CRC16_TYPE,
    CRC32_TYPE
};

/* Structure used to calculate crc */
/*
typedef struct {
    unsigned int type; // CRC16,CRC32 ...
	void (*crc_cbk)(int a); // Callback to proccess
	
} crc_internal_t;

crc_internal_t crc_callback[]=  {
  {CRC16_TYPE,   crc16},
  {CRC32_TYPE,     crc32},
};
*/


/* Structure used to calculate crc */
typedef struct {
    unsigned int type; // CRC16,CRC32 ...
    char* buff; //Buffer to proccess
    unsigned int size; //Size of buffer
    unsigned int result; //Size of buffer : MUST fit for CRC32 !	
} crc_t;

unsigned int debug = 1;

int crc_proccess(crc_t *crc)
{
    unsigned int tmp_size;
    unsigned int size = crc->size;
    char* pbuff = crc->buff;
    
    unsigned int u32Crc32 = 0;
    unsigned int u16Crc16 = 0;
    do{
        if (size > CRC_SIZE_BLOCK)
        {
            tmp_size = CRC_SIZE_BLOCK;
        }
        else
        {
            tmp_size = size;
        }
        
        
        switch (crc->type)
        {
            case CRC16_TYPE:
              u16Crc16 = crc16(u16Crc16, pbuff, tmp_size);
              if (debug) printf("CRC16 is %X \n",u16Crc16);
              break;

            case CRC32_TYPE:
              u32Crc32 = crc32(u32Crc32, pbuff, tmp_size);
              if (debug) printf("CRC32 is %X \n",u32Crc32);
              break;

            default:
              return CRC_ERROR_UNKNOWN_TYPE;
        }
        size -= tmp_size;
        pbuff += tmp_size;
    } while (size > 0);

    // Result saving
    switch (crc->type)
    {
        case CRC16_TYPE:
          crc->result = u16Crc16;
          break;

        case CRC32_TYPE:
          crc->result = u32Crc32;
          break;

        default:
          return CRC_ERROR_UNKNOWN_TYPE;
    }
    return CRC_ERROR_NONE;
	
}

int main(int argc, char **argv)
{
    int ret = CRC_ERROR_UNDEFINED;
    
    crc_t crc;
    
    char buff[] = "HelloWorld";
    
    crc.buff = &buff[0];
    crc.size = strlen(buff);
    crc.type = CRC32_TYPE;
   
    printf("Processing type %d on '%.10s' by block of %d len = %d\n",crc.type, crc.buff, CRC_SIZE_BLOCK, crc.size);
   
    ret = crc_proccess(&crc);
    
    printf("Result is %X\n", crc.result);
    
	
	return ret;
}



