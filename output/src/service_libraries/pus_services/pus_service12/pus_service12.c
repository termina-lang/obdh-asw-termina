
#include "service_libraries/pus_services/pus_service12/pus_service12.h"

_Bool PUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev,
                                                  const PUSService12 * const self,
                                                  const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    #line 262 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 263 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool res = 0;

    #line 264 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                       current_PMON_ID)].PID;

    #line 265 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 266 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 270 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 271 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 273 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 274 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 275 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 276 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 283 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((uint32_t)(SDP_value & expected_value_check_definition->mask_value) == (uint32_t)(expected_value_check_definition->expected_value & expected_value_check_definition->mask_value)) {
        
        #line 285 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        res = 1;

    }

    #line 288 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return res;

}

_Bool PUSService12__PID_is_above_upper_limit(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def) {
    
    #line 196 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 197 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool res = 0;

    #line 198 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint32_t upper_limit = limit_check_def->high_limit;

    #line 199 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                       current_PMON_ID)].PID;

    #line 200 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 201 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 205 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 206 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 208 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 209 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 210 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 211 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 218 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (SDP_value > upper_limit) {
        
        #line 220 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        res = 1;

    }

    #line 223 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return res;

}

_Bool PUSService12__PID_is_below_lower_limit(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def) {
    
    #line 229 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 230 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool res = 0;

    #line 231 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint32_t lower_limit = limit_check_def->low_limit;

    #line 232 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                       current_PMON_ID)].PID;

    #line 233 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(PID);

    #line 234 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint32_t SDP_value = 0U;

    #line 238 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 239 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID - 0U]);

    } else
    #line 241 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 242 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t SDP_value_u8 = 0U;

        #line 243 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value_u8 = atomic_load(&self->system_data_pool_u8[(size_t)PID - 11U]);

        #line 244 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        SDP_value = (uint32_t)SDP_value_u8;

    } else
    {
        

    }

    #line 251 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (SDP_value < lower_limit) {
        
        #line 253 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        res = 1;

    }

    #line 256 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return res;

}

void PUSService12__add_monitoring_transition(const __termina_event_t * const __ev,
                                             PUSService12 * const self) {
    
    #line 552 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t monitoring_status;
    #line 552 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_status.__variant = Success;

    #line 554 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter < 1U) {
        
        #line 556 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        #line 558 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                                         current_PMON_ID)].PID;

        #line 559 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        #line 560 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                                          current_PMON_ID)].type;

        #line 562 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 561 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0;

            #line 563 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            #line 564 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else
        #line 566 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 561 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0;

            #line 567 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            #line 568 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else
        {
            

        }

        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
            
            #line 576 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                             current_PMON_ID)].definition.ParamValueCheck.__0;

            #line 579 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else
        {
            

        }

        #line 588 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        #line 589 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].prev_status = self->do_monitoring_req_status_update.prev_status;

        #line 590 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                                               current_PMON_ID)].transition_obt;

        #line 592 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    #line 595 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter == 1U) {
        
        #line 597 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __option_box_t tm_handler;
        #line 597 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tm_handler.__variant = None;

        #line 598 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        #line 602 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (tm_handler.__variant == Some) {
            
            #line 600 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 604 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            uint16_t tm_count = 0U;

            #line 605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            MissionObt current_obt;
            #line 605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            current_obt.finetime = 0U;
            #line 605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            current_obt.seconds = 0U;

            #line 606 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 607 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 609 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            monitoring_status = build_tm_12_12((TMHandlerT *)b_tm_handler.data,
                                               tm_count, current_obt,
                                               self->monitoring_transition_counter,
                                               self->param_mon_transitions_table);

            #line 611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (monitoring_status.__variant == Success) {
                
                #line 612 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &monitoring_status);

            } else
            {
                
                #line 616 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 622 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            monitoring_status.__variant = Failure;
            #line 622 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            monitoring_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

        #line 628 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->monitoring_transition_counter = 0U;

    }

    #line 631 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

void PUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev,
                                         PUSService12 * const self) {
    
    #line 1096 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.PMONID;

    #line 1098 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U,
                                                        PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    #line 1100 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U,
                                                        PMONID)].enabled = 0;

    #line 1103 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 1107 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1109 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckValueStatus status;
            #line 1109 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckValueStatus__MonitorUnchecked;

            #line 1110 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            #line 1110 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].current_state.ParamValueStatus.__0 = status;

        } else
        #line 1112 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            #line 1114 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckLimitsStatus status;
            #line 1114 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckLimitsStatus__MonitorUnchecked;

            #line 1115 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            #line 1115 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else
        #line 1118 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            #line 1120 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckDeltaStatus status;
            #line 1120 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckDeltaStatus__MonitorUnchecked;

            #line 1121 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            #line 1121 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else
        {
            

        }

    }

    #line 1134 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

_Bool PUSService12__are_status_equal(const __termina_event_t * const __ev,
                                     const PUSService12 * const self,
                                     CheckState status1, CheckState status2) {
    
    #line 499 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 500 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return equal;

}

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const __termina_event_t * const __ev,
                                                                                 const PUSService12 * const self) {
    
    #line 105 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 106 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamValueCheckDefinition monitoring_definition;
    #line 106 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.EvID = 0U;
    #line 106 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.expected_value = 0U;
    #line 106 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.mask_value = 0U;

    #line 114 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 112 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamValueCheckDefinition param_check_definition = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                               current_PMON_ID)].definition.ParamValueCheck.__0;

        #line 116 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitoring_definition = param_check_definition;

    } else
    {
        

    }

    #line 125 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return monitoring_definition;

}

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const __termina_event_t * const __ev,
                                                                   const PUSService12 * const self) {
    
    #line 175 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamValueCheckDefinition current_monitor_definition = PUSService12__get_expected_value_monitoring_definition(__ev,
                                                                                                                  self);

    #line 176 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckValueStatus check_status;
    #line 176 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorUnchecked;

    #line 178 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__PID_has_expected_masked_value(__ev, self,
                                                    &current_monitor_definition)) {
        
        #line 180 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        check_status.__variant = CheckValueStatus__MonitorValueExpected;

    } else
    {
        
        #line 185 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    }

    #line 189 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return check_status;

}

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const __termina_event_t * const __ev,
                                                                         const PUSService12 * const self) {
    
    #line 79 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 80 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamLimitCheckDefinition monitoring_definition;
    #line 80 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.high_limit = 0U;
    #line 80 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.high_limit_evID = 0U;
    #line 80 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.low_limit = 0U;
    #line 80 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_definition.low_limit_evID = 0U;

    #line 89 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 87 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamLimitCheckDefinition limit_check_def = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                        current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 91 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitoring_definition = limit_check_def;

    } else
    {
        

    }

    #line 99 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return monitoring_definition;

}

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const __termina_event_t * const __ev,
                                                                   const PUSService12 * const self) {
    
    #line 150 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamLimitCheckDefinition current_monitor_definition = PUSService12__get_limits_monitoring_definition(__ev,
                                                                                                          self);

    #line 151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorUnchecked;

    #line 153 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__PID_is_above_upper_limit(__ev, self,
                                               &current_monitor_definition)) {
        
        #line 155 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    } else
    #line 158 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__PID_is_below_lower_limit(__ev, self,
                                               &current_monitor_definition)) {
        
        #line 160 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    } else
    {
        
        #line 166 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorWithinLimits;

    }

    #line 169 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return check_status;

}

_Bool PUSService12__is_expected_value_monitoring(const __termina_event_t * const __ev,
                                                 const PUSService12 * const self) {
    
    #line 66 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 67 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool is_exp_val_mon = 0;

    #line 69 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 71 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        is_exp_val_mon = 1;

    }

    #line 74 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return is_exp_val_mon;

}

_Bool PUSService12__is_limits_monitoring(const __termina_event_t * const __ev,
                                         const PUSService12 * const self) {
    
    #line 52 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 53 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool is_limits_mon = 0;

    #line 55 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 57 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        is_limits_mon = 1;

    }

    #line 60 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return is_limits_mon;

}

_Bool PUSService12__is_valid_PMONID(const __termina_event_t * const __ev,
                                    const PUSService12 * const self) {
    
    #line 40 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool is_valid = 0;

    #line 42 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((size_t)self->do_monitoring_req_status_update.PMONID < 16U) {
        
        #line 44 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        is_valid = 1;

    }

    #line 47 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return is_valid;

}

