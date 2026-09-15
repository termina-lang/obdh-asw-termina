
#include "service_libraries/pus_services/pus_service12.h"

static _Bool CPUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev, const CPUSService12 * const self, const ParamValueCheckDefinition * const expected_value_check_definition);

static _Bool CPUSService12__PID_is_above_upper_limit(const __termina_event_t * const __ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def);

static _Bool CPUSService12__PID_is_below_lower_limit(const __termina_event_t * const __ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def);

static __status_int32_t CPUSService12__add_monitoring_transition(const __termina_event_t * const __ev, CPUSService12 * const self);

static void CPUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev, CPUSService12 * const self);

static ParamValueCheckDefinition CPUSService12__get_expected_value_monitoring_definition(const __termina_event_t * const __ev, const CPUSService12 * const self);

static CheckValueStatus CPUSService12__check_PID_status_exp_val_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self);

static ParamLimitCheckDefinition CPUSService12__get_limits_monitoring_definition(const __termina_event_t * const __ev, const CPUSService12 * const self);

static CheckLimitsStatus CPUSService12__check_PID_status_limits_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self);

static _Bool CPUSService12__is_expected_value_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self);

static _Bool CPUSService12__is_limits_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self);

static _Bool CPUSService12__is_valid_PMONID(const __termina_event_t * const __ev, const CPUSService12 * const self);

