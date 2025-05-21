
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

uint8_t get_check_status_index(CheckState status) {
    
    #line 190 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 194 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamValueStatus) {
        
        #line 192 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckValueStatus param_status = status.ParamValueStatus.__0;

        #line 198 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorUnchecked) {
            
            #line 199 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 1U;

        } else
        #line 201 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
            
            #line 202 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 2U;

        } else
        {
            
            #line 205 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 3U;

        }

    } else
    #line 210 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamLimitStatus) {
        
        #line 192 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckLimitsStatus limit_status = status.ParamLimitStatus.__0;

        #line 214 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorUnchecked) {
            
            #line 215 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 4U;

        } else
        #line 217 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
            
            #line 218 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 5U;

        } else
        #line 220 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
            
            #line 221 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 6U;

        } else
        {
            
            #line 224 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 7U;

        }

    } else
    #line 229 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamDeltaStatus) {
        
        #line 192 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckDeltaStatus delta_status = status.ParamDeltaStatus.__0;

        #line 233 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorUnchecked) {
            
            #line 234 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 8U;

        } else
        #line 236 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaLow) {
            
            #line 237 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 9U;

        } else
        #line 239 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaHigh) {
            
            #line 240 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 10U;

        } else
        {
            
            #line 243 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 11U;

        }

    } else
    {
        
        #line 250 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    }

    #line 255 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

uint8_t get_type_index(MonitorCheckType type) {
    
    #line 260 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 264 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 265 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    } else
    #line 267 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Limits) {
        
        #line 268 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 1U;

    } else
    #line 270 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Delta) {
        
        #line 271 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 2U;

    } else
    {
        
        #line 274 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0xFFU;

    }

    #line 278 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

_Bool are_status_equal(CheckState status1, CheckState status2) {
    
    #line 284 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 286 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return equal;

}

MonitorCheckType get_check_type(uint8_t aux) {
    
    #line 293 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    MonitorCheckType monitor_check;
    #line 293 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    monitor_check.__variant = MonitorCheckType__Free;

    #line 295 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 0U) {
        
        #line 297 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__ExpectedValue;

    } else
    #line 299 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 1U) {
        
        #line 301 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Limits;

    } else
    #line 303 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 2U) {
        
        #line 305 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Delta;

    } else
    {
        
        #line 309 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Free;

    }

    #line 313 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return monitor_check;

}

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition) {
    
    #line 319 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool res = 0;

    #line 323 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if ((*param_limit_check_definition).__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 321 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        ParamLimitCheckDefinition param_limit_def = (*param_limit_check_definition).ParamLimitCheck.__0;

        #line 325 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_limit_def.low_limit < param_limit_def.high_limit) {
            
            #line 327 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            res = 1;

        }

    } else
    {
        
        #line 333 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        res = 0;

    }

    #line 337 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return res;

}
