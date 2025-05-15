
#include "service_libraries/pus_services/pus_service20/pus_service20.h"

void PUSService20__build_tm_20_2(const PUSService20 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter,
                                 MyResult * const result) {
    
    startup_tm(p_tm_handler);

    append_u8_appdata_field(p_tm_handler, 1U, result);

    append_u16_appdata_field(p_tm_handler,
                             (uint16_t)self->exec_tc_req_status_update.PID,
                             result);

    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t u8_SDP_value = 0U;

        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID]);

        append_u8_appdata_field(p_tm_handler, u8_SDP_value, result);

    } else if (item_type.__variant == DataPoolItemType__u32_t) {
        
        uint32_t u32_SDP_value = 0U;

        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

        append_u32_appdata_field(p_tm_handler, u32_SDP_value, result);

    } else {
        
        (*result).__variant = MyResult__Error;

    }

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    close_tm(p_tm_handler, 20U, 2U, tm_seq_counter, current_obt);

    return;

}

PSExecTCReqStatus PUSService20__exec20_1TC(PUSService20 * const self) {
    
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

                    PUSService20__build_tm_20_2(self,
                                                (TMHandlerT *)b_tm_handler2.data,
                                                tm_count2, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        if (result.__variant == MyResult__Error) {
                            

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
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler3, &result);

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

PSExecTCReqStatus PUSService20__exec20_3TC(PUSService20 * const self) {
    
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
                
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
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
                        
                        result.__variant = MyResult__Error;

                    }

                    if (succesful_execution) {
                        
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

                    build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
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

PS20ExecTCReqStatusUpdate PUSService20__get_TC_params(const PUSService20 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS20ExecTCReqStatusUpdate tc_data;
    tc_data.N = 0U;
    tc_data.PID = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_20_3_data.PID_value_u32 = 0U;
    tc_data.tc_20_3_data.PID_value_u8 = 0U;
    tc_data.tc_num_bytes = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    if (*subtype == 3U) {
        
        DataPoolItemType item_type = sys_data_pool_get_item_type(tc_data.PID);

        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                      &tc_data.tc_20_3_data.PID_value_u8);

        } else if (item_type.__variant == DataPoolItemType__u32_t) {
            
            *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                       &tc_data.tc_20_3_data.PID_value_u32);

        } else {
            
            (*result).__variant = MyResult__Error;

        }

    }

    return tc_data;

}

PSExecTCReqStatus PUSService20__manage_error_in_acceptance(const PUSService20 * const self) {
    
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

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const PUSService20 * const self) {
    
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

PSExecTCReqStatus PUSService20__manage_tm_limit_app_data_reached(const PUSService20 * const self) {
    
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

void PUSService20__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService20 * self = (PUSService20 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            MyResult result;
            result.__variant = MyResult__Ok;

            self->exec_tc_req_status_update = PUSService20__get_TC_params(self,
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
                
                self->exec_tc_req_status = PUSService20__exec20_1TC(self);

            } else if (subtype == 3U) {
                
                self->exec_tc_req_status = PUSService20__exec20_3TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (error_code == ACCEPTANCE_ERROR) {
                
                self->exec_tc_req_status = PUSService20__manage_error_in_acceptance(self);

            } else if (error_code == BUILD_TM_ERROR) {
                
                self->exec_tc_req_status = PUSService20__manage_tm_limit_app_data_reached(self);

            } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                self->exec_tc_req_status = PUSService20__manage_short_pack_length_error(self);

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

void PUSService20__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService20 * self = (PUSService20 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService20__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService20__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService20__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService20__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService20__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}
