#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3__INTERNAL_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3__INTERNAL_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/system_data_pool.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service5.h"
#include "service_libraries/rand.h"

#include "option.h"
#include "result.h"

typedef struct {
    _Bool found;
    size_t index;
} IndexFound;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t SID;
    uint8_t collection_interval;
} PS3ExecTCReqStatusUpdate;

typedef struct {
    _Bool enabled;
    uint16_t SID;
    uint8_t interval;
    uint8_t interval_control;
    uint8_t num_params;
    uint16_t params_def[16U];
} HKConfiguration;

#endif
