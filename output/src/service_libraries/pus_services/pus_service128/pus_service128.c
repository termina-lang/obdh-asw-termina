
#include "service_libraries/pus_services/pus_service128/pus_service128.h"

__status_int32_t PUSService128__exec128_1TC(const __termina_event_t * const __ev,
                                            PUSService128 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    _Bool ack_enabled = 0;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler1;
    tm_handler1.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler1);

    if (tm_handler1.__variant == Some) {
        
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        uint16_t tm_count1 = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count1);

        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &status, &ack_enabled);

        if (ack_enabled) {
            
            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler1, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

            }

        } else {
            
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    self->exec_tc_req_status_update.reebot_flag = 1;

    if (status.__variant == Success) {
        
        __option_box_t tm_handler2;
        tm_handler2.__variant = None;

        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        if (tm_handler2.__variant == Some) {
            
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            uint16_t tm_count2 = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count2);

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &status, &ack_enabled);

            if (ack_enabled) {
                
                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else {
            
            status.__variant = Failure;
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    return status;

}

void PUSService128__exec_tc(const __termina_event_t * const __ev,
                            void * const __this, TCHandlerT * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag) {
    
    PUSService128 * self = (PUSService128 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (subtype == 1U) {
                
                status = PUSService128__exec128_1TC(__ev, self);

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else {
            

        }

    }

    if (status.__variant == Success) {
        
        (*action_status).__variant = Success;

    } else {
        
        int32_t error_code = status.Failure.__0;

        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR) {
            
            (*action_status).__variant = Success;

            __option_box_t tm_handler;
            tm_handler.__variant = None;

            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            if (tm_handler.__variant == Some) {
                
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                uint16_t tm_count = 0U;

                MissionObt current_obt;
                current_obt.finetime = 0U;
                current_obt.seconds = 0U;

                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                if (error_code == ACCEPTANCE_ERROR) {
                    
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     current_obt, &status);

                } else if (error_code == BUILD_TM_ERROR) {
                    
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                                         current_obt, &status);

                } else {
                    

                }

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else {
            
            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = error_code;

        }

    }

    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    *reebot_flag = self->exec_tc_req_status_update.reebot_flag;

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
