#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9_H__

#include <termina.h>

#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/types.h"
#include "service_libraries/pus_tm_handler.h"

#include "option.h"
#include "result.h"

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const, void * const, uint16_t, uint16_t, size_t, __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
    } pus_service_1;
    struct {
        void * __that;
        void (* set_obt)(const __termina_event_t * const, void * const, MissionOBT);
    } obt_manager;
    PS9ExecTCReqStatusUpdate exec_tc_req_status_update;
} PUSService9;

__status_int32_t PUSService9__exec9_129TC(const __termina_event_t * const __ev, PUSService9 * const self);

void PUSService9__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);

#endif
