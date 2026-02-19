#ifndef __RESOURCES__GPIO_DRIVER_H__
#define __RESOURCES__GPIO_DRIVER_H__

#include <termina.h>

#include "service_libraries/errors.h"

#include "option.h"
#include "result.h"

typedef struct {
    uint32_t Data;
    uint32_t Output;
    uint32_t Direction;
} GPIO_registers;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    volatile GPIO_registers * registers;
} GPIODriver;

void GPIODriver__init_gpio(const __termina_event_t * const __ev, void * const __this);

void GPIODriver__write_led(const __termina_event_t * const __ev, void * const __this, uint8_t led, uint8_t value, __status_int32_t * const status);

#endif
