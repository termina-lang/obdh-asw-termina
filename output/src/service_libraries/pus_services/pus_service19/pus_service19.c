
#include "service_libraries/pus_services/pus_service19/pus_service19.h"

__status_int32_t PUSService19__delete_event_action(const __termina_event_t * const __ev,
                                                   PUSService19 * const self) {
    
    #line 73 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 73 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 75 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 77 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = 0U;

        #line 78 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

    } else
    {
        
        #line 83 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 83 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    #line 86 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__disable_event_action(const __termina_event_t * const __ev,
                                                    PUSService19 * const self) {
    
    #line 40 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 40 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 42 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 44 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

    } else
    {
        
        #line 48 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 48 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    #line 51 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__enable_event_action(const __termina_event_t * const __ev,
                                                   PUSService19 * const self) {
    
    #line 57 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 57 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 59 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 61 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 1;

    } else
    {
        
        #line 65 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 65 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    #line 68 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

FoundID PUSService19__get_free_event_action_index(const __termina_event_t * const __ev,
                                                  const PUSService19 * const self) {
    
    #line 108 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 108 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 108 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 110 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 112 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == 0U) {
            
            #line 114 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 115 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 118 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found_and_id;

}

FoundID PUSService19__is_ev_action_defined(const __termina_event_t * const __ev,
                                           const PUSService19 * const self,
                                           _Bool * const enabled,
                                           uint16_t evID) {
    
    #line 124 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 124 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 124 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 126 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 128 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            #line 130 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 131 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            *enabled = self->event_action_config[__termina_array__index(16U,
                                                                        i)].enabled;

            #line 132 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 135 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found_and_id;

}

