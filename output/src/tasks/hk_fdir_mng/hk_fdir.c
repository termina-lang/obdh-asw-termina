
#include "tasks/hk_fdir_mng/hk_fdir.h"

const size_t num_actions_per_second = 2U;

__status_int32_t HouseKeepingFDIR__do_fdir(HouseKeepingFDIR * const self) {
    
    #line 64 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 64 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 66 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    _Bool is_monitor_enabled = 0;

    #line 68 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    for (size_t i = 0U; i < 8U; i = i + 1U) {
        
        #line 70 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_12.is_PMON_enabled(self->pus_service_12.__that, i,
                                             &is_monitor_enabled);

        #line 72 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (is_monitor_enabled) {
            
            #line 74 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            uint16_t evID = 0U;

            #line 75 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            FaultInfo fault_info;
            #line 75 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            fault_info.__variant = FaultInfo__Empty;

            #line 76 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            _Bool event_triggered = 0;

            #line 78 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->pus_service_12.do_monitoring(self->pus_service_12.__that,
                                               (uint16_t)i, &evID, &fault_info,
                                               &event_triggered);

            #line 80 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            if (event_triggered) {
                
                #line 82 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                _Bool is_Ev_ID_enabled = 0;

                #line 83 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                self->pus_service_5.is_Ev_ID_enabled_ext(self->pus_service_5.__that,
                                                         evID,
                                                         &is_Ev_ID_enabled);

                #line 85 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                if (is_Ev_ID_enabled) {
                    
                    #line 87 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                    self->pus_service_5.build_and_tx_tm_5_x(self->pus_service_5.__that,
                                                            &result, evID,
                                                            fault_info);

                    #line 88 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                    self->pus_service_19.manage_event_action(self->pus_service_19.__that,
                                                             evID);

                }

            }

        }

    }

    #line 99 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return result;

}

__status_int32_t HouseKeepingFDIR__do_hk_fdir(void * const __this,
                                              TimeVal _current_time) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 110 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 110 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 112 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_3.update_params(self->pus_service_3.__that);

    #line 113 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_4.update_all_stats(self->pus_service_4.__that);

    #line 114 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_3.do_hk(self->pus_service_3.__that, &result);

    #line 115 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result = HouseKeepingFDIR__do_fdir(self);

    #line 117 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    size_t pending_actions[4U];
    #line 117 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 117 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        pending_actions[__i0] = 0U;
    }

    #line 118 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_19.get_pending_action_number(self->pus_service_19.__that,
                                                   pending_actions);

    #line 120 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    size_t n = 4U;

    #line 122 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[3U] > 0U) {
        
        #line 124 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 3U;

    } else
    #line 126 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[2U] > 0U) {
        
        #line 128 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 2U;

    } else
    #line 130 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[1U] > 0U) {
        
        #line 132 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 1U;

    } else
    #line 134 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[0U] > 0U) {
        
        #line 136 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 0U;

    } else
    {
        

    }

    #line 142 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (n < 4U) {
        
        #line 144 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        __option_box_t tc_handler;
        #line 144 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        tc_handler.__variant = None;

        #line 145 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->a_tc_handler_pool.alloc(self->a_tc_handler_pool.__that,
                                      &tc_handler);

        #line 149 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (tc_handler.__variant == Some) {
            
            #line 147 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            #line 151 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->pus_service_19.extract_action(self->pus_service_19.__that, n,
                                                (TCHandlerT *)b_tc_handler.data);

            #line 152 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            __termina_out_port__send(self->action_tc_message_queue_output,
                                     (void *)&b_tc_handler);

        } else
        {
            
            #line 156 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            result.__variant = Failure;
            #line 156 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            result.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 163 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return result;

}

void HouseKeepingFDIR__manage_error_in_acceptance(const HouseKeepingFDIR * const self,
                                                  const TCHandlerT * const tc_handler,
                                                  __status_int32_t * const ret) {
    
    #line 173 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    MyResult result;
    #line 173 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = MyResult__Ok;

    #line 175 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    MissionObt current_obt;
    #line 175 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    current_obt.finetime = 0U;
    #line 175 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    current_obt.seconds = 0U;

    #line 177 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __option_box_t tm_handler;
    #line 177 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    tm_handler.__variant = None;

    #line 178 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 182 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tm_handler.__variant == Some) {
        
        #line 180 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 184 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        uint16_t tm_count = 0U;

        #line 185 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 187 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 188 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         tc_handler->packet_header.packet_id,
                                         tc_handler->packet_error_ctrl,
                                         current_obt, &result);

        #line 191 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 193 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

        } else
        {
            
            #line 196 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 202 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        (*ret).__variant = Failure;
        #line 202 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        (*ret).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 207 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return;

}

__status_int32_t HouseKeepingFDIR__exec_tc(void * const __this,
                                           __termina_box_t tc_handler) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 217 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t res;
    #line 217 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    res.__variant = Success;

    #line 219 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    uint8_t tc_type = (*(TCHandlerT *)tc_handler.data).df_header.type;

    #line 221 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 3U) {
        
        #line 223 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_3.exec_tc(self->pus_service_3.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 225 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 5U) {
        
        #line 227 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_5.exec_tc(self->pus_service_5.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 229 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 12U) {
        
        #line 231 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_12.exec_tc(self->pus_service_12.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 233 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 19U) {
        
        #line 235 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_19.exec_tc(self->pus_service_19.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 238 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 4U) {
        
        #line 240 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_4.exec_tc(self->pus_service_4.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else
    {
        
        #line 244 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        HouseKeepingFDIR__manage_error_in_acceptance(self,
                                                     (TCHandlerT *)tc_handler.data,
                                                     &res);

    }

    #line 248 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that, tc_handler);

    #line 250 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return res;

}

void __HouseKeepingFDIR__termina_task(void * arg) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)arg;

    int32_t status = 0L;

    __termina_id_t next_msg = 0U;

    __status_int32_t result;
    result.__variant = Success;

    TimeVal do_hk_fdir__msg_data;
    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status != 0L) {
            break;
        }

        switch (next_msg) {
            
            case __HouseKeepingFDIR__hk_fdir_timer_ev:

                __termina_msg_queue__recv(self->hk_fdir_timer_ev,
                                          (void *)&do_hk_fdir__msg_data,
                                          &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->hk_fdir_timer_ev,
                                                           status);
                }

                result = HouseKeepingFDIR__do_hk_fdir(self,
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

                result = HouseKeepingFDIR__exec_tc(self, exec_tc__msg_data);

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
