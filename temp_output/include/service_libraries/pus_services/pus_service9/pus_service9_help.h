#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_HELP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_services.h"

typedef struct {
    uint32_t seconds;
    uint16_t finetime;
} MissionObt;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    MissionObt next_OBT;
} PS9ExecTCReqStatusUpdate;

TimeVal substract_TimeVal(TimeVal timeval1, TimeVal timeval2);

PS9ExecTCReqStatusUpdate ps9_init_tc_req_status_update();

#endif
