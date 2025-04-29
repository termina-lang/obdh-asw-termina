
#include "service_libraries/pus_services/pus_service12/pus_service12.h"

_Bool PUSService12__PID_has_expected_masked_value(const PUSService12 * const self,
                                                  const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool res = 0;

    uint16_t PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                       current_PMON_ID)].PID;

    uint32_t SDP_value = 0U;

    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    if (type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - sdp_first_u32_param_id]);

    } else if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t SDP_value_u8 = 0U;

        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - sdp_first_u8_param_id]);

        SDP_value = (uint32_t)SDP_value_u8;

    } else {
        

    }

    if ((uint32_t)(SDP_value & expected_value_check_definition->mask_value) == (uint32_t)(expected_value_check_definition->expected_value & expected_value_check_definition->mask_value)) {
        
        res = 1;

    }

    return res;

}

_Bool PUSService12__PID_is_above_upper_limit(const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool res = 0;

    uint32_t upper_limit = limit_check_def->high_limit;

    uint16_t PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                       current_PMON_ID)].PID;

    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    uint32_t SDP_value = 0U;

    if (type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - sdp_first_u32_param_id]);

    } else if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t SDP_value_u8 = 0U;

        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - sdp_first_u8_param_id]);

        SDP_value = (uint32_t)SDP_value_u8;

    } else {
        

    }

    if (SDP_value > upper_limit) {
        
        res = 1;

    }

    return res;

}

_Bool PUSService12__PID_is_below_lower_limit(const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool res = 0;

    uint32_t lower_limit = limit_check_def->low_limit;

    uint16_t PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                       current_PMON_ID)].PID;

    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    uint32_t SDP_value = 0U;

    if (type.__variant == DataPoolItemType__u32_t) {
        
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - sdp_first_u32_param_id]);

    } else if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t SDP_value_u8 = 0U;

        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - sdp_first_u8_param_id]);

        SDP_value = (uint32_t)SDP_value_u8;

    } else {
        

    }

    if (SDP_value < lower_limit) {
        
        res = 1;

    }

    return res;

}

void PUSService12__build_tm_12_12(const PUSService12 * const self,
                                  TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  Result * const result) {
    
    startup_tm(p_tm_handler);

    append_u8_appdata_field(p_tm_handler, self->monitoring_transition_counter,
                            result);

    for (size_t i = 0U; i < max_num_transitions && i < (size_t)self->monitoring_transition_counter; i = i + 1U) {
        
        uint8_t aux_prev_status = 0U;

        uint8_t aux_new_status = 0U;

        append_u16_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                          i)].PMONID,
                                 result);

        append_u16_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                          i)].PID,
                                 result);

        uint8_t type_id = get_type_index(self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                                  i)].type);

        append_u8_appdata_field(p_tm_handler, type_id, result);

        if (self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                     i)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            append_u32_appdata_field(p_tm_handler,
                                     self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                              i)].mask_value,
                                     result);

        }

        aux_prev_status = get_check_status_index(self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                                          i)].prev_status);

        aux_new_status = get_check_status_index(self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                                         i)].new_status);

        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                          i)].new_value,
                                 result);

        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                                          i)].limit_value,
                                 result);

        append_u8_appdata_field(p_tm_handler, aux_prev_status, result);

        append_u8_appdata_field(p_tm_handler, aux_new_status, result);

    }

    if ((*result).__variant == Result__Ok) {
        
        close_tm(p_tm_handler, 12U, 12U, tm_seq_counter, result);

    }

    return;

}

