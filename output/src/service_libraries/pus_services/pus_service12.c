
#include "service_libraries/pus_services/pus_service12.h"

static _Bool CPUSService12__PID_has_expected_masked_value(const termina__event_t * const termina__ev, const CPUSService12 * const self, const ParamValueCheckDefinition * const expected_value_check_definition);

static _Bool CPUSService12__PID_is_above_upper_limit(const termina__event_t * const termina__ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def);

static _Bool CPUSService12__PID_is_below_lower_limit(const termina__event_t * const termina__ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def);

static Status__i32 CPUSService12__add_monitoring_transition(const termina__event_t * const termina__ev, CPUSService12 * const self);

static void CPUSService12__add_valid_mng_mon_def(const termina__event_t * const termina__ev, CPUSService12 * const self);

static ParamValueCheckDefinition CPUSService12__get_expected_value_monitoring_definition(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static CheckValueResult CPUSService12__check_PID_status_exp_val_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static ParamLimitCheckDefinition CPUSService12__get_limits_monitoring_definition(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static CheckLimitsResult CPUSService12__check_PID_status_limits_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static _Bool CPUSService12__is_expected_value_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static _Bool CPUSService12__is_limits_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static _Bool CPUSService12__is_valid_PMONID(const termina__event_t * const termina__ev, const CPUSService12 * const self);

static _Bool CPUSService12__manage_new_status(const termina__event_t * const termina__ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_expected_value(const termina__event_t * const termina__ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_interval_control(const termina__event_t * const termina__ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_param_above_upper_limit(const termina__event_t * const termina__ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_param_below_lower_limit(const termina__event_t * const termina__ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_param_within_limits(const termina__event_t * const termina__ev, CPUSService12 * const self);

static DoMonitoringReqStatus CPUSService12__manage_unexpected_value(const termina__event_t * const termina__ev, CPUSService12 * const self);

static Status__i32 CPUSService12__exec12_1TC(const termina__event_t * const termina__ev, CPUSService12 * const self);

static void CPUSService12__set_unchecked(const termina__event_t * const termina__ev, CPUSService12 * const self);

static Status__i32 CPUSService12__exec12_2TC(const termina__event_t * const termina__ev, CPUSService12 * const self);

static Status__i32 CPUSService12__exec12_5TC(const termina__event_t * const termina__ev, CPUSService12 * const self);

static Status__i32 CPUSService12__exec12_6TC(const termina__event_t * const termina__ev, CPUSService12 * const self);

static _Bool CPUSService12__PID_has_expected_masked_value(const termina__event_t * const termina__ev, const CPUSService12 * const self, const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    (void)termina__ev;

    #line 261 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 262 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = false;

    #line 263 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

    #line 264 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 265 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 269 "src/service_libraries/pus_services/pus_service12.fin"
    if (type._variant == DataPoolItemType__u32_t) {
        
        #line 270 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 272 "src/service_libraries/pus_services/pus_service12.fin"
    if (type._variant == DataPoolItemType__u8_t) {
        
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

static _Bool CPUSService12__PID_is_above_upper_limit(const termina__event_t * const termina__ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def) {
    
    (void)termina__ev;

    #line 195 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 196 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = false;

    #line 197 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t upper_limit = limit_check_def->high_limit;

    #line 198 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

    #line 199 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 200 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 204 "src/service_libraries/pus_services/pus_service12.fin"
    if (type._variant == DataPoolItemType__u32_t) {
        
        #line 205 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 207 "src/service_libraries/pus_services/pus_service12.fin"
    if (type._variant == DataPoolItemType__u8_t) {
        
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

static _Bool CPUSService12__PID_is_below_lower_limit(const termina__event_t * const termina__ev, const CPUSService12 * const self, const ParamLimitCheckDefinition * const limit_check_def) {
    
    (void)termina__ev;

    #line 228 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 229 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool res = false;

    #line 230 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t lower_limit = limit_check_def->low_limit;

    #line 231 "src/service_libraries/pus_services/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

    #line 232 "src/service_libraries/pus_services/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 233 "src/service_libraries/pus_services/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 237 "src/service_libraries/pus_services/pus_service12.fin"
    if (type._variant == DataPoolItemType__u32_t) {
        
        #line 238 "src/service_libraries/pus_services/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 240 "src/service_libraries/pus_services/pus_service12.fin"
    if (type._variant == DataPoolItemType__u8_t) {
        
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

static Status__i32 CPUSService12__add_monitoring_transition(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 541 "src/service_libraries/pus_services/pus_service12.fin"
    Status__i32 monitoring_status = { ._variant = Status__Success };

    #line 543 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter < 1U) {
        
        #line 545 "src/service_libraries/pus_services/pus_service12.fin"
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        #line 547 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

        #line 548 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        #line 549 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].type;

        #line 551 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info._variant == FaultInfo__ParamOutOfLimit) {
            
            #line 551 "src/service_libraries/pus_services/pus_service12.fin"
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit._0;

            #line 552 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            #line 553 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else
        #line 555 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info._variant == FaultInfo__ParamFaultValue) {
            
            #line 555 "src/service_libraries/pus_services/pus_service12.fin"
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue._0;

            #line 556 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            #line 557 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else
        {
            

        }

        #line 566 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition._variant == MonitorDefinition__ParamValueCheck) {
            
            #line 566 "src/service_libraries/pus_services/pus_service12.fin"
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition.ParamValueCheck._0;

            #line 568 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else
        {
            

        }

        #line 577 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        #line 578 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].prev_status = self->do_monitoring_req_status_update.prev_status;

        #line 579 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_transitions_table[termina__check__array_index(1U, (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].transition_obt;

        #line 581 "src/service_libraries/pus_services/pus_service12.fin"
        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    #line 584 "src/service_libraries/pus_services/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter == 1U) {
        
        #line 586 "src/service_libraries/pus_services/pus_service12.fin"
        Option__box tm_handler = { ._variant = Option__None };

        #line 587 "src/service_libraries/pus_services/pus_service12.fin"
        self->tm_handler_pool.alloc(termina__ev, self->tm_handler_pool._that, &tm_handler);

        #line 591 "src/service_libraries/pus_services/pus_service12.fin"
        if (tm_handler._variant == Option__Some) {
            
            #line 591 "src/service_libraries/pus_services/pus_service12.fin"
            termina__box_t b_tm_handler = tm_handler.Some._0;

            #line 593 "src/service_libraries/pus_services/pus_service12.fin"
            uint16_t tm_count = 0U;

            #line 594 "src/service_libraries/pus_services/pus_service12.fin"
            MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

            #line 595 "src/service_libraries/pus_services/pus_service12.fin"
            self->tm_counter.get_next_tm_count(termina__ev, self->tm_counter._that, &tm_count);

            #line 596 "src/service_libraries/pus_services/pus_service12.fin"
            self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_obt);

            #line 598 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status = build_tm_12_12((TMHandler *)b_tm_handler.data, tm_count, current_obt, self->monitoring_transition_counter, self->param_mon_transitions_table);

            #line 600 "src/service_libraries/pus_services/pus_service12.fin"
            if (monitoring_status._variant == Status__Success) {
                
                #line 601 "src/service_libraries/pus_services/pus_service12.fin"
                self->tm_channel.send_tm(termina__ev, self->tm_channel._that, b_tm_handler, &monitoring_status);

            } else
            {
                
                #line 604 "src/service_libraries/pus_services/pus_service12.fin"
                self->tm_handler_pool.free(termina__ev, self->tm_handler_pool._that, b_tm_handler);

            }

        } else
        {
            
            #line 610 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status._variant = Status__Failure;
            #line 610 "src/service_libraries/pus_services/pus_service12.fin"
            monitoring_status.Failure._0 = TM_POOL_ALLOC_FAILURE;

        }

        #line 616 "src/service_libraries/pus_services/pus_service12.fin"
        self->monitoring_transition_counter = 0U;

    }

    #line 619 "src/service_libraries/pus_services/pus_service12.fin"
    return monitoring_status;

}

static void CPUSService12__add_valid_mng_mon_def(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 902 "src/service_libraries/pus_services/pus_service12.fin"
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.PMONID;

    #line 904 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[termina__check__array_index(16U, PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    #line 906 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[termina__check__array_index(16U, PMONID)].enabled = false;

    #line 909 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 913 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[termina__check__array_index(16U, PMONID)].type._variant == MonitorCheckType__ExpectedValue) {
            
            #line 915 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, PMONID)].current_state._variant = CheckState__ParamValueStatus;
            #line 915 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, PMONID)].current_state.ParamValueStatus._0._variant = Option__None;

        } else
        #line 917 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[termina__check__array_index(16U, PMONID)].type._variant == MonitorCheckType__Limits) {
            
            #line 919 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, PMONID)].current_state._variant = CheckState__ParamLimitStatus;
            #line 919 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, PMONID)].current_state.ParamLimitStatus._0._variant = Option__None;

        } else
        #line 922 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[termina__check__array_index(16U, PMONID)].type._variant == MonitorCheckType__Delta) {
            
            #line 924 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, PMONID)].current_state._variant = CheckState__ParamDeltaStatus;
            #line 924 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, PMONID)].current_state.ParamDeltaStatus._0._variant = Option__None;

        } else
        {
            

        }

    }

    #line 937 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

static ParamValueCheckDefinition CPUSService12__get_expected_value_monitoring_definition(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 108 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 109 "src/service_libraries/pus_services/pus_service12.fin"
    ParamValueCheckDefinition monitoring_definition = { .EvID = 0U, .expected_value = 0U, .mask_value = 0U };

    #line 117 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition._variant == MonitorDefinition__ParamValueCheck) {
        
        #line 117 "src/service_libraries/pus_services/pus_service12.fin"
        ParamValueCheckDefinition param_check_definition = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition.ParamValueCheck._0;

        #line 119 "src/service_libraries/pus_services/pus_service12.fin"
        monitoring_definition = param_check_definition;

    } else
    {
        

    }

    #line 128 "src/service_libraries/pus_services/pus_service12.fin"
    return monitoring_definition;

}

static CheckValueResult CPUSService12__check_PID_status_exp_val_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    #line 176 "src/service_libraries/pus_services/pus_service12.fin"
    ParamValueCheckDefinition current_monitor_definition = CPUSService12__get_expected_value_monitoring_definition(termina__ev, self);

    #line 177 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueResult check_status;

    #line 179 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__PID_has_expected_masked_value(termina__ev, self, &current_monitor_definition)) {
        
        #line 181 "src/service_libraries/pus_services/pus_service12.fin"
        check_status._variant = CheckValueResult__MonitorValueExpected;

    } else
    {
        
        #line 186 "src/service_libraries/pus_services/pus_service12.fin"
        check_status._variant = CheckValueResult__MonitorValueUnexpected;

    }

    #line 190 "src/service_libraries/pus_services/pus_service12.fin"
    return check_status;

}

static ParamLimitCheckDefinition CPUSService12__get_limits_monitoring_definition(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 82 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 83 "src/service_libraries/pus_services/pus_service12.fin"
    ParamLimitCheckDefinition monitoring_definition = { .high_limit = 0U, .high_limit_evID = 0U, .low_limit = 0U, .low_limit_evID = 0U };

    #line 92 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition._variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 92 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition limit_check_def = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition.ParamLimitCheck._0;

        #line 94 "src/service_libraries/pus_services/pus_service12.fin"
        monitoring_definition = limit_check_def;

    } else
    {
        

    }

    #line 102 "src/service_libraries/pus_services/pus_service12.fin"
    return monitoring_definition;

}

static CheckLimitsResult CPUSService12__check_PID_status_limits_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    #line 151 "src/service_libraries/pus_services/pus_service12.fin"
    ParamLimitCheckDefinition current_monitor_definition = CPUSService12__get_limits_monitoring_definition(termina__ev, self);

    #line 152 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsResult check_status;

    #line 154 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__PID_is_above_upper_limit(termina__ev, self, &current_monitor_definition)) {
        
        #line 156 "src/service_libraries/pus_services/pus_service12.fin"
        check_status._variant = CheckLimitsResult__MonitorAboveHighLimit;

    } else
    #line 159 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__PID_is_below_lower_limit(termina__ev, self, &current_monitor_definition)) {
        
        #line 161 "src/service_libraries/pus_services/pus_service12.fin"
        check_status._variant = CheckLimitsResult__MonitorBelowLowLimit;

    } else
    {
        
        #line 167 "src/service_libraries/pus_services/pus_service12.fin"
        check_status._variant = CheckLimitsResult__MonitorWithinLimits;

    }

    #line 170 "src/service_libraries/pus_services/pus_service12.fin"
    return check_status;

}

static _Bool CPUSService12__is_expected_value_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 69 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 70 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_exp_val_mon = false;

    #line 72 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].type._variant == MonitorCheckType__ExpectedValue) {
        
        #line 74 "src/service_libraries/pus_services/pus_service12.fin"
        is_exp_val_mon = true;

    }

    #line 77 "src/service_libraries/pus_services/pus_service12.fin"
    return is_exp_val_mon;

}

static _Bool CPUSService12__is_limits_monitoring(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 55 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 56 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool is_limits_mon = false;

    #line 58 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].type._variant == MonitorCheckType__Limits) {
        
        #line 60 "src/service_libraries/pus_services/pus_service12.fin"
        is_limits_mon = true;

    }

    #line 63 "src/service_libraries/pus_services/pus_service12.fin"
    return is_limits_mon;

}

static _Bool CPUSService12__is_valid_PMONID(const termina__event_t * const termina__ev, const CPUSService12 * const self) {
    
    (void)termina__ev;

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

static _Bool CPUSService12__manage_new_status(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 497 "src/service_libraries/pus_services/pus_service12.fin"
    _Bool transition = false;

    #line 498 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 500 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState new_state = self->do_monitoring_req_status_update.new_status;

    #line 501 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState current_state = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].current_state;

    #line 502 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState temp_state = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].temp_state;

    #line 504 "src/service_libraries/pus_services/pus_service12.fin"
    if (are_status_equal(new_state, current_state) == false) {
        
        #line 506 "src/service_libraries/pus_services/pus_service12.fin"
        if (are_status_equal(new_state, temp_state)) {
            
            #line 508 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition_control = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition_control + 1U;

        } else
        {
            
            #line 512 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].temp_state = new_state;

            #line 513 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition_control = 1U;

            #line 514 "src/service_libraries/pus_services/pus_service12.fin"
            MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

            #line 515 "src/service_libraries/pus_services/pus_service12.fin"
            self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_obt);

            #line 516 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].transition_obt = current_obt;

        }

        #line 519 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition_control >= self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition) {
            
            #line 521 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition_control = 0U;

            #line 522 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.prev_status = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].current_state;

            #line 523 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].current_state = new_state;

            #line 524 "src/service_libraries/pus_services/pus_service12.fin"
            transition = true;

        }

    } else
    {
        
        #line 530 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].temp_state = new_state;

        #line 531 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].repetition_control = 0U;

    }

    #line 535 "src/service_libraries/pus_services/pus_service12.fin"
    return transition;

}

