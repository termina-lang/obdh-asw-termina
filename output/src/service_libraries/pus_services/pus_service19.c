
#include "service_libraries/pus_services/pus_service19.h"

__status_int32_t PUSService19__delete_event_action(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 67 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 67 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 69 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 71 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = 0U;

        #line 72 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

    } else
    {
        
        #line 77 "src/service_libraries/pus_services/pus_service19.fin"
        status.__variant = Failure;
        #line 77 "src/service_libraries/pus_services/pus_service19.fin"
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    #line 80 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__disable_event_action(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 35 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 35 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 37 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 39 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

    } else
    {
        
        #line 43 "src/service_libraries/pus_services/pus_service19.fin"
        status.__variant = Failure;
        #line 43 "src/service_libraries/pus_services/pus_service19.fin"
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    #line 46 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__enable_event_action(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 51 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 51 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 53 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 55 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 1;

    } else
    {
        
        #line 59 "src/service_libraries/pus_services/pus_service19.fin"
        status.__variant = Failure;
        #line 59 "src/service_libraries/pus_services/pus_service19.fin"
        status.Failure.__0 = EVENT_ACTION_NOT_DEFINED_ERROR;

    }

    #line 62 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

FoundID PUSService19__get_free_event_action_index(const __termina_event_t * const __ev, const PUSService19 * const self) {
    
    #line 85 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id;
    #line 85 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 85 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 85 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.found = 0;

    #line 87 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 89 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U, i)].event_ID == 0U) {
            
            #line 91 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 92 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 95 "src/service_libraries/pus_services/pus_service19.fin"
    return found_and_id;

}

FoundID PUSService19__is_ev_action_defined(const __termina_event_t * const __ev, const PUSService19 * const self, uint16_t evID) {
    
    #line 100 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id;
    #line 100 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 100 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 100 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.found = 0;

    #line 102 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == 0; i = i + 1U) {
        
        #line 104 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U, i)].event_ID == evID) {
            
            #line 106 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 107 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.enabled = self->event_action_config[__termina_array__index(16U, i)].enabled;

            #line 108 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.found = 1;

        }

    }

    #line 111 "src/service_libraries/pus_services/pus_service19.fin"
    return found_and_id;

}

__status_int32_t PUSService19__exec19_1TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 119 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 119 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 121 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 123 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 129 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 131 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 138 "src/service_libraries/pus_services/pus_service19.fin"
        _Bool is_enabled = 0;

        #line 139 "src/service_libraries/pus_services/pus_service19.fin"
        TC19_1_Error error;
        #line 139 "src/service_libraries/pus_services/pus_service19.fin"
        error.__variant = TC19_1_Error__NoError;

        #line 141 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 143 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 145 "src/service_libraries/pus_services/pus_service19.fin"
            if (is_enabled) {
                
                #line 147 "src/service_libraries/pus_services/pus_service19.fin"
                error.__variant = TC19_1_Error__EvIDEnabled;

            } else
            {
                
                #line 151 "src/service_libraries/pus_services/pus_service19.fin"
                error.__variant = TC19_1_Error__NoError;

            }

        } else
        {
            
            #line 156 "src/service_libraries/pus_services/pus_service19.fin"
            self->exec_tc_req_status_update.ev_action_ID = PUSService19__get_free_event_action_index(__ev, self);

            #line 158 "src/service_libraries/pus_services/pus_service19.fin"
            if (self->exec_tc_req_status_update.ev_action_ID.found) {
                
                #line 159 "src/service_libraries/pus_services/pus_service19.fin"
                error.__variant = TC19_1_Error__NoError;

            } else
            {
                
                #line 162 "src/service_libraries/pus_services/pus_service19.fin"
                error.__variant = TC19_1_Error__MaxEventActionDefinitions;

            }

        }

        #line 168 "src/service_libraries/pus_services/pus_service19.fin"
        if (error.__variant == TC19_1_Error__NoError) {
            
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            TCHandler action_tc_handler;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.app_data_index = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.df_header.flag_ver_ack = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.df_header.sourceID = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.df_header.subtype = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.df_header.type = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.packet_error_ctrl = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.packet_header.packet_id = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.packet_header.packet_length = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.packet_header.packet_seq_ctrl = 0U;
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
                #line 27 "src/service_libraries/pus_tc_handler.fin"
                action_tc_handler.tc_descriptor.tc_bytes[__i0] = 0U;
            }
            #line 170 "src/service_libraries/pus_services/pus_service19.fin"
            action_tc_handler.tc_descriptor.tc_num_bytes = 0U;

            #line 172 "src/service_libraries/pus_services/pus_service19.fin"
            tc_handler_build_from_descriptor(&action_tc_handler, &self->exec_tc_req_status_update.action_tc_packet);

            #line 174 "src/service_libraries/pus_services/pus_service19.fin"
            TCStatus tc_status;
            #line 175 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
            #line 177 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status.error_code.__variant = TCErrorType__Undefined;
            #line 176 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

            #line 180 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

            #line 182 "src/service_libraries/pus_services/pus_service19.fin"
            if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                
                #line 184 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                #line 189 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                    #line 192 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                    #line 193 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_packets[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)] = action_tc_handler;

                    #line 195 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                }

            } else
            {
                
                #line 204 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.send_tm_1_4_ev_action_rejected(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

            }

        } else
        #line 213 "src/service_libraries/pus_services/pus_service19.fin"
        if (error.__variant == TC19_1_Error__EvIDEnabled) {
            
            #line 215 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        } else
        {
            
            #line 224 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_8_max_ev_actions_defined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 235 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_2TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 241 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 241 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 243 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 245 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 251 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 253 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 261 "src/service_libraries/pus_services/pus_service19.fin"
        _Bool is_enabled = 0;

        #line 263 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 266 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 268 "src/service_libraries/pus_services/pus_service19.fin"
            if (is_enabled) {
                
                #line 270 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.send_tm_1_4_ev_action_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

            } else
            {
                
                #line 278 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                #line 284 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 286 "src/service_libraries/pus_services/pus_service19.fin"
                    status = PUSService19__delete_event_action(__ev, self);

                }

                #line 290 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 292 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                }

            }

        } else
        {
            
            #line 304 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 314 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_4TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 320 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 320 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 322 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 324 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 330 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 332 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 340 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 342 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 344 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 350 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 352 "src/service_libraries/pus_services/pus_service19.fin"
                status = PUSService19__enable_event_action(__ev, self);

            }

            #line 356 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 358 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 368 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 377 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_5TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 383 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 383 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 386 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 388 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 395 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 397 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 405 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 408 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 410 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 416 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 418 "src/service_libraries/pus_services/pus_service19.fin"
                status = PUSService19__disable_event_action(__ev, self);

            }

            #line 422 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 424 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 434 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 444 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

