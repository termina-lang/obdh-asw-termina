
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
    PSExecTCReqStatus next_status;
    #line 134 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 136 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 136 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 136 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 138 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 138 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 139 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 143 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 141 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 145 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 148 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 150 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 151 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 154 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 156 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 158 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 159 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 159 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 165 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 165 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 170 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 172 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 173 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                TC19_1_Error error;
                #line 173 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                error.__variant = TC19_1_Error__NoError;

                #line 175 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 177 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 179 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 181 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__EvIDEnabled;

                    } else
                    {
                        
                        #line 185 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    }

                } else
                {
                    
                    #line 190 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(self);

                    #line 192 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (self->exec_tc_req_status_update.ev_action_ID.found) {
                        
                        #line 193 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__NoError;

                    } else
                    {
                        
                        #line 196 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        error.__variant = TC19_1_Error__MaxEventActionDefinitions;

                    }

                }

                #line 202 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__NoError) {
                    
                    #line 204 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCHandlerT action_tc_handler = tc_handler_init();

                    #line 206 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_handler_build_from_descriptor(&action_tc_handler,
                                                     &self->exec_tc_req_status_update.action_tc_packet);

                    #line 208 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    TCStatus tc_status;
                    #line 209 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                    #line 211 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.error_code.__variant = TCErrorType__Undefined;
                    #line 210 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                    #line 214 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

                    #line 216 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                        
                        #line 218 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 219 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     current_obt, &result);

                        #line 221 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 223 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 225 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 226 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 226 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 231 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 232 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 232 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                        #line 235 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                        #line 236 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->event_action_config[__termina_array__index(16U,
                                                                         self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                        #line 239 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 239 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 240 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 244 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 242 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 246 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 247 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 248 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 249 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2, current_obt, &result);

                            #line 251 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 253 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 255 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 256 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 256 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 261 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 262 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 262 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 266 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 266 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 272 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 273 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_4_ev_action_rejected((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt, &result);

                        #line 276 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 278 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 280 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 281 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 281 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 286 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 287 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 287 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    }

                } else
                #line 293 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (error.__variant == TC19_1_Error__EvIDEnabled) {
                    
                    #line 295 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 296 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.tc_data.packet_id,
                                                   self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_data.EvID,
                                                   current_obt, &result);

                    #line 299 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 301 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 303 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 304 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 304 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 309 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 310 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 310 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 316 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 317 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_8_max_ev_actions_defined((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.tc_data.packet_id,
                                                        self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                        self->exec_tc_req_status_update.tc_data.EvID,
                                                        current_obt, &result);

                    #line 320 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 322 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 324 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 325 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 325 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 330 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 331 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 331 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 339 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 340 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 343 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 345 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 347 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 348 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 348 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 353 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 354 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 354 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 362 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 362 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 366 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_2TC(PUSService19 * const self) {
    
    #line 373 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 373 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 374 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 374 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 376 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 376 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 376 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 378 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 378 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 379 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 383 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 381 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 385 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 386 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 388 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 390 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 391 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 394 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 396 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 398 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 399 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 399 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 403 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 404 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 404 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 409 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 411 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 413 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 415 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 417 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (is_enabled) {
                        
                        #line 419 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 420 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_4_ev_action_enabled((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.tc_data.EvID,
                                                       current_obt, &result);

                        #line 423 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 425 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 427 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 428 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 428 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 432 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 433 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 433 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 438 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 439 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                     current_obt, &result);

                        #line 441 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 443 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 445 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 446 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 446 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 450 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 451 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 451 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                        #line 454 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        result = PUSService19__delete_event_action(self);

                        #line 456 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 458 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __option_box_t tm_handler2;
                            #line 458 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            tm_handler2.__variant = None;

                            #line 459 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                          &tm_handler2);

                            #line 463 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (tm_handler2.__variant == Some) {
                                
                                #line 461 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                                #line 465 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                uint16_t tm_count2 = 0U;

                                #line 466 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                                   &tm_count2);

                                #line 467 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                    &current_obt);

                                #line 468 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                             tm_count2, current_obt, &result);

                                #line 470 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Ok) {
                                    
                                    #line 472 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->tm_channel.send_tm(self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &result);

                                    #line 474 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    if (result.__variant == MyResult__Error) {
                                        
                                        #line 475 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.__variant = PSExecTCReqStatus__Failure;
                                        #line 475 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                        next_status.Failure.__0 = TM_SEND_FAILURE;

                                    }

                                } else
                                {
                                    
                                    #line 479 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                    #line 480 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Error;
                                    #line 480 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Error.__0 = BUILD_TM_ERROR;

                                }

                            } else
                            {
                                
                                #line 485 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 485 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                            }

                        }

                    }

                } else
                {
                    
                    #line 495 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 496 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &result);

                    #line 499 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 501 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 503 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 504 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 504 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 508 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 509 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 509 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 514 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 515 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 518 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 520 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 522 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 523 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 523 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 527 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 528 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 528 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 535 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 535 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 539 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_4TC(PUSService19 * const self) {
    
    #line 546 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 546 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 547 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 547 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 549 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 549 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 549 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 551 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 551 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 552 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 556 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 554 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 558 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 559 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 561 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 563 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 564 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 567 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 569 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 571 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 572 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 572 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 576 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 577 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 577 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 583 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 585 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 587 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 589 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 591 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 592 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    #line 594 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 596 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 598 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 599 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 599 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 603 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 604 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 604 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    #line 607 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    result = PUSService19__enable_event_action(self);

                    #line 609 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 611 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 611 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 612 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 616 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 614 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 618 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 619 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 620 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 621 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2, current_obt, &result);

                            #line 623 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 625 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 627 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 628 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 628 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 632 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 633 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 633 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 638 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 638 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 645 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 646 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &result);

                    #line 649 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 651 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 653 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 654 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 654 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 658 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 659 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 659 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 665 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 666 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 669 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 671 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 673 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 674 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 678 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 679 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 679 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 686 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 686 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 690 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__exec19_5TC(PUSService19 * const self) {
    
    #line 696 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 696 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 697 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 697 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 699 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 699 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 699 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 701 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 701 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 702 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 706 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 704 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 708 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 709 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 711 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 713 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 714 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 717 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 719 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 721 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 722 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 722 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 726 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 727 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 727 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 732 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID)) {
                
                #line 734 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                _Bool is_enabled = 0;

                #line 736 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(self,
                                                                                                  &is_enabled,
                                                                                                  self->exec_tc_req_status_update.tc_data.EvID);

                #line 738 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->exec_tc_req_status_update.ev_action_ID.found) {
                    
                    #line 740 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 741 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    #line 743 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 745 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 747 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 748 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 748 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 752 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 753 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 753 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    #line 756 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    result = PUSService19__disable_event_action(self);

                    #line 758 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 760 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        __option_box_t tm_handler2;
                        #line 760 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        tm_handler2.__variant = None;

                        #line 761 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 765 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 763 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 767 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            uint16_t tm_count2 = 0U;

                            #line 768 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 769 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 770 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2, current_obt, &result);

                            #line 772 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 774 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 776 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 777 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 777 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 781 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 782 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 782 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 787 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 787 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 794 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 795 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    build_tm_1_4_ev_action_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.tc_data.packet_id,
                                                     self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data.EvID,
                                                     current_obt, &result);

                    #line 798 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 800 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 802 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 803 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 803 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 807 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 808 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 808 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 813 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 814 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                            self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data.EvID,
                                            current_obt, &result);

                #line 817 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 819 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 821 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 822 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 822 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 826 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 827 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 827 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 834 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 834 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 838 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PS19ExecTCReqStatusUpdate PUSService19__get_TC_params(const PUSService19 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    #line 843 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PS19ExecTCReqStatusUpdate ps19_req_status_update;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 858 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        ps19_req_status_update.action_tc_packet.tc_bytes[__i0] = 0U;
    }
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.action_tc_packet.tc_num_bytes = 0U;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.ev_action_ID.ev_action_index = 0U;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.ev_action_ID.found = 0;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.EvID = 0U;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.N = 0U;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_error_ctrl = 0U;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_id = 0U;
    #line 845 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.tc_num_bytes = 0U;

    #line 862 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 863 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 864 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    ps19_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 865 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler,
                                              &ps19_req_status_update.tc_data.N);

    #line 866 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &ps19_req_status_update.tc_data.EvID);

    #line 868 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (*subtype == 1U) {
        
        #line 870 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        ps19_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

        #line 872 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        for (size_t i = 0U; i < event_action_max_bytes && i < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; i = i + 1U) {
            
            #line 874 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            ps19_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U,
                                                                                    i)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                                                                                                    i + 12U)];

        }

    }

    #line 879 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return ps19_req_status_update;

}

