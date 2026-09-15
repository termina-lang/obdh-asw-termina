
#include "service_libraries/pus_services/pus_service1/internal.h"

const uint8_t ACCEPT_ACK_ENABLED_MASK = 0x1U;

const uint8_t EXEC_START_ACK_ENABLED_MASK = 0x2U;

const uint8_t EXEC_PROGRESS_ACK_ENABLED_MASK = 0x4U;

const uint8_t EXEC_COMPLETION_ACK_ENABLED_MASK = 0x8U;

_Bool is_crc_valid(const TCDescriptor * const tc_descriptor) {
    
    #line 81 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint16_t cal_crc_value = cal_crc_16(tc_descriptor->tc_bytes, tc_descriptor->tc_num_bytes - 2U);

    #line 82 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    #line 84 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool is_valid = cal_crc_value == packet_error_ctrl;

    #line 86 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return is_valid;

}

_Bool is_apid_valid(const TCDescriptor * const tc_descriptor) {
    
    #line 97 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint16_t epd_apid = 0x32CU;

    #line 98 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint16_t tc_apid = get_APID(tc_descriptor->tc_bytes);

    #line 100 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool is_valid = epd_apid == tc_apid;

    #line 102 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return is_valid;

}

_Bool is_sourceID_valid(const TCDescriptor * const tc_descriptor) {
    
    #line 113 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint16_t System_SourceID = 0x78U;

    #line 115 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint16_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    #line 117 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool is_valid = System_SourceID == sourceID;

    #line 119 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return is_valid;

}

_Bool is_tc_ack_accept_enabled(uint8_t flags_ack) {
    
    #line 130 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool ack_enabled = false;

    #line 132 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if ((uint8_t)(flags_ack & ACCEPT_ACK_ENABLED_MASK) != 0U) {
        
        #line 133 "src/service_libraries/pus_services/pus_service1/internal.fin"
        ack_enabled = true;

    }

    #line 135 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return ack_enabled;

}

_Bool is_tc_ack_start_exec_enabled(uint8_t flags_ack) {
    
    #line 148 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool ack_enabled = false;

    #line 150 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if ((uint8_t)(flags_ack & EXEC_START_ACK_ENABLED_MASK) != 0U) {
        
        #line 151 "src/service_libraries/pus_services/pus_service1/internal.fin"
        ack_enabled = true;

    }

    #line 153 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return ack_enabled;

}

_Bool is_tc_ack_progress_exec_enabled(uint8_t flags_ack) {
    
    #line 165 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool ack_enabled = false;

    #line 167 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if ((uint8_t)(flags_ack & EXEC_PROGRESS_ACK_ENABLED_MASK) != 0U) {
        
        #line 168 "src/service_libraries/pus_services/pus_service1/internal.fin"
        ack_enabled = true;

    }

    #line 170 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return ack_enabled;

}

_Bool is_tc_ack_completion_exec_enabled(uint8_t flags_ack) {
    
    #line 182 "src/service_libraries/pus_services/pus_service1/internal.fin"
    _Bool ack_enabled = false;

    #line 184 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if ((uint8_t)(flags_ack & EXEC_COMPLETION_ACK_ENABLED_MASK) != 0U) {
        
        #line 185 "src/service_libraries/pus_services/pus_service1/internal.fin"
        ack_enabled = true;

    }

    #line 187 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return ack_enabled;

}

uint8_t get_failure_subtype(TCVerifyStage verify_stage) {
    
    #line 199 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint8_t subtype;

    #line 202 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (verify_stage.__variant == TCVerifyStage__Acceptation) {
        
        #line 203 "src/service_libraries/pus_services/pus_service1/internal.fin"
        subtype = 2U;

    } else
    #line 205 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (verify_stage.__variant == TCVerifyStage__ExecStart) {
        
        #line 206 "src/service_libraries/pus_services/pus_service1/internal.fin"
        subtype = 4U;

    } else
    #line 208 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (verify_stage.__variant == TCVerifyStage__Progress) {
        
        #line 209 "src/service_libraries/pus_services/pus_service1/internal.fin"
        subtype = 6U;

    } else
    {
        
        #line 212 "src/service_libraries/pus_services/pus_service1/internal.fin"
        subtype = 8U;

    }

    #line 216 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return subtype;

}

