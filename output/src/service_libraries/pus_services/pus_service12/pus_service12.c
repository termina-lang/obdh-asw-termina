
#include "service_libraries/pus_services/pus_service12/pus_service12.h"

_Bool PUSService12__PID_has_expected_masked_value(const PUSService12 * const self,
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

_Bool PUSService12__PID_is_above_upper_limit(const PUSService12 * const self,
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

_Bool PUSService12__PID_is_below_lower_limit(const PUSService12 * const self,
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

void PUSService12__build_tm_12_12(const PUSService12 * const self,
                                  TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  MyResult * const result) {
    
    #line 549 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    startup_tm(p_tm_handler);

    #line 550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    append_u8_appdata_field(p_tm_handler, self->monitoring_transition_counter,
                            result);

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
                                 result);

        #line 558 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u16_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].PID,
                                 result);

        #line 559 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t type_id = get_type_index(self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                                  i)].type);

        #line 560 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u8_appdata_field(p_tm_handler, type_id, result);

        #line 563 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_transitions_table[__termina_array__index(1U,
                                                                     i)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 564 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            append_u32_appdata_field(p_tm_handler,
                                     self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                              i)].mask_value,
                                     result);

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
                                 result);

        #line 571 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].limit_value,
                                 result);

        #line 572 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u8_appdata_field(p_tm_handler, aux_prev_status, result);

        #line 573 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u8_appdata_field(p_tm_handler, aux_new_status, result);

        #line 574 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        append_u32_appdata_field(p_tm_handler,
                                 self->param_mon_transitions_table[__termina_array__index(1U,
                                                                                          i)].trans_obt.seconds,
                                 result);

    }

    #line 576 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if ((*result).__variant == MyResult__Ok) {
        
        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        MissionObt current_obt;
        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        current_obt.finetime = 0U;
        #line 577 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        current_obt.seconds = 0U;

        #line 578 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 579 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        close_tm(p_tm_handler, 12U, 12U, tm_seq_counter, current_obt);

    }

    #line 583 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

void PUSService12__add_monitoring_transition(PUSService12 * const self) {
    
    #line 589 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 589 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

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
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler);

        #line 639 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (tm_handler.__variant == Some) {
            
            #line 637 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            uint16_t tm_count = 0U;

            #line 642 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count);

            #line 644 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__build_tm_12_12(self, (TMHandlerT *)b_tm_handler.data,
                                         tm_count, &result);

            #line 646 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 647 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

            } else
            {
                
                #line 651 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 657 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            result.__variant = MyResult__Error;

        }

        #line 663 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->monitoring_transition_counter = 0U;

    }

    #line 666 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

void PUSService12__add_valid_mng_mon_def(PUSService12 * const self) {
    
    #line 1165 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_5.mon_config.PID;

    #line 1167 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(8U,
                                                        PMONID)] = self->exec_tc_req_status_update.tc_data_5.mon_config;

    #line 1169 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->param_mon_config_table[__termina_array__index(8U,
                                                        PMONID)].enabled = 0;

    #line 1172 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PMONID < 8U) {
        
        #line 1176 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1178 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckValueStatus status;
            #line 1178 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckValueStatus__MonitorUnchecked;

            #line 1179 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamValueStatus;
            #line 1179 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamValueStatus.__0 = status;

        } else
        #line 1181 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__Limits) {
            
            #line 1183 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckLimitsStatus status;
            #line 1183 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckLimitsStatus__MonitorUnchecked;

            #line 1184 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamLimitStatus;
            #line 1184 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamLimitStatus.__0 = status;

        } else
        #line 1187 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].type.__variant == MonitorCheckType__Delta) {
            
            #line 1189 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckDeltaStatus status;
            #line 1189 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            status.__variant = CheckDeltaStatus__MonitorUnchecked;

            #line 1190 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.__variant = CheckState__ParamDeltaStatus;
            #line 1190 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->param_mon_config_table[__termina_array__index(8U,
                                                                PMONID)].current_state.ParamDeltaStatus.__0 = status;

        } else
        {
            

        }

    }

    #line 1203 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

