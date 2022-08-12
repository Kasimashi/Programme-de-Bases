/*
 *	crc16.h - CRC-16 routine
 *
 * Implements the standard CRC-16:
 *   Width 16
 *   Poly  0x8005 (x^16 + x^15 + x^2 + 1)
 *   Init  0
 */

#ifndef __CRC16_H
#define __CRC16_H

unsigned short crc16(unsigned short crc, unsigned char const *buffer, unsigned int len);

#endif /* __CRC16_H */
