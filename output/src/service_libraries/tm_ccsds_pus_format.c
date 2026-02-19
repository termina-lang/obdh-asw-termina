
#include "service_libraries/tm_ccsds_pus_format.h"

uint16_t ccsds_pus_tm_build_packet_id(uint16_t apid) {
    
    #line 46 "src/service_libraries/tm_ccsds_pus_format.fin"
    return 18432U | (uint16_t)(apid & 0x7FFU);

}

uint16_t ccsds_pus_tm_build_packet_seq_ctrl(uint16_t sequence_flags, uint16_t tm_count) {
    
    #line 60 "src/service_libraries/tm_ccsds_pus_format.fin"
    return (uint16_t)((uint16_t)(sequence_flags & 0x3U) << 14U) | (uint16_t)(tm_count & 0x3FFFU);

}

uint32_t ccsds_pus_tm_build_df_header(uint8_t service_type, uint8_t service_subtype, uint8_t destinationID) {
    
    #line 74 "src/service_libraries/tm_ccsds_pus_format.fin"
    return (uint32_t)((uint32_t)(0x10000000U | (uint32_t)((uint32_t)service_type << 16U)) | (uint32_t)((uint32_t)service_subtype << 8U)) | (uint32_t)destinationID;

}

uint8_t ccsds_pus_tm_build_df_header_version(uint8_t version) {
    
    #line 87 "src/service_libraries/tm_ccsds_pus_format.fin"
    return (uint8_t)(version & 0xFU) << 4U;

}

void ccsds_pus_tm_set_fields(uint8_t tm_bytes[10U], const CCSDSPUSTMPacketHeader * const p_tm_packet_header, const CCSDSPUSTMDFHeader * const p_tm_df_header) {
    
    #line 103 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint16(p_tm_packet_header->packet_id, &tm_bytes[0U]);

    #line 106 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint16(p_tm_packet_header->packet_seq_ctrl, &tm_bytes[2U]);

    #line 109 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint16(p_tm_packet_header->packet_length, &tm_bytes[4U]);

    #line 112 "src/service_libraries/tm_ccsds_pus_format.fin"
    tm_bytes[6U] = p_tm_df_header->version;

    #line 115 "src/service_libraries/tm_ccsds_pus_format.fin"
    tm_bytes[7U] = p_tm_df_header->type;

    #line 118 "src/service_libraries/tm_ccsds_pus_format.fin"
    tm_bytes[8U] = p_tm_df_header->subtype;

    #line 121 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint16(p_tm_df_header->msg_type_counter, &tm_bytes[9U]);

    #line 124 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint16(p_tm_df_header->destinationID, &tm_bytes[11U]);

    #line 127 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint32(p_tm_df_header->obt_secs, &tm_bytes[13U]);

    #line 130 "src/service_libraries/tm_ccsds_pus_format.fin"
    serialize_uint16(p_tm_df_header->obt_finetime, &tm_bytes[17U]);

    #line 132 "src/service_libraries/tm_ccsds_pus_format.fin"
    return;

}
