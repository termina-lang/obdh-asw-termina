
#include "handlers/init.h"

const uint32_t Zero = 2048U;

const uint32_t Unit = 204U;

const uint32_t Dec = 20U;

__status_int32_t Init__init(const __termina_event_t * const __ev,
                            void * const __this, TimeVal _boot_time) {
    
    Init * self = (Init *)__this;

    __status_int32_t ret;
    ret.__variant = Success;

    self->uart.initialize(__ev, self->uart.__that);

    self->gpio_driver.init_gpio(__ev, self->gpio_driver.__that);

    for (size_t i = 5U; i < 12U; i = i + 1U) {
        
        atomic_store(&self->system_data_pool_u32[i], (uint32_t)i);

    }

    atomic_store(&self->system_data_pool_u32[0U],
                 (uint32_t)(Zero + (uint32_t)(1U * Unit)) + (uint32_t)(1U * Dec));

    atomic_store(&self->system_data_pool_u32[1U],
                 (uint32_t)(Zero + (uint32_t)(2U * Unit)) + (uint32_t)(4U * Dec));

    atomic_store(&self->system_data_pool_u32[2U],
                 (uint32_t)(Zero + (uint32_t)(3U * Unit)) + (uint32_t)(2U * Dec));

    atomic_store(&self->system_data_pool_u32[3U],
                 (uint32_t)(Zero + (uint32_t)(4U * Unit)) + (uint32_t)(9U * Dec));

    atomic_store(&self->system_data_pool_u32[4U], Zero + (uint32_t)(5U * Unit));

    for (size_t i = 0U; i < 18U; i = i + 1U) {
        
        atomic_store(&self->system_data_pool_u8[i], (uint8_t)i);

    }

    return ret;

}
