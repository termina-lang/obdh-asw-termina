
#include "tasks/hkfdirmng.h"

Result HK_FDIR_Manager__pus_serv19_manage_event_actions(HK_FDIR_Manager * const self) {
    
    Result res;
    res.__variant = Result__Ok;

    for (size_t i = 0; i < max_num_events && i < self->event_list.num_events; i = i + 1) {
        
        __option_EventInfo_t event_info;
        event_info.__variant = None;

        get_event_info(&self->event_list, i, &event_info);

        if (event_info.__variant == None) {
            

        } else {
            
            __option_EventInfo_params_t __Some = event_info.Some;

            if (is_RID_enabled(__Some.__0.ev_RID,
                               self->pus_serv5_RID_enable_config)) {
                
                size_t index = 0;

                _Bool enabled = 0;

                if (get_event_action_config(__Some.__0.ev_RID, &index, &enabled,
                                            self->pus_serv19_event_action_config)) {
                    
                    if (enabled) {
                        
                        __option_dyn_t tc_descriptor;
                        tc_descriptor.__variant = None;

                        __termina_pool__alloc(self->a_tc_descriptor_pool,
                                              &tc_descriptor);

                        if (tc_descriptor.__variant == None) {
                            
                            res.__variant = Result__Error;

                        } else {
                            
                            __option_dyn_params_t __Some = tc_descriptor.Some;

                            (*(TCDescriptorT *)__Some.__0.data).tc_num_bytes = self->pus_serv19_event_action_packets[index].tc_num_bytes;

                            for (size_t j = 0; j < event_action_max_bytes && j < (*(TCDescriptorT *)__Some.__0.data).tc_num_bytes; j = j + 1) {
                                
                                (*(TCDescriptorT *)__Some.__0.data).tc_bytes[j] = self->pus_serv19_event_action_packets[index].tc_bytes[j];

                            }

                            __termina_msg_queue__send(self->action_tc_message_queue_output,
                                                      (void *)&__Some.__0);

                        }

                    }

                }

            }

        }

    }

    clear_ev_list(&self->event_list);

    return res;

}

Result HK_FDIR_Manager__do_hk_fdir(HK_FDIR_Manager * const self,
                                   TimeVal _current_time) {
    
    Result res;
    res.__variant = Result__Ok;

    res = HK_FDIR_Manager__pus_serv3_do_hk(self);

    res = HK_FDIR_Manager__pus_serv12_do_monitoring(self);

    res = HK_FDIR_Manager__pus_serv5_build_event_list_tms(self);

    return res;

}

Result HK_FDIR_Manager__pus_serv5_build_event_list_tms(HK_FDIR_Manager * const self) {
    
    Result res;
    res.__variant = Result__Ok;

    for (size_t i = 0; i < max_num_events && i < self->event_list.num_events; i = i + 1) {
        
        __option_EventInfo_t event_info;
        event_info.__variant = None;

        get_event_info(&self->event_list, i, &event_info);

        if (event_info.__variant == None) {
            

        } else {
            
            __option_EventInfo_params_t __Some = event_info.Some;

            if (is_RID_enabled(__Some.__0.ev_RID,
                               self->pus_serv5_RID_enable_config)) {
                
                size_t index = get_RID_enable_config_index(__Some.__0.ev_RID);

                if (index < 4) {
                    
                    __option_dyn_t tm_descriptor;
                    tm_descriptor.__variant = None;

                    __termina_pool__alloc(self->a_tm_descriptor_pool,
                                          &tm_descriptor);

                    if (tm_descriptor.__variant == None) {
                        
                        res.__variant = Result__Error;

                    } else {
                        
                        __option_dyn_params_t __Some = tm_descriptor.Some;

                        uint16_t tm_count = 0;

                        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                             &tm_count);

                        build_tm_5_x((TMDescriptorT *)__Some.__0.data, tm_count,
                                     &__Some.__0, index);

                        __termina_msg_queue__send(self->tm_message_queue_output,
                                                  (void *)&__Some.__0);

                    }

                }

            }

        }

    }

    return res;

}

