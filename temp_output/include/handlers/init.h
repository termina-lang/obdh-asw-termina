#ifndef __HANDLERS__INIT_H__
#define __HANDLERS__INIT_H__

#include <termina.h>

#include "option.h"
#include "resources/uart.h"
#include "resources/system_data_pool.h"

typedef struct {
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    struct {
        void * __that;
        void (* init_gpio)(void * const);
    } gpio_driver;
    struct {
        void * __that;
        void (* initialize)(void * const);
    } uart;
} Init;

Result Init__init(void * const __this, TimeVal _boot_time);

#endif