void PUSService12__add_monitoring_transition(PUSService12 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    if ((size_t)self->monitoring_transition_counter < max_num_transitions) {
        
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                 (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                                         current_PMON_ID)].PID;

        self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                 (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                 (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                                          current_PMON_ID)].type;

        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0;

            self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0;

            self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else {
            

        }

        if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
            
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                             current_PMON_ID)].definition.ParamValueCheck.__0;

            self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                     (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else {
            

        }

        self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                 (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                 (size_t)self->monitoring_transition_counter)].prev_status = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                                                 current_PMON_ID)].current_state;

        self->param_mon_transitions_table[__termina_array__index(max_num_transitions,
                                                                 (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                                               current_PMON_ID)].transition_obt;

        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    if ((size_t)self->monitoring_transition_counter == max_num_transitions) {
        
        __option_box_t tm_handler;
        tm_handler.__variant = None;

        (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                        &tm_handler);

        if (tm_handler.__variant == Some) {
            
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            uint16_t tm_count = 0U;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            PUSService12__build_tm_12_12(self, (TMHandlerT *)b_tm_handler.data,
                                         tm_count, &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else {
            
            result.__variant = Result__Error;

        }

        self->monitoring_transition_counter = 0U;

    }

    return;

}

void PUSService12__add_valid_mng_mon_def(PUSService12 * const self) {
    
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.mon_config.PID;

    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                        PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                        PMONID)].enabled = 0;

    if (PMONID < max_num_pmon_ids) {
        
        if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            CheckValueStatus status;
            status.__variant = CheckValueStatus__MonitorUnchecked;

            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].current_state.ParamValueStatus.__0 = status;

        } else if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                       PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            CheckLimitsStatus status;
            status.__variant = CheckLimitsStatus__MonitorUnchecked;

            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                       PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            CheckDeltaStatus status;
            status.__variant = CheckDeltaStatus__MonitorUnchecked;

            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else {
            

        }

    }

    return;

}

_Bool PUSService12__are_status_equal(const PUSService12 * const self,
                                     CheckState status1, CheckState status2) {
    
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    return equal;

}

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    ParamValueCheckDefinition monitoring_definition;
    monitoring_definition.EvID = 0U;
    monitoring_definition.expected_value = 0U;
    monitoring_definition.mask_value = 0U;

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        ParamValueCheckDefinition param_check_definition = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                               current_PMON_ID)].definition.ParamValueCheck.__0;

        monitoring_definition = param_check_definition;

    } else {
        

    }

    return monitoring_definition;

}

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const PUSService12 * const self) {
    
    ParamValueCheckDefinition current_monitor_definition = PUSService12__get_expected_value_monitoring_definition(self);

    CheckValueStatus check_status;
    check_status.__variant = CheckValueStatus__MonitorUnchecked;

    if (PUSService12__PID_has_expected_masked_value(self,
                                                    &current_monitor_definition)) {
        
        check_status.__variant = CheckValueStatus__MonitorValueExpected;

    } else {
        
        check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    }

    return check_status;

}

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    ParamLimitCheckDefinition monitoring_definition;
    monitoring_definition.high_limit = 0U;
    monitoring_definition.high_limit_evID = 0U;
    monitoring_definition.low_limit = 0U;
    monitoring_definition.low_limit_evID = 0U;

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition limit_check_def = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                        current_PMON_ID)].definition.ParamLimitCheck.__0;

        monitoring_definition = limit_check_def;

    } else {
        

    }

    return monitoring_definition;

}

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const PUSService12 * const self) {
    
    ParamLimitCheckDefinition current_monitor_definition = PUSService12__get_limits_monitoring_definition(self);

    CheckLimitsStatus check_status;
    check_status.__variant = CheckLimitsStatus__MonitorUnchecked;

    if (PUSService12__PID_is_above_upper_limit(self,
                                               &current_monitor_definition)) {
        
        check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    } else if (PUSService12__PID_is_below_lower_limit(self,
                                                      &current_monitor_definition)) {
        
        check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    } else {
        
        check_status.__variant = CheckLimitsStatus__MonitorWithinLimits;

    }

    return check_status;

}

_Bool PUSService12__is_expected_value_monitoring(const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool is_exp_val_mon = 0;

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        is_exp_val_mon = 1;

    }

    return is_exp_val_mon;

}

_Bool PUSService12__is_limits_monitoring(const PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    _Bool is_limits_mon = 0;

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].type.__variant == MonitorCheckType__Limits) {
        
        is_limits_mon = 1;

    }

    return is_limits_mon;

}

_Bool PUSService12__is_valid_PMONID(const PUSService12 * const self) {
    
    _Bool is_valid = 0;

    if ((size_t)self->do_monitoring_req_status_update.PMONID < max_num_pmon_ids) {
        
        is_valid = 1;

    }

    return is_valid;

}

