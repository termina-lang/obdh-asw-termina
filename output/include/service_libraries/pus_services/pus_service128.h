#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service128/types.h"
#include "service_libraries/pus_tc_handler.h"

#include "option.h"
#include "result.h"

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
    } pus_service_1;
    PS128ExecTCReqStatusUpdate exec_tc_req_status_update;
} PUSService128;

__status_int32_t PUSService128__exec128_1TC(const __termina_event_t * const __ev, PUSService128 * const self);

void PUSService128__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status, _Bool * const reebot_flag);

#endif