_Bool PUSService12__manage_new_status(const __termina_event_t * const __ev,
                                      PUSService12 * const self) {
    
    #line 506 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool transition = 0;

    #line 507 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 509 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckState new_state = self->do_monitoring_req_status_update.new_status;

    #line 510 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckState current_state = self->param_mon_config_table[__termina_array__index(16U,
                                                                                   current_PMON_ID)].current_state;

    #line 511 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckState temp_state = self->param_mon_config_table[__termina_array__index(16U,
                                                                                current_PMON_ID)].temp_state;

    #line 513 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__are_status_equal(__ev, self, new_state,
                                       current_state) == 0) {
        
        #line 515 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (are_status_equal(new_state, temp_state)) {
            
            #line 517 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].repetition_control = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                           current_PMON_ID)].repetition_control + 1U;

        } else
        {
            
            #line 521 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].temp_state = new_state;

            #line 522 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].repetition_control = 1U;

            #line 523 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            MissionObt current_obt;
            #line 523 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            current_obt.finetime = 0U;
            #line 523 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            current_obt.seconds = 0U;

            #line 524 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 525 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].transition_obt = current_obt;

        }

        #line 528 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].repetition_control >= self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                            current_PMON_ID)].repetition) {
            
            #line 530 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].repetition_control = 0U;

            #line 531 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.prev_status = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                    current_PMON_ID)].current_state;

            #line 532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(16U,
                                                                current_PMON_ID)].current_state = new_state;

            #line 533 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            transition = 1;

        }

    } else
    {
        
        #line 539 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].temp_state = new_state;

        #line 540 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].repetition_control = 0U;

    }

    #line 544 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return transition;

}

