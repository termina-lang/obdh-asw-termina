
#include "service_libraries/pus_services/pus_service5.h"

RIDType get_RID_type(uint16_t RID) {
    
    RIDType RID_type;
    RID_type.__variant = RIDType__RIDNotValid;

    uint16_t aux_type = RID >> 12;

    uint16_t aux_id = RID & 0xFFF;

    if (aux_type == 1) {
        
        if (aux_id < informative_RIDs) {
            
            RID_type.__variant = RIDType__Informative;

        } else {
            
            RID_type.__variant = RIDType__RIDNotValid;

        }

    } else if (aux_type == 2) {
        
        if (aux_id < low_severity_anomaly_RIDs) {
            
            RID_type.__variant = RIDType__LowSeverityAnomaly;

        } else {
            
            RID_type.__variant = RIDType__RIDNotValid;

        }

    } else if (aux_type == 3) {
        
        if (aux_id < medium_severity_anomaly_RIDs) {
            
            RID_type.__variant = RIDType__MediumSeverityAnomaly;

        } else {
            
            RID_type.__variant = RIDType__RIDNotValid;

        }

    } else if (aux_type == 4) {
        
        if (aux_id < high_severity_anomaly_RIDs) {
            
            RID_type.__variant = RIDType__HighSeverityAnomaly;

        } else {
            
            RID_type.__variant = RIDType__RIDNotValid;

        }

    } else {
        
        RID_type.__variant = RIDType__RIDNotValid;

    }

    return RID_type;

}

size_t get_RID_enable_config_index(uint16_t RID) {
    
    RIDType RID_type = get_RID_type(RID);

    size_t index = 4;

    if (RID_type.__variant == RIDType__RIDNotValid) {
        
        index = 4;

    } else if (RID_type.__variant == RIDType__MediumSeverityAnomaly) {
        
        index = 2;

    } else if (RID_type.__variant == RIDType__LowSeverityAnomaly) {
        
        index = 1;

    } else if (RID_type.__variant == RIDType__Informative) {
        
        index = 0;

    } else {
        
        index = 3;

    }

    return index;

}

uint8_t get_RID_enable_config_offset(uint16_t RID) {
    
    return (uint8_t)(RID & offset_mask);

}

void build_tm_5_x(TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter, const EventInfo * const event,
                  size_t index) {
    
    CCSDSPUSTMPacketHeaderT tm_packet_header;
    tm_packet_header.packet_id = 0;
    tm_packet_header.packet_length = 0;
    tm_packet_header.packet_seq_ctrl = 0;

    CCSDSPUSTMDFHeaderT df_header;
    df_header.destinationID = 0;
    df_header.subtype = 0;
    df_header.type = 0;
    df_header.version = 0;

    tm_packet_header.packet_id = ccsds_pus_tm_build_packet_id(0x32C);

    tm_packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3,
                                                                          tm_seq_counter);

    tm_packet_header.packet_length = 5 + (uint16_t)event->ev_aux_data_size;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 5;

    df_header.subtype = (uint8_t)(index + 1);

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(event->ev_RID, &p_tm_descriptor->tm_bytes[14]);

    for (size_t i = 0; i < event_aux_data_max_size && i < event->ev_aux_data_size; i = i + 1) {
        
        p_tm_descriptor->tm_bytes[16 + i] = event->ev_aux_data[i];

    }

    p_tm_descriptor->tm_num_bytes = (size_t)tm_packet_header.packet_length + 7;

    return;

}

_Bool PUSService5__is_RID_enabled(const PUSService5 * const self,
                                  uint16_t RID) {
    
    _Bool enabled = 0;

    size_t index = get_RID_enable_config_index(RID);

    uint8_t offset = get_RID_enable_config_offset(RID);

    if (index < 4) {
        
        if ((uint32_t)((uint32_t)(self->RID_enable_config[index] >> offset) & 0x1) != 0) {
            
            enabled = 1;

        }

    }

    return enabled;

}

void PUSService5__build_event_list_tms(void * const __this,
                                       EventList * const event_list,
                                       Result * const result) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0; i < max_num_events && i < event_list->num_events; i = i + 1) {
        
        EventInfo event_info;
        event_info.ev_RID = 0;
        for (size_t __i0 = 0; __i0 < event_aux_data_max_size; __i0 = __i0 + 1) {
            event_info.ev_aux_data[__i0] = 0;
        }
        event_info.ev_aux_data_size = 0;

        get_event_info(&*event_list, i, &event_info);

        if (PUSService5__is_RID_enabled(self, event_info.ev_RID)) {
            
            size_t index = get_RID_enable_config_index(event_info.ev_RID);

            if (index < 4) {
                
                __option_box_t tm_descriptor;
                tm_descriptor.__variant = None;

                __termina_pool__alloc(self->a_tm_descriptor_pool,
                                      &tm_descriptor);

                if (tm_descriptor.__variant == Some) {
                    
                    __termina_box_t descriptor = tm_descriptor.Some.__0;

                    uint16_t tm_count = 0;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count);

                    build_tm_5_x((TMDescriptorT *)descriptor.data, tm_count,
                                 &event_info, index);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               descriptor, result);

                } else {
                    
                    (*result).__variant = Result__Error;

                }

            }

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService5__exec5_5TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            TMDescriptorT * const tm_descriptor,
                            uint16_t tm_seq_counter) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    uint16_t RID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    size_t index = get_RID_enable_config_index(RID);

    uint8_t offset = get_RID_enable_config_offset(RID);

    if (index < 4) {
        
        self->RID_enable_config[index] = self->RID_enable_config[index] | (uint32_t)(1 << offset);

        build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

    } else {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, RID,
                                       tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService5__exec5_6TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            TMDescriptorT * const tm_descriptor,
                            uint16_t tm_seq_counter) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    uint16_t RID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    size_t index = get_RID_enable_config_index(RID);

    uint8_t offset = get_RID_enable_config_offset(RID);

    if (index < 4) {
        
        self->RID_enable_config[index] = self->RID_enable_config[index] & (uint32_t)(0xFFFFFFFE << offset);

        build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

    } else {
        
        build_tm_1_8_tc_5_X_RIDunknown(tm_descriptor, tm_seq_counter, RID,
                                       tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService5__is_RID_enabled_ext(void * const __this, uint16_t RID,
                                     _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    *p_enabled = PUSService5__is_RID_enabled(self, RID);

    __termina_resource__unlock(&self->__resource);

    return;

}
