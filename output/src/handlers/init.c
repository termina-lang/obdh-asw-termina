
#include "handlers/init.h"

const uint32_t Zero = 2048U;

const uint32_t Unit = 204U;

const uint32_t Dec = 20U;

__status_int32_t Init__init(void * const __this, TimeVal _boot_time) {
    
    Init * self = (Init *)__this;

    #line 21 "src/handlers/init.fin"
    __status_int32_t ret;
    #line 21 "src/handlers/init.fin"
    ret.__variant = Success;

    #line 24 "src/handlers/init.fin"
    self->uart.riscv_uart_enable_RX(self->uart.__that);

    #line 25 "src/handlers/init.fin"
    self->uart.riscv_uart_enable_TX(self->uart.__that);

    #line 26 "src/handlers/init.fin"
    self->uart.riscv_uart_enable_RI(self->uart.__that);

    #line 29 "src/handlers/init.fin"
    self->gpio_driver.init_gpio(self->gpio_driver.__that);

    #line 31 "src/handlers/init.fin"
    for (size_t i = 5U; i < 12U; i = i + 1U) {
        
        #line 32 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u32[i], (uint32_t)i);

    }

    #line 34 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[0U],
                 (uint32_t)(Zero + (uint32_t)(1U * Unit)) + (uint32_t)(1U * Dec));

    #line 35 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[1U],
                 (uint32_t)(Zero + (uint32_t)(2U * Unit)) + (uint32_t)(4U * Dec));

    #line 36 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[2U],
                 (uint32_t)(Zero + (uint32_t)(3U * Unit)) + (uint32_t)(2U * Dec));

    #line 37 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[3U],
                 (uint32_t)(Zero + (uint32_t)(4U * Unit)) + (uint32_t)(9U * Dec));

    #line 38 "src/handlers/init.fin"
    atomic_store(&self->system_data_pool_u32[4U], Zero + (uint32_t)(5U * Unit));

    #line 40 "src/handlers/init.fin"
    for (size_t i = 0U; i < 18U; i = i + 1U) {
        
        #line 41 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u8[i], (uint8_t)i);

    }

    #line 46 "src/handlers/init.fin"
    return ret;

}
