
#include "service_libraries/pus_services/pus_service2/pus_service2.h"

MyResult PUSService2__dev_drv_on_off(PUSService2 * const self) {
    
    #line 381 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 381 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 383 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t led = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x10000000U);

    #line 384 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t on_off = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x1U);

    #line 386 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->gpio_driver.write_led(self->gpio_driver.__that, led, on_off, &result);

    #line 388 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return result;

}

_Bool PUSService2__device_drv_is_on_off_address_valid(const PUSService2 * const self) {
    
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    _Bool is_valid = 0;

    #line 214 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint32_t device_address = self->exec_tc_req_status_update.dev_address;

    #line 216 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (device_address == 0x1U || device_address == 0x10000001U || device_address == 0x20000001U || device_address == 0x30000001U || device_address == 0x0U || device_address == 0x10000000U || device_address == 0x20000000U || device_address == 0x30000000U) {
        
        #line 218 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        is_valid = 1;

    }

    #line 221 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return is_valid;

}

PSExecTCReqStatus PUSService2__exec2_1TC(PUSService2 * const self) {
    
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 38 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 38 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 39 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    _Bool ack_enabled = 0;

    #line 41 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 41 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 41 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 46 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 46 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 47 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 51 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 49 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 53 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 54 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 56 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 58 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 59 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 62 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 64 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 66 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 67 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 67 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 70 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 71 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 71 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 76 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (PUSService2__device_drv_is_on_off_address_valid(self)) {
                
                #line 78 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 79 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 81 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (ack_enabled) {
                    
                    #line 83 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 85 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 87 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 88 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 88 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 92 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 93 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 93 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 97 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 102 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                result = PUSService2__dev_drv_on_off(self);

                #line 104 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 106 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    __option_box_t tm_handler2;
                    #line 106 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    tm_handler2.__variant = None;

                    #line 107 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 111 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 109 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 113 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        uint16_t tm_count2 = 0U;

                        #line 114 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 115 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 116 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        build_tm_1_8_device_command_exec_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_error_ctrl,
                                                               self->exec_tc_req_status_update.dev_address,
                                                               current_obt,
                                                               &result);

                        #line 119 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 121 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 123 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 124 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 124 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 128 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 129 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 129 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 133 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 133 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 140 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    __option_box_t tm_handler2;
                    #line 140 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    tm_handler2.__variant = None;

                    #line 141 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 145 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 143 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 147 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        uint16_t tm_count2 = 0U;

                        #line 148 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 149 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 150 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 152 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (ack_enabled) {
                            
                            #line 154 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 156 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 158 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 159 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 159 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 163 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 164 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 164 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 168 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 174 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 174 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                }

            } else
            {
                
                #line 184 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 185 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                build_tm_1_4_device_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.dev_address,
                                                      current_obt, &result);

                #line 188 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 190 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 192 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 193 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 193 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 197 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 198 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 198 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 204 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 204 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 208 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PS2ExecTCReqStatusUpdate PUSService2__get_TC_params(const PUSService2 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 227 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PS2ExecTCReqStatusUpdate tc_data;
    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.N = 0U;
    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.dev_address = 0U;
    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.flags_ack = 0U;
    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_id = 0U;
    #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.tc_num_bytes = 0U;

    #line 237 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 238 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 239 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 240 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 241 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 242 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.dev_address);

    #line 244 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService2__manage_error_in_acceptance(const PUSService2 * const self) {
    
    #line 295 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 295 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 296 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 296 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 298 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 298 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 298 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 300 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 300 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 301 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 305 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 303 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 307 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 308 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 310 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 311 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 314 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 316 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 318 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 319 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 319 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 323 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 324 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 324 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 329 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 329 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 333 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_short_pack_length_error(const PUSService2 * const self) {
    
    #line 250 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 250 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 251 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 251 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 253 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 253 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 253 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 258 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 258 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 259 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 263 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 261 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 265 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 266 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 268 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 269 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 272 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 274 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 276 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 277 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 277 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 281 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 282 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 282 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 286 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 286 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 290 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_tm_limit_app_data_reached(const PUSService2 * const self) {
    
    #line 338 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 338 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 339 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 339 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 341 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 341 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 341 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 343 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 343 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 344 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 348 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 346 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 350 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 351 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 353 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 354 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 357 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 359 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 361 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 362 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 362 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 366 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 367 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 367 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 372 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 372 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 376 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

void PUSService2__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService2 * self = (PUSService2 *)__this;

    #line 393 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t subtype = 0U;

    #line 395 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 399 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 401 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            MyResult result;
            #line 401 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            result.__variant = MyResult__Ok;

            #line 403 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update = PUSService2__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 405 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 406 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 406 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 408 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 412 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 414 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (subtype == 1U) {
                
                #line 416 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__exec2_1TC(self);

            } else
            {
                
                #line 420 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 420 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 423 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 397 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 425 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 427 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 430 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__manage_error_in_acceptance(self);

            } else
            #line 432 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 435 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__manage_tm_limit_app_data_reached(self);

            } else
            #line 437 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 439 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 447 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 397 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 449 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).__variant = Failure;
            #line 449 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 450 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 459 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 461 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 464 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return;

}

void PUSService2__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    PUSService2 * self = (PUSService2 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService2__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService2__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService2__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService2__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService2__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}
