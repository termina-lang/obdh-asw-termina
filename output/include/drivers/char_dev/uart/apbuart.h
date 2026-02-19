#ifndef __DRIVERS__CHAR_DEV__UART__APBUART_H__
#define __DRIVERS__CHAR_DEV__UART__APBUART_H__

#include <termina.h>

#include "drivers/char_dev.h"
#include "service_libraries/errors.h"
#include "service_libraries/queue_u8.h"

#include "option.h"
#include "result.h"

extern const size_t hw_fifo_size;

typedef struct {
    uint32_t data;
    uint32_t status;
    uint32_t control;
    uint32_t scaler;
} APBUARTRegs;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* enqueue_rx)(const __termina_event_t * const, void * const, uint8_t, __result_bool__int32_t * const);
    } rx_queue;
    QueueU8 uart_tx_queue;
    _Bool rem_bytes;
    volatile APBUARTRegs * registers;
} CAPBUARTDriver;

void CAPBUARTDriver__disable_RF(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__disable_TF(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__disable_TI(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__enable_RI(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__enable_RX(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__enable_TI(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__enable_TX(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__initialize(const __termina_event_t * const __ev, void * const __this);

void CAPBUARTDriver__release_tx(const __termina_event_t * const __ev, CAPBUARTDriver * const self);

void CAPBUARTDriver__notify_irq(const __termina_event_t * const __ev, void * const __this, __result_bool__int32_t * const result);

_Bool CAPBUARTDriver__rf_data_ready(const __termina_event_t * const __ev, const CAPBUARTDriver * const self);

_Bool CAPBUARTDriver__tf_is_empty(const __termina_event_t * const __ev, const CAPBUARTDriver * const self);

void CAPBUARTDriver__send(const __termina_event_t * const __ev, void * const __this, const size_t nbytes, const uint8_t output_bytes[nbytes], __status_int32_t * const status);

_Bool CAPBUARTDriver__tf_is_full(const __termina_event_t * const __ev, const CAPBUARTDriver * const self);

#endif