_Bool PUSService12__are_status_equal(const PUSService12 * const self,
                                     CheckState status1, CheckState status2) {
    
    #line 499 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool equal = get_check_status_index(status1) == get_check_status_index(status2);

    #line 500 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return equal;

}

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const PUSService12 * const self) {
    
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

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const PUSService12 * const self) {
    
    #line 175 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamValueCheckDefinition current_monitor_definition = PUSService12__get_expected_value_monitoring_definition(self);

    #line 176 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckValueStatus check_status;
    #line 176 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckValueStatus__MonitorUnchecked;

    #line 178 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__PID_has_expected_masked_value(self,
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

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const PUSService12 * const self) {
    
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

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const PUSService12 * const self) {
    
    #line 150 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamLimitCheckDefinition current_monitor_definition = PUSService12__get_limits_monitoring_definition(self);

    #line 151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    CheckLimitsStatus check_status;
    #line 151 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    check_status.__variant = CheckLimitsStatus__MonitorUnchecked;

    #line 153 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__PID_is_above_upper_limit(self,
                                               &current_monitor_definition)) {
        
        #line 155 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        check_status.__variant = CheckLimitsStatus__MonitorAboveHighLimit;

    } else
    #line 158 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (PUSService12__PID_is_below_lower_limit(self,
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

