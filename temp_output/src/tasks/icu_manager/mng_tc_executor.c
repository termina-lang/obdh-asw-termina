
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         TCHandlerT * const tc_handler,
                                         Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    uint8_t tc_type = tc_handler->df_header.type;

    if (tc_type == 17U) {
        
        (self->pus_service_17.exec_tc)(self->pus_service_17.__that, tc_handler,
                                       ret);

    } else if (tc_type == 2U) {
        
        (self->pus_service_2.exec_tc)(self->pus_service_2.__that, tc_handler,
                                      ret);

    } else {
        
        (*ret).__variant = Result__Error;

    }

    return;

}

void ManagerTCExecutor__PUS_prio_exec_tc__mutex_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    ManagerTCExecutor__PUS_prio_exec_tc(self, tc_handler, ret);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void ManagerTCExecutor__PUS_prio_exec_tc__task_lock(void * const __this,
                                                    TCHandlerT * const tc_handler,
                                                    Result * const ret) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, ret);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__PUS_prio_exec_tc__event_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     Result * const ret) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, ret);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_1((TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler->packet_header.packet_id,
                     tc_handler->packet_error_ctrl, ret);

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler, ret);

    } else {
        
        (*ret).__variant = Result__Error;

    }

    return;

}

void ManagerTCExecutor__mng_tc_acceptation__mutex_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    ManagerTCExecutor__mng_tc_acceptation(self, tc_handler, ret);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void ManagerTCExecutor__mng_tc_acceptation__task_lock(void * const __this,
                                                      const TCHandlerT * const tc_handler,
                                                      Result * const ret) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__mng_tc_acceptation(__this, tc_handler, ret);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation__event_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       Result * const ret) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__mng_tc_acceptation(__this, tc_handler, ret);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_rejection(void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    TCStatus tc_status = try_tc_acceptation(&tc_handler->tc_descriptor);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_2(&tc_status, (TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler, ret);

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler, ret);

    } else {
        
        (*ret).__variant = Result__Error;

    }

    return;

}

void ManagerTCExecutor__mng_tc_rejection__mutex_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    ManagerTCExecutor__mng_tc_rejection(self, tc_handler, ret);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void ManagerTCExecutor__mng_tc_rejection__task_lock(void * const __this,
                                                    const TCHandlerT * const tc_handler,
                                                    Result * const ret) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__mng_tc_rejection(__this, tc_handler, ret);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__mng_tc_rejection__event_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     Result * const ret) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__mng_tc_rejection(__this, tc_handler, ret);
    __termina_event__unlock(lock);

}