static DoMonitoringReqStatus CPUSService12__manage_expected_value(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 350 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { ._variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 352 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueResult check_status = { ._variant = CheckValueResult__MonitorValueExpected };

    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status._variant = CheckState__ParamValueStatus;
    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus._0._variant = Option__Some;
    #line 353 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus._0.Some._0 = check_status;

    #line 355 "src/service_libraries/pus_services/pus_service12.fin"
    if (CPUSService12__manage_new_status(termina__ev, self)) {
        
        #line 357 "src/service_libraries/pus_services/pus_service12.fin"
        self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(termina__ev, self);

    }

    #line 360 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_interval_control(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 133 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 134 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { ._variant = DoMonitoringReqStatus__Exit };

    #line 136 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].interval_control = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].interval_control + 1U;

    #line 138 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].interval_control >= self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].interval) {
        
        #line 141 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].interval_control = 0U;

        #line 142 "src/service_libraries/pus_services/pus_service12.fin"
        next_status._variant = DoMonitoringReqStatus__GetMonitoringType;

    }

    #line 146 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_param_above_upper_limit(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 365 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { ._variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 367 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsResult check_status = { ._variant = CheckLimitsResult__MonitorAboveHighLimit };

    #line 368 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status._variant = CheckState__ParamLimitStatus;
    #line 368 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus._0._variant = Option__Some;
    #line 368 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus._0.Some._0 = check_status;

    #line 370 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 374 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition._variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 374 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition.ParamLimitCheck._0;

        #line 376 "src/service_libraries/pus_services/pus_service12.fin"
        ParamOutOfLimitInfo fault_info = { .PID = 0U, .PID_limit = 0U, .PID_value = 0U };

        #line 380 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

        #line 381 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_limit = check_definition.high_limit;

        #line 383 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 387 "src/service_libraries/pus_services/pus_service12.fin"
        if (type._variant == DataPoolItemType__u32_t) {
            
            #line 388 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 390 "src/service_libraries/pus_services/pus_service12.fin"
        if (type._variant == DataPoolItemType__u8_t) {
            
            #line 391 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 392 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 393 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 396 "src/service_libraries/pus_services/pus_service12.fin"
            next_status._variant = DoMonitoringReqStatus__Exit;

        }

        #line 400 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(termina__ev, self)) {
            
            #line 402 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = true;

            #line 403 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info._variant = FaultInfo__ParamOutOfLimit;
            #line 403 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit._0 = fault_info;

            #line 404 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(termina__ev, self);

            #line 405 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.high_limit_evID;

        }

    } else
    {
        
        #line 410 "src/service_libraries/pus_services/pus_service12.fin"
        next_status._variant = DoMonitoringReqStatus__Exit;

    }

    #line 415 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_param_below_lower_limit(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 420 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { ._variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 422 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsResult check_status = { ._variant = CheckLimitsResult__MonitorBelowLowLimit };

    #line 423 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status._variant = CheckState__ParamLimitStatus;
    #line 423 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus._0._variant = Option__Some;
    #line 423 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus._0.Some._0 = check_status;

    #line 425 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 429 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition._variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 429 "src/service_libraries/pus_services/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition.ParamLimitCheck._0;

        #line 431 "src/service_libraries/pus_services/pus_service12.fin"
        ParamOutOfLimitInfo fault_info = { .PID = 0U, .PID_limit = 0U, .PID_value = 0U };

        #line 435 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

        #line 436 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_limit = check_definition.low_limit;

        #line 438 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 442 "src/service_libraries/pus_services/pus_service12.fin"
        if (type._variant == DataPoolItemType__u32_t) {
            
            #line 443 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 445 "src/service_libraries/pus_services/pus_service12.fin"
        if (type._variant == DataPoolItemType__u8_t) {
            
            #line 446 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 447 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 448 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 451 "src/service_libraries/pus_services/pus_service12.fin"
            next_status._variant = DoMonitoringReqStatus__Exit;

        }

        #line 455 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(termina__ev, self)) {
            
            #line 457 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = true;

            #line 458 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info._variant = FaultInfo__ParamOutOfLimit;
            #line 458 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit._0 = fault_info;

            #line 459 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(termina__ev, self);

            #line 460 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.low_limit_evID;

        }

    } else
    {
        
        #line 465 "src/service_libraries/pus_services/pus_service12.fin"
        next_status._variant = DoMonitoringReqStatus__Exit;

    }

    #line 469 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_param_within_limits(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 474 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { ._variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 476 "src/service_libraries/pus_services/pus_service12.fin"
    CheckLimitsResult within_limits = { ._variant = CheckLimitsResult__MonitorWithinLimits };

    #line 477 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState new_status = { ._variant = CheckState__ParamLimitStatus, .ParamLimitStatus = { ._0 = { ._variant = Option__Some, .Some = { ._0 = within_limits } } } };

    #line 478 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status = new_status;

    #line 479 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 480 "src/service_libraries/pus_services/pus_service12.fin"
    CheckState current_status = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].current_state;

    #line 482 "src/service_libraries/pus_services/pus_service12.fin"
    if (are_status_equal(new_status, current_status) == false) {
        
        #line 484 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(termina__ev, self)) {
            
            #line 486 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(termina__ev, self);

        }

    }

    #line 490 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

