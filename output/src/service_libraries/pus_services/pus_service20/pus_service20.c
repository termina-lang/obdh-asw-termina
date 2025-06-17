
#include "service_libraries/pus_services/pus_service20/pus_service20.h"

__status_int32_t PUSService20__exec20_1TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    _Bool ack_enabled = 0;

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
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
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

                    startup_tm((TMHandlerT *)b_tm_handler2.data);

                    status = append_u8_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                     1U);

                    if (status.__variant == Success) {
                        
                        status = append_u16_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                          (uint16_t)self->exec_tc_req_status_update.PID);

                    }

                    if (status.__variant == Success) {
                        
                        DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                        if (item_type.__variant == DataPoolItemType__u8_t) {
                            
                            uint8_t u8_SDP_value = 0U;

                            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID]);

                            status = append_u8_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                             u8_SDP_value);

                        } else if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            uint32_t u32_SDP_value = 0U;

                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

                            status = append_u32_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                              u32_SDP_value);

                        } else {
                            
                            status.__variant = Failure;
                            status.Failure.__0 = INVALID_PID_ERROR;

                        }

                    }

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    if (status.__variant == Success) {
                        
                        close_tm((TMHandlerT *)b_tm_handler.data, 20U, 2U,
                                 tm_count, current_obt);

                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else {
                    
                    status.__variant = Failure;
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

                __option_box_t tm_handler3;
                tm_handler3.__variant = None;

                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler3);

                if (tm_handler3.__variant == Some) {
                    
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    uint16_t tm_count3 = 0U;

                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count3);

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_7((TMHandlerT *)b_tm_handler3.data,
                                          tm_count3,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
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

__status_int32_t PUSService20__exec20_3TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    _Bool ack_enabled = 0;

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
                
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
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

                    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                    _Bool succesful_execution = 0;

                    if (item_type.__variant == DataPoolItemType__u8_t) {
                        
                        atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                        succesful_execution = 1;

                    } else if (item_type.__variant == DataPoolItemType__u32_t) {
                        
                        atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                        succesful_execution = 1;

                    } else {
                        
                        status.__variant = Failure;
                        status.Failure.__0 = INVALID_PID_ERROR;

                    }

                    if (succesful_execution) {
                        
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

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
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

void PUSService20__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService20 * self = (PUSService20 *)__this;

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

            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            if (status.__variant == Success) {
                
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.PID);

            }

            if (subtype == 3U && status.__variant == Success) {
                
                DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                if (item_type.__variant == DataPoolItemType__u8_t) {
                    
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                } else if (item_type.__variant == DataPoolItemType__u32_t) {
                    
                    status = tc_handler_get_u32_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                } else {
                    
                    status.__variant = Failure;
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            }

            if (status.__variant == Success) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (subtype == 1U) {
                
                status = PUSService20__exec20_1TC(__ev, self);

            } else if (subtype == 3U) {
                
                status = PUSService20__exec20_3TC(__ev, self);

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

        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR || error_code == INVALID_PID_ERROR) {
            
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

                } else if (error_code == INVALID_PID_ERROR) {
                    
                    status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.packet_id,
                                                        self->exec_tc_req_status_update.packet_seq_ctrl,
                                                        self->exec_tc_req_status_update.PID,
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
