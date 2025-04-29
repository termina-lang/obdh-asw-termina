
#include "service_libraries/pus_services/pus_service19/pus_service19_help.h"

const size_t event_action_max_bytes = 242U;

const size_t max_event_action_definitions = 16U;

const size_t event_action_queue_dimension = 8U;

PS19ExecTCReqStatusUpdate ps19_init_tc_req_status_update() {
    
    PS19ExecTCReqStatusUpdate res;
    for (size_t __i0 = 0U; __i0 < max_tc_size; __i0 = __i0 + 1U) {
        res.action_tc_packet.tc_bytes[__i0] = 0U;
    }
    res.action_tc_packet.tc_num_bytes = 0U;
    res.ev_action_ID.ev_action_index = 0U;
    res.ev_action_ID.found = 0;
    res.tc_data.EvID = 0U;
    res.tc_data.N = 0U;
    res.tc_data.packet_error_ctrl = 0U;
    res.tc_data.packet_id = 0U;
    res.tc_data.tc_num_bytes = 0U;

    return res;

}
