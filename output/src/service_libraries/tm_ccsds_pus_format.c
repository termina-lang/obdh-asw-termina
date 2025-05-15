
#include "service_libraries/tm_ccsds_pus_format.h"

uint16_t ccsds_pus_tm_build_packet_id(uint16_t apid) {
    
    return (uint16_t)(1U << 11U) | (uint16_t)(apid & 0x7FFU);

}

uint16_t ccsds_pus_tm_build_packet_seq_ctrl(uint16_t sequence_flags,
                                            uint16_t tm_count) {
    
    return (uint16_t)(sequence_flags << 14U) | tm_count;

}

uint32_t ccsds_pus_tm_build_df_header(uint8_t service_type,
                                      uint8_t service_subtype,
                                      uint8_t destinationID) {
    
    return (uint32_t)((uint32_t)((uint32_t)(0x10U << 24U) | (uint32_t)((uint32_t)service_type << 16U)) | (uint32_t)((uint32_t)service_subtype << 8U)) | (uint32_t)destinationID;

}

uint8_t ccsds_pus_tm_build_df_header_version(uint8_t version) {
    
    return (uint8_t)(version & 0x7U) << 4U;

}

void ccsds_pus_tm_set_fields(uint8_t tm_bytes[10U],
                             const CCSDSPUSTMPacketHeaderT * const p_tm_packet_header,
                             const CCSDSPUSTMDFHeaderT * const p_tm_df_header) {
    
    serialize_uint16(p_tm_packet_header->packet_id, &tm_bytes[0U]);

    serialize_uint16(p_tm_packet_header->packet_seq_ctrl, &tm_bytes[2U]);

    serialize_uint16(p_tm_packet_header->packet_length, &tm_bytes[4U]);

    tm_bytes[6U] = p_tm_df_header->version;

    tm_bytes[7U] = p_tm_df_header->type;

    tm_bytes[8U] = p_tm_df_header->subtype;

    serialize_uint16(p_tm_df_header->msg_type_counter, &tm_bytes[9U]);

    serialize_uint16(p_tm_df_header->destinationID, &tm_bytes[11U]);

    serialize_uint32(p_tm_df_header->obt_secs, &tm_bytes[13U]);

    serialize_uint16(p_tm_df_header->obt_finetime, &tm_bytes[17U]);

    return;

}
