#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19__PUS_SERVICE19_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19__PUS_SERVICE19_HELP_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

extern const size_t event_action_max_bytes;

typedef struct {
    _Bool enabled;
    uint16_t event_ID;
} EventActionConfig;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t EvID;
} PS19TCData;

typedef struct {
    _Bool found;
    size_t ev_action_index;
    _Bool enabled;
} FoundID;

typedef struct {
    PS19TCData tc_data;
    FoundID ev_action_ID;
    TCDescriptorT action_tc_packet;
} PS19ExecTCReqStatusUpdate;

typedef enum {
    TC19_1_Error__NoError,
    TC19_1_Error__EvIDEnabled,
    TC19_1_Error__MaxEventActionDefinitions
} __enum_TC19_1_Error_t;

typedef struct {
    __enum_TC19_1_Error_t __variant;
} TC19_1_Error;

#endif
