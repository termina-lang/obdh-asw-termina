
#include "service_libraries/pus_services/pus_service12/pus_service12.h"

_Bool PUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev,
                                                  const PUSService12 * const self,
                                                  const ParamValueCheckDefinition * const expected_value_check_definition) {
    
    #line 262 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

    #line 263 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool res = 0;

    #line 264 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint16_t PID = self->param_mon_config_table[__termina_array__index(8U,
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
    uint16_t PID = self->param_mon_config_table[__termina_array__index(8U,
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
    uint16_t PID = self->param_mon_config_table[__termina_array__index(8U,
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

void PUSService12__build_tm_12_12(const __termina_event_t * const __ev,
                                  const PUSService12 * const self,
                                  TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  __status_int32_t * const status) {
    
    #line 549 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    startup_tm(p_tm_handler);

    #line 550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    append_u8_appdata_field(p_tm_handler, self->monitoring_transition_counter,
                            status);

    #line 552 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    for (size_t i = 0U; i < 1U && i < (size_t)self->monitoring_transition_counter; i = i + 1U) {
        
        #line 554 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t aux_prev_status = 0U;

        #line 555 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t aux_new_status = 0U;

        #line 557 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u16_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].PMONID,
                                 status);

        #line 558 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u16_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].PID,
                                 status);

        #line 559 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t type_id = get_type_index(self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                                  i)].type);

        #line 560 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u8_appdata_field(p_tm_handler, type_id, status);

        #line 563 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     i)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 564 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            append_u32_appdata_field(p_tm_handler,
                                     self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                              i)].mask_value,
                                     status);

        }

        #line 567 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        aux_prev_status = get_check_status_index(self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                                          i)].prev_status);

        #line 568 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        aux_new_status = get_check_status_index(self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                                         i)].new_status);

        #line 570 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].new_value,
                                 status);

        #line 571 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].limit_value,
                                 status);

        #line 572 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u8_appdata_field(p_tm_handler, aux_prev_status, status);

        #line 573 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u8_appdata_field(p_tm_handler, aux_new_status, status);

        #line 574 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].trans_obt.seconds,
                                 status);

    }

    #line 576 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((*status).__variant == Success) {
        
        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        MissionObt current_obt;
        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        current_obt.finetime = 0U;
        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        current_obt.seconds = 0U;

        #line 578 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 579 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        close_tm(p_tm_handler, 12U, 12U, tm_seq_counter, current_obt);

    }

    #line 583 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

void PUSService12__add_monitoring_transition(const __termina_event_t * const __ev,
                                             PUSService12 * const self) {
    
    #line 589 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __status_int32_t monitoring_status;
    #line 589 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    monitoring_status.__variant = Success;

    #line 591 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter < 1U) {
        
        #line 593 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        size_t current_PMON_ID = (size_t)self->do_monitoring_req_status_update.PMONID;

        #line 595 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].PID = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                         current_PMON_ID)].PID;

        #line 596 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].PMONID = self->do_monitoring_req_status_update.PMONID;

        #line 597 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].type = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                          current_PMON_ID)].type;

        #line 599 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 598 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            ParamOutOfLimitInfo out_of_limit_info = self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0;

            #line 600 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = out_of_limit_info.PID_limit;

            #line 601 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = out_of_limit_info.PID_value;

        } else
        #line 603 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status_update.fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 598 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            ParamFaultValueInfo fault_value_info = self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0;

            #line 604 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].limit_value = fault_value_info.PID_expected_value;

            #line 605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].new_value = fault_value_info.PID_value;

        } else
        {
            

        }

        #line 614 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
            
            #line 613 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            ParamValueCheckDefinition value_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                             current_PMON_ID)].definition.ParamValueCheck.__0;

            #line 616 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     (size_t)self->monitoring_transition_counter)].mask_value = value_definition.mask_value;

        } else
        {
            

        }

        #line 625 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].new_status = self->do_monitoring_req_status_update.new_status;

        #line 626 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].prev_status = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                                 current_PMON_ID)].current_state;

        #line 627 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_transitions_table[__termina_array__index(1U,
                                                                 (size_t)self->monitoring_transition_counter)].trans_obt = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                                               current_PMON_ID)].transition_obt;

        #line 629 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->monitoring_transition_counter = self->monitoring_transition_counter + 1U;

    }

    #line 632 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((size_t)self->monitoring_transition_counter == 1U) {
        
        #line 634 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __option_box_t tm_handler;
        #line 634 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tm_handler.__variant = None;

        #line 635 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        #line 639 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (tm_handler.__variant == Some) {
            
            #line 637 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            uint16_t tm_count = 0U;

            #line 642 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 644 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__build_tm_12_12(__ev, self,
                                         (TMHandlerT *)b_tm_handler.data,
                                         tm_count, &monitoring_status);

            #line 646 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (monitoring_status.__variant == Success) {
                
                #line 647 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &monitoring_status);

            } else
            {
                
                #line 651 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 657 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            monitoring_status.__variant = Failure;
            #line 657 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            monitoring_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

        #line 663 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->monitoring_transition_counter = 0U;

    }

    #line 666 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

void PUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev,
                                         PUSService12 * const self) {
    
    #line 1127 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.mon_config.PID;

    #line 1129 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(8U,
                                                        PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    #line 1131 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(8U,
                                                        PMONID)].enabled = 0;

    #line 1134 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 8U) {
        
        #line 1138 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1140 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckValueStatus status;
            #line 1140 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckValueStatus__MonitorUnchecked;

            #line 1141 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            #line 1141 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamValueStatus.__0 = status;

        } else
        #line 1143 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            #line 1145 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckLimitsStatus status;
            #line 1145 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckLimitsStatus__MonitorUnchecked;

            #line 1146 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            #line 1146 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else
        #line 1149 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            #line 1151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckDeltaStatus status;
            #line 1151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckDeltaStatus__MonitorUnchecked;

            #line 1152 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            #line 1152 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else
        {
            

        }

    }

    #line 1165 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
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
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 112 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamValueCheckDefinition param_check_definition = self->param_mon_config_table[__termina_array__index(8U,
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
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 87 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamLimitCheckDefinition limit_check_def = self->param_mon_config_table[__termina_array__index(8U,
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
    if (self->param_mon_config_table[__termina_array__index(8U,
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
    if (self->param_mon_config_table[__termina_array__index(8U,
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
    if ((size_t)self->do_monitoring_req_status_update.PMONID < 8U) {
        
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
    CheckState current_state = self->param_mon_config_table[__termina_array__index(8U,
                                                                                   current_PMON_ID)].current_state;

    #line 511 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckState temp_state = self->param_mon_config_table[__termina_array__index(8U,
                                                                                current_PMON_ID)].temp_state;

    #line 513 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__are_status_equal(__ev, self, new_state,
                                       current_state) == 0) {
        
        #line 515 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (are_status_equal(new_state, temp_state)) {
            
            #line 517 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                           current_PMON_ID)].repetition_control + 1U;

        } else
        {
            
            #line 521 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].temp_state = new_state;

            #line 522 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
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
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].transition_obt = current_obt;

        }

        #line 528 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control >= self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                            current_PMON_ID)].repetition) {
            
            #line 530 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].repetition_control = 0U;

            #line 531 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                current_PMON_ID)].current_state = new_state;

            #line 532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            transition = 1;

        }

    } else
    {
        
        #line 538 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].temp_state = new_state;

        #line 539 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].repetition_control = 0U;

    }

    #line 543 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
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
    self->param_mon_config_table[__termina_array__index(8U,
                                                        current_PMON_ID)].interval_control = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                 current_PMON_ID)].interval_control + 1U;

    #line 135 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].interval_control >= self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                                      current_PMON_ID)].interval) {
        
        #line 137 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
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
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 379 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 383 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(8U,
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
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamLimitCheck) {
        
        #line 435 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamLimitCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                         current_PMON_ID)].definition.ParamLimitCheck.__0;

        #line 439 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(8U,
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
    CheckState current_status = self->param_mon_config_table[__termina_array__index(8U,
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
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            current_PMON_ID)].definition.__variant == MonitorDefinition__ParamValueCheck) {
        
        #line 305 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamValueCheckDefinition check_definition = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                         current_PMON_ID)].definition.ParamValueCheck.__0;

        #line 309 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        fault_info.PID = self->param_mon_config_table[__termina_array__index(8U,
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
    
    #line 669 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 669 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 671 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    for (size_t i = 0U; i < 4U && self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit == 0; i = i + 1U) {
        
        #line 673 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Init) {
            
            #line 675 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.PMONID = PMONID;

            #line 676 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.EvID = *evID;

            #line 677 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info = *fault_info;

            #line 678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__CheckPMONID;

            #line 679 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 0;

        } else
        #line 682 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__CheckPMONID) {
            
            #line 685 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (PUSService12__is_valid_PMONID(__ev, self)) {
                
                #line 686 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_interval_control(__ev,
                                                                                       self);

            } else
            {
                
                #line 688 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 692 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetMonitoringType) {
            
            #line 694 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)PMONID)].enabled == 1) {
                
                #line 697 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (PUSService12__is_limits_monitoring(__ev, self)) {
                    
                    #line 699 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else
                #line 702 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (PUSService12__is_expected_value_monitoring(__ev, self)) {
                    
                    #line 704 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoExpectedValueMonitoring;

                } else
                {
                    
                    #line 708 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

                }

            } else
            {
                
                #line 713 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Exit;

            }

        } else
        #line 717 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoLimitsMonitoring) {
            
            #line 719 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckLimitsStatus limits_monitoring_status = PUSService12__check_PID_status_limits_monitoring(__ev,
                                                                                                          self);

            #line 722 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                #line 724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_above_upper_limit(__ev,
                                                                                              self);

            } else
            #line 726 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                #line 728 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_below_lower_limit(__ev,
                                                                                              self);

            } else
            #line 731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                #line 733 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_within_limits(__ev,
                                                                                          self);

            } else
            {
                

            }

        } else
        #line 742 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            #line 744 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckValueStatus exp_value_monitoring_status = PUSService12__check_PID_status_exp_val_monitoring(__ev,
                                                                                                             self);

            #line 747 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                #line 748 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_unexpected_value(__ev,
                                                                                       self);

            } else
            #line 750 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                #line 752 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_expected_value(__ev,
                                                                                     self);

            } else
            {
                

            }

        } else
        #line 762 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__GetRequestStatusUpdate) {
            
            #line 763 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *evID = self->do_monitoring_req_status_update.EvID;

            #line 764 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *fault_info = self->do_monitoring_req_status_update.fault_info;

            #line 765 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *event_triggered = self->do_monitoring_req_status_update.event_triggered;

        } else
        {
            

        }

    }

    #line 773 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__Exit) {
        
        #line 775 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;

    }

    #line 778 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 778 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

