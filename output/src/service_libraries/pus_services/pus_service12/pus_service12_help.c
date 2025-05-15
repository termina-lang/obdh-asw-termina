
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

uint8_t get_check_status_index(CheckState status) {
    
    uint8_t index = 0U;

    if (status.__variant == CheckState__ParamValueStatus) {
        
        CheckValueStatus param_status = status.ParamValueStatus.__0;

        if (param_status.__variant == CheckValueStatus__MonitorUnchecked) {
            
            index = 1U;

        } else if (param_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
            
            index = 2U;

        } else {
            
            index = 3U;

        }

    } else if (status.__variant == CheckState__ParamLimitStatus) {
        
        CheckLimitsStatus limit_status = status.ParamLimitStatus.__0;

        if (limit_status.__variant == CheckLimitsStatus__MonitorUnchecked) {
            
            index = 4U;

        } else if (limit_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
            
            index = 5U;

        } else if (limit_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
            
            index = 6U;

        } else {
            
            index = 7U;

        }

    } else if (status.__variant == CheckState__ParamDeltaStatus) {
        
        CheckDeltaStatus delta_status = status.ParamDeltaStatus.__0;

        if (delta_status.__variant == CheckDeltaStatus__MonitorUnchecked) {
            
            index = 8U;

        } else if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaLow) {
            
            index = 9U;

        } else if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaHigh) {
            
            index = 10U;

        } else {
            
            index = 11U;

        }

    } else {
        
        index = 0U;

    }

    return index;

}

uint8_t get_type_index(MonitorCheckType type) {
    
    uint8_t index = 0U;

    if (type.__variant == MonitorCheckType__ExpectedValue) {
        
        index = 0U;

    } else if (type.__variant == MonitorCheckType__Limits) {
        
        index = 1U;

    } else if (type.__variant == MonitorCheckType__Delta) {
        
        index = 2U;

    } else {
        
        index = 0xFFU;

    }

    return index;

}

_Bool are_status_equal(CheckState status1, CheckState status2) {
    
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    return equal;

}

MonitorCheckType get_check_type(uint8_t aux) {
    
    MonitorCheckType monitor_check;
    monitor_check.__variant = MonitorCheckType__Free;

    if (aux == 0U) {
        
        monitor_check.__variant = MonitorCheckType__ExpectedValue;

    } else if (aux == 1U) {
        
        monitor_check.__variant = MonitorCheckType__Limits;

    } else if (aux == 2U) {
        
        monitor_check.__variant = MonitorCheckType__Delta;

    } else {
        
        monitor_check.__variant = MonitorCheckType__Free;

    }

    return monitor_check;

}

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition) {
    
    _Bool res = 0;

    if ((*param_limit_check_definition).__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition param_limit_def = (*param_limit_check_definition).ParamLimitCheck.__0;

        if (param_limit_def.low_limit < param_limit_def.high_limit) {
            
            res = 1;

        }

    } else {
        
        res = 0;

    }

    return res;

}
