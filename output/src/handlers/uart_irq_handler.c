
#include "handlers/uart_irq_handler.h"

__status_int32_t UARTIrqHandler__irq_handler(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint32_t _vector) {
    
    UARTIrqHandler * self = (UARTIrqHandler *)__this;

    __status_int32_t status;
    status.__variant = Success;

    uint32_t uart_status = self->uart_registers->status;

    if ((uint32_t)(uart_status & 0x4U) != 0U) {
        
        self->uart.release_tx(__ev, self->uart.__that);

    }

    if ((uint32_t)(uart_status & 0x1U) != 0U) {
        
        __option_size_t tc_completed;
        tc_completed.__variant = None;

        self->uart.enqueue_rx(__ev, self->uart.__that, &tc_completed);

        if (tc_completed.__variant == Some) {
            
            size_t size = tc_completed.Some.__0;

            __termina_out_port__send(__ev, self->rx_frame, (void *)&size);

        } else {
            

        }

    }

    return status;

}
