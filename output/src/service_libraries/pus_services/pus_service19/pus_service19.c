
#include "service_libraries/pus_services/pus_service19/pus_service19.h"

__status_int32_t PUSService19__delete_event_action(const __termina_event_t * const __ev,
                                                   PUSService19 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = 0U;

        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    return status;

}

__status_int32_t PUSService19__disable_event_action(const __termina_event_t * const __ev,
                                                    PUSService19 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    return status;

}

__status_int32_t PUSService19__enable_event_action(const __termina_event_t * const __ev,
                                                   PUSService19 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 1;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    return status;

}

FoundID PUSService19__get_free_event_action_index(const __termina_event_t * const __ev,
                                                  const PUSService19 * const self) {
    
    FoundID found_and_id;
    found_and_id.enabled = 0;
    found_and_id.ev_action_index = 0U;
    found_and_id.found = 0;

    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == 0U) {
            
            found_and_id.ev_action_index = i;

            found_and_id.found = 1;

        }

    }

    return found_and_id;

}

FoundID PUSService19__is_ev_action_defined(const __termina_event_t * const __ev,
                                           const PUSService19 * const self,
                                           uint16_t evID) {
    
    FoundID found_and_id;
    found_and_id.enabled = 0;
    found_and_id.ev_action_index = 0U;
    found_and_id.found = 0;

    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            found_and_id.ev_action_index = i;

            found_and_id.enabled = self->event_action_config[__termina_array__index(16U,
                                                                                    i)].enabled;

            found_and_id.found = 1;

        }

    }

    return found_and_id;

}

__status_int32_t PUSService19__exec19_1TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
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

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &status);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                _Bool is_enabled = 0;

                TC19_1_Error error;
                error.__variant = TC19_1_Error__NoError;

                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    if (is_enabled) {
                        
                        error.__variant = TC19_1_Error__EvIDEnabled;

                    } else {
                        
                        error.__variant = TC19_1_Error__NoError;

                    }

                } else {
                    
                    self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(__ev,
                                                                                                             self);

                    if (self->exec_tc_req_status_update.ev_action_ID.found) {
                        
                        error.__variant = TC19_1_Error__NoError;

                    } else {
                        
                        error.__variant = TC19_1_Error__MaxEventActionDefinitions;

                    }

                }

                if (error.__variant == TC19_1_Error__NoError) {
                    
                    TCHandlerT action_tc_handler;
                    action_tc_handler.app_data_index = 0U;
                    action_tc_handler.df_header.flag_ver_ack = 0U;
                    action_tc_handler.df_header.sourceID = 0U;
                    action_tc_handler.df_header.subtype = 0U;
                    action_tc_handler.df_header.type = 0U;
                    action_tc_handler.packet_error_ctrl = 0U;
                    action_tc_handler.packet_header.packet_id = 0U;
                    action_tc_handler.packet_header.packet_length = 0U;
                    action_tc_handler.packet_header.packet_seq_ctrl = 0U;
                    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
                        action_tc_handler.tc_descriptor.tc_bytes[__i0] = 0U;
                    }
                    action_tc_handler.tc_descriptor.tc_num_bytes = 0U;

                    tc_handler_build_from_descriptor(&action_tc_handler,
                                                     &self->exec_tc_req_status_update.action_tc_packet);

                    TCStatus tc_status;
                    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                    tc_status.error_code.__variant = TCErrorType__Undefined;
                    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                    tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

                    if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                        
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     self->exec_tc_req_status_update.tc_data.flags_ack,
                                     current_obt, &status, &ack_enabled);

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

                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

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

                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &status, &ack_enabled);

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

                        build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt, &status);

                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    }

                } else if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.tc_data.packet_id,
                                                   self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_data.EvID,
                                                   current_obt, &status);

                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt, &status);

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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &status);

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

