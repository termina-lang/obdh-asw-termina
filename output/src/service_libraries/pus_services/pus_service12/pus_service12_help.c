
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

uint8_t get_check_status_index(CheckState status) {
    
    #line 195 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 199 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamValueStatus) {
        
        #line 197 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckValueStatus param_status = status.ParamValueStatus.__0;

        #line 203 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorUnchecked) {
            
            #line 204 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 1U;

        } else
        #line 206 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
            
            #line 207 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 2U;

        } else
        {
            
            #line 210 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 3U;

        }

    } else
    #line 215 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamLimitStatus) {
        
        #line 197 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckLimitsStatus limit_status = status.ParamLimitStatus.__0;

        #line 219 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorUnchecked) {
            
            #line 220 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 4U;

        } else
        #line 222 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
            
            #line 223 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 5U;

        } else
        #line 225 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (limit_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
            
            #line 226 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 6U;

        } else
        {
            
            #line 229 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 7U;

        }

    } else
    #line 234 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == CheckState__ParamDeltaStatus) {
        
        #line 197 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        CheckDeltaStatus delta_status = status.ParamDeltaStatus.__0;

        #line 238 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorUnchecked) {
            
            #line 239 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 8U;

        } else
        #line 241 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaLow) {
            
            #line 242 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 9U;

        } else
        #line 244 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (delta_status.__variant == CheckDeltaStatus__MonitorDeltaHigh) {
            
            #line 245 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 10U;

        } else
        {
            
            #line 248 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            index = 11U;

        }

    } else
    {
        
        #line 255 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    }

    #line 260 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

uint8_t get_type_index(MonitorCheckType type) {
    
    #line 265 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    uint8_t index = 0U;

    #line 269 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 270 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0U;

    } else
    #line 272 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Limits) {
        
        #line 273 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 1U;

    } else
    #line 275 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (type.__variant == MonitorCheckType__Delta) {
        
        #line 276 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 2U;

    } else
    {
        
        #line 279 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        index = 0xFFU;

    }

    #line 283 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return index;

}

_Bool are_status_equal(CheckState status1, CheckState status2) {
    
    #line 289 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 291 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return equal;

}

MonitorCheckType get_check_type(uint8_t aux) {
    
    #line 298 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    MonitorCheckType monitor_check;
    #line 298 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    monitor_check.__variant = MonitorCheckType__Free;

    #line 300 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 0U) {
        
        #line 302 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__ExpectedValue;

    } else
    #line 304 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 1U) {
        
        #line 306 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Limits;

    } else
    #line 308 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (aux == 2U) {
        
        #line 310 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Delta;

    } else
    {
        
        #line 314 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        monitor_check.__variant = MonitorCheckType__Free;

    }

    #line 318 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return monitor_check;

}

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition) {
    
    #line 324 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    _Bool res = 0;

    #line 328 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if ((*param_limit_check_definition).__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 326 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        ParamLimitCheckDefinition param_limit_def = (*param_limit_check_definition).ParamLimitCheck.__0;

        #line 330 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_limit_def.low_limit < param_limit_def.high_limit) {
            
            #line 332 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            res = 1;

        }

    } else
    {
        
        #line 338 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        res = 0;

    }

    #line 342 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return res;

}

__status_int32_t build_tm_12_12(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, MissionObt current_obt,
                                uint8_t counter,
                                const ParamMonitoringTransition param_mon_transitions_table[1U]) {
    
    #line 348 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    __status_int32_t status;
    #line 348 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    status.__variant = Success;

    #line 350 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    startup_tm(p_tm_handler);

    #line 351 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    status = append_u8_appdata_field(p_tm_handler, counter);

    #line 353 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    for (size_t i = 0U; i < 1U && i < (size_t)counter; i = i + 1U) {
        
        #line 355 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        uint8_t aux_prev_status = 0U;

        #line 356 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        uint8_t aux_new_status = 0U;

        #line 358 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 359 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u16_appdata_field(p_tm_handler,
                                              param_mon_transitions_table[__termina_array__index(1U,
                                                                                                 i)].PMONID);

        }

        #line 361 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 362 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u16_appdata_field(p_tm_handler,
                                              param_mon_transitions_table[__termina_array__index(1U,
                                                                                                 i)].PID);

        }

        #line 364 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 365 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            uint8_t type_id = get_type_index(param_mon_transitions_table[__termina_array__index(1U,
                                                                                                i)].type);

            #line 366 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u8_appdata_field(p_tm_handler, type_id);

        }

        #line 370 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (param_mon_transitions_table[__termina_array__index(1U,
                                                               i)].type.__variant == MonitorCheckType__ExpectedValue
            && status.__variant == Success) {
            
            #line 371 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u32_appdata_field(p_tm_handler,
                                              param_mon_transitions_table[__termina_array__index(1U,
                                                                                                 i)].mask_value);

        }

        #line 374 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        aux_prev_status = get_check_status_index(param_mon_transitions_table[__termina_array__index(1U,
                                                                                                    i)].prev_status);

        #line 375 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        aux_new_status = get_check_status_index(param_mon_transitions_table[__termina_array__index(1U,
                                                                                                   i)].new_status);

        #line 377 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 378 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u32_appdata_field(p_tm_handler,
                                              param_mon_transitions_table[__termina_array__index(1U,
                                                                                                 i)].new_value);

        }

        #line 380 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 381 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u32_appdata_field(p_tm_handler,
                                              param_mon_transitions_table[__termina_array__index(1U,
                                                                                                 i)].limit_value);

        }

        #line 383 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 384 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u8_appdata_field(p_tm_handler, aux_prev_status);

        }

        #line 386 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 387 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u8_appdata_field(p_tm_handler, aux_new_status);

        }

        #line 389 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        if (status.__variant == Success) {
            
            #line 390 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
            status = append_u32_appdata_field(p_tm_handler,
                                              param_mon_transitions_table[__termina_array__index(1U,
                                                                                                 i)].trans_obt.seconds);

        }

    }

    #line 393 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    if (status.__variant == Success) {
        
        #line 394 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
        close_tm(p_tm_handler, 12U, 12U, tm_seq_counter, current_obt);

    }

    #line 398 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    return status;

}
