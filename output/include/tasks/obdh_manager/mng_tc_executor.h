#ifndef TASKS__OBDH_MANAGER__MNG_TC_EXECUTOR_H__
#define TASKS__OBDH_MANAGER__MNG_TC_EXECUTOR_H__

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
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* notify_tm_1_1)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_2)(const termina__event_t * const termina__ev, void * const termina__this, const TCStatus * const tc_status, const TCHandler * const tc_handler, Status__i32 * const status);
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
    } pus_service_1;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status, _Bool * const reebot_flag);
    } pus_service_128;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
    } pus_service_9;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
    } pus_service_2;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
    } pus_service_17;
} CManagerTExecutor;

void CManagerTExecutor__PUS_prio_exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const status, _Bool * const reebot_flag);

void CManagerTExecutor__mng_tc_acceptation(const termina__event_t * const termina__ev, void * const termina__this, const TCHandler * const tc_handler, Status__i32 * const status);

void CManagerTExecutor__mng_tc_rejection(const termina__event_t * const termina__ev, void * const termina__this, const TCHandler * const tc_handler, const TCStatus * const tc_status, Status__i32 * const status);

#endif
