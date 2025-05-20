#ifndef __HANDLERS__INIT_H__
#define __HANDLERS__INIT_H__

#include <termina.h>

#include "resources/gpio_driver.h"
#include "resources/system_data_pool.h"
#include "resources/uart.h"

#include "option.h"

extern const uint32_t Zero;

extern const uint32_t Unit;

extern const uint32_t Dec;

typedef struct {
    __termina_id_t __handler_id;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    struct {
        void * __that;
        void (* init_gpio)(void * const);
    } gpio_driver;
    struct {
        void * __that;
        void (* riscv_uart_enable_RI)(void * const);
        void (* riscv_uart_enable_RX)(void * const);
        void (* riscv_uart_enable_TX)(void * const);
    } uart;
} Init;

__status_int32_t Init__init(void * const __this, TimeVal _boot_time);

#endif
