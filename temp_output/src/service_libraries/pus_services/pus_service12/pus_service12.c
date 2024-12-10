
#include "service_libraries/pus_services/pus_service12/pus_service12.h"

void PUSService12__do_monitoring(void * const __this,
                                 EventList * const event_list,
                                 Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0U; i < max_num_pmon_ids; i = i + 1U) {
        
        if (self->param_mon_config_table[i].enabled == 1) {
            
            uint16_t PID = self->param_mon_config_table[i].PID;

            uint16_t SDP_value = 0U;

            SDP_value = atomic_load(&self->system_data_pool[(size_t)PID]);

            if (self->param_mon_config_table[i].interval_control >= self->param_mon_config_table[i].interval) {
                
                self->param_mon_config_table[i].interval_control = 0U;

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
                    
                    self->param_mon_config_table[i].interval_control = self->param_mon_config_table[i].interval_control + 1U;

                }

            }

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService12__exec12_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t PMONID = (size_t)tc_descriptor->tc_bytes[10U];

        if (PMONID < max_num_pmon_ids) {
            
            if (self->param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected == 0) {
                
                self->param_mon_config_table[PMONID].enabled = 1;

                self->param_mon_config_table[PMONID].interval_control = 0U;

                build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                             tc_descriptor);

            } else {
                
                build_tm_1_8_tc_12_X_PMONIDundefined((TMDescriptorT *)descriptor.data,
                                                     tm_count, (uint16_t)PMONID,
                                                     tc_descriptor);

            }

        } else {
            
            build_tm_1_8_tc_12_X_PMONIDnotvalid((TMDescriptorT *)descriptor.data,
                                                tm_count, (uint16_t)PMONID,
                                                tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService12__exec12_2TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t PMONID = (size_t)tc_descriptor->tc_bytes[10U];

        if (PMONID < max_num_pmon_ids) {
            
            if (self->param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected == 0) {
                
                self->param_mon_config_table[PMONID].enabled = 0;

                build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                             tc_descriptor);

            } else {
                
                build_tm_1_8_tc_12_X_PMONIDundefined((TMDescriptorT *)descriptor.data,
                                                     tm_count, (uint16_t)PMONID,
                                                     tc_descriptor);

            }

        } else {
            
            build_tm_1_8_tc_12_X_PMONIDnotvalid((TMDescriptorT *)descriptor.data,
                                                tm_count, (uint16_t)PMONID,
                                                tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService12__exec12_5TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService12 * self = (PUSService12 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t PMONID = (size_t)deserialize_uint16(&tc_descriptor->tc_bytes[10U]);

        if (PMONID < max_num_pmon_ids) {
            
            if (self->param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected) {
                
                uint16_t PID = deserialize_uint16(&tc_descriptor->tc_bytes[12U]);

                if ((size_t)PID < sdp_num_params) {
                    
                    self->param_mon_config_table[PMONID].interval = tc_descriptor->tc_bytes[14U];

                    self->param_mon_config_table[PMONID].PID = PID;

                    self->param_mon_config_table[PMONID].interval_control = 0U;

                    self->param_mon_config_table[PMONID].state.__variant = CheckState__MonitorUnchecked;

                    self->param_limit_check_definition[PMONID].low_limit = deserialize_uint16(&tc_descriptor->tc_bytes[15U]);

                    self->param_limit_check_definition[PMONID].low_limit_rid = deserialize_uint16(&tc_descriptor->tc_bytes[17U]);

                    self->param_limit_check_definition[PMONID].high_limit = deserialize_uint16(&tc_descriptor->tc_bytes[19U]);

                    self->param_limit_check_definition[PMONID].high_limit_rid = deserialize_uint16(&tc_descriptor->tc_bytes[21U]);

                    build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                                 tc_descriptor);

                } else {
                    
                    build_tm_1_8_tc_20_X_PIDnotvalid((TMDescriptorT *)descriptor.data,
                                                     tm_count, PID,
                                                     tc_descriptor);

                }

            } else {
                
                build_tm_1_8_tc_12_X_PMONIDdefined((TMDescriptorT *)descriptor.data,
                                                   tm_count, (uint16_t)PMONID,
                                                   tc_descriptor);

            }

        } else {
            
            build_tm_1_8_tc_12_X_PMONIDnotvalid((TMDescriptorT *)descriptor.data,
                                                tm_count, (uint16_t)PMONID,
                                                tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
