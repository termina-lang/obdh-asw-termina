
#include "tasks/hk_fdir_mng/hk_fdir.h"

const size_t num_actions_per_second = 2U;

__status_int32_t HouseKeepingFDIR__do_fdir(const __termina_event_t * const __ev,
                                           HouseKeepingFDIR * const self) {
    
    __status_int32_t result;
    result.__variant = Success;

    _Bool is_monitor_enabled = 0;

    for (size_t i = 0U; i < 8U; i = i + 1U) {
        
        self->pus_service_12.is_PMON_enabled(__ev, self->pus_service_12.__that,
                                             i, &is_monitor_enabled);

        if (is_monitor_enabled) {
            
            uint16_t evID = 0U;

            FaultInfo fault_info;
            fault_info.__variant = FaultInfo__Empty;

            _Bool event_triggered = 0;

            self->pus_service_12.do_monitoring(__ev,
                                               self->pus_service_12.__that,
                                               (uint16_t)i, &evID, &fault_info,
                                               &event_triggered);

            if (event_triggered) {
                
                _Bool is_Ev_ID_enabled = 0;

                self->pus_service_5.is_Ev_ID_enabled_ext(__ev,
                                                         self->pus_service_5.__that,
                                                         evID,
                                                         &is_Ev_ID_enabled);

                if (is_Ev_ID_enabled) {
                    
                    self->pus_service_5.build_and_tx_tm_5_x(__ev,
                                                            self->pus_service_5.__that,
                                                            &result, evID,
                                                            fault_info);

                    self->pus_service_19.manage_event_action(__ev,
                                                             self->pus_service_19.__that,
                                                             evID);

                }

            }

        }

    }

    return result;

}

__status_int32_t HouseKeepingFDIR__do_hk_fdir(const __termina_event_t * const __ev,
                                              void * const __this,
                                              TimeVal _current_time) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    __status_int32_t result;
    result.__variant = Success;

    self->pus_service_3.update_params(__ev, self->pus_service_3.__that);

    self->pus_service_4.update_all_stats(__ev, self->pus_service_4.__that);

    self->pus_service_3.do_hk(__ev, self->pus_service_3.__that, &result);

    result = HouseKeepingFDIR__do_fdir(__ev, self);

    size_t pending_actions[4U];
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pending_actions[__i0] = 0U;
    }

    self->pus_service_19.get_pending_action_number(__ev,
                                                   self->pus_service_19.__that,
                                                   pending_actions);

    size_t n = 4U;

    if (pending_actions[3U] > 0U) {
        
        n = 3U;

    } else if (pending_actions[2U] > 0U) {
        
        n = 2U;

    } else if (pending_actions[1U] > 0U) {
        
        n = 1U;

    } else if (pending_actions[0U] > 0U) {
        
        n = 0U;

    } else {
        

    }

    if (n < 4U) {
        
        __option_box_t tc_handler;
        tc_handler.__variant = None;

        self->a_tc_handler_pool.alloc(__ev, self->a_tc_handler_pool.__that,
                                      &tc_handler);

        if (tc_handler.__variant == Some) {
            
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            self->pus_service_19.extract_action(__ev,
                                                self->pus_service_19.__that, n,
                                                (TCHandlerT *)b_tc_handler.data);

            __termina_out_port__send(__ev, self->action_tc_message_queue_output,
                                     (void *)&b_tc_handler);

        } else {
            
            result.__variant = Failure;
            result.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    return result;

}

__status_int32_t HouseKeepingFDIR__exec_tc(const __termina_event_t * const __ev,
                                           void * const __this,
                                           __termina_box_t tc_handler) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    __status_int32_t res;
    res.__variant = Success;

    uint8_t tc_type = (*(TCHandlerT *)tc_handler.data).df_header.type;

    if (tc_type == 3U) {
        
        self->pus_service_3.exec_tc(__ev, self->pus_service_3.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 5U) {
        
        self->pus_service_5.exec_tc(__ev, self->pus_service_5.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 12U) {
        
        self->pus_service_12.exec_tc(__ev, self->pus_service_12.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 19U) {
        
        self->pus_service_19.exec_tc(__ev, self->pus_service_19.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 4U) {
        
        self->pus_service_4.exec_tc(__ev, self->pus_service_4.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else {
        
        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        __status_int32_t status;
        status.__variant = Success;

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
                                             (*(TCHandlerT *)tc_handler.data).packet_header.packet_id,
                                             (*(TCHandlerT *)tc_handler.data).packet_error_ctrl,
                                             current_obt, &status);

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

    }

    self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                 tc_handler);

    return res;

}

void __HouseKeepingFDIR__termina_task(void * arg) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)arg;

    int32_t status = 0L;

    __termina_event_t event;

    __status_int32_t result;
    result.__variant = Success;

    TimeVal do_hk_fdir__msg_data;
    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &event, &status);

        if (status != 0L) {
            break;
        }

        switch (event.port_id) {
            
            case __HouseKeepingFDIR__hk_fdir_timer_ev:

                __termina_msg_queue__recv(self->hk_fdir_timer_ev,
                                          (void *)&do_hk_fdir__msg_data,
                                          &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->hk_fdir_timer_ev,
                                                           status);
                }

                result = HouseKeepingFDIR__do_hk_fdir(&event, self,
                                                      do_hk_fdir__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __HouseKeepingFDIR__hk_fdir_timer_ev,
                                                     result.Failure.__0);

                }

                break;

            case __HouseKeepingFDIR__hkfdir_message_queue_input:

                __termina_msg_queue__recv(self->hkfdir_message_queue_input,
                                          (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->hkfdir_message_queue_input,
                                                           status);
                }

                result = HouseKeepingFDIR__exec_tc(&event, self,
                                                   exec_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __HouseKeepingFDIR__hkfdir_message_queue_input,
                                                     result.Failure.__0);

                }

                break;

            default:

                __termina_exec__reboot();

                break;

        }

    }

    return;

}
