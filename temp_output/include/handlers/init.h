#ifndef __HANDLERS__INIT_H__
#define __HANDLERS__INIT_H__

#include <termina.h>

#include "resources/system_data_pool.h"
#include "resources/uart.h"

#include "option.h"

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
        void (* initialize)(void * const);
    } uart;
} Init;

__status_int32_t Init__init(void * const __this, TimeVal _boot_time);

#endif
