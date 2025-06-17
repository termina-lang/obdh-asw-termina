
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(const __termina_event_t * const __ev,
                                         void * const __this,
                                         TCHandlerT * const tc_handler,
                                         __status_int32_t * const status,
                                         _Bool * const reebot_flag) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    uint8_t tc_type = tc_handler->df_header.type;

    if (tc_type == 17U) {
        
        self->pus_service_17.exec_tc(__ev, self->pus_service_17.__that,
                                     tc_handler, status);

    } else if (tc_type == 2U) {
        
        self->pus_service_2.exec_tc(__ev, self->pus_service_2.__that,
                                    tc_handler, status);

    } else if (tc_type == 9U) {
        
        self->pus_service_9.exec_tc(__ev, self->pus_service_9.__that,
                                    tc_handler, status);

    } else if (tc_type == 128U) {
        
        self->pus_service_128.exec_tc(__ev, self->pus_service_128.__that,
                                      tc_handler, status, reebot_flag);

    } else {
        
        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        __option_box_t tm_handler;
        tm_handler.__variant = None;

        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        if (tm_handler.__variant == Some) {
            
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            uint16_t tm_count = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             tc_handler->packet_header.packet_id,
                                             tc_handler->packet_error_ctrl,
                                             current_obt, status);

            if ((*status).__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            (*status).__variant = Failure;
            (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void ManagerTCExecutor__mng_tc_acceptation(const __termina_event_t * const __ev,
                                           void * const __this,
                                           const TCHandlerT * const tc_handler,
                                           __status_int32_t * const status) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        _Bool ack_enabled = 0;

        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_1((TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler->packet_header.packet_id,
                     tc_handler->packet_error_ctrl,
                     tc_handler->df_header.flag_ver_ack, current_obt, status,
                     &ack_enabled);

        if (ack_enabled) {
            
            if ((*status).__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else {
        
        (*status).__variant = Failure;
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void ManagerTCExecutor__mng_tc_rejection(const __termina_event_t * const __ev,
                                         void * const __this,
                                         const TCHandlerT * const tc_handler,
                                         __status_int32_t * const status) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    TCStatus tc_status = try_tc_acceptation(&tc_handler->tc_descriptor);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_2(&tc_status, (TMHandlerT *)b_tm_handler.data, tm_count,
                     tc_handler, current_obt, status);

        if ((*status).__variant == Success) {
            
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else {
            
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else {
        
        (*status).__variant = Failure;
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
