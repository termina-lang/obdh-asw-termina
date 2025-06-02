
#include "resources/system_data_pool.h"

DataPoolItemType sys_data_pool_get_item_type(uint16_t PID) {
    
    #line 52 "src/resources/system_data_pool.fin"
    DataPoolItemType sdp_type;
    #line 52 "src/resources/system_data_pool.fin"
    sdp_type.__variant = DataPoolItemType__NoValidPID;

    #line 54 "src/resources/system_data_pool.fin"
    if ((size_t)PID < (size_t)(12U - 1U)) {
        
        #line 56 "src/resources/system_data_pool.fin"
        sdp_type.__variant = DataPoolItemType__u32_t;

    } else
    {
        
        #line 60 "src/resources/system_data_pool.fin"
        sdp_type.__variant = DataPoolItemType__u8_t;

    }

    #line 63 "src/resources/system_data_pool.fin"
    if ((size_t)PID >= (size_t)((size_t)((size_t)(12U - 1U) + 18U) - 1U)) {
        
        #line 65 "src/resources/system_data_pool.fin"
        sdp_type.__variant = DataPoolItemType__NoValidPID;

    }

    #line 68 "src/resources/system_data_pool.fin"
    return sdp_type;

}

_Bool sys_data_pool_is_valid_PID(uint16_t PID) {
    
    #line 81 "src/resources/system_data_pool.fin"
    _Bool is_valid = (size_t)PID < (size_t)((size_t)((size_t)(12U - 1U) + 18U) - 1U);

    #line 82 "src/resources/system_data_pool.fin"
    return is_valid;

}

_Bool sys_data_pool_is_PID_update_via_TC_enabled(uint16_t PID) {
    
    #line 97 "src/resources/system_data_pool.fin"
    _Bool is_enable = PID >= 5U;

    #line 98 "src/resources/system_data_pool.fin"
    return is_enable;

}
