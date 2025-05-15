
#include "resources/gpio_driver.h"

void GPIODriver__init_gpio(void * const __this) {
    
    GPIODriver * self = (GPIODriver *)__this;

    #line 25 "src/resources/gpio_driver.fin"
    self->registers->Direction = self->registers->Direction | (uint32_t)((uint32_t)((uint32_t)((uint32_t)(1U << 16U) | (uint32_t)(1U << 17U)) | (uint32_t)(1U << 18U)) | (uint32_t)(1U << 19U));

    #line 27 "src/resources/gpio_driver.fin"
    return;

}

void GPIODriver__init_gpio__mutex_lock(void * const __this) {
    
    GPIODriver * self = (GPIODriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    GPIODriver__init_gpio(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

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

void GPIODriver__write_led(void * const __this, uint8_t led, uint8_t value,
                           MyResult * const result) {
    
    GPIODriver * self = (GPIODriver *)__this;

    #line 32 "src/resources/gpio_driver.fin"
    if (led < 4U) {
        
        #line 33 "src/resources/gpio_driver.fin"
        (*result).__variant = MyResult__Ok;

        #line 34 "src/resources/gpio_driver.fin"
        uint8_t bit = led + 16U;

        #line 35 "src/resources/gpio_driver.fin"
        if (value == 0U) {
            
            #line 36 "src/resources/gpio_driver.fin"
            uint32_t mask = 0xFFFFFFFFU ^ (uint32_t)(1U << bit);

            #line 37 "src/resources/gpio_driver.fin"
            self->registers->Output = self->registers->Output & mask;

        } else
        {
            
            #line 39 "src/resources/gpio_driver.fin"
            self->registers->Output = self->registers->Output | (uint32_t)(1U << bit);

        }

    } else
    {
        
        #line 43 "src/resources/gpio_driver.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 46 "src/resources/gpio_driver.fin"
    return;

}

void GPIODriver__write_led__mutex_lock(void * const __this, uint8_t led,
                                       uint8_t value, MyResult * const result) {
    
    GPIODriver * self = (GPIODriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    GPIODriver__write_led(self, led, value, result);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void GPIODriver__write_led__task_lock(void * const __this, uint8_t led,
                                      uint8_t value, MyResult * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    GPIODriver__write_led(__this, led, value, result);
    __termina_task__unlock(lock);

}

void GPIODriver__write_led__event_lock(void * const __this, uint8_t led,
                                       uint8_t value, MyResult * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    GPIODriver__write_led(__this, led, value, result);
    __termina_event__unlock(lock);

}