DoMonitoringReqStatus PUSService12__manage_expected_value(const __termina_event_t * const __ev,
                                                          PUSService12 * const self) {
    
    #line 351 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 351 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 353 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckValueStatus check_status;
    #line 353 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorValueExpected;

    #line 354 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    #line 354 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    #line 356 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__manage_new_status(__ev, self)) {
        
        #line 358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        PUSService12__add_monitoring_transition(__ev, self);

    }

    #line 361 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_interval_control(const __termina_event_t * const __ev,
                                                            PUSService12 * const self) {
    
    #line 130 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 131 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 131 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__Exit;

    #line 133 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U,
                                                        current_PMON_ID)].interval_control = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                 current_PMON_ID)].interval_control + 1U;

    #line 135 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].interval_control >= self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                                      current_PMON_ID)].interval) {
        
        #line 137 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].interval_control = 0U;

        #line 138 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__GetMonitoringType;

    } else
    {
        
        #line 142 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 145 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(const __termina_event_t * const __ev,
                                                                   PUSService12 * const self) {
    
    #line 368 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 368 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 370 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamOutOfLimitInfo fault_info;
    #line 370 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID = 0U;
    #line 370 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_limit = 0U;
    #line 370 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_value = 0U;

    #line 374 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 374 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    #line 375 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    #line 375 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    #line 377 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 381 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 379 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 383 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                             current_PMON_ID)].PID;

        #line 384 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID_limit = check_definition.high_limit;

        #line 386 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 390 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 391 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 393 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 394 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            uint8_t value = 0U;

            #line 395 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 396 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 399 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 403 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 405 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 406 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 406 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 407 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

            #line 408 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.high_limit_evID;

        }

    } else
    {
        
        #line 413 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 418 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(const __termina_event_t * const __ev,
                                                                   PUSService12 * const self) {
    
    #line 424 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 424 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 426 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamOutOfLimitInfo fault_info;
    #line 426 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID = 0U;
    #line 426 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_limit = 0U;
    #line 426 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_value = 0U;

    #line 430 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 430 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorBelowLowLimit;

    #line 431 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamLimitStatus;
    #line 431 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamLimitStatus.__0 = check_status;

    #line 433 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 437 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 435 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 439 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                             current_PMON_ID)].PID;

        #line 440 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID_limit = check_definition.low_limit;

        #line 442 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 446 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 447 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 449 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 450 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            uint8_t value = 0U;

            #line 451 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 452 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 455 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 459 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 461 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 462 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 462 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 463 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

            #line 464 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.low_limit_evID;

        }

    } else
    {
        
        #line 469 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 473 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_param_within_limits(const __termina_event_t * const __ev,
                                                               PUSService12 * const self) {
    
    #line 478 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 478 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 480 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckLimitsStatus within_limits;
    #line 480 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    within_limits.__variant = CheckLimitsStatus__MonitorWithinLimits;

    #line 481 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckState new_status;
    #line 481 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    new_status.__variant = CheckState__ParamLimitStatus;
    #line 481 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    new_status.ParamLimitStatus.__0 = within_limits;

    #line 482 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status = new_status;

    #line 483 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 484 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckState current_status = self->param_mon_config_table[__termina_array__index(16U,
                                                                                    current_PMON_ID)].current_state;

    #line 486 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__are_status_equal(__ev, self, new_status,
                                       current_status) == 0) {
        
        #line 488 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 490 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

        }

    }

    #line 494 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_unexpected_value(const __termina_event_t * const __ev,
                                                            PUSService12 * const self) {
    
    #line 294 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DoMonitoringReqStatus next_status;
    #line 294 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = DoMonitoringReqStatus__GetRequestStatusUpdate;

    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamFaultValueInfo fault_info;
    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID = 0U;
    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_expected_value = 0U;
    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_mask = 0U;
    #line 296 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    fault_info.PID_value = 0U;

    #line 301 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckValueStatus check_status;
    #line 301 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorValueUnexpected;

    #line 302 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.__variant = CheckState__ParamValueStatus;
    #line 302 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->do_monitoring_req_status_update.new_status.ParamValueStatus.__0 = check_status;

    #line 303 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 307 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 305 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                         current_PMON_ID)].definition.ParamValueCheck.__0;

        #line 309 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(16U,
                                                                             current_PMON_ID)].PID;

        #line 310 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID_expected_value = check_definition.expected_value;

        #line 311 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID_mask = check_definition.mask_value;

        #line 313 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        DataPoolItemType type = sys_data_pool_get_item_type(fault_info.PID);

        #line 317 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u32_t) {
            
            #line 318 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            fault_info.PID_value = atomic_load(&self->system_data_pool_u32[(size_t)fault_info.PID - 0U]);

        } else
        #line 320 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (type.__variant == DataPoolItemType__u8_t) {
            
            #line 321 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            uint8_t value = 0U;

            #line 322 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            value = atomic_load(&self->system_data_pool_u8[(size_t)fault_info.PID - 11U]);

            #line 323 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            fault_info.PID_value = (uint32_t)value;

        } else
        {
            
            #line 327 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.__variant = DoMonitoringReqStatus__Exit;

        }

        #line 331 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (PUSService12__manage_new_status(__ev, self)) {
            
            #line 333 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamFaultValue;
            #line 334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0 = fault_info;

            #line 335 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(__ev, self);

            #line 336 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = check_definition.EvID;

        }

    } else
    {
        
        #line 341 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = DoMonitoringReqStatus__Exit;

    }

    #line 345 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

