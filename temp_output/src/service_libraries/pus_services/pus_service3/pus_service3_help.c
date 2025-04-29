
#include "service_libraries/pus_services/pus_service3/pus_service3_help.h"

const size_t max_num_of_SIDs = 8U;

const size_t max_params_per_SID = 16U;

PS3ExecTCReqStatusUpdate ps3_init_tc_req_status_update() {
    
    PS3ExecTCReqStatusUpdate ret;
    ret.index.found = 0;
    ret.index.index = 0U;
    ret.tc_data.N = 0U;
    ret.tc_data.SID = 0U;
    ret.tc_data.collection_interval = 0U;
    ret.tc_data.packet_error_ctrl = 0U;
    ret.tc_data.packet_id = 0U;
    ret.tc_data.tc_num_bytes = 0U;

    return ret;

}
