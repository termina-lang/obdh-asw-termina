#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_HELP_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

typedef struct {
    uint32_t min;
    MissionObt min_obt;
    uint32_t max;
    MissionObt max_obt;
    uint32_t mean_value;
    uint32_t samples;
} StatsDef;

typedef struct {
    _Bool defined[4U];
    uint16_t PID[4U];
    MissionObt start_time[4U];
} StatsConfig;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t PID;
    size_t valid_index;
} PS4ExecTCReqStatusUpdate;

typedef struct {
    size_t index;
    __status_int32_t status;
} IndexStatus;

void build_tm_4_2(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  size_t index, uint8_t N,
                  const StatsConfig * const stats_config_table,
                  const StatsDef param_stats[4U], MissionObt current_obt,
                  __status_int32_t * const status);

#endif