PSExecTCReqStatus PUSService19__exec19_1TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self) {
    
    #line 143 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 144 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 144 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 144 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 148 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 148 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 149 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 153 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 151 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 155 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 156 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 158 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 160 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 161 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt,
                                                &next_status.status);

            #line 164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (next_status.status.__variant == Success) {
                
                #line 166 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 171 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 176 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 178 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 179 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                TC19_1_Error error;
                #line 179 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                error.__variant = TC19_1_Error__NoError;

                #line 181 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 183 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 185 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 187 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__EvIDEnabled;

                    } else
                    {
                        
                        #line 191 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    }

                } else
                {
                    
                    #line 196 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(__ev,
                                                                                                             self);

                    #line 198 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (self->exec_tc_req_status_update.ev_action_ID.found) {
                        
                        #line 199 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    } else
                    {
                        
                        #line 202 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__MaxEventActionDefinitions;

                    }

                }

                #line 208 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__NoError) {
                    
                    #line 210 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCHandlerT action_tc_handler = tc_handler_init();

                    #line 212 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_handler_build_from_descriptor(&action_tc_handler,
                                                     &self->exec_tc_req_status_update.action_tc_packet);

                    #line 214 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCStatus tc_status;
                    #line 215 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                    #line 217 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.error_code.__variant = TCErrorType__Undefined;
                    #line 216 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                    #line 220 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

                    #line 222 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                        
                        #line 224 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 225 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     self->exec_tc_req_status_update.tc_data.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 227 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 229 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 231 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 235 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                            }

                        } else
                        {
                            
                            #line 240 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 243 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        #line 244 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                        #line 247 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 247 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 248 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 252 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 250 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 254 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 255 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 256 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 257 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &next_status.status,
                                         &ack_enabled);

                            #line 259 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 261 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (next_status.status.__variant == Success) {
                                    
                                    #line 263 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &next_status.status);

                                } else
                                {
                                    
                                    #line 267 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 273 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 277 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.status.__variant = Failure;
                            #line 277 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 283 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 284 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt,
                                                        &next_status.status);

                        #line 287 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 289 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 294 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    }

                } else
                #line 301 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    #line 303 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 304 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.tc_data.packet_id,
                                                   self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_data.EvID,
                                                   current_obt,
                                                   &next_status.status);

                    #line 307 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 309 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 314 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 321 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 322 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt,
                                                        &next_status.status);

                    #line 325 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 327 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 332 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 341 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 342 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &next_status.status);

                #line 345 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 347 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 352 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 365 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_2TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self) {
    
    #line 372 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 373 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 373 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 373 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 377 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 377 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 378 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 382 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 380 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 384 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 385 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 387 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 389 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 390 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt,
                                                &next_status.status);

            #line 393 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (next_status.status.__variant == Success) {
                
                #line 395 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 399 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 404 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 406 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 408 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 410 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 412 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 414 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 415 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.tc_data.EvID,
                                                       current_obt,
                                                       &next_status.status);

                        #line 418 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 420 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 424 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 429 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 430 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     self->exec_tc_req_status_update.tc_data.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 432 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 434 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 436 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 440 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                            }

                        } else
                        {
                            
                            #line 445 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 448 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.status = PUSService19__delete_event_action(__ev,
                                                                               self);

                        #line 450 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 452 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __option_box_t tm_handler2;
                            #line 452 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            tm_handler2.__variant = None;

                            #line 453 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.alloc(__ev,
                                                          self->a_tm_handler_pool.__that,
                                                          &tm_handler2);

                            #line 457 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (tm_handler2.__variant == Some) {
                                
                                #line 455 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                                #line 459 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                uint16_t tm_count2 = 0U;

                                #line 460 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_counter.get_next_tm_count(__ev,
                                                                   self->tm_counter.__that,
                                                                   &tm_count2);

                                #line 461 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->pus_service_9.get_current_obt(__ev,
                                                                    self->pus_service_9.__that,
                                                                    &current_obt);

                                #line 462 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                             tm_count2,
                                             self->exec_tc_req_status_update.tc_data.flags_ack,
                                             current_obt, &next_status.status,
                                             &ack_enabled);

                                #line 464 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (ack_enabled) {
                                    
                                    #line 466 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (next_status.status.__variant == Success) {
                                        
                                        #line 468 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->tm_channel.send_tm(__ev,
                                                                 self->tm_channel.__that,
                                                                 b_tm_handler2,
                                                                 &next_status.status);

                                    } else
                                    {
                                        
                                        #line 471 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->a_tm_handler_pool.free(__ev,
                                                                     self->a_tm_handler_pool.__that,
                                                                     b_tm_handler2);

                                    }

                                } else
                                {
                                    
                                    #line 477 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 482 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.status.__variant = Failure;
                                #line 482 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                            }

                        }

                    }

                } else
                {
                    
                    #line 492 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 493 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt,
                                                     &next_status.status);

                    #line 496 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 498 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 502 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 508 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 509 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &next_status.status);

                #line 512 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 514 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 518 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 526 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 526 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 530 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_4TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self) {
    
    #line 537 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 538 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 538 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 538 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 540 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 540 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 540 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 542 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 542 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 543 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 547 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 545 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 549 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 550 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 552 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 554 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 555 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt,
                                                &next_status.status);

            #line 558 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (next_status.status.__variant == Success) {
                
                #line 560 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 564 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 570 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 572 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 574 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 576 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 578 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 579 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 581 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 583 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 585 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 589 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 595 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 598 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.status = PUSService19__enable_event_action(__ev,
                                                                           self);

                    #line 600 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 602 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 602 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 603 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 607 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 605 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 609 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 610 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 611 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 612 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &next_status.status,
                                         &ack_enabled);

                            #line 614 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 616 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (next_status.status.__variant == Success) {
                                    
                                    #line 618 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &next_status.status);

                                } else
                                {
                                    
                                    #line 622 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 628 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 633 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.status.__variant = Failure;
                            #line 633 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 640 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 641 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt,
                                                     &next_status.status);

                    #line 644 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 646 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 649 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 656 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 657 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &next_status.status);

                #line 660 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 662 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 666 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 678 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_5TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self) {
    
    #line 684 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 685 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 685 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 685 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 687 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 687 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 687 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 689 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 689 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 690 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 694 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 692 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 696 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 697 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 699 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 701 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 702 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt,
                                                &next_status.status);

            #line 705 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (next_status.status.__variant == Success) {
                
                #line 707 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 711 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 717 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 719 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 721 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 723 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 725 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 726 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 728 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 730 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 732 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 736 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 742 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 745 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.status = PUSService19__disable_event_action(__ev,
                                                                            self);

                    #line 747 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 749 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 749 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 750 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 754 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 752 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 756 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 757 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 758 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 759 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &next_status.status,
                                         &ack_enabled);

                            #line 761 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 763 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (next_status.status.__variant == Success) {
                                    
                                    #line 765 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &next_status.status);

                                } else
                                {
                                    
                                    #line 769 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 775 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 780 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.status.__variant = Failure;
                            #line 780 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 787 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 788 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt,
                                                     &next_status.status);

                    #line 791 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 793 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 797 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 803 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 804 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &next_status.status);

                #line 807 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 809 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 813 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 821 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 821 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 825 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                           const PUSService19 * const self) {
    
    #line 870 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 870 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 870 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 872 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 872 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 872 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 874 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 874 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 875 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 879 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 877 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 881 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 882 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 884 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 885 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 888 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (next_status.status.__variant == Success) {
            
            #line 890 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 894 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 900 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 900 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 904 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                               const PUSService19 * const self) {
    
    #line 832 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 832 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 832 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 834 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 834 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 834 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 836 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 836 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 837 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 841 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 839 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 843 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 844 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 846 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 847 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 850 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (next_status.status.__variant == Success) {
            
            #line 852 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 856 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 861 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 861 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 865 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                 const PUSService19 * const self) {
    
    #line 909 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 909 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 909 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.status.__variant = Success;

    #line 911 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 911 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 911 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 913 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 913 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 914 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 918 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 916 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 920 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 921 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 923 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 924 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 927 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (next_status.status.__variant == Success) {
            
            #line 929 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 933 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 939 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.__variant = Failure;
        #line 939 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 943 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

