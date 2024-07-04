#ifndef __RESOURCES__TM_COUNTER_H__
#define __RESOURCES__TM_COUNTER_H__

#include <termina.h>

#include "option.h"

typedef struct {
    void * __that;
    void (* get_next_tm_count)(void * __this, uint16_t * count);
} TMCounterIface;

typedef struct {
    __termina_resource_t __resource;
    uint16_t tm_count;
} TMCounter;

void TMCounter__get_next_tm_count(void * const __this, uint16_t * count);

#endif
