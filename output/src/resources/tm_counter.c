
#include "resources/tm_counter.h"

void TMCounter__get_next_tm_count(const __termina_event_t * const __ev,
                                  void * const __this, uint16_t * const count) {
    
    TMCounter * self = (TMCounter *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    *count = self->tm_count;

    self->tm_count = (uint16_t)(self->tm_count + 1U) & 0x3FFFU;

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
