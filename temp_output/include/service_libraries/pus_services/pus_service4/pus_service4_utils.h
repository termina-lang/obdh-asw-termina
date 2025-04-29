#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_UTILS_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_UTILS_H__

#include <termina.h>

#include "option.h"

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

typedef enum {
    PS4ExecTCReqStatus__Init,
    PS4ExecTCReqStatus__ExecTC,
    PS4ExecTCReqStatus__Error,
    PS4ExecTCReqStatus__Exit
} __enum_PS4ExecTCReqStatus_t;

typedef struct {
    __enum_PS4ExecTCReqStatus_t __variant;
} PS4ExecTCReqStatus;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t PID;
} PS4ExecTCReqStatusUpdate;

PS4ExecTCReqStatusUpdate ps4_init_tc_req_status_update();

#endif
