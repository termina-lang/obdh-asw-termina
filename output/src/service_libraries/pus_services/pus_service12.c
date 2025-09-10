
#include "service_libraries/pus_services/pus_service12.h"

_Bool PUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev, const PUSService12 * const self, const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    #line 264 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 265 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = 0;

    #line 266 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

    #line 267 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 268 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 272 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 273 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 275 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 276 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 277 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 278 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 285 "src/service_libraries/pus_services/pus_service12.fin"
    if ((uint32_t)(SDP_value & expected_value_check_definition->mask_value) == (uint32_t)(expected_value_check_definition->expected_value & expected_value_check_definition->mask_value)) {
        
        #line 287 "src/service_libraries/pus_services/pus_service12.fin"
        res = 1;

    }

    #line 290 "src/service_libraries/pus_services/pus_service12.fin"
    return res;

}

_Bool PUSService12__PID_is_above_upper_limit(const __termina_event_t * const __ev, const PUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def) {
    
    #line 198 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 199 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = 0;

    #line 200 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t upper_limit = limit_check_def->high_limit;

    #line 201 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

    #line 202 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 203 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 207 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 208 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 210 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 211 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 212 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 214 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 221 "src/service_libraries/pus_services/pus_service12.fin"
    if (SDP_value > upper_limit) {
        
        #line 223 "src/service_libraries/pus_services/pus_service12.fin"
        res = 1;

    }

    #line 226 "src/service_libraries/pus_services/pus_service12.fin"
    return res;

}

_Bool PUSService12__PID_is_below_lower_limit(const __termina_event_t * const __ev, const PUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def) {
    
    #line 231 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 232 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = 0;

    #line 233 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t lower_limit = limit_check_def->low_limit;

    #line 234 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

    #line 235 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 236 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 240 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 241 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 243 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 244 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 245 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 246 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 253 "src/service_libraries/pus_services/pus_service12.fin"
    if (SDP_value < lower_limit) {
        
        #line 255 "src/service_libraries/pus_services/pus_service12.fin"
        res = 1;

    }

    #line 258 "src/service_libraries/pus_services/pus_service12.fin"
    return res;

}

