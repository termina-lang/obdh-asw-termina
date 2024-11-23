
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

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
