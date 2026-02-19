
#include "drivers/char_dev/irq_handler.h"

__status_int32_t CCharDevIRQHandler__irq_handler(const __termina_event_t * const __ev, void * const __this, uint32_t _vector) {
    
    #line 14 "src/drivers/char_dev/irq_handler.fin"
    CCharDevIRQHandler * self = (CCharDevIRQHandler *)__this;

    #line 16 "src/drivers/char_dev/irq_handler.fin"
    __status_int32_t status;
    #line 16 "src/drivers/char_dev/irq_handler.fin"
    status.__variant = Success;

    #line 17 "src/drivers/char_dev/irq_handler.fin"
    __result_bool__int32_t result;
    #line 17 "src/drivers/char_dev/irq_handler.fin"
    result.__variant = Ok;
    #line 17 "src/drivers/char_dev/irq_handler.fin"
    result.Ok.__0 = 0;

    #line 19 "src/drivers/char_dev/irq_handler.fin"
    self->uart_drv.notify_irq(__ev, self->uart_drv.__that, &result);

    #line 22 "src/drivers/char_dev/irq_handler.fin"
    if (result.__variant == Ok) {
        
        #line 22 "src/drivers/char_dev/irq_handler.fin"
        _Bool notify = result.Ok.__0;

        #line 24 "src/drivers/char_dev/irq_handler.fin"
        if (notify) {
            
            #line 25 "src/drivers/char_dev/irq_handler.fin"
            __termina_out_port__send(__ev, self->notify_rx, NULL);

        }

    } else
    {
        
        #line 28 "src/drivers/char_dev/irq_handler.fin"
        int32_t error_code = result.Error.__0;

        #line 29 "src/drivers/char_dev/irq_handler.fin"
        status.__variant = Failure;
        #line 29 "src/drivers/char_dev/irq_handler.fin"
        status.Failure.__0 = error_code;

    }

    #line 33 "src/drivers/char_dev/irq_handler.fin"
    return status;

}