Result HK_FDIR_Manager__pus_serv3_do_hk(HK_FDIR_Manager * const self) {
    
    Result res;
    res.__variant = Result__Ok;

    for (size_t i = 0; i < max_num_of_SIDs; i = i + 1) {
        
        if (self->pus_serv3_hk_config_table[i].enabled == 1) {
            
            self->pus_serv3_hk_config_table[i].interval_control = self->pus_serv3_hk_config_table[i].interval_control + 1;

            if (self->pus_serv3_hk_config_table[i].interval_control == self->pus_serv3_hk_config_table[i].interval) {
                
                self->pus_serv3_hk_config_table[i].interval_control = 0;

                __option_dyn_t tm_descriptor;
                tm_descriptor.__variant = None;

                __termina_pool__alloc(self->a_tm_descriptor_pool,
                                      &tm_descriptor);

                if (tm_descriptor.__variant == None) {
                    
                    res.__variant = Result__Error;

                } else {
                    
                    __option_dyn_params_t __Some = tm_descriptor.Some;

                    uint16_t tm_count = 0;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count);

                    HK_FDIR_Manager__pus_serv3_build_tm_3_25(self,
                                                             (TMDescriptorT *)__Some.__0.data,
                                                             tm_count, i);

                    __termina_msg_queue__send(self->tm_message_queue_output,
                                              (void *)&__Some.__0);

                }

            }

        }

    }

    return res;

}

void HK_FDIR_Manager__pus_serv3_build_tm_3_25(const HK_FDIR_Manager * const self,
                                              TMDescriptorT * p_tm_descriptor,
                                              uint16_t tm_seq_counter,
                                              size_t index) {
    
    CCSDSPUSTMPacketHeaderT tm_packet_header;
    tm_packet_header.packet_id = 0;
    tm_packet_header.packet_length = 0;
    tm_packet_header.packet_seq_ctrl = 0;

    CCSDSPUSTMDFHeaderT df_header;
    df_header.destinationID = 0;
    df_header.subtype = 0;
    df_header.type = 0;
    df_header.version = 0;

    tm_packet_header.packet_id = ccsds_pus_tm_build_packet_id(0x32C);

    tm_packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3,
                                                                          tm_seq_counter);

    tm_packet_header.packet_length = 4 + (uint16_t)(2 * (uint16_t)self->pus_serv3_hk_config_table[index].num_params);

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 3;

    df_header.subtype = 25;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    p_tm_descriptor->tm_bytes[10] = self->pus_serv3_hk_config_table[index].SID;

    size_t PID = 0;

    uint16_t SDP_value = 0;

    for (size_t j = 0; j < max_params_per_SID && j < (size_t)self->pus_serv3_hk_config_table[index].num_params; j = j + 1) {
        
        PID = (size_t)self->pus_serv3_hk_config_table[index].params_def[j];

        SDP_value = atomic_load(&self->system_data_pool[PID]);

        serialize_uint16(SDP_value, &p_tm_descriptor->tm_bytes[11 + j]);

    }

    p_tm_descriptor->tm_num_bytes = (uint16_t)(6 + tm_packet_header.packet_length) + 1;

    return;

}