_Bool PUSService12__manage_new_status(PUSService12 * const self) {
    
    _Bool transition = 0;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    CheckState new_state = self->do_monitoring_req_status_update.new_status;

    CheckState current_state = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                   current_PMON_ID)].current_state;

    CheckState temp_state = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                current_PMON_ID)].temp_state;

    if (PUSService12__are_status_equal(self, new_state, current_state) == 0) {
        
        if (are_status_equal(new_state, temp_state)) {
            
            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].repetition_control = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                           current_PMON_ID)].repetition_control + 1U;

        } else {
            
            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].temp_state = new_state;

            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].repetition_control = 1U;

        }

        if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].repetition_control >= self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                            current_PMON_ID)].repetition) {
            
            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].repetition_control = 0U;

            self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                current_PMON_ID)].current_state = new_state;

            transition = 1;

        }

    } else {
        
        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].temp_state = new_state;

        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].repetition_control = 0U;

    }

    return transition;

}

DoMonitoringReqStatus PUSService12__manage_expected_value(PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    CheckValueStatus check_status;
    check_status.__variant = CheckValueStatus__MonitorValueExpected;

    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    if (PUSService12__manage_new_status(self)) {
        
        PUSService12__add_monitoring_transition(self);

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_interval_control(PUSService12 * const self) {
    
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__Exit;

    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                        current_PMON_ID)].interval_control = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                 current_PMON_ID)].interval_control + 1U;

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].interval_control >= self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                                      current_PMON_ID)].interval) {
        
        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].interval_control = 0U;

        next_status.__variant = DoMonitoringReqStatus__GetMonitoringType;

    } else {
        
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(PUSService12 * const self) {
    
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

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        fault_info.PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                             current_PMON_ID)].PID;

        fault_info.PID_limit = check_definition.high_limit;

        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        if (type.__variant == DataPoolItemType__u32_t) {
            
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - sdp_first_u32_param_id]);

        } else if (type.__variant == DataPoolItemType__u8_t) {
            
            uint8_t value = 0U;

            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - sdp_first_u8_param_id]);

            fault_info.PID_value = (uint32_t)value;

        } else {
            

        }

        if (PUSService12__manage_new_status(self)) {
            
            self->do_monitoring_req_status_update.event_triggered = 1;

            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            PUSService12__add_monitoring_transition(self);

            self->do_monitoring_req_status_update.EvID = check_definition.high_limit_evID;

        }

    } else {
        

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(PUSService12 * const self) {
    
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

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        fault_info.PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                             current_PMON_ID)].PID;

        fault_info.PID_limit = check_definition.low_limit;

        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        if (type.__variant == DataPoolItemType__u32_t) {
            
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - sdp_first_u32_param_id]);

        } else if (type.__variant == DataPoolItemType__u8_t) {
            
            uint8_t value = 0U;

            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - sdp_first_u8_param_id]);

            fault_info.PID_value = (uint32_t)value;

        } else {
            

        }

        if (PUSService12__manage_new_status(self)) {
            
            self->do_monitoring_req_status_update.event_triggered = 1;

            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            PUSService12__add_monitoring_transition(self);

            self->do_monitoring_req_status_update.EvID = check_definition.low_limit_evID;

        }

    } else {
        

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_within_limits(PUSService12 * const self) {
    
    DoMonitoringReqStatus next_status;
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    CheckLimitsStatus within_limits;
    within_limits.__variant = CheckLimitsStatus__MonitorWithinLimits;

    CheckState new_status;
    new_status.__variant = CheckState__ParamLimitStatus;
    new_status.ParamLimitStatus.__0 = within_limits;

    self->do_monitoring_req_status_update.new_status = new_status;

    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    CheckState current_status = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                    current_PMON_ID)].current_state;

    if (PUSService12__are_status_equal(self, new_status, current_status) == 0) {
        
        if (PUSService12__manage_new_status(self)) {
            
            PUSService12__add_monitoring_transition(self);

        }

    }

    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_unexpected_value(PUSService12 * const self) {
    
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

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                         current_PMON_ID)].definition.ParamValueCheck.__0;

        fault_info.PID = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                             current_PMON_ID)].PID;

        fault_info.PID_expected_value = check_definition.expected_value;

        fault_info.PID_mask = check_definition.mask_value;

        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        if (type.__variant == DataPoolItemType__u32_t) {
            
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - sdp_first_u32_param_id]);

        } else if (type.__variant == DataPoolItemType__u8_t) {
            
            uint8_t value = 0U;

            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - sdp_first_u8_param_id]);

            fault_info.PID_value = (uint32_t)value;

        } else {
            

        }

        if (PUSService12__manage_new_status(self)) {
            
            self->do_monitoring_req_status_update.event_triggered = 1;

            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamFaultValue;
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0 = fault_info;

            PUSService12__add_monitoring_transition(self);

            self->do_monitoring_req_status_update.EvID = check_definition.EvID;

        }

    } else {
        

    }

    return next_status;

}

