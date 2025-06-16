#ifndef __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__
#define __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__

#include <termina.h>

#include "resources/tm_channel.h"
#include "resources/tm_counter.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service128/pus_service128.h"
#include "service_libraries/pus_services/pus_service17/pus_service17.h"
#include "service_libraries/pus_services/pus_service2/pus_service2.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* PUS_prio_exec_tc)(void * const, TCHandlerT * const,
                              __status_int32_t * const, _Bool * const);
    void (* mng_tc_acceptation)(void * const, const TCHandlerT * const,
                                __status_int32_t * const);
    void (* mng_tc_rejection)(void * const, const TCHandlerT * const,
                              __status_int32_t * const);
} MngTCExecIface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const,
                         TCHandlerT * const, __status_int32_t * const,
                         _Bool * const);
    } pus_service_128;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const,
                         TCHandlerT * const, __status_int32_t * const);
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const,
                         TCHandlerT * const, __status_int32_t * const);
    } pus_service_2;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const,
                         TCHandlerT * const, __status_int32_t * const);
    } pus_service_17;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const,
                                   void * const, uint16_t * const);
    } tm_counter;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const, void * const,
                         __termina_box_t, __status_int32_t * const);
    } tm_channel;
} ManagerTCExecutor;

void ManagerTCExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev,
                                         void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const status,
                                         _Bool * const reebot_flag);

void ManagerTCExecutor__mng_tc_acceptation(const __termina_event_t * const __ev,
                                           void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const status);

void ManagerTCExecutor__mng_tc_rejection(const __termina_event_t * const __ev,
                                         void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         __status_int32_t * const status);

#endif
