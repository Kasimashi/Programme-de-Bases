/*
 * crc32.h
 * See linux/lib/crc32.c for license and changes
 */
#ifndef _CRC32_H
#define _CRC32_H

/* extern u32  crc32_le(u32 crc, unsigned char const *p, size_t len); */
unsigned long crc32(unsigned long crc, const unsigned char *buf, unsigned int len);
//#define crc32(seed, data, length)  crc32_le(seed, (unsigned char const *)data, length)


#endif /* _CRC32_H */
