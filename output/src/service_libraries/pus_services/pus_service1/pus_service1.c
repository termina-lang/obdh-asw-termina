
#include "service_libraries/pus_services/pus_service1/pus_service1.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor) {
    
    #line 11 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    #line 12 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    TCExecutionCtrl exec_ctrl;
    #line 12 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlReboot;

    #line 14 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 9U || type == 17U) {
        
        #line 16 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    } else
    #line 18 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 3U || type == 5U || type == 12U || type == 19U) {
        
        #line 20 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

    } else
    #line 22 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 20U) {
        
        #line 24 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

    } else
    #line 26 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 128U) {
        
        #line 28 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlReboot;

    } else
    {
        

    }

    #line 34 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor) {
    
    #line 39 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    TCStatus status;
    #line 39 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
    #line 41 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    status.error_code.__variant = TCErrorType__Undefined;
    #line 40 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    status.execution_status.__variant = TCExecutionCtrl__Undefined;

    #line 43 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_crc_valid(tc_descriptor)) {
        
        #line 45 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 46 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.error_code.__variant = TCErrorType__CRCError;

    } else
    #line 48 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_apid_valid(tc_descriptor)) {
        
        #line 50 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 51 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.error_code.__variant = TCErrorType__APIDError;

    } else
    #line 53 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_sourceID_valid(tc_descriptor)) {
        
        #line 55 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 56 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.error_code.__variant = TCErrorType__SourceIDError;

    } else
    {
        
        #line 60 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        #line 61 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        #line 63 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (9U == type) {
            
            #line 65 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (129U == subtype) {
                
                #line 67 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 68 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 71 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 72 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 75 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (17U == type) {
            
            #line 77 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 79 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 80 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 83 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 84 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 86 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (4U == type) {
            
            #line 88 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 6U == subtype || 7U == subtype) {
                
                #line 90 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 91 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 95 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 96 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 98 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (2U == type) {
            
            #line 100 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 102 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 103 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 106 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 107 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 110 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (3U == type) {
            
            #line 112 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (5U == subtype || 6U == subtype || 31U == subtype) {
                
                #line 114 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 115 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 120 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 121 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 124 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (20U == type) {
            
            #line 126 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 3U == subtype) {
                
                #line 128 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 129 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 134 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 135 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 138 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (5U == type) {
            
            #line 140 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (5U == subtype || 6U == subtype) {
                
                #line 142 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 143 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 148 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 149 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 152 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (12U == type) {
            
            #line 154 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 5U == subtype || 6U == subtype) {
                
                #line 156 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 157 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 162 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 163 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 166 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (19U == type) {
            
            #line 168 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 2U == subtype || 4U == subtype || 5U == subtype) {
                
                #line 170 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 171 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 176 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 177 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 179 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (128U == type) {
            
            #line 181 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 183 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 184 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlReboot;

            } else
            {
                
                #line 188 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 189 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        {
            
            #line 193 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            #line 194 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    #line 200 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    return status;

}
