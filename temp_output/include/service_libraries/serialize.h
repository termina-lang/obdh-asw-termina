#ifndef __SERVICE_LIBRARIES__SERIALIZE_H__
#define __SERVICE_LIBRARIES__SERIALIZE_H__

#include <termina.h>

#include "option.h"

uint16_t deserialize_uint16(const uint8_t data_bytes[2U]);

uint32_t deserialize_uint32(const uint8_t data_bytes[4U]);

void serialize_uint16(uint16_t aux, uint8_t data_bytes[2U]);

void serialize_uint32(uint32_t aux, uint8_t data_bytes[4U]);

#endif
