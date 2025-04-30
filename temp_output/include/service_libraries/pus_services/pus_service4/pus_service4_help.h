#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_HELP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_services.h"

extern const size_t max_num_of_stats;

typedef struct {
    uint32_t min;
    TimeVal min_obt;
    uint32_t max;
    TimeVal max_obt;
    uint32_t mean_value;
    uint32_t samples;
} StatsDef;

typedef struct {
    _Bool defined[max_num_of_stats];
    uint16_t PID[max_num_of_stats];
    TimeVal start_time[max_num_of_stats];
} StatsConfig;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t PID;
} PS4ExecTCReqStatusUpdate;

PS4ExecTCReqStatusUpdate ps4_init_tc_req_status_update();

#endif
