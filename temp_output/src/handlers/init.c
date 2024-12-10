
#include "handlers/init.h"

Result Init__init(Init * const self, TimeVal _boot_time) {
    
    Result ret;
    ret.__variant = Result__Ok;

    (self->uart.initialize)(self->uart.__that);

    for (size_t i = 0U; i < sdp_num_params; i = i + 1U) {
        
        atomic_store(&self->system_data_pool[i], (uint16_t)i);

    }

    return ret;

}
