#ifndef __RESOURCES__UART_H__
#define __RESOURCES__UART_H__

#include <termina.h>

#include "option.h"
#include "libraries/queue_u8.h"

typedef struct {
    uint32_t data;
    uint32_t status;
    uint32_t control;
    uint32_t scaler;
} UARTRegs;

typedef enum {
    CharDevResult__Success,
    CharDevResult__TXFIFOFull
} __enum_CharDevResult_t;

typedef struct {
    __enum_CharDevResult_t __variant;
} CharDevResult;

#define max_send_size 256

typedef struct {
    void * __that;
    void (* send)(void * __this, const uint8_t output_bytes[max_send_size],
                  size_t nbytes, CharDevResult * result);
} CharDevSend;

typedef struct {
    void * __that;
    void (* initialize)(void * __this);
} CharDevInit;

typedef struct {
    void * __that;
    void (* release_tx)(void * __this);
} CharDevRelayIrq;

typedef struct {
    __termina_resource_t __resource;
    QueueU8 uart_queue;
    _Bool rem_bytes;
    volatile UARTRegs * registers;
} UARTDriver;

_Bool UARTDriver__tf_is_full(const UARTDriver * const self);

void UARTDriver__send(void * const __this,
                      const uint8_t output_bytes[max_send_size], size_t nbytes,
                      CharDevResult * result);

_Bool UARTDriver__tf_is_empty(const UARTDriver * const self);

void UARTDriver__release_tx(void * const __this);

void UARTDriver__initialize(void * const __this);

void UARTDriver__enable_TX(UARTDriver * const self);

void UARTDriver__enable_TI(UARTDriver * const self);

void UARTDriver__enable_RX(UARTDriver * const self);

void UARTDriver__enable_RI(UARTDriver * const self);

void UARTDriver__disable_TF(UARTDriver * const self);

void UARTDriver__disable_RF(UARTDriver * const self);

#endif