static _Bool CPUSService12__manage_new_status(const __termina_event_t * const __ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_expected_value(const __termina_event_t * const __ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_interval_control(const __termina_event_t * const __ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_param_above_upper_limit(const __termina_event_t * const __ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_param_below_lower_limit(const __termina_event_t * const __ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_param_within_limits(const __termina_event_t * const __ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_unexpected_value(const __termina_event_t * const __ev, CPUSService12 * const self);

static __status_int32_t CPUSService12__exec12_1TC(const __termina_event_t * const __ev, CPUSService12 * const self);

static void CPUSService12__set_unchecked(const __termina_event_t * const __ev, CPUSService12 * const self);

static __status_int32_t CPUSService12__exec12_2TC(const __termina_event_t * const __ev, CPUSService12 * const self);

static __status_int32_t CPUSService12__exec12_5TC(const __termina_event_t * const __ev, CPUSService12 * const self);

static __status_int32_t CPUSService12__exec12_6TC(const __termina_event_t * const __ev, CPUSService12 * const self);

static _Bool CPUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev, const CPUSService12 * const self, const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    (void)__ev;

    #line 261 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 262 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = false;

    #line 263 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

    #line 264 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 265 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 269 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 270 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 272 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 273 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 274 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 275 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 282 "src/service_libraries/pus_services/pus_service12.fin"
    if ((uint32_t)(SDP_value & expected_value_check_definition->mask_value) == (uint32_t)(expected_value_check_definition->expected_value & expected_value_check_definition->mask_value)) {
        
        #line 284 "src/service_libraries/pus_services/pus_service12.fin"
        res = true;

    }

    #line 287 "src/service_libraries/pus_services/pus_service12.fin"
    return res;

}

static _Bool CPUSService12__PID_is_above_upper_limit(const __termina_event_t * const __ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def) {
    
    (void)__ev;

    #line 195 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 196 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = false;

    #line 197 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t upper_limit = limit_check_def->high_limit;

    #line 198 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

    #line 199 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 200 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 204 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 205 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 207 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 208 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 209 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 211 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 218 "src/service_libraries/pus_services/pus_service12.fin"
    if (SDP_value > upper_limit) {
        
        #line 220 "src/service_libraries/pus_services/pus_service12.fin"
        res = true;

    }

    #line 223 "src/service_libraries/pus_services/pus_service12.fin"
    return res;

}

static _Bool CPUSService12__PID_is_below_lower_limit(const __termina_event_t * const __ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def) {
    
    (void)__ev;

    #line 228 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 229 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = false;

    #line 230 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t lower_limit = limit_check_def->low_limit;

    #line 231 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

    #line 232 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 233 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 237 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 238 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 240 "src/service_libraries/pus_services/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 241 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 242 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 243 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 250 "src/service_libraries/pus_services/pus_service12.fin"
    if (SDP_value < lower_limit) {
        
        #line 252 "src/service_libraries/pus_services/pus_service12.fin"
        res = true;

    }

    #line 255 "src/service_libraries/pus_services/pus_service12.fin"
    return res;

}

static __status_int32_t CPUSService12__add_monitoring_transition(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 541 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t monitoring_status = { .__variant = Success };

    #line 543 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter < 1U) {
        
        #line 545 "src/service_libraries/pus_services/pus_service12.fin"
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        #line 547 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 548 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        #line 549 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].type;

        #line 551 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 551 "src/service_libraries/pus_services/pus_service12.fin"
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0;

            #line 552 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            #line 553 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else
        #line 555 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 555 "src/service_libraries/pus_services/pus_service12.fin"
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0;

            #line 556 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            #line 557 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else
        {
            

        }

        #line 566 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
            
            #line 566 "src/service_libraries/pus_services/pus_service12.fin"
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamValueCheck.__0;

            #line 568 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else
        {
            

        }

        #line 577 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        #line 578 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].prev_status = self->do_monitoring_req_status_update.prev_status;

        #line 579 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U, (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].transition_obt;

        #line 581 "src/service_libraries/pus_services/pus_service12.fin"
        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    #line 584 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter == 1U) {
        
        #line 586 "src/service_libraries/pus_services/pus_service12.fin"
        __option_box_t tm_handler = { .__variant = None };

        #line 587 "src/service_libraries/pus_services/pus_service12.fin"
        self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that, &tm_handler);

        #line 591 "src/service_libraries/pus_services/pus_service12.fin"
        if (tm_handler.__variant == Some) {
            
            #line 591 "src/service_libraries/pus_services/pus_service12.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 593 "src/service_libraries/pus_services/pus_service12.fin"
            uint16_t tm_count = 0U;

            #line 594 "src/service_libraries/pus_services/pus_service12.fin"
            MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

            #line 595 "src/service_libraries/pus_services/pus_service12.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

            #line 596 "src/service_libraries/pus_services/pus_service12.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

            #line 598 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status = build_tm_12_12((TMHandler *)b_tm_handler.data, tm_count, current_obt, self->monitoring_transition_counter, self->param_mon_transitions_table);

            #line 600 "src/service_libraries/pus_services/pus_service12.fin"
            if (monitoring_status.__variant == Success) {
                
                #line 601 "src/service_libraries/pus_services/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, &monitoring_status);

            } else
            {
                
                #line 604 "src/service_libraries/pus_services/pus_service12.fin"
                self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that, b_tm_handler);

            }

        } else
        {
            
            #line 610 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status.__variant = Failure;
            #line 610 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

        #line 616 "src/service_libraries/pus_services/pus_service12.fin"
        self->monitoring_transition_counter = 0U;

    }

    #line 619 "src/service_libraries/pus_services/pus_service12.fin"
    return monitoring_status;

}

static void CPUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    (void)__ev;

    #line 912 "src/service_libraries/pus_services/pus_service12.fin"
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.PMONID;

    #line 914 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    #line 916 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, PMONID)].enabled = false;

    #line 919 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 923 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 925 "src/service_libraries/pus_services/pus_service12.fin"
            CheckValueStatus status = { .__variant = CheckValueStatus__MonitorUnchecked };

            #line 926 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            #line 926 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.ParamValueStatus.__0 = status;

        } else
        #line 928 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            #line 930 "src/service_libraries/pus_services/pus_service12.fin"
            CheckLimitsStatus status = { .__variant = CheckLimitsStatus__MonitorUnchecked };

            #line 931 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            #line 931 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else
        #line 934 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            #line 936 "src/service_libraries/pus_services/pus_service12.fin"
            CheckDeltaStatus status = { .__variant = CheckDeltaStatus__MonitorUnchecked };

            #line 937 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            #line 937 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else
        {
            

        }

    }

    #line 950 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

static ParamValueCheckDefinition CPUSService12__get_expected_value_monitoring_definition(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    (void)__ev;

    #line 108 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 109 "src/service_libraries/pus_services/pus_service12.fin"
    ParamValueCheckDefinition monitoring_definition = { .EvID = 0U, .expected_value = 0U, .mask_value = 0U };

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

static CheckValueStatus CPUSService12__check_PID_status_exp_val_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    #line 176 "src/service_libraries/pus_services/pus_service12.fin"
    ParamValueCheckDefinition current_monitor_definition = CPUSService12__get_expected_value_monitoring_definition(__ev, self);

    #line 177 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueStatus check_status;

    #line 179 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__PID_has_expected_masked_value(__ev, self, &current_monitor_definition)) {
        
        #line 181 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckValueStatus__MonitorValueExpected;

    } else
    {
        
        #line 186 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    }

    #line 190 "src/service_libraries/pus_services/pus_service12.fin"
    return check_status;

}

static ParamLimitCheckDefinition CPUSService12__get_limits_monitoring_definition(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    (void)__ev;

    #line 82 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    ParamLimitCheckDefinition monitoring_definition = { .high_limit = 0U, .high_limit_evID = 0U, .low_limit = 0U, .low_limit_evID = 0U };

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

static CheckLimitsStatus CPUSService12__check_PID_status_limits_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    #line 151 "src/service_libraries/pus_services/pus_service12.fin"
    ParamLimitCheckDefinition current_monitor_definition = CPUSService12__get_limits_monitoring_definition(__ev, self);

    #line 152 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus check_status;

    #line 154 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__PID_is_above_upper_limit(__ev, self, &current_monitor_definition)) {
        
        #line 156 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    } else
    #line 159 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__PID_is_below_lower_limit(__ev, self, &current_monitor_definition)) {
        
        #line 161 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    } else
    {
        
        #line 167 "src/service_libraries/pus_services/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorWithinLimits;

    }

    #line 170 "src/service_libraries/pus_services/pus_service12.fin"
    return check_status;

}

static _Bool CPUSService12__is_expected_value_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    (void)__ev;

    #line 69 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 70 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_exp_val_mon = false;

    #line 72 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 74 "src/service_libraries/pus_services/pus_service12.fin"
        is_exp_val_mon = true;

    }

    #line 77 "src/service_libraries/pus_services/pus_service12.fin"
    return is_exp_val_mon;

}