void PUSService12__add_monitoring_transition(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 548 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t monitoring_status;
    #line 548 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_status.__variant = Success;

    #line 550 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter < 1U) {
        
        #line 552 "src/service_libraries/pus_services/pus_service12.fin"
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        #line 554 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 555 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        #line 556 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].type;

        #line 558 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 558 "src/service_libraries/pus_services/pus_service12.fin"
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0;

            #line 559 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            #line 560 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else
        #line 562 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 562 "src/service_libraries/pus_services/pus_service12.fin"
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0;

            #line 563 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            #line 564 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else
        {
            

        }

        #line 573 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
            
            #line 573 "src/service_libraries/pus_services/pus_service12.fin"
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamValueCheck.__0;

            #line 575 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else
        {
            

        }

        #line 584 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        #line 585 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].prev_status = self->do_monitoring_req_status_update.prev_status;

        #line 586 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].transition_obt;

        #line 588 "src/service_libraries/pus_services/pus_service12.fin"
        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    #line 591 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter == 1U) {
        
        #line 593 "src/service_libraries/pus_services/pus_service12.fin"
        __option_box_t tm_handler;
        #line 593 "src/service_libraries/pus_services/pus_service12.fin"
        tm_handler.__variant = None;

        #line 594 "src/service_libraries/pus_services/pus_service12.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that, &tm_handler);

        #line 598 "src/service_libraries/pus_services/pus_service12.fin"
        if (tm_handler.__variant == Some) {
            
            #line 598 "src/service_libraries/pus_services/pus_service12.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 600 "src/service_libraries/pus_services/pus_service12.fin"
            uint16_t tm_count = 0U;

            #line 601 "src/service_libraries/pus_services/pus_service12.fin"
            MissionOBT current_obt;
            #line 601 "src/service_libraries/pus_services/pus_service12.fin"
            current_obt.finetime = 0U;
            #line 601 "src/service_libraries/pus_services/pus_service12.fin"
            current_obt.seconds = 0U;

            #line 602 "src/service_libraries/pus_services/pus_service12.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

            #line 603 "src/service_libraries/pus_services/pus_service12.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

            #line 605 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status = build_tm_12_12((TMHandler *)b_tm_handler.data, tm_count, current_obt, self->monitoring_transition_counter, self->param_mon_transitions_table);

            #line 607 "src/service_libraries/pus_services/pus_service12.fin"
            if (monitoring_status.__variant == Success) {
                
                #line 608 "src/service_libraries/pus_services/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, &monitoring_status);

            } else
            {
                
                #line 611 "src/service_libraries/pus_services/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that, b_tm_handler);

            }

        } else
        {
            
            #line 617 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status.__variant = Failure;
            #line 617 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

        #line 623 "src/service_libraries/pus_services/pus_service12.fin"
        self->monitoring_transition_counter = 0U;

    }

    #line 626 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

void PUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 929 "src/service_libraries/pus_services/pus_service12.fin"
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.PMONID;

    #line 931 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    #line 933 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, PMONID)].enabled = 0;

    #line 936 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 940 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 942 "src/service_libraries/pus_services/pus_service12.fin"
            CheckValueStatus status;
            #line 942 "src/service_libraries/pus_services/pus_service12.fin"
            status.__variant = CheckValueStatus__MonitorUnchecked;

            #line 943 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            #line 943 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.ParamValueStatus.__0 = status;

        } else
        #line 945 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            #line 947 "src/service_libraries/pus_services/pus_service12.fin"
            CheckLimitsStatus status;
            #line 947 "src/service_libraries/pus_services/pus_service12.fin"
            status.__variant = CheckLimitsStatus__MonitorUnchecked;

            #line 948 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            #line 948 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else
        #line 951 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            #line 953 "src/service_libraries/pus_services/pus_service12.fin"
            CheckDeltaStatus status;
            #line 953 "src/service_libraries/pus_services/pus_service12.fin"
            status.__variant = CheckDeltaStatus__MonitorUnchecked;

            #line 954 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            #line 954 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else
        {
            

        }

    }

    #line 967 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

_Bool PUSService12__are_status_equal(const __termina_event_t * const __ev, const PUSService12 * const self, CheckState status1, CheckState status2) {
    
    #line 498 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 499 "src/service_libraries/pus_services/pus_service12.fin"
    return equal;

}

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 108 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 109 "src/service_libraries/pus_services/pus_service12.fin"
    ParamValueCheckDefinition monitoring_definition;
    #line 109 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.EvID = 0U;
    #line 109 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.expected_value = 0U;
    #line 109 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.mask_value = 0U;

    #line 117 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 117 "src/service_libraries/pus_services/pus_service12.fin"
        ParamValueCheckDefinition param_check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamValueCheck.__0;

        #line 119 "src/service_libraries/pus_services/pus_service12.fin"
        monitoring_definition = param_check_definition;

    } else
    {
        

    }

    #line 128 "src/service_libraries/pus_services/pus_service12.fin"
    return monitoring_definition;

}

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 179 "src/service_libraries/pus_services/pus_service12.fin"
    ParamValueCheckDefinition current_monitor_definition = PUSService12__get_expected_value_monitoring_definition(__ev, self);

    #line 180 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueStatus check_status;
    #line 180 "src/service_libraries/pus_services/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorUnchecked;

    #line 182 "src/service_libraries/pus_services/pus_service12.fin"
    if (PUSService12__PID_has_expected_masked_value(__ev, self, &current_monitor_definition)) {
        
        #line 184 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckValueStatus__MonitorValueExpected;

    } else
    {
        
        #line 189 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    }

    #line 193 "src/service_libraries/pus_services/pus_service12.fin"
    return check_status;

}

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 82 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    ParamLimitCheckDefinition monitoring_definition;
    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.high_limit = 0U;
    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.high_limit_evID = 0U;
    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.low_limit = 0U;
    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    monitoring_definition.low_limit_evID = 0U;

    #line 92 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 92 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition limit_check_def = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 94 "src/service_libraries/pus_services/pus_service12.fin"
        monitoring_definition = limit_check_def;

    } else
    {
        

    }

    #line 102 "src/service_libraries/pus_services/pus_service12.fin"
    return monitoring_definition;

}

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 154 "src/service_libraries/pus_services/pus_service12.fin"
    ParamLimitCheckDefinition current_monitor_definition = PUSService12__get_limits_monitoring_definition(__ev, self);

    #line 155 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 155 "src/service_libraries/pus_services/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorUnchecked;

    #line 157 "src/service_libraries/pus_services/pus_service12.fin"
    if (PUSService12__PID_is_above_upper_limit(__ev, self, &current_monitor_definition)) {
        
        #line 159 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    } else
    #line 162 "src/service_libraries/pus_services/pus_service12.fin"
    if (PUSService12__PID_is_below_lower_limit(__ev, self, &current_monitor_definition)) {
        
        #line 164 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    } else
    {
        
        #line 170 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorWithinLimits;

    }

    #line 173 "src/service_libraries/pus_services/pus_service12.fin"
    return check_status;

}

_Bool PUSService12__is_expected_value_monitoring(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 69 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 70 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_exp_val_mon = 0;

    #line 72 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 74 "src/service_libraries/pus_services/pus_service12.fin"
        is_exp_val_mon = 1;

    }

    #line 77 "src/service_libraries/pus_services/pus_service12.fin"
    return is_exp_val_mon;

}

