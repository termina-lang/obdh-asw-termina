
#include "service_libraries/pus_services/pus_service19.h"

static __status_int32_t CPUSService19__delete_event_action(const __termina_event_t * const __ev, CPUSService19 * const self);

static __status_int32_t CPUSService19__disable_event_action(const __termina_event_t * const __ev, CPUSService19 * const self);

static __status_int32_t CPUSService19__enable_event_action(const __termina_event_t * const __ev, CPUSService19 * const self);

static FoundID CPUSService19__get_free_event_action_index(const __termina_event_t * const __ev, const CPUSService19 * const self);

static FoundID CPUSService19__is_ev_action_defined(const __termina_event_t * const __ev, const CPUSService19 * const self, uint16_t evID);

static __status_int32_t CPUSService19__exec19_1TC(const __termina_event_t * const __ev, CPUSService19 * const self);

static __status_int32_t CPUSService19__exec19_2TC(const __termina_event_t * const __ev, CPUSService19 * const self);

static __status_int32_t CPUSService19__exec19_4TC(const __termina_event_t * const __ev, CPUSService19 * const self);

static __status_int32_t CPUSService19__exec19_5TC(const __termina_event_t * const __ev, CPUSService19 * const self);

static __status_int32_t CPUSService19__delete_event_action(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    (void)__ev;

    #line 67 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 69 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 71 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = 0U;

        #line 72 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = false;

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

static __status_int32_t CPUSService19__disable_event_action(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    (void)__ev;

    #line 35 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 37 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 39 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = false;

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

static __status_int32_t CPUSService19__enable_event_action(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    (void)__ev;

    #line 51 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 53 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.EvID == self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID) {
        
        #line 55 "src/service_libraries/pus_services/pus_service19.fin"
        self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = true;

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

static FoundID CPUSService19__get_free_event_action_index(const __termina_event_t * const __ev, const CPUSService19 * const self) {
    
    (void)__ev;

    #line 85 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id = { .enabled = false, .ev_action_index = 0U, .found = false };

    #line 87 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == false; i = i + 1U) {
        
        #line 89 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U, i)].event_ID == 0U) {
            
            #line 91 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 92 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.found = true;

        }

    }

    #line 95 "src/service_libraries/pus_services/pus_service19.fin"
    return found_and_id;

}

static FoundID CPUSService19__is_ev_action_defined(const __termina_event_t * const __ev, const CPUSService19 * const self, uint16_t evID) {
    
    (void)__ev;

    #line 100 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id = { .enabled = false, .ev_action_index = 0U, .found = false };

    #line 102 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 16U && found_and_id.found == false; i = i + 1U) {
        
        #line 104 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->event_action_config[__termina_array__index(16U, i)].event_ID == evID) {
            
            #line 106 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.ev_action_index = i;

            #line 107 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.enabled = self->event_action_config[__termina_array__index(16U, i)].enabled;

            #line 108 "src/service_libraries/pus_services/pus_service19.fin"
            found_and_id.found = true;

        }

    }

    #line 111 "src/service_libraries/pus_services/pus_service19.fin"
    return found_and_id;

}

