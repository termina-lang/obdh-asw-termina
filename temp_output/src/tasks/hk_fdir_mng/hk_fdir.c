
#include "tasks/hk_fdir_mng/hk_fdir.h"

const size_t num_actions_per_second = 2U;

Result HouseKeepingFDIR__do_fdir(HouseKeepingFDIR * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    _Bool is_monitor_enabled = 0;

    for (size_t i = 0U; i < max_num_pmon_ids; i = i + 1U) {
        
        (self->pus_service_12.is_PMON_enabled)(self->pus_service_12.__that, i,
                                               &is_monitor_enabled);

        if (is_monitor_enabled) {
            
            uint16_t evID = 0U;

            FaultInfo fault_info;
            fault_info.__variant = FaultInfo__Empty;

            _Bool event_triggered = 0;

            (self->pus_service_12.do_monitoring)(self->pus_service_12.__that,
                                                 (uint16_t)i, &evID,
                                                 &fault_info, &event_triggered);

            if (event_triggered) {
                
                _Bool is_Ev_ID_enabled = 0;

                (self->pus_service_5.is_Ev_ID_enabled_ext)(self->pus_service_5.__that,
                                                           evID,
                                                           &is_Ev_ID_enabled);

                if (is_Ev_ID_enabled) {
                    
                    (self->pus_service_5.build_and_tx_tm_5_x)(self->pus_service_5.__that,
                                                              &result, evID,
                                                              fault_info);

                    (self->pus_service_19.manage_event_action)(self->pus_service_19.__that,
                                                               evID);

                }

            }

        }

    }

    return result;

}

Result HouseKeepingFDIR__do_hk_fdir(void * const __this,
                                    TimeVal _current_time) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    Result result;
    result.__variant = Result__Ok;

    (self->pus_service_4.update_all_stats)(self->pus_service_4.__that, &result);

    (self->pus_service_3.do_hk)(self->pus_service_3.__that, &result);

    result = HouseKeepingFDIR__do_fdir(self);

    size_t pending_actions[4U];
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pending_actions[__i0] = 0U;
    }

    (self->pus_service_19.get_pending_action_number)(self->pus_service_19.__that,
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

        (self->a_tc_handler_pool.alloc)(self->a_tc_handler_pool.__that,
                                        &tc_handler);

        if (tc_handler.__variant == Some) {
            
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            (self->pus_service_19.extract_action)(self->pus_service_19.__that,
                                                  n,
                                                  (TCHandlerT *)b_tc_handler.data);

            __termina_out_port__send(self->action_tc_message_queue_output,
                                     (void *)&b_tc_handler);

        } else {
            

        }

    }

    return result;

}

Result HouseKeepingFDIR__exec_tc(void * const __this,
                                 __termina_box_t tc_handler) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    Result res;
    res.__variant = Result__Ok;

    uint8_t tc_type = (*(TCHandlerT *)tc_handler.data).df_header.type;

    if (tc_type == 3U) {
        
        (self->pus_service_3.exec_tc)(self->pus_service_3.__that,
                                      (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 5U) {
        
        (self->pus_service_5.exec_tc)(self->pus_service_5.__that,
                                      (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 12U) {
        
        (self->pus_service_12.exec_tc)(self->pus_service_12.__that,
                                       (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 19U) {
        
        (self->pus_service_19.exec_tc)(self->pus_service_19.__that,
                                       (TCHandlerT *)tc_handler.data, &res);

    } else if (tc_type == 4U) {
        
        (self->pus_service_4.exec_tc)(self->pus_service_4.__that,
                                      (TCHandlerT *)tc_handler.data, &res);

    } else {
        
        res.__variant = Result__Error;

    }

    (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that, tc_handler);

    return res;

}

void __HouseKeepingFDIR__termina_task(void * arg) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)arg;

    Status status;
    status.__variant = Status__Success;

    uint32_t next_msg = 0U;

    Result result;
    result.__variant = Result__Ok;

    TimeVal do_hk_fdir__msg_data;
    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status.__variant != Status__Success) {
            break;
        }

        switch (next_msg) {
            
            case __HouseKeepingFDIR__hk_fdir_timer_ev:

                __termina_msg_queue__recv(self->hk_fdir_timer_ev,
                                          (void *)&do_hk_fdir__msg_data,
                                          &status);

                if (status.__variant != Status__Success) {
                    __termina_exec__shutdown();
                }

                result = HouseKeepingFDIR__do_hk_fdir(self,
                                                      do_hk_fdir__msg_data);

                if (result.__variant != Result__Ok) {
                    __termina_exec__shutdown();
                }

                break;

            case __HouseKeepingFDIR__hkfdir_message_queue_input:

                __termina_msg_queue__recv(self->hkfdir_message_queue_input,
                                          (void *)&exec_tc__msg_data, &status);

                if (status.__variant != Status__Success) {
                    __termina_exec__shutdown();
                }

                result = HouseKeepingFDIR__exec_tc(self, exec_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    __termina_exec__shutdown();
                }

                break;

            default:

                __termina_exec__shutdown();

                break;

        }

    }

    __termina_exec__shutdown();

    return;

}