_Bool PUSService12__is_limits_monitoring(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 55 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 56 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_limits_mon = 0;

    #line 58 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 60 "src/service_libraries/pus_services/pus_service12.fin"
        is_limits_mon = 1;

    }

    #line 63 "src/service_libraries/pus_services/pus_service12.fin"
    return is_limits_mon;

}

_Bool PUSService12__is_valid_PMONID(const __termina_event_t * const __ev, const PUSService12 * const self) {
    
    #line 43 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_valid = 0;

    #line 45 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->do_monitoring_req_status_update.PMONID < 16U) {
        
        #line 47 "src/service_libraries/pus_services/pus_service12.fin"
        is_valid = 1;

    }

    #line 50 "src/service_libraries/pus_services/pus_service12.fin"
    return is_valid;

}

_Bool PUSService12__manage_new_status(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 504 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool transition = 0;

    #line 505 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 507 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState new_state = self->do_monitoring_req_status_update.new_status;

    #line 508 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState current_state = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state;

    #line 509 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState temp_state = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].temp_state;

    #line 511 "src/service_libraries/pus_services/pus_service12.fin"
    if (PUSService12__are_status_equal(__ev, self, new_state, current_state) == 0) {
        
        #line 513 "src/service_libraries/pus_services/pus_service12.fin"
        if (are_status_equal(new_state, temp_state)) {
            
            #line 515 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control + 1U;

        } else
        {
            
            #line 519 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].temp_state = new_state;

            #line 520 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = 1U;

            #line 521 "src/service_libraries/pus_services/pus_service12.fin"
            MissionOBT current_obt;
            #line 521 "src/service_libraries/pus_services/pus_service12.fin"
            current_obt.finetime = 0U;
            #line 521 "src/service_libraries/pus_services/pus_service12.fin"
            current_obt.seconds = 0U;

            #line 522 "src/service_libraries/pus_services/pus_service12.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

            #line 523 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].transition_obt = current_obt;

        }

        #line 526 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control >= self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition) {
            
            #line 528 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = 0U;

            #line 529 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.prev_status = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state;

            #line 530 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state = new_state;

            #line 531 "src/service_libraries/pus_services/pus_service12.fin"
            transition = 1;

        }

    } else
    {
        
        #line 537 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].temp_state = new_state;

        #line 538 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = 0U;

    }

    #line 542 "src/service_libraries/pus_services/pus_service12.fin"
    return transition;

}

