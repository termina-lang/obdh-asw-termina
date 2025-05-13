
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const PUSService4 * const self,
                                   size_t pid_index) {
    
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    uint8_t u8_SDP_value = 0U;

    uint32_t u32_SDP_value = 0U;

    uint32_t mean_value = 0U;

    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else {
        

    }

    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const PUSService4 * const self,
                                               size_t pid_index) {
    
    _Bool is_higher = 0;

    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    uint8_t u8_SDP_value = 0U;

    uint32_t u32_SDP_value = 0U;

    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].max) {
            
            is_higher = 1;

        }

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        if (u32_SDP_value > self->param_stats[__termina_array__index(4U,
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

    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    uint8_t u8_SDP_value = 0U;

    uint32_t u32_SDP_value = 0U;

    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].min) {
            
            is_lower = 1;

        }

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        if (u32_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].min) {
            
            is_lower = 1;

        }

    } else {
        

    }

    return is_lower;

}

MyResult PUSService4__get_PID_defined_stats_index(PUSService4 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Error;

    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Error; i = i + 1U) {
        
        if (self->exec_tc_req_status_update.PID == self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                       i)]) {
            
            if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                        i)] == 1) {
                
                if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                    
                    self->exec_tc_req_status_update.valid_index = i;

                    result.__variant = MyResult__Ok;

                } else {
                    
                    self->stats_config_table.defined[__termina_array__index(4U,
                                                                            i)] = 0;

                }

            }

        }

    }

    return result;

}

MyResult PUSService4__get_free_index(const PUSService4 * const self,
                                     size_t * const index) {
    
    MyResult result;
    result.__variant = MyResult__Error;

    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Error; i = i + 1U) {
        
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 0 || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                                                                               i)]) == 0) {
            
            *index = i;

            result.__variant = MyResult__Ok;

        }

    }

    return result;

}

MyResult PUSService4__add_PID_stats(PUSService4 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    result = PUSService4__get_PID_defined_stats_index(self);

    if (result.__variant == MyResult__Error) {
        
        size_t index = 0U;

        result = PUSService4__get_free_index(self, &index);

        self->exec_tc_req_status_update.valid_index = index;

    }

    if (result.__variant == MyResult__Ok) {
        
        size_t PID_index = self->exec_tc_req_status_update.valid_index;

        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 1;

        self->stats_config_table.PID[__termina_array__index(4U,
                                                            PID_index)] = self->exec_tc_req_status_update.PID;

        self->param_stats[__termina_array__index(4U, PID_index)].samples = 0U;

        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        self->stats_config_table.start_time[__termina_array__index(4U,
                                                                   PID_index)] = current_obt;

    }

    return result;

}

void PUSService4__build_tm_4_2(const PUSService4 * const self,
                               TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, size_t index,
                               MyResult * const result) {
    
    startup_tm(p_tm_handler);

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    append_u32_appdata_field(p_tm_handler,
                             self->stats_config_table.start_time[__termina_array__index(4U,
                                                                                        index)].seconds,
                             result);

    append_u32_appdata_field(p_tm_handler, current_obt.seconds, result);

    append_u8_appdata_field(p_tm_handler, self->exec_tc_req_status_update.N,
                            result);

    append_u16_appdata_field(p_tm_handler,
                             self->stats_config_table.PID[__termina_array__index(4U,
                                                                                 index)],
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].samples,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].max,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].max_obt.seconds,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].min,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].min_obt.seconds,
                             result);

    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].mean_value,
                             result);

    if ((*result).__variant == MyResult__Ok) {
        
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    return;

}

MyResult PUSService4__delete_PID_stats(PUSService4 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Error;

    size_t PID_index = 0U;

    result = PUSService4__get_PID_defined_stats_index(self);

    if (result.__variant == MyResult__Ok) {
        
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 0;

    }

    return result;

}

void PUSService4__delete_all_stats(PUSService4 * const self) {
    
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

    }

    return;

}

