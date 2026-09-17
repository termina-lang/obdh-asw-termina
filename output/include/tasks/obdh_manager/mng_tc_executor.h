#ifndef __TASKS__OBDH_MANAGER__MNG_TC_EXECUTOR_H__
#define __TASKS__OBDH_MANAGER__MNG_TC_EXECUTOR_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service128.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service9.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_1)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* send_tm_1_2)(const __termina_event_t * const __ev, void * const __this, const TCStatus * const tc_status, const TCHandler * const tc_handler, __status_int32_t * const status);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
    } pus_service_1;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status, _Bool * const reebot_flag);
    } pus_service_128;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
    } pus_service_9;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
    } pus_service_2;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
    } pus_service_17;
} CManagerTExecutor;

void CManagerTExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const status, _Bool * const reebot_flag);

void CManagerTExecutor__mng_tc_acceptation(const __termina_event_t * const __ev, void * const __this, const TCHandler * const tc_handler, __status_int32_t * const status);

void CManagerTExecutor__mng_tc_rejection(const __termina_event_t * const __ev, void * const __this, const TCHandler * const tc_handler, const TCStatus * const tc_status, __status_int32_t * const status);

#endif