DoMonitoringReqStatus PUSService12__manage_expected_value(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 355 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueStatus check_status;
    #line 355 "src/service_libraries/pus_services/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorValueExpected;

    #line 356 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    #line 356 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    #line 358 "src/service_libraries/pus_services/pus_service12.fin"
    if (PUSService12__manage_new_status(__ev, self)) {
        
        #line 360 "src/service_libraries/pus_services/pus_service12.fin"
        PUSService12__add_monitoring_transition(__ev, self);

    }

    #line 363 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_interval_control(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 133 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 134 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 134 "src/service_libraries/pus_services/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__Exit;

    #line 136 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control + 1U;

    #line 138 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control >= self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval) {
        
        #line 141 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control = 0U;

        #line 142 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__GetMonitoringType;

    } else
    {
        
        #line 146 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 149 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 368 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 368 "src/service_libraries/pus_services/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 370 "src/service_libraries/pus_services/pus_service12.fin"
    ParamOutOfLimitInfo fault_info;
    #line 370 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID = 0U;
    #line 370 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_limit = 0U;
    #line 370 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_value = 0U;

    #line 374 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 374 "src/service_libraries/pus_services/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    #line 375 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    #line 375 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    #line 377 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 381 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 381 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 383 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 384 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_limit = check_definition.high_limit;

        #line 386 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 390 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 391 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 393 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 394 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 395 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 396 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 399 "src/service_libraries/pus_services/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 403 "src/service_libraries/pus_services/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 405 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 406 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 406 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 407 "src/service_libraries/pus_services/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

            #line 408 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.high_limit_evID;

        }

    } else
    {
        
        #line 413 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 418 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 423 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 423 "src/service_libraries/pus_services/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 425 "src/service_libraries/pus_services/pus_service12.fin"
    ParamOutOfLimitInfo fault_info;
    #line 425 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID = 0U;
    #line 425 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_limit = 0U;
    #line 425 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_value = 0U;

    #line 429 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 429 "src/service_libraries/pus_services/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    #line 430 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    #line 430 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    #line 432 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 436 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 436 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 438 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 439 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_limit = check_definition.low_limit;

        #line 441 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 445 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 446 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 448 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 449 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 450 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 451 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 454 "src/service_libraries/pus_services/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 458 "src/service_libraries/pus_services/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 460 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 461 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 461 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 462 "src/service_libraries/pus_services/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

            #line 463 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.low_limit_evID;

        }

    } else
    {
        
        #line 468 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 472 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_within_limits(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 477 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 477 "src/service_libraries/pus_services/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 479 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus within_limits;
    #line 479 "src/service_libraries/pus_services/pus_service12.fin"
    within_limits.__variant = CheckLimitsStatus__MonitorWithinLimits;

    #line 480 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState new_status;
    #line 480 "src/service_libraries/pus_services/pus_service12.fin"
    new_status.__variant = CheckState__ParamLimitStatus;
    #line 480 "src/service_libraries/pus_services/pus_service12.fin"
    new_status.ParamLimitStatus.__0 = within_limits;

    #line 481 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status = new_status;

    #line 482 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 483 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState current_status = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state;

    #line 485 "src/service_libraries/pus_services/pus_service12.fin"
    if (PUSService12__are_status_equal(__ev, self, new_status, current_status) == 0) {
        
        #line 487 "src/service_libraries/pus_services/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 489 "src/service_libraries/pus_services/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

        }

    }

    #line 493 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_unexpected_value(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 296 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 296 "src/service_libraries/pus_services/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 298 "src/service_libraries/pus_services/pus_service12.fin"
    ParamFaultValueInfo fault_info;
    #line 298 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID = 0U;
    #line 298 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_expected_value = 0U;
    #line 298 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_mask = 0U;
    #line 298 "src/service_libraries/pus_services/pus_service12.fin"
    fault_info.PID_value = 0U;

    #line 303 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueStatus check_status;
    #line 303 "src/service_libraries/pus_services/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    #line 304 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    #line 304 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    #line 305 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 309 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 309 "src/service_libraries/pus_services/pus_service12.fin"
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamValueCheck.__0;

        #line 311 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 312 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_expected_value = check_definition.expected_value;

        #line 313 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_mask = check_definition.mask_value;

        #line 315 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 319 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 320 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 322 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 323 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 324 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 325 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 329 "src/service_libraries/pus_services/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 333 "src/service_libraries/pus_services/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 335 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 336 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamFaultValue;
            #line 336 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0 = fault_info;

            #line 337 "src/service_libraries/pus_services/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

            #line 338 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.EvID;

        }

    } else
    {
        
        #line 343 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 347 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

void PUSService12__do_monitoring(const __termina_event_t * const __ev, void * const __this, uint16_t PMONID, uint16_t * const evID, FaultInfo * const fault_info, _Bool * const event_triggered) {
    
    #line 629 "src/service_libraries/pus_services/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 629 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 632 "src/service_libraries/pus_services/pus_service12.fin"
    for (size_t i = 0U; i < 5U && self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit == 0; i = i + 1U) {
        
        #line 634 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Init) {
            
            #line 636 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.PMONID = PMONID;

            #line 637 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = *evID;

            #line 638 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info = *fault_info;

            #line 639 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__CheckPMONID;

            #line 640 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 0;

        } else
        #line 643 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__CheckPMONID) {
            
            #line 646 "src/service_libraries/pus_services/pus_service12.fin"
            if (PUSService12__is_valid_PMONID(__ev, self) && self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled == 1) {
                
                #line 647 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_interval_control(__ev, self);

            } else
            {
                
                #line 649 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 653 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            #line 655 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled == 1) {
                
                #line 658 "src/service_libraries/pus_services/pus_service12.fin"
                if (PUSService12__is_limits_monitoring(__ev, self)) {
                    
                    #line 660 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else
                #line 663 "src/service_libraries/pus_services/pus_service12.fin"
                if (PUSService12__is_expected_value_monitoring(__ev, self)) {
                    
                    #line 665 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else
                {
                    
                    #line 669 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

                }

            } else
            {
                
                #line 674 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 678 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            #line 680 "src/service_libraries/pus_services/pus_service12.fin"
            CheckLimitsStatus limits_monitoring_status = PUSService12__check_PID_status_limits_monitoring(__ev, self);

            #line 683 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                #line 685 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_above_upper_limit(__ev, self);

            } else
            #line 687 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                #line 689 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_below_lower_limit(__ev, self);

            } else
            #line 692 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                #line 694 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_within_limits(__ev, self);

            } else
            {
                

            }

        } else
        #line 703 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            #line 705 "src/service_libraries/pus_services/pus_service12.fin"
            CheckValueStatus exp_value_monitoring_status = PUSService12__check_PID_status_exp_val_monitoring(__ev, self);

            #line 708 "src/service_libraries/pus_services/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                #line 709 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_unexpected_value(__ev, self);

            } else
            #line 711 "src/service_libraries/pus_services/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                #line 713 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_expected_value(__ev, self);

            } else
            {
                

            }

        } else
        #line 723 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetRequestStatusUpdate) {
            
            #line 724 "src/service_libraries/pus_services/pus_service12.fin"
            *evID = self->do_monitoring_req_status_update.EvID;

            #line 725 "src/service_libraries/pus_services/pus_service12.fin"
            *fault_info = self->do_monitoring_req_status_update.fault_info;

            #line 726 "src/service_libraries/pus_services/pus_service12.fin"
            *event_triggered = self->do_monitoring_req_status_update.event_triggered;

            #line 727 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 736 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit) {
        
        #line 738 "src/service_libraries/pus_services/pus_service12.fin"
        self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;

    }

    #line 741 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 741 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

