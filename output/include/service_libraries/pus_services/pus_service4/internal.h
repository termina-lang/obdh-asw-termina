#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__INTERNAL_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__INTERNAL_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1.h"

#include "option.h"

typedef struct {
    uint32_t min;
    MissionOBT min_obt;
    uint32_t max;
    MissionOBT max_obt;
    uint32_t mean_value;
    uint32_t samples;
} StatsDef;

typedef struct {
    _Bool defined[4U];
    uint16_t PID[4U];
    MissionOBT start_time[4U];
} StatsConfig;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
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

__status_int32_t build_tm_4_2(TMHandler * const p_tm_handler,
                              uint16_t tm_seq_counter, size_t index, uint8_t N,
                              const StatsConfig * const stats_config_table,
                              const StatsDef param_stats[4U],
                              MissionOBT current_obt);

#endif
