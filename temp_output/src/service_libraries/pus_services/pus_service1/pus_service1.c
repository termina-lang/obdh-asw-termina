
#include "service_libraries/pus_services/pus_service1/pus_service1.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor) {
    
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    TCExecutionCtrl exec_ctrl;
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlReboot;

    if (type == 9 || type == 17) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    } else if (type == 3 || type == 5 || type == 12 || type == 19) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

    } else if (type == 20) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

    } else if (type == 128) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlReboot;

    } else {
        

    }

    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor) {
    
    TCStatus status;
    status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
    status.error_code.__variant = TCErrorType__Undefined;
    status.execution_status.__variant = TCExecutionCtrl__Undefined;

    if (0 == is_crc_valid(tc_descriptor)) {
        
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        status.error_code.__variant = TCErrorType__CRCError;

    } else if (0 == is_apid_valid(tc_descriptor)) {
        
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        status.error_code.__variant = TCErrorType__APIDError;

    } else if (0 == is_sourceID_valid(tc_descriptor)) {
        
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        status.error_code.__variant = TCErrorType__SourceIDError;

    } else {
        
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        if (9 == type) {
            
            if (129 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (17 == type) {
            
            if (1 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (3 == type) {
            
            if (5 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (31 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (20 == type) {
            
            if (1 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else if (3 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (5 == type) {
            
            if (5 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (12 == type) {
            
            if (1 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (5 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (19 == type) {
            
            if (1 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (2 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (4 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (5 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (128 == type) {
            
            if (1 == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlReboot;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else {
            
            status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    return status;

}

void build_tm_1_1(TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length, 1, 1);

    return;

}

void build_tm_1_2(const TCStatus * const status,
                  TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * const tc_descriptor) {
    
    uint16_t error_code = 0;

    if ((*status).error_code.__variant == TCErrorType__Undefined) {
        

    } else if ((*status).error_code.__variant == TCErrorType__TypeError) {
        
        build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor,
                 base_length + 2, 1, 2);

        error_code = 5;

    } else if ((*status).error_code.__variant == TCErrorType__SubTypeError) {
        
        build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor,
                 base_length + 2, 1, 2);

        error_code = 6;

    } else if ((*status).error_code.__variant == TCErrorType__SourceIDError) {
        
        build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor,
                 base_length + 4, 1, 2);

        error_code = 4;

        uint8_t sourceID = get_source_id(tc_descriptor->tc_bytes);

        serialize_uint16((uint16_t)sourceID, &p_tm_descriptor->tm_bytes[16]);

    } else if ((*status).error_code.__variant == TCErrorType__CRCError) {
        
        build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor,
                 base_length + 6, 1, 2);

        error_code = 2;

        uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

        uint16_t calculated_crc = cal_crc_16(tc_descriptor->tc_bytes,
                                             tc_descriptor->tc_num_bytes - 2);

        serialize_uint16(packet_error_ctrl, &p_tm_descriptor->tm_bytes[16]);

        serialize_uint16(calculated_crc, &p_tm_descriptor->tm_bytes[18]);

    } else {
        
        build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor,
                 base_length + 2, 1, 2);

        error_code = 3;

    }

    serialize_uint16(error_code, &p_tm_descriptor->tm_bytes[14]);

    return;

}

void build_tm_1_7(TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length, 1, 7);

    return;

}

void build_tm_1_8_tc_3_X_SIDnotvalid(TMDescriptorT * const p_tm_descriptor,
                                     uint16_t tm_seq_counter, uint16_t SID,
                                     const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_3_X_invalid_SID, &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(SID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_20_X_PIDnotvalid(TMDescriptorT * const p_tm_descriptor,
                                      uint16_t tm_seq_counter, uint16_t PID,
                                      const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_20_X_invalid_PID,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_5_X_RIDunknown(TMDescriptorT * const p_tm_descriptor,
                                    uint16_t tm_seq_counter, uint16_t RID,
                                    const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_5_X_unknown_RID, &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(RID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_12_X_PMONIDundefined(TMDescriptorT * const p_tm_descriptor,
                                          uint16_t tm_seq_counter,
                                          uint16_t PMONID,
                                          const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_12_X_PMONID_undefined,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PMONID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_12_X_PMONIDdefined(TMDescriptorT * const p_tm_descriptor,
                                        uint16_t tm_seq_counter,
                                        uint16_t PMONID,
                                        const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_12_X_PMONID_defined,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PMONID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_12_X_PMONIDnotvalid(TMDescriptorT * const p_tm_descriptor,
                                         uint16_t tm_seq_counter,
                                         uint16_t PMONID,
                                         const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_12_X_invalid_PMONID,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PMONID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_19_X_event_action_enabled(TMDescriptorT * const p_tm_descriptor,
                                               uint16_t tm_seq_counter,
                                               uint16_t event_ID,
                                               const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_19_X_ev_action_is_enabled,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_19_1_max_event_actions(TMDescriptorT * const p_tm_descriptor,
                                            uint16_t tm_seq_counter,
                                            uint16_t event_ID,
                                            const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_19_1_max_ev_actions_reached,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_19_1_event_action_rejected(TMDescriptorT * const p_tm_descriptor,
                                                uint16_t tm_seq_counter,
                                                uint16_t event_ID,
                                                const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_19_1_ev_action_rejected,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    return;

}

void build_tm_1_8_tc_19_X_event_action_not_defined(TMDescriptorT * const p_tm_descriptor,
                                                   uint16_t tm_seq_counter,
                                                   uint16_t event_ID,
                                                   const TCDescriptorT * const tc_descriptor) {
    
    build_tm(p_tm_descriptor, tm_seq_counter, tc_descriptor, base_length + 4, 1,
             8);

    serialize_uint16(TM_1_8_TC_19_X_ev_action_not_defined,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    return;

}
