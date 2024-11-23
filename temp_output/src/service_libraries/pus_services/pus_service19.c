
#include "service_libraries/pus_services/pus_service19.h"

_Bool PUSService19__get_event_action_config(const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled) {
    
    _Bool found = 0;

    for (size_t i = 0; i < max_event_action_definitions && found == 0; i = i + 1) {
        
        if (self->event_action_config[i].event_ID == evID) {
            
            *index = i;

            *enabled = self->event_action_config[i].enabled;

            found = 1;

        }

    }

    return found;

}

_Bool PUSService19__get_free_event_action_index(const PUSService19 * const self,
                                                size_t * const index) {
    
    _Bool found = 0;

    for (size_t i = 0; i < max_event_action_definitions && found == 0; i = i + 1) {
        
        if (self->event_action_config[i].event_ID == 0) {
            
            *index = i;

            found = 1;

        }

    }

    return found;

}

void PUSService19__exec19_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t index = 0;

    _Bool found = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (PUSService19__get_event_action_config(self, evID, &index,
                                                  &enabled)) {
            
            found = 1;

        } else {
            
            if (PUSService19__get_free_event_action_index(self, &index)) {
                
                found = 1;

                enabled = 0;

            } else {
                
                found = 0;

            }

        }

        if (found) {
            
            if (enabled) {
                
                build_tm_1_8_tc_19_X_event_action_enabled(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

            } else {
                
                size_t action_packet_length = (size_t)get_packet_length(tc_descriptor->tc_bytes) - 7;

                for (size_t i = 0; i < event_action_max_bytes && i < action_packet_length; i = i + 1) {
                    
                    self->event_action_packets[index].tc_bytes[i] = tc_descriptor->tc_bytes[i + 12];

                }

                self->event_action_packets[index].tc_num_bytes = action_packet_length;

                TCStatus tc_status;
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
                tc_status.error_code.__variant = TCErrorType__Undefined;
                tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

                tc_status = try_tc_acceptation(&self->event_action_packets[index]);

                if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                    
                    self->event_action_config[index].event_ID = evID;

                    self->event_action_config[index].enabled = 0;

                    build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

                } else {
                    
                    build_tm_1_8_tc_19_1_event_action_rejected(tm_descriptor,
                                                               tm_seq_counter,
                                                               evID,
                                                               tc_descriptor);

                }

            }

        } else {
            
            build_tm_1_8_tc_19_1_max_event_actions(tm_descriptor,
                                                   tm_seq_counter, evID,
                                                   tc_descriptor);

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__exec19_2TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t index = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (PUSService19__get_event_action_config(self, evID, &index,
                                                  &enabled)) {
            
            if (enabled) {
                
                build_tm_1_8_tc_19_X_event_action_enabled(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

            } else {
                
                self->event_action_config[index].event_ID = 0;

                self->event_action_config[index].enabled = 0;

                build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

            }

        } else {
            
            build_tm_1_8_tc_19_X_event_action_not_defined(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__exec19_4TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t index = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (PUSService19__get_event_action_config(self, evID, &index,
                                                  &enabled)) {
            
            self->event_action_config[index].enabled = 1;

            build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

        } else {
            
            build_tm_1_8_tc_19_X_event_action_not_defined(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__exec19_5TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t index = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (PUSService19__get_event_action_config(self, evID, &index,
                                                  &enabled)) {
            
            self->event_action_config[index].enabled = 0;

            build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

        } else {
            
            build_tm_1_8_tc_19_X_event_action_not_defined(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__extract_action(void * const __this, size_t index,
                                  TCDescriptorT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    if (index == 0) {
        
        *action_packet = self->pending_action_queue_1I[self->pending_action_head[0]];

    } else if (index == 1) {
        
        *action_packet = self->pending_action_queue_2LS[self->pending_action_head[1]];

    } else if (index == 2) {
        
        *action_packet = self->pending_action_queue_3MS[self->pending_action_head[2]];

    } else if (index == 3) {
        
        *action_packet = self->pending_action_queue_4HS[self->pending_action_head[3]];

    } else {
        

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__get_pending_action_number(void * const __this,
                                             size_t paction_num[4]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0; i < 3; i = i + 1) {
        
        paction_num[i] = self->pending_action_number[i];

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__manage_event_actions(void * const __this,
                                        EventList * const event_list) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0; i < max_num_events && i < event_list->num_events; i = i + 1) {
        
        EventInfo event_info;
        event_info.ev_RID = 0;
        for (size_t __i0 = 0; __i0 < event_aux_data_max_size; __i0 = __i0 + 1) {
            event_info.ev_aux_data[__i0] = 0;
        }
        event_info.ev_aux_data_size = 0;

        get_event_info(&*event_list, i, &event_info);

        _Bool RIDenabled = 0;

        (self->pus_service_5.is_RID_enabled_ext)(self->pus_service_5.__that,
                                                 event_info.ev_RID,
                                                 &RIDenabled);

        if (RIDenabled) {
            
            size_t index = 0;

            _Bool enabled = 0;

            if (PUSService19__get_event_action_config(self, event_info.ev_RID,
                                                      &index, &enabled)) {
                
                if (enabled) {
                    
                    RIDType RID_type = get_RID_type(event_info.ev_RID);

                    size_t tail_index = 0;

                    if (RID_type.__variant == RIDType__RIDNotValid) {
                        

                    } else if (RID_type.__variant == RIDType__MediumSeverityAnomaly) {
                        
                        tail_index = (size_t)(self->pending_action_head[2] + self->pending_action_number[2]) % event_action_queue_dimension;

                        self->pending_action_queue_3MS[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[2] = self->pending_action_number[2] + 1;

                    } else if (RID_type.__variant == RIDType__LowSeverityAnomaly) {
                        
                        tail_index = (size_t)(self->pending_action_head[1] + self->pending_action_number[1]) % event_action_queue_dimension;

                        self->pending_action_queue_2LS[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[1] = self->pending_action_number[1] + 1;

                    } else if (RID_type.__variant == RIDType__Informative) {
                        
                        tail_index = (size_t)(self->pending_action_head[0] + self->pending_action_number[0]) % event_action_queue_dimension;

                        self->pending_action_queue_1I[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[0] = self->pending_action_number[0] + 1;

                    } else {
                        
                        tail_index = (size_t)(self->pending_action_head[3] + self->pending_action_number[3]) % event_action_queue_dimension;

                        self->pending_action_queue_4HS[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[3] = self->pending_action_number[3] + 1;

                    }

                } else {
                    

                }

            }

        }

    }

    clear_ev_list(event_list);

    __termina_resource__unlock(&self->__resource);

    return;

}
