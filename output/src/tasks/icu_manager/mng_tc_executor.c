
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const status, _Bool * const reebot_flag) {
    
    #line 59 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 59 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 61 "src/tasks/icu_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 63 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 65 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(__ev, self->pus_service_17.__that, tc_handler, status);

    } else
    #line 67 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(__ev, self->pus_service_2.__that, tc_handler, status);

    } else
    #line 71 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 73 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(__ev, self->pus_service_9.__that, tc_handler, status);

    } else
    #line 75 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 128U) {
        
        #line 77 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_128.exec_tc(__ev, self->pus_service_128.__that, tc_handler, status, reebot_flag);

    } else
    {
        
        #line 81 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, tc_handler->packet_header.packet_id, tc_handler->packet_header.packet_seq_ctrl, status);

    }

    #line 88 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 88 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_acceptation(const __termina_event_t * const __ev, void * const __this, const TCHandler * const tc_handler, __status_int32_t * const status) {
    
    #line 101 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 101 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 103 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->pus_service_1.notify_tm_1_1(__ev, self->pus_service_1.__that, tc_handler->packet_header.packet_id, tc_handler->packet_header.packet_seq_ctrl, tc_handler->df_header.flag_ver_ack, status);

    #line 109 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 109 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_rejection(const __termina_event_t * const __ev, void * const __this, const TCHandler * const tc_handler, const TCStatus * const tc_status, __status_int32_t * const status) {
    
    #line 122 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 122 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 124 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->pus_service_1.send_tm_1_2(__ev, self->pus_service_1.__that, tc_status, tc_handler, status);

    #line 126 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 126 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}
