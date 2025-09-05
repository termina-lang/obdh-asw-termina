
#include "service_libraries/pus_services/pus_service5/internal.h"

const uint16_t informative_Ev_IDs = 3U;

const uint16_t low_severity_anomaly_Ev_IDs = 4U;

const uint16_t medium_severity_anomaly_Ev_IDs = 0U;

const uint16_t high_severity_anomaly_Ev_IDs = 16U;

const uint16_t offset_mask = 0x1FU;

const uint16_t EvID_build_tm_error = 0x2100U;

Ev_IDType get_Ev_ID_type(uint16_t Ev_ID) {
    
    #line 61 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_IDType Ev_ID_type;
    #line 61 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

    #line 62 "src/service_libraries/pus_services/pus_service5/internal.fin"
    uint16_t aux_type = Ev_ID >> 12U;

    #line 63 "src/service_libraries/pus_services/pus_service5/internal.fin"
    uint16_t aux_id = Ev_ID & 0xFFFU;

    #line 65 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (aux_type == 1U) {
        
        #line 66 "src/service_libraries/pus_services/pus_service5/internal.fin"
        if (aux_id < informative_Ev_IDs) {
            
            #line 67 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__Informative;

        } else
        {
            
            #line 69 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    #line 71 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (aux_type == 2U) {
        
        #line 72 "src/service_libraries/pus_services/pus_service5/internal.fin"
        if (aux_id < low_severity_anomaly_Ev_IDs) {
            
            #line 73 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__LowSeverityAnomaly;

        } else
        {
            
            #line 75 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    #line 77 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (aux_type == 3U) {
        
        #line 78 "src/service_libraries/pus_services/pus_service5/internal.fin"
        if (aux_id < medium_severity_anomaly_Ev_IDs) {
            
            #line 79 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__MediumSeverityAnomaly;

        } else
        {
            
            #line 81 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    #line 83 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (aux_type == 4U) {
        
        #line 84 "src/service_libraries/pus_services/pus_service5/internal.fin"
        if (aux_id < high_severity_anomaly_Ev_IDs) {
            
            #line 85 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__HighSeverityAnomaly;

        } else
        {
            
            #line 87 "src/service_libraries/pus_services/pus_service5/internal.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    {
        
        #line 90 "src/service_libraries/pus_services/pus_service5/internal.fin"
        Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

    }

    #line 93 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return Ev_ID_type;

}

_Bool is_Ev_ID_valid(uint16_t evID) {
    
    #line 99 "src/service_libraries/pus_services/pus_service5/internal.fin"
    _Bool is_valid = 1;

    #line 100 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_IDType evID_type = get_Ev_ID_type(evID);

    #line 101 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (evID_type.__variant == Ev_IDType__Ev_IDNotValid) {
        
        #line 102 "src/service_libraries/pus_services/pus_service5/internal.fin"
        is_valid = 0;

    } else
    {
        

    }

    #line 106 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return is_valid;

}

size_t get_Ev_ID_enable_config_index(uint16_t Ev_ID) {
    
    #line 113 "src/service_libraries/pus_services/pus_service5/internal.fin"
    Ev_IDType Ev_ID_type = get_Ev_ID_type(Ev_ID);

    #line 114 "src/service_libraries/pus_services/pus_service5/internal.fin"
    size_t index = 0U;

    #line 116 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type.__variant == Ev_IDType__Informative) {
        
        #line 117 "src/service_libraries/pus_services/pus_service5/internal.fin"
        index = 1U;

    } else
    #line 119 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
        
        #line 120 "src/service_libraries/pus_services/pus_service5/internal.fin"
        index = 2U;

    } else
    #line 122 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
        
        #line 123 "src/service_libraries/pus_services/pus_service5/internal.fin"
        index = 3U;

    } else
    #line 125 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (Ev_ID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
        
        #line 126 "src/service_libraries/pus_services/pus_service5/internal.fin"
        index = 4U;

    } else
    {
        
        #line 129 "src/service_libraries/pus_services/pus_service5/internal.fin"
        index = 0U;

    }

    #line 133 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return index;

}

uint8_t get_Ev_ID_enable_config_offset(uint16_t Ev_ID) {
    
    #line 138 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return (uint8_t)(Ev_ID & offset_mask);

}

__status_int32_t build_tm_5_x_param_out_of_limit(TMHandler * const p_tm_handler,
                                                 uint16_t tm_seq_counter,
                                                 ParamOutOfLimitInfo fault_info,
                                                 uint16_t ev_ID,
                                                 MissionOBT current_obt) {
    
    #line 145 "src/service_libraries/pus_services/pus_service5/internal.fin"
    __status_int32_t status;
    #line 145 "src/service_libraries/pus_services/pus_service5/internal.fin"
    status.__variant = Success;

    #line 147 "src/service_libraries/pus_services/pus_service5/internal.fin"
    startup_tm(p_tm_handler);

    #line 148 "src/service_libraries/pus_services/pus_service5/internal.fin"
    status = append_u16_appdata_field(p_tm_handler, ev_ID);

    #line 149 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 150 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, fault_info.PID);

    }

    #line 152 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 153 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_value);

    }

    #line 155 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 156 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_limit);

    }

    #line 158 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 159 "src/service_libraries/pus_services/pus_service5/internal.fin"
        uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

        #line 160 "src/service_libraries/pus_services/pus_service5/internal.fin"
        close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    }

    #line 163 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return status;

}

__status_int32_t build_tm_5_x_param_check_value_fail(TMHandler * const p_tm_handler,
                                                     uint16_t tm_seq_counter,
                                                     ParamFaultValueInfo fault_info,
                                                     uint16_t ev_ID,
                                                     MissionOBT current_obt) {
    
    #line 169 "src/service_libraries/pus_services/pus_service5/internal.fin"
    __status_int32_t status;
    #line 169 "src/service_libraries/pus_services/pus_service5/internal.fin"
    status.__variant = Success;

    #line 171 "src/service_libraries/pus_services/pus_service5/internal.fin"
    startup_tm(p_tm_handler);

    #line 172 "src/service_libraries/pus_services/pus_service5/internal.fin"
    status = append_u16_appdata_field(p_tm_handler, ev_ID);

    #line 173 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 174 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, fault_info.PID);

    }

    #line 176 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 177 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_value);

    }

    #line 179 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 180 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, fault_info.PID_mask);

    }

    #line 182 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 183 "src/service_libraries/pus_services/pus_service5/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          fault_info.PID_expected_value);

    }

    #line 185 "src/service_libraries/pus_services/pus_service5/internal.fin"
    if (status.__variant == Success) {
        
        #line 186 "src/service_libraries/pus_services/pus_service5/internal.fin"
        uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

        #line 187 "src/service_libraries/pus_services/pus_service5/internal.fin"
        close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    }

    #line 190 "src/service_libraries/pus_services/pus_service5/internal.fin"
    return status;

}
