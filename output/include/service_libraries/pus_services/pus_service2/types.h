#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__TYPES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__TYPES_H__

#include <termina.h>

#include "option.h"

extern const size_t num_params2;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint32_t dev_address;
} PS2ExecTCReqStatusUpdate;

#endif