Result HK_FDIR_Manager__pus_serv12_do_monitoring(HK_FDIR_Manager * const self) {
    
    Result res;
    res.__variant = Result__Ok;

    for (size_t i = 0; i < max_num_pmon_ids; i = i + 1) {
        
        if (self->pus_serv12_param_mon_config_table[i].enabled == 1) {
            
            uint16_t PID = self->pus_serv12_param_mon_config_table[i].PID;

            uint16_t SDP_value = 0;

            SDP_value = atomic_load(&self->system_data_pool[(size_t)PID]);

            if (self->pus_serv12_param_mon_config_table[i].interval_control >= self->pus_serv12_param_mon_config_table[i].interval) {
                
                self->pus_serv12_param_mon_config_table[i].interval_control = 0;

                if (self->pus_serv12_param_mon_config_table[i].state.__variant == CheckState__MonitorUnselected == 0) {
                    
                    if (self->pus_serv12_param_mon_config_table[i].state.__variant == CheckState__MonitorAboveHighLimit == 0 && self->pus_serv12_param_mon_config_table[i].state.__variant == CheckState__MonitorBelowLowLimit == 0) {
                        
                        if (SDP_value > self->pus_serv12_param_limit_check_definition[i].high_limit) {
                            
                            trigger_event(&self->event_list,
                                          self->pus_serv12_param_limit_check_definition[i].high_limit_rid,
                                          PID, SDP_value,
                                          self->pus_serv12_param_limit_check_definition[i].high_limit,
                                          &res);

                            CheckState updated_state;
                            updated_state.__variant = CheckState__MonitorAboveHighLimit;

                            update_state(self->pus_serv12_param_mon_config_table,
                                         i, updated_state);

                        } else if (SDP_value < self->pus_serv12_param_limit_check_definition[i].low_limit) {
                            
                            trigger_event(&self->event_list,
                                          self->pus_serv12_param_limit_check_definition[i].low_limit_rid,
                                          PID, SDP_value,
                                          self->pus_serv12_param_limit_check_definition[i].low_limit,
                                          &res);

                            CheckState updated_state;
                            updated_state.__variant = CheckState__MonitorBelowLowLimit;

                            update_state(self->pus_serv12_param_mon_config_table,
                                         i, updated_state);

                        } else {
                            
                            if (self->pus_serv12_param_mon_config_table[i].state.__variant == CheckState__MonitorUnchecked) {
                                
                                CheckState updated_state;
                                updated_state.__variant = CheckState__MonitorWithinLimits;

                                update_state(self->pus_serv12_param_mon_config_table,
                                             i, updated_state);

                            }

                        }

                    } else {
                        
                        if (SDP_value < self->pus_serv12_param_limit_check_definition[i].high_limit && SDP_value > self->pus_serv12_param_limit_check_definition[i].low_limit) {
                            
                            CheckState updated_state;
                            updated_state.__variant = CheckState__MonitorWithinLimits;

                            update_state(self->pus_serv12_param_mon_config_table,
                                         i, updated_state);

                        }

                    }

                } else {
                    
                    self->pus_serv12_param_mon_config_table[i].interval_control = self->pus_serv12_param_mon_config_table[i].interval_control + 1;

                }

            }

        }

    }

    return res;

}

Result HK_FDIR_Manager__PUS_hk_fdir_exec_tc(HK_FDIR_Manager * const self,
                                            __termina_dyn_t tc_descriptor) {
    
    Result res;
    res.__variant = Result__Ok;

    __option_dyn_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == None) {
        
        res.__variant = Result__Error;

    } else {
        
        __option_dyn_params_t __Some = tm_descriptor.Some;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        uint8_t tc_type = get_type((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

        if (tc_type == 3) {
            
            PUS_service_3_execTC((TCDescriptorT *)tc_descriptor.data,
                                 (TMDescriptorT *)__Some.__0.data, tm_count,
                                 self->pus_serv3_hk_config_table);

        } else if (tc_type == 5) {
            
            PUS_service_5_execTC((TCDescriptorT *)tc_descriptor.data,
                                 (TMDescriptorT *)__Some.__0.data, tm_count,
                                 self->pus_serv5_RID_enable_config);

        } else if (tc_type == 12) {
            
            PUS_service_12_execTC((TCDescriptorT *)tc_descriptor.data,
                                  (TMDescriptorT *)__Some.__0.data, tm_count,
                                  self->pus_serv12_param_mon_config_table,
                                  self->pus_serv12_param_limit_check_definition);

        } else if (tc_type == 19) {
            
            PUS_service_19_execTC((TCDescriptorT *)tc_descriptor.data,
                                  (TMDescriptorT *)__Some.__0.data, tm_count,
                                  self->pus_serv19_event_action_config,
                                  self->pus_serv19_event_action_packets);

        } else {
            

        }

        __termina_msg_queue__send(self->tm_message_queue_output,
                                  (void *)&__Some.__0);

    }

    __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    return res;

}
