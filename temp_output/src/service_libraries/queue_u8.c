
#include "service_libraries/queue_u8.h"

const size_t queue_max_noe = 1024U;

_Bool is_full(const QueueU8 * const queue) {
    
    _Bool queue_is_full = queue->num_elements == queue_max_noe;

    return queue_is_full;

}

_Bool is_empty(const QueueU8 * const queue) {
    
    _Bool queue_is_empty = queue->num_elements == 0U;

    return queue_is_empty;

}

QueueResult enqueue(QueueU8 * const queue, uint8_t new_elem) {
    
    _Bool queue_is_full = is_full(&*queue);

    QueueResult result;
    result.__variant = QueueResult__Success;

    if (0 == queue_is_full) {
        
        size_t next_tail_index = (size_t)(queue->head_index + queue->num_elements) % queue_max_noe;

        queue->elements[__termina_array__index(queue_max_noe,
                                               next_tail_index)] = new_elem;

        queue->num_elements = queue->num_elements + 1U;

    } else {
        
        result.__variant = QueueResult__QueueFull;

    }

    return result;

}

void dequeue(QueueU8 * const queue, __option_uint8_t * const old_elem) {
    
    _Bool queue_is_empty = is_empty(&*queue);

    if (0 == queue_is_empty) {
        
        uint8_t element = queue->elements[__termina_array__index(queue_max_noe,
                                                                 queue->head_index)];

        (*old_elem).__variant = Some;
        (*old_elem).Some.__0 = element;

        queue->head_index = (size_t)(queue->head_index + 1U) % queue_max_noe;

        queue->num_elements = queue->num_elements - 1U;

    } else {
        
        (*old_elem).__variant = None;

    }

    return;

}

void get_num_enqueued_elems(const QueueU8 * const queue,
                            size_t * const nelems) {
    
    *nelems = queue->num_elements;

    return;

}
