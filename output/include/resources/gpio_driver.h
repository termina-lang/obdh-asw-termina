#ifndef RESOURCES__GPIO_DRIVER_H__
#define RESOURCES__GPIO_DRIVER_H__

#include <termina.h>

#include "service_libraries/errors.h"

#include "option.h"

typedef struct {
    uint32_t Data;
    uint32_t Output;
    uint32_t Direction;
} GPIO_registers;

typedef struct {
    termina__resource_lock_type_t _lock_type;
    volatile GPIO_registers * registers;
} CGPIODriver;

void CGPIODriver__init_gpio(const termina__event_t * const termina__ev, void * const termina__this);

void CGPIODriver__write_led(const termina__event_t * const termina__ev, void * const termina__this, const uint8_t led, const uint8_t value, Status__i32 * const status);

#endif
