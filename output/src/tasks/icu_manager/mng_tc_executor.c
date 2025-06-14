
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev,
                                         void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const status,
                                         _Bool * const reebot_flag) {
    
    #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 69 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 71 "src/tasks/icu_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 73 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 75 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(__ev, self->pus_service_17.__that,
                                     tc_handler, status);

    } else
    #line 77 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 79 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(__ev, self->pus_service_2.__that,
                                    tc_handler, status);

    } else
    #line 81 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 83 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(__ev, self->pus_service_9.__that,
                                    tc_handler, status);

    } else
    #line 85 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tc_type == 128U) {
        
        #line 87 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_128.exec_tc(__ev, self->pus_service_128.__that,
                                      tc_handler, status, reebot_flag);

    } else
    {
        
        #line 91 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 91 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 91 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 93 "src/tasks/icu_manager/mng_tc_executor.fin"
        __option_box_t tm_handler;
        #line 93 "src/tasks/icu_manager/mng_tc_executor.fin"
        tm_handler.__variant = None;

        #line 94 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        #line 98 "src/tasks/icu_manager/mng_tc_executor.fin"
        if (tm_handler.__variant == Some) {
            
            #line 96 "src/tasks/icu_manager/mng_tc_executor.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 100 "src/tasks/icu_manager/mng_tc_executor.fin"
            uint16_t tm_count = 0U;

            #line 101 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 103 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 104 "src/tasks/icu_manager/mng_tc_executor.fin"
            build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             tc_handler->packet_header.packet_id,
                                             tc_handler->packet_error_ctrl,
                                             current_obt, status);

            #line 107 "src/tasks/icu_manager/mng_tc_executor.fin"
            if ((*status).__variant == Success) {
                
                #line 109 "src/tasks/icu_manager/mng_tc_executor.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else
            {
                
                #line 112 "src/tasks/icu_manager/mng_tc_executor.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 118 "src/tasks/icu_manager/mng_tc_executor.fin"
            (*status).__variant = Failure;
            #line 118 "src/tasks/icu_manager/mng_tc_executor.fin"
            (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 124 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 124 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_acceptation(const __termina_event_t * const __ev,
                                           void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const status) {
    
    #line 137 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 137 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 139 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 139 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 140 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 144 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 142 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 146 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 147 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 149 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 149 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 149 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 154 "src/tasks/icu_manager/mng_tc_executor.fin"
        _Bool ack_enabled = 0;

        #line 156 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 157 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_1((TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler->packet_header.packet_id,
                     tc_handler->packet_error_ctrl,
                     tc_handler->df_header.flag_ver_ack, current_obt, status,
                     &ack_enabled);

        #line 160 "src/tasks/icu_manager/mng_tc_executor.fin"
        if (ack_enabled) {
            
            #line 162 "src/tasks/icu_manager/mng_tc_executor.fin"
            if ((*status).__variant == Success) {
                
                #line 165 "src/tasks/icu_manager/mng_tc_executor.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else
            {
                
                #line 169 "src/tasks/icu_manager/mng_tc_executor.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 174 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 180 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).__variant = Failure;
        #line 180 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 184 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 184 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}

void ManagerTCExecutor__mng_tc_rejection(const __termina_event_t * const __ev,
                                         void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         __status_int32_t * const status) {
    
    #line 197 "src/tasks/icu_manager/mng_tc_executor.fin"
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    #line 197 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 199 "src/tasks/icu_manager/mng_tc_executor.fin"
    __option_box_t tm_handler;
    #line 199 "src/tasks/icu_manager/mng_tc_executor.fin"
    tm_handler.__variant = None;

    #line 200 "src/tasks/icu_manager/mng_tc_executor.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 201 "src/tasks/icu_manager/mng_tc_executor.fin"
    TCStatus tc_status = try_tc_acceptation(&tc_handler->tc_descriptor);

    #line 205 "src/tasks/icu_manager/mng_tc_executor.fin"
    if (tm_handler.__variant == Some) {
        
        #line 203 "src/tasks/icu_manager/mng_tc_executor.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 207 "src/tasks/icu_manager/mng_tc_executor.fin"
        uint16_t tm_count = 0U;

        #line 208 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 210 "src/tasks/icu_manager/mng_tc_executor.fin"
        MissionObt current_obt;
        #line 210 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.finetime = 0U;
        #line 210 "src/tasks/icu_manager/mng_tc_executor.fin"
        current_obt.seconds = 0U;

        #line 215 "src/tasks/icu_manager/mng_tc_executor.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 216 "src/tasks/icu_manager/mng_tc_executor.fin"
        build_tm_1_2(&tc_status, (TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler, current_obt, status);

        #line 218 "src/tasks/icu_manager/mng_tc_executor.fin"
        if ((*status).__variant == Success) {
            
            #line 220 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 223 "src/tasks/icu_manager/mng_tc_executor.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 229 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).__variant = Failure;
        #line 229 "src/tasks/icu_manager/mng_tc_executor.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 232 "src/tasks/icu_manager/mng_tc_executor.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 232 "src/tasks/icu_manager/mng_tc_executor.fin"
    return;

}