static DoMonitoringReqStatus CPUSService12__manage_unexpected_value(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 293 "src/service_libraries/pus_services/pus_service12.fin"
    DoMonitoringReqStatus next_status = { ._variant = DoMonitoringReqStatus__GetRequestStatusUpdate };

    #line 295 "src/service_libraries/pus_services/pus_service12.fin"
    CheckValueResult check_status = { ._variant = CheckValueResult__MonitorValueUnexpected };

    #line 296 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status._variant = CheckState__ParamValueStatus;
    #line 296 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus._0._variant = Option__Some;
    #line 296 "src/service_libraries/pus_services/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus._0.Some._0 = check_status;

    #line 297 "src/service_libraries/pus_services/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 301 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition._variant == MonitorDefinition__ParamValueCheck) {
        
        #line 301 "src/service_libraries/pus_services/pus_service12.fin"
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].definition.ParamValueCheck._0;

        #line 303 "src/service_libraries/pus_services/pus_service12.fin"
        ParamFaultValueInfo fault_info = { .PID = 0U, .PID_expected_value = 0U, .PID_mask = 0U, .PID_value = 0U };

        #line 308 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[termina__check__array_index(16U, current_PMON_ID)].PID;

        #line 309 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_expected_value = check_definition.expected_value;

        #line 310 "src/service_libraries/pus_services/pus_service12.fin"
        fault_info.PID_mask = check_definition.mask_value;

        #line 312 "src/service_libraries/pus_services/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 316 "src/service_libraries/pus_services/pus_service12.fin"
        if (type._variant == DataPoolItemType__u32_t) {
            
            #line 317 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 319 "src/service_libraries/pus_services/pus_service12.fin"
        if (type._variant == DataPoolItemType__u8_t) {
            
            #line 320 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t value = 0U;

            #line 321 "src/service_libraries/pus_services/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 322 "src/service_libraries/pus_services/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 326 "src/service_libraries/pus_services/pus_service12.fin"
            next_status._variant = DoMonitoringReqStatus__Exit;

        }

        #line 330 "src/service_libraries/pus_services/pus_service12.fin"
        if (CPUSService12__manage_new_status(termina__ev, self)) {
            
            #line 332 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = true;

            #line 333 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info._variant = FaultInfo__ParamFaultValue;
            #line 333 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue._0 = fault_info;

            #line 334 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status = CPUSService12__add_monitoring_transition(termina__ev, self);

            #line 335 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.EvID;

        }

    } else
    {
        
        #line 340 "src/service_libraries/pus_services/pus_service12.fin"
        next_status._variant = DoMonitoringReqStatus__Exit;

    }

    #line 344 "src/service_libraries/pus_services/pus_service12.fin"
    return next_status;

}

