#ifndef __RESOURCES__TM_COUNTER_H__
#define __RESOURCES__TM_COUNTER_H__

#include <termina.h>

#include "option.h"

typedef struct {
    void * __that;
    void (* get_next_tm_count)(void * const, uint16_t * const);
} TMCounterIface;

typedef struct {
    __termina_id_t __mutex_id;
    uint16_t tm_count;
} TMCounter;

void TMCounter__get_next_tm_count(void * const __this, uint16_t * const count);
void TMCounter__get_next_tm_count__mutex_lock(void * const __this,
                                              uint16_t * const count);
void TMCounter__get_next_tm_count__task_lock(void * const __this,
                                             uint16_t * const count);
void TMCounter__get_next_tm_count__event_lock(void * const __this,
                                              uint16_t * const count);

#endif