PSExecTCReqStatus PUSService12__exec12_1TC(const __termina_event_t * const __ev,
                                           PUSService12 * const self) {
    
    #line 837 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 838 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 838 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 838 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 840 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 840 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 840 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 842 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 842 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 847 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 845 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 849 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 850 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 852 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 854 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 855 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                current_obt,
                                                &next_status.status);

            #line 858 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (next_status.status.__variant == Success) {
                
                #line 860 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 864 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 871 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

            #line 872 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            _Bool is_valid_PMONID = PMONID < 8U;

            #line 874 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_PMONID) {
                
                #line 876 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    #line 878 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 879 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 881 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 883 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 885 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 889 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 895 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].enabled = 1;

                    #line 899 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].interval_control = 0U;

                    #line 900 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].repetition_control = 0U;

                    #line 902 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __option_box_t tm_handler2;
                    #line 902 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    tm_handler2.__variant = None;

                    #line 903 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 907 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 905 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 909 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        uint16_t tm_count2 = 0U;

                        #line 910 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 911 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 912 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 914 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (ack_enabled) {
                            
                            #line 916 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 918 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 922 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 929 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 934 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.status.__variant = Failure;
                        #line 934 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 940 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 941 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                current_obt,
                                                &next_status.status);

                    #line 944 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 946 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 951 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 956 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 957 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            current_obt, &next_status.status);

                #line 960 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 962 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 967 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 974 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 974 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 978 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

