
#include "handlers/uart_irq_handler.h"

__status_int32_t UARTIrqHandler__irq_handler(void * const __this,
                                             uint32_t _vector) {
    
    UARTIrqHandler * self = (UARTIrqHandler *)__this;

    #line 18 "src/handlers/uart_irq_handler.fin"
    __status_int32_t status;
    #line 18 "src/handlers/uart_irq_handler.fin"
    status.__variant = Success;

    #line 19 "src/handlers/uart_irq_handler.fin"
    uint32_t uart_status = self->uart_registers->status;

    #line 21 "src/handlers/uart_irq_handler.fin"
    if ((uint32_t)(uart_status & 0x4U) != 0U) {
        
        #line 23 "src/handlers/uart_irq_handler.fin"
        self->uart.release_tx(self->uart.__that);

    }

    #line 27 "src/handlers/uart_irq_handler.fin"
    if ((uint32_t)(uart_status & 0x1U) != 0U) {
        
        #line 29 "src/handlers/uart_irq_handler.fin"
        __option_size_t tc_completed;
        #line 29 "src/handlers/uart_irq_handler.fin"
        tc_completed.__variant = None;

        #line 30 "src/handlers/uart_irq_handler.fin"
        self->uart.enqueue_rx(self->uart.__that, &tc_completed);

        #line 33 "src/handlers/uart_irq_handler.fin"
        if (tc_completed.__variant == Some) {
            
            #line 32 "src/handlers/uart_irq_handler.fin"
            size_t size = tc_completed.Some.__0;

            #line 34 "src/handlers/uart_irq_handler.fin"
            __termina_out_port__send(self->rx_frame, (void *)&size);

        } else
        {
            

        }

    }

    #line 43 "src/handlers/uart_irq_handler.fin"
    return status;

}
