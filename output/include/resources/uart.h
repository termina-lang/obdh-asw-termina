#ifndef __RESOURCES__UART_H__
#define __RESOURCES__UART_H__

#include <termina.h>

#include "option.h"

typedef struct {
    uint32_t data;
    uint32_t status;
    uint32_t control;
    uint32_t scaler;
} __attribute__((packed)) UARTRegs;

typedef struct {
    void * __that;
    void (* uart_tf_is_empty)(void * const, _Bool * const);
    void (* uart_enable_TX)(void * const);
    void (* uart_enable_RX)(void * const);
    void (* uart_enable_RI)(void * const);
    void (* putchar)(void * const, uint8_t, __status_int32_t * const);
    void (* getchar)(void * const, __option_uint8_t * const);
} UARTDriverIface;

typedef struct {
    __termina_id_t __mutex_id;
    volatile UARTRegs * uart_regs;
} UARTDriver;

void UARTDriver__getchar(void * const __this,
                         __option_uint8_t * const uart_data);
void UARTDriver__getchar__mutex_lock(void * const __this,
                                     __option_uint8_t * const uart_data);
void UARTDriver__getchar__task_lock(void * const __this,
                                    __option_uint8_t * const uart_data);
void UARTDriver__getchar__event_lock(void * const __this,
                                     __option_uint8_t * const uart_data);

_Bool UARTDriver__uart_tf_is_full(const UARTDriver * const self);

void UARTDriver__putchar(void * const __this, uint8_t c,
                         __status_int32_t * const status);
void UARTDriver__putchar__mutex_lock(void * const __this, uint8_t c,
                                     __status_int32_t * const status);
void UARTDriver__putchar__task_lock(void * const __this, uint8_t c,
                                    __status_int32_t * const status);
void UARTDriver__putchar__event_lock(void * const __this, uint8_t c,
                                     __status_int32_t * const status);

void UARTDriver__uart_enable_RI(void * const __this);
void UARTDriver__uart_enable_RI__mutex_lock(void * const __this);
void UARTDriver__uart_enable_RI__task_lock(void * const __this);
void UARTDriver__uart_enable_RI__event_lock(void * const __this);

void UARTDriver__uart_enable_RX(void * const __this);
void UARTDriver__uart_enable_RX__mutex_lock(void * const __this);
void UARTDriver__uart_enable_RX__task_lock(void * const __this);
void UARTDriver__uart_enable_RX__event_lock(void * const __this);

void UARTDriver__uart_enable_TX(void * const __this);
void UARTDriver__uart_enable_TX__mutex_lock(void * const __this);
void UARTDriver__uart_enable_TX__task_lock(void * const __this);
void UARTDriver__uart_enable_TX__event_lock(void * const __this);

void UARTDriver__uart_tf_is_empty(void * const __this, _Bool * const res);
void UARTDriver__uart_tf_is_empty__mutex_lock(void * const __this,
                                              _Bool * const res);
void UARTDriver__uart_tf_is_empty__task_lock(void * const __this,
                                             _Bool * const res);
void UARTDriver__uart_tf_is_empty__event_lock(void * const __this,
                                              _Bool * const res);

#endif
