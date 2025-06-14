
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

uint8_t get_check_status_index(CheckState status) {
    
    #line 193 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 197 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamValueStatus) {
        
        #line 195 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckValueStatus param_status = status.ParamValueStatus.__0;

        #line 201 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorUnchecked) {
            
            #line 202 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 1U;

        } else
        #line 204 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
            
            #line 205 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 2U;

        } else
        {
            
            #line 208 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 3U;

        }

    } else
    #line 213 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamLimitStatus) {
        
        #line 195 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckLimitsStatus limit_status = status.ParamLimitStatus.__0;

        #line 217 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorUnchecked) {
            
            #line 218 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 4U;

        } else
        #line 220 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
            
            #line 221 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 5U;

        } else
        #line 223 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
            
            #line 224 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 6U;

        } else
        {
            
            #line 227 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 7U;

        }

    } else
    #line 232 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamDeltaStatus) {
        
        #line 195 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckDeltaStatus delta_status = status.ParamDeltaStatus.__0;

        #line 236 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorUnchecked) {
            
            #line 237 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 8U;

        } else
        #line 239 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaLow) {
            
            #line 240 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 9U;

        } else
        #line 242 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaHigh) {
            
            #line 243 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 10U;

        } else
        {
            
            #line 246 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 11U;

        }

    } else
    {
        
        #line 253 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    }

    #line 258 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

uint8_t get_type_index(MonitorCheckType type) {
    
    #line 263 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 267 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 268 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    } else
    #line 270 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Limits) {
        
        #line 271 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 1U;

    } else
    #line 273 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Delta) {
        
        #line 274 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 2U;

    } else
    {
        
        #line 277 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0xFFU;

    }

    #line 281 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

_Bool are_status_equal(CheckState status1, CheckState status2) {
    
    #line 287 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 289 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return equal;

}

MonitorCheckType get_check_type(uint8_t aux) {
    
    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    MonitorCheckType monitor_check;
    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    monitor_check.__variant = MonitorCheckType__Free;

    #line 298 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 0U) {
        
        #line 300 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__ExpectedValue;

    } else
    #line 302 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 1U) {
        
        #line 304 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Limits;

    } else
    #line 306 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 2U) {
        
        #line 308 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Delta;

    } else
    {
        
        #line 312 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Free;

    }

    #line 316 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return monitor_check;

}

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition) {
    
    #line 322 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool res = 0;

    #line 326 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if ((*param_limit_check_definition).__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 324 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        ParamLimitCheckDefinition param_limit_def = (*param_limit_check_definition).ParamLimitCheck.__0;

        #line 328 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_limit_def.low_limit < param_limit_def.high_limit) {
            
            #line 330 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            res = 1;

        }

    } else
    {
        
        #line 336 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        res = 0;

    }

    #line 340 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return res;

}