void PUSService12__do_monitoring(const __termina_event_t * const __ev,
                                 void * const __this, uint16_t PMONID,
                                 uint16_t * const evID,
                                 FaultInfo * const fault_info,
                                 _Bool * const event_triggered) {
    
    #line 634 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 634 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 636 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    for (size_t i = 0U;
         i < 5U
         && self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 638 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Init) {
            
            #line 640 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.PMONID = PMONID;

            #line 641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = *evID;

            #line 642 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info = *fault_info;

            #line 643 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__CheckPMONID;

            #line 644 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 0;

        } else
        #line 647 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__CheckPMONID) {
            
            #line 650 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (PUSService12__is_valid_PMONID(__ev, self)
                && self->param_mon_config_table[__termina_array__index(16U,
                                                                       (size_t)PMONID)].enabled == 1) {
                
                #line 651 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_interval_control(__ev,
                                                                                       self);

            } else
            {
                
                #line 653 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 657 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            #line 659 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(16U,
                                                                    (size_t)PMONID)].enabled == 1) {
                
                #line 662 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (PUSService12__is_limits_monitoring(__ev, self)) {
                    
                    #line 664 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else
                #line 667 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (PUSService12__is_expected_value_monitoring(__ev, self)) {
                    
                    #line 669 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else
                {
                    
                    #line 673 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

                }

            } else
            {
                
                #line 678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 682 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            #line 684 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckLimitsStatus limits_monitoring_status = PUSService12__check_PID_status_limits_monitoring(__ev,
                                                                                                          self);

            #line 687 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                #line 689 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_above_upper_limit(__ev,
                                                                                              self);

            } else
            #line 691 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                #line 693 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_below_lower_limit(__ev,
                                                                                              self);

            } else
            #line 696 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                #line 698 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_within_limits(__ev,
                                                                                          self);

            } else
            {
                

            }

        } else
        #line 707 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            #line 709 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckValueStatus exp_value_monitoring_status = PUSService12__check_PID_status_exp_val_monitoring(__ev,
                                                                                                             self);

            #line 712 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                #line 713 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_unexpected_value(__ev,
                                                                                       self);

            } else
            #line 715 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                #line 717 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_expected_value(__ev,
                                                                                     self);

            } else
            {
                

            }

        } else
        #line 727 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetRequestStatusUpdate) {
            
            #line 728 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *evID = self->do_monitoring_req_status_update.EvID;

            #line 729 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *fault_info = self->do_monitoring_req_status_update.fault_info;

            #line 730 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *event_triggered = self->do_monitoring_req_status_update.event_triggered;

            #line 731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 740 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit) {
        
        #line 742 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;

    }

    #line 745 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 745 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

__status_int32_t PUSService12__exec12_1TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    #line 806 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 807 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t status;
    #line 807 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    status.__variant = Success;

    #line 809 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 809 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 809 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 811 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 811 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 812 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 816 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 814 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 818 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 819 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 821 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 823 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 824 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                         current_obt);

            #line 827 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 829 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 833 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 840 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

            #line 841 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            _Bool is_valid_PMONID = PMONID < 16U;

            #line 843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_PMONID) {
                
                #line 845 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->param_mon_config_table[__termina_array__index(16U,
                                                                        (size_t)PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    #line 847 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 848 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 850 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 852 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (status.__variant == Success) {
                            
                            #line 854 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 858 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 864 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 867 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U,
                                                                        (size_t)PMONID)].enabled = 1;

                    #line 868 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U,
                                                                        (size_t)PMONID)].interval_control = 0U;

                    #line 869 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U,
                                                                        (size_t)PMONID)].repetition_control = 0U;

                    #line 871 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __option_box_t tm_handler2;
                    #line 871 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    tm_handler2.__variant = None;

                    #line 872 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 876 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 874 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 878 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        uint16_t tm_count2 = 0U;

                        #line 879 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 880 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 881 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 883 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (ack_enabled) {
                            
                            #line 885 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 887 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else
                            {
                                
                                #line 891 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 903 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        status.__variant = Failure;
                        #line 903 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 909 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 910 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                         current_obt);

                    #line 913 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 915 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 920 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 925 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 926 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                     current_obt);

                #line 929 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 931 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 936 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 943 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.__variant = Failure;
        #line 943 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 947 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return status;

}

void PUSService12__set_unchecked(const __termina_event_t * const __ev,
                                 PUSService12 * const self) {
    
    #line 778 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    #line 782 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 783 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        CheckValueStatus monitor_unchecked;
        #line 783 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitor_unchecked.__variant = CheckValueStatus__MonitorUnchecked;

        #line 784 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamValueStatus;
        #line 784 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].current_state.ParamValueStatus.__0 = monitor_unchecked;

    } else
    #line 786 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 787 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        CheckLimitsStatus monitor_unchecked;
        #line 787 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitor_unchecked.__variant = CheckLimitsStatus__MonitorUnchecked;

        #line 788 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
        #line 788 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].current_state.ParamLimitStatus.__0 = monitor_unchecked;

    } else
    #line 790 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__Delta) {
        
        #line 791 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        CheckDeltaStatus monitor_unchecked;
        #line 791 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitor_unchecked.__variant = CheckDeltaStatus__MonitorUnchecked;

        #line 792 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
        #line 792 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(16U,
                                                            valid_PMONID)].current_state.ParamDeltaStatus.__0 = monitor_unchecked;

    } else
    {
        

    }

    #line 799 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(16U,
                                                        valid_PMONID)].temp_state = self->param_mon_config_table[__termina_array__index(16U,
                                                                                                                                        valid_PMONID)].current_state;

    #line 801 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

