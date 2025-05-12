#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3__PUS_SERVICE3_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3__PUS_SERVICE3_HELP_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

extern const size_t max_num_of_SIDs;

extern const size_t max_params_per_SID;

typedef struct {
    _Bool found;
    size_t index;
} IndexFound;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t SID;
    uint8_t collection_interval;
} PS3TCData;

typedef struct {
    IndexFound index;
    PS3TCData tc_data;
} PS3ExecTCReqStatusUpdate;

typedef struct {
    _Bool enabled;
    uint16_t SID;
    uint8_t interval;
    uint8_t interval_control;
    uint8_t num_params;
    uint16_t params_def[max_params_per_SID];
} HKConfiguration;

#endif