static _Bool CPUSService12__is_limits_monitoring(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    (void)__ev;

    #line 55 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 56 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_limits_mon = false;

    #line 58 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 60 "src/service_libraries/pus_services/pus_service12.fin"
        is_limits_mon = true;

    }

    #line 63 "src/service_libraries/pus_services/pus_service12.fin"
    return is_limits_mon;

}

static _Bool CPUSService12__is_valid_PMONID(const __termina_event_t * const __ev, const CPUSService12 * const self) {
    
    (void)__ev;

    #line 43 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_valid = false;

    #line 45 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->do_monitoring_req_status_update.PMONID < 16U) {
        
        #line 47 "src/service_libraries/pus_services/pus_service12.fin"
        is_valid = true;

    }

    #line 50 "src/service_libraries/pus_services/pus_service12.fin"
    return is_valid;

}

static _Bool CPUSService12__manage_new_status(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 497 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool transition = false;

    #line 498 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 500 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState new_state = self->do_monitoring_req_status_update.new_status;

    #line 501 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState current_state = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state;

    #line 502 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState temp_state = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].temp_state;

    #line 504 "src/service_libraries/pus_services/pus_service12.fin"
    if (are_status_equal(new_state, current_state) == false) {
        
        #line 506 "src/service_libraries/pus_services/pus_service12.fin"
        if (are_status_equal(new_state, temp_state)) {
            
            #line 508 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control + 1U;

        } else
        {
            
            #line 512 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].temp_state = new_state;

            #line 513 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = 1U;

            #line 514 "src/service_libraries/pus_services/pus_service12.fin"
            MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

            #line 515 "src/service_libraries/pus_services/pus_service12.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

            #line 516 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].transition_obt = current_obt;

        }

        #line 519 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control >= self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition) {
            
            #line 521 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = 0U;

            #line 522 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.prev_status = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state;

            #line 523 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state = new_state;

            #line 524 "src/service_libraries/pus_services/pus_service12.fin"
            transition = true;

        }

    } else
    {
        
        #line 530 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].temp_state = new_state;

        #line 531 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].repetition_control = 0U;

    }

    #line 535 "src/service_libraries/pus_services/pus_service12.fin"
    return transition;

}

