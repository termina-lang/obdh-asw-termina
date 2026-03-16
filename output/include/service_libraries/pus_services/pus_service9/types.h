#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__TYPES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__TYPES_H__

#include <termina.h>

#include "resources/obt_manager.h"

#include "option.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    MissionOBT next_OBT;
} PS9ExecTCReqStatusUpdate;

#endif
