
#include "libraries/pus_services/pus_service12.h"

void exec12_1TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids]) {
    
    size_t PMONID = (size_t)tc_descriptor->tc_bytes[10];

    if (PMONID < max_num_pmon_ids) {
        
        if (param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected == 0) {
            
            param_mon_config_table[PMONID].enabled = 1;

            param_mon_config_table[PMONID].interval_control = 0;

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

    return;

}

void exec12_2TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids]) {
    
    size_t PMONID = (size_t)tc_descriptor->tc_bytes[10];

    if (PMONID < max_num_pmon_ids) {
        
        if (param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected == 0) {
            
            param_mon_config_table[PMONID].enabled = 0;

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

    return;

}

void exec12_5TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids]) {
    
    size_t PMONID = (size_t)deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    if (PMONID < max_num_pmon_ids) {
        
        if (param_mon_config_table[PMONID].state.__variant == CheckState__MonitorUnselected) {
            
            uint16_t PID = deserialize_uint16(&tc_descriptor->tc_bytes[12]);

            if ((size_t)PID < SDP_num_params) {
                
                param_mon_config_table[PMONID].interval = tc_descriptor->tc_bytes[14];

                param_mon_config_table[PMONID].PID = PID;

                param_mon_config_table[PMONID].interval_control = 0;

                param_mon_config_table[PMONID].state.__variant = CheckState__MonitorUnchecked;

                param_limit_check_definition[PMONID].low_limit = deserialize_uint16(&tc_descriptor->tc_bytes[15]);

                param_limit_check_definition[PMONID].low_limit_rid = deserialize_uint16(&tc_descriptor->tc_bytes[17]);

                param_limit_check_definition[PMONID].high_limit = deserialize_uint16(&tc_descriptor->tc_bytes[19]);

                param_limit_check_definition[PMONID].high_limit_rid = deserialize_uint16(&tc_descriptor->tc_bytes[21]);

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

    return;

}

void PUS_service_12_execTC(const TCDescriptorT * tc_descriptor,
                           TMDescriptorT * tm_descriptor,
                           uint16_t tm_seq_counter,
                           ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                           ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids]) {
    
    uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

    if (subtype == 1) {
        
        exec12_1TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   param_mon_config_table);

    } else if (subtype == 2) {
        
        exec12_2TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   param_mon_config_table);

    } else if (subtype == 5) {
        
        exec12_5TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   param_mon_config_table, param_limit_check_definition);

    } else {
        

    }

    return;

}

void trigger_event(EventList * event_list, uint16_t RID, uint16_t PID,
                   uint16_t PID_value, uint16_t limit, Result * res) {
    
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