void PUSService12__do_monitoring(void * const __this, uint16_t PMONID,
                                 uint16_t * const evID,
                                 FaultInfo * const fault_info,
                                 _Bool * const event_triggered) {
    
    PUSService12 * self = (PUSService12 *)__this;

    for (size_t i = 0U; i < 4U && self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Init) {
            
            self->do_monitoring_req_status_update.PMONID = PMONID;

            self->do_monitoring_req_status_update.EvID = *evID;

            self->do_monitoring_req_status_update.fault_info = *fault_info;

            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__CheckPMONID;

            self->do_monitoring_req_status_update.event_triggered = 0;

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__CheckPMONID) {
            
            if (PUSService12__is_valid_PMONID(self)) {
                
                self->do_monitoring_req_status = PUSService12__manage_interval_control(self);

            } else {
                
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                    (size_t)PMONID)].enabled == 1) {
                
                if (PUSService12__is_limits_monitoring(self)) {
                    
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else if (PUSService12__is_expected_value_monitoring(self)) {
                    
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else {
                    
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

                }

            } else {
                
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            CheckLimitsStatus limits_monitoring_status = PUSService12__check_PID_status_limits_monitoring(self);

            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                self->do_monitoring_req_status = PUSService12__manage_param_above_upper_limit(self);

            } else if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                self->do_monitoring_req_status = PUSService12__manage_param_below_lower_limit(self);

            } else if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                self->do_monitoring_req_status = PUSService12__manage_param_within_limits(self);

            } else {
                

            }

        } else if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            CheckValueStatus exp_value_monitoring_status = PUSService12__check_PID_status_exp_val_monitoring(self);

            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                self->do_monitoring_req_status = PUSService12__manage_unexpected_value(self);

            } else if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                self->do_monitoring_req_status = PUSService12__manage_expected_value(self);

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

    return;

}

void PUSService12__do_monitoring__mutex_lock(void * const __this,
                                             uint16_t PMONID,
                                             uint16_t * const evID,
                                             FaultInfo * const fault_info,
                                             _Bool * const event_triggered) {
    
    PUSService12 * self = (PUSService12 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService12__do_monitoring(self, PMONID, evID, fault_info,
                                event_triggered);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService12__do_monitoring__task_lock(void * const __this,
                                            uint16_t PMONID,
                                            uint16_t * const evID,
                                            FaultInfo * const fault_info,
                                            _Bool * const event_triggered) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService12__do_monitoring(__this, PMONID, evID, fault_info,
                                event_triggered);
    __termina_task__unlock(lock);

}

void PUSService12__do_monitoring__event_lock(void * const __this,
                                             uint16_t PMONID,
                                             uint16_t * const evID,
                                             FaultInfo * const fault_info,
                                             _Bool * const event_triggered) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService12__do_monitoring(__this, PMONID, evID, fault_info,
                                event_triggered);
    __termina_event__unlock(lock);

}

PS12ExecTCReqStatus PUSService12__exec12_1TC(PUSService12 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PS12ExecTCReqStatus next_status;
    next_status.__variant = PS12ExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else {
            
            size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

            _Bool is_valid_PMONID = PMONID < max_num_pmon_ids;

            if (is_valid_PMONID) {
                
                if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                        (size_t)PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                        (size_t)PMONID)].enabled = 1;

                    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                        (size_t)PMONID)].interval_control = 0U;

                    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                        (size_t)PMONID)].repetition_control = 0U;

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                    &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                             &tm_count2);

                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, &result);

                        (self->tm_channel.send_tm)(self->tm_channel.__that,
                                                   b_tm_handler2, &result);

                    } else {
                        
                        result.__variant = Result__Error;

                    }

                } else {
                    
                    build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                }

            } else {
                
                build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS12ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS12ExecTCReqStatus__Exit;

    }

    return next_status;

}

