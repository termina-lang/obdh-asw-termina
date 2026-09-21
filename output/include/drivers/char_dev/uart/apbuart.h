#ifndef DRIVERS__CHAR_DEV__UART__APBUART_H__
#define DRIVERS__CHAR_DEV__UART__APBUART_H__

#include <termina.h>

#include "drivers/char_dev.h"
#include "service_libraries/errors.h"
#include "service_libraries/queue_u8.h"

#include "option.h"

extern const size_t hw_fifo_size;

typedef struct {
    uint32_t data;
    uint32_t status;
    uint32_t control;
    uint32_t scaler;
} APBUARTRegs;

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* enqueue)(const termina__event_t * const termina__ev, void * const termina__this, uint8_t byte, CharDevIrqStatus * const status);
    } rx_queue;
    QueueU8 uart_tx_queue;
    _Bool rem_bytes;
    volatile APBUARTRegs * registers;
} CAPBUARTDriver;

void CAPBUARTDriver__initialize(const termina__event_t * const termina__ev, void * const termina__this);

void CAPBUARTDriver__notify_irq(const termina__event_t * const termina__ev, void * const termina__this, CharDevIrqStatus * const status);

void CAPBUARTDriver__send(const termina__event_t * const termina__ev, void * const termina__this, uint8_t output_byte, Status__i32 * const status);

#endif
