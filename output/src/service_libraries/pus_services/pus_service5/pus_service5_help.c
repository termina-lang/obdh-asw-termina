
#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

const uint16_t informative_Ev_IDs = 3U;

const uint16_t low_severity_anomaly_Ev_IDs = 4U;

const uint16_t medium_severity_anomaly_Ev_IDs = 0U;

const uint16_t high_severity_anomaly_Ev_IDs = 16U;

const uint16_t offset_mask = 0x1FU;

const uint16_t EvID_build_tm_error = 0x2100U;

Ev_IDType get_Ev_ID_type(uint16_t Ev_ID) {
    
    Ev_IDType Ev_ID_type;
    Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

    uint16_t aux_type = Ev_ID >> 12U;

    uint16_t aux_id = Ev_ID & 0xFFFU;

    if (aux_type == 1U) {
        
        if (aux_id < informative_Ev_IDs) {
            
            Ev_ID_type.__variant = Ev_IDType__Informative;

        } else {
            
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else if (aux_type == 2U) {
        
        if (aux_id < low_severity_anomaly_Ev_IDs) {
            
            Ev_ID_type.__variant = Ev_IDType__LowSeverityAnomaly;

        } else {
            
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else if (aux_type == 3U) {
        
        if (aux_id < medium_severity_anomaly_Ev_IDs) {
            
            Ev_ID_type.__variant = Ev_IDType__MediumSeverityAnomaly;

        } else {
            
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else if (aux_type == 4U) {
        
        if (aux_id < high_severity_anomaly_Ev_IDs) {
            
            Ev_ID_type.__variant = Ev_IDType__HighSeverityAnomaly;

        } else {
            
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else {
        
        Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

    }

    return Ev_ID_type;

}

_Bool is_Ev_ID_valid(uint16_t evID) {
    
    _Bool is_valid = 1;

    Ev_IDType evID_type = get_Ev_ID_type(evID);

    if (evID_type.__variant == Ev_IDType__Ev_IDNotValid) {
        
        is_valid = 0;

    } else {
        

    }

    return is_valid;

}

size_t get_Ev_ID_enable_config_index(uint16_t Ev_ID) {
    
    Ev_IDType Ev_ID_type = get_Ev_ID_type(Ev_ID);

    size_t index = 4U;

    if (Ev_ID_type.__variant == Ev_IDType__Informative) {
        
        index = 0U;

    } else if (Ev_ID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
        
        index = 1U;

    } else if (Ev_ID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
        
        index = 2U;

    } else if (Ev_ID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
        
        index = 3U;

    } else {
        
        index = 4U;

    }

    return index;

}

uint8_t get_Ev_ID_enable_config_offset(uint16_t Ev_ID) {
    
    return (uint8_t)(Ev_ID & offset_mask);

}

void build_tm_5_x_param_out_of_limit(TMHandlerT * const p_tm_handler,
                                     uint16_t tm_seq_counter,
                                     ParamOutOfLimitInfo fault_info,
                                     uint16_t ev_ID, MissionObt current_obt,
                                     __status_int32_t * const status) {
    
    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, ev_ID, status);

    append_u16_appdata_field(p_tm_handler, fault_info.PID, status);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, status);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_limit, status);

    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    return;

}

void build_tm_5_x_param_check_value_fail(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         ParamFaultValueInfo fault_info,
                                         uint16_t ev_ID, MissionObt current_obt,
                                         __status_int32_t * const status) {
    
    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler, ev_ID, status);

    append_u16_appdata_field(p_tm_handler, fault_info.PID, status);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, status);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_mask, status);

    append_u32_appdata_field(p_tm_handler, fault_info.PID_expected_value,
                             status);

    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    return;

}
