#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__TYPES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__TYPES_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/system_data_pool.h"
#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1.h"

#include "option.h"
#include "result.h"

typedef struct {
    uint8_t PID_value_u8;
    uint32_t PID_value_u32;
} TC20_3Data;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t PID;
    TC20_3Data tc_20_3_data;
} PS20ExecTCReqStatusUpdate;

#endif
