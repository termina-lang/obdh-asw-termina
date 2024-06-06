#ifndef __SERIALIZE_H__
#define __SERIALIZE_H__

#include <termina.h>

uint16_t deserialize_uint16(const uint8_t data_bytes[2]);

uint32_t deserialize_uint32(const uint8_t data_bytes[4]);

void serialize_uint16(uint16_t aux, uint8_t data_bytes[2]);

void serialize_uint32(uint32_t aux, uint8_t data_bytes[4]);

#endif
