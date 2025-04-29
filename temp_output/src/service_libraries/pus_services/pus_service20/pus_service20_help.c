
#include "service_libraries/pus_services/pus_service20/pus_service20_help.h"

PS20ExecTCReqStatusUpdate ps20_init_tc_req_status_update() {
    
    PS20ExecTCReqStatusUpdate res;
    res.N = 0U;
    res.PID = 0U;
    res.packet_error_ctrl = 0U;
    res.packet_id = 0U;
    res.tc_20_3_data.PID_value_u32 = 0U;
    res.tc_20_3_data.PID_value_u8 = 0U;
    res.tc_num_bytes = 0U;

    return res;

}
