
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

__status_int32_t build_tm_1_1(TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter, uint16_t tc_packet_id,
                              uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                              MissionObt current_obt, _Bool * const enabled) {
    
    #line 63 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 63 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 65 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_accept_enabled(flags_ack)) {
        
        #line 67 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 68 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

        #line 69 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if (status.__variant == Success) {
            
            #line 70 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

        }

        #line 72 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if (status.__variant == Success) {
            
            #line 73 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            close_tm(p_tm_handler, 1U, 1U, tm_seq_counter, current_obt);

        }

        #line 75 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 79 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 82 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_2(const TCStatus * const tc_status,
                              TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter,
                              const TCHandlerT * const tc_handler,
                              MissionObt current_obt) {
    
    #line 100 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 100 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 102 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    uint8_t error_code = 0U;

    #line 104 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    startup_tm(p_tm_handler);

    #line 105 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = append_u16_appdata_field(p_tm_handler,
                                      tc_handler->packet_header.packet_id);

    #line 106 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (status.__variant == Success) {
        
        #line 107 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        status = append_u16_appdata_field(p_tm_handler,
                                          tc_handler->packet_error_ctrl);

    }

    #line 110 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (status.__variant == Success) {
        
        #line 113 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if ((*tc_status).error_code.__variant == TCErrorType__CRCError) {
            
            #line 115 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            error_code = 2U;

            #line 116 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u8_appdata_field(p_tm_handler, error_code);

            #line 117 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            uint16_t calculated_crc = cal_crc_16(tc_handler->tc_descriptor.tc_bytes,
                                                 tc_handler->tc_descriptor.tc_num_bytes - 2U);

            #line 118 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            if (status.__variant == Success) {
                
                #line 119 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
                status = append_u16_appdata_field(p_tm_handler,
                                                  tc_handler->packet_error_ctrl);

            }

            #line 121 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            if (status.__variant == Success) {
                
                #line 122 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
                status = append_u16_appdata_field(p_tm_handler, calculated_crc);

            }

        } else
        #line 126 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if ((*tc_status).error_code.__variant == TCErrorType__APIDError) {
            
            #line 128 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            error_code = 3U;

            #line 129 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u8_appdata_field(p_tm_handler, error_code);

        } else
        #line 132 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if ((*tc_status).error_code.__variant == TCErrorType__SourceIDError) {
            
            #line 134 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            error_code = 4U;

            #line 135 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u8_appdata_field(p_tm_handler, error_code);

            #line 136 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            if (status.__variant == Success) {
                
                #line 137 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
                status = append_u16_appdata_field(p_tm_handler,
                                                  (uint16_t)tc_handler->df_header.sourceID);

            }

        } else
        #line 141 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if ((*tc_status).error_code.__variant == TCErrorType__TypeError) {
            
            #line 143 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            error_code = 5U;

            #line 144 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u8_appdata_field(p_tm_handler, error_code);

            #line 145 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            if (status.__variant == Success) {
                
                #line 146 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
                status = append_u8_appdata_field(p_tm_handler,
                                                 tc_handler->df_header.type);

            }

        } else
        #line 150 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if ((*tc_status).error_code.__variant == TCErrorType__SubTypeError) {
            
            #line 152 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            error_code = 6U;

            #line 153 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u8_appdata_field(p_tm_handler, error_code);

            #line 154 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            if (status.__variant == Success) {
                
                #line 155 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
                status = append_u8_appdata_field(p_tm_handler,
                                                 tc_handler->df_header.subtype);

            }

        } else
        {
            

        }

    }

    #line 165 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (status.__variant == Success) {
        
        #line 166 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        close_tm(p_tm_handler, 1U, 2U, tm_seq_counter, current_obt);

    }

    #line 169 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_3(TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter, uint16_t tc_packet_id,
                              uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                              MissionObt current_obt, _Bool * const enabled) {
    
    #line 186 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 186 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 188 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_start_exec_enabled(flags_ack)) {
        
        #line 190 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 191 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

        #line 192 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if (status.__variant == Success) {
            
            #line 193 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

        }

        #line 195 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if (status.__variant == Success) {
            
            #line 196 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            close_tm(p_tm_handler, 1U, 3U, tm_seq_counter, current_obt);

        }

        #line 198 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 202 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 206 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_short_pack_length(TMHandlerT * const p_tm_handler,
                                                uint16_t tm_seq_counter,
                                                uint16_t tc_packet_id,
                                                uint16_t tc_packet_seq_ctrl,
                                                size_t tc_bytes,
                                                MissionObt current_obt) {
    
    #line 224 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 224 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 225 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 225 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 226 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    uint16_t failure_data = (uint16_t)tc_bytes;

    #line 228 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH,
                                           failure_data, current_obt);

    #line 231 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_num_of_instr_not_valid(TMHandlerT * const p_tm_handler,
                                                     uint16_t tm_seq_counter,
                                                     uint16_t tc_packet_id,
                                                     uint16_t tc_packet_seq_ctrl,
                                                     uint8_t N,
                                                     MissionObt current_obt) {
    
    #line 249 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 249 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 250 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 250 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 252 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter,
                                          tc_packet_id, tc_packet_seq_ctrl,
                                          verify_stage,
                                          TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR,
                                          N, current_obt);

    #line 255 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_device_address_not_valid(TMHandlerT * const p_tm_handler,
                                                       uint16_t tm_seq_counter,
                                                       uint16_t tc_packet_id,
                                                       uint16_t tc_packet_seq_ctrl,
                                                       uint32_t device_address,
                                                       MissionObt current_obt) {
    
    #line 273 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 273 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 274 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 274 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 276 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u32_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID,
                                           device_address, current_obt);

    #line 279 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_SID_not_valid(TMHandlerT * const p_tm_handler,
                                            uint16_t tm_seq_counter,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_seq_ctrl,
                                            uint16_t SID,
                                            MissionObt current_obt) {
    
    #line 298 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 298 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 299 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 299 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 301 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_3_X_INVALID_SID, SID,
                                           current_obt);

    #line 304 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_mem_address_not_valid(TMHandlerT * const p_tm_handler,
                                                    uint16_t tm_seq_counter,
                                                    uint16_t tc_packet_id,
                                                    uint16_t tc_packet_seq_ctrl,
                                                    uint8_t mem_id,
                                                    uint32_t mem_address,
                                                    MissionObt current_obt) {
    
    #line 324 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 324 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 325 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 325 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 327 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u8_u32_failure_data(p_tm_handler, tm_seq_counter,
                                              tc_packet_id, tc_packet_seq_ctrl,
                                              verify_stage,
                                              TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS,
                                              mem_id, mem_address, current_obt);

    #line 330 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_mem_id_read_only(TMHandlerT * const p_tm_handler,
                                               uint16_t tm_seq_counter,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               uint8_t mem_id,
                                               MissionObt current_obt) {
    
    #line 349 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 349 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 350 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 350 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 352 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter,
                                          tc_packet_id, tc_packet_seq_ctrl,
                                          verify_stage,
                                          TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY,
                                          mem_id, current_obt);

    #line 355 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_EvID_not_valid(TMHandlerT * const p_tm_handler,
                                             uint16_t tm_seq_counter,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t EvID,
                                             MissionObt current_obt) {
    
    #line 374 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 374 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 375 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 375 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 377 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_5_X_INVALID_EV_ID, EvID,
                                           current_obt);

    #line 380 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PID_not_valid(TMHandlerT * const p_tm_handler,
                                            uint16_t tm_seq_counter,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_seq_ctrl,
                                            uint16_t PID,
                                            MissionObt current_obt) {
    
    #line 399 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 399 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 400 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 400 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 402 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_20_X_INVALID_PID, PID,
                                           current_obt);

    #line 405 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PMON_undefined(TMHandlerT * const p_tm_handler,
                                             uint16_t tm_seq_counter,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t PMONID,
                                             MissionObt current_obt) {
    
    #line 424 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 424 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 425 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 425 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 427 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_12_X_PMON_UNDEFINED,
                                           PMONID, current_obt);

    #line 430 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PMON_defined(TMHandlerT * const p_tm_handler,
                                           uint16_t tm_seq_counter,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_seq_ctrl,
                                           uint16_t PMONID,
                                           MissionObt current_obt) {
    
    #line 448 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 448 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 449 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 449 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 451 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_12_X_PMON_DEFINED, PMONID,
                                           current_obt);

    #line 454 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PMON_enabled(TMHandlerT * const p_tm_handler,
                                           uint16_t tm_seq_counter,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_seq_ctrl,
                                           uint16_t PMONID,
                                           MissionObt current_obt) {
    
    #line 472 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 472 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 473 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 473 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 475 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_12_X_PMON_ENABLED, PMONID,
                                           current_obt);

    #line 478 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PMONID_invalid(TMHandlerT * const p_tm_handler,
                                             uint16_t tm_seq_counter,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t PMONID,
                                             MissionObt current_obt) {
    
    #line 496 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 496 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 497 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 497 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 499 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_12_X_INVALID_PMONID,
                                           PMONID, current_obt);

    #line 502 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PMON_definition_invalid(TMHandlerT * const p_tm_handler,
                                                      uint16_t tm_seq_counter,
                                                      uint16_t tc_packet_id,
                                                      uint16_t tc_packet_seq_ctrl,
                                                      uint16_t PMONID,
                                                      MissionObt current_obt) {
    
    #line 520 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 520 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 521 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 521 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 523 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_12_X_INVALID_PMON_DEFINITION,
                                           PMONID, current_obt);

    #line 526 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_ev_action_enabled(TMHandlerT * const p_tm_handler,
                                                uint16_t tm_seq_counter,
                                                uint16_t tc_packet_id,
                                                uint16_t tc_packet_seq_ctrl,
                                                uint16_t event_ID,
                                                MissionObt current_obt) {
    
    #line 544 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 544 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 545 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 545 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 547 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED,
                                           event_ID, current_obt);

    #line 550 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_ev_action_rejected(TMHandlerT * const p_tm_handler,
                                                 uint16_t tm_seq_counter,
                                                 uint16_t tc_packet_id,
                                                 uint16_t tc_packet_seq_ctrl,
                                                 uint16_t event_ID,
                                                 MissionObt current_obt) {
    
    #line 567 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 567 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 568 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 568 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 570 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_19_1_EV_ACTION_REJECTED,
                                           event_ID, current_obt);

    #line 573 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_ev_action_undefined(TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  uint16_t event_ID,
                                                  MissionObt current_obt) {
    
    #line 592 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 592 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 593 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 593 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 595 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED,
                                           event_ID, current_obt);

    #line 598 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PID_stats_undefined(TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  uint16_t PID,
                                                  MissionObt current_obt) {
    
    #line 616 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 616 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 617 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 617 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 619 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_4_7_PID_STATS_UNDEFINED,
                                           PID, current_obt);

    #line 622 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_PID_read_only_via_TC(TMHandlerT * const p_tm_handler,
                                                   uint16_t tm_seq_counter,
                                                   uint16_t tc_packet_id,
                                                   uint16_t tc_packet_seq_ctrl,
                                                   uint16_t PID,
                                                   MissionObt current_obt) {
    
    #line 640 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 640 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 641 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 641 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 643 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC,
                                           PID, current_obt);

    #line 646 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_4_error_in_acceptance(TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  MissionObt current_obt) {
    
    #line 663 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 663 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 664 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 664 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecStart;

    #line 666 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_no_failure_data(p_tm_handler, tm_seq_counter,
                                          tc_packet_id, tc_packet_seq_ctrl,
                                          verify_stage,
                                          TM_1_4_ERROR_IN_ACCEPTANCE,
                                          current_obt);

    #line 669 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_7(TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter, uint16_t tc_packet_id,
                              uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                              MissionObt current_obt, _Bool * const enabled) {
    
    #line 686 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 686 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 688 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    if (is_tc_ack_completion_exec_enabled(flags_ack)) {
        
        #line 690 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        startup_tm(p_tm_handler);

        #line 691 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        status = append_u16_appdata_field(p_tm_handler, tc_packet_id);

        #line 692 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if (status.__variant == Success) {
            
            #line 693 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            status = append_u16_appdata_field(p_tm_handler, tc_packet_seq_ctrl);

        }

        #line 695 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        if (status.__variant == Success) {
            
            #line 696 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
            close_tm(p_tm_handler, 1U, 7U, tm_seq_counter, current_obt);

        }

        #line 698 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 1;

    } else
    {
        
        #line 702 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
        *enabled = 0;

    }

    #line 705 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_8_max_ev_actions_defined(TMHandlerT * const p_tm_handler,
                                                     uint16_t tm_seq_counter,
                                                     uint16_t tc_packet_id,
                                                     uint16_t tc_packet_seq_ctrl,
                                                     uint16_t evID,
                                                     MissionObt current_obt) {
    
    #line 723 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 723 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 724 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 724 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 726 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED,
                                           evID, current_obt);

    #line 729 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_8_tm_exceed_limit_appdata(TMHandlerT * const p_tm_handler,
                                                      uint16_t tm_seq_counter,
                                                      uint16_t tc_packet_id,
                                                      uint16_t tc_packet_seq_ctrl,
                                                      MissionObt current_obt) {
    
    #line 747 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 747 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 748 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 748 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 750 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_no_failure_data(p_tm_handler, tm_seq_counter,
                                          tc_packet_id, tc_packet_seq_ctrl,
                                          verify_stage,
                                          TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA,
                                          current_obt);

    #line 753 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_8_device_command_exec_error(TMHandlerT * const p_tm_handler,
                                                        uint16_t tm_seq_counter,
                                                        uint16_t tc_packet_id,
                                                        uint16_t tc_packet_seq_ctrl,
                                                        uint32_t on_off_command,
                                                        MissionObt current_obt) {
    
    #line 771 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 771 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 772 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 772 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 774 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u32_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR,
                                           on_off_command, current_obt);

    #line 777 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_8_not_free_stats_config(TMHandlerT * const p_tm_handler,
                                                    uint16_t tm_seq_counter,
                                                    uint16_t tc_packet_id,
                                                    uint16_t tc_packet_seq_ctrl,
                                                    uint16_t PID,
                                                    MissionObt current_obt) {
    
    #line 796 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 796 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 797 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 797 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 799 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u16_failure_data(p_tm_handler, tm_seq_counter,
                                           tc_packet_id, tc_packet_seq_ctrl,
                                           verify_stage,
                                           TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG,
                                           PID, current_obt);

    #line 802 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}

__status_int32_t build_tm_1_8_mem_access_error(TMHandlerT * const p_tm_handler,
                                               uint16_t tm_seq_counter,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               uint8_t mem_ID,
                                               MissionObt current_obt) {
    
    #line 820 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    __status_int32_t status;
    #line 820 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status.__variant = Success;

    #line 821 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    TCVerifyStage verify_stage;
    #line 821 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    verify_stage.__variant = TCVerifyStage__ExecCompletion;

    #line 823 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    status = build_tm_1_X_u8_failure_data(p_tm_handler, tm_seq_counter,
                                          tc_packet_id, tc_packet_seq_ctrl,
                                          verify_stage,
                                          TM_1_8_TC_6_X_MEM_ACCESS_FAIL, mem_ID,
                                          current_obt);

    #line 826 "src/service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.fin"
    return status;

}