PSExecTCReqStatus PUSService4__exec4_1TC(PUSService4 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count, current_obt,
                     &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Ok; i = i + 1U) {
        
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            __option_box_t tm_handler2;
            tm_handler2.__variant = None;

            self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            if (tm_handler2.__variant == Some) {
                
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                uint16_t tm_count = 0U;

                self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                   &tm_count);

                PUSService4__build_tm_4_2(self,
                                          (TMHandlerT *)b_tm_handler2.data,
                                          tm_count, i, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler2, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                MissionObt current_obt_update;
                current_obt_update.finetime = 0U;
                current_obt_update.seconds = 0U;

                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt_update);

                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    if (result.__variant == MyResult__Ok) {
        
        __option_box_t tm_handler3;
        tm_handler3.__variant = None;

        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        if (tm_handler3.__variant == Some) {
            
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            uint16_t tm_count3 = 0U;

            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count3);

            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler3,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            next_status.__variant = PSExecTCReqStatus__Failure;
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else {
        

    }

    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_6TC(PUSService4 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        if (self->exec_tc_req_status_update.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                result = PUSService4__add_PID_stats(self);

                if (result.__variant == MyResult__Ok) {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, current_obt, &result);

                        if (result.__variant == MyResult__Ok) {
                            
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            if (result.__variant == MyResult__Error) {
                                
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else {
                            
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            next_status.__variant = PSExecTCReqStatus__Error;
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.PID,
                                                       current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_7TC(PUSService4 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        if (self->exec_tc_req_status_update.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                result = PUSService4__delete_PID_stats(self);

                if (result.__variant == MyResult__Ok) {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, current_obt, &result);

                        if (result.__variant == MyResult__Ok) {
                            
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            if (result.__variant == MyResult__Error) {
                                
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else {
                            
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            next_status.__variant = PSExecTCReqStatus__Error;
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.PID,
                                                     current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PS4ExecTCReqStatusUpdate PUSService4__get_TC_params(const PUSService4 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS4ExecTCReqStatusUpdate tc_data;
    tc_data.N = 0U;
    tc_data.PID = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_num_bytes = 0U;
    tc_data.valid_index = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    if (*subtype == 6U || *subtype == 7U) {
        
        *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

        *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    }

    return tc_data;

}

PSExecTCReqStatus PUSService4__manage_error_in_acceptance(const PUSService4 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService4__manage_short_pack_length_error(const PUSService4 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService4__manage_tm_limit_app_data_reached(const PUSService4 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

void PUSService4__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService4 * self = (PUSService4 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            MyResult result;
            result.__variant = MyResult__Ok;

            self->exec_tc_req_status_update = PUSService4__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            if (result.__variant == MyResult__Error) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

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
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (error_code == ACCEPTANCE_ERROR) {
                
                self->exec_tc_req_status = PUSService4__manage_error_in_acceptance(self);

            } else if (error_code == BUILD_TM_ERROR) {
                
                self->exec_tc_req_status = PUSService4__manage_tm_limit_app_data_reached(self);

            } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                self->exec_tc_req_status = PUSService4__manage_short_pack_length_error(self);

            } else {
                

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = failure_code;

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
                                      __status_int32_t * const action_status) {
    
    PUSService4 * self = (PUSService4 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService4__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService4__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService4__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__exec_tc(__this, tc_handler, action_status);
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

    if (index < 4U) {
        
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    index)] == 1) {
            
            if (sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
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

    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            MissionObt current_obt;
            current_obt.finetime = 0U;
            current_obt.seconds = 0U;

            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else {
            
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    return;

}

void PUSService4__startup__mutex_lock(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService4__startup(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

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

void PUSService4__update_all_stats(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                if (PUSService4__SDP_param_higher_than_limit(self, i) == 1) {
                    
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    MissionObt current_time;
                    current_time.finetime = 0U;
                    current_time.seconds = 0U;

                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_time);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else if (PUSService4__SDP_param_lower_than_limit(self,
                                                                   i) == 1) {
                    
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    MissionObt current_time;
                    current_time.finetime = 0U;
                    current_time.seconds = 0U;

                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_time);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else {
                    

                }

                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(self,
                                                                                                    i);

            } else {
                
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                 PID);

                self->param_stats[__termina_array__index(4U,
                                                         i)].max = system_data_pool_item;

                self->param_stats[__termina_array__index(4U,
                                                         i)].min = system_data_pool_item;

                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = system_data_pool_item;

                MissionObt current_time;
                current_time.finetime = 0U;
                current_time.seconds = 0U;

                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_time);

                self->param_stats[__termina_array__index(4U,
                                                         i)].max_obt = current_time;

                self->param_stats[__termina_array__index(4U,
                                                         i)].min_obt = current_time;

            }

            self->param_stats[__termina_array__index(4U,
                                                     i)].samples = self->param_stats[__termina_array__index(4U,
                                                                                                            i)].samples + 1U;

        } else {
            
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    return;

}

void PUSService4__update_all_stats__mutex_lock(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService4__update_all_stats(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService4__update_all_stats__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__update_all_stats(__this);
    __termina_task__unlock(lock);

}

void PUSService4__update_all_stats__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__update_all_stats(__this);
    __termina_event__unlock(lock);

}