__status_int32_t build_tm_1_X_no_failure_data(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, TCVerifyStage verify_stage, uint8_t failure_code, MissionOBT current_obt) {
    
    #line 235 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 237 "src/service_libraries/pus_services/pus_service1/internal.fin"
    startup_tm(p_tm_handler);

    #line 238 "src/service_libraries/pus_services/pus_service1/internal.fin"
    __status_int32_t status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    #line 239 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 240 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    #line 242 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 243 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    #line 245 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 246 "src/service_libraries/pus_services/pus_service1/internal.fin"
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    #line 249 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return status;

}

__status_int32_t build_tm_1_X_u8_failure_data(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, TCVerifyStage verify_stage, uint8_t failure_code, uint8_t failure_data, MissionOBT current_obt) {
    
    #line 260 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 262 "src/service_libraries/pus_services/pus_service1/internal.fin"
    startup_tm(p_tm_handler);

    #line 263 "src/service_libraries/pus_services/pus_service1/internal.fin"
    __status_int32_t status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    #line 264 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 265 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    #line 267 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 268 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    #line 270 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 271 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_data);

    }

    #line 273 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 274 "src/service_libraries/pus_services/pus_service1/internal.fin"
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    #line 277 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return status;

}

__status_int32_t build_tm_1_X_u16_failure_data(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, TCVerifyStage verify_stage, uint8_t failure_code, uint16_t failure_data, MissionOBT current_obt) {
    
    #line 288 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 290 "src/service_libraries/pus_services/pus_service1/internal.fin"
    startup_tm(p_tm_handler);

    #line 291 "src/service_libraries/pus_services/pus_service1/internal.fin"
    __status_int32_t status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    #line 292 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 293 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    #line 295 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 296 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    #line 298 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 299 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, failure_data);

    }

    #line 301 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 302 "src/service_libraries/pus_services/pus_service1/internal.fin"
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    #line 305 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return status;

}

__status_int32_t build_tm_1_X_u32_failure_data(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, TCVerifyStage verify_stage, uint8_t failure_code, uint32_t failure_data, MissionOBT current_obt) {
    
    #line 316 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 318 "src/service_libraries/pus_services/pus_service1/internal.fin"
    startup_tm(p_tm_handler);

    #line 319 "src/service_libraries/pus_services/pus_service1/internal.fin"
    __status_int32_t status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    #line 320 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 321 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    #line 323 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 324 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    #line 326 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 327 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, failure_data);

    }

    #line 329 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 330 "src/service_libraries/pus_services/pus_service1/internal.fin"
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    #line 333 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return status;

}

__status_int32_t build_tm_1_X_u8_u32_failure_data(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, TCVerifyStage verify_stage, uint8_t failure_code, uint8_t failure_data1, uint32_t failure_data2, MissionOBT current_obt) {
    
    #line 346 "src/service_libraries/pus_services/pus_service1/internal.fin"
    uint8_t subtype = get_failure_subtype(verify_stage);

    #line 348 "src/service_libraries/pus_services/pus_service1/internal.fin"
    startup_tm(p_tm_handler);

    #line 349 "src/service_libraries/pus_services/pus_service1/internal.fin"
    __status_int32_t status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

    #line 350 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 351 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

    }

    #line 353 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 354 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_code);

    }

    #line 356 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 357 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, failure_data1);

    }

    #line 359 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 360 "src/service_libraries/pus_services/pus_service1/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, failure_data2);

    }

    #line 362 "src/service_libraries/pus_services/pus_service1/internal.fin"
    if (status.__variant == Success) {
        
        #line 363 "src/service_libraries/pus_services/pus_service1/internal.fin"
        close_tm(p_tm_handler, 1U, subtype, tm_seq_counter, current_obt);

    }

    #line 366 "src/service_libraries/pus_services/pus_service1/internal.fin"
    return status;

}
