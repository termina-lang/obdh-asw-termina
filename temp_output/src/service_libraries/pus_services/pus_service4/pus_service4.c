
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const PUSService4 * const self,
                                   size_t pid_index) {
    
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                       pid_index)];

    uint8_t u8_SDP_value = 0U;

    uint32_t u32_SDP_value = 0U;

    uint32_t mean_value = 0U;

    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else {
        

    }

    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const PUSService4 * const self,
                                               size_t pid_index) {
    
    _Bool is_higher = 0;

    uint16_t PID = self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                       pid_index)];

    uint8_t u8_SDP_value = 0U;

    uint32_t u32_SDP_value = 0U;

    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(max_num_of_stats,
                                                                              pid_index)].max) {
            
            is_higher = 1;

        }

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        if (u32_SDP_value > self->param_stats[__termina_array__index(max_num_of_stats,
                                                                     pid_index)].max) {
            
            is_higher = 1;

        }

    } else {
        

    }

    return is_higher;

}

_Bool PUSService4__SDP_param_lower_than_limit(const PUSService4 * const self,
                                              size_t pid_index) {
    
    _Bool is_lower = 0;

    uint16_t PID = self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                       pid_index)];

    uint8_t u8_SDP_value = 0U;

    uint32_t u32_SDP_value = 0U;

    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(max_num_of_stats,
                                                                              pid_index)].min) {
            
            is_lower = 1;

        }

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        if (u32_SDP_value < self->param_stats[__termina_array__index(max_num_of_stats,
                                                                     pid_index)].min) {
            
            is_lower = 1;

        }

    } else {
        

    }

    return is_lower;

}

Result PUSService4__get_PID_defined_stats_index(const PUSService4 * const self,
                                                size_t * const index) {
    
    Result result;
    result.__variant = Result__Error;

    for (size_t i = 0U; i < max_num_of_stats && result.__variant == Result__Error; i = i + 1U) {
        
        if (self->exec_tc_req_status_update.PID == self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                                                       i)]) {
            
            if (self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                        i)] == 1) {
                
                if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                    
                    *index = i;

                    result.__variant = Result__Ok;

                } else {
                    

                }

            }

        }

    }

    return result;

}

Result PUSService4__get_free_index(const PUSService4 * const self,
                                   size_t * const index) {
    
    Result result;
    result.__variant = Result__Error;

    for (size_t i = 0U; i < max_num_of_stats && result.__variant == Result__Error; i = i + 1U) {
        
        if (self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                    i)] == 0 || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                                                                                                               i)]) == 0) {
            
            *index = i;

            result.__variant = Result__Ok;

        }

    }

    return result;

}

Result PUSService4__add_PID_stats(PUSService4 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    size_t PID_index = 0U;

    result = PUSService4__get_PID_defined_stats_index(self, &PID_index);

    if (result.__variant == Result__Error) {
        
        result = PUSService4__get_free_index(self, &PID_index);

    }

    if (result.__variant == Result__Ok) {
        
        self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                PID_index)] = 1;

        self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                            PID_index)] = self->exec_tc_req_status_update.PID;

        self->param_stats[__termina_array__index(max_num_of_stats,
                                                 PID_index)].samples = 0U;

        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                              &current_obt);

        self->stats_config_table.start_time[__termina_array__index(max_num_of_stats,
                                                                   PID_index)] = current_obt;

    }

    return result;

}

void PUSService4__build_tm_4_2(const PUSService4 * const self,
                               TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, size_t index,
                               Result * const result) {
    
    startup_tm(p_tm_handler);

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                          &current_obt);

    append_u32_appdata_field(p_tm_handler,
                             self->stats_config_table.start_time[__termina_array__index(max_num_of_stats,
                                                                                        index)].seconds,
                             result);

    append_u32_appdata_field(p_tm_handler, current_obt.seconds, result);

    append_u8_appdata_field(p_tm_handler, self->exec_tc_req_status_update.N,
                            result);

    append_u16_appdata_field(p_tm_handler,
                             self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                                 index)],
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(max_num_of_stats,
                                                                      index)].samples,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(max_num_of_stats,
                                                                      index)].max,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(max_num_of_stats,
                                                                      index)].max_obt.seconds,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(max_num_of_stats,
                                                                      index)].min,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(max_num_of_stats,
                                                                      index)].min_obt.seconds,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(max_num_of_stats,
                                                                      index)].mean_value,
                             result);

    if ((*result).__variant == Result__Ok) {
        
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, result);

    }

    return;

}

