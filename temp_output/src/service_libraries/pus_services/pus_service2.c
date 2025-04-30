
#include "service_libraries/pus_services/pus_service2.h"

const size_t num_params2 = 64U;

PS2ExecTCReqStatusUpdate ps2_init_tc_req_status_update() {
    
    PS2ExecTCReqStatusUpdate res;
    res.N = 0U;
    res.dev_address = 0U;
    res.packet_error_ctrl = 0U;
    res.packet_id = 0U;
    res.tc_num_bytes = 0U;

    return res;

}

Result PUSService2__dev_drv_on_off(PUSService2 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    uint8_t led = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x10000000U);

    uint8_t on_off = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x1U);

    (self->gpio_driver.write_led)(self->gpio_driver.__that, led, on_off);

    return result;

}

_Bool PUSService2__device_drv_is_on_off_address_valid(const PUSService2 * const self) {
    
    _Bool is_valid = 0;

    uint32_t device_address = self->exec_tc_req_status_update.dev_address;

    if (device_address == 0x1U || device_address == 0x10000001U || device_address == 0x20000001U || device_address == 0x30000001U || device_address == 0x0U || device_address == 0x10000000U || device_address == 0x20000000U || device_address == 0x30000000U) {
        
        is_valid = 1;

    }

    return is_valid;

}

PSExecTCReqStatus PUSService2__exec2_1TC(PUSService2 * const self) {
    
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
            
            if (PUSService2__device_drv_is_on_off_address_valid(self)) {
                
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

                result = PUSService2__dev_drv_on_off(self);

                if (result.__variant == Result__Error) {
                    
                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                    &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                             &tm_count2);

                        build_tm_1_8_device_command_exec_error((TMHandlerT *)b_tm_handler.data,
                                                               tm_count,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_error_ctrl,
                                                               self->exec_tc_req_status_update.dev_address,
                                                               &result);

                        (self->tm_channel.send_tm)(self->tm_channel.__that,
                                                   b_tm_handler2, &result);

                    } else {
                        
                        result.__variant = Result__Error;

                    }

                } else {
                    
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
                
                build_tm_1_4_device_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.dev_address,
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

PS2ExecTCReqStatusUpdate PUSService2__get_TC_params(const PUSService2 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    Result * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS2ExecTCReqStatusUpdate tc_data;
    tc_data.N = 0U;
    tc_data.dev_address = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_num_bytes = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.dev_address);

    return tc_data;

}

PSExecTCReqStatus PUSService2__manage_short_pack_length_error(const PUSService2 * const self) {
    
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

void PUSService2__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          Result * const result) {
    
    PUSService2 * self = (PUSService2 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update = PUSService2__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         result);

            if ((*result).__variant == Result__Error) {
                
                self->exec_tc_req_status = PUSService2__manage_short_pack_length_error(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 1U) {
                
                self->exec_tc_req_status = PUSService2__exec2_1TC(self);

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

void PUSService2__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    PUSService2 * self = (PUSService2 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService2__exec_tc(self, tc_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService2__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService2__exec_tc(__this, tc_handler, result);
    __termina_task__unlock(lock);

}

void PUSService2__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService2__exec_tc(__this, tc_handler, result);
    __termina_event__unlock(lock);

}
