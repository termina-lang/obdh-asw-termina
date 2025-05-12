#ifndef __SERVICE_LIBRARIES__CRC_H__
#define __SERVICE_LIBRARIES__CRC_H__

#include <termina.h>

#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

uint16_t cal_crc_16(const uint8_t data[max_tc_size], size_t nbytes);

#endif
