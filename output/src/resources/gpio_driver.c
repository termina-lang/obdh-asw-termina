
#include "resources/gpio_driver.h"

void GPIODriver__init_gpio(const __termina_event_t * const __ev,
                           void * const __this) {
    
    GPIODriver * self = (GPIODriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    self->registers->Direction = self->registers->Direction | (uint32_t)((uint32_t)((uint32_t)((uint32_t)(1U << 16U) | (uint32_t)(1U << 17U)) | (uint32_t)(1U << 18U)) | (uint32_t)(1U << 19U));

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void GPIODriver__write_led(const __termina_event_t * const __ev,
                           void * const __this, uint8_t led, uint8_t value,
                           __status_int32_t * const status) {
    
    GPIODriver * self = (GPIODriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    if (led < 4U) {
        
        (*status).__variant = Success;

        uint8_t bit = led + 16U;

        if (value == 0U) {
            
            uint32_t mask = 0xFFFFFFFFU ^ (uint32_t)(1U << bit);

            self->registers->Output = self->registers->Output & mask;

        } else {
            
            self->registers->Output = self->registers->Output | (uint32_t)(1U << bit);

        }

    } else {
        
        (*status).__variant = Failure;
        (*status).Failure.__0 = INVALID_LED_INDEX_ERROR;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
