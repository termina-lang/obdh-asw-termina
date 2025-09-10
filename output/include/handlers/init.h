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
        void (* init_gpio)(const __termina_event_t * const, void * const);
    } gpio_driver;
    struct {
        void * __that;
        void (* initialize)(const __termina_event_t * const, void * const);
    } uart;
} Init;

__status_int32_t Init__init(const __termina_event_t * const __ev, void * const __this, TimeVal _boot_time);

#endif
