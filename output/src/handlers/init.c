
#include "handlers/init.h"

__status_int32_t Init__init(void * const __this, TimeVal _boot_time) {
    
    Init * self = (Init *)__this;

    #line 17 "src/handlers/init.fin"
    __status_int32_t ret;
    #line 17 "src/handlers/init.fin"
    ret.__variant = Success;

    #line 20 "src/handlers/init.fin"
    self->uart.riscv_uart_enable_RX(self->uart.__that);

    #line 21 "src/handlers/init.fin"
    self->uart.riscv_uart_enable_TX(self->uart.__that);

    #line 22 "src/handlers/init.fin"
    self->uart.riscv_uart_enable_RI(self->uart.__that);

    #line 25 "src/handlers/init.fin"
    self->gpio_driver.init_gpio(self->gpio_driver.__that);

    #line 27 "src/handlers/init.fin"
    for (size_t i = 0U; i < 12U; i = i + 1U) {
        
        #line 28 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u32[i], (uint32_t)i);

    }

    #line 30 "src/handlers/init.fin"
    for (size_t i = 0U; i < 18U; i = i + 1U) {
        
        #line 31 "src/handlers/init.fin"
        atomic_store(&self->system_data_pool_u8[i], (uint8_t)i);

    }

    #line 36 "src/handlers/init.fin"
    return ret;

}
