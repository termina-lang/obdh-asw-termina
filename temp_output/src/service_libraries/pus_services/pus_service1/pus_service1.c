
#include "service_libraries/pus_services/pus_service1/pus_service1.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor) {
    
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    TCExecutionCtrl exec_ctrl;
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlReboot;

    if (type == 9U || type == 17U) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    } else if (type == 3U || type == 5U || type == 12U || type == 19U) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

    } else if (type == 20U) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

    } else if (type == 128U) {
        
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

        if (9U == type) {
            
            if (129U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (17U == type) {
            
            if (1U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (3U == type) {
            
            if (5U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (31U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (20U == type) {
            
            if (1U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else if (3U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (5U == type) {
            
            if (5U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (12U == type) {
            
            if (1U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (5U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (6U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (19U == type) {
            
            if (1U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (2U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (4U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else if (5U == subtype) {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (128U == type) {
            
            if (1U == subtype) {
                
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
