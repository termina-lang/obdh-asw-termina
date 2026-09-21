
#include "service_libraries/pus_services/pus_service5/internal.h"

const uint16_t informative_Ev_IDs = 3U;

const uint16_t low_severity_anomaly_Ev_IDs = 4U;

const uint16_t medium_severity_anomaly_Ev_IDs = 0U;

const uint16_t high_severity_anomaly_Ev_IDs = 16U;

const uint16_t Ev_IDs_per_type[5U] = { 0U, informative_Ev_IDs, low_severity_anomaly_Ev_IDs, medium_severity_anomaly_Ev_IDs, high_severity_anomaly_Ev_IDs };

const uint16_t offset_mask = 0x1FU;

const uint16_t EvID_build_tm_error = 0x2100U;

Ev_IDType get_Ev_ID_type(uint16_t Ev_ID) {
    
    #line 65 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_IDType Ev_ID_type = { ._variant = Ev_IDType__Ev_IDNotValid };

    #line 66 "src/service_libraries/pus_services/pus_service5/internal.fin"
    uint16_t aux_type = Ev_ID >> 12U;

    #line 68 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (aux_type >= 1U && aux_type <= 4U) {
        
        #line 69 "src/service_libraries/pus_services/pus_service5/internal.fin"
        uint16_t aux_id = Ev_ID & 0xFFFU;

        #line 70 "src/service_libraries/pus_services/pus_service5/internal.fin"
        if (aux_id < Ev_IDs_per_type[termina__check__array_index(5U, (size_t)aux_type)]) {
            
            #line 71 "src/service_libraries/pus_services/pus_service5/internal.fin"
            if (aux_type == 1U) {
                
                #line 72 "src/service_libraries/pus_services/pus_service5/internal.fin"
                Ev_ID_type._variant = Ev_IDType__Informative;

            } else
            #line 73 "src/service_libraries/pus_services/pus_service5/internal.fin"
            if (aux_type == 2U) {
                
                #line 74 "src/service_libraries/pus_services/pus_service5/internal.fin"
                Ev_ID_type._variant = Ev_IDType__LowSeverityAnomaly;

            } else
            #line 75 "src/service_libraries/pus_services/pus_service5/internal.fin"
            if (aux_type == 3U) {
                
                #line 76 "src/service_libraries/pus_services/pus_service5/internal.fin"
                Ev_ID_type._variant = Ev_IDType__MediumSeverityAnomaly;

            } else
            {
                
                #line 78 "src/service_libraries/pus_services/pus_service5/internal.fin"
                Ev_ID_type._variant = Ev_IDType__HighSeverityAnomaly;

            }

        }

    }

    #line 83 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return Ev_ID_type;

}

_Bool is_Ev_ID_valid(uint16_t evID) {
    
    #line 89 "src/service_libraries/pus_services/pus_service5/internal.fin"
    _Bool is_valid = true;

    #line 90 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_IDType evID_type = get_Ev_ID_type(evID);

    #line 91 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (evID_type._variant == Ev_IDType__Ev_IDNotValid) {
        
        #line 92 "src/service_libraries/pus_services/pus_service5/internal.fin"
        is_valid = false;

    } else
    {
        

    }

    #line 96 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return is_valid;

}

size_t get_Ev_ID_enable_config_index(uint16_t Ev_ID) {
    
    #line 103 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_IDType Ev_ID_type = get_Ev_ID_type(Ev_ID);

    #line 104 "src/service_libraries/pus_services/pus_service5/internal.fin"
    size_t config_slot = 0U;

    #line 106 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type._variant == Ev_IDType__Informative) {
        
        #line 107 "src/service_libraries/pus_services/pus_service5/internal.fin"
        config_slot = 1U;

    } else
    #line 109 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type._variant == Ev_IDType__LowSeverityAnomaly) {
        
        #line 110 "src/service_libraries/pus_services/pus_service5/internal.fin"
        config_slot = 2U;

    } else
    #line 112 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type._variant == Ev_IDType__MediumSeverityAnomaly) {
        
        #line 113 "src/service_libraries/pus_services/pus_service5/internal.fin"
        config_slot = 3U;

    } else
    #line 115 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type._variant == Ev_IDType__HighSeverityAnomaly) {
        
        #line 116 "src/service_libraries/pus_services/pus_service5/internal.fin"
        config_slot = 4U;

    } else
    {
        

    }

    #line 122 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return config_slot;

}

uint8_t get_Ev_ID_enable_config_offset(uint16_t Ev_ID) {
    
    #line 127 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return (uint8_t)(uint16_t)(Ev_ID & offset_mask);

}

Status__i32 build_tm_5_x_param_out_of_limit(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, ParamOutOfLimitInfo fault_info, uint16_t ev_ID, MissionOBT current_obt) {
    
    #line 134 "src/service_libraries/pus_services/pus_service5/internal.fin"
    startup_tm(p_tm_handler);

    #line 135 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Status__i32 status = append_u16_appdata_field(p_tm_handler, ev_ID);

    #line 136 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 137 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, fault_info.PID);

    }

    #line 139 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 140 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_value);

    }

    #line 142 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 143 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_limit);

    }

    #line 145 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 146 "src/service_libraries/pus_services/pus_service5/internal.fin"
        uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

        #line 147 "src/service_libraries/pus_services/pus_service5/internal.fin"
        close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    }

    #line 150 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return status;

}

Status__i32 build_tm_5_x_param_check_value_fail(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, ParamFaultValueInfo fault_info, uint16_t ev_ID, MissionOBT current_obt) {
    
    #line 156 "src/service_libraries/pus_services/pus_service5/internal.fin"
    startup_tm(p_tm_handler);

    #line 157 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Status__i32 status = append_u16_appdata_field(p_tm_handler, ev_ID);

    #line 158 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 159 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, fault_info.PID);

    }

    #line 161 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 162 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_value);

    }

    #line 164 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 165 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_mask);

    }

    #line 167 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 168 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_expected_value);

    }

    #line 170 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 171 "src/service_libraries/pus_services/pus_service5/internal.fin"
        uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

        #line 172 "src/service_libraries/pus_services/pus_service5/internal.fin"
        close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    }

    #line 175 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return status;

}
