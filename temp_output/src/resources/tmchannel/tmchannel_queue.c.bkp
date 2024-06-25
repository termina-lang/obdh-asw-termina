
#include "resources/tmchannel/tmchannel_queue.h"

void QueueU8__enqueue(void * const __this, uint8_t new_elem,
                      QueueResult * result) {
    
    QueueU8 * self = (QueueU8 *)__this;

    __termina_resource__lock(&self->__resource);

    _Bool queue_is_full = QueueU8__is_full(self);

    if (0 == queue_is_full) {
        
        size_t next_tail_index = (size_t)(self->head_index + self->num_elements) % queue_max_noe;

        self->elements[next_tail_index] = new_elem;

        self->num_elements = self->num_elements + 1;

        (*result).__variant = QueueResult__Success;

    } else {
        
        (*result).__variant = QueueResult__QueueFull;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

_Bool QueueU8__is_full(const QueueU8 * const self) {
    
    _Bool queue_is_full = self->num_elements == queue_max_noe;

    return queue_is_full;

}

void QueueU8__dequeue(void * const __this, __option_uint8_t * old_elem) {
    
    QueueU8 * self = (QueueU8 *)__this;

    __termina_resource__lock(&self->__resource);

    _Bool queue_is_empty = QueueU8__is_empty(self);

    if (0 == queue_is_empty) {
        
        uint8_t element = self->elements[self->head_index];

        (*old_elem).__variant = Some;
        (*old_elem).Some.__0 = element;

        self->head_index = (size_t)(self->head_index + 1) % queue_max_noe;

        self->num_elements = self->num_elements - 1;

    } else {
        
        (*old_elem).__variant = None;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

_Bool QueueU8__is_empty(const QueueU8 * const self) {
    
    _Bool queue_is_empty = self->num_elements == 0;

    return queue_is_empty;

}