static DoMonitoringReqStatus CPUSService12__manage_expected_value(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 350 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { .__variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 352 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueStatus check_status = { .__variant = CheckValueStatus__MonitorValueExpected };

    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    #line 355 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__manage_new_status(__ev, self)) {
        
        #line 357 "src/service_libraries/pus_services/pus_service12.fin"
        self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(__ev, self);

    }

    #line 360 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_interval_control(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    (void)__ev;

    #line 133 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 134 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { .__variant = DoMonitoringReqStatus__Exit };

    #line 136 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control + 1U;

    #line 138 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control >= self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval) {
        
        #line 141 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].interval_control = 0U;

        #line 142 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__GetMonitoringType;

    }

    #line 146 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_param_above_upper_limit(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 365 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { .__variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 367 "src/service_libraries/pus_services/pus_service12.fin"
    ParamOutOfLimitInfo fault_info = { .PID = 0U, .PID_limit = 0U, .PID_value = 0U };

    #line 371 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus check_status = { .__variant = CheckLimitsStatus__MonitorAboveHighLimit };

    #line 372 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    #line 372 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    #line 374 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 378 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 378 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 380 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 381 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_limit = check_definition.high_limit;

        #line 383 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 387 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 388 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 390 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 391 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 392 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 393 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 396 "src/service_libraries/pus_services/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 400 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(__ev, self)) {
            
            #line 402 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = true;

            #line 403 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 403 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 404 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(__ev, self);

            #line 405 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.high_limit_evID;

        }

    } else
    {
        
        #line 410 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 415 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_param_below_lower_limit(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 420 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { .__variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 422 "src/service_libraries/pus_services/pus_service12.fin"
    ParamOutOfLimitInfo fault_info = { .PID = 0U, .PID_limit = 0U, .PID_value = 0U };

    #line 426 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus check_status = { .__variant = CheckLimitsStatus__MonitorBelowLowLimit };

    #line 427 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    #line 427 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    #line 429 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 433 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 433 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 435 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 436 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_limit = check_definition.low_limit;

        #line 438 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 442 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 443 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 445 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 446 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 447 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 448 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 451 "src/service_libraries/pus_services/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 455 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(__ev, self)) {
            
            #line 457 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = true;

            #line 458 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 458 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 459 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(__ev, self);

            #line 460 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.low_limit_evID;

        }

    } else
    {
        
        #line 465 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 469 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_param_within_limits(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 474 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { .__variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 476 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsStatus within_limits = { .__variant = CheckLimitsStatus__MonitorWithinLimits };

    #line 477 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState new_status = { .__variant = CheckState__ParamLimitStatus, .ParamLimitStatus = { .__0 = within_limits } };

    #line 478 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status = new_status;

    #line 479 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 480 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState current_status = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].current_state;

    #line 482 "src/service_libraries/pus_services/pus_service12.fin"
    if (are_status_equal(new_status, current_status) == false) {
        
        #line 484 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(__ev, self)) {
            
            #line 486 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(__ev, self);

        }

    }

    #line 490 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_unexpected_value(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 293 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { .__variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 295 "src/service_libraries/pus_services/pus_service12.fin"
    ParamFaultValueInfo fault_info = { .PID = 0U, .PID_expected_value = 0U, .PID_mask = 0U, .PID_value = 0U };

    #line 300 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueStatus check_status = { .__variant = CheckValueStatus__MonitorValueUnexpected };

    #line 301 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    #line 301 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    #line 302 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 306 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 306 "src/service_libraries/pus_services/pus_service12.fin"
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].definition.ParamValueCheck.__0;

        #line 308 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U, current_PMON_ID)].PID;

        #line 309 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_expected_value = check_definition.expected_value;

        #line 310 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_mask = check_definition.mask_value;

        #line 312 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 316 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 317 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 319 "src/service_libraries/pus_services/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 320 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 321 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 322 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 326 "src/service_libraries/pus_services/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 330 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(__ev, self)) {
            
            #line 332 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = true;

            #line 333 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamFaultValue;
            #line 333 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0 = fault_info;

            #line 334 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(__ev, self);

            #line 335 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.EvID;

        }

    } else
    {
        
        #line 340 "src/service_libraries/pus_services/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 344 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

void CPUSService12__do_monitoring(const __termina_event_t * const __ev, void * const __this, uint16_t PMONID, uint16_t * const evID, FaultInfo * const fault_info, _Bool * const event_triggered, __status_int32_t * const status) {
    
    #line 622 "src/service_libraries/pus_services/pus_service12.fin"
    CPUSService12 * self = (CPUSService12 *)__this;

    #line 622 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 625 "src/service_libraries/pus_services/pus_service12.fin"
    for (size_t i = 0U; i < 5U && (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit) == false; i = i + 1U) {
        
        #line 627 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Init) {
            
            #line 629 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.PMONID = PMONID;

            #line 630 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = *evID;

            #line 631 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info = *fault_info;

            #line 632 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__CheckPMONID;

            #line 633 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = false;

            #line 634 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status.__variant = Success;

        } else
        #line 637 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__CheckPMONID) {
            
            #line 640 "src/service_libraries/pus_services/pus_service12.fin"
            if (CPUSService12__is_valid_PMONID(__ev, self) && self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled == true) {
                
                #line 641 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_interval_control(__ev, self);

            } else
            {
                
                #line 643 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 647 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            #line 649 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled == true) {
                
                #line 652 "src/service_libraries/pus_services/pus_service12.fin"
                if (CPUSService12__is_limits_monitoring(__ev, self)) {
                    
                    #line 654 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else
                #line 657 "src/service_libraries/pus_services/pus_service12.fin"
                if (CPUSService12__is_expected_value_monitoring(__ev, self)) {
                    
                    #line 659 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else
                {
                    
                    #line 663 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

                }

            } else
            {
                
                #line 668 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 672 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            #line 674 "src/service_libraries/pus_services/pus_service12.fin"
            CheckLimitsStatus limits_monitoring_status = CPUSService12__check_PID_status_limits_monitoring(__ev, self);

            #line 677 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                #line 679 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_param_above_upper_limit(__ev, self);

            } else
            #line 681 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                #line 683 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_param_below_lower_limit(__ev, self);

            } else
            #line 686 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                #line 688 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_param_within_limits(__ev, self);

            } else
            {
                

            }

        } else
        #line 697 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            #line 699 "src/service_libraries/pus_services/pus_service12.fin"
            CheckValueStatus exp_value_monitoring_status = CPUSService12__check_PID_status_exp_val_monitoring(__ev, self);

            #line 702 "src/service_libraries/pus_services/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                #line 703 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_unexpected_value(__ev, self);

            } else
            #line 705 "src/service_libraries/pus_services/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                #line 707 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_expected_value(__ev, self);

            } else
            {
                

            }

        } else
        #line 717 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetRequestStatusUpdate) {
            
            #line 718 "src/service_libraries/pus_services/pus_service12.fin"
            *evID = self->do_monitoring_req_status_update.EvID;

            #line 719 "src/service_libraries/pus_services/pus_service12.fin"
            *fault_info = self->do_monitoring_req_status_update.fault_info;

            #line 720 "src/service_libraries/pus_services/pus_service12.fin"
            *event_triggered = self->do_monitoring_req_status_update.event_triggered;

            #line 721 "src/service_libraries/pus_services/pus_service12.fin"
            *status = self->do_monitoring_req_status_update.status;

            #line 722 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 731 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit) {
        
        #line 733 "src/service_libraries/pus_services/pus_service12.fin"
        self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;

    }

    #line 736 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 736 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