void CPUSService12__do_monitoring(const termina__event_t * const termina__ev, void * const termina__this, uint16_t PMONID, uint16_t * const evID, FaultInfo * const fault_info, _Bool * const event_triggered, Status__i32 * const status) {
    
    #line 622 "src/service_libraries/pus_services/pus_service12.fin"
    CPUSService12 * self = (CPUSService12 *)termina__this;

    #line 622 "src/service_libraries/pus_services/pus_service12.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 625 "src/service_libraries/pus_services/pus_service12.fin"
    for (size_t i = 0U; i < 5U && (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__Exit) == false; i = i + 1U) {
        
        #line 627 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__Init) {
            
            #line 629 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.PMONID = PMONID;

            #line 630 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = *evID;

            #line 631 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info = *fault_info;

            #line 632 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status._variant = DoMonitoringReqStatus__CheckPMONID;

            #line 633 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = false;

            #line 634 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status_update.status._variant = Status__Success;

        } else
        #line 637 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__CheckPMONID) {
            
            #line 640 "src/service_libraries/pus_services/pus_service12.fin"
            if (CPUSService12__is_valid_PMONID(termina__ev, self) && self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].enabled == true) {
                
                #line 641 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_interval_control(termina__ev, self);

            } else
            {
                
                #line 643 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status._variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 647 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            #line 649 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].enabled == true) {
                
                #line 652 "src/service_libraries/pus_services/pus_service12.fin"
                if (CPUSService12__is_limits_monitoring(termina__ev, self)) {
                    
                    #line 654 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status._variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else
                #line 657 "src/service_libraries/pus_services/pus_service12.fin"
                if (CPUSService12__is_expected_value_monitoring(termina__ev, self)) {
                    
                    #line 659 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status._variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else
                {
                    
                    #line 663 "src/service_libraries/pus_services/pus_service12.fin"
                    self->do_monitoring_req_status._variant = DoMonitoringReqStatus__Exit;

                }

            } else
            {
                
                #line 668 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status._variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 672 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            #line 674 "src/service_libraries/pus_services/pus_service12.fin"
            CheckLimitsResult limits_monitoring_status = CPUSService12__check_PID_status_limits_monitoring(termina__ev, self);

            #line 677 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status._variant == CheckLimitsResult__MonitorAboveHighLimit) {
                
                #line 679 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_param_above_upper_limit(termina__ev, self);

            } else
            #line 681 "src/service_libraries/pus_services/pus_service12.fin"
            if (limits_monitoring_status._variant == CheckLimitsResult__MonitorBelowLowLimit) {
                
                #line 683 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_param_below_lower_limit(termina__ev, self);

            } else
            {
                
                #line 688 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_param_within_limits(termina__ev, self);

            }

        } else
        #line 694 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            #line 696 "src/service_libraries/pus_services/pus_service12.fin"
            CheckValueResult exp_value_monitoring_status = CPUSService12__check_PID_status_exp_val_monitoring(termina__ev, self);

            #line 699 "src/service_libraries/pus_services/pus_service12.fin"
            if (exp_value_monitoring_status._variant == CheckValueResult__MonitorValueUnexpected) {
                
                #line 700 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_unexpected_value(termina__ev, self);

            } else
            {
                
                #line 704 "src/service_libraries/pus_services/pus_service12.fin"
                self->do_monitoring_req_status = CPUSService12__manage_expected_value(termina__ev, self);

            }

        } else
        #line 710 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__GetRequestStatusUpdate) {
            
            #line 711 "src/service_libraries/pus_services/pus_service12.fin"
            *evID = self->do_monitoring_req_status_update.EvID;

            #line 712 "src/service_libraries/pus_services/pus_service12.fin"
            *fault_info = self->do_monitoring_req_status_update.fault_info;

            #line 713 "src/service_libraries/pus_services/pus_service12.fin"
            *event_triggered = self->do_monitoring_req_status_update.event_triggered;

            #line 714 "src/service_libraries/pus_services/pus_service12.fin"
            *status = self->do_monitoring_req_status_update.status;

            #line 715 "src/service_libraries/pus_services/pus_service12.fin"
            self->do_monitoring_req_status._variant = DoMonitoringReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 724 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->do_monitoring_req_status._variant == DoMonitoringReqStatus__Exit) {
        
        #line 726 "src/service_libraries/pus_services/pus_service12.fin"
        self->do_monitoring_req_status._variant = DoMonitoringReqStatus__Init;

    }

    #line 729 "src/service_libraries/pus_services/pus_service12.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 729 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

