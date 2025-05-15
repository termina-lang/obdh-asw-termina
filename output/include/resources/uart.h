#ifndef __RESOURCES__UART_H__
#define __RESOURCES__UART_H__

#include <termina.h>

#include "option.h"

typedef struct {
    uint32_t data;
    uint32_t status;
    uint32_t control;
    uint32_t scaler;
} UARTRegs;

typedef struct {
    void * __that;
    void (* riscv_uart_tf_is_empty)(void * const, _Bool * const);
    void (* riscv_uart_enable_TX)(void * const);
    void (* riscv_uart_enable_RX)(void * const);
    void (* riscv_uart_enable_RI)(void * const);
    void (* riscv_putchar)(void * const, uint8_t, __status_int32_t * const);
    void (* riscv_getchar)(void * const, __option_uint8_t * const);
} UARTDriver;

typedef struct {
    __termina_id_t __mutex_id;
    volatile UARTRegs * uart_regs;
} CRISCVUARTDriver;

void CRISCVUARTDriver__riscv_getchar(void * const __this,
                                     __option_uint8_t * const uart_data);
void CRISCVUARTDriver__riscv_getchar__mutex_lock(void * const __this,
                                                 __option_uint8_t * const uart_data);
void CRISCVUARTDriver__riscv_getchar__task_lock(void * const __this,
                                                __option_uint8_t * const uart_data);
void CRISCVUARTDriver__riscv_getchar__event_lock(void * const __this,
                                                 __option_uint8_t * const uart_data);

_Bool CRISCVUARTDriver__riscv_uart_tf_is_full(const CRISCVUARTDriver * const self);

void CRISCVUARTDriver__riscv_putchar(void * const __this, uint8_t c,
                                     __status_int32_t * const status);
void CRISCVUARTDriver__riscv_putchar__mutex_lock(void * const __this, uint8_t c,
                                                 __status_int32_t * const status);
void CRISCVUARTDriver__riscv_putchar__task_lock(void * const __this, uint8_t c,
                                                __status_int32_t * const status);
void CRISCVUARTDriver__riscv_putchar__event_lock(void * const __this, uint8_t c,
                                                 __status_int32_t * const status);

void CRISCVUARTDriver__riscv_uart_enable_RI(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_RI__mutex_lock(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_RI__task_lock(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_RI__event_lock(void * const __this);

void CRISCVUARTDriver__riscv_uart_enable_RX(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_RX__mutex_lock(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_RX__task_lock(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_RX__event_lock(void * const __this);

void CRISCVUARTDriver__riscv_uart_enable_TX(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_TX__mutex_lock(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_TX__task_lock(void * const __this);
void CRISCVUARTDriver__riscv_uart_enable_TX__event_lock(void * const __this);

void CRISCVUARTDriver__riscv_uart_tf_is_empty(void * const __this,
                                              _Bool * const res);
void CRISCVUARTDriver__riscv_uart_tf_is_empty__mutex_lock(void * const __this,
                                                          _Bool * const res);
void CRISCVUARTDriver__riscv_uart_tf_is_empty__task_lock(void * const __this,
                                                         _Bool * const res);
void CRISCVUARTDriver__riscv_uart_tf_is_empty__event_lock(void * const __this,
                                                          _Bool * const res);

#endif
