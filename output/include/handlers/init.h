#ifndef HANDLERS__INIT_H__
#define HANDLERS__INIT_H__

#include <termina.h>

#include "drivers/char_dev/uart/apbuart.h"
#include "resources/gpio_driver.h"
#include "resources/system_data_pool.h"

#include "option.h"

extern const uint32_t Zero;

extern const uint32_t Unit;

extern const uint32_t Dec;

typedef struct {
    termina__id_t _handler_id;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    struct {
        void * _that;
        void (* init_gpio)(const termina__event_t * const termina__ev, void * const termina__this);
    } gpio_driver;
    struct {
        void * _that;
        void (* initialize)(const termina__event_t * const termina__ev, void * const termina__this);
    } uart_drv;
} CInitHandler;

Status__i32 CInitHandler__init(const termina__event_t * const termina__ev, void * const termina__this, TimeVal termina__ignored__boot_time);

#endif
