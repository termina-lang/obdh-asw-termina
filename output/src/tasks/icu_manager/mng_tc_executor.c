
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev,
                                         void * const __this,
                                         TCHandler * const tc_handler,
                                         __status_int32_t * const status,
                                         _Bool * const reebot_flag) {
    
    #line 58 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 58 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 60 "src/tasks/icu_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 62 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 64 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(__ev, self->pus_service_17.__that,
                                     tc_handler, status);

    } else
    #line 66 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 68 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(__ev, self->pus_service_2.__that,
                                    tc_handler, status);

    } else
    #line 70 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 72 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(__ev, self->pus_service_9.__that,
                                    tc_handler, status);

    } else
    #line 74 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 128U) {
        
        #line 76 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_128.exec_tc(__ev, self->pus_service_128.__that,
                                      tc_handler, status, reebot_flag);

    } else
    {
        
        #line 80 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                            self->pus_service_1.__that,
                                                            tc_handler->packet_header.packet_id,
                                                            tc_handler->packet_header.packet_seq_ctrl,
                                                            status);

    }

    #line 87 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 87 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_acceptation(const __termina_event_t * const __ev,
                                           void * const __this,
                                           const TCHandler * const tc_handler,
                                           __status_int32_t * const status) {
    
    #line 100 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 100 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 102 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->pus_service_1.notify_tm_1_1(__ev, self->pus_service_1.__that,
                                      tc_handler->packet_header.packet_id,
                                      tc_handler->packet_header.packet_seq_ctrl,
                                      tc_handler->df_header.flag_ver_ack,
                                      status);

    #line 108 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 108 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_rejection(const __termina_event_t * const __ev,
                                         void * const __this,
                                         const TCHandler * const tc_handler,
                                         const TCStatus * const tc_status,
                                         __status_int32_t * const status) {
    
    #line 121 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 121 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 123 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->pus_service_1.send_tm_1_2(__ev, self->pus_service_1.__that, tc_status,
                                    tc_handler, status);

    #line 125 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 125 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}