void PUSService12__set_unchecked(const __termina_event_t * const __ev,
                                 PUSService12 * const self) {
    
    #line 809 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

    #line 813 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
        
        #line 814 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        CheckValueStatus monitor_unchecked;
        #line 814 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitor_unchecked.__variant = CheckValueStatus__MonitorUnchecked;

        #line 815 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamValueStatus;
        #line 815 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.ParamValueStatus.__0 = monitor_unchecked;

    } else
    #line 817 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__Limits) {
        
        #line 818 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        CheckLimitsStatus monitor_unchecked;
        #line 818 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitor_unchecked.__variant = CheckLimitsStatus__MonitorUnchecked;

        #line 819 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
        #line 819 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.ParamLimitStatus.__0 = monitor_unchecked;

    } else
    #line 821 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].type.__variant == MonitorCheckType__Delta) {
        
        #line 822 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        CheckDeltaStatus monitor_unchecked;
        #line 822 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        monitor_unchecked.__variant = CheckDeltaStatus__MonitorUnchecked;

        #line 823 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
        #line 823 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->param_mon_config_table[__termina_array__index(8U,
                                                            valid_PMONID)].current_state.ParamDeltaStatus.__0 = monitor_unchecked;

    } else
    {
        

    }

    #line 830 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(8U,
                                                        valid_PMONID)].temp_state = self->param_mon_config_table[__termina_array__index(8U,
                                                                                                                                        valid_PMONID)].current_state;

    #line 832 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

