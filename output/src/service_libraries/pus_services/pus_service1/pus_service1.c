
#include "service_libraries/pus_services/pus_service1/pus_service1.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor) {
    
    #line 11 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    #line 12 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    TCExecutionCtrl exec_ctrl;
    #line 12 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    #line 14 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 9U || type == 17U || type == 128U) {
        
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
    {
        

    }

    #line 30 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor) {
    
    #line 35 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    TCStatus status;
    #line 35 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
    #line 37 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    status.error_code.__variant = TCErrorType__Undefined;
    #line 36 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    status.execution_status.__variant = TCExecutionCtrl__Undefined;

    #line 39 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_crc_valid(tc_descriptor)) {
        
        #line 41 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 42 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.error_code.__variant = TCErrorType__CRCError;

    } else
    #line 44 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_apid_valid(tc_descriptor)) {
        
        #line 46 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 47 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.error_code.__variant = TCErrorType__APIDError;

    } else
    #line 49 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_sourceID_valid(tc_descriptor)) {
        
        #line 51 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 52 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        status.error_code.__variant = TCErrorType__SourceIDError;

    } else
    {
        
        #line 56 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        #line 57 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        #line 59 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (9U == type) {
            
            #line 61 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (129U == subtype) {
                
                #line 63 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 64 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 67 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 68 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 71 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (17U == type) {
            
            #line 73 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 75 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 76 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 79 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 80 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 82 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (4U == type) {
            
            #line 84 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 6U == subtype || 7U == subtype) {
                
                #line 86 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 87 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 91 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 92 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 94 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (2U == type) {
            
            #line 96 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 98 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 99 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 102 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 103 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 106 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (3U == type) {
            
            #line 108 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (5U == subtype || 6U == subtype || 31U == subtype) {
                
                #line 110 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 111 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 116 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 117 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 120 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (20U == type) {
            
            #line 122 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 3U == subtype) {
                
                #line 124 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 125 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 130 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 131 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 134 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (5U == type) {
            
            #line 136 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (5U == subtype || 6U == subtype) {
                
                #line 138 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 139 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 144 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 145 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 148 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (12U == type) {
            
            #line 150 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 5U == subtype || 6U == subtype) {
                
                #line 152 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 153 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 158 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 159 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 162 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (19U == type) {
            
            #line 164 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 2U == subtype || 4U == subtype || 5U == subtype) {
                
                #line 166 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 167 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 172 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 173 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 175 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (128U == type) {
            
            #line 177 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 179 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 180 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 184 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 185 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        {
            
            #line 189 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            #line 190 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    #line 196 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    return status;

}