__status_int32_t PUSService12__exec12_2TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    #line 953 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 954 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t status;
    #line 954 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    status.__variant = Success;

    #line 956 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 956 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 956 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 958 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 958 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 959 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 963 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 961 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 965 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 966 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 968 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 970 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 971 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                         current_obt);

            #line 974 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 976 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 981 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 16U;

            #line 989 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_PMONID) {
                
                #line 991 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->param_mon_config_table[__termina_array__index(16U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    #line 993 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 994 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 996 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 998 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (status.__variant == Success) {
                            
                            #line 1000 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 1004 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 1010 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 1013 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(16U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = 0;

                    #line 1014 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    PUSService12__set_unchecked(__ev, self);

                    #line 1015 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __option_box_t tm_handler2;
                    #line 1015 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    tm_handler2.__variant = None;

                    #line 1016 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 1020 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 1018 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 1022 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        uint16_t tm_count2 = 0U;

                        #line 1023 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 1024 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 1025 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 1027 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (ack_enabled) {
                            
                            #line 1029 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1031 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else
                            {
                                
                                #line 1035 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 1041 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1045 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        status.__variant = Failure;
                        #line 1045 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 1051 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1052 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                         current_obt);

                    #line 1055 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1057 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 1062 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 1067 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1068 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                     current_obt);

                #line 1071 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1073 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 1078 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 1087 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.__variant = Failure;
        #line 1087 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1091 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return status;

}

__status_int32_t PUSService12__exec12_5TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    #line 1139 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1140 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t status;
    #line 1140 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    status.__variant = Success;

    #line 1142 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1142 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1142 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1144 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1144 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1145 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1149 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1147 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1152 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1154 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
            
            #line 1156 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1158 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_5.N,
                                                         current_obt);

            #line 1161 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 1163 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 1168 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        #line 1172 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == 0) {
            
            #line 1174 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1175 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                                current_obt);

            #line 1178 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 1180 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 1185 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        #line 1189 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            #line 1191 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
                
                #line 1193 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1194 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 1196 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1198 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1200 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 1204 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 1211 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 1214 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                PUSService12__add_valid_mng_mon_def(__ev, self);

                #line 1216 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __option_box_t tm_handler2;
                #line 1216 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                tm_handler2.__variant = None;

                #line 1217 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 1221 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 1219 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 1223 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    uint16_t tm_count2 = 0U;

                    #line 1224 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 1225 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1226 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 1228 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1230 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (status.__variant == Success) {
                            
                            #line 1232 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 1236 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1242 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1246 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status.__variant = Failure;
                    #line 1246 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 1252 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1253 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                              current_obt);

                #line 1256 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1258 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 1263 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        } else
        #line 1268 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1270 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1271 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                  self->exec_tc_req_status_update.packet_id,
                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                  self->exec_tc_req_status_update.flags_ack,
                                  current_obt, &ack_enabled);

            #line 1273 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (ack_enabled) {
                
                #line 1275 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1277 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 1281 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 1287 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

            #line 1290 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_valid_mng_mon_def(__ev, self);

            #line 1292 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __option_box_t tm_handler2;
            #line 1292 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            tm_handler2.__variant = None;

            #line 1293 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 1297 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 1295 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 1299 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                uint16_t tm_count2 = 0U;

                #line 1300 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count2);

                #line 1301 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1302 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                      tm_count2,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 1304 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1306 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1308 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2, &status);

                    } else
                    {
                        
                        #line 1312 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1318 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else
            {
                
                #line 1323 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status.__variant = Failure;
                #line 1323 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 1328 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1329 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                          tm_count,
                                                          self->exec_tc_req_status_update.packet_id,
                                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                                          self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                          current_obt);

            #line 1332 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 1334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 1339 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        }

    } else
    {
        
        #line 1344 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.__variant = Failure;
        #line 1344 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1348 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return status;

}