PSExecTCReqStatus PUSService12__exec12_2TC(const __termina_event_t * const __ev,
                                           PUSService12 * const self) {
    
    #line 984 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 985 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 985 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 985 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 989 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 989 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 990 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 994 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 992 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 996 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 997 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 999 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 1001 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1002 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                current_obt,
                                                &next_status.status);

            #line 1005 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (next_status.status.__variant == Success) {
                
                #line 1007 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 1012 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 1018 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 8U;

            #line 1020 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_PMONID) {
                
                #line 1022 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    #line 1024 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1025 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 1027 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1029 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 1031 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 1035 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 1041 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 1044 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = 0;

                    #line 1045 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    PUSService12__set_unchecked(__ev, self);

                    #line 1046 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __option_box_t tm_handler2;
                    #line 1046 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    tm_handler2.__variant = None;

                    #line 1047 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 1051 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 1049 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 1053 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        uint16_t tm_count2 = 0U;

                        #line 1054 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 1055 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 1056 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 1058 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (ack_enabled) {
                            
                            #line 1060 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 1062 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 1066 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 1072 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1076 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.status.__variant = Failure;
                        #line 1076 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 1082 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1083 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                current_obt,
                                                &next_status.status);

                    #line 1086 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 1088 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 1093 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 1098 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1099 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            current_obt, &next_status.status);

                #line 1102 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 1104 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 1109 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 1118 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 1118 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1122 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__exec12_5TC(const __termina_event_t * const __ev,
                                           PUSService12 * const self) {
    
    #line 1170 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1171 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1171 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 1171 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 1173 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1173 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1173 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1175 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1175 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1176 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1180 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1178 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1182 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1183 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1185 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
            
            #line 1187 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1188 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_5.N,
                                                current_obt,
                                                &next_status.status);

            #line 1191 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (next_status.status.__variant == Success) {
                
                #line 1193 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 1198 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        #line 1202 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == 0) {
            
            #line 1204 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1205 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                       current_obt, &next_status.status);

            #line 1208 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (next_status.status.__variant == Success) {
                
                #line 1210 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 1215 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        #line 1219 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            #line 1221 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
                
                #line 1223 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1224 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 1226 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1228 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 1230 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 1234 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 1241 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 1244 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                PUSService12__add_valid_mng_mon_def(__ev, self);

                #line 1246 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __option_box_t tm_handler2;
                #line 1246 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                tm_handler2.__variant = None;

                #line 1247 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 1251 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 1249 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 1253 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    uint16_t tm_count2 = 0U;

                    #line 1254 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 1255 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1256 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 1258 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1260 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 1262 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 1266 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1272 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1276 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.status.__variant = Failure;
                    #line 1276 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 1282 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1283 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                     current_obt,
                                                     &next_status.status);

                #line 1286 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 1288 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 1293 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        } else
        #line 1298 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1300 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1301 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &next_status.status, &ack_enabled);

            #line 1303 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (ack_enabled) {
                
                #line 1305 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 1307 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 1311 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 1317 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

            #line 1320 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_valid_mng_mon_def(__ev, self);

            #line 1322 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __option_box_t tm_handler2;
            #line 1322 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            tm_handler2.__variant = None;

            #line 1323 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 1327 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 1325 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 1329 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                uint16_t tm_count2 = 0U;

                #line 1330 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count2);

                #line 1331 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1332 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 1334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1336 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 1338 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 1342 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1348 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else
            {
                
                #line 1353 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.status.__variant = Failure;
                #line 1353 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 1358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1359 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                 tm_count,
                                                 self->exec_tc_req_status_update.packet_id,
                                                 self->exec_tc_req_status_update.packet_error_ctrl,
                                                 self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                 current_obt,
                                                 &next_status.status);

            #line 1362 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (next_status.status.__variant == Success) {
                
                #line 1364 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 1369 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        }

    } else
    {
        
        #line 1374 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 1374 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1378 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__exec12_6TC(const __termina_event_t * const __ev,
                                           PUSService12 * const self) {
    
    #line 1385 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1386 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1386 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 1386 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 1388 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1388 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1388 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1390 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1390 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1391 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1396 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1394 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1398 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1399 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1401 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 1403 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1404 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                current_obt,
                                                &next_status.status);

            #line 1407 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (next_status.status.__variant == Success) {
                
                #line 1409 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 1414 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 1420 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

            #line 1422 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (PMON_type.__variant == MonitorCheckType__Free) {
                
                #line 1424 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1425 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            current_obt, &next_status.status);

                #line 1428 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 1430 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 1435 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            #line 1439 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == 0) {
                
                #line 1441 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1442 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 1444 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1446 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 1448 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 1452 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 1458 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 1461 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

                #line 1463 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __option_box_t tm_handler2;
                #line 1463 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                tm_handler2.__variant = None;

                #line 1464 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 1468 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 1466 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 1470 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    uint16_t tm_count2 = 0U;

                    #line 1471 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 1472 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1473 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 1475 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1477 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 1479 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 1483 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1489 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1494 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.status.__variant = Failure;
                    #line 1494 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 1499 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 1500 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMON_enabled((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_error_ctrl,
                                          self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                          current_obt, &next_status.status);

                #line 1503 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 1505 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 1510 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 1521 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 1521 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1525 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