static __status_int32_t CPUSService19__exec19_1TC(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    #line 119 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 121 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 123 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 129 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == false) {
        
        #line 131 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 138 "src/service_libraries/pus_services/pus_service19.fin"
        _Bool is_enabled = false;

        #line 139 "src/service_libraries/pus_services/pus_service19.fin"
        TC19_1_Error error;

        #line 141 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = CPUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

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
            self->exec_tc_req_status_update.ev_action_ID = CPUSService19__get_free_event_action_index(__ev, self);

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
            TCHandler action_tc_handler = { .app_data_index = 0U, .df_header = { .flag_ver_ack = 0U, .sourceID = 0U, .subtype = 0U, .type = 0U }, .packet_error_ctrl = 0U, .packet_header = { .packet_id = 0U, .packet_length = 0U, .packet_seq_ctrl = 0U }, .tc_descriptor = self->exec_tc_req_status_update.action_tc_packet };

            #line 187 "src/service_libraries/pus_services/pus_service19.fin"
            tc_handler_build(&action_tc_handler);

            #line 189 "src/service_libraries/pus_services/pus_service19.fin"
            TCStatus tc_status = try_tc_acceptation(&self->exec_tc_req_status_update.action_tc_packet);

            #line 191 "src/service_libraries/pus_services/pus_service19.fin"
            if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                
                #line 193 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                #line 198 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 200 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].event_ID = self->exec_tc_req_status_update.tc_data.EvID;

                    #line 201 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_config[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)].enabled = false;

                    #line 202 "src/service_libraries/pus_services/pus_service19.fin"
                    self->event_action_packets[__termina_array__index(16U, self->exec_tc_req_status_update.ev_action_ID.ev_action_index)] = action_tc_handler;

                    #line 204 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                }

            } else
            {
                
                #line 213 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.send_tm_1_4_ev_action_rejected(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

            }

        } else
        #line 222 "src/service_libraries/pus_services/pus_service19.fin"
        if (error.__variant == TC19_1_Error__EvIDEnabled) {
            
            #line 224 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        } else
        {
            
            #line 233 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_8_max_ev_actions_defined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 244 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

static __status_int32_t CPUSService19__exec19_2TC(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    #line 250 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 252 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 254 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 260 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == false) {
        
        #line 262 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 270 "src/service_libraries/pus_services/pus_service19.fin"
        _Bool is_enabled = false;

        #line 272 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = CPUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 275 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 277 "src/service_libraries/pus_services/pus_service19.fin"
            if (is_enabled) {
                
                #line 279 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.send_tm_1_4_ev_action_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

            } else
            {
                
                #line 287 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                #line 293 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 295 "src/service_libraries/pus_services/pus_service19.fin"
                    status = CPUSService19__delete_event_action(__ev, self);

                }

                #line 299 "src/service_libraries/pus_services/pus_service19.fin"
                if (status.__variant == Success) {
                    
                    #line 301 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

                }

            }

        } else
        {
            
            #line 313 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 323 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

static __status_int32_t CPUSService19__exec19_4TC(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    #line 329 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 331 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 333 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 339 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == false) {
        
        #line 341 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 349 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = CPUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 351 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 353 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 359 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 361 "src/service_libraries/pus_services/pus_service19.fin"
                status = CPUSService19__enable_event_action(__ev, self);

            }

            #line 365 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 367 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 377 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 386 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

static __status_int32_t CPUSService19__exec19_5TC(const __termina_event_t * const __ev, CPUSService19 * const self) {
    
    #line 392 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = { .__variant = Success };

    #line 395 "src/service_libraries/pus_services/pus_service19.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 397 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    #line 404 "src/service_libraries/pus_services/pus_service19.fin"
    if (is_Ev_ID_valid(self->exec_tc_req_status_update.tc_data.EvID) == false) {
        
        #line 406 "src/service_libraries/pus_services/pus_service19.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

    } else
    {
        
        #line 414 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.ev_action_ID = CPUSService19__is_ev_action_defined(__ev, self, self->exec_tc_req_status_update.tc_data.EvID);

        #line 417 "src/service_libraries/pus_services/pus_service19.fin"
        if (self->exec_tc_req_status_update.ev_action_ID.found) {
            
            #line 419 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 425 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 427 "src/service_libraries/pus_services/pus_service19.fin"
                status = CPUSService19__disable_event_action(__ev, self);

            }

            #line 431 "src/service_libraries/pus_services/pus_service19.fin"
            if (status.__variant == Success) {
                
                #line 433 "src/service_libraries/pus_services/pus_service19.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 443 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_ev_action_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.EvID, &status);

        }

    }

    #line 453 "src/service_libraries/pus_services/pus_service19.fin"
    return status;

}

void CPUSService19__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 456 "src/service_libraries/pus_services/pus_service19.fin"
    CPUSService19 * self = (CPUSService19 *)__this;

    #line 456 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 458 "src/service_libraries/pus_services/pus_service19.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 460 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 461 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 462 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 463 "src/service_libraries/pus_services/pus_service19.fin"
    self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 465 "src/service_libraries/pus_services/pus_service19.fin"
    __status_int32_t status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.N);

    #line 467 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 468 "src/service_libraries/pus_services/pus_service19.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.EvID);

    }

    #line 471 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success && subtype == 1U) {
        
        #line 473 "src/service_libraries/pus_services/pus_service19.fin"
        self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes = (size_t)(tc_handler->tc_descriptor.tc_num_bytes - 2U) - tc_handler->app_data_index;

        #line 475 "src/service_libraries/pus_services/pus_service19.fin"
        for (size_t j = 0U; j < event_action_max_bytes && j < self->exec_tc_req_status_update.action_tc_packet.tc_num_bytes; j = j + 1U) {
            
            #line 477 "src/service_libraries/pus_services/pus_service19.fin"
            self->exec_tc_req_status_update.action_tc_packet.tc_bytes[__termina_array__index(256U, j)] = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U, j + tc_handler->app_data_index)];

        }

    }

    #line 483 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 485 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 1U) {
            
            #line 487 "src/service_libraries/pus_services/pus_service19.fin"
            status = CPUSService19__exec19_1TC(__ev, self);

        } else
        #line 489 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 2U) {
            
            #line 491 "src/service_libraries/pus_services/pus_service19.fin"
            status = CPUSService19__exec19_2TC(__ev, self);

        } else
        #line 493 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 4U) {
            
            #line 495 "src/service_libraries/pus_services/pus_service19.fin"
            status = CPUSService19__exec19_4TC(__ev, self);

        } else
        #line 497 "src/service_libraries/pus_services/pus_service19.fin"
        if (subtype == 5U) {
            
            #line 499 "src/service_libraries/pus_services/pus_service19.fin"
            status = CPUSService19__exec19_5TC(__ev, self);

        } else
        {
            
            #line 503 "src/service_libraries/pus_services/pus_service19.fin"
            status.__variant = Failure;
            #line 503 "src/service_libraries/pus_services/pus_service19.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 511 "src/service_libraries/pus_services/pus_service19.fin"
    if (status.__variant == Success) {
        
        #line 513 "src/service_libraries/pus_services/pus_service19.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 516 "src/service_libraries/pus_services/pus_service19.fin"
        int32_t error_code = status.Failure.__0;

        #line 518 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 520 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 525 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 527 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 532 "src/service_libraries/pus_services/pus_service19.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 534 "src/service_libraries/pus_services/pus_service19.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.tc_num_bytes, action_status);

        } else
        {
            
            #line 542 "src/service_libraries/pus_services/pus_service19.fin"
            (*action_status).__variant = Failure;
            #line 542 "src/service_libraries/pus_services/pus_service19.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 549 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 549 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void CPUSService19__extract_action(const __termina_event_t * const __ev, void * const __this, size_t index, TCHandler * const action_packet) {
    
    #line 650 "src/service_libraries/pus_services/pus_service19.fin"
    CPUSService19 * self = (CPUSService19 *)__this;

    #line 650 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 652 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 0U) {
        
        #line 654 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_1I[__termina_array__index(8U, self->pending_action_head[0U])];

        #line 655 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[0U] = (size_t)(self->pending_action_head[0U] + 1U) % 8U;

        #line 656 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[0U] = self->pending_action_number[0U] - 1U;

    } else
    #line 658 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 1U) {
        
        #line 660 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_2LS[__termina_array__index(8U, self->pending_action_head[1U])];

        #line 661 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[1U] = (size_t)(self->pending_action_head[1U] + 1U) % 8U;

        #line 662 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[1U] = self->pending_action_number[1U] - 1U;

    } else
    #line 664 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 2U) {
        
        #line 666 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_3MS[__termina_array__index(8U, self->pending_action_head[2U])];

        #line 667 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[2U] = (size_t)(self->pending_action_head[2U] + 1U) % 8U;

        #line 668 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[2U] = self->pending_action_number[2U] - 1U;

    } else
    #line 670 "src/service_libraries/pus_services/pus_service19.fin"
    if (index == 3U) {
        
        #line 672 "src/service_libraries/pus_services/pus_service19.fin"
        *action_packet = self->pending_action_queue_4HS[__termina_array__index(8U, self->pending_action_head[3U])];

        #line 673 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_head[3U] = (size_t)(self->pending_action_head[3U] + 1U) % 8U;

        #line 674 "src/service_libraries/pus_services/pus_service19.fin"
        self->pending_action_number[3U] = self->pending_action_number[3U] - 1U;

    } else
    {
        

    }

    #line 680 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 680 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void CPUSService19__get_pending_action_number(const __termina_event_t * const __ev, void * const __this, size_t paction_num[4U]) {
    
    #line 639 "src/service_libraries/pus_services/pus_service19.fin"
    CPUSService19 * self = (CPUSService19 *)__this;

    #line 639 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 641 "src/service_libraries/pus_services/pus_service19.fin"
    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        #line 643 "src/service_libraries/pus_services/pus_service19.fin"
        paction_num[__termina_array__index(4U, i)] = self->pending_action_number[__termina_array__index(4U, i)];

    }

    #line 647 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 647 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}

