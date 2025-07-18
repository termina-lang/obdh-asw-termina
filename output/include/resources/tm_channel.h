#ifndef __RESOURCES__TM_CHANNEL_H__
#define __RESOURCES__TM_CHANNEL_H__

#include <termina.h>

#include "resources/uart.h"
#include "service_libraries/pus_tm_handler.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* send_tm)(void * const, __termina_box_t, __status_int32_t * const);
} TMChannelIface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send)(const __termina_event_t * const, void * const,
                      const size_t, const uint8_t *, __status_int32_t * const);
    } uart;
} TMChannel;

void TMChannel__send_tm(const __termina_event_t * const __ev,
                        void * const __this, __termina_box_t tm_handler,
                        __status_int32_t * const status);

#endif
