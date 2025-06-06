
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__manage_error_in_acceptance(const ManagerTCExecutor * const self,
                                                   const TCHandlerT * const tc_handler,
                                                   __status_int32_t * const status) {
    
    #line 68 "src/tasks/icu_manager/mng_tc_executor.fin"
    MissionObt current_obt;
    #line 68 "src/tasks/icu_manager/mng_tc_executor.fin"
    current_obt.finetime = 0U;
    #line 68 "src/tasks/icu_manager/mng_tc_executor.fin"
    current_obt.seconds = 0U;

    #line 70 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 70 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 71 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 75 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 73 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 77 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 78 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 80 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 81 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         tc_handler->packet_header.packet_id,
                                         tc_handler->packet_error_ctrl,
                                         current_obt, status);

        #line 84 "src/tasks/icu_manager/mng_tc_executor.fin"
        if ((*status).__variant == Success) {
            
            #line 86 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     status);

        } else
        {
            
            #line 89 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 95 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).__variant = Failure;
        #line 95 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 100 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const status,
                                         _Bool * const reebot_flag) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 115 "src/tasks/icu_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 117 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 119 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(self->pus_service_17.__that, tc_handler,
                                     status);

    } else
    #line 121 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 123 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(self->pus_service_2.__that, tc_handler,
                                    status);

    } else
    #line 125 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 127 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(self->pus_service_9.__that, tc_handler,
                                    status);

    } else
    #line 129 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 128U) {
        
        #line 131 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_128.exec_tc(self->pus_service_128.__that, tc_handler,
                                      status, reebot_flag);

    } else
    {
        
        #line 135 "src/tasks/icu_manager/mng_tc_executor.fin"
        ManagerTCExecutor__manage_error_in_acceptance(self, &*tc_handler,
                                                      status);

    }

    #line 138 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__PUS_prio_exec_tc__mutex_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const status,
                                                     _Bool * const reebot_flag) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__PUS_prio_exec_tc(self, tc_handler, status, reebot_flag);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__PUS_prio_exec_tc__task_lock(void * const __this,
                                                    TCHandlerT * const tc_handler,
                                                    __status_int32_t * const status,
                                                    _Bool * const reebot_flag) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, status,
                                        reebot_flag);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__PUS_prio_exec_tc__event_lock(void * const __this,
                                                     TCHandlerT * const tc_handler,
                                                     __status_int32_t * const status,
                                                     _Bool * const reebot_flag) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__PUS_prio_exec_tc(__this, tc_handler, status,
                                        reebot_flag);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const status) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 153 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 153 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 154 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 158 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 156 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 160 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 161 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 163 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 163 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 163 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 168 "src/tasks/icu_manager/mng_tc_executor.fin"
        _Bool ack_enabled = 0;

        #line 170 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 171 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_1((TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler->packet_header.packet_id,
                     tc_handler->packet_error_ctrl,
                     tc_handler->df_header.flag_ver_ack, current_obt, status,
                     &ack_enabled);

        #line 174 "src/tasks/icu_manager/mng_tc_executor.fin"
        if (ack_enabled) {
            
            #line 176 "src/tasks/icu_manager/mng_tc_executor.fin"
            if ((*status).__variant == Success) {
                
                #line 179 "src/tasks/icu_manager/mng_tc_executor.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         status);

            } else
            {
                
                #line 183 "src/tasks/icu_manager/mng_tc_executor.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 188 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 194 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).__variant = Failure;
        #line 194 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 198 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_acceptation__mutex_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       __status_int32_t * const status) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__mng_tc_acceptation(self, tc_handler, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__mng_tc_acceptation__task_lock(void * const __this,
                                                      const TCHandlerT * const tc_handler,
                                                      __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__mng_tc_acceptation(__this, tc_handler, status);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__mng_tc_acceptation__event_lock(void * const __this,
                                                       const TCHandlerT * const tc_handler,
                                                       __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__mng_tc_acceptation(__this, tc_handler, status);
    __termina_event__unlock(lock);

}

void ManagerTCExecutor__mng_tc_rejection(void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         __status_int32_t * const status) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 213 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 213 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 214 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 215 "src/tasks/icu_manager/mng_tc_executor.fin"
    TCStatus tc_status = try_tc_acceptation(&tc_handler->tc_descriptor);

    #line 219 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 217 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 221 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 222 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 224 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 224 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 224 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 229 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 230 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_2(&tc_status, (TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler, current_obt, status);

        #line 232 "src/tasks/icu_manager/mng_tc_executor.fin"
        if ((*status).__variant == Success) {
            
            #line 234 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     status);

        } else
        {
            
            #line 237 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 243 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).__variant = Failure;
        #line 243 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 246 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_rejection__mutex_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     __status_int32_t * const status) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    ManagerTCExecutor__mng_tc_rejection(self, tc_handler, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void ManagerTCExecutor__mng_tc_rejection__task_lock(void * const __this,
                                                    const TCHandlerT * const tc_handler,
                                                    __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    ManagerTCExecutor__mng_tc_rejection(__this, tc_handler, status);
    __termina_task__unlock(lock);

}

void ManagerTCExecutor__mng_tc_rejection__event_lock(void * const __this,
                                                     const TCHandlerT * const tc_handler,
                                                     __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    ManagerTCExecutor__mng_tc_rejection(__this, tc_handler, status);
    __termina_event__unlock(lock);

}
