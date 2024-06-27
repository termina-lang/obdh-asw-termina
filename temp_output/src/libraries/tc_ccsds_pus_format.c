
#include "libraries/tc_ccsds_pus_format.h"

uint16_t get_packet_id(const uint8_t tc_bytes[max_tc_size]) {
    
    uint16_t packet_id = 0;

    packet_id = deserialize_uint16(&tc_bytes[0]);

    return packet_id;

}

uint16_t get_APID(const uint8_t tc_bytes[max_tc_size]) {
    
    uint16_t packet_id = get_packet_id(tc_bytes);

    return packet_id & 0x7FF;

}

uint16_t get_seq_flags(uint16_t packet_seq_ctrl) {
    
    return packet_seq_ctrl >> 14;

}

uint16_t get_seq_count(uint16_t packet_seq_ctrl) {
    
    return packet_seq_ctrl & 0x3FFF;

}

uint16_t get_packet_length(const uint8_t tc_bytes[max_tc_size]) {
    
    return deserialize_uint16(&tc_bytes[4]);

}

uint16_t get_packet_seq_ctrl(const uint8_t tc_bytes[max_tc_size]) {
    
    uint16_t packet_error_ctrl = 0;

    uint16_t crc_offset = get_packet_length(tc_bytes) + 5;

    packet_error_ctrl = deserialize_uint16(&tc_bytes[(size_t)crc_offset]);

    return packet_error_ctrl;

}

uint8_t get_ack(uint8_t flag_ver_ack) {
    
    return flag_ver_ack & 0xF;

}

uint8_t get_type(const uint8_t tc_bytes[max_tc_size]) {
    
    uint8_t type = tc_bytes[7];

    return type;

}

uint8_t get_subtype(const uint8_t tc_bytes[max_tc_size]) {
    
    uint8_t subtype = tc_bytes[8];

    return subtype;

}

uint8_t get_source_id(const uint8_t tc_bytes[max_tc_size]) {
    
    uint8_t sourceID = tc_bytes[9];

    return sourceID;

}

void tc_get_fields(const uint8_t tc_bytes[max_tc_size],
                   CCSDSPUSTCPacketHeaderT * p_tc_packet_header,
                   CCSDSPUSTCDFHeaderT * p_tc_df_header,
                   uint16_t * p_tc_packet_err_ctrl) {
    
    p_tc_packet_header->packet_id = deserialize_uint16(&tc_bytes[0]);

    p_tc_packet_header->packet_seq_ctrl = deserialize_uint16(&tc_bytes[2]);

    p_tc_packet_header->packet_length = deserialize_uint16(&tc_bytes[4]);

    p_tc_df_header->flag_ver_ack = tc_bytes[6];

    p_tc_df_header->type = tc_bytes[7];

    p_tc_df_header->subtype = tc_bytes[8];

    p_tc_df_header->sourceID = tc_bytes[9];

    uint8_t packet_error_ctrl[2];
    for (size_t __i0 = 0; __i0 < 2; __i0 = __i0 + 1) {
        packet_error_ctrl[__i0] = 0;
    }

    packet_error_ctrl[0] = tc_bytes[(size_t)((*p_tc_packet_header).packet_length + 5)];

    packet_error_ctrl[1] = tc_bytes[(size_t)((*p_tc_packet_header).packet_length + 6)];

    *p_tc_packet_err_ctrl = deserialize_uint16(packet_error_ctrl);

    return;

}