__status_int32_t PUSService12__exec12_6TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self) {
    
    #line 1355 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1356 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t status;
    #line 1356 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    status.__variant = Success;

    #line 1358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1360 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1360 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1361 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1366 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1364 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1368 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1369 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1371 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 1373 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1374 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                         current_obt);

            #line 1377 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 1379 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 1384 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 1390 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

            #line 1392 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (PMON_type.__variant == MonitorCheckType__Free) {
                
                #line 1394 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1395 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                     current_obt);

                #line 1398 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1400 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 1405 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            #line 1409 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(16U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == 0) {
                
                #line 1411 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1412 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 1414 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1416 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (status.__variant == Success) {
                        
                        #line 1418 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 1422 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 1428 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 1431 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->param_mon_config_table[__termina_array__index(16U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

                #line 1433 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __option_box_t tm_handler2;
                #line 1433 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                tm_handler2.__variant = None;

                #line 1434 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 1438 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 1436 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 1440 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    uint16_t tm_count2 = 0U;

                    #line 1441 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 1442 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1443 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 1445 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1447 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (status.__variant == Success) {
                            
                            #line 1449 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 1453 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1459 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1464 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status.__variant = Failure;
                    #line 1464 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 1469 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1470 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = build_tm_1_4_PMON_enabled((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.packet_id,
                                                   self->exec_tc_req_status_update.packet_seq_ctrl,
                                                   self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                   current_obt);

                #line 1473 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1475 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 1480 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 1491 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.__variant = Failure;
        #line 1491 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1495 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return status;

}

