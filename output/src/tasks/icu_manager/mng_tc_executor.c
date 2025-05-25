
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const ret,
                                         _Bool * const reebot_flag) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 33 "src/tasks/icu_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 35 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 37 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(self->pus_service_17.__that, tc_handler,
                                     ret);

    } else
    #line 39 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 41 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(self->pus_service_2.__that, tc_handler,
                                    ret);

    } else
    #line 43 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 45 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(self->pus_service_9.__that, tc_handler,
                                    ret);

    } else
    #line 47 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 128U) {
        
        #line 49 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_128.exec_tc(self->pus_service_128.__that, tc_handler,
                                      ret, reebot_flag);

    } else
    {
        

    }

    #line 56 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__PUS_prio_exec_tc__mutex_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret,
                                                     _Bool * const reebot_flag) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__PUS_prio_exec_tc(self, tc_handler, ret, reebot_flag);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__PUS_prio_exec_tc__task_lock(void * const __this,
                                                    TCHandlerT * const tc_handler,
                                                    __status_int32_t * const ret,
                                                    _Bool * const reebot_flag) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, ret, reebot_flag);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__PUS_prio_exec_tc__event_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const ret,
                                                     _Bool * const reebot_flag) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, ret, reebot_flag);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 61 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 61 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 62 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 66 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 64 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 68 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 71 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 71 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 71 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 75 "src/tasks/icu_manager/mng_tc_executor.fin"
        MyResult result;
        #line 75 "src/tasks/icu_manager/mng_tc_executor.fin"
        result.__variant = MyResult__Ok;

        #line 76 "src/tasks/icu_manager/mng_tc_executor.fin"
        _Bool ack_enabled = 0;

        #line 78 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 79 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_1((TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler->packet_header.packet_id,
                     tc_handler->packet_error_ctrl,
                     tc_handler->df_header.flag_ver_ack, current_obt, &result,
                     &ack_enabled);

        #line 82 "src/tasks/icu_manager/mng_tc_executor.fin"
        if (ack_enabled) {
            
            #line 84 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

        } else
        {
            
            #line 87 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 93 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).__variant = Failure;
        #line 93 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 97 "src/tasks/icu_manager/mng_tc_executor.fin"
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

    #line 103 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 103 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 104 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 105 "src/tasks/icu_manager/mng_tc_executor.fin"
    TCStatus tc_status = try_tc_acceptation(&tc_handler->tc_descriptor);

    #line 109 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 107 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 111 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 112 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 114 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 114 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 114 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 118 "src/tasks/icu_manager/mng_tc_executor.fin"
        MyResult result;
        #line 118 "src/tasks/icu_manager/mng_tc_executor.fin"
        result.__variant = MyResult__Ok;

        #line 119 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 120 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_2(&tc_status, (TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler, current_obt, &result);

        #line 121 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                 &result);

    } else
    {
        
        #line 125 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).__variant = Failure;
        #line 125 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*ret).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 128 "src/tasks/icu_manager/mng_tc_executor.fin"
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
