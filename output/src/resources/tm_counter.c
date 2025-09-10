
#include "resources/tm_counter.h"

void TMCounter__get_next_tm_count(const __termina_event_t * const __ev, void * const __this, uint16_t * const count) {
    
    #line 39 "src/resources/tm_counter.fin"
    TMCounter * self = (TMCounter *)__this;

    #line 39 "src/resources/tm_counter.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 41 "src/resources/tm_counter.fin"
    *count = self->tm_count;

    #line 42 "src/resources/tm_counter.fin"
    self->tm_count = (uint16_t)(self->tm_count + 1U) & 0x3FFFU;

    #line 44 "src/resources/tm_counter.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 44 "src/resources/tm_counter.fin"
    return;

}
