
#include "resources/tm_counter.h"

void CTMCounter__get_next_tm_count(const termina__event_t * const termina__ev, void * const termina__this, uint16_t * const count) {
    
    #line 39 "src/resources/tm_counter.fin"
    CTMCounter * self = (CTMCounter *)termina__this;

    #line 39 "src/resources/tm_counter.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 41 "src/resources/tm_counter.fin"
    *count = self->tm_count;

    #line 42 "src/resources/tm_counter.fin"
    self->tm_count = (uint16_t)(self->tm_count + 1U) & 0x3FFFU;

    #line 44 "src/resources/tm_counter.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 44 "src/resources/tm_counter.fin"
    return;

}
