
#include "service_libraries/pus_services/pus_service19/pus_service19.h"

MyResult PUSService19__delete_event_action(PUSService19 * const self) {
    
    #line 67 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 67 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Error;

    #line 68 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 70 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = 0U;

        #line 71 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

        #line 72 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        result.__variant = MyResult__Ok;

    }

    #line 76 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return result;

}

MyResult PUSService19__disable_event_action(PUSService19 * const self) {
    
    #line 40 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 40 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Error;

    #line 41 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 43 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

        #line 44 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        result.__variant = MyResult__Ok;

    }

    #line 48 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return result;

}

MyResult PUSService19__enable_event_action(PUSService19 * const self) {
    
    #line 54 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 54 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Error;

    #line 55 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U,
                                                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 57 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U,
                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 1;

        #line 58 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        result.__variant = MyResult__Ok;

    }

    #line 62 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return result;

}

FoundID PUSService19__get_free_event_action_index(const PUSService19 * const self) {
    
    #line 98 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 98 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 98 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 100 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 102 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == 0U) {
            
            #line 104 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 105 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 108 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found_and_id;

}

FoundID PUSService19__is_ev_action_defined(const PUSService19 * const self,
                                           _Bool * const enabled,
                                           uint16_t evID) {
    
    #line 114 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 114 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 114 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 116 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 118 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            #line 120 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 121 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            *enabled = self->event_action_config[__termina_array__index(16U,
                                                                        i)].enabled;

            #line 122 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 125 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found_and_id;

}

