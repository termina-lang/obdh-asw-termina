#ifndef RESOURCES__TM_CHANNEL_H__
#define RESOURCES__TM_CHANNEL_H__

#include <termina.h>

#include "drivers/char_dev.h"
#include "service_libraries/pus_tm_handler.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    termina__allocator_t tm_handler_pool;
    struct {
        void * _that;
        void (* send)(const termina__event_t * const termina__ev, void * const termina__this, const uint8_t output_byte, Status__i32 * const status);
    } char_dev;
} CTMChannel;

void CTMChannel__send_tm(const termina__event_t * const termina__ev, void * const termina__this, const termina__box_t tm_handler, Status__i32 * const status);

#endif
