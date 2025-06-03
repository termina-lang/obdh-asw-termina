#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_HELP_H__

#include <termina.h>

#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_services.h"
#include "service_libraries/pus_tm_handler.h"

#include "option.h"
#include "result.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    MissionObt next_OBT;
} PS9ExecTCReqStatusUpdate;

TimeVal substract_TimeVal(TimeVal timeval1, TimeVal timeval2);

#endif
