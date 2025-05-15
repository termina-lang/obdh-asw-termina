
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

uint8_t get_check_status_index(CheckState status) {
    
    #line 188 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 192 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamValueStatus) {
        
        #line 190 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckValueStatus param_status = status.ParamValueStatus.__0;

        #line 196 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorUnchecked) {
            
            #line 197 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 1U;

        } else
        #line 199 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
            
            #line 200 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 2U;

        } else
        {
            
            #line 203 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 3U;

        }

    } else
    #line 208 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamLimitStatus) {
        
        #line 190 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckLimitsStatus limit_status = status.ParamLimitStatus.__0;

        #line 212 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorUnchecked) {
            
            #line 213 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 4U;

        } else
        #line 215 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
            
            #line 216 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 5U;

        } else
        #line 218 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
            
            #line 219 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 6U;

        } else
        {
            
            #line 222 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 7U;

        }

    } else
    #line 227 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamDeltaStatus) {
        
        #line 190 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckDeltaStatus delta_status = status.ParamDeltaStatus.__0;

        #line 231 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorUnchecked) {
            
            #line 232 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 8U;

        } else
        #line 234 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaLow) {
            
            #line 235 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 9U;

        } else
        #line 237 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaHigh) {
            
            #line 238 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 10U;

        } else
        {
            
            #line 241 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 11U;

        }

    } else
    {
        
        #line 248 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    }

    #line 253 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

uint8_t get_type_index(MonitorCheckType type) {
    
    #line 258 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 262 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 263 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    } else
    #line 265 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Limits) {
        
        #line 266 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 1U;

    } else
    #line 268 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Delta) {
        
        #line 269 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 2U;

    } else
    {
        
        #line 272 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0xFFU;

    }

    #line 276 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

_Bool are_status_equal(CheckState status1, CheckState status2) {
    
    #line 282 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 284 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return equal;

}

MonitorCheckType get_check_type(uint8_t aux) {
    
    #line 291 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    MonitorCheckType monitor_check;
    #line 291 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    monitor_check.__variant = MonitorCheckType__Free;

    #line 293 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 0U) {
        
        #line 295 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__ExpectedValue;

    } else
    #line 297 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 1U) {
        
        #line 299 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Limits;

    } else
    #line 301 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 2U) {
        
        #line 303 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Delta;

    } else
    {
        
        #line 307 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Free;

    }

    #line 311 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return monitor_check;

}

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition) {
    
    #line 317 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool res = 0;

    #line 321 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if ((*param_limit_check_definition).__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 319 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        ParamLimitCheckDefinition param_limit_def = (*param_limit_check_definition).ParamLimitCheck.__0;

        #line 323 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_limit_def.low_limit < param_limit_def.high_limit) {
            
            #line 325 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            res = 1;

        }

    } else
    {
        
        #line 331 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        res = 0;

    }

    #line 335 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return res;

}
