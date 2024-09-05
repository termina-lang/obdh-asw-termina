
#include "libraries/pus_services/pus_service19.h"

_Bool get_event_action_config(uint16_t evID, size_t * index, _Bool * enabled,
                              const EventActionConfig event_action_config_table[max_event_action_definitions]) {
    
    _Bool found = 0;

    for (size_t i = 0; i < max_event_action_definitions && found == 0; i = i + 1) {
        
        if (event_action_config_table[i].event_ID == evID) {
            
            *index = i;

            *enabled = event_action_config_table[i].enabled;

            found = 1;

        }

    }

    return found;

}

_Bool get_free_event_action_index(size_t * index,
                                  const EventActionConfig event_action_config_table[max_event_action_definitions]) {
    
    _Bool found = 0;

    for (size_t i = 0; i < max_event_action_definitions && found == 0; i = i + 1) {
        
        if (event_action_config_table[i].event_ID == 0) {
            
            *index = i;

            found = 1;

        }

    }

    return found;

}

void exec19_1TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions],
                TCDescriptorT event_action_packs[max_event_action_definitions]) {
    
    size_t index = 0;

    _Bool found = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (get_event_action_config(evID, &index, &enabled,
                                    event_action_config_table)) {
            
            found = 1;

        } else if (get_free_event_action_index(&index,
                                               event_action_config_table)) {
            
            found = 1;

            enabled = 0;

        } else {
            
            build_tm_1_8_tc_19_1_max_event_actions(tm_descriptor,
                                                   tm_seq_counter, evID,
                                                   tc_descriptor);

        }

        if (found) {
            
            if (enabled) {
                
                build_tm_1_8_tc_19_X_event_action_enabled(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

            } else {
                
                size_t action_packet_length = (size_t)get_packet_length(tc_descriptor->tc_bytes) - 7;

                for (size_t i = 0; i < event_action_max_bytes && i < action_packet_length; i = i + 1) {
                    
                    event_action_packs[index].tc_bytes[i] = tc_descriptor->tc_bytes[i + 12];

                }

                event_action_packs[index].tc_num_bytes = action_packet_length;

                TCStatus tc_status;
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;
                tc_status.error_code.__variant = TCErrorType__CRCError;
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

                try_tc_acceptation(&tc_status, &event_action_packs[index]);

                if (tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
                    
                    event_action_config_table[index].event_ID = evID;

                    event_action_config_table[index].enabled = 0;

                    build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

                } else {
                    
                    build_tm_1_8_tc_19_1_event_action_rejected(tm_descriptor,
                                                               tm_seq_counter,
                                                               evID,
                                                               tc_descriptor);

                }

            }

        }

    }

    return;

}

void exec19_2TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions]) {
    
    size_t index = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (get_event_action_config(evID, &index, &enabled,
                                    event_action_config_table)) {
            
            if (enabled) {
                
                build_tm_1_8_tc_19_X_event_action_enabled(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

            } else {
                
                event_action_config_table[index].event_ID = 0;

                event_action_config_table[index].enabled = 0;

                build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

            }

        } else {
            
            build_tm_1_8_tc_19_X_event_action_not_defined(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

        }

    }

    return;

}

void exec19_4TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions]) {
    
    size_t index = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (get_event_action_config(evID, &index, &enabled,
                                    event_action_config_table)) {
            
            event_action_config_table[index].enabled = 1;

            build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

        } else {
            
            build_tm_1_8_tc_19_X_event_action_not_defined(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

        }

    }

    return;

}

void exec19_5TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions]) {
    
    size_t index = 0;

    _Bool enabled = 0;

    uint16_t evID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    RIDType event_type = get_RID_type(evID);

    if (event_type.__variant == RIDType__RIDNotValid) {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, evID,
                                       tc_descriptor);

    } else {
        
        if (get_event_action_config(evID, &index, &enabled,
                                    event_action_config_table)) {
            
            event_action_config_table[index].enabled = 1;

            build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

        } else {
            
            build_tm_1_8_tc_19_X_event_action_not_defined(tm_descriptor,
                                                          tm_seq_counter, evID,
                                                          tc_descriptor);

        }

    }

    return;

}

void PUS_service_19_execTC(const TCDescriptorT * tc_descriptor,
                           TMDescriptorT * tm_descriptor,
                           uint16_t tm_seq_counter,
                           EventActionConfig event_action_config_table[max_event_action_definitions],
                           TCDescriptorT event_action_packs[max_event_action_definitions]) {
    
    uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

    if (subtype == 1) {
        
        exec19_1TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   event_action_config_table, event_action_packs);

    } else if (subtype == 2) {
        
        exec19_2TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   event_action_config_table);

    } else if (subtype == 4) {
        
        exec19_4TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   event_action_config_table);

    } else if (subtype == 5) {
        
        exec19_5TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   event_action_config_table);

    } else {
        

    }

    return;

}
