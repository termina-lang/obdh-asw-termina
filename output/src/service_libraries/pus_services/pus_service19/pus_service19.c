
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
    
    #line 93 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 93 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 93 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 93 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 95 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 97 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == 0U) {
            
            #line 99 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 100 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 103 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found_and_id;

}

FoundID PUSService19__is_ev_action_defined(const __termina_event_t * const __ev,
                                           const PUSService19 * const self,
                                           uint16_t evID) {
    
    #line 109 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 109 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 109 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 109 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 111 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 113 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            #line 115 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 116 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.enabled = self->event_action_config[__termina_array__index(16U,
                                                                                    i)].enabled;

            #line 117 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 120 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found_and_id;

}

__status_int32_t PUSService19__exec19_1TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 128 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 129 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 129 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 131 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 131 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 131 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 133 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 133 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 134 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 138 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 136 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 140 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 141 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 143 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 145 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 149 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 151 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 156 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 161 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 163 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                TC19_1_Error error;
                #line 164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                error.__variant = TC19_1_Error__NoError;

                #line 166 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 168 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 170 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 172 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__EvIDEnabled;

                    } else
                    {
                        
                        #line 176 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    }

                } else
                {
                    
                    #line 181 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(__ev,
                                                                                                             self);

                    #line 183 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (self->exec_tc_req_status_update.ev_action_ID.found) {
                        
                        #line 184 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    } else
                    {
                        
                        #line 187 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__MaxEventActionDefinitions;

                    }

                }

                #line 193 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__NoError) {
                    
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCHandlerT action_tc_handler;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.app_data_index = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.df_header.flag_ver_ack = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.df_header.sourceID = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.df_header.subtype = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.df_header.type = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.packet_error_ctrl = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.packet_header.packet_id = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.packet_header.packet_length = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.packet_header.packet_seq_ctrl = 0U;
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
                        #line 26 "src/service_libraries/pus_tc_handler.fin"
                        action_tc_handler.tc_descriptor.tc_bytes[__i0] = 0U;
                    }
                    #line 195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    action_tc_handler.tc_descriptor.tc_num_bytes = 0U;

                    #line 197 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_handler_build_from_descriptor(&action_tc_handler,
                                                     &self->exec_tc_req_status_update.action_tc_packet);

                    #line 199 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCStatus tc_status;
                    #line 200 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                    #line 202 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.error_code.__variant = TCErrorType__Undefined;
                    #line 201 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                    #line 205 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

                    #line 207 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                        
                        #line 209 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 210 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                              tm_count,
                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.tc_data.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 212 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 214 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (status.__variant == Success) {
                                
                                #line 216 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler, &status);

                            } else
                            {
                                
                                #line 220 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                            }

                        } else
                        {
                            
                            #line 225 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 229 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        #line 230 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                        #line 231 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_packets[__termina_array__index(16U,
                                                                          self->exec_tc_req_status_update.ev_action_ID.ev_action_index)] = action_tc_handler;

                        #line 233 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 233 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 234 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 238 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 236 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 240 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 241 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 242 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 243 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.tc_data.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 245 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 247 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 249 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 253 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 259 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 263 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.__variant = Failure;
                            #line 263 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 269 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 270 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                                 tm_count,
                                                                 self->exec_tc_req_status_update.tc_data.packet_id,
                                                                 self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                 self->exec_tc_req_status_update.tc_data.EvID,
                                                                 current_obt);

                        #line 273 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 275 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 280 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    }

                } else
                #line 287 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    #line 289 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 290 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                                            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_data.EvID,
                                                            current_obt);

                    #line 293 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 295 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 300 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 307 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 308 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                                 tm_count,
                                                                 self->exec_tc_req_status_update.tc_data.packet_id,
                                                                 self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                 self->exec_tc_req_status_update.tc_data.EvID,
                                                                 current_obt);

                    #line 311 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 313 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 318 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 327 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 328 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 331 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 333 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 338 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 347 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 347 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 351 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_2TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 358 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 359 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 359 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 363 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 363 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 364 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 368 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 366 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 370 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 371 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 373 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 376 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 379 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 381 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 385 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 390 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 392 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 394 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 396 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 398 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 400 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 401 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                                tm_count,
                                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                                self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                self->exec_tc_req_status_update.tc_data.EvID,
                                                                current_obt);

                        #line 404 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 406 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 410 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 415 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 416 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                              tm_count,
                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.tc_data.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 418 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 420 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (status.__variant == Success) {
                                
                                #line 422 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler, &status);

                            } else
                            {
                                
                                #line 426 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                            }

                        } else
                        {
                            
                            #line 431 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 434 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = PUSService19__delete_event_action(__ev, self);

                        #line 436 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 438 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __option_box_t tm_handler2;
                            #line 438 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            tm_handler2.__variant = None;

                            #line 439 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.alloc(__ev,
                                                          self->a_tm_handler_pool.__that,
                                                          &tm_handler2);

                            #line 443 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (tm_handler2.__variant == Some) {
                                
                                #line 441 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                                #line 445 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                uint16_t tm_count2 = 0U;

                                #line 446 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_counter.get_next_tm_count(__ev,
                                                                   self->tm_counter.__that,
                                                                   &tm_count2);

                                #line 447 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->pus_service_9.get_current_obt(__ev,
                                                                    self->pus_service_9.__that,
                                                                    &current_obt);

                                #line 448 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                      tm_count2,
                                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.tc_data.flags_ack,
                                                      current_obt,
                                                      &ack_enabled);

                                #line 450 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (ack_enabled) {
                                    
                                    #line 452 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (status.__variant == Success) {
                                        
                                        #line 454 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->tm_channel.send_tm(__ev,
                                                                 self->tm_channel.__that,
                                                                 b_tm_handler2,
                                                                 &status);

                                    } else
                                    {
                                        
                                        #line 457 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->a_tm_handler_pool.free(__ev,
                                                                     self->a_tm_handler_pool.__that,
                                                                     b_tm_handler2);

                                    }

                                } else
                                {
                                    
                                    #line 463 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 468 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                status.__variant = Failure;
                                #line 468 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                            }

                        }

                    }

                } else
                {
                    
                    #line 478 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 479 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data.EvID,
                                                              current_obt);

                    #line 482 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 484 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 488 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 494 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 495 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 498 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 500 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 504 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 512 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 512 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 516 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_4TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 523 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 524 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 524 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 526 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 526 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 526 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 528 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 528 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 529 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 533 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 531 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 535 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 536 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 538 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 540 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 541 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 544 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 546 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 550 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 556 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 559 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 561 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 563 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 564 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 566 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 568 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 570 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 574 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 580 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 583 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = PUSService19__enable_event_action(__ev, self);

                    #line 585 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 587 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 587 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 588 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 592 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 590 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 594 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 595 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 596 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 597 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.tc_data.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 599 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 601 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 603 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 607 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 613 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 618 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.__variant = Failure;
                            #line 618 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 625 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 626 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data.EvID,
                                                              current_obt);

                    #line 629 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 631 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 634 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 641 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 642 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 645 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 647 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 651 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 659 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 659 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 663 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_5TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 669 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 670 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 670 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 672 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 672 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 672 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 675 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 679 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 677 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 681 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 682 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 684 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 686 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 687 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 690 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 692 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 696 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 702 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 704 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 706 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 708 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 709 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 711 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 713 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 715 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 719 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 725 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 728 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = PUSService19__disable_event_action(__ev, self);

                    #line 730 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 732 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 732 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 733 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 737 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 735 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 739 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 740 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 741 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 742 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.tc_data.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 744 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 746 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 748 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 752 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 758 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 763 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.__variant = Failure;
                            #line 763 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 770 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 771 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data.EvID,
                                                              current_obt);

                    #line 774 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 776 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 780 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 786 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 787 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 790 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 792 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 796 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 804 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 804 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 808 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

