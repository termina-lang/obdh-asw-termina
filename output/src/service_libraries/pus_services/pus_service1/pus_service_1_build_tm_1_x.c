
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
                  MyResult * const result, _Bool * const enabled) {
    
    #line 42 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_accept_enabled(flags_ack)) {
        
        #line 44 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 45 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, tc_packet_id, result);

        #line 46 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, tc_packet_error_ctrl, result);

        #line 47 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 1U, tm_seq_counter, current_obt);

        #line 48 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 52 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 55 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_2(const TCStatus * const status,
                  TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  const TCHandlerT * const tc_handler, MissionObt current_obt,
                  MyResult * const result) {
    
    #line 61 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    uint8_t error_code = 0U;

    #line 63 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    startup_tm(p_tm_handler);

    #line 64 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    append_u16_appdata_field(p_tm_handler, tc_handler->packet_header.packet_id,
                             result);

    #line 65 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    append_u16_appdata_field(p_tm_handler, tc_handler->packet_error_ctrl,
                             result);

    #line 69 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*status).error_code.__variant == TCErrorType__CRCError) {
        
        #line 71 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 2U;

        #line 72 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, result);

        #line 73 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        uint16_t calculated_crc = cal_crc_16(tc_handler->tc_descriptor.tc_bytes,
                                             tc_handler->tc_descriptor.tc_num_bytes - 2U);

        #line 74 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, tc_handler->packet_error_ctrl,
                                 result);

        #line 75 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler, calculated_crc, result);

    } else
    #line 78 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*status).error_code.__variant == TCErrorType__APIDError) {
        
        #line 80 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 3U;

        #line 81 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, result);

    } else
    #line 84 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*status).error_code.__variant == TCErrorType__SourceIDError) {
        
        #line 86 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 4U;

        #line 87 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, result);

        #line 88 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u16_appdata_field(p_tm_handler,
                                 (uint16_t)tc_handler->df_header.sourceID,
                                 result);

    } else
    #line 91 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*status).error_code.__variant == TCErrorType__TypeError) {
        
        #line 93 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 5U;

        #line 94 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, result);

    } else
    #line 97 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if ((*status).error_code.__variant == TCErrorType__SubTypeError) {
        
        #line 99 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        error_code = 6U;

        #line 100 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        append_u8_appdata_field(p_tm_handler, error_code, result);

    } else
    {
        

    }

    #line 108 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    close_tm(p_tm_handler, 1U, 2U, tm_seq_counter, current_obt);

    #line 110 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_3(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint8_t flags_ack, MissionObt current_obt,
                  MyResult * const result, _Bool * const enabled) {
    
    #line 117 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_start_exec_enabled(flags_ack)) {
        
        #line 119 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 120 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 3U, tm_seq_counter, current_obt);

        #line 121 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 125 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 130 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    (*result).__variant = MyResult__Ok;

    #line 132 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_short_pack_length(TMHandlerT * const p_tm_handler,
                                    uint16_t tm_seq_counter,
                                    uint16_t tc_packet_id,
                                    uint16_t tc_packet_error_ctrl,
                                    size_t tc_bytes, MissionObt current_obt,
                                    MyResult * const result) {
    
    #line 139 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 139 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 140 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    uint16_t failure_data = (uint16_t)tc_bytes;

    #line 142 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH,
                                  failure_data, current_obt, result);

    #line 146 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_num_of_instr_not_valid(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         uint16_t tc_packet_id,
                                         uint16_t tc_packet_error_ctrl,
                                         uint8_t N, MissionObt current_obt,
                                         MyResult * const result) {
    
    #line 152 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 152 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 154 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR, N,
                                 current_obt, result);

    #line 157 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_device_address_not_valid(TMHandlerT * const p_tm_handler,
                                           uint16_t tm_seq_counter,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_error_ctrl,
                                           uint32_t device_address,
                                           MissionObt current_obt,
                                           MyResult * const result) {
    
    #line 163 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 163 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 165 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u32_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID,
                                  device_address, current_obt, result);

    #line 168 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_SID_not_valid(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                uint16_t tc_packet_error_ctrl, uint16_t SID,
                                MissionObt current_obt,
                                MyResult * const result) {
    
    #line 174 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 174 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 176 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_3_X_INVALID_SID, SID, current_obt,
                                  result);

    #line 179 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_mem_address_not_valid(TMHandlerT * const p_tm_handler,
                                        uint16_t tm_seq_counter,
                                        uint16_t tc_packet_id,
                                        uint16_t tc_packet_error_ctrl,
                                        uint8_t mem_id, uint32_t mem_address,
                                        MissionObt current_obt,
                                        MyResult * const result) {
    
    #line 185 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 185 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 187 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_u32_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                     tc_packet_error_ctrl, verify_stage,
                                     TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS,
                                     mem_id, mem_address, current_obt, result);

    #line 190 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_mem_id_read_only(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   uint8_t mem_id, MissionObt current_obt,
                                   MyResult * const result) {
    
    #line 196 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 196 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 198 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY, mem_id,
                                 current_obt, result);

    #line 201 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_EvID_not_valid(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t EvID,
                                 MissionObt current_obt,
                                 MyResult * const result) {
    
    #line 207 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 207 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 209 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_5_X_INVALID_EV_ID, EvID,
                                  current_obt, result);

    #line 212 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PID_not_valid(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                uint16_t tc_packet_error_ctrl, uint16_t PID,
                                MissionObt current_obt,
                                MyResult * const result) {
    
    #line 218 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 218 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 220 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_20_X_INVALID_PID, PID, current_obt,
                                  result);

    #line 223 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_undefined(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                                 MissionObt current_obt,
                                 MyResult * const result) {
    
    #line 229 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 229 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 231 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_PMON_UNDEFINED, PMONID,
                                  current_obt, result);

    #line 234 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_defined(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, uint16_t tc_packet_id,
                               uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                               MissionObt current_obt,
                               MyResult * const result) {
    
    #line 240 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 240 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 242 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_PMON_DEFINED, PMONID,
                                  current_obt, result);

    #line 245 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_enabled(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, uint16_t tc_packet_id,
                               uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                               MissionObt current_obt,
                               MyResult * const result) {
    
    #line 251 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 251 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 253 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_PMON_ENABLED, PMONID,
                                  current_obt, result);

    #line 256 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMONID_invalid(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                                 MissionObt current_obt,
                                 MyResult * const result) {
    
    #line 262 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 262 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 264 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_INVALID_PMONID, PMONID,
                                  current_obt, result);

    #line 267 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PMON_definition_invalid(TMHandlerT * const p_tm_handler,
                                          uint16_t tm_seq_counter,
                                          uint16_t tc_packet_id,
                                          uint16_t tc_packet_error_ctrl,
                                          uint16_t PMONID,
                                          MissionObt current_obt,
                                          MyResult * const result) {
    
    #line 273 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 273 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 275 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_12_X_INVALID_PMON_DEFINITION,
                                  PMONID, current_obt, result);

    #line 278 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_ev_action_enabled(TMHandlerT * const p_tm_handler,
                                    uint16_t tm_seq_counter,
                                    uint16_t tc_packet_id,
                                    uint16_t tc_packet_error_ctrl,
                                    uint16_t event_ID, MissionObt current_obt,
                                    MyResult * const result) {
    
    #line 284 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 284 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 286 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED, event_ID,
                                  current_obt, result);

    #line 289 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_ev_action_rejected(TMHandlerT * const p_tm_handler,
                                     uint16_t tm_seq_counter,
                                     uint16_t tc_packet_id,
                                     uint16_t tc_packet_error_ctrl,
                                     uint16_t event_ID, MissionObt current_obt,
                                     MyResult * const result) {
    
    #line 295 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 295 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 297 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_19_1_EV_ACTION_REJECTED, event_ID,
                                  current_obt, result);

    #line 300 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_ev_action_undefined(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      uint16_t event_ID, MissionObt current_obt,
                                      MyResult * const result) {
    
    #line 306 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 306 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 308 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED,
                                  event_ID, current_obt, result);

    #line 311 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PID_stats_undefined(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      uint16_t PID, MissionObt current_obt,
                                      MyResult * const result) {
    
    #line 317 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 317 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 319 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_4_7_PID_STATS_UNDEFINED, PID,
                                  current_obt, result);

    #line 322 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_PID_read_only_via_TC(TMHandlerT * const p_tm_handler,
                                       uint16_t tm_seq_counter,
                                       uint16_t tc_packet_id,
                                       uint16_t tc_packet_error_ctrl,
                                       uint16_t PID, MissionObt current_obt,
                                       MyResult * const result) {
    
    #line 328 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 328 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 330 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC, PID,
                                  current_obt, result);

    #line 333 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_4_error_in_acceptance(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      MissionObt current_obt,
                                      MyResult * const result) {
    
    #line 339 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 339 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 341 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_no_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_4_ERROR_IN_ACCEPTANCE, current_obt,
                                 result);

    #line 344 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_7(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint8_t flags_ack, MissionObt current_obt,
                  MyResult * const result, _Bool * const enabled) {
    
    #line 350 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_completion_exec_enabled(flags_ack)) {
        
        #line 352 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 353 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 7U, tm_seq_counter, current_obt);

        #line 354 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 358 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 361 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    (*result).__variant = MyResult__Ok;

    #line 363 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_max_ev_actions_defined(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         uint16_t tc_packet_id,
                                         uint16_t tc_packet_error_ctrl,
                                         uint16_t evID, MissionObt current_obt,
                                         MyResult * const result) {
    
    #line 370 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 370 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 372 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED, evID,
                                  current_obt, result);

    #line 375 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_tm_exceed_limit_appdata(TMHandlerT * const p_tm_handler,
                                          uint16_t tm_seq_counter,
                                          uint16_t tc_packet_id,
                                          uint16_t tc_packet_error_ctrl,
                                          MissionObt current_obt,
                                          MyResult * const result) {
    
    #line 382 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 382 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 384 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_no_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA,
                                 current_obt, result);

    #line 387 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_device_command_exec_error(TMHandlerT * const p_tm_handler,
                                            uint16_t tm_seq_counter,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_error_ctrl,
                                            uint32_t on_off_command,
                                            MissionObt current_obt,
                                            MyResult * const result) {
    
    #line 393 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 393 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 395 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u32_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR,
                                  on_off_command, current_obt, result);

    #line 398 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_not_free_stats_config(TMHandlerT * const p_tm_handler,
                                        uint16_t tm_seq_counter,
                                        uint16_t tc_packet_id,
                                        uint16_t tc_packet_error_ctrl,
                                        uint16_t PID, MissionObt current_obt,
                                        MyResult * const result) {
    
    #line 405 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 405 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 407 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                  tc_packet_error_ctrl, verify_stage,
                                  TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG, PID,
                                  current_obt, result);

    #line 410 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}

void build_tm_1_8_mem_access_error(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   uint8_t mem_ID, MissionObt current_obt,
                                   MyResult * const result) {
    
    #line 416 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 416 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 418 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter, tc_packet_id,
                                 tc_packet_error_ctrl, verify_stage,
                                 TM_1_8_TC_6_X_MEM_ACCESS_FAIL, mem_ID,
                                 current_obt, result);

    #line 421 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return;

}
