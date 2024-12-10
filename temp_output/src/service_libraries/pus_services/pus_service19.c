
#include "service_libraries/pus_services/pus_service19.h"

_Bool PUSService19__get_event_action_config(const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled) {
    
    _Bool found = 0;

    for (size_t i = 0U; i < max_event_action_definitions && found == 0; i = i + 1U) {
        
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

    for (size_t i = 0U; i < max_event_action_definitions && found == 0; i = i + 1U) {
        
        if (self->event_action_config[i].event_ID == 0U) {
            
            *index = i;

            found = 1;

        }

    }

    return found;

}

void PUSService19__exec19_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = 0U;

        _Bool found = 0;

        _Bool enabled = 0;

        uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10U]);

        RIDType event_type = get_RID_type(evID);

        if (event_type.__variant == RIDType__RIDNotValid) {
            
            build_tm_1_8_tc_5_X_RIDunknown((TMDescriptorT *)descriptor.data,
                                           tm_count, evID, tc_descriptor);

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
                    
                    build_tm_1_8_tc_19_X_event_action_enabled((TMDescriptorT *)descriptor.data,
                                                              tm_count, evID,
                                                              tc_descriptor);

                } else {
                    
                    size_t action_packet_length = (size_t)get_packet_length(tc_descriptor->tc_bytes) - 7U;

                    for (size_t i = 0U; i < event_action_max_bytes && i < action_packet_length; i = i + 1U) {
                        
                        self->event_action_packets[index].tc_bytes[i] = tc_descriptor->tc_bytes[i + 12U];

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

                        build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                                     tc_descriptor);

                    } else {
                        
                        build_tm_1_8_tc_19_1_event_action_rejected((TMDescriptorT *)descriptor.data,
                                                                   tm_count,
                                                                   evID,
                                                                   tc_descriptor);

                    }

                }

            } else {
                
                build_tm_1_8_tc_19_1_max_event_actions((TMDescriptorT *)descriptor.data,
                                                       tm_count, evID,
                                                       tc_descriptor);

            }

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__exec19_2TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = 0U;

        _Bool enabled = 0;

        uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10U]);

        RIDType event_type = get_RID_type(evID);

        if (event_type.__variant == RIDType__RIDNotValid) {
            
            build_tm_1_8_tc_5_X_RIDunknown((TMDescriptorT *)descriptor.data,
                                           tm_count, evID, tc_descriptor);

        } else {
            
            if (PUSService19__get_event_action_config(self, evID, &index,
                                                      &enabled)) {
                
                if (enabled) {
                    
                    build_tm_1_8_tc_19_X_event_action_enabled((TMDescriptorT *)descriptor.data,
                                                              tm_count, evID,
                                                              tc_descriptor);

                } else {
                    
                    self->event_action_config[index].event_ID = 0U;

                    self->event_action_config[index].enabled = 0;

                    build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                                 tc_descriptor);

                }

            } else {
                
                build_tm_1_8_tc_19_X_event_action_not_defined((TMDescriptorT *)descriptor.data,
                                                              tm_count, evID,
                                                              tc_descriptor);

            }

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__exec19_4TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = 0U;

        _Bool enabled = 0;

        uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10U]);

        RIDType event_type = get_RID_type(evID);

        if (event_type.__variant == RIDType__RIDNotValid) {
            
            build_tm_1_8_tc_5_X_RIDunknown((TMDescriptorT *)descriptor.data,
                                           tm_count, evID, tc_descriptor);

        } else {
            
            if (PUSService19__get_event_action_config(self, evID, &index,
                                                      &enabled)) {
                
                self->event_action_config[index].enabled = 1;

                build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                             tc_descriptor);

            } else {
                
                build_tm_1_8_tc_19_X_event_action_not_defined((TMDescriptorT *)descriptor.data,
                                                              tm_count, evID,
                                                              tc_descriptor);

            }

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__exec19_5TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = 0U;

        _Bool enabled = 0;

        uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10U]);

        RIDType event_type = get_RID_type(evID);

        if (event_type.__variant == RIDType__RIDNotValid) {
            
            build_tm_1_8_tc_5_X_RIDunknown((TMDescriptorT *)descriptor.data,
                                           tm_count, evID, tc_descriptor);

        } else {
            
            if (PUSService19__get_event_action_config(self, evID, &index,
                                                      &enabled)) {
                
                self->event_action_config[index].enabled = 0;

                build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                             tc_descriptor);

            } else {
                
                build_tm_1_8_tc_19_X_event_action_not_defined((TMDescriptorT *)descriptor.data,
                                                              tm_count, evID,
                                                              tc_descriptor);

            }

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__extract_action(void * const __this, size_t index,
                                  TCDescriptorT * const action_packet) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    if (index == 0U) {
        
        *action_packet = self->pending_action_queue_1I[self->pending_action_head[0U]];

    } else if (index == 1U) {
        
        *action_packet = self->pending_action_queue_2LS[self->pending_action_head[1U]];

    } else if (index == 2U) {
        
        *action_packet = self->pending_action_queue_3MS[self->pending_action_head[2U]];

    } else if (index == 3U) {
        
        *action_packet = self->pending_action_queue_4HS[self->pending_action_head[3U]];

    } else {
        

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__get_pending_action_number(void * const __this,
                                             size_t paction_num[4U]) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0U; i < 3U; i = i + 1U) {
        
        paction_num[i] = self->pending_action_number[i];

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService19__manage_event_actions(void * const __this,
                                        EventList * const event_list) {
    
    PUSService19 * self = (PUSService19 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0U; i < max_num_events && i < event_list->num_events; i = i + 1U) {
        
        EventInfo event_info;
        event_info.ev_RID = 0U;
        for (size_t __i0 = 0U; __i0 < event_aux_data_max_size; __i0 = __i0 + 1U) {
            event_info.ev_aux_data[__i0] = 0U;
        }
        event_info.ev_aux_data_size = 0U;

        get_event_info(&*event_list, i, &event_info);

        _Bool RIDenabled = 0;

        (self->pus_service_5.is_RID_enabled_ext)(self->pus_service_5.__that,
                                                 event_info.ev_RID,
                                                 &RIDenabled);

        if (RIDenabled) {
            
            size_t index = 0U;

            _Bool enabled = 0;

            if (PUSService19__get_event_action_config(self, event_info.ev_RID,
                                                      &index, &enabled)) {
                
                if (enabled) {
                    
                    RIDType RID_type = get_RID_type(event_info.ev_RID);

                    size_t tail_index = 0U;

                    if (RID_type.__variant == RIDType__RIDNotValid) {
                        

                    } else if (RID_type.__variant == RIDType__MediumSeverityAnomaly) {
                        
                        tail_index = (size_t)(self->pending_action_head[2U] + self->pending_action_number[2U]) % event_action_queue_dimension;

                        self->pending_action_queue_3MS[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[2U] = self->pending_action_number[2U] + 1U;

                    } else if (RID_type.__variant == RIDType__LowSeverityAnomaly) {
                        
                        tail_index = (size_t)(self->pending_action_head[1U] + self->pending_action_number[1U]) % event_action_queue_dimension;

                        self->pending_action_queue_2LS[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[1U] = self->pending_action_number[1U] + 1U;

                    } else if (RID_type.__variant == RIDType__Informative) {
                        
                        tail_index = (size_t)(self->pending_action_head[0U] + self->pending_action_number[0U]) % event_action_queue_dimension;

                        self->pending_action_queue_1I[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[0U] = self->pending_action_number[0U] + 1U;

                    } else {
                        
                        tail_index = (size_t)(self->pending_action_head[3U] + self->pending_action_number[3U]) % event_action_queue_dimension;

                        self->pending_action_queue_4HS[tail_index] = self->event_action_packets[index];

                        self->pending_action_number[3U] = self->pending_action_number[3U] + 1U;

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
