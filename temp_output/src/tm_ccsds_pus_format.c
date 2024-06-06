
#include "tm_ccsds_pus_format.h"

uint16_t ccsds_pus_tm_build_packet_id(uint16_t apid) {
    
    return (uint16_t)(1 << 11) | (uint16_t)(apid & 0x7FF);

}

uint16_t ccsds_pus_tm_build_packet_seq_ctrl(uint16_t sequence_flags,
                                            uint16_t tm_count) {
    
    return (uint16_t)(sequence_flags << 14) | tm_count;

}

uint32_t ccsds_pus_tm_build_df_header(uint8_t service_type,
                                      uint8_t service_subtype,
                                      uint8_t destinationID) {
    
    return (uint32_t)((uint32_t)((uint32_t)(0x10 << 24) | (uint32_t)((uint32_t)service_type << 16)) | (uint32_t)((uint32_t)service_subtype << 8)) | (uint32_t)destinationID;

}

uint8_t ccsds_pus_tm_build_df_header_version(uint8_t version) {
    
    return (uint8_t)(version & 0x7) << 4;

}

void ccsds_pus_tm_set_fields(uint8_t tm_bytes[10],
                             const CCSDSPUSTMTCPacketHeaderT * p_tm_packet_header,
                             const CCSDSPUSTMDFHeaderT * p_tm_df_header) {
    
    serialize_uint16(p_tm_packet_header->packet_id, &tm_bytes[0]);

    serialize_uint16(p_tm_packet_header->packet_seq_ctrl, &tm_bytes[2]);

    serialize_uint16(p_tm_packet_header->packet_length, &tm_bytes[4]);

    tm_bytes[6] = p_tm_df_header->version;

    tm_bytes[7] = p_tm_df_header->type;

    tm_bytes[8] = p_tm_df_header->subtype;

    tm_bytes[9] = p_tm_df_header->destinationID;

    return;

}
