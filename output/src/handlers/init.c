
#include "handlers/init.h"

const uint32_t Zero = 2048U;

const uint32_t Unit = 204U;

const uint32_t Dec = 20U;

Status__i32 CInitHandler__init(const termina__event_t * const termina__ev, void * const termina__this, const TimeVal termina__ignored__boot_time) {
    
    (void)termina__ignored__boot_time;

    #line 42 "src/handlers/init.fin"
    CInitHandler * self = (CInitHandler *)termina__this;

    #line 44 "src/handlers/init.fin"
    Status__i32 ret = { ._variant = Status__Success };

    #line 47 "src/handlers/init.fin"
    self->uart_drv.initialize(termina__ev, self->uart_drv._that);

    #line 50 "src/handlers/init.fin"
    self->gpio_driver.init_gpio(termina__ev, self->gpio_driver._that);

    #line 53 "src/handlers/init.fin"
    for (size_t i = 5U; i < 12U; i = i + 1U) {
        
        #line 54 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u32[i], (uint32_t)i);

    }

    #line 56 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[10U], 5U);

    #line 58 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[0U], 2272U);

    #line 59 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[1U], 2536U);

    #line 60 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[2U], 2700U);

    #line 61 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[3U], 3044U);

    #line 62 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[4U], 3068U);

    #line 65 "src/handlers/init.fin"
    for (size_t i = 0U; i < 18U; i = i + 1U) {
        
        #line 66 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u8[i], (uint8_t)i);

    }

    #line 70 "src/handlers/init.fin"
    return ret;

}
