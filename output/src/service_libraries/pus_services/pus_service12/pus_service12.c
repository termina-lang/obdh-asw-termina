
#include "service_libraries/pus_services/pus_service12/pus_service12.h"

_Bool PUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev,
                                                  const PUSService12 * const self,
                                                  const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool res = 0;

    uint16_t PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                       current_PMON_ID)].PID;

    uint32_t SDP_value = 0U;

    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    if (type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t SDP_value_u8 = 0U;

        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        SDP_value = (uint32_t)SDP_value_u8;

    } else {
        

    }

    if ((uint32_t)(SDP_value & expected_value_check_definition->mask_value) == (uint32_t)(expected_value_check_definition->expected_value & expected_value_check_definition->mask_value)) {
        
        res = 1;

    }

    return res;

}

_Bool PUSService12__PID_is_above_upper_limit(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool res = 0;

    uint32_t upper_limit = limit_check_def->high_limit;

    uint16_t PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                       current_PMON_ID)].PID;

    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    uint32_t SDP_value = 0U;

    if (type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t SDP_value_u8 = 0U;

        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        SDP_value = (uint32_t)SDP_value_u8;

    } else {
        

    }

    if (SDP_value > upper_limit) {
        
        res = 1;

    }

    return res;

}

_Bool PUSService12__PID_is_below_lower_limit(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool res = 0;

    uint32_t lower_limit = limit_check_def->low_limit;

    uint16_t PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                       current_PMON_ID)].PID;

    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    uint32_t SDP_value = 0U;

    if (type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t SDP_value_u8 = 0U;

        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        SDP_value = (uint32_t)SDP_value_u8;

    } else {
        

    }

    if (SDP_value < lower_limit) {
        
        res = 1;

    }

    return res;

}

