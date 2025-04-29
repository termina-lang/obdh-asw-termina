
#include "handlers/uart_irq_handler.h"

const uint32_t riscv_uart_dr = 0x1U;

const uint32_t riscv_uart_te = 0x4U;

Result UARTIrqHandler__irq_handler(void * const __this, uint32_t _vector) {
    
    UARTIrqHandler * self = (UARTIrqHandler *)__this;

    Result ret;
    ret.__variant = Result__Ok;

    uint32_t status = self->uart_registers->status;

    if ((uint32_t)(status & riscv_uart_te) != 0U) {
        
        (self->uart.release_tx)(self->uart.__that);

    }

    if ((uint32_t)(status & riscv_uart_dr) != 0U) {
        
        uint8_t byte = (uint8_t)self->uart_registers->data;

        __termina_out_port__send(self->byte_message_queue_output,
                                 (void *)&byte);

    }

    return ret;

}
