#ifndef __CRC_H__
#define __CRC_H__

#include <termina.h>
#include "serialize.h"

uint16_t cal_crc_16(const uint8_t data[256], uint16_t nbytes);

#endif
