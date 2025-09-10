
#include "handlers/uart_irq_handler.h"

__status_int32_t UARTIrqHandler__irq_handler(const __termina_event_t * const __ev, void * const __this, uint32_t _vector) {
    
    #line 46 "src/handlers/uart_irq_handler.fin"
    UARTIrqHandler * self = (UARTIrqHandler *)__this;

    #line 48 "src/handlers/uart_irq_handler.fin"
    __status_int32_t status;
    #line 48 "src/handlers/uart_irq_handler.fin"
    status.__variant = Success;

    #line 49 "src/handlers/uart_irq_handler.fin"
    uint32_t uart_status = self->uart_registers->status;

    #line 51 "src/handlers/uart_irq_handler.fin"
    if ((uint32_t)(uart_status & 0x4U) != 0U) {
        
        #line 53 "src/handlers/uart_irq_handler.fin"
        self->uart.release_tx(__ev, self->uart.__that);

    }

    #line 57 "src/handlers/uart_irq_handler.fin"
    if ((uint32_t)(uart_status & 0x1U) != 0U) {
        
        #line 59 "src/handlers/uart_irq_handler.fin"
        __option_size_t tc_completed;
        #line 59 "src/handlers/uart_irq_handler.fin"
        tc_completed.__variant = None;

        #line 60 "src/handlers/uart_irq_handler.fin"
        self->uart.enqueue_rx(__ev, self->uart.__that, &tc_completed);

        #line 63 "src/handlers/uart_irq_handler.fin"
        if (tc_completed.__variant == Some) {
            
            #line 63 "src/handlers/uart_irq_handler.fin"
            size_t size = tc_completed.Some.__0;

            #line 64 "src/handlers/uart_irq_handler.fin"
            __termina_out_port__send(__ev, self->rx_frame, (void *)&size);

        } else
        {
            

        }

    }

    #line 73 "src/handlers/uart_irq_handler.fin"
    return status;

}