static Status__i32 CPUSService12__exec12_1TC(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 774 "src/service_libraries/pus_services/pus_service12.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 776 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 778 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 785 "src/service_libraries/pus_services/pus_service12.fin"
        size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

        #line 786 "src/service_libraries/pus_services/pus_service12.fin"
        _Bool is_valid_PMONID = PMONID < 16U;

        #line 788 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_PMONID) {
            
            #line 790 "src/service_libraries/pus_services/pus_service12.fin"
            if ((self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].type._variant == MonitorCheckType__Free) == false) {
                
                #line 792 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                #line 797 "src/service_libraries/pus_services/pus_service12.fin"
                if (status._variant == Status__Success) {
                    
                    #line 799 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].enabled = true;

                    #line 800 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].interval_control = 0U;

                    #line 801 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].repetition_control = 0U;

                    #line 803 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                } else
                {
                    
                    #line 811 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.send_tm_1_4_PMON_undefined(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

                }

            } else
            {
                
                #line 821 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.send_tm_1_4_PMONID_invalid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

            }

        }

    }

    #line 832 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

static void CPUSService12__set_unchecked(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    (void)termina__ev;

    #line 749 "src/service_libraries/pus_services/pus_service12.fin"
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    #line 753 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].type._variant == MonitorCheckType__ExpectedValue) {
        
        #line 754 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state._variant = CheckState__ParamValueStatus;
        #line 754 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state.ParamValueStatus._0._variant = Option__None;

    } else
    #line 756 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].type._variant == MonitorCheckType__Limits) {
        
        #line 757 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state._variant = CheckState__ParamLimitStatus;
        #line 757 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state.ParamLimitStatus._0._variant = Option__None;

    } else
    #line 759 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].type._variant == MonitorCheckType__Delta) {
        
        #line 760 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state._variant = CheckState__ParamDeltaStatus;
        #line 760 "src/service_libraries/pus_services/pus_service12.fin"
        self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state.ParamDeltaStatus._0._variant = Option__None;

    } else
    {
        

    }

    #line 767 "src/service_libraries/pus_services/pus_service12.fin"
    self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].temp_state = self->param_mon_config_table[termina__check__array_index(16U, valid_PMONID)].current_state;

    #line 769 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