static __status_int32_t CPUSService12__exec12_1TC(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 784 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status = { .__variant = Success };

    #line 786 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 788 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 795 "src/service_libraries/pus_services/pus_service12.fin"
        size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

        #line 796 "src/service_libraries/pus_services/pus_service12.fin"
        _Bool is_valid_PMONID = PMONID < 16U;

        #line 798 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_PMONID) {
            
            #line 800 "src/service_libraries/pus_services/pus_service12.fin"
            if ((self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].type.__variant == MonitorCheckType__Free) == false) {
                
                #line 802 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                #line 807 "src/service_libraries/pus_services/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 809 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled = true;

                    #line 810 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].interval_control = 0U;

                    #line 811 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].repetition_control = 0U;

                    #line 813 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                } else
                {
                    
                    #line 821 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.send_tm_1_4_PMON_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

                }

            } else
            {
                
                #line 831 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.send_tm_1_4_PMONID_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

            }

        }

    }

    #line 842 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

static void CPUSService12__set_unchecked(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    (void)__ev;

    #line 756 "src/service_libraries/pus_services/pus_service12.fin"
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    #line 760 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 761 "src/service_libraries/pus_services/pus_service12.fin"
        CheckValueStatus monitor_unchecked = { .__variant = CheckValueStatus__MonitorUnchecked };

        #line 762 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.__variant = CheckState__ParamValueStatus;
        #line 762 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.ParamValueStatus.__0 = monitor_unchecked;

    } else
    #line 764 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 765 "src/service_libraries/pus_services/pus_service12.fin"
        CheckLimitsStatus monitor_unchecked = { .__variant = CheckLimitsStatus__MonitorUnchecked };

        #line 766 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
        #line 766 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.ParamLimitStatus.__0 = monitor_unchecked;

    } else
    #line 768 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].type.__variant == MonitorCheckType__Delta) {
        
        #line 769 "src/service_libraries/pus_services/pus_service12.fin"
        CheckDeltaStatus monitor_unchecked = { .__variant = CheckDeltaStatus__MonitorUnchecked };

        #line 770 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
        #line 770 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state.ParamDeltaStatus.__0 = monitor_unchecked;

    } else
    {
        

    }

    #line 777 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].temp_state = self->param_mon_config_table[__termina_array__index(16U, valid_PMONID)].current_state;

    #line 779 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

