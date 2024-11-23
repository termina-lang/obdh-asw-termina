
#include "service_libraries/pus_services/pus_service12.h"

void trigger_event(EventList * const event_list, uint16_t RID, uint16_t PID,
                   uint16_t PID_value, uint16_t limit, Result * const res) {
    
    EventInfo ev_info;
    ev_info.ev_RID = RID;
    for (size_t __i0 = 0; __i0 < event_aux_data_max_size; __i0 = __i0 + 1) {
        ev_info.ev_aux_data[__i0] = 0;
    }
    ev_info.ev_aux_data_size = 6;

    serialize_uint16(PID, &ev_info.ev_aux_data[0]);

    serialize_uint16(PID_value, &ev_info.ev_aux_data[2]);

    serialize_uint16(limit, &ev_info.ev_aux_data[4]);

    ListResult result = add_event(event_list, ev_info);

    if (result.__variant == ListResult__ListFull) {
        
        (*res).__variant = Result__Error;

    } else {
        
        (*res).__variant = Result__Ok;

    }

    return;

}

void update_state(ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                  size_t PMONID, CheckState new_state) {
    
    if (PMONID < max_num_pmon_ids) {
        
        param_mon_config_table[PMONID].prev_state = param_mon_config_table[PMONID].state;

        param_mon_config_table[PMONID].state = new_state;

        clock_get_uptime(&param_mon_config_table[PMONID].transitionY2K);

    }

    return;

}

void PUSService12__do_monitoring(void * const __this,
                                 EventList * const event_list,
                                 Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0; i < max_num_pmon_ids; i = i + 1) {
        
        if (self->param_mon_config_table[i].enabled == 1) {
            
            uint16_t PID = self->param_mon_config_table[i].PID;

            uint16_t SDP_value = 0;

            SDP_value = atomic_load(&self->system_data_pool[(size_t)PID]);

            if (self->param_mon_config_table[i].interval_control >= self->param_mon_config_table[i].interval) {
                
                self->param_mon_config_table[i].interval_control = 0;

                if (self->param_mon_config_table[i].state.__variant == CheckState__MonitorUnselected == 0) {
                    
                    if (self->param_mon_config_table[i].state.__variant == CheckState__MonitorAboveHighLimit == 0 && self->param_mon_config_table[i].state.__variant == CheckState__MonitorBelowLowLimit == 0) {
                        
                        if (SDP_value > self->param_limit_check_definition[i].high_limit) {
                            
                            trigger_event(event_list,
                                          self->param_limit_check_definition[i].high_limit_rid,
                                          PID, SDP_value,
                                          self->param_limit_check_definition[i].high_limit,
                                          result);

                            CheckState updated_state;
                            updated_state.__variant = CheckState__MonitorAboveHighLimit;

                            update_state(self->param_mon_config_table, i,
                                         updated_state);

                        } else if (SDP_value < self->param_limit_check_definition[i].low_limit) {
                            
                            trigger_event(event_list,
                                          self->param_limit_check_definition[i].low_limit_rid,
                                          PID, SDP_value,
                                          self->param_limit_check_definition[i].low_limit,
                                          result);

                            CheckState updated_state;
                            updated_state.__variant = CheckState__MonitorBelowLowLimit;

                            update_state(self->param_mon_config_table, i,
                                         updated_state);

                        } else {
                            
                            if (self->param_mon_config_table[i].state.__variant == CheckState__MonitorUnchecked) {
                                
                                CheckState updated_state;
                                updated_state.__variant = CheckState__MonitorWithinLimits;

                                update_state(self->param_mon_config_table, i,
                                             updated_state);

                            }

                        }

                    } else {
                        
                        if (SDP_value < self->param_limit_check_definition[i].high_limit && SDP_value > self->param_limit_check_definition[i].low_limit) {
                            
                            CheckState updated_state;
                            updated_state.__variant = CheckState__MonitorWithinLimits;

                            update_state(self->param_mon_config_table, i,
                                         updated_state);

                        }

                    }

                } else {
                    
                    self->param_mon_config_table[i].interval_control = self->param_mon_config_table[i].interval_control + 1;

                }

            }

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService12__exec12_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t PMONID = (size_t)tc_descriptor->tc_bytes[10];

    if (PMONID < max_num_pmon_ids) {
        
        if (self->param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected == 0) {
            
            self->param_mon_config_table[PMONID].enabled = 1;

            self->param_mon_config_table[PMONID].interval_control = 0;

            build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

        } else {
            
            build_tm_1_8_tc_12_X_PMONIDundefined(tm_descriptor, tm_seq_counter,
                                                 (uint16_t)PMONID,
                                                 tc_descriptor);

        }

    } else {
        
        build_tm_1_8_tc_12_X_PMONIDnotvalid(tm_descriptor, tm_seq_counter,
                                            (uint16_t)PMONID, tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService12__exec12_2TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t PMONID = (size_t)tc_descriptor->tc_bytes[10];

    if (PMONID < max_num_pmon_ids) {
        
        if (self->param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected == 0) {
            
            self->param_mon_config_table[PMONID].enabled = 0;

            build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

        } else {
            
            build_tm_1_8_tc_12_X_PMONIDundefined(tm_descriptor, tm_seq_counter,
                                                 (uint16_t)PMONID,
                                                 tc_descriptor);

        }

    } else {
        
        build_tm_1_8_tc_12_X_PMONIDnotvalid(tm_descriptor, tm_seq_counter,
                                            (uint16_t)PMONID, tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService12__exec12_5TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t PMONID = (size_t)deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    if (PMONID < max_num_pmon_ids) {
        
        if (self->param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected) {
            
            uint16_t PID = deserialize_uint16(&tc_descriptor->tc_bytes[12]);

            if ((size_t)PID < sdp_num_params) {
                
                self->param_mon_config_table[PMONID].interval = tc_descriptor->tc_bytes[14];

                self->param_mon_config_table[PMONID].PID = PID;

                self->param_mon_config_table[PMONID].interval_control = 0;

                self->param_mon_config_table[PMONID].state.__variant = CheckState__MonitorUnchecked;

                self->param_limit_check_definition[PMONID].low_limit = deserialize_uint16(&tc_descriptor->tc_bytes[15]);

                self->param_limit_check_definition[PMONID].low_limit_rid = deserialize_uint16(&tc_descriptor->tc_bytes[17]);

                self->param_limit_check_definition[PMONID].high_limit = deserialize_uint16(&tc_descriptor->tc_bytes[19]);

                self->param_limit_check_definition[PMONID].high_limit_rid = deserialize_uint16(&tc_descriptor->tc_bytes[21]);

                build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

            } else {
                
                build_tm_1_8_tc_20_X_PIDnotvalid(tm_descriptor, tm_seq_counter,
                                                 PID, tc_descriptor);

            }

        } else {
            
            build_tm_1_8_tc_12_X_PMONIDdefined(tm_descriptor, tm_seq_counter,
                                               (uint16_t)PMONID, tc_descriptor);

        }

    } else {
        
        build_tm_1_8_tc_12_X_PMONIDnotvalid(tm_descriptor, tm_seq_counter,
                                            (uint16_t)PMONID, tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
