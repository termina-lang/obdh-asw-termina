
#include "service_libraries/pus_services/pus_service19/pus_service19.h"

MyResult PUSService19__delete_event_action(PUSService19 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Error;

    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = 0U;

        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

        result.__variant = MyResult__Ok;

    }

    return result;

}

MyResult PUSService19__disable_event_action(PUSService19 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Error;

    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

        result.__variant = MyResult__Ok;

    }

    return result;

}

MyResult PUSService19__enable_event_action(PUSService19 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Error;

    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 1;

        result.__variant = MyResult__Ok;

    }

    return result;

}

FoundID PUSService19__get_free_event_action_index(const PUSService19 * const self) {
    
    FoundID found_and_id;
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

FoundID PUSService19__is_ev_action_defined(const PUSService19 * const self,
                                           _Bool * const enabled,
                                           uint16_t evID) {
    
    FoundID found_and_id;
    found_and_id.ev_action_index = 0U;
    found_and_id.found = 0;

    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            found_and_id.ev_action_index = i;

            *enabled = self->event_action_config[__termina_array__index(16U,
                                                                        i)].enabled;

            found_and_id.found = 1;

        }

    }

    return found_and_id;

}

PSExecTCReqStatus PUSService19__exec19_1TC(PUSService19 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
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
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                _Bool is_enabled = 0;

                TC19_1_Error error;
                error.__variant = TC19_1_Error__NoError;

                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    if (is_enabled) {
                        
                        error.__variant = TC19_1_Error__EvIDEnabled;

                    } else {
                        
                        error.__variant = TC19_1_Error__NoError;

                    }

                } else {
                    
                    self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(self);

                    if (self->exec_tc_req_status_update.ev_action_ID.found) {
                        
                        error.__variant = TC19_1_Error__NoError;

                    } else {
                        
                        error.__variant = TC19_1_Error__MaxEventActionDefinitions;

                    }

                }

                if (error.__variant == TC19_1_Error__NoError) {
                    
                    TCHandlerT action_tc_handler = tc_handler_init();

                    tc_handler_build_from_descriptor(&action_tc_handler,
                                                     &self->exec_tc_req_status_update.action_tc_packet);

                    TCStatus tc_status;
                    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                    tc_status.error_code.__variant = TCErrorType__Undefined;
                    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                    tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

                    if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                        
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

                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

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
                                                         b_tm_handler2,
                                                         &result);

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

                        build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
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

                } else if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.tc_data.packet_id,
                                                   self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_data.EvID,
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

                } else {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
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

PSExecTCReqStatus PUSService19__exec19_2TC(PUSService19 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
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
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                _Bool is_enabled = 0;

                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    if (is_enabled) {
                        
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.tc_data.EvID,
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

                    } else {
                        
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

                        result = PUSService19__delete_event_action(self);

                        if (result.__variant == MyResult__Ok) {
                            
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
                                                             b_tm_handler2,
                                                             &result);

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

                        }

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
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

PSExecTCReqStatus PUSService19__exec19_4TC(PUSService19 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
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
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                _Bool is_enabled = 0;

                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
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

                    result = PUSService19__enable_event_action(self);

                    if (result.__variant == MyResult__Ok) {
                        
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
                                                         b_tm_handler2,
                                                         &result);

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

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
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

PSExecTCReqStatus PUSService19__exec19_5TC(PUSService19 * const self) {
    
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

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
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
            
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                _Bool is_enabled = 0;

                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
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

                    result = PUSService19__disable_event_action(self);

                    if (result.__variant == MyResult__Ok) {
                        
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
                                                         b_tm_handler2,
                                                         &result);

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

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
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

                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
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

PS19ExecTCReqStatusUpdate PUSService19__get_TC_params(const PUSService19 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS19ExecTCReqStatusUpdate ps19_req_status_update;
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        ps19_req_status_update.action_tc_packet.tc_bytes[__i0] = 0U;
    }
    ps19_req_status_update.action_tc_packet.tc_num_bytes = 0U;
    ps19_req_status_update.ev_action_ID.ev_action_index = 0U;
    ps19_req_status_update.ev_action_ID.found = 0;
    ps19_req_status_update.tc_data.EvID = 0U;
    ps19_req_status_update.tc_data.N = 0U;
    ps19_req_status_update.tc_data.packet_error_ctrl = 0U;
    ps19_req_status_update.tc_data.packet_id = 0U;
    ps19_req_status_update.tc_data.tc_num_bytes = 0U;

    ps19_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    ps19_req_status_update.tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    ps19_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *result = tc_handler_get_u8_appdata_field(tc_handler,
                                              &ps19_req_status_update.tc_data.N);

    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &ps19_req_status_update.tc_data.EvID);

    if (*subtype == 1U) {
        
        ps19_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

        for (size_t i = 0U; i < event_action_max_bytes && i < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; i = i + 1U) {
            
            ps19_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                    i)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                    i + 12U)];

        }

    }

    return ps19_req_status_update;

}

