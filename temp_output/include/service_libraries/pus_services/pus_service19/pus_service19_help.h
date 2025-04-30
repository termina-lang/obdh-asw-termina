#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19__PUS_SERVICE19_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19__PUS_SERVICE19_HELP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/event_list.h"
#include "service_libraries/pus_services/pus_services.h"

extern const size_t event_action_max_bytes;

extern const size_t max_event_action_definitions;

extern const size_t event_action_queue_dimension;

typedef struct {
    _Bool enabled;
    uint16_t event_ID;
} EventActionConfig;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t EvID;
} PS19TCData;

typedef struct {
    _Bool found;
    size_t ev_action_index;
} FoundID;

typedef struct {
    PS19TCData tc_data;
    FoundID ev_action_ID;
    TCDescriptorT action_tc_packet;
} PS19ExecTCReqStatusUpdate;

PS19ExecTCReqStatusUpdate ps19_init_tc_req_status_update();

typedef enum {
    TC19_1_Error__NoError,
    TC19_1_Error__EvIDEnabled,
    TC19_1_Error__MaxEventActionDefinitions
} __enum_TC19_1_Error_t;

typedef struct {
    __enum_TC19_1_Error_t __variant;
} TC19_1_Error;

#endif
