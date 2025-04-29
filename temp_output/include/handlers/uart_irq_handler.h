#ifndef __HANDLERS__UART_IRQ_HANDLER_H__
#define __HANDLERS__UART_IRQ_HANDLER_H__

#include <termina.h>

#include "option.h"
#include "resources/uart.h"

extern const uint32_t riscv_uart_dr;

extern const uint32_t riscv_uart_te;

typedef struct {
    __termina_out_port_t byte_message_queue_output;
    volatile UARTRegs * uart_registers;
    struct {
        void * __that;
        void (* release_tx)(void * const);
    } uart;
} UARTIrqHandler;

Result UARTIrqHandler__irq_handler(void * const __this, uint32_t _vector);

#endif
