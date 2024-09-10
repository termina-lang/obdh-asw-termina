
#include "libraries/pus_services/pus_service1.h"

_Bool is_crc_valid(const TCDescriptorT * tc_descriptor) {
    
    uint16_t cal_crc_value = cal_crc_16(tc_descriptor->tc_bytes,
                                        tc_descriptor->tc_num_bytes - 2);

    uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    _Bool is_valid = cal_crc_value == packet_error_ctrl;

    return is_valid;

}

_Bool is_apid_valid(const TCDescriptorT * tc_descriptor) {
    
    uint16_t epd_apid = 0x32C;

    uint16_t tc_apid = get_APID(tc_descriptor->tc_bytes);

    _Bool is_valid = epd_apid == tc_apid;

    return is_valid;

}

_Bool is_sourceID_valid(const TCDescriptorT * tc_descriptor) {
    
    uint8_t Mission_TimeLine_SourceID = 110;

    uint8_t TC_Sequences_SourceID = 111;

    uint8_t Direct_Commands_SourceID = 120;

    uint8_t sourceID = get_source_id(tc_descriptor->tc_bytes);

    _Bool is_valid = Mission_TimeLine_SourceID == sourceID || TC_Sequences_SourceID == sourceID || Direct_Commands_SourceID == sourceID;

    return is_valid;

}

