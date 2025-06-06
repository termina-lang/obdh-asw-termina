#ifndef __RESOURCES__GPIO_DRIVER_H__
#define __RESOURCES__GPIO_DRIVER_H__

#include <termina.h>

#include "service_libraries/errors.h"

#include "option.h"

typedef struct {
    uint32_t Data;
    uint32_t Output;
    uint32_t Direction;
} GPIO_registers;

typedef struct {
    void * __that;
    void (* init_gpio)(void * const);
    void (* write_led)(void * const, uint8_t, uint8_t,
                       __status_int32_t * const);
} GPIODrvIface;

typedef struct {
    __termina_id_t __mutex_id;
    volatile GPIO_registers * registers;
} GPIODriver;

void GPIODriver__init_gpio(void * const __this);
void GPIODriver__init_gpio__mutex_lock(void * const __this);
void GPIODriver__init_gpio__task_lock(void * const __this);
void GPIODriver__init_gpio__event_lock(void * const __this);

void GPIODriver__write_led(void * const __this, uint8_t led, uint8_t value,
                           __status_int32_t * const status);
void GPIODriver__write_led__mutex_lock(void * const __this, uint8_t led,
                                       uint8_t value,
                                       __status_int32_t * const status);
void GPIODriver__write_led__task_lock(void * const __this, uint8_t led,
                                      uint8_t value,
                                      __status_int32_t * const status);
void GPIODriver__write_led__event_lock(void * const __this, uint8_t led,
                                       uint8_t value,
                                       __status_int32_t * const status);

#endif
