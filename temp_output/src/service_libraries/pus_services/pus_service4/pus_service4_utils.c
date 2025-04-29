
#include "service_libraries/pus_services/pus_service4/pus_service4_utils.h"

const size_t max_num_of_stats = 4U;

PS4ExecTCReqStatusUpdate ps4_init_tc_req_status_update() {
    
    PS4ExecTCReqStatusUpdate res;
    res.N = 0U;
    res.PID = 0U;
    res.packet_error_ctrl = 0U;
    res.packet_id = 0U;
    res.tc_num_bytes = 0U;

    return res;

}
