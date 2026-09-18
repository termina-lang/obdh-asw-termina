
#include "service_libraries/pus_services/pus_service1/tc_acceptance.h"

TCExecutionCtrl handle_tc(const TCDescriptor * const tc_descriptor) {
    
    #line 25 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    #line 26 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    TCExecutionCtrl exec_ctrl;

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
        
        #line 43 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        exec_ctrl.__variant = TCExecutionCtrl__Undefined;

    }

    #line 46 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptor * const tc_descriptor) {
    
    #line 67 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    TCStatus tc_status = { .acceptation_status = { .__variant = TCAcceptationStatus__Rejected }, .error_code = { .__variant = TCErrorType__Undefined }, .execution_status = { .__variant = TCExecutionCtrl__Undefined } };

    #line 71 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (false == is_crc_valid(tc_descriptor)) {
        
        #line 73 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 74 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.error_code.__variant = TCErrorType__CRCError;

    } else
    #line 76 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (false == is_apid_valid(tc_descriptor)) {
        
        #line 78 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 79 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.error_code.__variant = TCErrorType__APIDError;

    } else
    #line 81 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    if (false == is_sourceID_valid(tc_descriptor)) {
        
        #line 83 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 84 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        tc_status.error_code.__variant = TCErrorType__SourceIDError;

    } else
    {
        
        #line 88 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        #line 89 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        #line 91 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (9U == type) {
            
            #line 93 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (129U == subtype) {
                
                #line 95 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 96 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 99 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 100 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 103 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (17U == type) {
            
            #line 105 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype) {
                
                #line 107 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 108 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 111 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 112 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 114 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (4U == type) {
            
            #line 116 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 6U == subtype || 7U == subtype) {
                
                #line 118 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 119 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 123 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 124 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 126 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (2U == type) {
            
            #line 128 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype) {
                
                #line 130 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 131 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 134 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 135 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 138 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (3U == type) {
            
            #line 140 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (5U == subtype || 6U == subtype || 31U == subtype) {
                
                #line 142 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 143 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 148 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 149 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 152 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (20U == type) {
            
            #line 154 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 3U == subtype) {
                
                #line 156 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 157 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 162 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 163 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 166 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (5U == type) {
            
            #line 168 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (5U == subtype || 6U == subtype) {
                
                #line 170 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 171 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 176 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 177 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 180 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (12U == type) {
            
            #line 182 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 2U == subtype || 5U == subtype || 6U == subtype) {
                
                #line 184 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 185 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 190 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 191 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 194 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (19U == type) {
            
            #line 196 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype || 2U == subtype || 4U == subtype || 5U == subtype) {
                
                #line 198 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 199 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 204 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 205 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 207 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (128U == type) {
            
            #line 209 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (1U == subtype) {
                
                #line 211 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 212 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 216 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 217 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 219 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
        if (6U == type) {
            
            #line 221 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            if (2U == subtype || 5U == subtype || 9U == subtype) {
                
                #line 223 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 224 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 229 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 230 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        {
            
            #line 234 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            #line 235 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
            tc_status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    #line 241 "src/service_libraries/pus_services/pus_service1/tc_acceptance.fin"
    return tc_status;

}