__status_int32_t PUSService12__exec12_1TC(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 801 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status;
    #line 801 "src/service_libraries/pus_services/pus_service12.fin"
    status.__variant = Success;

    #line 803 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 805 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 812 "src/service_libraries/pus_services/pus_service12.fin"
        size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

        #line 813 "src/service_libraries/pus_services/pus_service12.fin"
        _Bool is_valid_PMONID = PMONID < 16U;

        #line 815 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_PMONID) {
            
            #line 817 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                
                #line 819 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                #line 824 "src/service_libraries/pus_services/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 826 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled = 1;

                    #line 827 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].interval_control = 0U;

                    #line 828 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].repetition_control = 0U;

                    #line 830 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                } else
                {
                    
                    #line 838 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.send_tm_1_4_PMON_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

                }

            } else
            {
                
                #line 848 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.send_tm_1_4_PMONID_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

            }

        }

    }

    #line 859 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

void PUSService12__set_unchecked(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 773 "src/service_libraries/pus_services/pus_service12.fin"
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    #line 777 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 778 "src/service_libraries/pus_services/pus_service12.fin"
        CheckValueStatus monitor_unchecked;
        #line 778 "src/service_libraries/pus_services/pus_service12.fin"
        monitor_unchecked.__variant = CheckValueStatus__MonitorUnchecked;

        #line 779 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.__variant = CheckState__ParamValueStatus;
        #line 779 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.ParamValueStatus.__0 = monitor_unchecked;

    } else
    #line 781 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 782 "src/service_libraries/pus_services/pus_service12.fin"
        CheckLimitsStatus monitor_unchecked;
        #line 782 "src/service_libraries/pus_services/pus_service12.fin"
        monitor_unchecked.__variant = CheckLimitsStatus__MonitorUnchecked;

        #line 783 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
        #line 783 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.ParamLimitStatus.__0 = monitor_unchecked;

    } else
    #line 785 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].type.__variant == MonitorCheckType__Delta) {
        
        #line 786 "src/service_libraries/pus_services/pus_service12.fin"
        CheckDeltaStatus monitor_unchecked;
        #line 786 "src/service_libraries/pus_services/pus_service12.fin"
        monitor_unchecked.__variant = CheckDeltaStatus__MonitorUnchecked;

        #line 787 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
        #line 787 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.ParamDeltaStatus.__0 = monitor_unchecked;

    } else
    {
        

    }

    #line 794 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].temp_state = self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state;

    #line 796 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

