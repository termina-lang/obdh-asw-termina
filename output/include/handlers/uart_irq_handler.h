#ifndef __HANDLERS__UART_IRQ_HANDLER_H__
#define __HANDLERS__UART_IRQ_HANDLER_H__

#include <termina.h>

#include "resources/uart.h"

#include "option.h"

extern const uint32_t riscv_uart_dr;

extern const uint32_t riscv_uart_te;

typedef struct {
    __termina_id_t __handler_id;
    __termina_out_port_t byte_message_queue_output;
    volatile UARTRegs * uart_registers;
    struct {
        void * __that;
        void (* release_tx)(void * const);
    } uart;
} UARTIrqHandler;

__status_int32_t UARTIrqHandler__irq_handler(void * const __this,
                                             uint32_t _vector);

#endif