void PUSService12__add_monitoring_transition(const __termina_event_t * const __ev,
                                             PUSService12 * const self) {
    
    __status_int32_t monitoring_status;
    monitoring_status.__variant = Success;

    if ((size_t)self->monitoring_transition_counter < 1U) {
        
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                         current_PMON_ID)].PID;

        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                          current_PMON_ID)].type;

        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0;

            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0;

            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else {
            

        }

        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
            
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                             current_PMON_ID)].definition.ParamValueCheck.__0;

            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else {
            

        }

        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].prev_status = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                                 current_PMON_ID)].current_state;

        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                               current_PMON_ID)].transition_obt;

        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    if ((size_t)self->monitoring_transition_counter == 1U) {
        
        __option_box_t tm_handler;
        tm_handler.__variant = None;

        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        if (tm_handler.__variant == Some) {
            
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            uint16_t tm_count = 0U;

            MissionObt current_obt;
            current_obt.finetime = 0U;
            current_obt.seconds = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            monitoring_status = build_tm_12_12((TMHandlerT *)b_tm_handler.data,
                                               tm_count, current_obt,
                                               self->monitoring_transition_counter,
                                               self->param_mon_transitions_table);

            if (monitoring_status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &monitoring_status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            monitoring_status.__variant = Failure;
            monitoring_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

        self->monitoring_transition_counter = 0U;

    }

    return;

}

void PUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev,
                                         PUSService12 * const self) {
    
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.mon_config.PID;

    self->param_mon_config_table[__termina_array__index(8U,
                                                        PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    self->param_mon_config_table[__termina_array__index(8U,
                                                        PMONID)].enabled = 0;

    if (PMONID < 8U) {
        
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            CheckValueStatus status;
            status.__variant = CheckValueStatus__MonitorUnchecked;

            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamValueStatus.__0 = status;

        } else if (self->param_mon_config_table[__termina_array__index(8U,
                                                                       PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            CheckLimitsStatus status;
            status.__variant = CheckLimitsStatus__MonitorUnchecked;

            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else if (self->param_mon_config_table[__termina_array__index(8U,
                                                                       PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            CheckDeltaStatus status;
            status.__variant = CheckDeltaStatus__MonitorUnchecked;

            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else {
            

        }

    }

    return;

}

_Bool PUSService12__are_status_equal(const __termina_event_t * const __ev,
                                     const PUSService12 * const self,
                                     CheckState status1, CheckState status2) {
    
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    return equal;

}

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const __termina_event_t * const __ev,
                                                                                 const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    ParamValueCheckDefinition monitoring_definition;
    monitoring_definition.EvID = 0U;
    monitoring_definition.expected_value = 0U;
    monitoring_definition.mask_value = 0U;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        ParamValueCheckDefinition param_check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                               current_PMON_ID)].definition.ParamValueCheck.__0;

        monitoring_definition = param_check_definition;

    } else {
        

    }

    return monitoring_definition;

}

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const __termina_event_t * const __ev,
                                                                   const PUSService12 * const self) {
    
    ParamValueCheckDefinition current_monitor_definition = PUSService12__get_expected_value_monitoring_definition(__ev,
                                                                                                                  self);

    CheckValueStatus check_status;
    check_status.__variant = CheckValueStatus__MonitorUnchecked;

    if (PUSService12__PID_has_expected_masked_value(__ev, self,
                                                    &current_monitor_definition)) {
        
        check_status.__variant = CheckValueStatus__MonitorValueExpected;

    } else {
        
        check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    }

    return check_status;

}

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const __termina_event_t * const __ev,
                                                                         const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    ParamLimitCheckDefinition monitoring_definition;
    monitoring_definition.high_limit = 0U;
    monitoring_definition.high_limit_evID = 0U;
    monitoring_definition.low_limit = 0U;
    monitoring_definition.low_limit_evID = 0U;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition limit_check_def = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                        current_PMON_ID)].definition.ParamLimitCheck.__0;

        monitoring_definition = limit_check_def;

    } else {
        

    }

    return monitoring_definition;

}

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const __termina_event_t * const __ev,
                                                                   const PUSService12 * const self) {
    
    ParamLimitCheckDefinition current_monitor_definition = PUSService12__get_limits_monitoring_definition(__ev,
                                                                                                          self);

    CheckLimitsStatus check_status;
    check_status.__variant = CheckLimitsStatus__MonitorUnchecked;

    if (PUSService12__PID_is_above_upper_limit(__ev, self,
                                               &current_monitor_definition)) {
        
        check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    } else if (PUSService12__PID_is_below_lower_limit(__ev, self,
                                                      &current_monitor_definition)) {
        
        check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    } else {
        
        check_status.__variant = CheckLimitsStatus__MonitorWithinLimits;

    }

    return check_status;

}

_Bool PUSService12__is_expected_value_monitoring(const __termina_event_t * const __ev,
                                                 const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool is_exp_val_mon = 0;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        is_exp_val_mon = 1;

    }

    return is_exp_val_mon;

}

_Bool PUSService12__is_limits_monitoring(const __termina_event_t * const __ev,
                                         const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool is_limits_mon = 0;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].type.__variant == MonitorCheckType__Limits) {
        
        is_limits_mon = 1;

    }

    return is_limits_mon;

}

_Bool PUSService12__is_valid_PMONID(const __termina_event_t * const __ev,
                                    const PUSService12 * const self) {
    
    _Bool is_valid = 0;

    if ((size_t)self->do_monitoring_req_status_update.PMONID < 8U) {
        
        is_valid = 1;

    }

    return is_valid;

}

_Bool PUSService12__manage_new_status(const __termina_event_t * const __ev,
                                      PUSService12 * const self) {
    
    _Bool transition = 0;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    CheckState new_state = self->do_monitoring_req_status_update.new_status;

    CheckState current_state = self->param_mon_config_table[__termina_array__index(8U,
                                                                                   current_PMON_ID)].current_state;

    CheckState temp_state = self->param_mon_config_table[__termina_array__index(8U,
                                                                                current_PMON_ID)].temp_state;

    if (PUSService12__are_status_equal(__ev, self, new_state,
                                       current_state) == 0) {
        
        if (are_status_equal(new_state, temp_state)) {
            
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                           current_PMON_ID)].repetition_control + 1U;

        } else {
            
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].temp_state = new_state;

            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control = 1U;

            MissionObt current_obt;
            current_obt.finetime = 0U;
            current_obt.seconds = 0U;

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].transition_obt = current_obt;

        }

        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control >= self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                            current_PMON_ID)].repetition) {
            
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control = 0U;

            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].current_state = new_state;

            transition = 1;

        }

    } else {
        
        self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].temp_state = new_state;

        self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].repetition_control = 0U;

    }

    return transition;

}