PSExecTCReqStatus PUSService19__manage_error_in_acceptance(const PUSService19 * const self) {
    
    #line 928 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 928 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 929 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 929 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 931 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 931 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 931 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 933 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 933 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 934 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 938 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 936 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 940 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 941 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 943 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 944 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                         current_obt, &result);

        #line 947 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 949 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 951 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 952 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 952 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 956 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 957 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 957 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 962 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 962 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 966 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_short_pack_length_error(const PUSService19 * const self) {
    
    #line 885 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 885 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 886 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 886 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 888 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 888 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 888 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 890 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 890 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 891 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 895 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 893 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 897 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 898 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 900 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 901 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &result);

        #line 904 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 906 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 908 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 910 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 910 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 914 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 915 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 915 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 919 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 919 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 923 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

PSExecTCReqStatus PUSService19__manage_tm_limit_app_data_reached(const PUSService19 * const self) {
    
    #line 971 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    PSExecTCReqStatus next_status;
    #line 971 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 972 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MyResult result;
    #line 972 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    result.__variant = MyResult__Ok;

    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    MissionObt current_obt;
    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.finetime = 0U;
    #line 974 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    current_obt.seconds = 0U;

    #line 976 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    __option_box_t tm_handler;
    #line 976 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    tm_handler.__variant = None;

    #line 977 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 981 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (tm_handler.__variant == Some) {
        
        #line 979 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 983 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        uint16_t tm_count = 0U;

        #line 984 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 986 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 987 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                             current_obt, &result);

        #line 990 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 992 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 994 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 995 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 995 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 999 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 1000 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 1000 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 1005 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1005 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1009 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    return next_status;

}

void PUSService19__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService19 * self = (PUSService19 *)__this;

    #line 1015 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    uint8_t subtype = 0U;

    #line 1017 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 1021 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 1023 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            MyResult result;
            #line 1023 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            result.__variant = MyResult__Ok;

            #line 1024 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status_update = PUSService19__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          &result);

            #line 1026 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1027 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 1027 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 1029 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 1033 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 1035 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 1U) {
                
                #line 1037 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_1TC(self);

            } else
            #line 1039 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 2U) {
                
                #line 1041 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_2TC(self);

            } else
            #line 1043 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 4U) {
                
                #line 1045 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_4TC(self);

            } else
            #line 1047 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (subtype == 5U) {
                
                #line 1049 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__exec19_5TC(self);

            } else
            {
                
                #line 1053 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 1053 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 1056 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 1019 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 1058 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 1060 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 1063 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__manage_error_in_acceptance(self);

            } else
            #line 1065 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 1068 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__manage_tm_limit_app_data_reached(self);

            } else
            #line 1070 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 1072 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                self->exec_tc_req_status = PUSService19__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 1080 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 1019 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 1082 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 1082 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 1083 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 1092 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 1094 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 1097 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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

    #line 1205 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 0U) {
        
        #line 1207 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U,
                                                                              self->pending_action_head[0U])];

    } else
    #line 1209 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 1U) {
        
        #line 1211 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                               self->pending_action_head[1U])];

    } else
    #line 1213 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 2U) {
        
        #line 1215 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                               self->pending_action_head[2U])];

    } else
    #line 1217 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (index == 3U) {
        
        #line 1219 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                               self->pending_action_head[3U])];

    } else
    {
        

    }

    #line 1225 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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

    #line 1194 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 1196 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        paction_num[__termina_array__index(4U,
                                           i)] = self->pending_action_number[__termina_array__index(4U,
                                                                                                    i)];

    }

    #line 1200 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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

    #line 1104 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    FoundID found_and_id;
    #line 1104 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 1104 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id.found = 0;

    #line 1105 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    _Bool is_enabled = 0;

    #line 1106 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(self, &is_enabled, evID);

    #line 1108 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
    if (found_and_id.found && is_enabled) {
        
        #line 1110 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 1112 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 1113 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            size_t tail_index = 0U;

            #line 1116 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 1118 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 1120 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 1121 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U,
                                                                         tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                          found_and_id.ev_action_index)];

                    #line 1122 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1130 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 1132 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 1134 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 1135 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1136 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1144 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 1146 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 1148 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 1149 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1150 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 1158 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 1160 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 1162 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 1163 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U,
                                                                          tail_index)] = self->event_action_packets[__termina_array__index(16U,
                                                                                                                                           found_and_id.ev_action_index)];

                    #line 1164 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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

    #line 1187 "src/service_libraries/pus_services/pus_service19/pus_service19.fin"
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
