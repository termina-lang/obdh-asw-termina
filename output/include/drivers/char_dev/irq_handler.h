#ifndef DRIVERS__CHAR_DEV__IRQ_HANDLER_H__
#define DRIVERS__CHAR_DEV__IRQ_HANDLER_H__

#include <termina.h>

#include "drivers/char_dev.h"

#include "option.h"

typedef struct {
    termina__id_t _handler_id;
    termina__out_port_t frame_ready_output;
    struct {
        void * _that;
        void (* notify_irq)(const termina__event_t * const termina__ev, void * const termina__this, CharDevIrqStatus * const result);
    } uart_drv;
} CCharDevIRQHandler;

Status__i32 CCharDevIRQHandler__irq_handler(const termina__event_t * const termina__ev, void * const termina__this, const uint32_t termina__ignored__vector);

#endif