DoMonitoringReqStatus PUSService12__manage_expected_value(const __termina_event_t * const __ev,
                                                          PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    CheckValueStatus check_status;
    check_status.__variant = CheckValueStatus__MonitorValueExpected;

    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    if (PUSService12__manage_new_status(__ev, self)) {
        
        PUSService12__add_monitoring_transition(__ev, self);

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_interval_control(const __termina_event_t * const __ev,
                                                            PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__Exit;

    self->param_mon_config_table[__termina_array__index(8U,
                                                        current_PMON_ID)].interval_control = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                 current_PMON_ID)].interval_control + 1U;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].interval_control >= self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                      current_PMON_ID)].interval) {
        
        self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].interval_control = 0U;

        next_status.__variant = DoMonitoringReqStatus__GetMonitoringType;

    } else {
        
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(const __termina_event_t * const __ev,
                                                                   PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    ParamOutOfLimitInfo fault_info;
    fault_info.PID = 0U;
    fault_info.PID_limit = 0U;
    fault_info.PID_value = 0U;

    CheckLimitsStatus check_status;
    check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        fault_info.PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                             current_PMON_ID)].PID;

        fault_info.PID_limit = check_definition.high_limit;

        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        if (type.__variant == DataPoolItemType__u32_t) {
            
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else if (type.__variant == DataPoolItemType__u8_t) {
            
            uint8_t value = 0U;

            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            fault_info.PID_value = (uint32_t)value;

        } else {
            
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        if (PUSService12__manage_new_status(__ev, self)) {
            
            self->do_monitoring_req_status_update.event_triggered = 1;

            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            PUSService12__add_monitoring_transition(__ev, self);

            self->do_monitoring_req_status_update.EvID = check_definition.high_limit_evID;

        }

    } else {
        
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(const __termina_event_t * const __ev,
                                                                   PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    ParamOutOfLimitInfo fault_info;
    fault_info.PID = 0U;
    fault_info.PID_limit = 0U;
    fault_info.PID_value = 0U;

    CheckLimitsStatus check_status;
    check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        fault_info.PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                             current_PMON_ID)].PID;

        fault_info.PID_limit = check_definition.low_limit;

        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        if (type.__variant == DataPoolItemType__u32_t) {
            
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else if (type.__variant == DataPoolItemType__u8_t) {
            
            uint8_t value = 0U;

            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            fault_info.PID_value = (uint32_t)value;

        } else {
            
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        if (PUSService12__manage_new_status(__ev, self)) {
            
            self->do_monitoring_req_status_update.event_triggered = 1;

            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            PUSService12__add_monitoring_transition(__ev, self);

            self->do_monitoring_req_status_update.EvID = check_definition.low_limit_evID;

        }

    } else {
        
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_within_limits(const __termina_event_t * const __ev,
                                                               PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    CheckLimitsStatus within_limits;
    within_limits.__variant = CheckLimitsStatus__MonitorWithinLimits;

    CheckState new_status;
    new_status.__variant = CheckState__ParamLimitStatus;
    new_status.ParamLimitStatus.__0 = within_limits;

    self->do_monitoring_req_status_update.new_status = new_status;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    CheckState current_status = self->param_mon_config_table[__termina_array__index(8U,
                                                                                    current_PMON_ID)].current_state;

    if (PUSService12__are_status_equal(__ev, self, new_status,
                                       current_status) == 0) {
        
        if (PUSService12__manage_new_status(__ev, self)) {
            
            PUSService12__add_monitoring_transition(__ev, self);

        }

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_unexpected_value(const __termina_event_t * const __ev,
                                                            PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    ParamFaultValueInfo fault_info;
    fault_info.PID = 0U;
    fault_info.PID_expected_value = 0U;
    fault_info.PID_mask = 0U;
    fault_info.PID_value = 0U;

    CheckValueStatus check_status;
    check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                         current_PMON_ID)].definition.ParamValueCheck.__0;

        fault_info.PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                             current_PMON_ID)].PID;

        fault_info.PID_expected_value = check_definition.expected_value;

        fault_info.PID_mask = check_definition.mask_value;

        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        if (type.__variant == DataPoolItemType__u32_t) {
            
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else if (type.__variant == DataPoolItemType__u8_t) {
            
            uint8_t value = 0U;

            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            fault_info.PID_value = (uint32_t)value;

        } else {
            
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        if (PUSService12__manage_new_status(__ev, self)) {
            
            self->do_monitoring_req_status_update.event_triggered = 1;

            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamFaultValue;
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0 = fault_info;

            PUSService12__add_monitoring_transition(__ev, self);

            self->do_monitoring_req_status_update.EvID = check_definition.EvID;

        }

    } else {
        
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    return next_status;

}

void PUSService12__do_monitoring(const __termina_event_t * const __ev,
                                 void * const __this, uint16_t PMONID,
                                 uint16_t * const evID,
                                 FaultInfo * const fault_info,
                                 _Bool * const event_triggered) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    for (size_t i = 0U; i < 4U && self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Init) {
            
            self->do_monitoring_req_status_update.PMONID = PMONID;

            self->do_monitoring_req_status_update.EvID = *evID;

            self->do_monitoring_req_status_update.fault_info = *fault_info;

            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__CheckPMONID;

            self->do_monitoring_req_status_update.event_triggered = 0;

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__CheckPMONID) {
            
            if (PUSService12__is_valid_PMONID(__ev, self)) {
                
                self->do_monitoring_req_status = PUSService12__manage_interval_control(__ev,
                                                                                       self);

            } else {
                
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            if (self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)PMONID)].enabled == 1) {
                
                if (PUSService12__is_limits_monitoring(__ev, self)) {
                    
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else if (PUSService12__is_expected_value_monitoring(__ev,
                                                                      self)) {
                    
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else {
                    
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

                }

            } else {
                
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            CheckLimitsStatus limits_monitoring_status = PUSService12__check_PID_status_limits_monitoring(__ev,
                                                                                                          self);

            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                self->do_monitoring_req_status = PUSService12__manage_param_above_upper_limit(__ev,
                                                                                              self);

            } else if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                self->do_monitoring_req_status = PUSService12__manage_param_below_lower_limit(__ev,
                                                                                              self);

            } else if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                self->do_monitoring_req_status = PUSService12__manage_param_within_limits(__ev,
                                                                                          self);

            } else {
                

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            CheckValueStatus exp_value_monitoring_status = PUSService12__check_PID_status_exp_val_monitoring(__ev,
                                                                                                             self);

            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                self->do_monitoring_req_status = PUSService12__manage_unexpected_value(__ev,
                                                                                       self);

            } else if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                self->do_monitoring_req_status = PUSService12__manage_expected_value(__ev,
                                                                                     self);

            } else {
                

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetRequestStatusUpdate) {
            
            *evID = self->do_monitoring_req_status_update.EvID;

            *fault_info = self->do_monitoring_req_status_update.fault_info;

            *event_triggered = self->do_monitoring_req_status_update.event_triggered;

        } else {
            

        }

    }

    if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit) {
        
        self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

__status_int32_t PUSService12__exec12_1TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                         current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

            _Bool is_valid_PMONID = PMONID < 8U;

            if (is_valid_PMONID) {
                
                if (self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].enabled = 1;

                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].interval_control = 0U;

                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].repetition_control = 0U;

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        if (ack_enabled) {
                            
                            if (status.__variant == Success) {
                                
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else {
                                
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else {
                        
                        status.__variant = Failure;
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                         current_obt);

                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                     current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

void PUSService12__set_unchecked(const __termina_event_t * const __ev,
                                 PUSService12 * const self) {
    
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        CheckValueStatus monitor_unchecked;
        monitor_unchecked.__variant = CheckValueStatus__MonitorUnchecked;

        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamValueStatus;
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.ParamValueStatus.__0 = monitor_unchecked;

    } else if (self->param_mon_config_table[__termina_array__index(8U,
                                                                   valid_PMONID)].type.__variant == MonitorCheckType__Limits) {
        
        CheckLimitsStatus monitor_unchecked;
        monitor_unchecked.__variant = CheckLimitsStatus__MonitorUnchecked;

        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.ParamLimitStatus.__0 = monitor_unchecked;

    } else if (self->param_mon_config_table[__termina_array__index(8U,
                                                                   valid_PMONID)].type.__variant == MonitorCheckType__Delta) {
        
        CheckDeltaStatus monitor_unchecked;
        monitor_unchecked.__variant = CheckDeltaStatus__MonitorUnchecked;

        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.ParamDeltaStatus.__0 = monitor_unchecked;

    } else {
        

    }

    self->param_mon_config_table[__termina_array__index(8U,
                                                        valid_PMONID)].temp_state = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                        valid_PMONID)].current_state;

    return;

}

