#ifndef __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__
#define __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__

#include <termina.h>

#include "resources/tm_channel.h"
#include "resources/tm_counter.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service128.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* PUS_prio_exec_tc)(void * const, TCHandlerT * const,
                              __status_int32_t * const);
    void (* mng_tc_acceptation)(void * const, const TCHandlerT * const,
                                __status_int32_t * const);
    void (* mng_tc_rejection)(void * const, const TCHandlerT * const,
                              __status_int32_t * const);
} MngTCExecIface;

typedef struct {
    __termina_id_t __mutex_id;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const,
                         __status_int32_t * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const,
                         __status_int32_t * const);
    } pus_service_2;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const,
                         __status_int32_t * const);
    } pus_service_17;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
} ManagerTCExecutor;

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const ret);
void ManagerTCExecutor__PUS_prio_exec_tc__mutex_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret);
void ManagerTCExecutor__PUS_prio_exec_tc__task_lock(void * const __this,
                                                    TCHandlerT * const tc_handler,
                                                    __status_int32_t * const ret);
void ManagerTCExecutor__PUS_prio_exec_tc__event_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret);

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const ret);
void ManagerTCExecutor__mng_tc_acceptation__mutex_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       __status_int32_t * const ret);
void ManagerTCExecutor__mng_tc_acceptation__task_lock(void * const __this,
                                                      const TCHandlerT * const tc_handler,
                                                      __status_int32_t * const ret);
void ManagerTCExecutor__mng_tc_acceptation__event_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       __status_int32_t * const ret);

void ManagerTCExecutor__mng_tc_rejection(void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         __status_int32_t * const ret);
void ManagerTCExecutor__mng_tc_rejection__mutex_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret);
void ManagerTCExecutor__mng_tc_rejection__task_lock(void * const __this,
                                                    const TCHandlerT * const tc_handler,
                                                    __status_int32_t * const ret);
void ManagerTCExecutor__mng_tc_rejection__event_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret);

#endif
