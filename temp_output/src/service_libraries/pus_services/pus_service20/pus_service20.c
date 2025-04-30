
#include "service_libraries/pus_services/pus_service20/pus_service20.h"

void PUSService20__build_tm_20_2(const PUSService20 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter,
                                 Result * const result) {
    
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
        
        (*result).__variant = Result__Error;

    }

    close_tm(p_tm_handler, 20U, 2U, tm_seq_counter, result);

    return;

}

PSExecTCReqStatus PUSService20__exec20_1TC(PUSService20 * const self) {
    
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

                    PUSService20__build_tm_20_2(self,
                                                (TMHandlerT *)b_tm_handler2.data,
                                                tm_count2, &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler2, &result);

                } else {
                    
                    result.__variant = Result__Error;

                }

                __option_box_t tm_handler3;
                tm_handler3.__variant = None;

                (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                &tm_handler3);

                if (tm_handler3.__variant == Some) {
                    
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    uint16_t tm_count3 = 0U;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count3);

                    build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler3, &result);

                } else {
                    
                    result.__variant = Result__Error;

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

PSExecTCReqStatus PUSService20__exec20_3TC(PUSService20 * const self) {
    
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
                
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

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
                        
                        result.__variant = Result__Error;

                    }

                    if (succesful_execution) {
                        
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

                    }

                } else {
                    
                    build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
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

PS20ExecTCReqStatusUpdate PUSService20__get_TC_params(const PUSService20 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      Result * const result) {
    
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
            
            (*result).__variant = Result__Error;

        }

    }

    return tc_data;

}

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const PUSService20 * const self) {
    
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

void PUSService20__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           Result * const result) {
    
    PUSService20 * self = (PUSService20 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update = PUSService20__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          result);

            if ((*result).__variant == Result__Error) {
                
                self->exec_tc_req_status = PUSService20__manage_short_pack_length_error(self);

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

void PUSService20__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result) {
    
    PUSService20 * self = (PUSService20 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService20__exec_tc(self, tc_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService20__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService20__exec_tc(__this, tc_handler, result);
    __termina_task__unlock(lock);

}

void PUSService20__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService20__exec_tc(__this, tc_handler, result);
    __termina_event__unlock(lock);

}
