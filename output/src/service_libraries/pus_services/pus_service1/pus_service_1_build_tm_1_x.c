
#include "service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.h"

const uint8_t TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH = 1U;

const uint8_t TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR = 2U;

const uint8_t TM_1_4_TC_2_X_DEVICE_NOT_VALID = 3U;

const uint8_t TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID = 4U;

const uint8_t TM_1_4_TC_3_X_INVALID_SID = 5U;

const uint8_t TM_1_4_TC_4_7_PID_STATS_UNDEFINED = 6U;

const uint8_t TM_1_4_TC_5_X_INVALID_EV_ID = 7U;

const uint8_t TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS = 8U;

const uint8_t TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY = 9U;

const uint8_t TM_1_4_TC_6_X_OUT_OF_MEMORY_ID_LIMITS = 10U;

const uint8_t TM_1_4_TC_11_X_SCHED_TC_REJECTED = 11U;

const uint8_t TM_1_4_TC_11_X_INVALID_SCHED_TIME = 12U;

const uint8_t TM_1_4_TC_12_X_PMON_UNDEFINED = 13U;

const uint8_t TM_1_4_TC_12_X_PMON_DEFINED = 14U;

const uint8_t TM_1_4_TC_12_X_PMON_ENABLED = 15U;

const uint8_t TM_1_4_TC_12_X_INVALID_PMONID = 16U;

const uint8_t TM_1_4_TC_12_X_INVALID_PMON_DEFINITION = 17U;

const uint8_t TM_1_4_TC_15_X_INVALID_PACKET_STORE = 18U;

const uint8_t TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED = 19U;

const uint8_t TM_1_4_TC_19_1_EV_ACTION_REJECTED = 20U;

const uint8_t TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED = 21U;

const uint8_t TM_1_4_TC_20_X_INVALID_PID = 22U;

const uint8_t TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC = 23U;

const uint8_t TM_1_4_ERROR_IN_ACCEPTANCE = 24U;

const uint8_t TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA = 1U;

const uint8_t TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR = 2U;

const uint8_t TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG = 3U;

const uint8_t TM_1_8_TC_6_X_MEM_ACCESS_FAIL = 4U;

const uint8_t TM_1_8_TC_11_X_SCHED_TC_POOL_EMPTY = 5U;

const uint8_t TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED = 6U;