Result PUSService4__delete_PID_stats(PUSService4 * const self) {
    
    Result result;
    result.__variant = Result__Error;

    size_t PID_index = 0U;

    result = PUSService4__get_PID_defined_stats_index(self, &PID_index);

    if (result.__variant == Result__Ok) {
        
        self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                PID_index)] = 0;

    }

    return result;

}

void PUSService4__delete_all_stats(PUSService4 * const self) {
    
    for (size_t i = 0U; i < max_num_of_stats; i = i + 1U) {
        
        self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                i)] = 0;

    }

    return;

}

PSExecTCReqStatus PUSService4__exec4_1TC(PUSService4 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count, &result);

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                   &result);

    } else {
        
        result.__variant = Result__Error;

    }

    for (size_t i = 0U; i < max_num_of_stats && result.__variant == Result__Ok; i = i + 1U) {
        
        if (self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                    i)] == 1) {
            
            __option_box_t tm_handler2;
            tm_handler2.__variant = None;

            (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                            &tm_handler2);

            if (tm_handler2.__variant == Some) {
                
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                uint16_t tm_count = 0U;

                (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                     &tm_count);

                PUSService4__build_tm_4_2(self,
                                          (TMHandlerT *)b_tm_handler2.data,
                                          tm_count, i, &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler2, &result);

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].samples = 0U;

                MissionObt current_obt;
                current_obt.finetime = 0U;
                current_obt.seconds = 0U;

                (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                                      &current_obt);

                self->stats_config_table.start_time[__termina_array__index(max_num_of_stats,
                                                                           i)] = current_obt;

            } else {
                
                result.__variant = Result__Error;

            }

        }

    }

    if (result.__variant == Result__Ok) {
        
        __option_box_t tm_handler3;
        tm_handler3.__variant = None;

        (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                        &tm_handler3);

        if (tm_handler3.__variant == Some) {
            
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            uint16_t tm_count3 = 0U;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count3);

            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3, &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler3,
                                       &result);

        } else {
            
            result.__variant = Result__Error;

        }

    } else {
        

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PSExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Exit;

    }

    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_6TC(PUSService4 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (self->exec_tc_req_status_update.N != 1U) {
            
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else {
            
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                result = PUSService4__add_PID_stats(self);

                if (result.__variant == Result__Ok) {
                    
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                    &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                             &tm_count2);

                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, &result);

                        (self->tm_channel.send_tm)(self->tm_channel.__that,
                                                   b_tm_handler2, &result);

                    } else {
                        
                        result.__variant = Result__Error;

                    }

                } else {
                    
                    build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.PID,
                                                       &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                }

            } else {
                
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PSExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Exit;

    }

    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_7TC(PUSService4 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (self->exec_tc_req_status_update.N != 1U) {
            
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else {
            
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                result = PUSService4__delete_PID_stats(self);

                if (result.__variant == Result__Ok) {
                    
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                    &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                             &tm_count2);

                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, &result);

                        (self->tm_channel.send_tm)(self->tm_channel.__that,
                                                   b_tm_handler2, &result);

                    } else {
                        
                        result.__variant = Result__Error;

                    }

                } else {
                    
                    build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.PID,
                                                     &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                }

            } else {
                
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PSExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Exit;

    }

    return next_status;

}

PS4ExecTCReqStatusUpdate PUSService4__get_TC_params(const PUSService4 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    Result * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS4ExecTCReqStatusUpdate tc_data;
    tc_data.N = 0U;
    tc_data.PID = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_num_bytes = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    if (*subtype == 6U || *subtype == 7U) {
        
        *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

        *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    }

    return tc_data;

}

PSExecTCReqStatus PUSService4__manage_short_pack_length_error(const PUSService4 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Error;

    Result result;
    result.__variant = Result__Ok;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       &result);

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                   &result);

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PSExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Exit;

    }

    return next_status;

}