__status_int32_t PUSService12__exec12_2TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                         current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 8U;

            if (is_valid_PMONID) {
                
                if (self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = 0;

                    PUSService12__set_unchecked(__ev, self);

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        if (ack_enabled) {
                            
                            if (status.__variant == Success) {
                                
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else {
                                
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else {
                        
                        status.__variant = Failure;
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else {
                    
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                         current_obt);

                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                     current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

__status_int32_t PUSService12__exec12_5TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_5.N,
                                                         current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == 0) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                                current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                if (ack_enabled) {
                    
                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                PUSService12__add_valid_mng_mon_def(__ev, self);

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else {
                    
                    status.__variant = Failure;
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                              current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        } else if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                  self->exec_tc_req_status_update.packet_id,
                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                  self->exec_tc_req_status_update.flags_ack,
                                  current_obt, &ack_enabled);

            if (ack_enabled) {
                
                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

            PUSService12__add_valid_mng_mon_def(__ev, self);

            __option_box_t tm_handler2;
            tm_handler2.__variant = None;

            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            if (tm_handler2.__variant == Some) {
                
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                uint16_t tm_count2 = 0U;

                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count2);

                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                      tm_count2,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                if (ack_enabled) {
                    
                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                          tm_count,
                                                          self->exec_tc_req_status_update.packet_id,
                                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                                          self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                          current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

__status_int32_t PUSService12__exec12_6TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    _Bool ack_enabled = 0;

    __status_int32_t status;
    status.__variant = Success;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                         current_obt);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

            if (PMON_type.__variant == MonitorCheckType__Free) {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                     current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else if (self->param_mon_config_table[__termina_array__index(8U,
                                                                           (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == 0) {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                if (ack_enabled) {
                    
                    if (status.__variant == Success) {
                        
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    if (ack_enabled) {
                        
                        if (status.__variant == Success) {
                            
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else {
                            
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else {
                    
                    status.__variant = Failure;
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else {
                
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                status = build_tm_1_4_PMON_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.packet_id,
                                                   self->exec_tc_req_status_update.packet_seq_ctrl,
                                                   self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                   current_obt);

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

void PUSService12__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            if (subtype == 1U || subtype == 2U || subtype == 6U) {
                
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.tc_data_1_2_6.N);

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

                }

            } else if (subtype == 5U) {
                
                uint8_t aux = 0U;

                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.tc_data_5.N);

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_data_5.PMONID);

                }

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                }

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_data_5.mon_config.interval);

                }

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_data_5.mon_config.repetition);

                }

                if (status.__variant == Success) {
                    
                    status = tc_handler_get_u8_appdata_field(tc_handler, &aux);

                    self->exec_tc_req_status_update.tc_data_5.mon_config.type = get_check_type(aux);

                }

                if (status.__variant == Success) {
                    
                    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
                        
                        ParamValueCheckDefinition value_def;
                        value_def.EvID = 0U;
                        value_def.expected_value = 0U;
                        value_def.mask_value = 0U;

                        DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                        if (type.__variant == DataPoolItemType__u8_t) {
                            
                            uint8_t mask = 0U;

                            uint8_t expected_value = 0U;

                            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                     &mask);

                            value_def.mask_value = (uint32_t)mask;

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                         &expected_value);

                                value_def.expected_value = (uint32_t)expected_value;

                            }

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &value_def.EvID);

                            }

                        } else if (type.__variant == DataPoolItemType__u32_t) {
                            
                            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                      &value_def.mask_value);

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                          &value_def.expected_value);

                            }

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &value_def.EvID);

                            }

                        } else {
                            
                            status.__variant = Failure;
                            status.Failure.__0 = INVALID_PID_ERROR;

                        }

                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamValueCheck;
                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck.__0 = value_def;

                    } else if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
                        
                        ParamLimitCheckDefinition limits_def;
                        limits_def.high_limit = 0U;
                        limits_def.high_limit_evID = 0U;
                        limits_def.low_limit = 0U;
                        limits_def.low_limit_evID = 0U;

                        DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                        if (type.__variant == DataPoolItemType__u8_t) {
                            
                            uint8_t low_limit = 0U;

                            uint8_t high_limit = 0U;

                            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                     &low_limit);

                            limits_def.low_limit = (uint32_t)low_limit;

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.low_limit_evID);

                            }

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                         &high_limit);

                                limits_def.high_limit = (uint32_t)high_limit;

                            }

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.high_limit_evID);

                            }

                        } else if (type.__variant == DataPoolItemType__u32_t) {
                            
                            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                      &limits_def.low_limit);

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.low_limit_evID);

                            }

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                          &limits_def.high_limit);

                            }

                            if (status.__variant == Success) {
                                
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.high_limit_evID);

                            }

                        } else {
                            
                            status.__variant = Failure;
                            status.Failure.__0 = INVALID_PID_ERROR;

                        }

                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamLimitCheck;
                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck.__0 = limits_def;

                    } else {
                        

                    }

                }

            } else {
                

            }

            if (status.__variant == Success) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (subtype == 1U) {
                
                status = PUSService12__exec12_1TC(__ev, self);

            } else if (subtype == 2U) {
                
                status = PUSService12__exec12_2TC(__ev, self);

            } else if (subtype == 5U) {
                
                status = PUSService12__exec12_5TC(__ev, self);

            } else if (subtype == 6U) {
                
                status = PUSService12__exec12_6TC(__ev, self);

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else {
            

        }

    }

    if (status.__variant == Success) {
        
        (*action_status).__variant = Success;

    } else {
        
        int32_t error_code = status.Failure.__0;

        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR || error_code == INVALID_PID_ERROR) {
            
            (*action_status).__variant = Success;

            __option_box_t tm_handler;
            tm_handler.__variant = None;

            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            if (tm_handler.__variant == Some) {
                
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                uint16_t tm_count = 0U;

                MissionObt current_obt;
                current_obt.finetime = 0U;
                current_obt.seconds = 0U;

                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                if (error_code == ACCEPTANCE_ERROR) {
                    
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else if (error_code == BUILD_TM_ERROR) {
                    
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else if (error_code == INVALID_PID_ERROR) {
                    
                    status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.packet_id,
                                                        self->exec_tc_req_status_update.packet_seq_ctrl,
                                                        self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                                        current_obt);

                } else {
                    

                }

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else {
            
            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = error_code;

        }

    }

    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

MonitorCheckType PUSService12__get_PMON_type(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             size_t PMONID) {
    
    MonitorCheckType mon_type;
    mon_type.__variant = MonitorCheckType__Free;

    if (PMONID < 8U) {
        
        mon_type = self->param_mon_config_table[__termina_array__index(8U,
                                                                       (size_t)PMONID)].type;

    }

    return mon_type;

}

void PUSService12__is_PMON_enabled(const __termina_event_t * const __ev,
                                   void * const __this, size_t PMONID,
                                   _Bool * const is_enabled) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    if (PMONID < 8U) {
        
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__Free == 0) {
            
            *is_enabled = self->param_mon_config_table[__termina_array__index(8U,
                                                                              (size_t)PMONID)].enabled;

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
