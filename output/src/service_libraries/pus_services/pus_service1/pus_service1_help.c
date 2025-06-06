
#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

const uint8_t ACCEPT_ACK_ENABLED_MASK = 0x1U;

const uint8_t EXEC_START_ACK_ENABLED_MASK = 0x2U;

const uint8_t EXEC_PROGRESS_ACK_ENABLED_MASK = 0x4U;

const uint8_t EXEC_COMPLETION_ACK_ENABLED_MASK = 0x8U;

_Bool is_crc_valid(const TCDescriptorT * const tc_descriptor) {
    
    #line 85 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t cal_crc_value = cal_crc_16(tc_descriptor->tc_bytes,
                                        tc_descriptor->tc_num_bytes - 2U);

    #line 86 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    #line 88 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool is_valid = cal_crc_value == packet_error_ctrl;

    #line 90 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return is_valid;

}

_Bool is_apid_valid(const TCDescriptorT * const tc_descriptor) {
    
    #line 101 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t epd_apid = 0x32CU;

    #line 102 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t tc_apid = get_APID(tc_descriptor->tc_bytes);

    #line 104 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool is_valid = epd_apid == tc_apid;

    #line 106 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return is_valid;

}

_Bool is_sourceID_valid(const TCDescriptorT * const tc_descriptor) {
    
    #line 117 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t System_SourceID = 0x78U;

    #line 119 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint16_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    #line 121 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool is_valid = System_SourceID == sourceID;

    #line 123 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return is_valid;

}

_Bool is_tc_ack_accept_enabled(uint8_t flags_ack) {
    
    #line 134 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool ack_enabled = 0;

    #line 136 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if ((uint8_t)(flags_ack & ACCEPT_ACK_ENABLED_MASK) != 0U) {
        
        #line 137 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        ack_enabled = 1;

    }

    #line 139 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return ack_enabled;

}

_Bool is_tc_ack_start_exec_enabled(uint8_t flags_ack) {
    
    #line 152 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool ack_enabled = 0;

    #line 154 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if ((uint8_t)(flags_ack & EXEC_START_ACK_ENABLED_MASK) != 0U) {
        
        #line 155 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        ack_enabled = 1;

    }

    #line 157 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return ack_enabled;

}

_Bool is_tc_ack_progress_exec_enabled(uint8_t flags_ack) {
    
    #line 169 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool ack_enabled = 0;

    #line 171 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if ((uint8_t)(flags_ack & EXEC_PROGRESS_ACK_ENABLED_MASK) != 0U) {
        
        #line 172 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        ack_enabled = 1;

    }

    #line 174 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return ack_enabled;

}

_Bool is_tc_ack_completion_exec_enabled(uint8_t flags_ack) {
    
    #line 186 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    _Bool ack_enabled = 0;

    #line 188 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if ((uint8_t)(flags_ack & EXEC_COMPLETION_ACK_ENABLED_MASK) != 0U) {
        
        #line 189 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        ack_enabled = 1;

    }

    #line 191 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return ack_enabled;

}

uint8_t get_failure_subtype(TCVerifyStage verify_stage) {
    
    #line 203 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = 0U;

    #line 206 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if (verify_stage.__variant == TCVerifyStage__Acceptation) {
        
        #line 207 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 2U;

    } else
    #line 209 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if (verify_stage.__variant == TCVerifyStage__ExecStart) {
        
        #line 210 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 4U;

    } else
    #line 212 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    if (verify_stage.__variant == TCVerifyStage__Progress) {
        
        #line 213 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 6U;

    } else
    {
        
        #line 216 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
        subtype = 8U;

    }

    #line 220 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return subtype;

}

void build_tm_1_X_no_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, MissionObt current_obt,
                                  __status_int32_t * const status) {
    
    #line 239 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 241 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 242 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, status);

    #line 243 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, status);

    #line 244 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, status);

    #line 245 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 247 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return;

}

void build_tm_1_X_u8_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, uint8_t failure_data,
                                  MissionObt current_obt,
                                  __status_int32_t * const status) {
    
    #line 258 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 260 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 261 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, status);

    #line 262 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, status);

    #line 263 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, status);

    #line 264 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_data, status);

    #line 265 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 267 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return;

}

void build_tm_1_X_u16_failure_data(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   TCVerifyStage verify_stage,
                                   uint8_t failure_code, uint16_t failure_data,
                                   MissionObt current_obt,
                                   __status_int32_t * const status) {
    
    #line 278 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 280 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 281 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, status);

    #line 282 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, status);

    #line 283 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, status);

    #line 284 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, failure_data, status);

    #line 285 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 287 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return;

}

void build_tm_1_X_u32_failure_data(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   TCVerifyStage verify_stage,
                                   uint8_t failure_code, uint32_t failure_data,
                                   MissionObt current_obt,
                                   __status_int32_t * const status) {
    
    #line 298 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 300 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 301 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, status);

    #line 302 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, status);

    #line 303 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, status);

    #line 304 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u32_appdata_field(p_tm_handler, failure_data, status);

    #line 305 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 307 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
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
                                      __status_int32_t * const status) {
    
    #line 320 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 322 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    startup_tm(p_tm_handler);

    #line 323 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_id, status);

    #line 324 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, status);

    #line 325 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_code, status);

    #line 326 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u8_appdata_field(p_tm_handler, failure_data1, status);

    #line 327 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    append_u32_appdata_field(p_tm_handler, failure_data2, status);

    #line 328 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    #line 330 "src/service_libraries/pus_services/pus_service1/pus_service1_help.fin"
    return;

}
