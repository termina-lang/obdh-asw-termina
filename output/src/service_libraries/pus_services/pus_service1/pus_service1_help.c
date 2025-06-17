
#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

const uint8_t ACCEPT_ACK_ENABLED_MASK = 0x1U;

const uint8_t EXEC_START_ACK_ENABLED_MASK = 0x2U;

const uint8_t EXEC_PROGRESS_ACK_ENABLED_MASK = 0x4U;

const uint8_t EXEC_COMPLETION_ACK_ENABLED_MASK = 0x8U;

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
    
    uint16_t System_SourceID = 0x78U;

    uint16_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    _Bool is_valid = System_SourceID == sourceID;

    return is_valid;

}

_Bool is_tc_ack_accept_enabled(uint8_t flags_ack) {
    
    _Bool ack_enabled = 0;

    if ((uint8_t)(flags_ack & ACCEPT_ACK_ENABLED_MASK) != 0U) {
        
        ack_enabled = 1;

    }

    return ack_enabled;

}

_Bool is_tc_ack_start_exec_enabled(uint8_t flags_ack) {
    
    _Bool ack_enabled = 0;

    if ((uint8_t)(flags_ack & EXEC_START_ACK_ENABLED_MASK) != 0U) {
        
        ack_enabled = 1;

    }

    return ack_enabled;

}

_Bool is_tc_ack_progress_exec_enabled(uint8_t flags_ack) {
    
    _Bool ack_enabled = 0;

    if ((uint8_t)(flags_ack & EXEC_PROGRESS_ACK_ENABLED_MASK) != 0U) {
        
        ack_enabled = 1;

    }

    return ack_enabled;

}

_Bool is_tc_ack_completion_exec_enabled(uint8_t flags_ack) {
    
    _Bool ack_enabled = 0;

    if ((uint8_t)(flags_ack & EXEC_COMPLETION_ACK_ENABLED_MASK) != 0U) {
        
        ack_enabled = 1;

    }

    return ack_enabled;

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

__status_int32_t build_tm_1_X_no_failure_data(TMHandlerT * const p_tm_handler,
                                              uint16_t tm_seq_counter,
                                              uint16_t tc_packet_id,
                                              uint16_t tc_packet_seq_ctrl,
                                              TCVerifyStage verify_stage,
                                              uint8_t failure_code,
                                              MissionObt current_obt) {
    
    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    if (status.__variant == Success) {
        
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    return status;

}

__status_int32_t build_tm_1_X_u8_failure_data(TMHandlerT * const p_tm_handler,
                                              uint16_t tm_seq_counter,
                                              uint16_t tc_packet_id,
                                              uint16_t tc_packet_seq_ctrl,
                                              TCVerifyStage verify_stage,
                                              uint8_t failure_code,
                                              uint8_t failure_data,
                                              MissionObt current_obt) {
    
    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_data);

    }

    if (status.__variant == Success) {
        
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    return status;

}

__status_int32_t build_tm_1_X_u16_failure_data(TMHandlerT * const p_tm_handler,
                                               uint16_t tm_seq_counter,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               TCVerifyStage verify_stage,
                                               uint8_t failure_code,
                                               uint16_t failure_data,
                                               MissionObt current_obt) {
    
    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler, failure_data);

    }

    if (status.__variant == Success) {
        
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    return status;

}

__status_int32_t build_tm_1_X_u32_failure_data(TMHandlerT * const p_tm_handler,
                                               uint16_t tm_seq_counter,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               TCVerifyStage verify_stage,
                                               uint8_t failure_code,
                                               uint32_t failure_data,
                                               MissionObt current_obt) {
    
    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler, failure_data);

    }

    if (status.__variant == Success) {
        
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    return status;

}

__status_int32_t build_tm_1_X_u8_u32_failure_data(TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  TCVerifyStage verify_stage,
                                                  uint8_t failure_code,
                                                  uint8_t failure_data1,
                                                  uint32_t failure_data2,
                                                  MissionObt current_obt) {
    
    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = get_failure_subtype(verify_stage);

    startup_tm(p_tm_handler);

    status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, failure_data1);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler, failure_data2);

    }

    if (status.__variant == Success) {
        
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    return status;

}
