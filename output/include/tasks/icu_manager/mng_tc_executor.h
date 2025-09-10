#ifndef __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__
#define __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__

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
    void * __that;
    void (* PUS_prio_exec_tc)(void * const, TCHandler * const, __status_int32_t * const, _Bool * const);
    void (* mng_tc_acceptation)(void * const, const TCHandler * const, __status_int32_t * const);
    void (* mng_tc_rejection)(void * const, const TCHandler * const, const TCStatus * const, __status_int32_t * const);
} MngTCExecIface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_1)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_2)(const __termina_event_t * const, void * const, const TCStatus * const, const TCHandler * const, __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
    } pus_service_1;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const, TCHandler * const, __status_int32_t * const, _Bool * const);
    } pus_service_128;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const, TCHandler * const, __status_int32_t * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const, TCHandler * const, __status_int32_t * const);
    } pus_service_2;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const, TCHandler * const, __status_int32_t * const);
    } pus_service_17;
} ManagerTCExecutor;

void ManagerTCExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const status, _Bool * const reebot_flag);

void ManagerTCExecutor__mng_tc_acceptation(const __termina_event_t * const __ev, void * const __this, const TCHandler * const tc_handler, __status_int32_t * const status);

void ManagerTCExecutor__mng_tc_rejection(const __termina_event_t * const __ev, void * const __this, const TCHandler * const tc_handler, const TCStatus * const tc_status, __status_int32_t * const status);

#endif