void PUSService12__set_unchecked(PUSService12 * const self) {
    
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        CheckValueStatus monitor_unchecked;
        monitor_unchecked.__variant = CheckValueStatus__MonitorUnchecked;

        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamValueStatus;
        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].current_state.ParamValueStatus.__0 = monitor_unchecked;

    } else if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                   valid_PMONID)].type.__variant == MonitorCheckType__Limits) {
        
        CheckLimitsStatus monitor_unchecked;
        monitor_unchecked.__variant = CheckLimitsStatus__MonitorUnchecked;

        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].current_state.ParamLimitStatus.__0 = monitor_unchecked;

    } else if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                   valid_PMONID)].type.__variant == MonitorCheckType__Delta) {
        
        CheckDeltaStatus monitor_unchecked;
        monitor_unchecked.__variant = CheckDeltaStatus__MonitorUnchecked;

        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
        self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                            valid_PMONID)].current_state.ParamDeltaStatus.__0 = monitor_unchecked;

    } else {
        

    }

    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                        valid_PMONID)].temp_state = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                                                                                        valid_PMONID)].current_state;

    return;

}

PS12ExecTCReqStatus PUSService12__exec12_2TC(PUSService12 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PS12ExecTCReqStatus next_status;
    next_status.__variant = PS12ExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else {
            
            _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < max_num_pmon_ids;

            if (is_valid_PMONID) {
                
                if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                    self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = 0;

                    PUSService12__set_unchecked(self);

                    __option_box_t tm_handler2;
                    tm_handler2.__variant = None;

                    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                    &tm_handler2);

                    if (tm_handler2.__variant == Some) {
                        
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        uint16_t tm_count2 = 0U;

                        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                             &tm_count2);

                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, &result);

                        (self->tm_channel.send_tm)(self->tm_channel.__that,
                                                   b_tm_handler2, &result);

                    } else {
                        
                        result.__variant = Result__Error;

                    }

                } else {
                    
                    build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler, &result);

                }

            } else {
                
                build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS12ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS12ExecTCReqStatus__Exit;

    }

    return next_status;

}

PS12ExecTCReqStatus PUSService12__exec12_5TC(PUSService12 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PS12ExecTCReqStatus next_status;
    next_status.__variant = PS12ExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
            
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_5.N,
                                                &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == 0) {
            
            build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                       &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
                
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

                PUSService12__add_valid_mng_mon_def(self);

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count2);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler2, &result);

                } else {
                    
                    result.__variant = Result__Error;

                }

            } else {
                
                build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                     &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        } else if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count, &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

            PUSService12__add_valid_mng_mon_def(self);

            __option_box_t tm_handler2;
            tm_handler2.__variant = None;

            (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                            &tm_handler2);

            if (tm_handler2.__variant == Some) {
                
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                uint16_t tm_count2 = 0U;

                (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                     &tm_count2);

                build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                             &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler2, &result);

            } else {
                
                result.__variant = Result__Error;

            }

        } else {
            
            build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                 tm_count,
                                                 self->exec_tc_req_status_update.packet_id,
                                                 self->exec_tc_req_status_update.packet_error_ctrl,
                                                 self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                 &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS12ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS12ExecTCReqStatus__Exit;

    }

    return next_status;

}

PS12ExecTCReqStatus PUSService12__exec12_6TC(PUSService12 * const self) {
    
    Result result;
    result.__variant = Result__Ok;

    PS12ExecTCReqStatus next_status;
    next_status.__variant = PS12ExecTCReqStatus__Error;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                &result);

            (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                       &result);

        } else {
            
            MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

            if (PMON_type.__variant == MonitorCheckType__Free) {
                
                build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            } else if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                           (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == 0) {
                
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

                self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                                &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count2);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 &result);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               b_tm_handler2, &result);

                } else {
                    
                    result.__variant = Result__Error;

                }

            } else {
                
                build_tm_1_4_PMON_enabled((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_error_ctrl,
                                          self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                          &result);

                (self->tm_channel.send_tm)(self->tm_channel.__that,
                                           b_tm_handler, &result);

            }

        }

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS12ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS12ExecTCReqStatus__Exit;

    }

    return next_status;

}

