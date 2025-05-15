
#include "handlers/uart_irq_handler.h"

const uint32_t riscv_uart_dr = 0x1U;

const uint32_t riscv_uart_te = 0x4U;

__status_int32_t UARTIrqHandler__irq_handler(void * const __this,
                                             uint32_t _vector) {
    
    UARTIrqHandler * self = (UARTIrqHandler *)__this;

    #line 16 "src/handlers/uart_irq_handler.fin"
    __status_int32_t ret;
    #line 16 "src/handlers/uart_irq_handler.fin"
    ret.__variant = Success;

    #line 17 "src/handlers/uart_irq_handler.fin"
    uint32_t status = self->uart_registers->status;

    #line 19 "src/handlers/uart_irq_handler.fin"
    if ((uint32_t)(status & riscv_uart_te) != 0U) {
        
        #line 21 "src/handlers/uart_irq_handler.fin"
        self->uart.release_tx(self->uart.__that);

    }

    #line 23 "src/handlers/uart_irq_handler.fin"
    if ((uint32_t)(status & riscv_uart_dr) != 0U) {
        
        #line 25 "src/handlers/uart_irq_handler.fin"
        uint8_t byte = (uint8_t)self->uart_registers->data;

        #line 26 "src/handlers/uart_irq_handler.fin"
        __termina_out_port__send(self->byte_message_queue_output,
                                 (void *)&byte);

    }

    #line 30 "src/handlers/uart_irq_handler.fin"
    return ret;

}
