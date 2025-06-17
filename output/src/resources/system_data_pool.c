
#include "resources/system_data_pool.h"

DataPoolItemType sys_data_pool_get_item_type(uint16_t PID) {
    
    DataPoolItemType sdp_type;
    sdp_type.__variant = DataPoolItemType__NoValidPID;

    if ((size_t)PID < (size_t)(12U - 1U)) {
        
        sdp_type.__variant = DataPoolItemType__u32_t;

    } else {
        
        sdp_type.__variant = DataPoolItemType__u8_t;

    }

    if ((size_t)PID >= (size_t)((size_t)((size_t)(12U - 1U) + 18U) - 1U)) {
        
        sdp_type.__variant = DataPoolItemType__NoValidPID;

    }

    return sdp_type;

}

_Bool sys_data_pool_is_valid_PID(uint16_t PID) {
    
    _Bool is_valid = (size_t)PID < (size_t)((size_t)((size_t)(12U - 1U) + 18U) - 1U);

    return is_valid;

}

_Bool sys_data_pool_is_PID_update_via_TC_enabled(uint16_t PID) {
    
    _Bool is_enable = PID >= 5U;

    return is_enable;

}
