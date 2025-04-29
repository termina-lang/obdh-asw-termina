
#include "resources/gpio_driver.h"

void GPIODriver__init_gpio(void * const __this) {
    
    GPIODriver * self = (GPIODriver *)__this;

    self->registers->Direction = self->registers->Direction | (uint32_t)((uint32_t)((uint32_t)((uint32_t)(1U << 16U) | (uint32_t)(1U << 17U)) | (uint32_t)(1U << 18U)) | (uint32_t)(1U << 19U));

    return;

}

void GPIODriver__init_gpio__mutex_lock(void * const __this) {
    
    GPIODriver * self = (GPIODriver *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    GPIODriver__init_gpio(self);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void GPIODriver__init_gpio__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    GPIODriver__init_gpio(__this);
    __termina_task__unlock(lock);

}

void GPIODriver__init_gpio__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    GPIODriver__init_gpio(__this);
    __termina_event__unlock(lock);

}

void GPIODriver__write_led(void * const __this, uint8_t led, uint8_t value) {
    
    GPIODriver * self = (GPIODriver *)__this;

    if (led < 4U) {
        
        uint8_t bit = led + 16U;

        if (value == 0U) {
            
            uint32_t mask = 0xFFFFFFFFU ^ (uint32_t)(1U << bit);

            self->registers->Output = self->registers->Output & mask;

        } else {
            
            self->registers->Output = self->registers->Output | (uint32_t)(1U << bit);

        }

    }

    return;

}

void GPIODriver__write_led__mutex_lock(void * const __this, uint8_t led,
                                       uint8_t value) {
    
    GPIODriver * self = (GPIODriver *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    GPIODriver__write_led(self, led, value);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void GPIODriver__write_led__task_lock(void * const __this, uint8_t led,
                                      uint8_t value) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    GPIODriver__write_led(__this, led, value);
    __termina_task__unlock(lock);

}

void GPIODriver__write_led__event_lock(void * const __this, uint8_t led,
                                       uint8_t value) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    GPIODriver__write_led(__this, led, value);
    __termina_event__unlock(lock);

}
