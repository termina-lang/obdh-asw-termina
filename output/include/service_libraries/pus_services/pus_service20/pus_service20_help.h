#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_HELP_H__

#include <termina.h>

#include "resources/system_data_pool.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

typedef struct {
    uint8_t PID_value_u8;
    uint32_t PID_value_u32;
} TC20_3Data;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t PID;
    TC20_3Data tc_20_3_data;
} PS20ExecTCReqStatusUpdate;

#endif
