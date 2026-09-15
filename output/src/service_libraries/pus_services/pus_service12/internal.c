
#include "service_libraries/pus_services/pus_service12/internal.h"

uint8_t get_check_status_index(CheckState status) {
    
    #line 193 "src/service_libraries/pus_services/pus_service12/internal.fin"
    uint8_t index = 0U;

    #line 197 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (status.__variant == CheckState__ParamValueStatus) {
        
        #line 197 "src/service_libraries/pus_services/pus_service12/internal.fin"
        CheckValueStatus param_status = status.ParamValueStatus.__0;

        #line 201 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (param_status.__variant == CheckValueStatus__MonitorUnchecked) {
            
            #line 202 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 1U;

        } else
        #line 204 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (param_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
            
            #line 205 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 2U;

        } else
        {
            
            #line 208 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 3U;

        }

    } else
    #line 213 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (status.__variant == CheckState__ParamLimitStatus) {
        
        #line 213 "src/service_libraries/pus_services/pus_service12/internal.fin"
        CheckLimitsStatus limit_status = status.ParamLimitStatus.__0;

        #line 217 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorUnchecked) {
            
            #line 218 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 4U;

        } else
        #line 220 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
            
            #line 221 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 5U;

        } else
        #line 223 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
            
            #line 224 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 6U;

        } else
        {
            
            #line 227 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 7U;

        }

    } else
    #line 232 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (status.__variant == CheckState__ParamDeltaStatus) {
        
        #line 232 "src/service_libraries/pus_services/pus_service12/internal.fin"
        CheckDeltaStatus delta_status = status.ParamDeltaStatus.__0;

        #line 236 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorUnchecked) {
            
            #line 237 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 8U;

        } else
        #line 239 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaLow) {
            
            #line 240 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 9U;

        } else
        #line 242 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaHigh) {
            
            #line 243 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 10U;

        } else
        {
            
            #line 246 "src/service_libraries/pus_services/pus_service12/internal.fin"
            index = 11U;

        }

    } else
    {
        

    }

    #line 256 "src/service_libraries/pus_services/pus_service12/internal.fin"
    return index;

}

uint8_t get_type_index(MonitorCheckType type) {
    
    #line 261 "src/service_libraries/pus_services/pus_service12/internal.fin"
    uint8_t index;

    #line 265 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 266 "src/service_libraries/pus_services/pus_service12/internal.fin"
        index = 0U;

    } else
    #line 268 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (type.__variant == MonitorCheckType__Limits) {
        
        #line 269 "src/service_libraries/pus_services/pus_service12/internal.fin"
        index = 1U;

    } else
    #line 271 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (type.__variant == MonitorCheckType__Delta) {
        
        #line 272 "src/service_libraries/pus_services/pus_service12/internal.fin"
        index = 2U;

    } else
    {
        
        #line 275 "src/service_libraries/pus_services/pus_service12/internal.fin"
        index = 0xFFU;

    }

    #line 279 "src/service_libraries/pus_services/pus_service12/internal.fin"
    return index;

}

_Bool are_status_equal(CheckState status1, CheckState status2) {
    
    #line 285 "src/service_libraries/pus_services/pus_service12/internal.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 287 "src/service_libraries/pus_services/pus_service12/internal.fin"
    return equal;

}