__status_int32_t PUSService12__exec12_2TC(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 864 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status;
    #line 864 "src/service_libraries/pus_services/pus_service12.fin"
    status.__variant = Success;

    #line 867 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 869 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 877 "src/service_libraries/pus_services/pus_service12.fin"
        _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 16U;

        #line 879 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_PMONID) {
            
            #line 881 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                
                #line 883 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                #line 889 "src/service_libraries/pus_services/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 891 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = 0;

                    #line 892 "src/service_libraries/pus_services/pus_service12.fin"
                    PUSService12__set_unchecked(__ev, self);

                    #line 894 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                }

            } else
            {
                
                #line 905 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.send_tm_1_4_PMON_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

            }

        } else
        {
            
            #line 915 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMONID_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        }

    }

    #line 924 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

__status_int32_t PUSService12__exec12_5TC(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 972 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status;
    #line 972 "src/service_libraries/pus_services/pus_service12.fin"
    status.__variant = Success;

    #line 975 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
        
        #line 977 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.N, &status);

    } else
    #line 983 "src/service_libraries/pus_services/pus_service12.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == 0) {
        
        #line 985 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.mon_config.PID, &status);

    } else
    #line 991 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
        
        #line 993 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
            
            #line 995 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            #line 1001 "src/service_libraries/pus_services/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 1003 "src/service_libraries/pus_services/pus_service12.fin"
                PUSService12__add_valid_mng_mon_def(__ev, self);

                #line 1005 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            }

        } else
        {
            
            #line 1014 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_definition_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.PMONID, &status);

        }

    } else
    #line 1022 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 1024 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 1030 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1032 "src/service_libraries/pus_services/pus_service12.fin"
            PUSService12__add_valid_mng_mon_def(__ev, self);

            #line 1034 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        }

    } else
    {
        
        #line 1043 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_PMON_definition_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.PMONID, &status);

    }

    #line 1051 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