static __status_int32_t CPUSService12__exec12_2TC(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 847 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status = { .__variant = Success };

    #line 850 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 852 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 860 "src/service_libraries/pus_services/pus_service12.fin"
        _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 16U;

        #line 862 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_PMONID) {
            
            #line 864 "src/service_libraries/pus_services/pus_service12.fin"
            if ((self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free) == false) {
                
                #line 866 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                #line 872 "src/service_libraries/pus_services/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 874 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = false;

                    #line 875 "src/service_libraries/pus_services/pus_service12.fin"
                    CPUSService12__set_unchecked(__ev, self);

                    #line 877 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                }

            } else
            {
                
                #line 888 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.send_tm_1_4_PMON_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

            }

        } else
        {
            
            #line 898 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMONID_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        }

    }

    #line 907 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

static __status_int32_t CPUSService12__exec12_5TC(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 955 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status = { .__variant = Success };

    #line 958 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
        
        #line 960 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.N, &status);

    } else
    #line 966 "src/service_libraries/pus_services/pus_service12.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == false) {
        
        #line 968 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.mon_config.PID, &status);

    } else
    #line 974 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
        
        #line 976 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
            
            #line 978 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            #line 984 "src/service_libraries/pus_services/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 986 "src/service_libraries/pus_services/pus_service12.fin"
                CPUSService12__add_valid_mng_mon_def(__ev, self);

                #line 988 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            }

        } else
        {
            
            #line 997 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_definition_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.PMONID, &status);

        }

    } else
    #line 1005 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 1007 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 1013 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1015 "src/service_libraries/pus_services/pus_service12.fin"
            CPUSService12__add_valid_mng_mon_def(__ev, self);

            #line 1017 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        }

    } else
    {
        
        #line 1026 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_PMON_definition_invalid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.PMONID, &status);

    }

    #line 1034 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

