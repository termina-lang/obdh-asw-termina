#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17__PUS_SERVICE17_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17__PUS_SERVICE17_HELP_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    uint8_t flags_ack;
} PS17ExecTCReqStatusUpdate;

void build_tm_17_2(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                   MissionObt current_obt);

#endif