static Status__i32 CPUSService12__exec12_2TC(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 837 "src/service_libraries/pus_services/pus_service12.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 840 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 842 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 850 "src/service_libraries/pus_services/pus_service12.fin"
        _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 16U;

        #line 852 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_PMONID) {
            
            #line 854 "src/service_libraries/pus_services/pus_service12.fin"
            if ((self->param_mon_config_table[termina__check__array_index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type._variant == MonitorCheckType__Free) == false) {
                
                #line 856 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                #line 862 "src/service_libraries/pus_services/pus_service12.fin"
                if (status._variant == Status__Success) {
                    
                    #line 864 "src/service_libraries/pus_services/pus_service12.fin"
                    self->param_mon_config_table[termina__check__array_index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = false;

                    #line 865 "src/service_libraries/pus_services/pus_service12.fin"
                    CPUSService12__set_unchecked(termina__ev, self);

                    #line 867 "src/service_libraries/pus_services/pus_service12.fin"
                    self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                }

            } else
            {
                
                #line 878 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.send_tm_1_4_PMON_undefined(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

            }

        } else
        {
            
            #line 888 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMONID_invalid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        }

    }

    #line 897 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

static Status__i32 CPUSService12__exec12_5TC(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 942 "src/service_libraries/pus_services/pus_service12.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 945 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
        
        #line 947 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.N, &status);

    } else
    #line 953 "src/service_libraries/pus_services/pus_service12.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == false) {
        
        #line 955 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.mon_config.PID, &status);

    } else
    #line 961 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type._variant == MonitorCheckType__Limits) {
        
        #line 963 "src/service_libraries/pus_services/pus_service12.fin"
        if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
            
            #line 965 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            #line 971 "src/service_libraries/pus_services/pus_service12.fin"
            if (status._variant == Status__Success) {
                
                #line 973 "src/service_libraries/pus_services/pus_service12.fin"
                CPUSService12__add_valid_mng_mon_def(termina__ev, self);

                #line 975 "src/service_libraries/pus_services/pus_service12.fin"
                self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            }

        } else
        {
            
            #line 984 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_definition_invalid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.PMONID, &status);

        }

    } else
    #line 992 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type._variant == MonitorCheckType__ExpectedValue) {
        
        #line 994 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 1000 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1002 "src/service_libraries/pus_services/pus_service12.fin"
            CPUSService12__add_valid_mng_mon_def(termina__ev, self);

            #line 1004 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        }

    } else
    {
        
        #line 1013 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_PMON_definition_invalid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.PMONID, &status);

    }

    #line 1021 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

