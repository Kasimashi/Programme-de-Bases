#ifndef _CRC_H_
#define _CRC_H_

#include "crc16.h"
#include "crc32.h"
#include "error_code.h"

#define CRC_SIZE_BLOCK  3


enum CRC{
    CRC16_TYPE,
    CRC32_TYPE
};

/* Structure used to calculate crc */
typedef struct {
    unsigned int type; // CRC16,CRC32 ...
    char* buff; //Buffer to proccess
    unsigned int size; //Size of buffer
    unsigned int result; //Size of buffer : MUST fit for CRC32 !	
} crc_t;

int crc_proccess(crc_t *crc);

#endif //_CRC_H_