MonitorDefinition PUSService12__get_PMON_limit_check_definition(const __termina_event_t * const __ev,
                                                                const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                __status_int32_t * const status) {
    
    #line 1532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamLimitCheckDefinition limits_def;
    #line 1532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.high_limit = 0U;
    #line 1532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.high_limit_evID = 0U;
    #line 1532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.low_limit = 0U;
    #line 1532 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.low_limit_evID = 0U;

    #line 1539 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

    #line 1543 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 1545 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t low_limit = 0U;

        #line 1546 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t high_limit = 0U;

        #line 1549 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u8_appdata_field(tc_handler, &low_limit);

        #line 1552 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.low_limit_evID);

        #line 1555 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u8_appdata_field(tc_handler, &high_limit);

        #line 1558 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.high_limit_evID);

        #line 1560 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        limits_def.low_limit = (uint32_t)low_limit;

        #line 1561 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        limits_def.high_limit = (uint32_t)high_limit;

    } else
    #line 1564 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 1567 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &limits_def.low_limit);

        #line 1570 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.low_limit_evID);

        #line 1573 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &limits_def.low_limit);

        #line 1576 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.high_limit_evID);

    } else
    {
        
        #line 1580 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*status).__variant = Failure;
        #line 1580 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*status).Failure.__0 = INVALID_PID_ERROR;

    }

    #line 1586 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MonitorDefinition param_limit_check_definition;
    #line 1586 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    param_limit_check_definition.__variant = MonitorDefinition__ParamLimitCheck;
    #line 1586 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    param_limit_check_definition.ParamLimitCheck.__0 = limits_def;

    #line 1588 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return param_limit_check_definition;

}

MonitorDefinition PUSService12__get_PMON_value_check_definition(const __termina_event_t * const __ev,
                                                                const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                __status_int32_t * const status) {
    
    #line 1595 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamValueCheckDefinition value_def;
    #line 1595 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    value_def.EvID = 0U;
    #line 1595 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    value_def.expected_value = 0U;
    #line 1595 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    value_def.mask_value = 0U;

    #line 1601 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

    #line 1605 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 1607 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t mask = 0U;

        #line 1608 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t expected_value = 0U;

        #line 1611 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u8_appdata_field(tc_handler, &mask);

        #line 1614 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u8_appdata_field(tc_handler, &expected_value);

        #line 1617 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

        #line 1619 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        value_def.mask_value = (uint32_t)mask;

        #line 1620 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        value_def.expected_value = (uint32_t)expected_value;

    } else
    #line 1623 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 1626 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &value_def.mask_value);

        #line 1629 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &value_def.expected_value);

        #line 1632 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *status = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

    } else
    {
        
        #line 1636 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*status).__variant = Failure;
        #line 1636 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*status).Failure.__0 = INVALID_PID_ERROR;

    }

    #line 1641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MonitorDefinition expected_value_check_definition;
    #line 1641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    expected_value_check_definition.__variant = MonitorDefinition__ParamValueCheck;
    #line 1641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    expected_value_check_definition.ParamValueCheck.__0 = value_def;

    #line 1642 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return expected_value_check_definition;

}