void PUSService19__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 447 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 447 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 449 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 449 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 450 "src/service_libraries/pus_services/pus_service19.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 452 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 453 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 454 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 455 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 457 "src/service_libraries/pus_services/pus_service19.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.N);

    #line 459 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 460 "src/service_libraries/pus_services/pus_service19.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.EvID);

    }

    #line 463 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success && subtype == 1U) {
        
        #line 465 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

        #line 467 "src/service_libraries/pus_services/pus_service19.fin"
        for (size_t j = 0U; j < event_action_max_bytes && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; j = j + 1U) {
            
            #line 469 "src/service_libraries/pus_services/pus_service19.fin"
            self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U, j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U, j + tc_handler->app_data_index)];

        }

    }

    #line 475 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 477 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 1U) {
            
            #line 479 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_1TC(__ev, self);

        } else
        #line 481 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 2U) {
            
            #line 483 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_2TC(__ev, self);

        } else
        #line 485 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 4U) {
            
            #line 487 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_4TC(__ev, self);

        } else
        #line 489 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 5U) {
            
            #line 491 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_5TC(__ev, self);

        } else
        {
            
            #line 495 "src/service_libraries/pus_services/pus_service19.fin"
            status.__variant = Failure;
            #line 495 "src/service_libraries/pus_services/pus_service19.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 503 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 505 "src/service_libraries/pus_services/pus_service19.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 508 "src/service_libraries/pus_services/pus_service19.fin"
        int32_t error_code = status.Failure.__0;

        #line 510 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 512 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 517 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 519 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 524 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 526 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.tc_num_bytes, action_status);

        } else
        {
            
            #line 534 "src/service_libraries/pus_services/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 534 "src/service_libraries/pus_services/pus_service19.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 541 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 541 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void PUSService19__extract_action(const __termina_event_t * const __ev, void * const __this, size_t index, TCHandler * const action_packet) {
    
    #line 644 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 644 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 646 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 0U) {
        
        #line 648 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U, self->pending_action_head[0U])];

        #line 649 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[0U] = (size_t)(self->pending_action_head[0U] + 1U) % 8U;

        #line 650 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[0U] = self->pending_action_number[0U] - 1U;

    } else
    #line 652 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 1U) {
        
        #line 654 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U, self->pending_action_head[1U])];

        #line 655 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[1U] = (size_t)(self->pending_action_head[1U] + 1U) % 8U;

        #line 656 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[1U] = self->pending_action_number[1U] - 1U;

    } else
    #line 658 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 2U) {
        
        #line 660 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U, self->pending_action_head[2U])];

        #line 661 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[2U] = (size_t)(self->pending_action_head[2U] + 1U) % 8U;

        #line 662 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[2U] = self->pending_action_number[2U] - 1U;

    } else
    #line 664 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 3U) {
        
        #line 666 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U, self->pending_action_head[3U])];

        #line 667 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[3U] = (size_t)(self->pending_action_head[3U] + 1U) % 8U;

        #line 668 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[3U] = self->pending_action_number[3U] - 1U;

    } else
    {
        

    }

    #line 674 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 674 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev, void * const __this, size_t paction_num[4U]) {
    
    #line 633 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 633 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 635 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 637 "src/service_libraries/pus_services/pus_service19.fin"
        paction_num[__termina_array__index(4U, i)] = self->pending_action_number[__termina_array__index(4U, i)];

    }

    #line 641 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 641 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void PUSService19__manage_event_action(const __termina_event_t * const __ev, void * const __this, uint16_t evID) {
    
    #line 545 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 545 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 547 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id;
    #line 547 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 547 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 547 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.found = 0;

    #line 548 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(__ev, self, evID);

    #line 550 "src/service_libraries/pus_services/pus_service19.fin"
    if (found_and_id.found && found_and_id.enabled) {
        
        #line 552 "src/service_libraries/pus_services/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 554 "src/service_libraries/pus_services/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 555 "src/service_libraries/pus_services/pus_service19.fin"
            size_t tail_index = 0U;

            #line 559 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 561 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 563 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 564 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 565 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 573 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 575 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 577 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 578 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 579 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 587 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 589 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 591 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 592 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 593 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 601 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 603 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 605 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 606 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 607 "src/service_libraries/pus_services/pus_service19.fin"
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

    #line 630 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 630 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}
