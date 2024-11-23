
#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

_Bool is_crc_valid(const TCDescriptorT * const tc_descriptor) {
    
    uint16_t cal_crc_value = cal_crc_16(tc_descriptor->tc_bytes,
                                        tc_descriptor->tc_num_bytes - 2);

    uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    _Bool is_valid = cal_crc_value == packet_error_ctrl;

    return is_valid;

}

_Bool is_apid_valid(const TCDescriptorT * const tc_descriptor) {
    
    uint16_t epd_apid = 0x32C;

    uint16_t tc_apid = get_APID(tc_descriptor->tc_bytes);

    _Bool is_valid = epd_apid == tc_apid;

    return is_valid;

}

_Bool is_sourceID_valid(const TCDescriptorT * const tc_descriptor) {
    
    uint8_t Mission_TimeLine_SourceID = 110;

    uint8_t TC_Sequences_SourceID = 111;

    uint8_t Direct_Commands_SourceID = 120;

    uint8_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    _Bool is_valid = Mission_TimeLine_SourceID == sourceID || TC_Sequences_SourceID == sourceID || Direct_Commands_SourceID == sourceID;

    return is_valid;

}

void build_tm(TMDescriptorT * const p_tm_descriptor, uint16_t tm_seq_counter,
              const TCDescriptorT * const tc_descriptor, uint16_t tm_plength,
              uint8_t tm_type, uint8_t tm_subtype) {
    
    CCSDSPUSTMPacketHeaderT tm_packet_header;
    tm_packet_header.packet_id = 0;
    tm_packet_header.packet_length = 0;
    tm_packet_header.packet_seq_ctrl = 0;

    CCSDSPUSTMDFHeaderT df_header;
    df_header.destinationID = 0;
    df_header.subtype = 0;
    df_header.type = 0;
    df_header.version = 0;

    uint16_t tc_packet_id = get_packet_id(tc_descriptor->tc_bytes);

    uint16_t tc_packet_seq_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    tm_packet_header.packet_id = ccsds_pus_tm_build_packet_id(0x32C);

    tm_packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3,
                                                                          tm_seq_counter);

    tm_packet_header.packet_length = tm_plength;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = tm_type;

    df_header.subtype = tm_subtype;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    p_tm_descriptor->tm_num_bytes = (size_t)tm_packet_header.packet_length + 7;

    return;

}
