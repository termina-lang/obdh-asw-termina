
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

                        #line 228 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        #line 229 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                        #line 232 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 232 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 233 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 237 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 235 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 239 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 240 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 241 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 242 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.tc_data.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 244 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 246 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 248 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 252 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 258 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 262 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.__variant = Failure;
                            #line 262 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 268 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 269 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                                 tm_count,
                                                                 self->exec_tc_req_status_update.tc_data.packet_id,
                                                                 self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                 self->exec_tc_req_status_update.tc_data.EvID,
                                                                 current_obt);

                        #line 272 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 274 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 279 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    }

                } else
                #line 286 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    #line 288 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 289 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                                            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_data.EvID,
                                                            current_obt);

                    #line 292 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 294 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 299 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 306 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 307 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                                 tm_count,
                                                                 self->exec_tc_req_status_update.tc_data.packet_id,
                                                                 self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                 self->exec_tc_req_status_update.tc_data.EvID,
                                                                 current_obt);

                    #line 310 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 312 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 317 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 326 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 327 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 330 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 332 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 337 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 346 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 346 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 350 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_2TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 357 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 358 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 358 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 360 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 360 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 360 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 362 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 362 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 363 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 367 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 365 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 369 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 370 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 372 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 374 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 378 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 380 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 384 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 389 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 391 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 393 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 395 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 397 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 399 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 400 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                                tm_count,
                                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                                self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                self->exec_tc_req_status_update.tc_data.EvID,
                                                                current_obt);

                        #line 403 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 405 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 409 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 414 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 415 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                              tm_count,
                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.tc_data.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 417 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 419 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (status.__variant == Success) {
                                
                                #line 421 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler, &status);

                            } else
                            {
                                
                                #line 425 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                            }

                        } else
                        {
                            
                            #line 430 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 433 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        status = PUSService19__delete_event_action(__ev, self);

                        #line 435 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 437 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __option_box_t tm_handler2;
                            #line 437 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            tm_handler2.__variant = None;

                            #line 438 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.alloc(__ev,
                                                          self->a_tm_handler_pool.__that,
                                                          &tm_handler2);

                            #line 442 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (tm_handler2.__variant == Some) {
                                
                                #line 440 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                                #line 444 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                uint16_t tm_count2 = 0U;

                                #line 445 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_counter.get_next_tm_count(__ev,
                                                                   self->tm_counter.__that,
                                                                   &tm_count2);

                                #line 446 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->pus_service_9.get_current_obt(__ev,
                                                                    self->pus_service_9.__that,
                                                                    &current_obt);

                                #line 447 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                      tm_count2,
                                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.tc_data.flags_ack,
                                                      current_obt,
                                                      &ack_enabled);

                                #line 449 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (ack_enabled) {
                                    
                                    #line 451 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (status.__variant == Success) {
                                        
                                        #line 453 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->tm_channel.send_tm(__ev,
                                                                 self->tm_channel.__that,
                                                                 b_tm_handler2,
                                                                 &status);

                                    } else
                                    {
                                        
                                        #line 456 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->a_tm_handler_pool.free(__ev,
                                                                     self->a_tm_handler_pool.__that,
                                                                     b_tm_handler2);

                                    }

                                } else
                                {
                                    
                                    #line 462 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 467 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                status.__variant = Failure;
                                #line 467 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                            }

                        }

                    }

                } else
                {
                    
                    #line 477 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 478 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data.EvID,
                                                              current_obt);

                    #line 481 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 483 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 487 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 493 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 494 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 497 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 499 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 503 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 511 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 511 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 515 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_4TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 522 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 523 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 523 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 525 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 525 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 525 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 527 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 527 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 528 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 532 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 530 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 534 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 535 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 537 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 539 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 540 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 543 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 545 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 549 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 555 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 558 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 560 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 562 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 563 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 565 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 567 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 569 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 573 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 579 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 582 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = PUSService19__enable_event_action(__ev, self);

                    #line 584 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 586 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 586 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 587 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 591 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 589 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 593 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 594 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 595 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 596 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.tc_data.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 598 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 600 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 602 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 606 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 612 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 617 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.__variant = Failure;
                            #line 617 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 624 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 625 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data.EvID,
                                                              current_obt);

                    #line 628 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 630 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 633 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 640 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 641 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 644 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 646 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 650 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 658 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 658 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 662 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_5TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self) {
    
    #line 668 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 669 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 669 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 671 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 671 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 671 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 673 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 673 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 678 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 676 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 680 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 681 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 683 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 685 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 686 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 689 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 691 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 695 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 701 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 703 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev,
                                                                                                  self,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 705 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 707 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 708 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 710 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 712 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (status.__variant == Success) {
                            
                            #line 714 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 718 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 724 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 727 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = PUSService19__disable_event_action(__ev, self);

                    #line 729 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 731 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 731 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 732 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 736 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 734 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 738 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 739 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 740 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 741 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.tc_data.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 743 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 745 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 747 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 751 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 757 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 762 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.__variant = Failure;
                            #line 762 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 769 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 770 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data.EvID,
                                                              current_obt);

                    #line 773 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (status.__variant == Success) {
                        
                        #line 775 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 779 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 785 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 786 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt);

                #line 789 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 791 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 795 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 803 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.__variant = Failure;
        #line 803 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 807 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return status;

}

void PUSService19__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 815 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 815 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 817 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __status_int32_t status;
    #line 817 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    status.__variant = Success;

    #line 818 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 820 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 824 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 826 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

            #line 827 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 828 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 829 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 830 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.tc_data.N);

            #line 831 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 832 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.tc_data.EvID);

            }

            #line 836 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 838 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

                #line 840 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                for (size_t j = 0U;
                     j < event_action_max_bytes
                     && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes;
                     j = j + 1U) {
                    
                    #line 842 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                                     j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                                     j + 12U)];

                }

            }

            #line 848 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 850 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 854 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 859 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 861 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 863 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 865 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_1TC(__ev, self);

            } else
            #line 867 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 2U) {
                
                #line 869 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_2TC(__ev, self);

            } else
            #line 871 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 4U) {
                
                #line 873 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_4TC(__ev, self);

            } else
            #line 875 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 5U) {
                
                #line 877 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status = PUSService19__exec19_5TC(__ev, self);

            } else
            {
                
                #line 881 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.__variant = Failure;
                #line 881 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 893 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 895 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 891 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        int32_t error_code = status.Failure.__0;

        #line 900 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 902 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Success;

            #line 904 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            __option_box_t tm_handler;
            #line 904 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            tm_handler.__variant = None;

            #line 905 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 909 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (tm_handler.__variant == Some) {
                
                #line 907 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 911 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                uint16_t tm_count = 0U;

                #line 912 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                MissionObt current_obt;
                #line 912 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                current_obt.finetime = 0U;
                #line 912 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                current_obt.seconds = 0U;

                #line 914 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 915 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 917 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 919 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 922 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 924 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 927 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 929 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                                            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 939 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 941 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 945 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 951 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.__variant = Failure;
                #line 951 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 958 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 958 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 964 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 966 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 966 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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
    
    #line 971 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 971 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 973 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 973 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 973 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 973 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool is_enabled = 0;

    #line 975 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(__ev, self, evID);

    #line 977 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (found_and_id.found && is_enabled) {
        
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
