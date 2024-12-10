#ifndef __HANDLERS__UART_IRQ_HANDLER_H__
#define __HANDLERS__UART_IRQ_HANDLER_H__

#include <termina.h>

#include "option.h"
#include "resources/uart.h"

#define riscv_uart_dr 0x1

#define riscv_uart_te 0x4

typedef struct {
    __termina_out_port_t byte_message_queue_output;
    volatile UARTRegs * uart_registers;
    CharDevRelayIrq uart;
} UARTIrqHandler;

Result UARTIrqHandler__irq_handler(UARTIrqHandler * const self,
                                   uint32_t _vector);

#endif