void PUSService19__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 947 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 947 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 949 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 951 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 955 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 957 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

            #line 958 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 959 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 960 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 961 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                              &self->exec_tc_req_status_update.tc_data.N);

            #line 962 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                               &self->exec_tc_req_status_update.tc_data.EvID);

            #line 964 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 966 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

                #line 968 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                for (size_t j = 0U; j < event_action_max_bytes && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; j = j + 1U) {
                    
                    #line 970 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                                     j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                                     j + 12U)];

                }

            }

            #line 976 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 978 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 982 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 987 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 989 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 991 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_1TC(__ev, self);

            } else
            #line 993 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 2U) {
                
                #line 995 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_2TC(__ev, self);

            } else
            #line 997 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 4U) {
                
                #line 999 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_4TC(__ev, self);

            } else
            #line 1001 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 5U) {
                
                #line 1003 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_5TC(__ev, self);

            } else
            {
                
                #line 1007 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 1007 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 1008 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 1019 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 1021 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 1017 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 1026 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 1028 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status = PUSService19__manage_error_in_acceptance(__ev,
                                                                                self);

        } else
        #line 1030 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 1032 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status = PUSService19__manage_tm_limit_app_data_reached(__ev,
                                                                                      self);

        } else
        #line 1034 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 1036 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status = PUSService19__manage_short_pack_length_error(__ev,
                                                                                    self);

        } else
        #line 1038 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (error_code == EVENT_ACTION_NOT_DEFINED_ERROR) {
            

        } else
        {
            
            #line 1044 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 1044 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 1052 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 1053 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 1057 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1057 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__extract_action(const __termina_event_t * const __ev,
                                  void * const __this, size_t index,
                                  TCHandlerT * const action_packet) {
    
    #line 1163 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 1163 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1165 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 0U) {
        
        #line 1167 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U,
                                                                              self->pending_action_head[0U])];

    } else
    #line 1169 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 1U) {
        
        #line 1171 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                               self->pending_action_head[1U])];

    } else
    #line 1173 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 2U) {
        
        #line 1175 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                               self->pending_action_head[2U])];

    } else
    #line 1177 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 3U) {
        
        #line 1179 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                               self->pending_action_head[3U])];

    } else
    {
        

    }

    #line 1185 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1185 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

_Bool PUSService19__get_event_action_config(const __termina_event_t * const __ev,
                                            const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled) {
    
    #line 92 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool found = 0;

    #line 94 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found == 0; i = i + 1U) {
        
        #line 96 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            #line 98 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            *index = i;

            #line 99 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            *enabled = self->event_action_config[__termina_array__index(16U,
                                                                        i)].enabled;

            #line 100 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found = 1;

        }

    }

    #line 103 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found;

}

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev,
                                             void * const __this,
                                             size_t paction_num[4U]) {
    
    #line 1152 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 1152 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1154 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 1156 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        paction_num[__termina_array__index(4U,
                                           i)] = self->pending_action_number[__termina_array__index(4U,
                                                                                                    i)];

    }

    #line 1160 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1160 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__manage_event_action(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t evID) {
    
    #line 1062 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 1062 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1064 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 1064 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 1064 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 1065 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool is_enabled = 0;

    #line 1066 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(__ev, self, &is_enabled,
                                                      evID);

    #line 1068 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (found_and_id.found && is_enabled) {
        
        #line 1070 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 1072 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 1073 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            size_t tail_index = 0U;

            #line 1076 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 1078 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 1080 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 1081 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U,
                                                                         tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                          found_and_id.ev_action_index)];

                    #line 1082 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1090 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 1092 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 1094 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 1095 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1096 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1104 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 1106 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 1108 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 1109 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1110 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1118 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 1120 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 1122 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 1123 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1124 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[3U] = self->pending_action_number[3U] + 1U;

                } else
                {
                    

                }

            } else
            {
                

            }

        } else
        {
            

        }

    }

    #line 1147 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1147 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}
