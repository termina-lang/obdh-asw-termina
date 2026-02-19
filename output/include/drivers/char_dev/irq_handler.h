#ifndef __DRIVERS__CHAR_DEV__IRQ_HANDLER_H__
#define __DRIVERS__CHAR_DEV__IRQ_HANDLER_H__

#include <termina.h>

#include "drivers/char_dev.h"

#include "option.h"
#include "result.h"

typedef struct {
    __termina_id_t __handler_id;
    __termina_out_port_t notify_rx;
    struct {
        void * __that;
        void (* notify_irq)(const __termina_event_t * const, void * const, __result_bool__int32_t * const);
    } uart_drv;
} CCharDevIRQHandler;

__status_int32_t CCharDevIRQHandler__irq_handler(const __termina_event_t * const __ev, void * const __this, uint32_t _vector);

#endif