_Bool PUSService12__is_expected_value_monitoring(const PUSService12 * const self) {
    
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

_Bool PUSService12__is_limits_monitoring(const PUSService12 * const self) {
    
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

_Bool PUSService12__is_valid_PMONID(const PUSService12 * const self) {
    
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

_Bool PUSService12__manage_new_status(PUSService12 * const self) {
    
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
    if (PUSService12__are_status_equal(self, new_state, current_state) == 0) {
        
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
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
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

DoMonitoringReqStatus PUSService12__manage_expected_value(PUSService12 * const self) {
    
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
    if (PUSService12__manage_new_status(self)) {
        
        #line 358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        PUSService12__add_monitoring_transition(self);

    }

    #line 361 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_interval_control(PUSService12 * const self) {
    
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

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(PUSService12 * const self) {
    
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
        if (PUSService12__manage_new_status(self)) {
            
            #line 405 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 406 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 406 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 407 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(self);

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

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(PUSService12 * const self) {
    
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
        if (PUSService12__manage_new_status(self)) {
            
            #line 461 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 462 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamOutOfLimit;
            #line 462 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamOutOfLimit.__0 = fault_info;

            #line 463 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(self);

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

DoMonitoringReqStatus PUSService12__manage_param_within_limits(PUSService12 * const self) {
    
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
    if (PUSService12__are_status_equal(self, new_status, current_status) == 0) {
        
        #line 488 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (PUSService12__manage_new_status(self)) {
            
            #line 490 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(self);

        }

    }

    #line 494 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

DoMonitoringReqStatus PUSService12__manage_unexpected_value(PUSService12 * const self) {
    
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
        if (PUSService12__manage_new_status(self)) {
            
            #line 333 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.event_triggered = 1;

            #line 334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.__variant = FaultInfo__ParamFaultValue;
            #line 334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->do_monitoring_req_status_update.fault_info.ParamFaultValue.__0 = fault_info;

            #line 335 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_monitoring_transition(self);

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

void PUSService12__do_monitoring(void * const __this, uint16_t PMONID,
                                 uint16_t * const evID,
                                 FaultInfo * const fault_info,
                                 _Bool * const event_triggered) {
    
    PUSService12 * self = (PUSService12 *)__this;

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
            if (PUSService12__is_valid_PMONID(self)) {
                
                #line 686 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_interval_control(self);

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
                if (PUSService12__is_limits_monitoring(self)) {
                    
                    #line 699 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->do_monitoring_req_status.__variant = DoMonitoringReqStatus__DoLimitsMonitoring;

                } else
                #line 702 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (PUSService12__is_expected_value_monitoring(self)) {
                    
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
            CheckLimitsStatus limits_monitoring_status = PUSService12__check_PID_status_limits_monitoring(self);

            #line 722 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorAboveHighLimit) {
                
                #line 724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_above_upper_limit(self);

            } else
            #line 726 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorBelowLowLimit) {
                
                #line 728 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_below_lower_limit(self);

            } else
            #line 731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (limits_monitoring_status.__variant == CheckLimitsStatus__MonitorWithinLimits) {
                
                #line 733 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_param_within_limits(self);

            } else
            {
                

            }

        } else
        #line 742 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->do_monitoring_req_status.__variant == DoMonitoringReqStatus__DoExpectedValueMonitoring) {
            
            #line 744 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            CheckValueStatus exp_value_monitoring_status = PUSService12__check_PID_status_exp_val_monitoring(self);

            #line 747 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueUnexpected) {
                
                #line 748 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_unexpected_value(self);

            } else
            #line 750 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (exp_value_monitoring_status.__variant == CheckValueStatus__MonitorValueExpected) {
                
                #line 752 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->do_monitoring_req_status = PUSService12__manage_expected_value(self);

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
    return;

}

void PUSService12__do_monitoring__mutex_lock(void * const __this,
                                             uint16_t PMONID,
                                             uint16_t * const evID,
                                             FaultInfo * const fault_info,
                                             _Bool * const event_triggered) {
    
    PUSService12 * self = (PUSService12 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService12__do_monitoring(self, PMONID, evID, fault_info,
                                event_triggered);
    __termina_mutex__unlock(self->__mutex_id, &__status);

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

PSExecTCReqStatus PUSService12__exec12_1TC(PUSService12 * const self) {
    
    #line 837 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 837 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 838 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 839 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 839 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 841 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 841 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 841 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 844 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 848 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 846 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 850 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 851 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 853 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 855 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 856 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                current_obt, &result);

            #line 859 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 861 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 863 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 864 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 864 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 868 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 869 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 869 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 876 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            size_t PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID;

            #line 877 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            _Bool is_valid_PMONID = PMONID < 8U;

            #line 879 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_PMONID) {
                
                #line 881 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    #line 883 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 884 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 886 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 888 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 890 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 892 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 893 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 893 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 897 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 904 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 907 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].enabled = 1;

                    #line 908 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].interval_control = 0U;

                    #line 909 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)PMONID)].repetition_control = 0U;

                    #line 911 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __option_box_t tm_handler2;
                    #line 911 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    tm_handler2.__variant = None;

                    #line 912 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 916 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 914 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 918 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        uint16_t tm_count2 = 0U;

                        #line 919 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 920 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 921 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 923 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (ack_enabled) {
                            
                            #line 925 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 927 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 929 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 930 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 930 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 934 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 935 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 935 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 941 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 946 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 946 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 952 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 953 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                current_obt, &result);

                    #line 956 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 958 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 960 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 961 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 961 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 966 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 967 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 967 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 972 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 973 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            current_obt, &result);

                #line 976 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 978 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 980 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 981 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 981 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 986 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 994 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 994 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 998 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

void PUSService12__set_unchecked(PUSService12 * const self) {
    
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

PSExecTCReqStatus PUSService12__exec12_2TC(PUSService12 * const self) {
    
    #line 1004 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 1004 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 1005 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1006 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1006 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1008 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1008 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1008 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1010 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1010 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1011 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1015 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1013 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1017 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1018 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1020 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 1022 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1023 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                current_obt, &result);

            #line 1026 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 1028 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 1030 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 1031 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1031 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 1036 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 1037 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 1037 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 1043 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            _Bool is_valid_PMONID = (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID < 8U;

            #line 1045 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_PMONID) {
                
                #line 1047 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant == MonitorCheckType__Free == 0) {
                    
                    #line 1049 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1050 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 1052 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1054 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 1056 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 1058 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 1059 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 1059 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 1063 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 1064 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 1064 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 1069 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 1072 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->param_mon_config_table[__termina_array__index(8U,
                                                                        (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled = 0;

                    #line 1073 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    PUSService12__set_unchecked(self);

                    #line 1074 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __option_box_t tm_handler2;
                    #line 1074 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    tm_handler2.__variant = None;

                    #line 1075 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 1079 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 1077 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 1081 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        uint16_t tm_count2 = 0U;

                        #line 1082 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 1083 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 1084 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 1086 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (ack_enabled) {
                            
                            #line 1088 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 1090 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 1092 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 1093 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 1093 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 1097 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 1098 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 1098 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 1103 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 1107 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 1107 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 1113 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1114 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                                current_obt, &result);

                    #line 1117 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 1119 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 1121 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 1122 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 1122 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 1127 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 1128 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 1128 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 1133 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1134 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMONID_invalid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            current_obt, &result);

                #line 1137 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 1139 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 1141 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 1142 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 1142 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 1147 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 1148 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 1148 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 1156 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1156 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1160 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__exec12_5TC(PUSService12 * const self) {
    
    #line 1208 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 1208 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 1209 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1210 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1210 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1212 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1212 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1212 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1214 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1214 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1215 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1219 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1217 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1221 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1222 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1224 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.N != 1U) {
            
            #line 1226 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1227 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_5.N,
                                                current_obt, &result);

            #line 1230 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 1232 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 1234 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 1236 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1236 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 1241 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 1242 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 1242 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        #line 1245 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.tc_data_5.mon_config.PID) == 0) {
            
            #line 1247 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1248 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data_5.mon_config.PID,
                                       current_obt, &result);

            #line 1251 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 1253 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 1255 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 1256 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1256 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 1261 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 1262 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 1262 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        #line 1265 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            #line 1267 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (is_valid_check_limit_def(&self->exec_tc_req_status_update.tc_data_5.mon_config.definition)) {
                
                #line 1269 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1270 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 1272 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1274 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 1276 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 1278 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 1279 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 1279 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 1283 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 1284 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 1284 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 1290 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 1293 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                PUSService12__add_valid_mng_mon_def(self);

                #line 1295 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __option_box_t tm_handler2;
                #line 1295 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                tm_handler2.__variant = None;

                #line 1296 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 1300 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 1298 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 1302 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    uint16_t tm_count2 = 0U;

                    #line 1303 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 1304 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1305 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 1307 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1309 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 1311 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 1313 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 1314 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 1314 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 1318 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 1319 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 1319 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 1324 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1328 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1328 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 1334 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1335 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                     current_obt, &result);

                #line 1338 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 1340 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 1342 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 1343 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 1343 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 1348 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 1349 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 1349 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        } else
        #line 1353 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1355 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1356 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 1358 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (ack_enabled) {
                
                #line 1360 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 1362 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 1364 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 1365 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 1365 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 1369 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 1370 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 1370 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 1375 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

            #line 1378 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            PUSService12__add_valid_mng_mon_def(self);

            #line 1380 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            __option_box_t tm_handler2;
            #line 1380 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            tm_handler2.__variant = None;

            #line 1381 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 1385 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 1383 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 1387 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                uint16_t tm_count2 = 0U;

                #line 1388 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                   &tm_count2);

                #line 1389 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1390 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 1392 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1394 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 1396 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 1398 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 1399 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 1399 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 1403 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 1404 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 1404 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 1409 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else
            {
                
                #line 1414 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 1414 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 1419 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1420 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_PMON_definition_invalid((TMHandlerT *)b_tm_handler.data,
                                                 tm_count,
                                                 self->exec_tc_req_status_update.packet_id,
                                                 self->exec_tc_req_status_update.packet_error_ctrl,
                                                 self->exec_tc_req_status_update.tc_data_5.PMONID,
                                                 current_obt, &result);

            #line 1423 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 1425 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 1427 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 1428 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1428 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 1433 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 1434 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 1434 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        }

    } else
    {
        
        #line 1439 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1439 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1443 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__exec12_6TC(PUSService12 * const self) {
    
    #line 1450 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 1450 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 1451 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    _Bool ack_enabled = 0;

    #line 1452 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1452 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1454 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1454 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1454 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1456 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1456 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1457 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1462 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1460 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1464 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1465 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1467 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_1_2_6.N != 1U) {
            
            #line 1469 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1470 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data_1_2_6.N,
                                                current_obt, &result);

            #line 1473 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 1475 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 1477 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 1478 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1478 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 1483 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 1484 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 1484 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 1490 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            MonitorCheckType PMON_type = get_check_type((uint8_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID);

            #line 1492 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (PMON_type.__variant == MonitorCheckType__Free) {
                
                #line 1494 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1495 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMON_undefined((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                            current_obt, &result);

                #line 1498 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 1500 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 1502 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 1503 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 1503 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 1508 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 1509 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 1509 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            #line 1513 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].enabled == 0) {
                
                #line 1515 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1516 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 1518 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (ack_enabled) {
                    
                    #line 1520 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 1522 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 1524 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 1525 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 1525 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 1529 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 1530 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 1530 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 1535 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 1538 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->param_mon_config_table[__termina_array__index(8U,
                                                                    (size_t)self->exec_tc_req_status_update.tc_data_1_2_6.PMONID)].type.__variant = MonitorCheckType__Free;

                #line 1540 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                __option_box_t tm_handler2;
                #line 1540 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                tm_handler2.__variant = None;

                #line 1541 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 1545 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 1543 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 1547 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    uint16_t tm_count2 = 0U;

                    #line 1548 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 1549 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 1550 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 1552 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (ack_enabled) {
                        
                        #line 1554 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 1556 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 1558 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 1559 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 1559 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 1563 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 1564 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 1564 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 1569 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 1574 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 1574 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 1579 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 1580 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                build_tm_1_4_PMON_enabled((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_error_ctrl,
                                          self->exec_tc_req_status_update.tc_data_1_2_6.PMONID,
                                          current_obt, &result);

                #line 1583 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 1585 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 1587 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 1588 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 1588 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 1593 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 1594 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 1594 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 1604 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1604 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1608 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

MonitorDefinition PUSService12__get_PMON_limit_check_definition(const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                MyResult * const result) {
    
    #line 1615 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamLimitCheckDefinition limits_def;
    #line 1615 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.high_limit = 0U;
    #line 1615 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.high_limit_evID = 0U;
    #line 1615 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.low_limit = 0U;
    #line 1615 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    limits_def.low_limit_evID = 0U;

    #line 1622 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

    #line 1626 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 1628 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t low_limit = 0U;

        #line 1629 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t high_limit = 0U;

        #line 1632 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &low_limit);

        #line 1635 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.low_limit_evID);

        #line 1638 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &high_limit);

        #line 1641 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.high_limit_evID);

        #line 1643 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        limits_def.low_limit = (uint32_t)low_limit;

        #line 1644 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        limits_def.high_limit = (uint32_t)high_limit;

    } else
    #line 1647 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 1650 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &limits_def.low_limit);

        #line 1653 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.low_limit_evID);

        #line 1656 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &limits_def.low_limit);

        #line 1659 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &limits_def.high_limit_evID);

    } else
    {
        
        #line 1663 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 1669 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MonitorDefinition param_limit_check_definition;
    #line 1669 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    param_limit_check_definition.__variant = MonitorDefinition__ParamLimitCheck;
    #line 1669 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    param_limit_check_definition.ParamLimitCheck.__0 = limits_def;

    #line 1671 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return param_limit_check_definition;

}

MonitorDefinition PUSService12__get_PMON_value_check_definition(const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                MyResult * const result) {
    
    #line 1678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    ParamValueCheckDefinition value_def;
    #line 1678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    value_def.EvID = 0U;
    #line 1678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    value_def.expected_value = 0U;
    #line 1678 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    value_def.mask_value = 0U;

    #line 1684 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    DataPoolItemType type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.tc_data_5.mon_config.PID);

    #line 1688 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u8_t) {
        
        #line 1690 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t mask = 0U;

        #line 1691 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t expected_value = 0U;

        #line 1694 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &mask);

        #line 1697 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &expected_value);

        #line 1700 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

        #line 1702 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        value_def.mask_value = (uint32_t)mask;

        #line 1703 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        value_def.expected_value = (uint32_t)expected_value;

    } else
    #line 1706 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (type.__variant == DataPoolItemType__u32_t) {
        
        #line 1709 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &value_def.mask_value);

        #line 1712 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                   &value_def.expected_value);

        #line 1715 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler, &value_def.EvID);

    } else
    {
        
        #line 1719 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 1724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MonitorDefinition expected_value_check_definition;
    #line 1724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    expected_value_check_definition.__variant = MonitorDefinition__ParamValueCheck;
    #line 1724 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    expected_value_check_definition.ParamValueCheck.__0 = value_def;

    #line 1725 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return expected_value_check_definition;

}

PS12ExecTCReqStatusUpdate PUSService12__get_TC_params(const PUSService12 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PS12ExecTCReqStatusUpdate tc_data;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.flags_ack = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.packet_id = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_1_2_6.N = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_1_2_6.PMONID = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.N = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.PMONID = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.PID = 0U;
    #line 183 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    tc_data.tc_data_5.mon_config.current_state.__variant = CheckState__Unselected;
    #line 176 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    tc_data.tc_data_5.mon_config.definition.__variant = MonitorDefinition__Unselected;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.enabled = 0;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.interval = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.interval_control = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.repetition = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.repetition_control = 0U;
    #line 182 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    tc_data.tc_data_5.mon_config.temp_state.__variant = CheckState__Unselected;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.transition_obt.finetime = 0U;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_data_5.mon_config.transition_obt.seconds = 0U;
    #line 174 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    tc_data.tc_data_5.mon_config.type.__variant = MonitorCheckType__Free;
    #line 1731 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_num_bytes = 0U;

    #line 1732 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 1733 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 1734 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 1735 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 1737 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 1739 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (*subtype == 1U || *subtype == 2U || *subtype == 6U) {
        
        #line 1741 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        PS12TC_1_2_6_Data tc_data_1_2_6_aux;
        #line 1741 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data_1_2_6_aux.N = 0U;
        #line 1741 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data_1_2_6_aux.PMONID = 0U;

        #line 1747 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data_1_2_6_aux.N);

        #line 1748 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &tc_data_1_2_6_aux.PMONID);

        #line 1750 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data.tc_data_1_2_6 = tc_data_1_2_6_aux;

    } else
    #line 1752 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (*subtype == 5U) {
        
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        ParamMonitoringConfiguration mon_config_aux;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.PID = 0U;
        #line 1765 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.current_state.__variant = CheckState__Unselected;
        #line 1758 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.definition.__variant = MonitorDefinition__Unselected;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.enabled = 0;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.interval = 0U;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.interval_control = 0U;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.repetition = 0U;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.repetition_control = 0U;
        #line 1764 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.temp_state.__variant = CheckState__Unselected;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.transition_obt.finetime = 0U;
        #line 1754 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.transition_obt.seconds = 0U;
        #line 1756 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        mon_config_aux.type.__variant = MonitorCheckType__Free;

        #line 1767 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint8_t aux = 0U;

        #line 1769 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        PS12TC_5_Data tc_data_5_aux;
        #line 1769 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data_5_aux.N = 0U;
        #line 1769 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data_5_aux.PMONID = 0U;
        #line 1769 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data_5_aux.mon_config = mon_config_aux;

        #line 1775 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data_5_aux.N);

        #line 1776 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &tc_data_5_aux.PMONID);

        #line 1777 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler,
                                                   &tc_data_5_aux.mon_config.PID);

        #line 1778 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data_5_aux.mon_config.interval);

        #line 1779 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data_5_aux.mon_config.repetition);

        #line 1780 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &aux);

        #line 1781 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data_5_aux.mon_config.type = get_check_type(aux);

        #line 1783 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__ExpectedValue) {
            
            #line 1785 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            tc_data_5_aux.mon_config.definition = PUSService12__get_PMON_value_check_definition(self,
                                                                                                tc_handler,
                                                                                                result);

        } else
        #line 1788 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status_update.tc_data_5.mon_config.type.__variant == MonitorCheckType__Limits) {
            
            #line 1790 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            tc_data_5_aux.mon_config.definition = PUSService12__get_PMON_limit_check_definition(self,
                                                                                                tc_handler,
                                                                                                result);

        } else
        {
            

        }

        #line 1796 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        tc_data.tc_data_5 = tc_data_5_aux;

    } else
    {
        

    }

    #line 1804 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService12__manage_error_in_acceptance(const PUSService12 * const self) {
    
    #line 1852 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1852 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1853 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 1853 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 1855 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1855 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1855 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1857 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1857 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1858 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1862 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1860 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1864 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1865 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1867 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 1868 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 1871 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 1873 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 1875 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1876 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 1876 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 1880 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 1881 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 1881 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 1886 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1886 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1890 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__manage_short_pack_length_error(const PUSService12 * const self) {
    
    #line 1810 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1810 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1811 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 1811 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 1813 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1813 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1813 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1815 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1815 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1816 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1820 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1818 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1822 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1823 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1824 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 1825 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 1828 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 1830 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 1832 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1833 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 1833 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 1838 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 1839 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 1839 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 1843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1843 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1847 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

