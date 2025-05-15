
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 31 "src/tasks/icu_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 33 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 35 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(self->pus_service_17.__that, tc_handler,
                                     ret);

    } else
    #line 37 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 39 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(self->pus_service_2.__that, tc_handler,
                                    ret);

    } else
    #line 41 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 43 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(self->pus_service_9.__that, tc_handler,
                                    ret);

    } else
    {
        

    }

    #line 54 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__PUS_prio_exec_tc__mutex_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__PUS_prio_exec_tc(self, tc_handler, ret);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__PUS_prio_exec_tc__task_lock(void * const __this,
                                                    TCHandlerT * const tc_handler,
                                                    __status_int32_t * const ret) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, ret);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__PUS_prio_exec_tc__event_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, ret);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 59 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 59 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 60 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 64 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 62 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 66 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 67 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 73 "src/tasks/icu_manager/mng_tc_executor.fin"
        MyResult result;
        #line 73 "src/tasks/icu_manager/mng_tc_executor.fin"
        result.__variant = MyResult__Ok;

        #line 75 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_1((TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler->packet_header.packet_id,
                     tc_handler->packet_error_ctrl, current_obt, &result);

        #line 76 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                 &result);

    } else
    {
        
        #line 80 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).__variant = Failure;
        #line 80 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 84 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_acceptation__mutex_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__mng_tc_acceptation(self, tc_handler, ret);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__mng_tc_acceptation__task_lock(void * const __this,
                                                      const TCHandlerT * const tc_handler,
                                                      __status_int32_t * const ret) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__mng_tc_acceptation(__this, tc_handler, ret);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation__event_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       __status_int32_t * const ret) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__mng_tc_acceptation(__this, tc_handler, ret);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_rejection(void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 90 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 90 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 91 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 92 "src/tasks/icu_manager/mng_tc_executor.fin"
    TCStatus tc_status = try_tc_acceptation(&tc_handler->tc_descriptor);

    #line 96 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 94 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 98 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 99 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 101 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 101 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 101 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 105 "src/tasks/icu_manager/mng_tc_executor.fin"
        MyResult result;
        #line 105 "src/tasks/icu_manager/mng_tc_executor.fin"
        result.__variant = MyResult__Ok;

        #line 107 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_2(&tc_status, (TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler, current_obt, &result);

        #line 108 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                 &result);

    } else
    {
        
        #line 112 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).__variant = Failure;
        #line 112 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 115 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_rejection__mutex_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__mng_tc_rejection(self, tc_handler, ret);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__mng_tc_rejection__task_lock(void * const __this,
                                                    const TCHandlerT * const tc_handler,
                                                    __status_int32_t * const ret) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__mng_tc_rejection(__this, tc_handler, ret);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__mng_tc_rejection__event_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__mng_tc_rejection(__this, tc_handler, ret);
    __termina_event__unlock(lock);

}
