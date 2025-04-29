
#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

const uint16_t informative_Ev_IDs = 3U;

const uint16_t low_severity_anomaly_Ev_IDs = 4U;

const uint16_t medium_severity_anomaly_Ev_IDs = 0U;

const uint16_t high_severity_anomaly_Ev_IDs = 16U;

const uint16_t offset_mask = 0x1FU;

PS5ExecTCReqStatusUpdate ps5_init_tc_req_status_update() {
    
    PS5ExecTCReqStatusUpdate ret;
    ret.EvID = 0U;
    ret.N = 0U;
    ret.packet_error_ctrl = 0U;
    ret.packet_id = 0U;
    ret.tc_num_bytes = 0U;

    return ret;

}

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