MonitorDefinition PUSService12__get_PMON_limit_check_definition(const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                Result * const result) {
    
    ParamLimitCheckDefinition limits_def;
    limits_def.high_limit = 0U;
    limits_def.high_limit_evID = 0U;
    limits_def.low_limit = 0U;
    limits_def.low_limit_evID = 0U;

    DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

    if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t low_limit = 0U;

        uint8_t high_limit = 0U;

        *result = tc_handler_get_u8_appdata_field(tc_handler, &low_limit);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.low_limit_evID);

        *result = tc_handler_get_u8_appdata_field(tc_handler, &high_limit);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.high_limit_evID);

        limits_def.low_limit = (uint32_t)low_limit;

        limits_def.high_limit = (uint32_t)high_limit;

    } else if (type.__variant == DataPoolItemType__u32_t) {
        
        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &limits_def.low_limit);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.low_limit_evID);

        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &limits_def.low_limit);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.high_limit_evID);

    } else {
        
        (*result).__variant = Result__Error;

    }

    MonitorDefinition param_limit_check_definition;
    param_limit_check_definition.__variant = MonitorDefinition__ParamLimitCheck;
    param_limit_check_definition.ParamLimitCheck.__0 = limits_def;

    return param_limit_check_definition;

}

MonitorDefinition PUSService12__get_PMON_value_check_definition(const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                Result * const result) {
    
    ParamValueCheckDefinition value_def;
    value_def.EvID = 0U;
    value_def.expected_value = 0U;
    value_def.mask_value = 0U;

    DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

    if (type.__variant == DataPoolItemType__u8_t) {
        
        uint8_t mask = 0U;

        uint8_t expected_value = 0U;

        *result = tc_handler_get_u8_appdata_field(tc_handler, &mask);

        *result = tc_handler_get_u8_appdata_field(tc_handler, &expected_value);

        *result = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

        value_def.mask_value = (uint32_t)mask;

        value_def.expected_value = (uint32_t)expected_value;

    } else if (type.__variant == DataPoolItemType__u32_t) {
        
        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &value_def.mask_value);

        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &value_def.expected_value);

        *result = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

    } else {
        
        (*result).__variant = Result__Error;

    }

    MonitorDefinition expected_value_check_definition;
    expected_value_check_definition.__variant = MonitorDefinition__ParamValueCheck;
    expected_value_check_definition.ParamValueCheck.__0 = value_def;

    return expected_value_check_definition;

}

PS12ExecTCReqStatusUpdate PUSService12__get_TC_params(const PUSService12 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      Result * const result) {
    
    PS12ExecTCReqStatusUpdate tc_data = PS12ExecTCReqStatusUpdate_init();

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *subtype = tc_handler->df_header.subtype;

    if (*subtype == 1U || *subtype == 2U || *subtype == 6U) {
        
        PS12TC_1_2_6_Data tc_data_1_2_6_aux;
        tc_data_1_2_6_aux.N = 0U;
        tc_data_1_2_6_aux.PMONID = 0U;

        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data_1_2_6_aux.N);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &tc_data_1_2_6_aux.PMONID);

        tc_data.tc_data_1_2_6 = tc_data_1_2_6_aux;

    } else if (*subtype == 5U) {
        
        ParamMonitoringConfiguration mon_config_aux;
        mon_config_aux.PID = 0U;
        mon_config_aux.current_state.__variant = CheckState__Unselected;
        mon_config_aux.definition.__variant = MonitorDefinition__Unselected;
        mon_config_aux.enabled = 0;
        mon_config_aux.interval = 0U;
        mon_config_aux.interval_control = 0U;
        mon_config_aux.repetition = 0U;
        mon_config_aux.repetition_control = 0U;
        mon_config_aux.temp_state.__variant = CheckState__Unselected;
        mon_config_aux.transition_obt.tv_sec = 0U;
        mon_config_aux.transition_obt.tv_usec = 0U;
        mon_config_aux.type.__variant = MonitorCheckType__Free;

        uint8_t aux = 0U;

        PS12TC_5_Data tc_data_5_aux;
        tc_data_5_aux.N = 0U;
        tc_data_5_aux.PMONID = 0U;
        tc_data_5_aux.mon_config = mon_config_aux;

        *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data_5_aux.N);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &tc_data_5_aux.PMONID);

        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &tc_data_5_aux.mon_config.PID);

        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data_5_aux.mon_config.interval);

        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data_5_aux.mon_config.repetition);

        *result = tc_handler_get_u8_appdata_field(tc_handler, &aux);

        tc_data_5_aux.mon_config.type = get_check_type(aux);

        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            tc_data_5_aux.mon_config.definition = PUSService12__get_PMON_value_check_definition(self,
                                                                                                tc_handler,
                                                                                                result);

        } else if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            tc_data_5_aux.mon_config.definition = PUSService12__get_PMON_limit_check_definition(self,
                                                                                                tc_handler,
                                                                                                result);

        } else {
            

        }

        tc_data.tc_data_5 = tc_data_5_aux;

    } else {
        

    }

    return tc_data;

}