void build_tm_1_1(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint16_t tc_packet_id, uint16_t tc_packet_error_ctrl,
                  uint8_t flags_ack, MissionObt current_obt,
                  __status_int32_t * const status, _Bool * const enabled) {
    
    #line 63 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_accept_enabled(flags_ack)) {
        
        #line 65 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 66 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, tc_packet_id, status);

        #line 67 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, status);

        #line 68 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 1U, tm_seq_counter, current_obt);

        #line 69 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 73 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 76 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_2(const TCStatus * const tc_status,
                  TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  const TCHandlerT * const tc_handler, MissionObt current_obt,
                  __status_int32_t * const status) {
    
    #line 94 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    uint8_t error_code = 0U;

    #line 96 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    startup_tm(p_tm_handler);

    #line 97 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    append_u16_appdata_field(p_tm_handler, tc_handler->packet_header.packet_id,
                             status);

    #line 98 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    append_u16_appdata_field(p_tm_handler, tc_handler->packet_error_ctrl,
                             status);

    #line 102 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*tc_status).error_code.__variant == TCErrorType__CRCError) {
        
        #line 104 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 2U;

        #line 105 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, status);

        #line 106 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        uint16_t calculated_crc = cal_crc_16(tc_handler->tc_descriptor.tc_bytes,
                                             tc_handler->tc_descriptor.tc_num_bytes - 2U);

        #line 107 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, tc_handler->packet_error_ctrl,
                                 status);

        #line 108 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, calculated_crc, status);

    } else
    #line 111 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*tc_status).error_code.__variant == TCErrorType__APIDError) {
        
        #line 113 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 3U;

        #line 114 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, status);

    } else
    #line 117 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*tc_status).error_code.__variant == TCErrorType__SourceIDError) {
        
        #line 119 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 4U;

        #line 120 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, status);

        #line 121 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler,
                                 (uint16_t)tc_handler->df_header.sourceID,
                                 status);

    } else
    #line 124 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*tc_status).error_code.__variant == TCErrorType__TypeError) {
        
        #line 126 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 5U;

        #line 127 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, status);

    } else
    #line 130 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*tc_status).error_code.__variant == TCErrorType__SubTypeError) {
        
        #line 132 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 6U;

        #line 133 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, status);

    } else
    {
        

    }

    #line 141 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    close_tm(p_tm_handler, 1U, 2U, tm_seq_counter, current_obt);

    #line 143 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_3(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint8_t flags_ack, MissionObt current_obt,
                  __status_int32_t * const status, _Bool * const enabled) {
    
    #line 160 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_start_exec_enabled(flags_ack)) {
        
        #line 162 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 163 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 3U, tm_seq_counter, current_obt);

        #line 164 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 168 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 173 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    (*status).__variant = Success;

    #line 175 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_short_pack_length(TMHandlerT * const p_tm_handler,
                                    uint16_t tm_seq_counter,
                                    uint16_t tc_packet_id,
                                    uint16_t tc_packet_error_ctrl,
                                    size_t tc_bytes, MissionObt current_obt,
                                    __status_int32_t * const status) {
    
    #line 193 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 193 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 194 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    uint16_t failure_data = (uint16_t)tc_bytes;

    #line 196 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH,
                                  failure_data, current_obt, status);

    #line 200 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_num_of_instr_not_valid(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         uint16_t tc_packet_id,
                                         uint16_t tc_packet_error_ctrl,
                                         uint8_t N, MissionObt current_obt,
                                         __status_int32_t * const status) {
    
    #line 218 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 218 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 220 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR, N,
                                 current_obt, status);

    #line 223 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_device_address_not_valid(TMHandlerT * const p_tm_handler,
                                           uint16_t tm_seq_counter,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_error_ctrl,
                                           uint32_t device_address,
                                           MissionObt current_obt,
                                           __status_int32_t * const status) {
    
    #line 241 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 241 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 243 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u32_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID,
                                  device_address, current_obt, status);

    #line 246 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_SID_not_valid(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                uint16_t tc_packet_error_ctrl, uint16_t SID,
                                MissionObt current_obt,
                                __status_int32_t * const status) {
    
    #line 265 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 265 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 267 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_3_X_INVALID_SID, SID, current_obt,
                                  status);

    #line 270 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_mem_address_not_valid(TMHandlerT * const p_tm_handler,
                                        uint16_t tm_seq_counter,
                                        uint16_t tc_packet_id,
                                        uint16_t tc_packet_error_ctrl,
                                        uint8_t mem_id, uint32_t mem_address,
                                        MissionObt current_obt,
                                        __status_int32_t * const status) {
    
    #line 290 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 290 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 292 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_u32_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                     tc_packet_error_ctrl, verify_stage,
                                     TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS,
                                     mem_id, mem_address, current_obt, status);

    #line 295 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_mem_id_read_only(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   uint8_t mem_id, MissionObt current_obt,
                                   __status_int32_t * const status) {
    
    #line 314 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 314 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 316 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY, mem_id,
                                 current_obt, status);

    #line 319 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_EvID_not_valid(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t EvID,
                                 MissionObt current_obt,
                                 __status_int32_t * const status) {
    
    #line 338 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 338 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 340 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_5_X_INVALID_EV_ID, EvID,
                                  current_obt, status);

    #line 343 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PID_not_valid(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                uint16_t tc_packet_error_ctrl, uint16_t PID,
                                MissionObt current_obt,
                                __status_int32_t * const status) {
    
    #line 362 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 362 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 364 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_20_X_INVALID_PID, PID, current_obt,
                                  status);

    #line 367 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_undefined(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                                 MissionObt current_obt,
                                 __status_int32_t * const status) {
    
    #line 386 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 386 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 388 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_PMON_UNDEFINED, PMONID,
                                  current_obt, status);

    #line 391 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_defined(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, uint16_t tc_packet_id,
                               uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                               MissionObt current_obt,
                               __status_int32_t * const status) {
    
    #line 409 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 409 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 411 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_PMON_DEFINED, PMONID,
                                  current_obt, status);

    #line 414 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_enabled(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, uint16_t tc_packet_id,
                               uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                               MissionObt current_obt,
                               __status_int32_t * const status) {
    
    #line 432 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 432 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 434 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_PMON_ENABLED, PMONID,
                                  current_obt, status);

    #line 437 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMONID_invalid(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                                 MissionObt current_obt,
                                 __status_int32_t * const status) {
    
    #line 455 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 455 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 457 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_INVALID_PMONID, PMONID,
                                  current_obt, status);

    #line 460 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_definition_invalid(TMHandlerT * const p_tm_handler,
                                          uint16_t tm_seq_counter,
                                          uint16_t tc_packet_id,
                                          uint16_t tc_packet_error_ctrl,
                                          uint16_t PMONID,
                                          MissionObt current_obt,
                                          __status_int32_t * const status) {
    
    #line 478 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 478 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 480 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_INVALID_PMON_DEFINITION,
                                  PMONID, current_obt, status);

    #line 483 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_ev_action_enabled(TMHandlerT * const p_tm_handler,
                                    uint16_t tm_seq_counter,
                                    uint16_t tc_packet_id,
                                    uint16_t tc_packet_error_ctrl,
                                    uint16_t event_ID, MissionObt current_obt,
                                    __status_int32_t * const status) {
    
    #line 501 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 501 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 503 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED, event_ID,
                                  current_obt, status);

    #line 506 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_ev_action_rejected(TMHandlerT * const p_tm_handler,
                                     uint16_t tm_seq_counter,
                                     uint16_t tc_packet_id,
                                     uint16_t tc_packet_error_ctrl,
                                     uint16_t event_ID, MissionObt current_obt,
                                     __status_int32_t * const status) {
    
    #line 523 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 523 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 525 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_19_1_EV_ACTION_REJECTED, event_ID,
                                  current_obt, status);

    #line 528 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_ev_action_undefined(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      uint16_t event_ID, MissionObt current_obt,
                                      __status_int32_t * const status) {
    
    #line 547 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 547 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 549 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED,
                                  event_ID, current_obt, status);

    #line 552 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PID_stats_undefined(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      uint16_t PID, MissionObt current_obt,
                                      __status_int32_t * const status) {
    
    #line 570 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 570 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 572 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_4_7_PID_STATS_UNDEFINED, PID,
                                  current_obt, status);

    #line 575 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PID_read_only_via_TC(TMHandlerT * const p_tm_handler,
                                       uint16_t tm_seq_counter,
                                       uint16_t tc_packet_id,
                                       uint16_t tc_packet_error_ctrl,
                                       uint16_t PID, MissionObt current_obt,
                                       __status_int32_t * const status) {
    
    #line 593 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 593 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 595 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC, PID,
                                  current_obt, status);

    #line 598 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_error_in_acceptance(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      MissionObt current_obt,
                                      __status_int32_t * const status) {
    
    #line 615 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 615 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 617 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_no_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_4_ERROR_IN_ACCEPTANCE, current_obt,
                                 status);

    #line 620 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_7(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint8_t flags_ack, MissionObt current_obt,
                  __status_int32_t * const status, _Bool * const enabled) {
    
    #line 637 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_completion_exec_enabled(flags_ack)) {
        
        #line 639 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 640 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 7U, tm_seq_counter, current_obt);

        #line 641 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 645 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 648 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    (*status).__variant = Success;

    #line 650 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_max_ev_actions_defined(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         uint16_t tc_packet_id,
                                         uint16_t tc_packet_error_ctrl,
                                         uint16_t evID, MissionObt current_obt,
                                         __status_int32_t * const status) {
    
    #line 668 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 668 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 670 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED, evID,
                                  current_obt, status);

    #line 673 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_tm_exceed_limit_appdata(TMHandlerT * const p_tm_handler,
                                          uint16_t tm_seq_counter,
                                          uint16_t tc_packet_id,
                                          uint16_t tc_packet_error_ctrl,
                                          MissionObt current_obt,
                                          __status_int32_t * const status) {
    
    #line 691 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 691 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 693 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_no_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA,
                                 current_obt, status);

    #line 696 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_device_command_exec_error(TMHandlerT * const p_tm_handler,
                                            uint16_t tm_seq_counter,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_error_ctrl,
                                            uint32_t on_off_command,
                                            MissionObt current_obt,
                                            __status_int32_t * const status) {
    
    #line 714 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 714 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 716 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u32_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR,
                                  on_off_command, current_obt, status);

    #line 719 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_not_free_stats_config(TMHandlerT * const p_tm_handler,
                                        uint16_t tm_seq_counter,
                                        uint16_t tc_packet_id,
                                        uint16_t tc_packet_error_ctrl,
                                        uint16_t PID, MissionObt current_obt,
                                        __status_int32_t * const status) {
    
    #line 738 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 738 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 740 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG, PID,
                                  current_obt, status);

    #line 743 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_mem_access_error(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   uint8_t mem_ID, MissionObt current_obt,
                                   __status_int32_t * const status) {
    
    #line 761 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 761 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 763 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_8_TC_6_X_MEM_ACCESS_FAIL, mem_ID,
                                 current_obt, status);

    #line 766 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}
