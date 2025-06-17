
#include "service_libraries/pus_services/pus_service1/pus_service1.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor) {
    
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    TCExecutionCtrl exec_ctrl;
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    if (type == 9U || type == 17U || type == 128U) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    } else if (type == 3U || type == 5U || type == 12U || type == 19U) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

    } else if (type == 20U) {
        
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

    } else {
        

    }

    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor) {
    
    TCStatus tc_status;
    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
    tc_status.error_code.__variant = TCErrorType__Undefined;
    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

    if (0 == is_crc_valid(tc_descriptor)) {
        
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        tc_status.error_code.__variant = TCErrorType__CRCError;

    } else if (0 == is_apid_valid(tc_descriptor)) {
        
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        tc_status.error_code.__variant = TCErrorType__APIDError;

    } else if (0 == is_sourceID_valid(tc_descriptor)) {
        
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        tc_status.error_code.__variant = TCErrorType__SourceIDError;

    } else {
        
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        if (9U == type) {
            
            if (129U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (17U == type) {
            
            if (1U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (4U == type) {
            
            if (1U == subtype || 6U == subtype || 7U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (2U == type) {
            
            if (1U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (3U == type) {
            
            if (5U == subtype || 6U == subtype || 31U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (20U == type) {
            
            if (1U == subtype || 3U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (5U == type) {
            
            if (5U == subtype || 6U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (12U == type) {
            
            if (1U == subtype || 5U == subtype || 6U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (19U == type) {
            
            if (1U == subtype || 2U == subtype || 4U == subtype || 5U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else if (128U == type) {
            
            if (1U == subtype) {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else {
                
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else {
            
            tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            tc_status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    return tc_status;

}
