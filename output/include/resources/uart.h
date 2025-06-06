#ifndef __RESOURCES__UART_H__
#define __RESOURCES__UART_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/queue_u8.h"
#include "service_libraries/serialize.h"

#include "option.h"

typedef enum {
    RXStatus__SyncBytesRx,
    RXStatus__SyncLengthRx,
    RXStatus__TCBytesRx,
    RXStatus__FinishedTCRx
} __enum_RXStatus_t;

typedef struct {
    __enum_RXStatus_t __variant;
} RXStatus;

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
    void (* receive)(void * const, __option_uint8_t * const);
} CharDevRecv;

typedef struct {
    void * __that;
    void (* initialize)(void * const);
} CharDevInit;

typedef struct {
    void * __that;
    void (* release_tx)(void * const);
    void (* enqueue_rx)(void * const, __option_size_t * const);
} CharDevRelayIrq;

typedef struct {
    __termina_id_t __mutex_id;
    QueueU8 uart_rx_queue;
    QueueU8 uart_tx_queue;
    _Bool rem_bytes;
    volatile UARTRegs * registers;
    RXStatus rx_status;
    size_t tc_num_bytes;
    uint8_t raw_rx_tc_length[2U];
    size_t aux_index;
    uint8_t sync_word[4U];
} UARTDriver;

void UARTDriver__disable_RF(UARTDriver * const self);

void UARTDriver__disable_TF(UARTDriver * const self);

void UARTDriver__enable_RI(UARTDriver * const self);

void UARTDriver__enable_RX(UARTDriver * const self);

void UARTDriver__enable_TI(UARTDriver * const self);

void UARTDriver__enable_TX(UARTDriver * const self);

_Bool UARTDriver__rf_data_ready(const UARTDriver * const self);

void UARTDriver__enqueue_rx(void * const __this,
                            __option_size_t * const tc_completed);
void UARTDriver__enqueue_rx__mutex_lock(void * const __this,
                                        __option_size_t * const tc_completed);
void UARTDriver__enqueue_rx__task_lock(void * const __this,
                                       __option_size_t * const tc_completed);
void UARTDriver__enqueue_rx__event_lock(void * const __this,
                                        __option_size_t * const tc_completed);

void UARTDriver__initialize(void * const __this);
void UARTDriver__initialize__mutex_lock(void * const __this);
void UARTDriver__initialize__task_lock(void * const __this);
void UARTDriver__initialize__event_lock(void * const __this);

void UARTDriver__receive(void * const __this, __option_uint8_t * const byte);
void UARTDriver__receive__mutex_lock(void * const __this,
                                     __option_uint8_t * const byte);
void UARTDriver__receive__task_lock(void * const __this,
                                    __option_uint8_t * const byte);
void UARTDriver__receive__event_lock(void * const __this,
                                     __option_uint8_t * const byte);

_Bool UARTDriver__tf_is_full(const UARTDriver * const self);

void UARTDriver__release_tx(void * const __this);
void UARTDriver__release_tx__mutex_lock(void * const __this);
void UARTDriver__release_tx__task_lock(void * const __this);
void UARTDriver__release_tx__event_lock(void * const __this);

_Bool UARTDriver__tf_is_empty(const UARTDriver * const self);

void UARTDriver__send(void * const __this, const size_t nbytes,
                      const uint8_t output_bytes[nbytes],
                      __status_int32_t * const status);
void UARTDriver__send__mutex_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const status);
void UARTDriver__send__task_lock(void * const __this, const size_t nbytes,
                                 const uint8_t output_bytes[nbytes],
                                 __status_int32_t * const status);
void UARTDriver__send__event_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const status);

#endif