MonitorCheckType get_check_type(uint8_t aux) {
    
    #line 294 "src/service_libraries/pus_services/pus_service12/internal.fin"
    MonitorCheckType monitor_check;

    #line 296 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (aux == 0U) {
        
        #line 298 "src/service_libraries/pus_services/pus_service12/internal.fin"
        monitor_check.__variant = MonitorCheckType__ExpectedValue;

    } else
    #line 300 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (aux == 1U) {
        
        #line 302 "src/service_libraries/pus_services/pus_service12/internal.fin"
        monitor_check.__variant = MonitorCheckType__Limits;

    } else
    #line 304 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (aux == 2U) {
        
        #line 306 "src/service_libraries/pus_services/pus_service12/internal.fin"
        monitor_check.__variant = MonitorCheckType__Delta;

    } else
    {
        
        #line 310 "src/service_libraries/pus_services/pus_service12/internal.fin"
        monitor_check.__variant = MonitorCheckType__Free;

    }

    #line 314 "src/service_libraries/pus_services/pus_service12/internal.fin"
    return monitor_check;

}

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition) {
    
    #line 320 "src/service_libraries/pus_services/pus_service12/internal.fin"
    _Bool res = false;

    #line 324 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if ((*param_limit_check_definition).__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 324 "src/service_libraries/pus_services/pus_service12/internal.fin"
        ParamLimitCheckDefinition param_limit_def = (*param_limit_check_definition).ParamLimitCheck.__0;

        #line 326 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (param_limit_def.low_limit < param_limit_def.high_limit) {
            
            #line 328 "src/service_libraries/pus_services/pus_service12/internal.fin"
            res = true;

        }

    } else
    {
        
        #line 334 "src/service_libraries/pus_services/pus_service12/internal.fin"
        res = false;

    }

    #line 338 "src/service_libraries/pus_services/pus_service12/internal.fin"
    return res;

}

__status_int32_t build_tm_12_12(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt, uint8_t counter, const ParamMonitoringTransition param_mon_transitions_table[1U]) {
    
    #line 344 "src/service_libraries/pus_services/pus_service12/internal.fin"
    startup_tm(p_tm_handler);

    #line 345 "src/service_libraries/pus_services/pus_service12/internal.fin"
    __status_int32_t status = append_u8_appdata_field(p_tm_handler, counter);

    #line 347 "src/service_libraries/pus_services/pus_service12/internal.fin"
    for (size_t i = 0U; i < 1U && i < (size_t)counter; i = i + 1U) {
        
        #line 349 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 350 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u16_appdata_field(p_tm_handler, param_mon_transitions_table[__termina_array__index(1U, i)].PMONID);

        }

        #line 352 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 353 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u16_appdata_field(p_tm_handler, param_mon_transitions_table[__termina_array__index(1U, i)].PID);

        }

        #line 355 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 356 "src/service_libraries/pus_services/pus_service12/internal.fin"
            uint8_t type_id = get_type_index(param_mon_transitions_table[__termina_array__index(1U, i)].type);

            #line 357 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u8_appdata_field(p_tm_handler, type_id);

        }

        #line 361 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (param_mon_transitions_table[__termina_array__index(1U, i)].type.__variant == MonitorCheckType__ExpectedValue && status.__variant == Success) {
            
            #line 362 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u32_appdata_field(p_tm_handler, param_mon_transitions_table[__termina_array__index(1U, i)].mask_value);

        }

        #line 365 "src/service_libraries/pus_services/pus_service12/internal.fin"
        uint8_t aux_prev_status = get_check_status_index(param_mon_transitions_table[__termina_array__index(1U, i)].prev_status);

        #line 366 "src/service_libraries/pus_services/pus_service12/internal.fin"
        uint8_t aux_new_status = get_check_status_index(param_mon_transitions_table[__termina_array__index(1U, i)].new_status);

        #line 368 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 369 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u32_appdata_field(p_tm_handler, param_mon_transitions_table[__termina_array__index(1U, i)].new_value);

        }

        #line 371 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 372 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u32_appdata_field(p_tm_handler, param_mon_transitions_table[__termina_array__index(1U, i)].limit_value);

        }

        #line 374 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 375 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u8_appdata_field(p_tm_handler, aux_prev_status);

        }

        #line 377 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 378 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u8_appdata_field(p_tm_handler, aux_new_status);

        }

        #line 380 "src/service_libraries/pus_services/pus_service12/internal.fin"
        if (status.__variant == Success) {
            
            #line 381 "src/service_libraries/pus_services/pus_service12/internal.fin"
            status = append_u32_appdata_field(p_tm_handler, param_mon_transitions_table[__termina_array__index(1U, i)].trans_obt.seconds);

        }

    }

    #line 384 "src/service_libraries/pus_services/pus_service12/internal.fin"
    if (status.__variant == Success) {
        
        #line 385 "src/service_libraries/pus_services/pus_service12/internal.fin"
        close_tm(p_tm_handler, 12U, 12U, tm_seq_counter, current_obt);

    }

    #line 389 "src/service_libraries/pus_services/pus_service12/internal.fin"
    return status;

}