void PUSService19__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 816 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 816 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 818 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 818 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 819 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 821 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 825 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 827 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

            #line 828 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 829 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 830 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 831 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.tc_data.N);

            #line 832 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 833 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.tc_data.EvID);

            }

            #line 837 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 839 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

                #line 841 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                for (size_t j = 0U;
                     j < event_action_max_bytes
                     && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes;
                     j = j + 1U) {
                    
                    #line 843 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                                     j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                                     j + tc_handler->app_data_index)];

                }

            }

            #line 849 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 851 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 855 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 860 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 862 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 864 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 866 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_1TC(__ev, self);

            } else
            #line 868 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 2U) {
                
                #line 870 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_2TC(__ev, self);

            } else
            #line 872 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 4U) {
                
                #line 874 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_4TC(__ev, self);

            } else
            #line 876 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 5U) {
                
                #line 878 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_5TC(__ev, self);

            } else
            {
                
                #line 882 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.__variant = Failure;
                #line 882 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 894 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 896 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 892 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        int32_t error_code = status.Failure.__0;

        #line 901 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Success;

            #line 905 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            __option_box_t tm_handler;
            #line 905 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            tm_handler.__variant = None;

            #line 906 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 910 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (tm_handler.__variant == Some) {
                
                #line 908 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 912 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                uint16_t tm_count = 0U;

                #line 913 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                MissionObt current_obt;
                #line 913 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                current_obt.finetime = 0U;
                #line 913 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                current_obt.seconds = 0U;

                #line 915 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 916 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 918 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 920 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 923 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 925 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 928 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 930 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                                            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 940 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 942 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 946 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 952 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.__variant = Failure;
                #line 952 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 959 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 959 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 965 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 967 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 967 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__extract_action(const __termina_event_t * const __ev,
                                  void * const __this, size_t index,
                                  TCHandlerT * const action_packet) {
    
    #line 1072 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 1072 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1074 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 0U) {
        
        #line 1076 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U,
                                                                              self->pending_action_head[0U])];

        #line 1077 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_head[0U] = (size_t)(self->pending_action_head[0U] + 1U) % 8U;

        #line 1078 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_number[0U] = self->pending_action_number[0U] - 1U;

    } else
    #line 1080 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 1U) {
        
        #line 1082 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                               self->pending_action_head[1U])];

        #line 1083 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_head[1U] = (size_t)(self->pending_action_head[1U] + 1U) % 8U;

        #line 1084 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_number[1U] = self->pending_action_number[1U] - 1U;

    } else
    #line 1086 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 2U) {
        
        #line 1088 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                               self->pending_action_head[2U])];

        #line 1089 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_head[2U] = (size_t)(self->pending_action_head[2U] + 1U) % 8U;

        #line 1090 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_number[2U] = self->pending_action_number[2U] - 1U;

    } else
    #line 1092 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 3U) {
        
        #line 1094 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                               self->pending_action_head[3U])];

        #line 1095 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_head[3U] = (size_t)(self->pending_action_head[3U] + 1U) % 8U;

        #line 1096 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pending_action_number[3U] = self->pending_action_number[3U] - 1U;

    } else
    {
        

    }

    #line 1102 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1102 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev,
                                             void * const __this,
                                             size_t paction_num[4U]) {
    
    #line 1061 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 1061 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1063 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 1065 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        paction_num[__termina_array__index(4U,
                                           i)] = self->pending_action_number[__termina_array__index(4U,
                                                                                                    i)];

    }

    #line 1069 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1069 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__manage_event_action(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t evID) {
    
    #line 972 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 972 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 975 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(__ev, self, evID);

    #line 977 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (found_and_id.found && found_and_id.enabled) {
        
        #line 979 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 981 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 982 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            size_t tail_index = 0U;

            #line 985 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 987 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 989 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 990 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U,
                                                                         tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                          found_and_id.ev_action_index)];

                    #line 991 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 999 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 1001 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 1003 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 1004 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1005 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1013 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 1015 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 1017 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 1018 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1019 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1027 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 1029 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 1031 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 1032 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1033 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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

    #line 1056 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1056 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}
