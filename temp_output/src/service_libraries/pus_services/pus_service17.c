
#include "service_libraries/pus_services/pus_service17.h"

void build_tm_17_2(TMDescriptorT * const tm_descriptor,
                   uint16_t tm_seq_counter) {
    
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

    tm_packet_header.packet_length = 3;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 17;

    df_header.subtype = 2;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    tm_descriptor->tm_num_bytes = (size_t)tm_packet_header.packet_length + 7;

    return;

}

void PUS_service_17_execTC(const TCDescriptorT * const tc_descriptor,
                           TMDescriptorT * const tm_descriptor,
                           uint16_t tm_seq_counter) {
    
    uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

    if (subtype == 1) {
        
        build_tm_17_2(tm_descriptor, tm_seq_counter);

    }

    return;

}
