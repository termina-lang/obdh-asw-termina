
#include "handlers/init.h"

__status_int32_t Init__init(void * const __this, TimeVal _boot_time) {
    
    Init * self = (Init *)__this;

    __status_int32_t ret;
    ret.__variant = Success;

    self->uart.initialize(self->uart.__that);

    self->gpio_driver.init_gpio(self->gpio_driver.__that);

    for (size_t i = 0U; i < sdp_num_u32_params; i = i + 1U) {
        
        atomic_store(&self->system_data_pool_u32[i], (uint32_t)i);

    }

    for (size_t i = 0U; i < sdp_num_u8_params; i = i + 1U) {
        
        atomic_store(&self->system_data_pool_u8[i], (uint8_t)i);

    }

    return ret;

}
