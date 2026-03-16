#ifndef __RESOURCES__TM_COUNTER_H__
#define __RESOURCES__TM_COUNTER_H__

#include <termina.h>

#include "option.h"

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    uint16_t tm_count;
} CTMCounter;

void CTMCounter__get_next_tm_count(const __termina_event_t * const __ev, void * const __this, uint16_t * const count);

#endif