static Status__i32 CPUSService12__exec12_6TC(const termina__event_t * const termina__ev, CPUSService12 * const self) {
    
    #line 1027 "src/service_libraries/pus_services/pus_service12.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 1029 "src/service_libraries/pus_services/pus_service12.fin"
    if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
        
        #line 1031 "src/service_libraries/pus_services/pus_service12.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.N, &status);

    } else
    {
        
        #line 1039 "src/service_libraries/pus_services/pus_service12.fin"
        MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

        #line 1041 "src/service_libraries/pus_services/pus_service12.fin"
        if (PMON_type._variant == MonitorCheckType__Free) {
            
            #line 1043 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_undefined(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        } else
        #line 1049 "src/service_libraries/pus_services/pus_service12.fin"
        if (self->param_mon_config_table[termina__check__array_index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == false) {
            
            #line 1051 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

            #line 1057 "src/service_libraries/pus_services/pus_service12.fin"
            self->param_mon_config_table[termina__check__array_index(16U, (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type._variant = MonitorCheckType__Free;

            #line 1059 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        } else
        {
            
            #line 1067 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PMON_enabled(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_1_2_6.PMONID, &status);

        }

    }

    #line 1078 "src/service_libraries/pus_services/pus_service12.fin"
    return status;

}

void CPUSService12__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status) {
    
    #line 1083 "src/service_libraries/pus_services/pus_service12.fin"
    CPUSService12 * self = (CPUSService12 *)termina__this;

    #line 1083 "src/service_libraries/pus_services/pus_service12.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 1085 "src/service_libraries/pus_services/pus_service12.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 1086 "src/service_libraries/pus_services/pus_service12.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 1088 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 1089 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 1090 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 1091 "src/service_libraries/pus_services/pus_service12.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 1093 "src/service_libraries/pus_services/pus_service12.fin"
    if (subtype == 1U || subtype == 2U || subtype == 6U) {
        
        #line 1095 "src/service_libraries/pus_services/pus_service12.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_1_2_6.N);

        #line 1097 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1098 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

        }

    } else
    #line 1101 "src/service_libraries/pus_services/pus_service12.fin"
    if (subtype == 5U) {
        
        #line 1103 "src/service_libraries/pus_services/pus_service12.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.N);

        #line 1105 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1106 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.PMONID);

        }

        #line 1108 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1109 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

        }

        #line 1111 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1112 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.interval);

        }

        #line 1114 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1115 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data_5.mon_config.repetition);

        }

        #line 1117 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1118 "src/service_libraries/pus_services/pus_service12.fin"
            uint8_t aux = 0U;

            #line 1119 "src/service_libraries/pus_services/pus_service12.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &aux);

            #line 1120 "src/service_libraries/pus_services/pus_service12.fin"
            self->exec_tc_req_status_update.tc_data_5.mon_config.type = get_check_type(aux);

        }

        #line 1123 "src/service_libraries/pus_services/pus_service12.fin"
        if (status._variant == Status__Success) {
            
            #line 1125 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->exec_tc_req_status_update.tc_data_5.mon_config.type._variant == MonitorCheckType__ExpectedValue) {
                
                #line 1127 "src/service_libraries/pus_services/pus_service12.fin"
                ParamValueCheckDefinition value_def = { .EvID = 0U, .expected_value = 0U, .mask_value = 0U };

                #line 1133 "src/service_libraries/pus_services/pus_service12.fin"
                DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1137 "src/service_libraries/pus_services/pus_service12.fin"
                if (type._variant == DataPoolItemType__u8_t) {
                    
                    #line 1139 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t mask = 0U;

                    #line 1142 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &mask);

                    #line 1143 "src/service_libraries/pus_services/pus_service12.fin"
                    value_def.mask_value = (uint32_t)mask;

                    #line 1146 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1147 "src/service_libraries/pus_services/pus_service12.fin"
                        uint8_t expected_value = 0U;

                        #line 1148 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u8_appdata_field(tc_handler, &expected_value);

                        #line 1149 "src/service_libraries/pus_services/pus_service12.fin"
                        value_def.expected_value = (uint32_t)expected_value;

                    }

                    #line 1153 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1154 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

                    }

                    #line 1157 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition._variant = MonitorDefinition__ParamValueCheck;
                    #line 1157 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck._0 = value_def;

                } else
                #line 1160 "src/service_libraries/pus_services/pus_service12.fin"
                if (type._variant == DataPoolItemType__u32_t) {
                    
                    #line 1163 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler, &value_def.mask_value);

                    #line 1166 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1167 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u32_appdata_field(tc_handler, &value_def.expected_value);

                    }

                    #line 1171 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1172 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

                    }

                    #line 1175 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition._variant = MonitorDefinition__ParamValueCheck;
                    #line 1175 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck._0 = value_def;

                } else
                {
                    
                    #line 1179 "src/service_libraries/pus_services/pus_service12.fin"
                    status._variant = Status__Failure;
                    #line 1179 "src/service_libraries/pus_services/pus_service12.fin"
                    status.Failure._0 = INVALID_PID_ERROR;

                }

            } else
            #line 1184 "src/service_libraries/pus_services/pus_service12.fin"
            if (self->exec_tc_req_status_update.tc_data_5.mon_config.type._variant == MonitorCheckType__Limits) {
                
                #line 1186 "src/service_libraries/pus_services/pus_service12.fin"
                ParamLimitCheckDefinition limits_def = { .high_limit = 0U, .high_limit_evID = 0U, .low_limit = 0U, .low_limit_evID = 0U };

                #line 1193 "src/service_libraries/pus_services/pus_service12.fin"
                DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1197 "src/service_libraries/pus_services/pus_service12.fin"
                if (type._variant == DataPoolItemType__u8_t) {
                    
                    #line 1199 "src/service_libraries/pus_services/pus_service12.fin"
                    uint8_t low_limit = 0U;

                    #line 1202 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &low_limit);

                    #line 1203 "src/service_libraries/pus_services/pus_service12.fin"
                    limits_def.low_limit = (uint32_t)low_limit;

                    #line 1206 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1207 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.low_limit_evID);

                    }

                    #line 1211 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1212 "src/service_libraries/pus_services/pus_service12.fin"
                        uint8_t high_limit = 0U;

                        #line 1213 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u8_appdata_field(tc_handler, &high_limit);

                        #line 1214 "src/service_libraries/pus_services/pus_service12.fin"
                        limits_def.high_limit = (uint32_t)high_limit;

                    }

                    #line 1218 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1219 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.high_limit_evID);

                    }

                    #line 1222 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition._variant = MonitorDefinition__ParamLimitCheck;
                    #line 1222 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck._0 = limits_def;

                } else
                #line 1225 "src/service_libraries/pus_services/pus_service12.fin"
                if (type._variant == DataPoolItemType__u32_t) {
                    
                    #line 1228 "src/service_libraries/pus_services/pus_service12.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler, &limits_def.low_limit);

                    #line 1231 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1232 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.low_limit_evID);

                    }

                    #line 1236 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1237 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u32_appdata_field(tc_handler, &limits_def.high_limit);

                    }

                    #line 1241 "src/service_libraries/pus_services/pus_service12.fin"
                    if (status._variant == Status__Success) {
                        
                        #line 1242 "src/service_libraries/pus_services/pus_service12.fin"
                        status = tc_handler_get_u16_appdata_field(tc_handler, &limits_def.high_limit_evID);

                    }

                    #line 1245 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition._variant = MonitorDefinition__ParamLimitCheck;
                    #line 1245 "src/service_libraries/pus_services/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck._0 = limits_def;

                } else
                {
                    
                    #line 1249 "src/service_libraries/pus_services/pus_service12.fin"
                    status._variant = Status__Failure;
                    #line 1249 "src/service_libraries/pus_services/pus_service12.fin"
                    status.Failure._0 = INVALID_PID_ERROR;

                }

            } else
            {
                

            }

        }

    } else
    {
        

    }

    #line 1265 "src/service_libraries/pus_services/pus_service12.fin"
    if (status._variant == Status__Success) {
        
        #line 1267 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 1U) {
            
            #line 1269 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_1TC(termina__ev, self);

        } else
        #line 1271 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 2U) {
            
            #line 1273 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_2TC(termina__ev, self);

        } else
        #line 1275 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 5U) {
            
            #line 1277 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_5TC(termina__ev, self);

        } else
        #line 1279 "src/service_libraries/pus_services/pus_service12.fin"
        if (subtype == 6U) {
            
            #line 1281 "src/service_libraries/pus_services/pus_service12.fin"
            status = CPUSService12__exec12_6TC(termina__ev, self);

        } else
        {
            
            #line 1285 "src/service_libraries/pus_services/pus_service12.fin"
            status._variant = Status__Failure;
            #line 1285 "src/service_libraries/pus_services/pus_service12.fin"
            status.Failure._0 = ACCEPTANCE_ERROR;

        }

    }

    #line 1292 "src/service_libraries/pus_services/pus_service12.fin"
    if (status._variant == Status__Success) {
        
        #line 1294 "src/service_libraries/pus_services/pus_service12.fin"
        (*action_status)._variant = Status__Success;

    } else
    {
        
        #line 1297 "src/service_libraries/pus_services/pus_service12.fin"
        int32_t error_code = status.Failure._0;

        #line 1299 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 1301 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 1306 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 1308 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 1313 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 1315 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_num_bytes, action_status);

        } else
        #line 1321 "src/service_libraries/pus_services/pus_service12.fin"
        if (error_code == INVALID_PID_ERROR) {
            
            #line 1323 "src/service_libraries/pus_services/pus_service12.fin"
            self->pus_service_1.send_tm_1_4_PID_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data_5.mon_config.PID, action_status);

        } else
        {
            
            #line 1331 "src/service_libraries/pus_services/pus_service12.fin"
            (*action_status)._variant = Status__Failure;
            #line 1331 "src/service_libraries/pus_services/pus_service12.fin"
            (*action_status).Failure._0 = error_code;

        }

    }

    #line 1338 "src/service_libraries/pus_services/pus_service12.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 1338 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}

void CPUSService12__is_PMON_enabled(const termina__event_t * const termina__ev, void * const termina__this, size_t PMONID, _Bool * const is_enabled) {
    
    #line 732 "src/service_libraries/pus_services/pus_service12.fin"
    CPUSService12 * self = (CPUSService12 *)termina__this;

    #line 732 "src/service_libraries/pus_services/pus_service12.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 734 "src/service_libraries/pus_services/pus_service12.fin"
    *is_enabled = false;

    #line 736 "src/service_libraries/pus_services/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 738 "src/service_libraries/pus_services/pus_service12.fin"
        if ((self->param_mon_config_table[termina__check__array_index(16U, PMONID)].type._variant == MonitorCheckType__Free) == false) {
            
            #line 740 "src/service_libraries/pus_services/pus_service12.fin"
            *is_enabled = self->param_mon_config_table[termina__check__array_index(16U, (size_t)PMONID)].enabled;

        }

    }

    #line 744 "src/service_libraries/pus_services/pus_service12.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 744 "src/service_libraries/pus_services/pus_service12.fin"
    return;

}
