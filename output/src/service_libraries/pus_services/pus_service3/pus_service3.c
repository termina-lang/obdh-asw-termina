
#include "service_libraries/pus_services/pus_service3/pus_service3.h"

void PUSService3__do_hk(const __termina_event_t * const __ev,
                        void * const __this,
                        __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t do_hk_status;
    do_hk_status.__variant = Success;

    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            self->hk_config_table[__termina_array__index(8U,
                                                         i)].interval_control = self->hk_config_table[__termina_array__index(8U,
                                                                                                                             i)].interval_control + 1U;

            if (self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control >= self->hk_config_table[__termina_array__index(8U,
                                                                                                                                  i)].interval) {
                
                self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control = 0U;

                __option_box_t tm_handler;
                tm_handler.__variant = None;

                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler);

                if (tm_handler.__variant == Some) {
                    
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    uint16_t tm_count = 0U;

                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count);

                    startup_tm((TMHandlerT *)b_tm_handler.data);

                    do_hk_status = append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                                            self->hk_config_table[__termina_array__index(8U,
                                                                                                         i)].SID);

                    uint16_t PID = 0U;

                    uint32_t u32_SDP_value = 0U;

                    uint8_t u8_SDP_value = 0U;

                    for (size_t j = 0U; j < 16U && (j < (size_t)self->hk_config_table[__termina_array__index(8U,
                                                                                                             i)].num_params && do_hk_status.__variant == Success); j = j + 1U) {
                        
                        PID = self->hk_config_table[__termina_array__index(8U,
                                                                           i)].params_def[__termina_array__index(16U,
                                                                                                                 j)];

                        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

                        if (item_type.__variant == DataPoolItemType__u8_t) {
                            
                            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

                            do_hk_status = append_u8_appdata_field((TMHandlerT *)b_tm_handler.data,
                                                                   u8_SDP_value);

                        } else if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

                            do_hk_status = append_u32_appdata_field((TMHandlerT *)b_tm_handler.data,
                                                                    u32_SDP_value);

                        } else {
                            
                            do_hk_status.__variant = Failure;
                            do_hk_status.Failure.__0 = SDP_ITEM_TYPE_ERROR;

                        }

                    }

                    MissionObt current_obt;
                    current_obt.finetime = 0U;
                    current_obt.seconds = 0U;

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    if (do_hk_status.__variant == Success) {
                        
                        close_tm((TMHandlerT *)b_tm_handler.data, 3U, 25U,
                                 tm_count, current_obt);

                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &do_hk_status);

                    } else {
                        
                        self->pus_service_5.build_and_tx_tm_5_2(__ev,
                                                                self->pus_service_5.__that,
                                                                &do_hk_status);

                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else {
                    
                    (*action_status).__variant = Failure;
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

IndexFound PUSService3__get_SIDindex(const __termina_event_t * const __ev,
                                     const PUSService3 * const self) {
    
    IndexFound index_found;
    index_found.found = 0;
    index_found.index = 0U;

    for (size_t i = 0U; i < 8U && index_found.found == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status_update.tc_data.SID == self->hk_config_table[__termina_array__index(8U,
                                                                                                        i)].SID) {
            
            index_found.found = 1;

            index_found.index = i;

        }

    }

    return index_found;

}

__status_int32_t PUSService3__exec3_31TC(const __termina_event_t * const __ev,
                                         PUSService3 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
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
            
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev,
                                                                              self);

            if (self->exec_tc_req_status_update.index.found) {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.tc_data.flags_ack,
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
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

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
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
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

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.tc_data.packet_id,
                                                    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.tc_data.SID,
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

__status_int32_t PUSService3__exec3_5TC(const __termina_event_t * const __ev,
                                        PUSService3 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
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
            
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev,
                                                                              self);

            if (self->exec_tc_req_status_update.index.found) {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.tc_data.flags_ack,
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
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 1;

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

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
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
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

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.tc_data.packet_id,
                                                    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.tc_data.SID,
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

__status_int32_t PUSService3__exec3_6TC(const __termina_event_t * const __ev,
                                        PUSService3 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
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
            
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev,
                                                                              self);

            if (self->exec_tc_req_status_update.index.found) {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.tc_data.flags_ack,
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
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 0;

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

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
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
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

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.tc_data.packet_id,
                                                    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.tc_data.SID,
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

void PUSService3__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

            self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.tc_data.N);

            if (status.__variant == Success) {
                
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.tc_data.SID);

            }

            if (subtype == 31U && status.__variant == Success) {
                
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.tc_data.collection_interval);

            }

            if (status.__variant == Success) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = ACCEPTANCE_ERROR;

                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (subtype == 5U) {
                
                status = PUSService3__exec3_5TC(__ev, self);

            } else if (subtype == 6U) {
                
                status = PUSService3__exec3_6TC(__ev, self);

            } else if (subtype == 31U) {
                
                status = PUSService3__exec3_31TC(__ev, self);

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
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              current_obt);

                } else if (error_code == BUILD_TM_ERROR) {
                    
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                  current_obt);

                } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                                            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_data.tc_num_bytes,
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

void PUSService3__update_params(const __termina_event_t * const __ev,
                                void * const __this) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    for (size_t i = 0U; i < 5U; i = i + 1U) {
        
        uint32_t random_noise = (uint32_t)(rand_r(&self->random_seed) % 11U) - 5U;

        uint32_t data = 0U;

        data = atomic_load(&self->system_data_pool_u32[i]);

        data = data + random_noise;

        atomic_store(&self->system_data_pool_u32[i], data);

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
