
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
            action_tc_handler.tc_descriptor = self->exec_tc_req_status_update.action_tc_packet;

            #line 187 "src/service_libraries/pus_services/pus_service19.fin"
            tc_handler_build(&action_tc_handler);

            #line 189 "src/service_libraries/pus_services/pus_service19.fin"
            TCStatus tc_status;
            #line 190 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
            #line 192 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status.error_code.__variant = TCErrorType__Undefined;
            #line 191 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

            #line 195 "src/service_libraries/pus_services/pus_service19.fin"
            tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

            #line 197 "src/service_libraries/pus_services/pus_service19.fin"
            if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                
                #line 199 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                #line 204 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 206 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                    #line 207 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = 0;

                    #line 208 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_packets[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)] = action_tc_handler;

                    #line 210 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                }

            } else
            {
                
                #line 219 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.send_tm_1_4_ev_action_rejected(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

            }

        } else
        #line 228 "src/service_libraries/pus_services/pus_service19.fin"
        if (error.__variant == TC19_1_Error__EvIDEnabled) {
            
            #line 230 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        } else
        {
            
            #line 239 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_8_max_ev_actions_defined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 250 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_2TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 256 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 256 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 258 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 260 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 266 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 268 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 276 "src/service_libraries/pus_services/pus_service19.fin"
        _Bool is_enabled = 0;

        #line 278 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 281 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 283 "src/service_libraries/pus_services/pus_service19.fin"
            if (is_enabled) {
                
                #line 285 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.send_tm_1_4_ev_action_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

            } else
            {
                
                #line 293 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                #line 299 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 301 "src/service_libraries/pus_services/pus_service19.fin"
                    status = PUSService19__delete_event_action(__ev, self);

                }

                #line 305 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 307 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                }

            }

        } else
        {
            
            #line 319 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 329 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_4TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 335 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 335 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 337 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 339 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 345 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 347 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 355 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 357 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 359 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 365 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 367 "src/service_libraries/pus_services/pus_service19.fin"
                status = PUSService19__enable_event_action(__ev, self);

            }

            #line 371 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 373 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 383 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 392 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

__status_int32_t PUSService19__exec19_5TC(const __termina_event_t * const __ev, PUSService19 * const self) {
    
    #line 398 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 398 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 401 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 403 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 410 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == 0) {
        
        #line 412 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 420 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = PUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 423 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 425 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 431 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 433 "src/service_libraries/pus_services/pus_service19.fin"
                status = PUSService19__disable_event_action(__ev, self);

            }

            #line 437 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 439 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 449 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 459 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

void PUSService19__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 462 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 462 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 464 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status;
    #line 464 "src/service_libraries/pus_services/pus_service19.fin"
    status.__variant = Success;

    #line 465 "src/service_libraries/pus_services/pus_service19.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 467 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 468 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 469 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 470 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 472 "src/service_libraries/pus_services/pus_service19.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.N);

    #line 474 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 475 "src/service_libraries/pus_services/pus_service19.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.EvID);

    }

    #line 478 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success && subtype == 1U) {
        
        #line 480 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

        #line 482 "src/service_libraries/pus_services/pus_service19.fin"
        for (size_t j = 0U; j < event_action_max_bytes && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; j = j + 1U) {
            
            #line 484 "src/service_libraries/pus_services/pus_service19.fin"
            self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U, j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U, j + tc_handler->app_data_index)];

        }

    }

    #line 490 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 492 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 1U) {
            
            #line 494 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_1TC(__ev, self);

        } else
        #line 496 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 2U) {
            
            #line 498 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_2TC(__ev, self);

        } else
        #line 500 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 4U) {
            
            #line 502 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_4TC(__ev, self);

        } else
        #line 504 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 5U) {
            
            #line 506 "src/service_libraries/pus_services/pus_service19.fin"
            status = PUSService19__exec19_5TC(__ev, self);

        } else
        {
            
            #line 510 "src/service_libraries/pus_services/pus_service19.fin"
            status.__variant = Failure;
            #line 510 "src/service_libraries/pus_services/pus_service19.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 518 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 520 "src/service_libraries/pus_services/pus_service19.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 523 "src/service_libraries/pus_services/pus_service19.fin"
        int32_t error_code = status.Failure.__0;

        #line 525 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 527 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 532 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 534 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 539 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 541 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.tc_num_bytes, action_status);

        } else
        {
            
            #line 549 "src/service_libraries/pus_services/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 549 "src/service_libraries/pus_services/pus_service19.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 556 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 556 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void PUSService19__extract_action(const __termina_event_t * const __ev, void * const __this, size_t index, TCHandler * const action_packet) {
    
    #line 659 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 659 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 661 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 0U) {
        
        #line 663 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U, self->pending_action_head[0U])];

        #line 664 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[0U] = (size_t)(self->pending_action_head[0U] + 1U) % 8U;

        #line 665 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[0U] = self->pending_action_number[0U] - 1U;

    } else
    #line 667 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 1U) {
        
        #line 669 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U, self->pending_action_head[1U])];

        #line 670 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[1U] = (size_t)(self->pending_action_head[1U] + 1U) % 8U;

        #line 671 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[1U] = self->pending_action_number[1U] - 1U;

    } else
    #line 673 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 2U) {
        
        #line 675 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U, self->pending_action_head[2U])];

        #line 676 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[2U] = (size_t)(self->pending_action_head[2U] + 1U) % 8U;

        #line 677 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[2U] = self->pending_action_number[2U] - 1U;

    } else
    #line 679 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 3U) {
        
        #line 681 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U, self->pending_action_head[3U])];

        #line 682 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[3U] = (size_t)(self->pending_action_head[3U] + 1U) % 8U;

        #line 683 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[3U] = self->pending_action_number[3U] - 1U;

    } else
    {
        

    }

    #line 689 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 689 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev, void * const __this, size_t paction_num[4U]) {
    
    #line 648 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 648 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 650 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 652 "src/service_libraries/pus_services/pus_service19.fin"
        paction_num[__termina_array__index(4U, i)] = self->pending_action_number[__termina_array__index(4U, i)];

    }

    #line 656 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 656 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void PUSService19__manage_event_action(const __termina_event_t * const __ev, void * const __this, uint16_t evID) {
    
    #line 560 "src/service_libraries/pus_services/pus_service19.fin"
    PUSService19 * self = (PUSService19 *)__this;

    #line 560 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 562 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id;
    #line 562 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.enabled = 0;
    #line 562 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.ev_action_index = 0U;
    #line 562 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id.found = 0;

    #line 563 "src/service_libraries/pus_services/pus_service19.fin"
    found_and_id = PUSService19__is_ev_action_defined(__ev, self, evID);

    #line 565 "src/service_libraries/pus_services/pus_service19.fin"
    if (found_and_id.found && found_and_id.enabled) {
        
        #line 567 "src/service_libraries/pus_services/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 569 "src/service_libraries/pus_services/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 570 "src/service_libraries/pus_services/pus_service19.fin"
            size_t tail_index = 0U;

            #line 574 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 576 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 578 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 579 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 580 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 588 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 590 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 592 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 593 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 594 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 602 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 604 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 606 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 607 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 608 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 616 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 618 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 620 "src/service_libraries/pus_services/pus_service19.fin"
                    tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 621 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 622 "src/service_libraries/pus_services/pus_service19.fin"
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

    #line 645 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 645 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}
