#ifndef __RESOURCES__UART_H__
#define __RESOURCES__UART_H__

#include <termina.h>

#include "service_libraries/queue_u8.h"

#include "option.h"

typedef struct {
    uint32_t data;
    uint32_t status;
    uint32_t control;
    uint32_t scaler;
} UARTRegs;

typedef struct {
    void * __that;
    void (* send)(void * const, const size_t, const uint8_t *,
                  __status_int32_t * const);
} CharDevSend;

typedef struct {
    void * __that;
    void (* initialize)(void * const);
} CharDevInit;

typedef struct {
    void * __that;
    void (* release_tx)(void * const);
} CharDevRelayIrq;

typedef struct {
    __termina_id_t __mutex_id;
    QueueU8 uart_queue;
    _Bool rem_bytes;
    volatile UARTRegs * registers;
} UARTDriver;

void UARTDriver__disable_RF(UARTDriver * const self);

void UARTDriver__disable_TF(UARTDriver * const self);

void UARTDriver__enable_RI(UARTDriver * const self);

void UARTDriver__enable_RX(UARTDriver * const self);

void UARTDriver__enable_TI(UARTDriver * const self);

void UARTDriver__enable_TX(UARTDriver * const self);

void UARTDriver__initialize(void * const __this);
void UARTDriver__initialize__mutex_lock(void * const __this);
void UARTDriver__initialize__task_lock(void * const __this);
void UARTDriver__initialize__event_lock(void * const __this);

_Bool UARTDriver__tf_is_full(const UARTDriver * const self);

void UARTDriver__release_tx(void * const __this);
void UARTDriver__release_tx__mutex_lock(void * const __this);
void UARTDriver__release_tx__task_lock(void * const __this);
void UARTDriver__release_tx__event_lock(void * const __this);

_Bool UARTDriver__tf_is_empty(const UARTDriver * const self);

void UARTDriver__send(void * const __this, const size_t nbytes,
                      const uint8_t output_bytes[nbytes],
                      __status_int32_t * const result);
void UARTDriver__send__mutex_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const result);
void UARTDriver__send__task_lock(void * const __this, const size_t nbytes,
                                 const uint8_t output_bytes[nbytes],
                                 __status_int32_t * const result);
void UARTDriver__send__event_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const result);

#endif
