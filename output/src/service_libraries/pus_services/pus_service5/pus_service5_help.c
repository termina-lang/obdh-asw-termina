
#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

const uint16_t informative_Ev_IDs = 3U;

const uint16_t low_severity_anomaly_Ev_IDs = 4U;

const uint16_t medium_severity_anomaly_Ev_IDs = 0U;

const uint16_t high_severity_anomaly_Ev_IDs = 16U;

const uint16_t offset_mask = 0x1FU;

const uint16_t EvID_build_tm_error = 0x2100U;

Ev_IDType get_Ev_ID_type(uint16_t Ev_ID) {
    
    #line 67 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    Ev_IDType Ev_ID_type;
    #line 67 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

    #line 68 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    uint16_t aux_type = Ev_ID >> 12U;

    #line 69 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    uint16_t aux_id = Ev_ID & 0xFFFU;

    #line 71 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (aux_type == 1U) {
        
        #line 72 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        if (aux_id < informative_Ev_IDs) {
            
            #line 73 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__Informative;

        } else
        {
            
            #line 75 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    #line 77 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (aux_type == 2U) {
        
        #line 78 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        if (aux_id < low_severity_anomaly_Ev_IDs) {
            
            #line 79 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__LowSeverityAnomaly;

        } else
        {
            
            #line 81 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    #line 83 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (aux_type == 3U) {
        
        #line 84 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        if (aux_id < medium_severity_anomaly_Ev_IDs) {
            
            #line 85 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__MediumSeverityAnomaly;

        } else
        {
            
            #line 87 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    #line 89 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (aux_type == 4U) {
        
        #line 90 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        if (aux_id < high_severity_anomaly_Ev_IDs) {
            
            #line 91 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__HighSeverityAnomaly;

        } else
        {
            
            #line 93 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
            Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

        }

    } else
    {
        
        #line 96 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        Ev_ID_type.__variant = Ev_IDType__Ev_IDNotValid;

    }

    #line 99 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    return Ev_ID_type;

}

_Bool is_Ev_ID_valid(uint16_t evID) {
    
    #line 105 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    _Bool is_valid = 1;

    #line 106 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    Ev_IDType evID_type = get_Ev_ID_type(evID);

    #line 107 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (evID_type.__variant == Ev_IDType__Ev_IDNotValid) {
        
        #line 108 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        is_valid = 0;

    } else
    {
        

    }

    #line 112 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    return is_valid;

}

size_t get_Ev_ID_enable_config_index(uint16_t Ev_ID) {
    
    #line 119 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    Ev_IDType Ev_ID_type = get_Ev_ID_type(Ev_ID);

    #line 120 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    size_t index = 4U;

    #line 122 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (Ev_ID_type.__variant == Ev_IDType__Informative) {
        
        #line 123 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        index = 0U;

    } else
    #line 125 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (Ev_ID_type.__variant == Ev_IDType__LowSeverityAnomaly) {
        
        #line 126 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        index = 1U;

    } else
    #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (Ev_ID_type.__variant == Ev_IDType__MediumSeverityAnomaly) {
        
        #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        index = 2U;

    } else
    #line 131 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    if (Ev_ID_type.__variant == Ev_IDType__HighSeverityAnomaly) {
        
        #line 132 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        index = 3U;

    } else
    {
        
        #line 135 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
        index = 4U;

    }

    #line 139 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    return index;

}

uint8_t get_Ev_ID_enable_config_offset(uint16_t Ev_ID) {
    
    #line 144 "src/service_libraries/pus_services/pus_service5/pus_service5_help.fin"
    return (uint8_t)(Ev_ID & offset_mask);

}