void PUSService4__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          Result * const result) {
    
    PUSService4 * self = (PUSService4 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update = PUSService4__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         result);

            if ((*result).__variant == Result__Error) {
                
                self->exec_tc_req_status = PUSService4__manage_short_pack_length_error(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 1U) {
                
                self->exec_tc_req_status = PUSService4__exec4_1TC(self);

            } else if (subtype == 6U) {
                
                self->exec_tc_req_status = PUSService4__exec4_6TC(self);

            } else if (subtype == 7U) {
                
                self->exec_tc_req_status = PUSService4__exec4_7TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            (*result).__variant = Result__Error;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    return;

}

void PUSService4__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    PUSService4 * self = (PUSService4 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService4__exec_tc(self, tc_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService4__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__exec_tc(__this, tc_handler, result);
    __termina_task__unlock(lock);

}

void PUSService4__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__exec_tc(__this, tc_handler, result);
    __termina_event__unlock(lock);

}

uint32_t PUSService4__get_data_pool_item(const PUSService4 * const self,
                                         uint16_t PID) {
    
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    uint32_t SDP_value = 0U;

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t aux_value = 0U;

        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        SDP_value = (uint32_t)aux_value;

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else {
        

    }

    return SDP_value;

}

_Bool PUSService4__is_stats_index_defined(const PUSService4 * const self,
                                          size_t index) {
    
    _Bool is_defined = 0;

    if (index < max_num_of_stats) {
        
        if (self->stats_config_table.defined[__termina_array__index(max_num_of_stats,
                                                                    index)] == 1) {
            
            if (sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                                               index)])) {
                
                is_defined = 1;

            } else {
                

            }

        }

    }

    return is_defined;

}

void PUSService4__startup(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    for (size_t i = 0U; i < max_num_of_stats; i = i + 1U) {
        
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            self->param_stats[__termina_array__index(max_num_of_stats,
                                                     i)].samples = 0U;

            MissionObt current_obt;
            current_obt.finetime = 0U;
            current_obt.seconds = 0U;

            (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                                  &current_obt);

            self->stats_config_table.start_time[__termina_array__index(max_num_of_stats,
                                                                       i)] = current_obt;

        }

    }

    return;

}

void PUSService4__startup__mutex_lock(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService4__startup(self);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService4__startup__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__startup(__this);
    __termina_task__unlock(lock);

}

void PUSService4__startup__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__startup(__this);
    __termina_event__unlock(lock);

}

void PUSService4__update_all_stats(void * const __this, Result * const result) {
    
    PUSService4 * self = (PUSService4 *)__this;

    for (size_t i = 0U; i < max_num_of_stats; i = i + 1U) {
        
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(max_num_of_stats,
                                                                               i)];

            if (self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].samples > 0U) {
                
                if (PUSService4__SDP_param_higher_than_limit(self, i) == 1) {
                    
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    self->param_stats[__termina_array__index(max_num_of_stats,
                                                             i)].max = system_data_pool_item;

                    MissionObt current_time;
                    current_time.finetime = 0U;
                    current_time.seconds = 0U;

                    (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                                          &current_time);

                    self->param_stats[__termina_array__index(max_num_of_stats,
                                                             i)].max_obt = current_time;

                } else if (PUSService4__SDP_param_lower_than_limit(self,
                                                                   i) == 1) {
                    
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    self->param_stats[__termina_array__index(max_num_of_stats,
                                                             i)].min = system_data_pool_item;

                    MissionObt current_time;
                    current_time.finetime = 0U;
                    current_time.seconds = 0U;

                    (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                                          &current_time);

                    self->param_stats[__termina_array__index(max_num_of_stats,
                                                             i)].min_obt = current_time;

                } else {
                    

                }

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].mean_value = PUSService4__SDP_get_mean(self,
                                                                                                    i);

            } else {
                
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                 PID);

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].max = system_data_pool_item;

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].min = system_data_pool_item;

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].mean_value = system_data_pool_item;

                MissionObt current_time;
                current_time.finetime = 0U;
                current_time.seconds = 0U;

                (self->pus_service_9.get_current_obt)(self->pus_service_9.__that,
                                                      &current_time);

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].max_obt = current_time;

                self->param_stats[__termina_array__index(max_num_of_stats,
                                                         i)].min_obt = current_time;

            }

            self->param_stats[__termina_array__index(max_num_of_stats,
                                                     i)].samples = self->param_stats[__termina_array__index(max_num_of_stats,
                                                                                                            i)].samples + 1U;

        } else {
            
            (*result).__variant = Result__Error;

        }

    }

    return;

}

void PUSService4__update_all_stats__mutex_lock(void * const __this,
                                               Result * const result) {
    
    PUSService4 * self = (PUSService4 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService4__update_all_stats(self, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService4__update_all_stats__task_lock(void * const __this,
                                              Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__update_all_stats(__this, result);
    __termina_task__unlock(lock);

}

void PUSService4__update_all_stats__event_lock(void * const __this,
                                               Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__update_all_stats(__this, result);
    __termina_event__unlock(lock);

}
