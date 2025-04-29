
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_tm_5_x_param_check_value_fail(const PUSService5 * const self,
                                                      TMHandlerT * const p_tm_handler,
                                                      uint16_t tm_seq_counter,
                                                      ParamFaultValueInfo fault_info,
                                                      uint16_t ev_ID,
                                                      Result * const result) {
    
    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, ev_ID, result);

    append_u16_appdata_field(p_tm_handler, fault_info.PID, result);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, result);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_mask, result);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_expected_value,
                             result);

    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, result);

    return;

}

void PUSService5__build_tm_5_x_param_out_of_limit(const PUSService5 * const self,
                                                  TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  ParamOutOfLimitInfo fault_info,
                                                  uint16_t ev_ID,
                                                  Result * const result) {
    
    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, ev_ID, result);

    append_u16_appdata_field(p_tm_handler, fault_info.PID, result);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, result);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_limit, result);

    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, result);

    return;

}

void PUSService5__build_and_tx_tm_5_x(void * const __this,
                                      Result * const result, uint16_t evID,
                                      FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            PUSService5__build_tm_5_x_param_out_of_limit(self,
                                                         (TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         fault_value_info, evID,
                                                         result);

        } else if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            PUSService5__build_tm_5_x_param_check_value_fail(self,
                                                             (TMHandlerT *)b_tm_handler.data,
                                                             tm_count,
                                                             fault_value_info,
                                                             evID, result);

        } else {
            
            (*result).__variant = Result__Error;

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                   result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    return;

}

void PUSService5__build_and_tx_tm_5_x__mutex_lock(void * const __this,
                                                  Result * const result,
                                                  uint16_t evID,
                                                  FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService5__build_and_tx_tm_5_x(self, result, evID, fault_info);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService5__build_and_tx_tm_5_x__task_lock(void * const __this,
                                                 Result * const result,
                                                 uint16_t evID,
                                                 FaultInfo fault_info) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__build_and_tx_tm_5_x(__this, result, evID, fault_info);
    __termina_task__unlock(lock);

}

void PUSService5__build_and_tx_tm_5_x__event_lock(void * const __this,
                                                  Result * const result,
                                                  uint16_t evID,
                                                  FaultInfo fault_info) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__build_and_tx_tm_5_x(__this, result, evID, fault_info);
    __termina_event__unlock(lock);

}

PS5ExecTCReqStatus PUSService5__exec5_5TC(PUSService5 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PS5ExecTCReqStatus next_status;
    next_status.__variant = PS5ExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

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
            
            _Bool is_valid_EvID = index < 4U;

            if (is_valid_EvID) {
                
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count2);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler2, &result);

                } else {
                    
                    result.__variant = Result__Error;

                }

            } else {
                
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS5ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS5ExecTCReqStatus__Exit;

    }

    return next_status;

}

PS5ExecTCReqStatus PUSService5__exec5_6TC(PUSService5 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PS5ExecTCReqStatus next_status;
    next_status.__variant = PS5ExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

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
            
            _Bool is_valid_EvID = index < 4U;

            if (is_valid_EvID) {
                
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count2);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler2, &result);

                } else {
                    
                    result.__variant = Result__Error;

                }

            } else {
                
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS5ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS5ExecTCReqStatus__Exit;

    }

    return next_status;

}

PS5ExecTCReqStatusUpdate PUSService5__get_TC_params(const PUSService5 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    Result * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS5ExecTCReqStatusUpdate tc_data;
    tc_data.EvID = 0U;
    tc_data.N = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_num_bytes = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.EvID);

    return tc_data;

}

PS5ExecTCReqStatus PUSService5__manage_short_pack_length_error(const PUSService5 * const self) {
    
    PS5ExecTCReqStatus next_status;
    next_status.__variant = PS5ExecTCReqStatus__Error;

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
        
        next_status.__variant = PS5ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS5ExecTCReqStatus__Exit;

    }

    return next_status;

}

void PUSService5__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          Result * const result) {
    
    PUSService5 * self = (PUSService5 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PS5ExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PS5ExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update = PUSService5__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         result);

            if ((*result).__variant == Result__Error) {
                
                self->exec_tc_req_status = PUSService5__manage_short_pack_length_error(self);

            } else {
                
                self->exec_tc_req_status.__variant = PS5ExecTCReqStatus__ExecTC;

            }

        } else if (self->exec_tc_req_status.__variant == PS5ExecTCReqStatus__ExecTC) {
            
            if (subtype == 5U) {
                
                self->exec_tc_req_status = PUSService5__exec5_5TC(self);

            } else if (subtype == 6U) {
                
                self->exec_tc_req_status = PUSService5__exec5_6TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PS5ExecTCReqStatus__Error;

            }

        } else if (self->exec_tc_req_status.__variant == PS5ExecTCReqStatus__Error) {
            
            (*result).__variant = Result__Error;

            self->exec_tc_req_status.__variant = PS5ExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PS5ExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PS5ExecTCReqStatus__Init;

    }

    return;

}

void PUSService5__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    PUSService5 * self = (PUSService5 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService5__exec_tc(self, tc_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService5__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__exec_tc(__this, tc_handler, result);
    __termina_task__unlock(lock);

}

void PUSService5__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__exec_tc(__this, tc_handler, result);
    __termina_event__unlock(lock);

}

_Bool PUSService5__is_Ev_ID_enabled(const PUSService5 * const self,
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

void PUSService5__is_Ev_ID_enabled_ext(void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    *p_enabled = PUSService5__is_Ev_ID_enabled(self, Ev_ID);

    return;

}

void PUSService5__is_Ev_ID_enabled_ext__mutex_lock(void * const __this,
                                                   uint16_t Ev_ID,
                                                   _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService5__is_Ev_ID_enabled_ext(self, Ev_ID, p_enabled);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService5__is_Ev_ID_enabled_ext__task_lock(void * const __this,
                                                  uint16_t Ev_ID,
                                                  _Bool * const p_enabled) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__is_Ev_ID_enabled_ext(__this, Ev_ID, p_enabled);
    __termina_task__unlock(lock);

}

void PUSService5__is_Ev_ID_enabled_ext__event_lock(void * const __this,
                                                   uint16_t Ev_ID,
                                                   _Bool * const p_enabled) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__is_Ev_ID_enabled_ext(__this, Ev_ID, p_enabled);
    __termina_event__unlock(lock);

}