__status_int32_t PUSService19__exec19_2TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
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

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &status);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                _Bool is_enabled = 0;

                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    if (is_enabled) {
                        
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.tc_data.EvID,
                                                       current_obt, &status);

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
                        
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     self->exec_tc_req_status_update.tc_data.flags_ack,
                                     current_obt, &status, &ack_enabled);

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

                        status = PUSService19__delete_event_action(__ev, self);

                        if (status.__variant == Success) {
                            
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

                                build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                             tm_count2,
                                             self->exec_tc_req_status_update.tc_data.flags_ack,
                                             current_obt, &status,
                                             &ack_enabled);

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

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &status);

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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &status);

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

__status_int32_t PUSService19__exec19_4TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
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

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &status);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &status, &ack_enabled);

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

                    status = PUSService19__enable_event_action(__ev, self);

                    if (status.__variant == Success) {
                        
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

                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &status, &ack_enabled);

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

                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &status);

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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &status);

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

__status_int32_t PUSService19__exec19_5TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
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

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &status);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &status, &ack_enabled);

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

                    status = PUSService19__disable_event_action(__ev, self);

                    if (status.__variant == Success) {
                        
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

                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &status, &ack_enabled);

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

                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &status);

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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &status);

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

void PUSService19__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

            self->exec_tc_req_status_update.tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

            self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

            self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.tc_data.N);

            if (status.__variant == Success) {
                
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.tc_data.EvID);

            }

            if (subtype == 1U) {
                
                self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

                for (size_t j = 0U; j < event_action_max_bytes && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; j = j + 1U) {
                    
                    self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                                     j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                                     j + 12U)];

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
                
                status = PUSService19__exec19_1TC(__ev, self);

            } else if (subtype == 2U) {
                
                status = PUSService19__exec19_2TC(__ev, self);

            } else if (subtype == 4U) {
                
                status = PUSService19__exec19_4TC(__ev, self);

            } else if (subtype == 5U) {
                
                status = PUSService19__exec19_5TC(__ev, self);

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
                    
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     current_obt, &status);

                } else if (error_code == BUILD_TM_ERROR) {
                    
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                         current_obt, &status);

                } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.tc_data.packet_id,
                                                   self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                                   current_obt, &status);

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

void PUSService19__extract_action(const __termina_event_t * const __ev,
                                  void * const __this, size_t index,
                                  TCHandlerT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    if (index == 0U) {
        
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U,
                                                                              self->pending_action_head[0U])];

    } else if (index == 1U) {
        
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                               self->pending_action_head[1U])];

    } else if (index == 2U) {
        
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                               self->pending_action_head[2U])];

    } else if (index == 3U) {
        
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                               self->pending_action_head[3U])];

    } else {
        

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev,
                                             void * const __this,
                                             size_t paction_num[4U]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        paction_num[__termina_array__index(4U,
                                           i)] = self->pending_action_number[__termina_array__index(4U,
                                                                                                    i)];

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void PUSService19__manage_event_action(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t evID) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    FoundID found_and_id;
    found_and_id.enabled = 0;
    found_and_id.ev_action_index = 0U;
    found_and_id.found = 0;

    _Bool is_enabled = 0;

    found_and_id = PUSService19__is_ev_action_defined(__ev, self, evID);

    if (found_and_id.found && is_enabled) {
        
        if (found_and_id.ev_action_index < 16U) {
            
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            size_t tail_index = 0U;

            if (RID_type.__variant == Ev_IDType__Informative) {
                
                if (self->pending_action_number[0U] < 8U) {
                    
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    self->pending_action_queue_1I[__termina_array__index(8U,
                                                                         tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                          found_and_id.ev_action_index)];

                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else {
                    

                }

            } else if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                if (self->pending_action_number[1U] < 8U) {
                    
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else {
                    

                }

            } else if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                if (self->pending_action_number[2U] < 8U) {
                    
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else {
                    

                }

            } else if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                if (self->pending_action_number[3U] < 8U) {
                    
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    self->pending_action_number[3U] = self->pending_action_number[3U] + 1U;

                } else {
                    

                }

            } else {
                

            }

        } else {
            

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