PS12ExecTCReqStatus PUSService12__manage_short_pack_length_error(const PUSService12 * const self) {
    
    PS12ExecTCReqStatus next_status;
    next_status.__variant = PS12ExecTCReqStatus__Error;

    Result result;
    result.__variant = Result__Ok;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       &result);

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                   &result);

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Error) {
        
        next_status.__variant = PS12ExecTCReqStatus__Error;

    } else {
        
        next_status.__variant = PS12ExecTCReqStatus__Exit;

    }

    return next_status;

}

void PUSService12__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PS12ExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PS12ExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update = PUSService12__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          result);

            if ((*result).__variant == Result__Error) {
                
                self->exec_tc_req_status = PUSService12__manage_short_pack_length_error(self);

            } else {
                
                self->exec_tc_req_status.__variant = PS12ExecTCReqStatus__ExecTC;

            }

        } else if (self->exec_tc_req_status.__variant == PS12ExecTCReqStatus__ExecTC) {
            
            if (subtype == 1U) {
                
                self->exec_tc_req_status = PUSService12__exec12_1TC(self);

            } else if (subtype == 2U) {
                
                self->exec_tc_req_status = PUSService12__exec12_2TC(self);

            } else if (subtype == 5U) {
                
                self->exec_tc_req_status = PUSService12__exec12_5TC(self);

            } else if (subtype == 6U) {
                
                self->exec_tc_req_status = PUSService12__exec12_6TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PS12ExecTCReqStatus__Error;

            }

        } else if (self->exec_tc_req_status.__variant == PS12ExecTCReqStatus__Error) {
            
            (*result).__variant = Result__Error;

            self->exec_tc_req_status.__variant = PS12ExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PS12ExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PS12ExecTCReqStatus__Init;

    }

    return;

}

void PUSService12__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService12__exec_tc(self, tc_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService12__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService12__exec_tc(__this, tc_handler, result);
    __termina_task__unlock(lock);

}

void PUSService12__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService12__exec_tc(__this, tc_handler, result);
    __termina_event__unlock(lock);

}

MonitorCheckType PUSService12__get_PMON_type(const PUSService12 * const self,
                                             size_t PMONID) {
    
    MonitorCheckType mon_type;
    mon_type.__variant = MonitorCheckType__Free;

    if (PMONID < max_num_pmon_ids) {
        
        mon_type = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                       (size_t)PMONID)].type;

    }

    return mon_type;

}

void PUSService12__is_PMON_enabled(void * const __this, size_t PMONID,
                                   _Bool * const is_enabled) {
    
    PUSService12 * self = (PUSService12 *)__this;

    if (PMONID < max_num_pmon_ids) {
        
        if (self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                PMONID)].type.__variant == MonitorCheckType__Free == 0) {
            
            *is_enabled = self->param_mon_config_table[__termina_array__index(max_num_pmon_ids,
                                                                              (size_t)PMONID)].enabled;

        }

    }

    return;

}

void PUSService12__is_PMON_enabled__mutex_lock(void * const __this,
                                               size_t PMONID,
                                               _Bool * const is_enabled) {
    
    PUSService12 * self = (PUSService12 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService12__is_PMON_enabled(self, PMONID, is_enabled);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService12__is_PMON_enabled__task_lock(void * const __this,
                                              size_t PMONID,
                                              _Bool * const is_enabled) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService12__is_PMON_enabled(__this, PMONID, is_enabled);
    __termina_task__unlock(lock);

}

void PUSService12__is_PMON_enabled__event_lock(void * const __this,
                                               size_t PMONID,
                                               _Bool * const is_enabled) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService12__is_PMON_enabled(__this, PMONID, is_enabled);
    __termina_event__unlock(lock);

}