void PUSService12__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 1500 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 1500 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1502 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t status;
    #line 1502 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    status.__variant = Success;

    #line 1503 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 1505 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 1509 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 1511 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 1512 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 1513 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 1514 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 1516 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 1U || subtype == 2U || subtype == 6U) {
                
                #line 1518 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.tc_data_1_2_6.N);

                #line 1519 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1520 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

                }

            } else
            #line 1523 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 5U) {
                
                #line 1525 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                uint8_t aux = 0U;

                #line 1527 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.tc_data_5.N);

                #line 1528 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1529 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_data_5.PMONID);

                }

                #line 1531 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                }

                #line 1534 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1535 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_data_5.mon_config.interval);

                }

                #line 1537 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1538 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_data_5.mon_config.repetition);

                }

                #line 1540 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1541 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler, &aux);

                    #line 1542 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.type = get_check_type(aux);

                }

                #line 1546 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1548 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
                        
                        #line 1550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        ParamValueCheckDefinition value_def;
                        #line 1550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        value_def.EvID = 0U;
                        #line 1550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        value_def.expected_value = 0U;
                        #line 1550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        value_def.mask_value = 0U;

                        #line 1556 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                        #line 1560 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (type.__variant == DataPoolItemType__u8_t) {
                            
                            #line 1562 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            uint8_t mask = 0U;

                            #line 1563 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            uint8_t expected_value = 0U;

                            #line 1566 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                     &mask);

                            #line 1567 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            value_def.mask_value = (uint32_t)mask;

                            #line 1570 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1571 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                         &expected_value);

                                #line 1572 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                value_def.expected_value = (uint32_t)expected_value;

                            }

                            #line 1576 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &value_def.EvID);

                            }

                        } else
                        #line 1582 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 1585 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                      &value_def.mask_value);

                            #line 1588 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1589 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                          &value_def.expected_value);

                            }

                            #line 1593 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1594 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &value_def.EvID);

                            }

                        } else
                        {
                            
                            #line 1600 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status.__variant = Failure;
                            #line 1600 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status.Failure.__0 = INVALID_PID_ERROR;

                        }

                        #line 1605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamValueCheck;
                        #line 1605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamValueCheck.__0 = value_def;

                    } else
                    #line 1608 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
                        
                        #line 1611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        ParamLimitCheckDefinition limits_def;
                        #line 1611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        limits_def.high_limit = 0U;
                        #line 1611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        limits_def.high_limit_evID = 0U;
                        #line 1611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        limits_def.low_limit = 0U;
                        #line 1611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        limits_def.low_limit_evID = 0U;

                        #line 1618 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                        #line 1622 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (type.__variant == DataPoolItemType__u8_t) {
                            
                            #line 1624 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            uint8_t low_limit = 0U;

                            #line 1625 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            uint8_t high_limit = 0U;

                            #line 1628 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                     &low_limit);

                            #line 1629 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            limits_def.low_limit = (uint32_t)low_limit;

                            #line 1632 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1633 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.low_limit_evID);

                            }

                            #line 1637 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1638 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                         &high_limit);

                                #line 1639 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                limits_def.high_limit = (uint32_t)high_limit;

                            }

                            #line 1644 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1645 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.high_limit_evID);

                            }

                        } else
                        #line 1650 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 1653 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                      &limits_def.low_limit);

                            #line 1656 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1657 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.low_limit_evID);

                            }

                            #line 1661 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1662 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                          &limits_def.high_limit);

                            }

                            #line 1666 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (status.__variant == Success) {
                                
                                #line 1667 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                          &limits_def.high_limit_evID);

                            }

                        } else
                        {
                            
                            #line 1672 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status.__variant = Failure;
                            #line 1672 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            status.Failure.__0 = INVALID_PID_ERROR;

                        }

                        #line 1676 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__ParamLimitCheck;
                        #line 1676 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->exec_tc_req_status_update.tc_data_5.mon_config.definition.ParamLimitCheck.__0 = limits_def;

                    } else
                    {
                        

                    }

                }

            } else
            {
                

            }

            #line 1691 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (status.__variant == Success) {
                
                #line 1693 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 1697 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 1702 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 1704 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 1706 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 1U) {
                
                #line 1708 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = PUSService12__exec12_1TC(__ev, self);

            } else
            #line 1710 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 2U) {
                
                #line 1712 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = PUSService12__exec12_2TC(__ev, self);

            } else
            #line 1714 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 5U) {
                
                #line 1716 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = PUSService12__exec12_5TC(__ev, self);

            } else
            #line 1718 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 6U) {
                
                #line 1720 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status = PUSService12__exec12_6TC(__ev, self);

            } else
            {
                
                #line 1724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status.__variant = Failure;
                #line 1724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 1735 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (status.__variant == Success) {
        
        #line 1737 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 1733 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        int32_t error_code = status.Failure.__0;

        #line 1742 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR
            || error_code == INVALID_PID_ERROR) {
            
            #line 1744 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).__variant = Success;

            #line 1746 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __option_box_t tm_handler;
            #line 1746 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            tm_handler.__variant = None;

            #line 1747 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 1751 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (tm_handler.__variant == Some) {
                
                #line 1749 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 1753 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                uint16_t tm_count = 0U;

                #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                MissionObt current_obt;
                #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                current_obt.finetime = 0U;
                #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                current_obt.seconds = 0U;

                #line 1756 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 1757 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1759 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 1761 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 1764 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 1766 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 1769 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 1771 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                #line 1774 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (error_code == INVALID_PID_ERROR) {
                    
                    #line 1775 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.packet_id,
                                                        self->exec_tc_req_status_update.packet_seq_ctrl,
                                                        self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                                        current_obt);

                } else
                {
                    

                }

                #line 1785 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (status.__variant == Success) {
                    
                    #line 1787 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 1791 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 1797 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status.__variant = Failure;
                #line 1797 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 1804 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).__variant = Failure;
            #line 1804 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 1810 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 1812 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1812 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

MonitorCheckType PUSService12__get_PMON_type(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             size_t PMONID) {
    
    #line 766 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MonitorCheckType mon_type;
    #line 766 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    mon_type.__variant = MonitorCheckType__Free;

    #line 768 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 770 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_type = self->param_mon_config_table[__termina_array__index(16U,
                                                                       (size_t)PMONID)].type;

    }

    #line 773 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return mon_type;

}

void PUSService12__is_PMON_enabled(const __termina_event_t * const __ev,
                                   void * const __this, size_t PMONID,
                                   _Bool * const is_enabled) {
    
    #line 748 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 748 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 750 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    *is_enabled = 0;

    #line 752 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 16U) {
        
        #line 754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(16U,
                                                                PMONID)].type.__variant == MonitorCheckType__Free == 0) {
            
            #line 756 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *is_enabled = self->param_mon_config_table[__termina_array__index(16U,
                                                                              (size_t)PMONID)].enabled;

        }

    }

    #line 760 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 760 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}
