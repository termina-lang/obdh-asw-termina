#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128__PUS_SERVICE128_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128__PUS_SERVICE128_HELP_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    _Bool reebot_flag;
} PS128ExecTCReqStatusUpdate;

#endif