PSExecTCReqStatus PUSService12__manage_tm_limit_app_data_reached(const PUSService12 * const self) {
    
    #line 1895 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    PSExecTCReqStatus next_status;
    #line 1895 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 1896 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MyResult result;
    #line 1896 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    result.__variant = MyResult__Ok;

    #line 1898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    MissionObt current_obt;
    #line 1898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.finetime = 0U;
    #line 1898 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    current_obt.seconds = 0U;

    #line 1900 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    __option_box_t tm_handler;
    #line 1900 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    tm_handler.__variant = None;

    #line 1901 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 1905 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1903 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1907 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        uint16_t tm_count = 0U;

        #line 1908 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 1910 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 1911 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 1914 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 1916 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 1918 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1919 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 1919 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 1923 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 1924 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 1924 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 1929 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 1929 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1933 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return next_status;

}

void PUSService12__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService12 * self = (PUSService12 *)__this;

    #line 1939 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    uint8_t subtype = 0U;

    #line 1941 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 1945 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 1947 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            MyResult result;
            #line 1947 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            result.__variant = MyResult__Ok;

            #line 1948 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status_update = PUSService12__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          &result);

            #line 1950 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 1951 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 1951 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 1953 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 1957 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 1959 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 1U) {
                
                #line 1961 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_1TC(self);

            } else
            #line 1963 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 2U) {
                
                #line 1965 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_2TC(self);

            } else
            #line 1967 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 5U) {
                
                #line 1969 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_5TC(self);

            } else
            #line 1971 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (subtype == 6U) {
                
                #line 1973 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__exec12_6TC(self);

            } else
            {
                
                #line 1977 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 1977 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 1980 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 1943 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 1982 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 1984 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 1987 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__manage_error_in_acceptance(self);

            } else
            #line 1989 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 1992 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__manage_tm_limit_app_data_reached(self);

            } else
            #line 1994 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 1996 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
                self->exec_tc_req_status = PUSService12__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 2004 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 1943 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 2006 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).__variant = Failure;
            #line 2006 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 2007 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 2016 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 2018 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 2021 "src/service_libraries/pus_services/pus_service12/pus_service12.fin"
    return;

}

void PUSService12__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService12 * self = (PUSService12 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService12__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService12__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService12__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService12__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService12__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

MonitorCheckType PUSService12__get_PMON_type(const PUSService12 * const self,
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

void PUSService12__is_PMON_enabled(void * const __this, size_t PMONID,
                                   _Bool * const is_enabled) {
    
    PUSService12 * self = (PUSService12 *)__this;

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
    return;

}

void PUSService12__is_PMON_enabled__mutex_lock(void * const __this,
                                               size_t PMONID,
                                               _Bool * const is_enabled) {
    
    PUSService12 * self = (PUSService12 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService12__is_PMON_enabled(self, PMONID, is_enabled);
    __termina_mutex__unlock(self->__mutex_id, &__status);

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
