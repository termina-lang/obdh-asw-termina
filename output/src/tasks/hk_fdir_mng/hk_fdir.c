
#include "tasks/hk_fdir_mng/hk_fdir.h"

const size_t num_actions_per_second = 2U;

__status_int32_t HouseKeepingFDIR__check_pending_actions(const __termina_event_t * const __ev, void * const __this) {
    
    #line 96 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 98 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 98 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 100 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    size_t pending_actions[4U];
    #line 100 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 100 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        pending_actions[__i0] = 0U;
    }

    #line 101 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_19.get_pending_action_number(__ev, self->pus_service_19.__that, pending_actions);

    #line 103 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    size_t n = 4U;

    #line 105 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[3U] > 0U) {
        
        #line 107 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 3U;

    } else
    #line 109 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[2U] > 0U) {
        
        #line 111 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 2U;

    } else
    #line 113 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[1U] > 0U) {
        
        #line 115 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 1U;

    } else
    #line 117 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (pending_actions[0U] > 0U) {
        
        #line 119 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        n = 0U;

    } else
    {
        

    }

    #line 125 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (n < 4U) {
        
        #line 127 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        __option_box_t tc_handler;
        #line 127 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        tc_handler.__variant = None;

        #line 128 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->a_tc_handler_pool.alloc(__ev, self->a_tc_handler_pool.__that, &tc_handler);

        #line 132 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (tc_handler.__variant == Some) {
            
            #line 132 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            #line 134 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->pus_service_19.extract_action(__ev, self->pus_service_19.__that, n, (TCHandler *)b_tc_handler.data);

            #line 135 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            __termina_out_port__send(__ev, self->action_tc_message_queue_output, (void *)&b_tc_handler);

        } else
        {
            
            #line 139 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            result.__variant = Failure;
            #line 139 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            result.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 145 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return result;

}

__status_int32_t HouseKeepingFDIR__do_fdir(const __termina_event_t * const __ev, void * const __this) {
    
    #line 53 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 55 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 55 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 57 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    _Bool is_monitor_enabled = 0;

    #line 59 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    for (size_t i = 0U; i < 16U; i = i + 1U) {
        
        #line 61 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_12.is_PMON_enabled(__ev, self->pus_service_12.__that, i, &is_monitor_enabled);

        #line 63 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        if (is_monitor_enabled) {
            
            #line 65 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            uint16_t evID = 0U;

            #line 66 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            FaultInfo fault_info;
            #line 66 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            fault_info.__variant = FaultInfo__Empty;

            #line 67 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            _Bool event_triggered = 0;

            #line 69 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            self->pus_service_12.do_monitoring(__ev, self->pus_service_12.__that, (uint16_t)i, &evID, &fault_info, &event_triggered);

            #line 71 "src/tasks/hk_fdir_mng/hk_fdir.fin"
            if (event_triggered) {
                
                #line 73 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                _Bool is_Ev_ID_enabled = 0;

                #line 74 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                self->pus_service_5.is_Ev_ID_enabled_ext(__ev, self->pus_service_5.__that, evID, &is_Ev_ID_enabled);

                #line 76 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                if (is_Ev_ID_enabled) {
                    
                    #line 78 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                    self->pus_service_5.send_tm_5_x(__ev, self->pus_service_5.__that, evID, fault_info, &result);

                    #line 79 "src/tasks/hk_fdir_mng/hk_fdir.fin"
                    self->pus_service_19.manage_event_action(__ev, self->pus_service_19.__that, evID);

                }

            }

        }

    }

    #line 88 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (result.__variant == Success) {
        
        #line 89 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        return HouseKeepingFDIR__check_pending_actions(__ev, self);

    } else
    {
        
        #line 91 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        return result;

    }

}

__status_int32_t HouseKeepingFDIR__do_hk_fdir(const __termina_event_t * const __ev, void * const __this, TimeVal _current_time) {
    
    #line 156 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 158 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t result;
    #line 158 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    result.__variant = Success;

    #line 160 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_3.update_params(__ev, self->pus_service_3.__that);

    #line 161 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_4.update_all_stats(__ev, self->pus_service_4.__that);

    #line 162 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->pus_service_3.do_hk(__ev, self->pus_service_3.__that, &result);

    #line 164 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return HouseKeepingFDIR__do_fdir(__ev, self);

}

__status_int32_t HouseKeepingFDIR__exec_tc(const __termina_event_t * const __ev, void * const __this, __termina_box_t tc_handler) {
    
    #line 175 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)__this;

    #line 177 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    __status_int32_t status;
    #line 177 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    status.__variant = Success;

    #line 179 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    uint8_t tc_type = (*(TCHandler *)tc_handler.data).df_header.type;

    #line 181 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 3U) {
        
        #line 183 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_3.exec_tc(__ev, self->pus_service_3.__that, (TCHandler *)tc_handler.data, &status);

    } else
    #line 185 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 5U) {
        
        #line 187 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_5.exec_tc(__ev, self->pus_service_5.__that, (TCHandler *)tc_handler.data, &status);

    } else
    #line 189 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 12U) {
        
        #line 191 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_12.exec_tc(__ev, self->pus_service_12.__that, (TCHandler *)tc_handler.data, &status);

    } else
    #line 193 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 19U) {
        
        #line 195 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_19.exec_tc(__ev, self->pus_service_19.__that, (TCHandler *)tc_handler.data, &status);

    } else
    #line 198 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    if (tc_type == 4U) {
        
        #line 200 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_4.exec_tc(__ev, self->pus_service_4.__that, (TCHandler *)tc_handler.data, &status);

    } else
    {
        
        #line 204 "src/tasks/hk_fdir_mng/hk_fdir.fin"
        self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, (*(TCHandler *)tc_handler.data).packet_header.packet_id, (*(TCHandler *)tc_handler.data).packet_header.packet_seq_ctrl, &status);

    }

    #line 211 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that, tc_handler);

    #line 213 "src/tasks/hk_fdir_mng/hk_fdir.fin"
    return status;

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

                __termina_msg_queue__recv(self->hk_fdir_timer_ev, (void *)&do_hk_fdir__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->hk_fdir_timer_ev, status);
                }

                result = HouseKeepingFDIR__do_hk_fdir(&event, self, do_hk_fdir__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source, __HouseKeepingFDIR__hk_fdir_timer_ev, result.Failure.__0);

                }

                break;

            case __HouseKeepingFDIR__hkfdir_message_queue_input:

                __termina_msg_queue__recv(self->hkfdir_message_queue_input, (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->hkfdir_message_queue_input, status);
                }

                result = HouseKeepingFDIR__exec_tc(&event, self, exec_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source, __HouseKeepingFDIR__hkfdir_message_queue_input, result.Failure.__0);

                }

                break;

            default:

                __termina_exec__reboot();

                break;

        }

    }

    return;

}