__status_int32_t PUSService12__exec12_6TC(const __termina_event_t * const __ev, PUSService12 * const self) {
    
    #line 1057 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status;
    #line 1057 "src/service_libraries/pus_services/pus_service12.fin"
    status.__variant = Success;

    #line 1059 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 1061 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 1069 "src/service_libraries/pus_services/pus_service12.fin"
        MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

        #line 1071 "src/service_libraries/pus_services/pus_service12.fin"
        if (PMON_type.__variant == MonitorCheckType__Free) {
            
            #line 1073 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        } else
        #line 1079 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == 0) {
            
            #line 1081 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            #line 1087 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

            #line 1089 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        } else
        {
            
            #line 1097 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        }

    }

    #line 1108 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

void PUSService12__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 1113 "src/service_libraries/pus_services/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 1113 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 1115 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status;
    #line 1115 "src/service_libraries/pus_services/pus_service12.fin"
    status.__variant = Success;

    #line 1116 "src/service_libraries/pus_services/pus_service12.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 1118 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 1119 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 1120 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 1121 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 1123 "src/service_libraries/pus_services/pus_service12.fin"
    if (subtype == 1U || subtype == 2U || subtype == 6U) {
        
        #line 1125 "src/service_libraries/pus_services/pus_service12.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_1_2_6.N);

        #line 1127 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1128 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

        }

    } else
    #line 1131 "src/service_libraries/pus_services/pus_service12.fin"
    if (subtype == 5U) {
        
        #line 1133 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t aux = 0U;

        #line 1135 "src/service_libraries/pus_services/pus_service12.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.N);

        #line 1137 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1138 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.PMONID);

        }

        #line 1140 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1141 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

        }

        #line 1143 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1144 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.interval);

        }

        #line 1146 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1147 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.repetition);

        }

        #line 1149 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1150 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &aux);

            #line 1151 "src/service_libraries/pus_services/pus_service12.fin"
            self->exec_tc_req_status_update.tc_data_5.mon_config.type = get_check_type(aux);

        }

        #line 1154 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1156 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
                
                #line 1158 "src/service_libraries/pus_services/pus_service12.fin"
                ParamValueCheckDefinition value_def;
                #line 1158 "src/service_libraries/pus_services/pus_service12.fin"
                value_def.EvID = 0U;
                #line 1158 "src/service_libraries/pus_services/pus_service12.fin"
                value_def.expected_value = 0U;
                #line 1158 "src/service_libraries/pus_services/pus_service12.fin"
                value_def.mask_value = 0U;

                #line 1164 "src/service_libraries/pus_services/pus_service12.fin"
                DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1168 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 1170 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t mask = 0U;

                    #line 1171 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t expected_value = 0U;

                    #line 1174 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &mask);

                    #line 1175 "src/service_libraries/pus_services/pus_service12.fin"
                    value_def.mask_value = (uint32_t)mask;

                    #line 1178 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1179 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u8_appdata_field(tc_handler, &expected_value);

                        #line 1180 "src/service_libraries/pus_services/pus_service12.fin"
                        value_def.expected_value = (uint32_t)expected_value;

                    }

                    #line 1184 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1185 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

                    }

                    #line 1188 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamValueCheck;
                    #line 1188 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck.__0 = value_def;

                } else
                #line 1191 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 1194 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler, &value_def.mask_value);

                    #line 1197 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1198 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u32_appdata_field(tc_handler, &value_def.expected_value);

                    }

                    #line 1202 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1203 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

                    }

                    #line 1206 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamValueCheck;
                    #line 1206 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck.__0 = value_def;

                } else
                {
                    
                    #line 1210 "src/service_libraries/pus_services/pus_service12.fin"
                    status.__variant = Failure;
                    #line 1210 "src/service_libraries/pus_services/pus_service12.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            } else
            #line 1215 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
                
                #line 1217 "src/service_libraries/pus_services/pus_service12.fin"
                ParamLimitCheckDefinition limits_def;
                #line 1217 "src/service_libraries/pus_services/pus_service12.fin"
                limits_def.high_limit = 0U;
                #line 1217 "src/service_libraries/pus_services/pus_service12.fin"
                limits_def.high_limit_evID = 0U;
                #line 1217 "src/service_libraries/pus_services/pus_service12.fin"
                limits_def.low_limit = 0U;
                #line 1217 "src/service_libraries/pus_services/pus_service12.fin"
                limits_def.low_limit_evID = 0U;

                #line 1224 "src/service_libraries/pus_services/pus_service12.fin"
                DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1228 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 1230 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t low_limit = 0U;

                    #line 1231 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t high_limit = 0U;

                    #line 1234 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &low_limit);

                    #line 1235 "src/service_libraries/pus_services/pus_service12.fin"
                    limits_def.low_limit = (uint32_t)low_limit;

                    #line 1238 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1239 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.low_limit_evID);

                    }

                    #line 1243 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1244 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u8_appdata_field(tc_handler, &high_limit);

                        #line 1245 "src/service_libraries/pus_services/pus_service12.fin"
                        limits_def.high_limit = (uint32_t)high_limit;

                    }

                    #line 1249 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1250 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.high_limit_evID);

                    }

                    #line 1253 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamLimitCheck;
                    #line 1253 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck.__0 = limits_def;

                } else
                #line 1256 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 1259 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler, &limits_def.low_limit);

                    #line 1262 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1263 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.low_limit_evID);

                    }

                    #line 1267 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1268 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u32_appdata_field(tc_handler, &limits_def.high_limit);

                    }

                    #line 1272 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1273 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.high_limit_evID);

                    }

                    #line 1276 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamLimitCheck;
                    #line 1276 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck.__0 = limits_def;

                } else
                {
                    
                    #line 1280 "src/service_libraries/pus_services/pus_service12.fin"
                    status.__variant = Failure;
                    #line 1280 "src/service_libraries/pus_services/pus_service12.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            } else
            {
                

            }

        }

    } else
    {
        

    }

    #line 1296 "src/service_libraries/pus_services/pus_service12.fin"
    if (status.__variant == Success) {
        
        #line 1298 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 1U) {
            
            #line 1300 "src/service_libraries/pus_services/pus_service12.fin"
            status = PUSService12__exec12_1TC(__ev, self);

        } else
        #line 1302 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 2U) {
            
            #line 1304 "src/service_libraries/pus_services/pus_service12.fin"
            status = PUSService12__exec12_2TC(__ev, self);

        } else
        #line 1306 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 5U) {
            
            #line 1308 "src/service_libraries/pus_services/pus_service12.fin"
            status = PUSService12__exec12_5TC(__ev, self);

        } else
        #line 1310 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 6U) {
            
            #line 1312 "src/service_libraries/pus_services/pus_service12.fin"
            status = PUSService12__exec12_6TC(__ev, self);

        } else
        {
            
            #line 1316 "src/service_libraries/pus_services/pus_service12.fin"
            status.__variant = Failure;
            #line 1316 "src/service_libraries/pus_services/pus_service12.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 1323 "src/service_libraries/pus_services/pus_service12.fin"
    if (status.__variant == Success) {
        
        #line 1325 "src/service_libraries/pus_services/pus_service12.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 1328 "src/service_libraries/pus_services/pus_service12.fin"
        int32_t error_code = status.Failure.__0;

        #line 1330 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 1332 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 1337 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 1339 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 1344 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 1346 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_num_bytes, action_status);

        } else
        #line 1352 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == INVALID_PID_ERROR) {
            
            #line 1354 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.mon_config.PID, action_status);

        } else
        {
            
            #line 1362 "src/service_libraries/pus_services/pus_service12.fin"
            (*action_status).__variant = Failure;
            #line 1362 "src/service_libraries/pus_services/pus_service12.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 1369 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1369 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

MonitorCheckType PUSService12__get_PMON_type(const __termina_event_t * const __ev, const PUSService12 * const self, size_t PMONID) {
    
    #line 761 "src/service_libraries/pus_services/pus_service12.fin"
    MonitorCheckType mon_type;
    #line 761 "src/service_libraries/pus_services/pus_service12.fin"
    mon_type.__variant = MonitorCheckType__Free;

    #line 763 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 765 "src/service_libraries/pus_services/pus_service12.fin"
        mon_type = self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].type;

    }

    #line 768 "src/service_libraries/pus_services/pus_service12.fin"
    return mon_type;

}

void PUSService12__is_PMON_enabled(const __termina_event_t * const __ev, void * const __this, size_t PMONID, _Bool * const is_enabled) {
    
    #line 744 "src/service_libraries/pus_services/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 744 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 746 "src/service_libraries/pus_services/pus_service12.fin"
    *is_enabled = 0;

    #line 748 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 750 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__Free == 0) {
            
            #line 752 "src/service_libraries/pus_services/pus_service12.fin"
            *is_enabled = self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled;

        }

    }

    #line 756 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 756 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}
