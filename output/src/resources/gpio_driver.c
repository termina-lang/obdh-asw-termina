
#include "resources/gpio_driver.h"

void GPIODriver__init_gpio(const __termina_event_t * const __ev, void * const __this) {
    
    #line 46 "src/resources/gpio_driver.fin"
    GPIODriver * self = (GPIODriver *)__this;

    #line 46 "src/resources/gpio_driver.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 48 "src/resources/gpio_driver.fin"
    self->registers->Direction = self->registers->Direction | (uint32_t)((uint32_t)((uint32_t)((uint32_t)(1U << 16U) | (uint32_t)(1U << 17U)) | (uint32_t)(1U << 18U)) | (uint32_t)(1U << 19U));

    #line 50 "src/resources/gpio_driver.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 50 "src/resources/gpio_driver.fin"
    return;

}

void GPIODriver__write_led(const __termina_event_t * const __ev, void * const __this, uint8_t led, uint8_t value, __status_int32_t * const status) {
    
    #line 63 "src/resources/gpio_driver.fin"
    GPIODriver * self = (GPIODriver *)__this;

    #line 63 "src/resources/gpio_driver.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 65 "src/resources/gpio_driver.fin"
    if (led > 5U && led < 10U) {
        
        #line 67 "src/resources/gpio_driver.fin"
        (*status).__variant = Success;

        #line 69 "src/resources/gpio_driver.fin"
        uint8_t bit = led + 17U;

        #line 70 "src/resources/gpio_driver.fin"
        if (value == 0U) {
            
            #line 71 "src/resources/gpio_driver.fin"
            uint32_t mask = 0xFFFFFFFFU ^ (uint32_t)(1U << bit);

            #line 72 "src/resources/gpio_driver.fin"
            self->registers->Output = self->registers->Output & mask;

        } else
        {
            
            #line 74 "src/resources/gpio_driver.fin"
            self->registers->Output = self->registers->Output | (uint32_t)(1U << bit);

        }

    } else
    {
        
        #line 79 "src/resources/gpio_driver.fin"
        (*status).__variant = Failure;
        #line 79 "src/resources/gpio_driver.fin"
        (*status).Failure.__0 = INVALID_LED_INDEX_ERROR;

    }

    #line 83 "src/resources/gpio_driver.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 83 "src/resources/gpio_driver.fin"
    return;

}