PSExecTCReqStatus PUSService19__manage_error_in_acceptance(const PUSService19 * const self) {
    
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
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
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

PSExecTCReqStatus PUSService19__manage_short_pack_length_error(const PUSService19 * const self) {
    
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
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
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

PSExecTCReqStatus PUSService19__manage_tm_limit_app_data_reached(const PUSService19 * const self) {
    
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
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
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

void PUSService19__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService19 * self = (PUSService19 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            MyResult result;
            result.__variant = MyResult__Ok;

            self->exec_tc_req_status_update = PUSService19__get_TC_params(self,
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
                
                self->exec_tc_req_status = PUSService19__exec19_1TC(self);

            } else if (subtype == 2U) {
                
                self->exec_tc_req_status = PUSService19__exec19_2TC(self);

            } else if (subtype == 4U) {
                
                self->exec_tc_req_status = PUSService19__exec19_4TC(self);

            } else if (subtype == 5U) {
                
                self->exec_tc_req_status = PUSService19__exec19_5TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (error_code == ACCEPTANCE_ERROR) {
                
                self->exec_tc_req_status = PUSService19__manage_error_in_acceptance(self);

            } else if (error_code == BUILD_TM_ERROR) {
                
                self->exec_tc_req_status = PUSService19__manage_tm_limit_app_data_reached(self);

            } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                self->exec_tc_req_status = PUSService19__manage_short_pack_length_error(self);

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

void PUSService19__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService19__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

void PUSService19__extract_action(void * const __this, size_t index,
                                  TCHandlerT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

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

    return;

}

void PUSService19__extract_action__mutex_lock(void * const __this, size_t index,
                                              TCHandlerT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__extract_action(self, index, action_packet);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__extract_action__task_lock(void * const __this, size_t index,
                                             TCHandlerT * const action_packet) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__extract_action(__this, index, action_packet);
    __termina_task__unlock(lock);

}

void PUSService19__extract_action__event_lock(void * const __this, size_t index,
                                              TCHandlerT * const action_packet) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__extract_action(__this, index, action_packet);
    __termina_event__unlock(lock);

}

_Bool PUSService19__get_event_action_config(const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled) {
    
    _Bool found = 0;

    for (size_t i = 0U; i < 16U && found == 0; i = i + 1U) {
        
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            *index = i;

            *enabled = self->event_action_config[__termina_array__index(16U,
                                                                        i)].enabled;

            found = 1;

        }

    }

    return found;

}

void PUSService19__get_pending_action_number(void * const __this,
                                             size_t paction_num[4U]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        paction_num[__termina_array__index(4U,
                                           i)] = self->pending_action_number[__termina_array__index(4U,
                                                                                                    i)];

    }

    return;

}

void PUSService19__get_pending_action_number__mutex_lock(void * const __this,
                                                         size_t paction_num[4U]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__get_pending_action_number(self, paction_num);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__get_pending_action_number__task_lock(void * const __this,
                                                        size_t paction_num[4U]) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__get_pending_action_number(__this, paction_num);
    __termina_task__unlock(lock);

}

void PUSService19__get_pending_action_number__event_lock(void * const __this,
                                                         size_t paction_num[4U]) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__get_pending_action_number(__this, paction_num);
    __termina_event__unlock(lock);

}

void PUSService19__manage_event_action(void * const __this, uint16_t evID) {
    
    PUSService19 * self = (PUSService19 *)__this;

    FoundID found_and_id;
    found_and_id.ev_action_index = 0U;
    found_and_id.found = 0;

    _Bool is_enabled = 0;

    found_and_id = PUSService19__is_ev_action_defined(self, &is_enabled, evID);

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

    return;

}

void PUSService19__manage_event_action__mutex_lock(void * const __this,
                                                   uint16_t evID) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__manage_event_action(self, evID);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__manage_event_action__task_lock(void * const __this,
                                                  uint16_t evID) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__manage_event_action(__this, evID);
    __termina_task__unlock(lock);

}

void PUSService19__manage_event_action__event_lock(void * const __this,
                                                   uint16_t evID) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__manage_event_action(__this, evID);
    __termina_event__unlock(lock);

}
