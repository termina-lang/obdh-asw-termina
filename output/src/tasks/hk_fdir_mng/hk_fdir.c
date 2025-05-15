
#include "tasks/hk_fdir_mng/hk_fdir.h"

const size_t num_actions_per_second = 2U;

__status_int32_t HouseKeepingFDIR__do_fdir(HouseKeepingFDIR * const self) {
    
    #line 30 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 30 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 32 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    _Bool is_monitor_enabled = 0;

    #line 34 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    for (size_t i = 0U; i < 8U; i = i + 1U) {
        
        #line 36 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_12.is_PMON_enabled(self->pus_service_12.__that, i,
                                             &is_monitor_enabled);

        #line 38 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (is_monitor_enabled) {
            
            #line 40 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            uint16_t evID = 0U;

            #line 41 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            FaultInfo fault_info;
            #line 41 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            fault_info.__variant = FaultInfo__Empty;

            #line 42 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            _Bool event_triggered = 0;

            #line 44 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->pus_service_12.do_monitoring(self->pus_service_12.__that,
                                               (uint16_t)i, &evID, &fault_info,
                                               &event_triggered);

            #line 46 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            if (event_triggered) {
                
                #line 48 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                _Bool is_Ev_ID_enabled = 0;

                #line 49 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                self->pus_service_5.is_Ev_ID_enabled_ext(self->pus_service_5.__that,
                                                         evID,
                                                         &is_Ev_ID_enabled);

                #line 51 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                if (is_Ev_ID_enabled) {
                    
                    #line 53 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                    self->pus_service_5.build_and_tx_tm_5_x(self->pus_service_5.__that,
                                                            &result, evID,
                                                            fault_info);

                    #line 54 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                    self->pus_service_19.manage_event_action(self->pus_service_19.__that,
                                                             evID);

                }

            }

        }

    }

    #line 65 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return result;

}

__status_int32_t HouseKeepingFDIR__do_hk_fdir(void * const __this,
                                              TimeVal _current_time) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 70 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 70 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 72 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_4.update_all_stats(self->pus_service_4.__that);

    #line 73 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_3.do_hk(self->pus_service_3.__that, &result);

    #line 74 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result = HouseKeepingFDIR__do_fdir(self);

    #line 76 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    size_t pending_actions[4U];
    #line 76 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 76 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        pending_actions[__i0] = 0U;
    }

    #line 77 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_19.get_pending_action_number(self->pus_service_19.__that,
                                                   pending_actions);

    #line 79 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    size_t n = 4U;

    #line 81 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[3U] > 0U) {
        
        #line 83 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 3U;

    } else
    #line 85 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[2U] > 0U) {
        
        #line 87 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 2U;

    } else
    #line 89 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[1U] > 0U) {
        
        #line 91 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 1U;

    } else
    #line 93 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[0U] > 0U) {
        
        #line 95 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 0U;

    } else
    {
        

    }

    #line 101 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (n < 4U) {
        
        #line 103 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        __option_box_t tc_handler;
        #line 103 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        tc_handler.__variant = None;

        #line 104 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->a_tc_handler_pool.alloc(self->a_tc_handler_pool.__that,
                                      &tc_handler);

        #line 108 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (tc_handler.__variant == Some) {
            
            #line 106 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            #line 110 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->pus_service_19.extract_action(self->pus_service_19.__that, n,
                                                (TCHandlerT *)b_tc_handler.data);

            #line 111 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            __termina_out_port__send(self->action_tc_message_queue_output,
                                     (void *)&b_tc_handler);

        } else
        {
            
            #line 115 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            result.__variant = Failure;
            #line 115 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            result.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 122 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return result;

}

__status_int32_t HouseKeepingFDIR__exec_tc(void * const __this,
                                           __termina_box_t tc_handler) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 127 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t res;
    #line 127 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    res.__variant = Success;

    #line 129 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    uint8_t tc_type = (*(TCHandlerT *)tc_handler.data).df_header.type;

    #line 131 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 3U) {
        
        #line 133 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_3.exec_tc(self->pus_service_3.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 135 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 5U) {
        
        #line 137 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_5.exec_tc(self->pus_service_5.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 139 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 12U) {
        
        #line 141 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_12.exec_tc(self->pus_service_12.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 143 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 19U) {
        
        #line 145 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_19.exec_tc(self->pus_service_19.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else
    #line 148 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 4U) {
        
        #line 150 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_4.exec_tc(self->pus_service_4.__that,
                                    (TCHandlerT *)tc_handler.data, &res);

    } else
    {
        
        #line 154 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        res.__variant = Failure;
        #line 154 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        res.Failure.__0 = ACCEPTANCE_ERROR;

    }

    #line 159 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that, tc_handler);

    #line 161 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return res;

}

void __HouseKeepingFDIR__termina_task(void * arg) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)arg;

    int32_t status = 0L;

    uint32_t next_msg = 0U;

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
