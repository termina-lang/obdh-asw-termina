#ifndef __RESOURCES__UART_H__
#define __RESOURCES__UART_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/queue_u8.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

extern const size_t hw_fifo_size;

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
    __termina_resource_lock_type_t __lock_type;
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

void UARTDriver__disable_RF(const __termina_event_t * const __ev,
                            UARTDriver * const self);

void UARTDriver__disable_TF(const __termina_event_t * const __ev,
                            UARTDriver * const self);

void UARTDriver__disable_TI(const __termina_event_t * const __ev,
                            UARTDriver * const self);

void UARTDriver__enable_RI(const __termina_event_t * const __ev,
                           UARTDriver * const self);

void UARTDriver__enable_RX(const __termina_event_t * const __ev,
                           UARTDriver * const self);

void UARTDriver__enable_TI(const __termina_event_t * const __ev,
                           UARTDriver * const self);

void UARTDriver__enable_TX(const __termina_event_t * const __ev,
                           UARTDriver * const self);

_Bool UARTDriver__rf_data_ready(const __termina_event_t * const __ev,
                                const UARTDriver * const self);

void UARTDriver__enqueue_rx(const __termina_event_t * const __ev,
                            void * const __this,
                            __option_size_t * const tc_completed);

void UARTDriver__initialize(const __termina_event_t * const __ev,
                            void * const __this);

void UARTDriver__receive(const __termina_event_t * const __ev,
                         void * const __this, __option_uint8_t * const byte);

void UARTDriver__release_tx(const __termina_event_t * const __ev,
                            void * const __this);

_Bool UARTDriver__tf_is_empty(const __termina_event_t * const __ev,
                              const UARTDriver * const self);

void UARTDriver__send(const __termina_event_t * const __ev, void * const __this,
                      const size_t nbytes, const uint8_t output_bytes[nbytes],
                      __status_int32_t * const status);

_Bool UARTDriver__tf_is_full(const __termina_event_t * const __ev,
                             const UARTDriver * const self);

#endif
