
#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

_Bool is_crc_valid(const TCDescriptorT * const tc_descriptor) {
    
    #line 43 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t cal_crc_value = cal_crc_16(tc_descriptor->tc_bytes,
                                        tc_descriptor->tc_num_bytes - 2U);

    #line 44 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    #line 46 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool is_valid = cal_crc_value == packet_error_ctrl;

    #line 48 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return is_valid;

}

_Bool is_apid_valid(const TCDescriptorT * const tc_descriptor) {
    
    #line 54 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t epd_apid = 0x32CU;

    #line 55 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t tc_apid = get_APID(tc_descriptor->tc_bytes);

    #line 57 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool is_valid = epd_apid == tc_apid;

    #line 59 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return is_valid;

}

_Bool is_sourceID_valid(const TCDescriptorT * const tc_descriptor) {
    
    #line 65 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t Mission_TimeLine_SourceID = 110U;

    #line 66 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t TC_Sequences_SourceID = 111U;

    #line 67 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t Direct_Commands_SourceID = 120U;

    #line 69 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    #line 71 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool is_valid = Mission_TimeLine_SourceID == sourceID || TC_Sequences_SourceID == sourceID || Direct_Commands_SourceID == sourceID;

    #line 75 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return is_valid;

}

uint8_t get_failure_subtype(TCVerifyStage verify_stage) {
    
    #line 82 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = 0U;

    #line 85 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if (verify_stage.__variant == TCVerifyStage__Acceptation) {
        
        #line 86 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 2U;

    } else
    #line 88 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if (verify_stage.__variant == TCVerifyStage__ExecStart) {
        
        #line 89 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 4U;

    } else
    #line 91 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if (verify_stage.__variant == TCVerifyStage__Progress) {
        
        #line 92 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 6U;

    } else
    {
        
        #line 95 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 8U;

    }

    #line 99 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return subtype;

}

void build_tm_1_X_no_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, MissionObt current_obt,
                                  MyResult * const result) {
    
    #line 106 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 108 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 109 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    #line 110 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    #line 111 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, result);

    #line 112 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 114 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
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
    
    #line 121 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 123 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 124 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    #line 125 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    #line 126 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, result);

    #line 127 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_data, result);

    #line 128 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 130 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
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
    
    #line 138 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 140 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 141 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    #line 142 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    #line 143 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, result);

    #line 144 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, failure_data, result);

    #line 145 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 147 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
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
    
    #line 155 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 157 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 158 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    #line 159 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    #line 160 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, result);

    #line 161 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u32_appdata_field(p_tm_handler, failure_data, result);

    #line 162 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 164 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
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
    
    #line 171 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 173 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 174 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

    #line 175 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

    #line 176 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, result);

    #line 177 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_data1, result);

    #line 178 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u32_appdata_field(p_tm_handler, failure_data2, result);

    #line 179 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 181 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return;

}
