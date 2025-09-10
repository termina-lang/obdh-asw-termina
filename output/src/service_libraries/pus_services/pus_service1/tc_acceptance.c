
#include "service_libraries/pus_services/pus_service1/tc_acceptance.h"

TCExecutionCtrl handle_tc(const TCDescriptor * const tc_descriptor) {
    
    #line 25 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    #line 26 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    TCExecutionCtrl exec_ctrl;
    #line 26 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    #line 28 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (type == 9U || type == 17U || type == 128U) {
        
        #line 30 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    } else
    #line 32 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (type == 3U || type == 5U || type == 12U || type == 19U) {
        
        #line 34 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

    } else
    #line 36 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (type == 20U) {
        
        #line 38 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

    } else
    {
        

    }

    #line 44 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptor * const tc_descriptor) {
    
    #line 65 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    TCStatus tc_status;
    #line 65 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
    #line 67 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    tc_status.error_code.__variant = TCErrorType__Undefined;
    #line 66 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

    #line 69 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (0 == is_crc_valid(tc_descriptor)) {
        
        #line 71 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 72 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.error_code.__variant = TCErrorType__CRCError;

    } else
    #line 74 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (0 == is_apid_valid(tc_descriptor)) {
        
        #line 76 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 77 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.error_code.__variant = TCErrorType__APIDError;

    } else
    #line 79 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (0 == is_sourceID_valid(tc_descriptor)) {
        
        #line 81 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 82 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.error_code.__variant = TCErrorType__SourceIDError;

    } else
    {
        
        #line 86 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        #line 87 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        #line 89 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (9U == type) {
            
            #line 91 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (129U == subtype) {
                
                #line 93 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 94 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 97 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 98 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 101 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (17U == type) {
            
            #line 103 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype) {
                
                #line 105 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 106 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 109 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 110 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 112 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (4U == type) {
            
            #line 114 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 6U == subtype || 7U == subtype) {
                
                #line 116 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 117 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 121 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 122 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 124 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (2U == type) {
            
            #line 126 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype) {
                
                #line 128 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 129 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 132 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 133 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 136 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (3U == type) {
            
            #line 138 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (5U == subtype || 6U == subtype || 31U == subtype) {
                
                #line 140 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 141 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 146 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 147 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 150 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (20U == type) {
            
            #line 152 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 3U == subtype) {
                
                #line 154 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 155 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 160 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 161 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 164 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (5U == type) {
            
            #line 166 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (5U == subtype || 6U == subtype) {
                
                #line 168 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 169 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 174 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 175 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 178 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (12U == type) {
            
            #line 180 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 5U == subtype || 6U == subtype) {
                
                #line 182 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 183 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 188 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 189 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 192 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (19U == type) {
            
            #line 194 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 2U == subtype || 4U == subtype || 5U == subtype) {
                
                #line 196 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 197 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 202 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 203 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 205 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (128U == type) {
            
            #line 207 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype) {
                
                #line 209 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 210 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 214 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 215 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 217 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (6U == type) {
            
            #line 219 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (2U == subtype || 5U == subtype || 9U == subtype) {
                
                #line 221 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 222 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 227 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 228 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        {
            
            #line 232 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            #line 233 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            tc_status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    #line 239 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    return tc_status;

}
