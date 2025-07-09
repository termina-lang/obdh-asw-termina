
#include "service_libraries/pus_services/pus_service1/pus_service1.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor) {
    
    #line 28 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    uint8_t type = get_type(tc_descriptor->tc_bytes);

    #line 29 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    TCExecutionCtrl exec_ctrl;
    #line 29 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    #line 31 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 9U || type == 17U || type == 128U) {
        
        #line 33 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

    } else
    #line 35 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 3U || type == 5U || type == 12U || type == 19U) {
        
        #line 37 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

    } else
    #line 39 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (type == 20U) {
        
        #line 41 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        exec_ctrl.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

    } else
    {
        

    }

    #line 47 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    return exec_ctrl;

}

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor) {
    
    #line 68 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    TCStatus tc_status;
    #line 68 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    tc_status.acceptation_status.__variant = TCAcceptationStatus__Undefined;
    #line 70 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    tc_status.error_code.__variant = TCErrorType__Undefined;
    #line 69 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    tc_status.execution_status.__variant = TCExecutionCtrl__Undefined;

    #line 72 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_crc_valid(tc_descriptor)) {
        
        #line 74 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 75 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        tc_status.error_code.__variant = TCErrorType__CRCError;

    } else
    #line 77 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_apid_valid(tc_descriptor)) {
        
        #line 79 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 80 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        tc_status.error_code.__variant = TCErrorType__APIDError;

    } else
    #line 82 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    if (0 == is_sourceID_valid(tc_descriptor)) {
        
        #line 84 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

        #line 85 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        tc_status.error_code.__variant = TCErrorType__SourceIDError;

    } else
    {
        
        #line 89 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        uint8_t type = get_type(tc_descriptor->tc_bytes);

        #line 90 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

        #line 92 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (9U == type) {
            
            #line 94 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (129U == subtype) {
                
                #line 96 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 97 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 100 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 101 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 104 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (17U == type) {
            
            #line 106 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 108 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 109 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 112 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 113 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 115 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (4U == type) {
            
            #line 117 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 6U == subtype || 7U == subtype) {
                
                #line 119 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 120 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 124 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 125 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 127 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (2U == type) {
            
            #line 129 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 131 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 132 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 135 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 136 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 139 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (3U == type) {
            
            #line 141 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (5U == subtype || 6U == subtype || 31U == subtype) {
                
                #line 143 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 144 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 149 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 150 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 153 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (20U == type) {
            
            #line 155 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 3U == subtype) {
                
                #line 157 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 158 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 163 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 164 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 167 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (5U == type) {
            
            #line 169 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (5U == subtype || 6U == subtype) {
                
                #line 171 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 172 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 177 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 178 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 181 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (12U == type) {
            
            #line 183 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 5U == subtype || 6U == subtype) {
                
                #line 185 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 186 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 191 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 192 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 195 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (19U == type) {
            
            #line 197 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype || 2U == subtype || 4U == subtype
                || 5U == subtype) {
                
                #line 199 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 200 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlHK_FDIRTC;

            } else
            {
                
                #line 205 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 206 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 208 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (128U == type) {
            
            #line 210 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (1U == subtype) {
                
                #line 212 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 213 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlPrioTC;

            } else
            {
                
                #line 217 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 218 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        #line 220 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
        if (6U == type) {
            
            #line 222 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            if (2U == subtype || 5U == subtype || 9U == subtype) {
                
                #line 224 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Accepted;

                #line 225 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.execution_status.__variant = TCExecutionCtrl__ExecCtrlBKGTC;

            } else
            {
                
                #line 230 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

                #line 231 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
                tc_status.error_code.__variant = TCErrorType__SubTypeError;

            }

        } else
        {
            
            #line 235 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            tc_status.acceptation_status.__variant = TCAcceptationStatus__Rejected;

            #line 236 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
            tc_status.error_code.__variant = TCErrorType__TypeError;

        }

    }

    #line 242 "src/service_libraries/pus_services/pus_service1/pus_service1.fin"
    return tc_status;

}
