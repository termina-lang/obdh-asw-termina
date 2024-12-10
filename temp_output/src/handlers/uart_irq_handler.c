
#include "handlers/uart_irq_handler.h"

Result UARTIrqHandler__irq_handler(UARTIrqHandler * const self,
                                   uint32_t _vector) {
    
    Result ret;
    ret.__variant = Result__Ok;

    uint32_t status = self->uart_registers->status;

    if ((uint32_t)(status & riscv_uart_te) != 0) {
        
        (self->uart.release_tx)(self->uart.__that);

    }

    if ((uint32_t)(status & riscv_uart_dr) != 0) {
        
        uint8_t byte = (uint8_t)self->uart_registers->data;

        __termina_msg_queue__send(self->byte_message_queue_output,
                                  (void *)&byte);

    }

    return ret;

}
