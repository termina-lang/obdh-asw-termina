
#include "service_libraries/pus_services/pus_service2/pus_service2.h"

__status_int32_t PUSService2__dev_drv_on_off(const __termina_event_t * const __ev,
                                             PUSService2 * const self) {
    
    #line 212 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __status_int32_t status;
    #line 212 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    status.__variant = Success;

    #line 214 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t led = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x10000000U);

    #line 215 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t on_off = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0x1U);

    #line 217 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->gpio_driver.write_led(__ev, self->gpio_driver.__that, led, on_off,
                                &status);

    #line 219 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return status;

}

_Bool PUSService2__device_drv_is_on_off_address_valid(const __termina_event_t * const __ev,
                                                      const PUSService2 * const self) {
    
    #line 196 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    _Bool is_valid = 0;

    #line 197 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint32_t device_address = self->exec_tc_req_status_update.dev_address;

    #line 199 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (device_address == 0x1U || device_address == 0x10000001U
        || device_address == 0x20000001U
        || device_address == 0x30000001U
        || device_address == 0x0U
        || device_address == 0x10000000U
        || device_address == 0x20000000U
        || device_address == 0x30000000U) {
        
        #line 201 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        is_valid = 1;

    }

    #line 204 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return is_valid;

}

__status_int32_t PUSService2__exec2_1TC(const __termina_event_t * const __ev,
                                        PUSService2 * const self) {
    
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __status_int32_t status;
    #line 37 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    status.__variant = Success;

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
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 61 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (status.__variant == Success) {
                
                #line 63 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

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
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 77 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (ack_enabled) {
                    
                    #line 79 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    if (status.__variant == Success) {
                        
                        #line 81 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

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
                status = PUSService2__dev_drv_on_off(__ev, self);

                #line 98 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (status.__variant == Success == 0) {
                    
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
                        status = build_tm_1_8_device_command_exec_error((TMHandlerT *)b_tm_handler2.data,
                                                                        tm_count2,
                                                                        self->exec_tc_req_status_update.packet_id,
                                                                        self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                        self->exec_tc_req_status_update.dev_address,
                                                                        current_obt);

                        #line 113 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (status.__variant == Success) {
                            
                            #line 115 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

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
                        status.__variant = Failure;
                        #line 123 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

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
                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 142 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        if (ack_enabled) {
                            
                            #line 144 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                            if (status.__variant == Success) {
                                
                                #line 146 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

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
                        status.__variant = Failure;
                        #line 161 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                }

            } else
            {
                
                #line 171 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 172 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status = build_tm_1_4_device_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                               tm_count,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.dev_address,
                                                               current_obt);

                #line 175 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (status.__variant == Success) {
                    
                    #line 177 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

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
        status.__variant = Failure;
        #line 187 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 191 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return status;

}

void PUSService2__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 222 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    PUSService2 * self = (PUSService2 *)__this;

    #line 222 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 224 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __status_int32_t status;
    #line 224 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    status.__variant = Success;

    #line 225 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 227 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 231 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 233 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 234 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 235 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 236 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 237 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            #line 238 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (status.__variant == Success) {
                
                #line 239 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.dev_address);

            }

            #line 242 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (status.__variant == Success) {
                
                #line 244 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 248 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 253 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 255 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 257 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (subtype == 1U) {
                
                #line 259 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status = PUSService2__exec2_1TC(__ev, self);

            } else
            {
                
                #line 263 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status.__variant = Failure;
                #line 263 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 274 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    if (status.__variant == Success) {
        
        #line 276 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 272 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        int32_t error_code = status.Failure.__0;

        #line 281 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 283 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).__variant = Success;

            #line 285 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            __option_box_t tm_handler;
            #line 285 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            tm_handler.__variant = None;

            #line 286 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 290 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            if (tm_handler.__variant == Some) {
                
                #line 288 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 292 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                uint16_t tm_count = 0U;

                #line 293 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                MissionObt current_obt;
                #line 293 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                current_obt.finetime = 0U;
                #line 293 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                current_obt.seconds = 0U;

                #line 295 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 296 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 298 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 300 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 303 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 305 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 308 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 310 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 320 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                if (status.__variant == Success) {
                    
                    #line 322 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 326 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 332 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status.__variant = Failure;
                #line 332 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 338 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).__variant = Failure;
            #line 338 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 345 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 347 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 347 "src/service_libraries/pus_services/pus_service2/pus_service2.fin"
    return;

}
