
#include "resources/tm_counter.h"

void TMCounter__get_next_tm_count(void * const __this, uint16_t * const count) {
    
    TMCounter * self = (TMCounter *)__this;

    __termina_resource__lock(&self->__resource);

    *count = self->tm_count;

    self->tm_count = (uint16_t)(self->tm_count + 1) & 0x3FFF;

    __termina_resource__unlock(&self->__resource);

    return;

}
