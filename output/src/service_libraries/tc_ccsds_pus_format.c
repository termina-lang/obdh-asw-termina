
#include "service_libraries/tc_ccsds_pus_format.h"

uint16_t get_packet_id(const uint8_t tc_bytes[256U]) {
    
    uint16_t packet_id = 0U;

    packet_id = deserialize_uint16(&tc_bytes[0U]);

    return packet_id;

}

uint16_t get_APID(const uint8_t tc_bytes[256U]) {
    
    uint16_t packet_id = get_packet_id(tc_bytes);

    return packet_id & 0x7FFU;

}

uint16_t get_seq_flags(uint16_t packet_seq_ctrl) {
    
    return packet_seq_ctrl >> 14U;

}

uint16_t get_seq_count(uint16_t packet_seq_ctrl) {
    
    return packet_seq_ctrl & 0x3FFFU;

}

uint16_t get_packet_length(const uint8_t tc_bytes[256U]) {
    
    return deserialize_uint16(&tc_bytes[4U]);

}

uint16_t get_packet_seq_ctrl(const uint8_t tc_bytes[256U]) {
    
    uint16_t packet_error_ctrl = 0U;

    uint16_t crc_offset = get_packet_length(tc_bytes) + 5U;

    packet_error_ctrl = deserialize_uint16(&tc_bytes[__termina_array__slice(256U,
                                                                            2U,
                                                                            (size_t)crc_offset,
                                                                            (size_t)(crc_offset + 2U))]);

    return packet_error_ctrl;

}

uint8_t get_ack(uint8_t flag_ver_ack) {
    
    return flag_ver_ack & 0xFU;

}

uint8_t get_type(const uint8_t tc_bytes[256U]) {
    
    uint8_t type = tc_bytes[7U];

    return type;

}

uint8_t get_subtype(const uint8_t tc_bytes[256U]) {
    
    uint8_t subtype = tc_bytes[8U];

    return subtype;

}

uint8_t get_source_id(const uint8_t tc_bytes[256U]) {
    
    uint8_t sourceID = tc_bytes[9U];

    return sourceID;

}

void tc_get_fields(const uint8_t tc_bytes[256U],
                   CCSDSPUSTCPacketHeaderT * const p_tc_packet_header,
                   CCSDSPUSTCDFHeaderT * const p_tc_df_header,
                   uint16_t * const p_tc_packet_err_ctrl) {
    
    p_tc_packet_header->packet_id = deserialize_uint16(&tc_bytes[0U]);

    p_tc_packet_header->packet_seq_ctrl = deserialize_uint16(&tc_bytes[2U]);

    p_tc_packet_header->packet_length = deserialize_uint16(&tc_bytes[4U]);

    p_tc_df_header->flag_ver_ack = tc_bytes[6U];

    p_tc_df_header->type = tc_bytes[7U];

    p_tc_df_header->subtype = tc_bytes[8U];

    p_tc_df_header->sourceID = deserialize_uint16(&tc_bytes[9U]);

    uint8_t packet_error_ctrl[2U];
    for (size_t __i0 = 0U; __i0 < 2U; __i0 = __i0 + 1U) {
        packet_error_ctrl[__i0] = 0U;
    }

    packet_error_ctrl[0U] = tc_bytes[__termina_array__index(256U,
                                                            (size_t)((*p_tc_packet_header).packet_length + 5U))];

    packet_error_ctrl[1U] = tc_bytes[__termina_array__index(256U,
                                                            (size_t)((*p_tc_packet_header).packet_length + 6U))];

    *p_tc_packet_err_ctrl = deserialize_uint16(packet_error_ctrl);

    return;

}
