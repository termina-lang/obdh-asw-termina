
#include "resources/gpio_driver.h"

void GPIODriver__init_gpio(void * const __this) {
    
    GPIODriver * self = (GPIODriver *)__this;

    #line 52 "src/resources/gpio_driver.fin"
    self->registers->Direction = self->registers->Direction | (uint32_t)((uint32_t)((uint32_t)((uint32_t)(1U << 16U) | (uint32_t)(1U << 17U)) | (uint32_t)(1U << 18U)) | (uint32_t)(1U << 19U));

    #line 54 "src/resources/gpio_driver.fin"
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
                           __status_int32_t * const status) {
    
    GPIODriver * self = (GPIODriver *)__this;

    #line 69 "src/resources/gpio_driver.fin"
    if (led < 4U) {
        
        #line 71 "src/resources/gpio_driver.fin"
        (*status).__variant = Success;

        #line 73 "src/resources/gpio_driver.fin"
        uint8_t bit = led + 16U;

        #line 74 "src/resources/gpio_driver.fin"
        if (value == 0U) {
            
            #line 75 "src/resources/gpio_driver.fin"
            uint32_t mask = 0xFFFFFFFFU ^ (uint32_t)(1U << bit);

            #line 76 "src/resources/gpio_driver.fin"
            self->registers->Output = self->registers->Output & mask;

        } else
        {
            
            #line 78 "src/resources/gpio_driver.fin"
            self->registers->Output = self->registers->Output | (uint32_t)(1U << bit);

        }

    } else
    {
        
        #line 83 "src/resources/gpio_driver.fin"
        (*status).__variant = Failure;
        #line 83 "src/resources/gpio_driver.fin"
        (*status).Failure.__0 = INVALID_LED_INDEX_ERROR;

    }

    #line 87 "src/resources/gpio_driver.fin"
    return;

}

void GPIODriver__write_led__mutex_lock(void * const __this, uint8_t led,
                                       uint8_t value,
                                       __status_int32_t * const status) {
    
    GPIODriver * self = (GPIODriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    GPIODriver__write_led(self, led, value, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void GPIODriver__write_led__task_lock(void * const __this, uint8_t led,
                                      uint8_t value,
                                      __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    GPIODriver__write_led(__this, led, value, status);
    __termina_task__unlock(lock);

}

void GPIODriver__write_led__event_lock(void * const __this, uint8_t led,
                                       uint8_t value,
                                       __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    GPIODriver__write_led(__this, led, value, status);
    __termina_event__unlock(lock);

}
