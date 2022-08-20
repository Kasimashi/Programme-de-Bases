#include "crc.h"

/**
* This function proccess a crc16 or crc32 by block of CRC_SIZE_BLOCK bytes
*/
int crc_proccess(crc_t *crc)
{
    /* Internal Copy of Data */
    unsigned int tmp_size;
    unsigned int size = crc->size;
    char* pbuff = crc->buff;
    
    unsigned int u32Crc32 = 0;
    unsigned short u16Crc16 = 0;
    /* Processing by Block ! :) : avoid to use to much memory */
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
              //printf("CRC16 is %X \n",u16Crc16);
              break;

            case CRC32_TYPE:
              u32Crc32 = crc32(u32Crc32, pbuff, tmp_size);
              //printf("CRC32 is %X \n",u32Crc32);
              break;

            default:
              return CRC_ERROR_UNKNOWN_TYPE;
        }
        size -= tmp_size;
        pbuff += tmp_size;
    } while (size > 0);

    /* Result saving depending of type */
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