PSExecTCReqStatus PUSService19__exec19_1TC(PUSService19 * const self) {
    
    #line 133 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 133 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 134 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 135 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 135 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 137 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 137 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 137 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 139 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 139 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 140 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 144 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 142 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 147 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 149 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 151 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 152 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 155 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 157 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 159 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 160 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 160 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 165 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 166 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 166 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 171 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 173 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 174 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                TC19_1_Error error;
                #line 174 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                error.__variant = TC19_1_Error__NoError;

                #line 176 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 178 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 180 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 182 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__EvIDEnabled;

                    } else
                    {
                        
                        #line 186 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    }

                } else
                {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(self);

                    #line 193 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (self->exec_tc_req_status_update.ev_action_ID.found) {
                        
                        #line 194 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    } else
                    {
                        
                        #line 197 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__MaxEventActionDefinitions;

                    }

                }

                #line 203 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__NoError) {
                    
                    #line 205 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCHandlerT action_tc_handler = tc_handler_init();

                    #line 207 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_handler_build_from_descriptor(&action_tc_handler,
                                                     &self->exec_tc_req_status_update.action_tc_packet);

                    #line 209 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCStatus tc_status;
                    #line 210 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                    #line 212 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.error_code.__variant = TCErrorType__Undefined;
                    #line 211 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                    #line 215 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

                    #line 217 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                        
                        #line 219 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 220 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     self->exec_tc_req_status_update.tc_data.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 222 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 224 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 226 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler, &result);

                                #line 228 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 229 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 229 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 233 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                                #line 234 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 234 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 239 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 242 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        #line 243 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                        #line 246 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 246 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 247 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 251 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 249 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 253 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 254 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 255 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 256 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &result, &ack_enabled);

                            #line 258 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 260 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Ok) {
                                    
                                    #line 262 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &result);

                                    #line 264 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (result.__variant == MyResult__Error) {
                                        
                                        #line 265 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.__variant = PSExecTCReqStatus__Failure;
                                        #line 265 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.Failure.__0 = TM_SEND_FAILURE;

                                    }

                                } else
                                {
                                    
                                    #line 269 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                    #line 270 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Error;
                                    #line 270 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Error.__0 = BUILD_TM_ERROR;

                                }

                            } else
                            {
                                
                                #line 275 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 279 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 279 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 285 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 286 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt, &result);

                        #line 289 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 291 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 293 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 294 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 294 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 299 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 300 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 300 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    }

                } else
                #line 306 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    #line 308 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 309 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.tc_data.packet_id,
                                                   self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_data.EvID,
                                                   current_obt, &result);

                    #line 312 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 314 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 316 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 317 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 317 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 322 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 323 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 323 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 329 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 330 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt, &result);

                    #line 333 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 335 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 337 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 338 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 338 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 343 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 344 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 344 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 352 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 353 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 356 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 358 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 360 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 361 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 366 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 367 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 367 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 375 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 379 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_2TC(PUSService19 * const self) {
    
    #line 386 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 386 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 387 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 388 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 388 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 390 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 390 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 392 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 392 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 393 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 397 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 395 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 399 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 400 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 402 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 404 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 405 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 408 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 410 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 412 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 413 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 413 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 417 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 418 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 418 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 423 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 425 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 427 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 429 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 431 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 433 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 434 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.tc_data.EvID,
                                                       current_obt, &result);

                        #line 437 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 439 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 441 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 442 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 442 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 446 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 447 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 447 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 452 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 453 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     self->exec_tc_req_status_update.tc_data.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 455 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (ack_enabled) {
                            
                            #line 457 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 459 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler, &result);

                                #line 461 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 462 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 462 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 466 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler);

                                #line 467 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 467 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 472 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                        #line 475 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        result = PUSService19__delete_event_action(self);

                        #line 477 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 479 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __option_box_t tm_handler2;
                            #line 479 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            tm_handler2.__variant = None;

                            #line 480 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                          &tm_handler2);

                            #line 484 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (tm_handler2.__variant == Some) {
                                
                                #line 482 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                                #line 486 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                uint16_t tm_count2 = 0U;

                                #line 487 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                                   &tm_count2);

                                #line 488 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                    &current_obt);

                                #line 489 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                             tm_count2,
                                             self->exec_tc_req_status_update.tc_data.flags_ack,
                                             current_obt, &result,
                                             &ack_enabled);

                                #line 491 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (ack_enabled) {
                                    
                                    #line 493 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (result.__variant == MyResult__Ok) {
                                        
                                        #line 495 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                                 b_tm_handler2,
                                                                 &result);

                                        #line 497 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        if (result.__variant == MyResult__Error) {
                                            
                                            #line 498 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                            next_status.__variant = PSExecTCReqStatus__Failure;
                                            #line 498 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                            next_status.Failure.__0 = TM_SEND_FAILURE;

                                        }

                                    } else
                                    {
                                        
                                        #line 502 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                     b_tm_handler2);

                                        #line 503 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.__variant = PSExecTCReqStatus__Error;
                                        #line 503 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.Error.__0 = BUILD_TM_ERROR;

                                    }

                                } else
                                {
                                    
                                    #line 508 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 513 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 513 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                            }

                        }

                    }

                } else
                {
                    
                    #line 523 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 524 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &result);

                    #line 527 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 529 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 531 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 532 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 532 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 536 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 537 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 537 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 542 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 543 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 546 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 548 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 550 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 551 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 551 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 555 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 556 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 556 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 563 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 563 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 567 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_4TC(PUSService19 * const self) {
    
    #line 574 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 574 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 575 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 576 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 576 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 578 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 578 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 578 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 580 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 580 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 581 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 585 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 583 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 587 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 588 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 590 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 592 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 593 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 596 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 598 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 600 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 601 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 601 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 605 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 606 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 606 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 612 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 614 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 616 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 618 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 620 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 621 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 623 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 625 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 627 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 629 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 630 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 630 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 634 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 635 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 635 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 640 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 643 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    result = PUSService19__enable_event_action(self);

                    #line 645 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 647 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 647 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 648 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 652 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 650 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 654 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 655 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 656 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 657 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &result, &ack_enabled);

                            #line 659 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 661 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Ok) {
                                    
                                    #line 663 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &result);

                                    #line 665 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (result.__variant == MyResult__Error) {
                                        
                                        #line 666 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.__variant = PSExecTCReqStatus__Failure;
                                        #line 666 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.Failure.__0 = TM_SEND_FAILURE;

                                    }

                                } else
                                {
                                    
                                    #line 670 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                    #line 671 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Error;
                                    #line 671 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Error.__0 = BUILD_TM_ERROR;

                                }

                            } else
                            {
                                
                                #line 676 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 681 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 681 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 688 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 689 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &result);

                    #line 692 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 694 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 696 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 697 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 697 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 701 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 702 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 702 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 708 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 709 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 712 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 714 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 716 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 717 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 717 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 721 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 722 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 722 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 729 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 729 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 733 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_5TC(PUSService19 * const self) {
    
    #line 739 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 739 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 740 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool ack_enabled = 0;

    #line 741 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 741 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 743 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 743 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 743 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 745 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 745 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 746 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 750 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 748 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 752 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 753 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 755 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 757 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 758 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 761 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 763 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 765 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 766 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 766 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 770 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 771 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 771 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 776 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 778 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 780 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 782 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 784 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 785 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 787 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (ack_enabled) {
                        
                        #line 789 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 791 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 793 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 794 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 794 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 798 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 799 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 799 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 804 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 807 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    result = PUSService19__disable_event_action(self);

                    #line 809 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 811 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 811 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 812 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 816 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 814 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 818 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 819 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 820 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 821 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.tc_data.flags_ack,
                                         current_obt, &result, &ack_enabled);

                            #line 823 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (ack_enabled) {
                                
                                #line 825 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Ok) {
                                    
                                    #line 827 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &result);

                                    #line 829 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (result.__variant == MyResult__Error) {
                                        
                                        #line 830 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.__variant = PSExecTCReqStatus__Failure;
                                        #line 830 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.Failure.__0 = TM_SEND_FAILURE;

                                    }

                                } else
                                {
                                    
                                    #line 834 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                    #line 835 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Error;
                                    #line 835 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Error.__0 = BUILD_TM_ERROR;

                                }

                            } else
                            {
                                
                                #line 840 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 852 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 853 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &result);

                    #line 856 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 858 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 860 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 861 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 861 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 865 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 866 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 866 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 871 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 872 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 875 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 877 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 879 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 880 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 880 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 884 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 885 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 885 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 892 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 892 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 896 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PS19ExecTCReqStatusUpdate PUSService19__get_TC_params(const PUSService19 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    #line 901 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PS19ExecTCReqStatusUpdate ps19_req_status_update;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 917 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        ps19_req_status_update.action_tc_packet.tc_bytes[__i0] = 0U;
    }
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.action_tc_packet.tc_num_bytes = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.ev_action_ID.ev_action_index = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.ev_action_ID.found = 0;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.EvID = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.N = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.flags_ack = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_error_ctrl = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_id = 0U;
    #line 903 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.tc_num_bytes = 0U;

    #line 921 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 922 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 923 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 924 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 925 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler,
                                              &ps19_req_status_update.tc_data.N);

    #line 926 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &ps19_req_status_update.tc_data.EvID);

    #line 928 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (*subtype == 1U) {
        
        #line 930 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        ps19_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

        #line 932 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        for (size_t i = 0U; i < event_action_max_bytes && i < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; i = i + 1U) {
            
            #line 934 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            ps19_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                    i)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                    i + 12U)];

        }

    }

    #line 939 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return ps19_req_status_update;

}

