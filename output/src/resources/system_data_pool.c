
#include "resources/system_data_pool.h"

const size_t sdp_last_u32_param_id = 11U;

const size_t sdp_last_u8_param_id = 28U;

const size_t sdp_first_u32_param_id = 0U;

const size_t sdp_first_u8_param_id = 11U;

DataPoolItemType sys_data_pool_get_item_type(uint16_t PID) {
    
    #line 19 "src/resources/system_data_pool.fin"
    DataPoolItemType sdp_type;
    #line 19 "src/resources/system_data_pool.fin"
    sdp_type.__variant = DataPoolItemType__NoValidPID;

    #line 21 "src/resources/system_data_pool.fin"
    if ((size_t)PID < sdp_last_u32_param_id) {
        
        #line 23 "src/resources/system_data_pool.fin"
        sdp_type.__variant = DataPoolItemType__u32_t;

    } else
    {
        
        #line 27 "src/resources/system_data_pool.fin"
        sdp_type.__variant = DataPoolItemType__u8_t;

    }

    #line 30 "src/resources/system_data_pool.fin"
    if ((size_t)PID >= sdp_last_u8_param_id) {
        
        #line 32 "src/resources/system_data_pool.fin"
        sdp_type.__variant = DataPoolItemType__NoValidPID;

    }

    #line 35 "src/resources/system_data_pool.fin"
    return sdp_type;

}

_Bool sys_data_pool_is_valid_PID(uint16_t PID) {
    
    #line 40 "src/resources/system_data_pool.fin"
    _Bool is_valid = (size_t)PID < sdp_last_u8_param_id;

    #line 41 "src/resources/system_data_pool.fin"
    return is_valid;

}

_Bool sys_data_pool_is_PID_update_via_TC_enabled(uint16_t PID) {
    
    #line 47 "src/resources/system_data_pool.fin"
    _Bool is_enable = PID >= 5U;

    #line 48 "src/resources/system_data_pool.fin"
    return is_enable;

}
