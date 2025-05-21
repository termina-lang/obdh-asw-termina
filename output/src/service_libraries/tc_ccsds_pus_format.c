
#include "service_libraries/tc_ccsds_pus_format.h"

uint16_t get_packet_id(const uint8_t tc_bytes[256U]) {
    
    #line 35 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint16_t packet_id = 0U;

    #line 36 "src/service_libraries/tc_ccsds_pus_format.fin"
    packet_id = deserialize_uint16(&tc_bytes[0U]);

    #line 37 "src/service_libraries/tc_ccsds_pus_format.fin"
    return packet_id;

}

uint16_t get_APID(const uint8_t tc_bytes[256U]) {
    
    #line 45 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint16_t packet_id = get_packet_id(tc_bytes);

    #line 47 "src/service_libraries/tc_ccsds_pus_format.fin"
    return packet_id & 0x7FFU;

}

uint16_t get_seq_flags(uint16_t packet_seq_ctrl) {
    
    #line 54 "src/service_libraries/tc_ccsds_pus_format.fin"
    return packet_seq_ctrl >> 14U;

}

uint16_t get_seq_count(uint16_t packet_seq_ctrl) {
    
    #line 61 "src/service_libraries/tc_ccsds_pus_format.fin"
    return packet_seq_ctrl & 0x3FFFU;

}

uint16_t get_packet_length(const uint8_t tc_bytes[256U]) {
    
    #line 66 "src/service_libraries/tc_ccsds_pus_format.fin"
    return deserialize_uint16(&tc_bytes[4U]);

}

uint16_t get_packet_seq_ctrl(const uint8_t tc_bytes[256U]) {
    
    #line 71 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint16_t packet_error_ctrl = 0U;

    #line 72 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint16_t crc_offset = get_packet_length(tc_bytes) + 5U;

    #line 73 "src/service_libraries/tc_ccsds_pus_format.fin"
    packet_error_ctrl = deserialize_uint16(&tc_bytes[__termina_array__slice(256U,
                                                                            2U,
                                                                            (size_t)crc_offset,
                                                                            (size_t)(crc_offset + 2U))]);

    #line 75 "src/service_libraries/tc_ccsds_pus_format.fin"
    return packet_error_ctrl;

}

uint8_t get_ack(uint8_t flag_ver_ack) {
    
    #line 81 "src/service_libraries/tc_ccsds_pus_format.fin"
    return flag_ver_ack & 0xFU;

}

uint8_t get_type(const uint8_t tc_bytes[256U]) {
    
    #line 86 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint8_t type = tc_bytes[7U];

    #line 87 "src/service_libraries/tc_ccsds_pus_format.fin"
    return type;

}

uint8_t get_subtype(const uint8_t tc_bytes[256U]) {
    
    #line 92 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint8_t subtype = tc_bytes[8U];

    #line 93 "src/service_libraries/tc_ccsds_pus_format.fin"
    return subtype;

}

uint16_t get_source_id(const uint8_t tc_bytes[256U]) {
    
    #line 98 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint16_t sourceID = deserialize_uint16(&tc_bytes[9U]);

    #line 99 "src/service_libraries/tc_ccsds_pus_format.fin"
    return sourceID;

}

void tc_get_fields(const uint8_t tc_bytes[256U],
                   CCSDSPUSTCPacketHeaderT * const p_tc_packet_header,
                   CCSDSPUSTCDFHeaderT * const p_tc_df_header,
                   uint16_t * const p_tc_packet_err_ctrl) {
    
    #line 109 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_packet_header->packet_id = deserialize_uint16(&tc_bytes[0U]);

    #line 112 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_packet_header->packet_seq_ctrl = deserialize_uint16(&tc_bytes[2U]);

    #line 115 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_packet_header->packet_length = deserialize_uint16(&tc_bytes[4U]);

    #line 118 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_df_header->flag_ver_ack = tc_bytes[6U];

    #line 121 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_df_header->type = tc_bytes[7U];

    #line 122 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_df_header->subtype = tc_bytes[8U];

    #line 123 "src/service_libraries/tc_ccsds_pus_format.fin"
    p_tc_df_header->sourceID = deserialize_uint16(&tc_bytes[9U]);

    #line 127 "src/service_libraries/tc_ccsds_pus_format.fin"
    uint8_t packet_error_ctrl[2U];
    #line 127 "src/service_libraries/tc_ccsds_pus_format.fin"
    for (size_t __i0 = 0U; __i0 < 2U; __i0 = __i0 + 1U) {
        #line 127 "src/service_libraries/tc_ccsds_pus_format.fin"
        packet_error_ctrl[__i0] = 0U;
    }

    #line 128 "src/service_libraries/tc_ccsds_pus_format.fin"
    packet_error_ctrl[0U] = tc_bytes[__termina_array__index(256U,
                                                            (size_t)((*p_tc_packet_header).packet_length + 5U))];

    #line 129 "src/service_libraries/tc_ccsds_pus_format.fin"
    packet_error_ctrl[1U] = tc_bytes[__termina_array__index(256U,
                                                            (size_t)((*p_tc_packet_header).packet_length + 6U))];

    #line 131 "src/service_libraries/tc_ccsds_pus_format.fin"
    *p_tc_packet_err_ctrl = deserialize_uint16(packet_error_ctrl);

    #line 133 "src/service_libraries/tc_ccsds_pus_format.fin"
    return;

}
