#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_HELP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "resources/system_data_pool.h"

typedef enum {
    PS20ExecTCReqStatus__Init,
    PS20ExecTCReqStatus__ExecTC,
    PS20ExecTCReqStatus__Error,
    PS20ExecTCReqStatus__Exit
} __enum_PS20ExecTCReqStatus_t;

typedef struct {
    __enum_PS20ExecTCReqStatus_t __variant;
} PS20ExecTCReqStatus;

typedef struct {
    uint8_t PID_value_u8;
    uint32_t PID_value_u32;
} TC20_3Data;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t PID;
    TC20_3Data tc_20_3_data;
} PS20ExecTCReqStatusUpdate;

PS20ExecTCReqStatusUpdate ps20_init_tc_req_status_update();

#endif
