
#include "service_libraries/pus_services/pus_service2/pus_service2.h"

__status_int32_t PUSService2__dev_drv_on_off(const __termina_event_t * const __ev,
                                             PUSService2 * const self) {
    
    #line 328 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __status_int32_t status;
    #line 328 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    status.__variant = Success;

    #line 330 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t led = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x10000000U);

    #line 331 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t on_off = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x1U);

    #line 333 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->gpio_driver.write_led(__ev, self->gpio_driver.__that, led, on_off,
                                &status);

    #line 335 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return status;

}

_Bool PUSService2__device_drv_is_on_off_address_valid(const __termina_event_t * const __ev,
                                                      const PUSService2 * const self) {
    
    #line 196 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    _Bool is_valid = 0;

    #line 197 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint32_t device_address = self->exec_tc_req_status_update.dev_address;

    #line 199 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (device_address == 0x1U || device_address == 0x10000001U || device_address == 0x20000001U || device_address == 0x30000001U || device_address == 0x0U || device_address == 0x10000000U || device_address == 0x20000000U || device_address == 0x30000000U) {
        
        #line 201 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        is_valid = 1;

    }

    #line 204 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return is_valid;

}

PSExecTCReqStatus PUSService2__exec2_1TC(const __termina_event_t * const __ev,
                                         PUSService2 * const self) {
    
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.status.__variant = Success;

    #line 38 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    _Bool ack_enabled = 0;

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
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 50 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 48 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 52 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 53 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 55 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 57 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 58 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt,
                                                &next_status.status);

            #line 61 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (next_status.status.__variant == Success) {
                
                #line 63 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 66 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 72 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (PUSService2__device_drv_is_on_off_address_valid(__ev, self)) {
                
                #line 74 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 75 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 77 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (ack_enabled) {
                    
                    #line 79 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 81 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 86 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 91 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 96 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                next_status.status = PUSService2__dev_drv_on_off(__ev, self);

                #line 98 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (next_status.status.__variant == Success == 0) {
                    
                    #line 100 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    __option_box_t tm_handler2;
                    #line 100 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    tm_handler2.__variant = None;

                    #line 101 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 105 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 103 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 107 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        uint16_t tm_count2 = 0U;

                        #line 108 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 109 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 110 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        build_tm_1_8_device_command_exec_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_error_ctrl,
                                                               self->exec_tc_req_status_update.dev_address,
                                                               current_obt,
                                                               &next_status.status);

                        #line 113 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 115 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 118 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 123 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.status.__variant = Failure;
                        #line 123 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 130 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    __option_box_t tm_handler2;
                    #line 130 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    tm_handler2.__variant = None;

                    #line 131 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 135 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 133 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 137 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        uint16_t tm_count2 = 0U;

                        #line 138 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 139 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 140 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 142 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (ack_enabled) {
                            
                            #line 144 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 146 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 150 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 155 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 161 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.status.__variant = Failure;
                        #line 161 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                }

            } else
            {
                
                #line 171 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 172 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                build_tm_1_4_device_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.dev_address,
                                                      current_obt,
                                                      &next_status.status);

                #line 175 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 177 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 181 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 187 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.__variant = Failure;
        #line 187 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 191 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                          const PUSService2 * const self) {
    
    #line 252 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 252 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 252 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.status.__variant = Success;

    #line 254 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 254 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 254 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 256 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 256 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 257 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 261 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 259 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 263 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 264 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 266 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 267 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 270 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (next_status.status.__variant == Success) {
            
            #line 272 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 276 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 281 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.__variant = Failure;
        #line 281 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 285 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                              const PUSService2 * const self) {
    
    #line 211 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 211 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 211 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.status.__variant = Success;

    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 213 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 218 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 218 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 219 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 223 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 221 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 225 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 226 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 228 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 229 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 232 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (next_status.status.__variant == Success) {
            
            #line 234 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 238 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 243 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.__variant = Failure;
        #line 243 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 247 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

PSExecTCReqStatus PUSService2__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                const PUSService2 * const self) {
    
    #line 290 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PSExecTCReqStatus next_status;
    #line 290 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 290 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    next_status.status.__variant = Success;

    #line 292 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    MissionObt current_obt;
    #line 292 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.finetime = 0U;
    #line 292 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    current_obt.seconds = 0U;

    #line 294 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __option_box_t tm_handler;
    #line 294 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    tm_handler.__variant = None;

    #line 295 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 299 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (tm_handler.__variant == Some) {
        
        #line 297 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 301 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        uint16_t tm_count = 0U;

        #line 302 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 304 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 305 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 308 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (next_status.status.__variant == Success) {
            
            #line 310 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 314 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 319 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.__variant = Failure;
        #line 319 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 323 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return next_status;

}

void PUSService2__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 338 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PUSService2 * self = (PUSService2 *)__this;

    #line 338 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 340 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 342 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 346 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 348 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 349 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 350 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 351 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 352 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                              &self->exec_tc_req_status_update.N);

            #line 353 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                               &self->exec_tc_req_status_update.dev_address);

            #line 356 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 358 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 362 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 367 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 369 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (subtype == 1U) {
                
                #line 371 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status = PUSService2__exec2_1TC(__ev, self);

            } else
            {
                
                #line 375 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 375 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 376 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 387 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 389 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 385 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 394 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 397 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status = PUSService2__manage_error_in_acceptance(__ev,
                                                                               self);

        } else
        #line 399 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 402 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status = PUSService2__manage_tm_limit_app_data_reached(__ev,
                                                                                     self);

        } else
        #line 404 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 406 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status = PUSService2__manage_short_pack_length_error(__ev,
                                                                                   self);

        } else
        #line 408 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (error_code == INVALID_LED_INDEX_ERROR) {
            

        } else
        {
            
            #line 415 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).__variant = Failure;
            #line 415 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 423 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 424 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 427 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 427 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return;

}
