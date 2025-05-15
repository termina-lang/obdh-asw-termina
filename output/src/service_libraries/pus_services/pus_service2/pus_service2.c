
#include "service_libraries/pus_services/pus_service2/pus_service2.h"

MyResult PUSService2__dev_drv_on_off(PUSService2 * const self) {
    
    #line 363 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 363 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 365 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t led = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x10000000U);

    #line 366 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t on_off = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x1U);

    #line 368 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->gpio_driver.write_led(self->gpio_driver.__that, led, on_off, &result);

    #line 370 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return result;

}

_Bool PUSService2__device_drv_is_on_off_address_valid(const PUSService2 * const self) {
    
    #line 197 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    _Bool is_valid = 0;

    #line 198 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint32_t device_address = self->exec_tc_req_status_update.dev_address;

    #line 200 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (device_address == 0x1U || device_address == 0x10000001U || device_address == 0x20000001U || device_address == 0x30000001U || device_address == 0x0U || device_address == 0x10000000U || device_address == 0x20000000U || device_address == 0x30000000U) {
        
        #line 202 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        is_valid = 1;

    }

    #line 205 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
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

    #line 40 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 40 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 40 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 45 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 45 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 46 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 50 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 48 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 52 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 53 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 55 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 57 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 58 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 61 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 63 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 65 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 66 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 66 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 69 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 70 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 70 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 75 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (PUSService2__device_drv_is_on_off_address_valid(self)) {
                
                #line 77 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 78 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 80 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 82 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 84 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 85 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 85 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 89 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 90 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 90 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 93 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                result = PUSService2__dev_drv_on_off(self);

                #line 95 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 97 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    __option_box_t tm_handler2;
                    #line 97 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    tm_handler2.__variant = None;

                    #line 98 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 102 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 100 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 104 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        uint16_t tm_count2 = 0U;

                        #line 105 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 106 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 107 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        build_tm_1_8_device_command_exec_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_error_ctrl,
                                                               self->exec_tc_req_status_update.dev_address,
                                                               current_obt,
                                                               &result);

                        #line 110 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 112 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 114 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 115 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 115 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 119 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 120 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 120 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 124 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 124 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 131 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    __option_box_t tm_handler2;
                    #line 131 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    tm_handler2.__variant = None;

                    #line 132 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 136 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 134 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 138 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        uint16_t tm_count2 = 0U;

                        #line 139 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 140 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 141 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, current_obt, &result);

                        #line 143 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 145 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 147 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 148 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 148 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 152 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 153 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 153 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 158 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 158 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                }

            } else
            {
                
                #line 168 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 169 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                build_tm_1_4_device_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.dev_address,
                                                      current_obt, &result);

                #line 172 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 174 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 176 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 177 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 177 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 181 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 182 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 182 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 188 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 188 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 192 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PS2ExecTCReqStatusUpdate PUSService2__get_TC_params(const PUSService2 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 211 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PS2ExecTCReqStatusUpdate tc_data;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.N = 0U;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.dev_address = 0U;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_id = 0U;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.tc_num_bytes = 0U;

    #line 220 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 221 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 222 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 223 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 224 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.dev_address);

    #line 226 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService2__manage_error_in_acceptance(const PUSService2 * const self) {
    
    #line 277 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 277 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 278 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 278 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 280 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 280 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 280 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 282 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 282 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 283 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 287 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 285 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 289 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 290 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 292 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 293 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 296 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 298 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 300 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 301 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 301 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 305 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 306 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 306 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 311 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 311 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 315 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_short_pack_length_error(const PUSService2 * const self) {
    
    #line 232 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 232 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 233 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 233 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 235 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 235 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 235 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 240 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 240 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 241 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 245 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 243 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 247 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 248 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 250 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 251 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 254 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 256 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 258 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 259 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 259 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 263 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 264 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 264 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 268 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 268 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 272 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_tm_limit_app_data_reached(const PUSService2 * const self) {
    
    #line 320 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 320 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 321 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MyResult result;
    #line 321 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    result.__variant = MyResult__Ok;

    #line 323 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 323 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 323 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 325 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 325 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 326 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 330 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 328 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 332 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 333 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 335 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 336 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 339 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 341 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 343 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 344 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 344 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 348 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 349 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 349 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 354 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 354 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 358 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

void PUSService2__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService2 * self = (PUSService2 *)__this;

    #line 375 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t subtype = 0U;

    #line 377 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 381 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 383 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            MyResult result;
            #line 383 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            result.__variant = MyResult__Ok;

            #line 385 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update = PUSService2__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 387 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 388 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 388 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 390 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 394 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 396 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (subtype == 1U) {
                
                #line 398 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__exec2_1TC(self);

            } else
            {
                
                #line 402 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 402 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 405 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 379 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 407 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 409 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 412 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__manage_error_in_acceptance(self);

            } else
            #line 414 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 417 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__manage_tm_limit_app_data_reached(self);

            } else
            #line 419 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 421 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 429 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 379 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 431 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).__variant = Failure;
            #line 431 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 432 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 441 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 443 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 446 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
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
