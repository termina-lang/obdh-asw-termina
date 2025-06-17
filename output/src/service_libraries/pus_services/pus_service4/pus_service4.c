
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const __termina_event_t * const __ev,
                                   const PUSService4 * const self,
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

_Bool PUSService4__SDP_param_higher_than_limit(const __termina_event_t * const __ev,
                                               const PUSService4 * const self,
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

_Bool PUSService4__SDP_param_lower_than_limit(const __termina_event_t * const __ev,
                                              const PUSService4 * const self,
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

__status_int32_t PUSService4__get_PID_defined_stats_index(const __termina_event_t * const __ev,
                                                          PUSService4 * const self) {
    
    __status_int32_t status;
    status.__variant = Failure;
    status.Failure.__0 = INVALID_PID_ERROR;

    for (size_t i = 0U; i < 4U && status.__variant == Success; i = i + 1U) {
        
        if (self->exec_tc_req_status_update.PID == self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                       i)]) {
            
            if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                        i)] == 1) {
                
                if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                    
                    self->exec_tc_req_status_update.valid_index = i;

                    status.__variant = Success;

                } else {
                    
                    self->stats_config_table.defined[__termina_array__index(4U,
                                                                            i)] = 0;

                }

            }

        }

    }

    return status;

}

IndexStatus PUSService4__get_free_index(const __termina_event_t * const __ev,
                                        const PUSService4 * const self) {
    
    IndexStatus id_status;
    id_status.index = 0U;
    id_status.status.__variant = Failure;
    id_status.status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    for (size_t i = 0U; i < 4U && id_status.status.__variant == Failure; i = i + 1U) {
        
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 0 || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                                                                               i)]) == 0) {
            
            id_status.index = i;

            id_status.status.__variant = Success;

        }

    }

    return id_status;

}

__status_int32_t PUSService4__add_PID_stats(const __termina_event_t * const __ev,
                                            PUSService4 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    IndexStatus index_status;
    index_status.index = 0U;
    index_status.status.__variant = Success;

    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    if (status.__variant == Success) {
        
        index_status = PUSService4__get_free_index(__ev, self);

        self->exec_tc_req_status_update.valid_index = index_status.index;

    }

    if (index_status.status.__variant == Success) {
        
        size_t PID_index = self->exec_tc_req_status_update.valid_index;

        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 1;

        self->stats_config_table.PID[__termina_array__index(4U,
                                                            PID_index)] = self->exec_tc_req_status_update.PID;

        self->param_stats[__termina_array__index(4U, PID_index)].samples = 0U;

        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        self->stats_config_table.start_time[__termina_array__index(4U,
                                                                   PID_index)] = current_obt;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    }

    return status;

}

__status_int32_t PUSService4__delete_PID_stats(const __termina_event_t * const __ev,
                                               PUSService4 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    size_t PID_index = 0U;

    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    if (status.__variant == Success) {
        
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 0;

    }

    return status;

}

void PUSService4__delete_all_stats(const __termina_event_t * const __ev,
                                   PUSService4 * const self) {
    
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

    }

    return;

}

__status_int32_t PUSService4__exec4_1TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

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

        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                              self->exec_tc_req_status_update.packet_id,
                              self->exec_tc_req_status_update.packet_seq_ctrl,
                              self->exec_tc_req_status_update.flags_ack,
                              current_obt, &ack_enabled);

        if (ack_enabled) {
            
            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

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
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    for (size_t i = 0U; i < 4U && status.__variant == Success; i = i + 1U) {
        
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            __option_box_t tm_handler2;
            tm_handler2.__variant = None;

            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            if (tm_handler2.__variant == Some) {
                
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                uint16_t tm_count = 0U;

                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_4_2((TMHandlerT *)b_tm_handler2.data,
                                      tm_count, i,
                                      self->exec_tc_req_status_update.N,
                                      &self->stats_config_table,
                                      self->param_stats, current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                MissionObt current_obt_update;
                current_obt_update.finetime = 0U;
                current_obt_update.seconds = 0U;

                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt_update);

                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    if (status.__variant == Success) {
        
        __option_box_t tm_handler3;
        tm_handler3.__variant = None;

        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        if (tm_handler3.__variant == Some) {
            
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            uint16_t tm_count3 = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count3);

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                  self->exec_tc_req_status_update.packet_id,
                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                  self->exec_tc_req_status_update.flags_ack,
                                  current_obt, &ack_enabled);

            if (ack_enabled) {
                
                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler3, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                }

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else {
            
            status.__variant = Failure;
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else {
        

    }

    return status;

}

__status_int32_t PUSService4__exec4_6TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

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

        if (self->exec_tc_req_status_update.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                status = PUSService4__add_PID_stats(__ev, self);

                if (status.__variant == Success) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        if (ack_enabled) {
                            
                            if (status.__variant == Success) {
                                
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

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

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                                tm_count,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                self->exec_tc_req_status_update.PID,
                                                                current_obt);

                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.packet_id,
                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.PID,
                                                    current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

__status_int32_t PUSService4__exec4_7TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

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

        if (self->exec_tc_req_status_update.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                status = PUSService4__delete_PID_stats(__ev, self);

                if (status.__variant == Success) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        if (ack_enabled) {
                            
                            if (status.__variant == Success) {
                                
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

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

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.PID,
                                                              current_obt);

                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.packet_id,
                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.PID,
                                                    current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

void PUSService4__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService4 * self = (PUSService4 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            if (subtype == 6U || subtype == 7U) {
                
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.N);

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.PID);

                }

            }

            if (status.__variant == Success) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = ACCEPTANCE_ERROR;

                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 1U) {
                
                status = PUSService4__exec4_1TC(__ev, self);

            } else if (subtype == 6U) {
                
                status = PUSService4__exec4_6TC(__ev, self);

            } else if (subtype == 7U) {
                
                status = PUSService4__exec4_7TC(__ev, self);

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = ACCEPTANCE_ERROR;

                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else {
            

        }

    }

    if (status.__variant == Success) {
        
        (*action_status).__variant = Success;

    } else {
        
        int32_t error_code = status.Failure.__0;

        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
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
                    
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else if (error_code == BUILD_TM_ERROR) {
                    
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

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

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

uint32_t PUSService4__get_data_pool_item(const __termina_event_t * const __ev,
                                         const PUSService4 * const self,
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

_Bool PUSService4__is_stats_index_defined(const __termina_event_t * const __ev,
                                          const PUSService4 * const self,
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

void PUSService4__startup(const __termina_event_t * const __ev,
                          void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            MissionObt current_obt;
            current_obt.finetime = 0U;
            current_obt.seconds = 0U;

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else {
            
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void PUSService4__update_all_stats(const __termina_event_t * const __ev,
                                   void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                if (PUSService4__SDP_param_higher_than_limit(__ev, self,
                                                             i) == 1) {
                    
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    MissionObt current_time;
                    current_time.finetime = 0U;
                    current_time.seconds = 0U;

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_time);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else if (PUSService4__SDP_param_lower_than_limit(__ev, self,
                                                                   i) == 1) {
                    
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    MissionObt current_time;
                    current_time.finetime = 0U;
                    current_time.seconds = 0U;

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_time);

                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else {
                    

                }

                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(__ev,
                                                                                                    self,
                                                                                                    i);

            } else {
                
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                 self,
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

                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
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

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