PSExecTCReqStatus PUSService12__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                           const PUSService12 * const self) {
    
    #line 1687 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1687 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 1687 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 1689 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1689 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1689 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1691 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1691 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1692 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1696 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1694 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1698 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1699 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1701 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 1702 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 1705 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (next_status.status.__variant == Success) {
            
            #line 1707 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 1711 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 1717 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 1717 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1721 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                               const PUSService12 * const self) {
    
    #line 1649 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1649 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 1649 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 1651 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1651 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1651 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1653 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1653 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1654 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1658 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1656 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1660 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1661 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1662 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 1663 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 1666 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (next_status.status.__variant == Success) {
            
            #line 1668 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 1673 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 1678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 1678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1682 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                 const PUSService12 * const self) {
    
    #line 1726 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1726 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 1726 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.status.__variant = Success;

    #line 1728 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1728 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1728 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1730 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1730 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 1735 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1733 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1737 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1738 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1740 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 1741 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 1744 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (next_status.status.__variant == Success) {
            
            #line 1746 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 1750 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 1756 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.__variant = Failure;
        #line 1756 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1760 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

void PUSService12__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 1764 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 1764 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1766 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 1768 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 1772 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 1774 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 1775 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 1776 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 1777 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 1779 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 1U || subtype == 2U || subtype == 6U) {
                
                #line 1781 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                  &self->exec_tc_req_status_update.tc_data_1_2_6.N);

                #line 1782 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                                   &self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

            } else
            #line 1784 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 5U) {
                
                #line 1786 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                uint8_t aux = 0U;

                #line 1788 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                  &self->exec_tc_req_status_update.tc_data_5.N);

                #line 1789 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                                   &self->exec_tc_req_status_update.tc_data_5.PMONID);

                #line 1790 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                                   &self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

                #line 1791 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                  &self->exec_tc_req_status_update.tc_data_5.mon_config.interval);

                #line 1792 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                  &self->exec_tc_req_status_update.tc_data_5.mon_config.repetition);

                #line 1793 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                  &aux);

                #line 1794 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status_update.tc_data_5.mon_config.type = get_check_type(aux);

                #line 1796 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
                    
                    #line 1799 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition = PUSService12__get_PMON_value_check_definition(__ev,
                                                                                                                                    self,
                                                                                                                                    tc_handler,
                                                                                                                                    &self->exec_tc_req_status.status);

                } else
                #line 1802 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
                    
                    #line 1805 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->exec_tc_req_status_update.tc_data_5.mon_config.definition = PUSService12__get_PMON_limit_check_definition(__ev,
                                                                                                                                    self,
                                                                                                                                    tc_handler,
                                                                                                                                    &self->exec_tc_req_status.status);

                } else
                {
                    

                }

            } else
            {
                

            }

            #line 1818 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 1820 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 1824 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 1829 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 1831 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 1U) {
                
                #line 1833 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_1TC(__ev, self);

            } else
            #line 1835 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 2U) {
                
                #line 1837 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_2TC(__ev, self);

            } else
            #line 1839 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 5U) {
                
                #line 1841 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_5TC(__ev, self);

            } else
            #line 1843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 6U) {
                
                #line 1845 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_6TC(__ev, self);

            } else
            {
                
                #line 1849 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 1849 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 1850 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 1861 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 1863 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 1859 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 1868 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 1870 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status = PUSService12__manage_error_in_acceptance(__ev,
                                                                                self);

        } else
        #line 1872 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 1874 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status = PUSService12__manage_tm_limit_app_data_reached(__ev,
                                                                                      self);

        } else
        #line 1876 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 1878 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status = PUSService12__manage_short_pack_length_error(__ev,
                                                                                    self);

        } else
        #line 1880 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (error_code == INVALID_PID_ERROR) {
            

        } else
        {
            
            #line 1886 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).__variant = Failure;
            #line 1886 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 1894 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 1895 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 1898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

MonitorCheckType PUSService12__get_PMON_type(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             size_t PMONID) {
    
    #line 797 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MonitorCheckType mon_type;
    #line 797 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    mon_type.__variant = MonitorCheckType__Free;

    #line 799 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 8U) {
        
        #line 801 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_type = self->param_mon_config_table[__termina_array__index(8U,
                                                                       (size_t)PMONID)].type;

    }

    #line 804 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return mon_type;

}

void PUSService12__is_PMON_enabled(const __termina_event_t * const __ev,
                                   void * const __this, size_t PMONID,
                                   _Bool * const is_enabled) {
    
    #line 781 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PUSService12 * self = (PUSService12 *)__this;

    #line 781 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 783 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 8U) {
        
        #line 785 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__Free == 0) {
            
            #line 787 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            *is_enabled = self->param_mon_config_table[__termina_array__index(8U,
                                                                              (size_t)PMONID)].enabled;

        }

    }

    #line 791 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 791 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}