void CPUSService19__manage_event_action(const __termina_event_t * const __ev, void * const __this, uint16_t evID) {
    
    #line 553 "src/service_libraries/pus_services/pus_service19.fin"
    CPUSService19 * self = (CPUSService19 *)__this;

    #line 553 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 555 "src/service_libraries/pus_services/pus_service19.fin"
    FoundID found_and_id = CPUSService19__is_ev_action_defined(__ev, self, evID);

    #line 557 "src/service_libraries/pus_services/pus_service19.fin"
    if (found_and_id.found && found_and_id.enabled) {
        
        #line 559 "src/service_libraries/pus_services/pus_service19.fin"
        if (found_and_id.ev_action_index < 16U) {
            
            #line 561 "src/service_libraries/pus_services/pus_service19.fin"
            Ev_IDType RID_type = get_Ev_ID_type(evID);

            #line 565 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__Informative) {
                
                #line 567 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[0U] < 8U) {
                    
                    #line 569 "src/service_libraries/pus_services/pus_service19.fin"
                    size_t tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % 8U;

                    #line 570 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_1I[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 571 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                } else
                {
                    

                }

            } else
            #line 579 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
                
                #line 581 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[1U] < 8U) {
                    
                    #line 583 "src/service_libraries/pus_services/pus_service19.fin"
                    size_t tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % 8U;

                    #line 584 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_2LS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 585 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                } else
                {
                    

                }

            } else
            #line 593 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
                
                #line 595 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[2U] < 8U) {
                    
                    #line 597 "src/service_libraries/pus_services/pus_service19.fin"
                    size_t tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % 8U;

                    #line 598 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_3MS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 599 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                } else
                {
                    

                }

            } else
            #line 607 "src/service_libraries/pus_services/pus_service19.fin"
            if (RID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
                
                #line 609 "src/service_libraries/pus_services/pus_service19.fin"
                if (self->pending_action_number[3U] < 8U) {
                    
                    #line 611 "src/service_libraries/pus_services/pus_service19.fin"
                    size_t tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % 8U;

                    #line 612 "src/service_libraries/pus_services/pus_service19.fin"
                    self->pending_action_queue_4HS[__termina_array__index(8U, tail_index)] = self->event_action_packets[__termina_array__index(16U, found_and_id.ev_action_index)];

                    #line 613 "src/service_libraries/pus_services/pus_service19.fin"
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

    #line 636 "src/service_libraries/pus_services/pus_service19.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 636 "src/service_libraries/pus_services/pus_service19.fin"
    return;

}
