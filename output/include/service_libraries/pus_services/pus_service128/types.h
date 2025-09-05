#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128__TYPES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128__TYPES_H__

#include <termina.h>

#include "option.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    _Bool reebot_flag;
} PS128ExecTCReqStatusUpdate;

#endif
