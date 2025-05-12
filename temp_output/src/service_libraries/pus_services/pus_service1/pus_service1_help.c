
#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

_Bool is_crc_valid(const TCDescriptorT * const tc_descriptor) {
    
    uint16_t cal_crc_value = cal_crc_16(tc_descriptor->tc_bytes,
                                        tc_descriptor->tc_num_bytes - 2U);

    uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    _Bool is_valid = cal_crc_value == packet_error_ctrl;

    return is_valid;

}

_Bool is_apid_valid(const TCDescriptorT * const tc_descriptor) {
    
    uint16_t epd_apid = 0x32CU;

    uint16_t tc_apid = get_APID(tc_descriptor->tc_bytes);

    _Bool is_valid = epd_apid == tc_apid;

    return is_valid;

}

_Bool is_sourceID_valid(const TCDescriptorT * const tc_descriptor) {
    
    uint8_t Mission_TimeLine_SourceID = 110U;

    uint8_t TC_Sequences_SourceID = 111U;

    uint8_t Direct_Commands_SourceID = 120U;

    uint8_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    _Bool is_valid = Mission_TimeLine_SourceID == sourceID || TC_Sequences_SourceID == sourceID || Direct_Commands_SourceID == sourceID;

    return is_valid;

}

uint8_t get_failure_subtype(TCVerifyStage verify_stage) {
    
    uint8_t subtype = 0U;

    if (verify_stage.__variant == TCVerifyStage__Acceptation) {
        
        subtype = 2U;

    } else if (verify_stage.__variant == TCVerifyStage__ExecStart) {
        
        subtype = 4U;

    } else if (verify_stage.__variant == TCVerifyStage__Progress) {
        
        subtype = 6U;

    } else {
        
        subtype = 8U;

    }

    return subtype;

}

void build_tm_1_X_no_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, MissionObt current_obt,
                                  MyResult * const result) {
    
    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    append_u8_appdata_field(p_tm_handler, failure_code, result);

    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    return;

}

void build_tm_1_X_u8_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, uint8_t failure_data,
                                  MissionObt current_obt,
                                  MyResult * const result) {
    
    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    append_u8_appdata_field(p_tm_handler, failure_code, result);

    append_u8_appdata_field(p_tm_handler, failure_data, result);

    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    return;

}

void build_tm_1_X_u16_failure_data(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   TCVerifyStage verify_stage,
                                   uint8_t failure_code, uint16_t failure_data,
                                   MissionObt current_obt,
                                   MyResult * const result) {
    
    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    append_u8_appdata_field(p_tm_handler, failure_code, result);

    append_u16_appdata_field(p_tm_handler, failure_data, result);

    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    return;

}

void build_tm_1_X_u32_failure_data(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   TCVerifyStage verify_stage,
                                   uint8_t failure_code, uint32_t failure_data,
                                   MissionObt current_obt,
                                   MyResult * const result) {
    
    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    append_u8_appdata_field(p_tm_handler, failure_code, result);

    append_u32_appdata_field(p_tm_handler, failure_data, result);

    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    return;

}

void build_tm_1_X_u8_u32_failure_data(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      TCVerifyStage verify_stage,
                                      uint8_t failure_code,
                                      uint8_t failure_data1,
                                      uint32_t failure_data2,
                                      MissionObt current_obt,
                                      MyResult * const result) {
    
    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    append_u8_appdata_field(p_tm_handler, failure_code, result);

    append_u8_appdata_field(p_tm_handler, failure_data1, result);

    append_u32_appdata_field(p_tm_handler, failure_data2, result);

    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    return;

}
