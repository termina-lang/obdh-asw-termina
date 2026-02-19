#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17__INTERNAL_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17__INTERNAL_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/tm_channel.h"

#include "option.h"
#include "result.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
} PS17ExecTCReqStatusUpdate;

void build_tm_17_2(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt);

#endif