PSExecTCReqStatus PUSService19__manage_error_in_acceptance(const PUSService19 * const self) {
    
    #line 988 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 988 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 989 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 989 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 991 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 991 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 991 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 993 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 993 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 994 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 998 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 996 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1000 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 1001 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1003 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 1004 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                         current_obt, &result);

        #line 1007 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 1009 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 1011 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1012 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 1012 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 1016 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 1017 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 1017 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 1022 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1022 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1026 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_short_pack_length_error(const PUSService19 * const self) {
    
    #line 945 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 945 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 946 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 946 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 948 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 948 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 948 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 950 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 950 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 951 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 955 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 953 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 957 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 958 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 960 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 961 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &result);

        #line 964 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 966 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 968 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 970 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 970 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 975 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 975 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 979 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 979 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 983 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_tm_limit_app_data_reached(const PUSService19 * const self) {
    
    #line 1031 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 1031 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1032 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 1032 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 1034 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 1034 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 1034 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 1036 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 1036 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 1037 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1041 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1039 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1043 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 1044 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1046 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 1047 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                             current_obt, &result);

        #line 1050 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 1052 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 1054 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1055 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 1055 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 1059 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 1060 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 1060 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 1065 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1065 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1069 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

void PUSService19__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService19 * self = (PUSService19 *)__this;

    #line 1075 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    uint8_t subtype = 0U;

    #line 1077 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 1081 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 1083 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            MyResult result;
            #line 1083 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            result.__variant = MyResult__Ok;

            #line 1084 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update = PUSService19__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          &result);

            #line 1086 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1087 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 1087 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 1089 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 1093 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 1095 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 1097 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_1TC(self);

            } else
            #line 1099 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 2U) {
                
                #line 1101 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_2TC(self);

            } else
            #line 1103 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 4U) {
                
                #line 1105 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_4TC(self);

            } else
            #line 1107 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 5U) {
                
                #line 1109 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_5TC(self);

            } else
            {
                
                #line 1113 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 1113 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 1116 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 1079 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 1118 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 1120 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 1123 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__manage_error_in_acceptance(self);

            } else
            #line 1125 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 1128 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__manage_tm_limit_app_data_reached(self);

            } else
            #line 1130 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 1132 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 1140 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 1079 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 1142 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 1142 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 1143 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 1152 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 1154 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 1157 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService19__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