static __status_int32_t CPUSService12__exec12_6TC(const __termina_event_t * const __ev, CPUSService12 * const self) {
    
    #line 1040 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status = { .__variant = Success };

    #line 1042 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 1044 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 1052 "src/service_libraries/pus_services/pus_service12.fin"
        MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

        #line 1054 "src/service_libraries/pus_services/pus_service12.fin"
        if (PMON_type.__variant == MonitorCheckType__Free) {
            
            #line 1056 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_undefined(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        } else
        #line 1062 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == false) {
            
            #line 1064 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            #line 1070 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

            #line 1072 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        } else
        {
            
            #line 1080 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_enabled(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        }

    }

    #line 1091 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

void CPUSService12__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 1096 "src/service_libraries/pus_services/pus_service12.fin"
    CPUSService12 * self = (CPUSService12 *)__this;

    #line 1096 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 1098 "src/service_libraries/pus_services/pus_service12.fin"
    __status_int32_t status = { .__variant = Success };

    #line 1099 "src/service_libraries/pus_services/pus_service12.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 1101 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 1102 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 1103 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 1104 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 1106 "src/service_libraries/pus_services/pus_service12.fin"
    if (subtype == 1U || subtype == 2U || subtype == 6U) {
        
        #line 1108 "src/service_libraries/pus_services/pus_service12.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_1_2_6.N);

        #line 1110 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1111 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

        }

    } else
    #line 1114 "src/service_libraries/pus_services/pus_service12.fin"
    if (subtype == 5U) {
        
        #line 1116 "src/service_libraries/pus_services/pus_service12.fin"
        uint8_t aux = 0U;

        #line 1118 "src/service_libraries/pus_services/pus_service12.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.N);

        #line 1120 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1121 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.PMONID);

        }

        #line 1123 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1124 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

        }

        #line 1126 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1127 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.interval);

        }

        #line 1129 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1130 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.repetition);

        }

        #line 1132 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1133 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &aux);

            #line 1134 "src/service_libraries/pus_services/pus_service12.fin"
            self->exec_tc_req_status_update.tc_data_5.mon_config.type = get_check_type(aux);

        }

        #line 1137 "src/service_libraries/pus_services/pus_service12.fin"
        if (status.__variant == Success) {
            
            #line 1139 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
                
                #line 1141 "src/service_libraries/pus_services/pus_service12.fin"
                ParamValueCheckDefinition value_def = { .EvID = 0U, .expected_value = 0U, .mask_value = 0U };

                #line 1147 "src/service_libraries/pus_services/pus_service12.fin"
                DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1151 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 1153 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t mask = 0U;

                    #line 1154 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t expected_value = 0U;

                    #line 1157 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &mask);

                    #line 1158 "src/service_libraries/pus_services/pus_service12.fin"
                    value_def.mask_value = (uint32_t)mask;

                    #line 1161 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1162 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u8_appdata_field(tc_handler, &expected_value);

                        #line 1163 "src/service_libraries/pus_services/pus_service12.fin"
                        value_def.expected_value = (uint32_t)expected_value;

                    }

                    #line 1167 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1168 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

                    }

                    #line 1171 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamValueCheck;
                    #line 1171 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck.__0 = value_def;

                } else
                #line 1174 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 1177 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler, &value_def.mask_value);

                    #line 1180 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1181 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u32_appdata_field(tc_handler, &value_def.expected_value);

                    }

                    #line 1185 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1186 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

                    }

                    #line 1189 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamValueCheck;
                    #line 1189 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck.__0 = value_def;

                } else
                {
                    
                    #line 1193 "src/service_libraries/pus_services/pus_service12.fin"
                    status.__variant = Failure;
                    #line 1193 "src/service_libraries/pus_services/pus_service12.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            } else
            #line 1198 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
                
                #line 1200 "src/service_libraries/pus_services/pus_service12.fin"
                ParamLimitCheckDefinition limits_def = { .high_limit = 0U, .high_limit_evID = 0U, .low_limit = 0U, .low_limit_evID = 0U };

                #line 1207 "src/service_libraries/pus_services/pus_service12.fin"
                DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1211 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 1213 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t low_limit = 0U;

                    #line 1214 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t high_limit = 0U;

                    #line 1217 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &low_limit);

                    #line 1218 "src/service_libraries/pus_services/pus_service12.fin"
                    limits_def.low_limit = (uint32_t)low_limit;

                    #line 1221 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1222 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.low_limit_evID);

                    }

                    #line 1226 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1227 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u8_appdata_field(tc_handler, &high_limit);

                        #line 1228 "src/service_libraries/pus_services/pus_service12.fin"
                        limits_def.high_limit = (uint32_t)high_limit;

                    }

                    #line 1232 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1233 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.high_limit_evID);

                    }

                    #line 1236 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamLimitCheck;
                    #line 1236 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck.__0 = limits_def;

                } else
                #line 1239 "src/service_libraries/pus_services/pus_service12.fin"
                if (type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 1242 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler, &limits_def.low_limit);

                    #line 1245 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1246 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.low_limit_evID);

                    }

                    #line 1250 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1251 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u32_appdata_field(tc_handler, &limits_def.high_limit);

                    }

                    #line 1255 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1256 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.high_limit_evID);

                    }

                    #line 1259 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamLimitCheck;
                    #line 1259 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck.__0 = limits_def;

                } else
                {
                    
                    #line 1263 "src/service_libraries/pus_services/pus_service12.fin"
                    status.__variant = Failure;
                    #line 1263 "src/service_libraries/pus_services/pus_service12.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            } else
            {
                

            }

        }

    } else
    {
        

    }

    #line 1279 "src/service_libraries/pus_services/pus_service12.fin"
    if (status.__variant == Success) {
        
        #line 1281 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 1U) {
            
            #line 1283 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_1TC(__ev, self);

        } else
        #line 1285 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 2U) {
            
            #line 1287 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_2TC(__ev, self);

        } else
        #line 1289 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 5U) {
            
            #line 1291 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_5TC(__ev, self);

        } else
        #line 1293 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 6U) {
            
            #line 1295 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_6TC(__ev, self);

        } else
        {
            
            #line 1299 "src/service_libraries/pus_services/pus_service12.fin"
            status.__variant = Failure;
            #line 1299 "src/service_libraries/pus_services/pus_service12.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 1306 "src/service_libraries/pus_services/pus_service12.fin"
    if (status.__variant == Success) {
        
        #line 1308 "src/service_libraries/pus_services/pus_service12.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 1311 "src/service_libraries/pus_services/pus_service12.fin"
        int32_t error_code = status.Failure.__0;

        #line 1313 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 1315 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 1320 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 1322 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 1327 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 1329 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_num_bytes, action_status);

        } else
        #line 1335 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == INVALID_PID_ERROR) {
            
            #line 1337 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.mon_config.PID, action_status);

        } else
        {
            
            #line 1345 "src/service_libraries/pus_services/pus_service12.fin"
            (*action_status).__variant = Failure;
            #line 1345 "src/service_libraries/pus_services/pus_service12.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 1352 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1352 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

void CPUSService12__is_PMON_enabled(const __termina_event_t * const __ev, void * const __this, size_t PMONID, _Bool * const is_enabled) {
    
    #line 739 "src/service_libraries/pus_services/pus_service12.fin"
    CPUSService12 * self = (CPUSService12 *)__this;

    #line 739 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 741 "src/service_libraries/pus_services/pus_service12.fin"
    *is_enabled = false;

    #line 743 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 745 "src/service_libraries/pus_services/pus_service12.fin"
        if ((self->param_mon_config_table[__termina_array__index(16U, PMONID)].type.__variant == MonitorCheckType__Free) == false) {
            
            #line 747 "src/service_libraries/pus_services/pus_service12.fin"
            *is_enabled = self->param_mon_config_table[__termina_array__index(16U, (size_t)PMONID)].enabled;

        }

    }

    #line 751 "src/service_libraries/pus_services/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 751 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}
