
#include "handlers/init.h"

const uint32_t Zero = 2048U;

const uint32_t Unit = 204U;

const uint32_t Dec = 20U;

__status_int32_t Init__init(void * const __this, TimeVal _boot_time) {
    
    Init * self = (Init *)__this;

    #line 44 "src/handlers/init.fin"
    __status_int32_t ret;
    #line 44 "src/handlers/init.fin"
    ret.__variant = Success;

    #line 47 "src/handlers/init.fin"
    self->uart.initialize(self->uart.__that);

    #line 50 "src/handlers/init.fin"
    self->gpio_driver.init_gpio(self->gpio_driver.__that);

    #line 53 "src/handlers/init.fin"
    for (size_t i = 5U; i < 12U; i = i + 1U) {
        
        #line 54 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u32[i], (uint32_t)i);

    }

    #line 58 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[0U],
                 (uint32_t)(Zero + (uint32_t)(1U * Unit)) + (uint32_t)(1U * Dec));

    #line 59 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[1U],
                 (uint32_t)(Zero + (uint32_t)(2U * Unit)) + (uint32_t)(4U * Dec));

    #line 60 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[2U],
                 (uint32_t)(Zero + (uint32_t)(3U * Unit)) + (uint32_t)(2U * Dec));

    #line 61 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[3U],
                 (uint32_t)(Zero + (uint32_t)(4U * Unit)) + (uint32_t)(9U * Dec));

    #line 62 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[4U], Zero + (uint32_t)(5U * Unit));

    #line 65 "src/handlers/init.fin"
    for (size_t i = 0U; i < 18U; i = i + 1U) {
        
        #line 66 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u8[i], (uint8_t)i);

    }

    #line 70 "src/handlers/init.fin"
    return ret;

}