TCExecutionCtrl handle_tc(const TCDescriptorT * tc_descriptor) {
    
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

void try_tc_acceptation(TCStatus * status,
                        const TCDescriptorT * tc_descriptor) {
    
    (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

    if (0 == is_crc_valid(tc_descriptor)) {
        
        (*status).acceptation_status.__variant = TCAcceptationStatus__Rejected;

        (*status).error_code.__variant = TCErrorType__CRCError;

    } else if (0 == is_apid_valid(tc_descriptor)) {
        
        (*status).acceptation_status.__variant = TCAcceptationStatus__Rejected;

        (*status).error_code.__variant = TCErrorType__APIDError;

    } else if (0 == is_sourceID_valid(tc_descriptor)) {
        
        (*status).acceptation_status.__variant = TCAcceptationStatus__Rejected;

        (*status).error_code.__variant = TCErrorType__SourceIDError;

    } else {
        
        (*status).acceptation_status.__variant = TCAcceptationStatus__Rejected;

        (*status).error_code.__variant = TCErrorType__TypeError;

        uint8_t type = get_type(tc_descriptor->tc_bytes);

        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        if (9 == type) {
            
            if (129 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (17 == type) {
            
            if (1 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (3 == type) {
            
            if (5 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (31 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (20 == type) {
            
            if (1 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else if (3 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (5 == type) {
            
            if (5 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (12 == type) {
            
            if (1 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (5 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (19 == type) {
            
            if (1 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (2 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (4 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (5 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

        if (128 == type) {
            
            if (1 == subtype) {
                
                (*status).acceptation_status.__variant = TCAcceptationStatus__Accepted;

                (*status).execution_status.__variant = TCExecutionCtrl__ExecCtrlReboot;

            } else {
                
                (*status).error_code.__variant = TCErrorType__SubTypeError;

            }

        }

    }

    return;

}

void build_tm_1_1(TMDescriptorT * p_tm_descriptor, uint16_t tm_seq_counter,
                  const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 0x7;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 1;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_2(const TCStatus * status, TMDescriptorT * p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * tc_descriptor) {
    
    CCSDSPUSTMPacketHeaderT tm_packet_header;
    tm_packet_header.packet_id = 0;
    tm_packet_header.packet_length = 0;
    tm_packet_header.packet_seq_ctrl = 0;

    CCSDSPUSTMDFHeaderT df_header;
    df_header.destinationID = 0;
    df_header.subtype = 0;
    df_header.type = 0;
    df_header.version = 0;

    uint16_t error_code = 0;

    uint16_t tc_packet_id = get_packet_id(tc_descriptor->tc_bytes);

    uint16_t tc_packet_seq_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

    tm_packet_header.packet_id = ccsds_pus_tm_build_packet_id(0x32C);

    tm_packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3,
                                                                          tm_seq_counter);

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 2;

    df_header.destinationID = 0x78;

    if ((*status).error_code.__variant == TCErrorType__TypeError) {
        
        tm_packet_header.packet_length = 9;

        error_code = 5;

    } else if ((*status).error_code.__variant == TCErrorType__SubTypeError) {
        
        tm_packet_header.packet_length = 9;

        error_code = 6;

    } else if ((*status).error_code.__variant == TCErrorType__SourceIDError) {
        
        tm_packet_header.packet_length = 11;

        error_code = 4;

        uint8_t sourceID = get_source_id(tc_descriptor->tc_bytes);

        serialize_uint16((uint16_t)sourceID, &p_tm_descriptor->tm_bytes[16]);

    } else if ((*status).error_code.__variant == TCErrorType__CRCError) {
        
        tm_packet_header.packet_length = 13;

        error_code = 2;

        uint16_t packet_error_ctrl = get_packet_seq_ctrl(tc_descriptor->tc_bytes);

        uint16_t calculated_crc = cal_crc_16(tc_descriptor->tc_bytes,
                                             tc_descriptor->tc_num_bytes - 2);

        serialize_uint16(packet_error_ctrl, &p_tm_descriptor->tm_bytes[16]);

        serialize_uint16(calculated_crc, &p_tm_descriptor->tm_bytes[18]);

    } else {
        
        tm_packet_header.packet_length = 9;

        error_code = 3;

    }

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(error_code, &p_tm_descriptor->tm_bytes[14]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_7(TMDescriptorT * p_tm_descriptor, uint16_t tm_seq_counter,
                  const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 0x7;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 7;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_3_X_SIDnotvalid(TMDescriptorT * p_tm_descriptor,
                                     uint16_t tm_seq_counter, uint16_t SID,
                                     const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_3_X_invalid_SID, &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(SID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_20_X_PIDnotvalid(TMDescriptorT * p_tm_descriptor,
                                      uint16_t tm_seq_counter, uint16_t PID,
                                      const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_20_X_invalid_PID,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_5_X_RIDunknown(TMDescriptorT * p_tm_descriptor,
                                    uint16_t tm_seq_counter, uint16_t RID,
                                    const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_5_X_unknown_RID, &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(RID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_12_X_PMONIDundefined(TMDescriptorT * p_tm_descriptor,
                                          uint16_t tm_seq_counter,
                                          uint16_t PMONID,
                                          const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_12_X_PMONID_undefined,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PMONID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_12_X_PMONIDdefined(TMDescriptorT * p_tm_descriptor,
                                        uint16_t tm_seq_counter,
                                        uint16_t PMONID,
                                        const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_12_X_PMONID_defined,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PMONID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_12_X_PMONIDnotvalid(TMDescriptorT * p_tm_descriptor,
                                         uint16_t tm_seq_counter,
                                         uint16_t PMONID,
                                         const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_12_X_invalid_PMONID,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(PMONID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_19_X_event_action_enabled(TMDescriptorT * p_tm_descriptor,
                                               uint16_t tm_seq_counter,
                                               uint16_t event_ID,
                                               const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_19_X_ev_action_is_enabled,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_19_1_max_event_actions(TMDescriptorT * p_tm_descriptor,
                                            uint16_t tm_seq_counter,
                                            uint16_t event_ID,
                                            const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_19_1_max_ev_actions_reached,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_19_1_event_action_rejected(TMDescriptorT * p_tm_descriptor,
                                                uint16_t tm_seq_counter,
                                                uint16_t event_ID,
                                                const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_19_1_ev_action_rejected,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}

void build_tm_1_8_tc_19_X_event_action_not_defined(TMDescriptorT * p_tm_descriptor,
                                                   uint16_t tm_seq_counter,
                                                   uint16_t event_ID,
                                                   const TCDescriptorT * tc_descriptor) {
    
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

    tm_packet_header.packet_length = 11;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 1;

    df_header.subtype = 8;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16(tc_packet_id, &p_tm_descriptor->tm_bytes[10]);

    serialize_uint16(tc_packet_seq_ctrl, &p_tm_descriptor->tm_bytes[12]);

    serialize_uint16(TM_1_8_TC_19_X_ev_action_not_defined,
                     &p_tm_descriptor->tm_bytes[14]);

    serialize_uint16(event_ID, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = tm_packet_header.packet_length + 7;

    return;

}
