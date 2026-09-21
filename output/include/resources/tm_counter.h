#ifndef RESOURCES__TM_COUNTER_H__
#define RESOURCES__TM_COUNTER_H__

#include <termina.h>

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    uint16_t tm_count;
} CTMCounter;

void CTMCounter__get_next_tm_count(const termina__event_t * const termina__ev, void * const termina__this, uint16_t * const count);

#endif
