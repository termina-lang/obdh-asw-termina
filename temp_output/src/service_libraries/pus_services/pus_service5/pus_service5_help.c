
#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

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
