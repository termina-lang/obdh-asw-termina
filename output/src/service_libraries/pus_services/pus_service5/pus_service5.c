
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        startup_tm((TMHandlerT *)b_tm_handler.data);

        *status = append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                           EvID_build_tm_error);

        if ((*status).__variant == Success) {
            
            uint16_t tm_count = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            MissionObt current_obt;
            current_obt.finetime = 0U;
            current_obt.seconds = 0U;

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else {
            
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else {
        
        (*status).__variant = Failure;
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void PUSService5__build_and_tx_tm_5_x(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            *status = build_tm_5_x_param_out_of_limit((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      fault_value_info, evID,
                                                      current_obt);

        } else if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            *status = build_tm_5_x_param_check_value_fail((TMHandlerT *)b_tm_handler.data,
                                                          tm_count,
                                                          fault_value_info,
                                                          evID, current_obt);

        } else {
            

        }

        if ((*status).__variant == Success) {
            
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else {
            
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else {
        
        (*status).__variant = Failure;
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

__status_int32_t PUSService5__exec5_5TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
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

        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

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
            
            _Bool is_valid_EvID = index < 4U;

            if (is_valid_EvID) {
                
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

                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

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

                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.EvID,
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

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
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

        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

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
            
            _Bool is_valid_EvID = index < 4U;

            if (is_valid_EvID) {
                
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

                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

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

                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.EvID,
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

void PUSService5__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService5 * self = (PUSService5 *)__this;

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

            status = tc_handler_get_u16_appdata_field(tc_handler,
                                                      &self->exec_tc_req_status_update.EvID);

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
                
                status = PUSService5__exec5_5TC(__ev, self);

            } else if (subtype == 6U) {
                
                status = PUSService5__exec5_6TC(__ev, self);

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

_Bool PUSService5__is_Ev_ID_enabled(const __termina_event_t * const __ev,
                                    const PUSService5 * const self,
                                    uint16_t Ev_ID) {
    
    _Bool enabled = 0;

    size_t index = get_Ev_ID_enable_config_index(Ev_ID);

    uint8_t offset = get_Ev_ID_enable_config_offset(Ev_ID);

    if (index < 4U) {
        
        if ((uint32_t)((uint32_t)(self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                   index)] >> offset) & 0x1U) != 0U) {
            
            enabled = 1;

        }

    }

    return enabled;

}

void PUSService5__is_Ev_ID_enabled_ext(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    *p_enabled = PUSService5__is_Ev_ID_enabled(__ev, self, Ev_ID);

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