void PUSService19__extract_action(void * const __this, size_t index,
                                  TCHandlerT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

    #line 1265 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 0U) {
        
        #line 1267 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U,
                                                                              self->pending_action_head[0U])];

    } else
    #line 1269 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 1U) {
        
        #line 1271 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                               self->pending_action_head[1U])];

    } else
    #line 1273 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 2U) {
        
        #line 1275 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                               self->pending_action_head[2U])];

    } else
    #line 1277 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 3U) {
        
        #line 1279 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                               self->pending_action_head[3U])];

    } else
    {
        

    }

    #line 1285 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__extract_action__mutex_lock(void * const __this, size_t index,
                                              TCHandlerT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__extract_action(self, index, action_packet);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__extract_action__task_lock(void * const __this, size_t index,
                                             TCHandlerT * const action_packet) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__extract_action(__this, index, action_packet);
    __termina_task__unlock(lock);

}

void PUSService19__extract_action__event_lock(void * const __this, size_t index,
                                              TCHandlerT * const action_packet) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__extract_action(__this, index, action_packet);
    __termina_event__unlock(lock);

}

_Bool PUSService19__get_event_action_config(const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled) {
    
    #line 82 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool found = 0;

    #line 84 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found == 0; i = i + 1U) {
        
        #line 86 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U,
                                                             i)].event_ID == evID) {
            
            #line 88 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            *index = i;

            #line 89 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            *enabled = self->event_action_config[__termina_array__index(16U,
                                                                        i)].enabled;

            #line 90 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            found = 1;

        }

    }

    #line 93 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return found;

}

void PUSService19__get_pending_action_number(void * const __this,
                                             size_t paction_num[4U]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    #line 1254 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 1256 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        paction_num[__termina_array__index(4U,
                                           i)] = self->pending_action_number[__termina_array__index(4U,
                                                                                                    i)];

    }

    #line 1260 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__get_pending_action_number__mutex_lock(void * const __this,
                                                         size_t paction_num[4U]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__get_pending_action_number(self, paction_num);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__get_pending_action_number__task_lock(void * const __this,
                                                        size_t paction_num[4U]) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__get_pending_action_number(__this, paction_num);
    __termina_task__unlock(lock);

}

void PUSService19__get_pending_action_number__event_lock(void * const __this,
                                                         size_t paction_num[4U]) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__get_pending_action_number(__this, paction_num);
    __termina_event__unlock(lock);

}

void PUSService19__manage_event_action(void * const __this, uint16_t evID) {
    
    PUSService19 * self = (PUSService19 *)__this;

    #line 1164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 1164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 1164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 1165 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool is_enabled = 0;

    #line 1166 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(self, &is_enabled, evID);

    #line 1168 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (found_and_id.found && is_enabled) {
        
        #line 1170 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 1172 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 1173 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            size_t tail_index = 0U;

            #line 1176 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 1178 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 1180 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 1181 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U,
                                                                         tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                          found_and_id.ev_action_index)];

                    #line 1182 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1190 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 1192 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 1194 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 1195 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1196 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1204 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 1206 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 1208 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 1209 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1210 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1218 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 1220 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 1222 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 1223 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1224 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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

    #line 1247 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return;

}

void PUSService19__manage_event_action__mutex_lock(void * const __this,
                                                   uint16_t evID) {
    
    PUSService19 * self = (PUSService19 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService19__manage_event_action(self, evID);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService19__manage_event_action__task_lock(void * const __this,
                                                  uint16_t evID) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService19__manage_event_action(__this, evID);
    __termina_task__unlock(lock);

}

void PUSService19__manage_event_action__event_lock(void * const __this,
                                                   uint16_t evID) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService19__manage_event_action(__this, evID);
    __termina_event__unlock(lock);

}
