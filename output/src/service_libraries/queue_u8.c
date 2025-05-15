
#include "service_libraries/queue_u8.h"

_Bool is_full(const QueueU8 * const queue) {
    
    #line 17 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_full = queue->num_elements == 1024U;

    #line 18 "src/service_libraries/queue_u8.fin"
    return queue_is_full;

}

_Bool is_empty(const QueueU8 * const queue) {
    
    #line 22 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_empty = queue->num_elements == 0U;

    #line 23 "src/service_libraries/queue_u8.fin"
    return queue_is_empty;

}

QueueResult enqueue(QueueU8 * const queue, uint8_t new_elem) {
    
    #line 28 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_full = is_full(&*queue);

    #line 29 "src/service_libraries/queue_u8.fin"
    QueueResult result;
    #line 29 "src/service_libraries/queue_u8.fin"
    result.__variant = QueueResult__Success;

    #line 31 "src/service_libraries/queue_u8.fin"
    if (0 == queue_is_full) {
        
        #line 32 "src/service_libraries/queue_u8.fin"
        size_t next_tail_index = (size_t)(queue->head_index + queue->num_elements) % 1024U;

        #line 33 "src/service_libraries/queue_u8.fin"
        queue->elements[__termina_array__index(1024U,
                                               next_tail_index)] = new_elem;

        #line 34 "src/service_libraries/queue_u8.fin"
        queue->num_elements = queue->num_elements + 1U;

    } else
    {
        
        #line 36 "src/service_libraries/queue_u8.fin"
        result.__variant = QueueResult__QueueFull;

    }

    #line 38 "src/service_libraries/queue_u8.fin"
    return result;

}

void dequeue(QueueU8 * const queue, __option_uint8_t * const old_elem) {
    
    #line 43 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_empty = is_empty(&*queue);

    #line 45 "src/service_libraries/queue_u8.fin"
    if (0 == queue_is_empty) {
        
        #line 46 "src/service_libraries/queue_u8.fin"
        uint8_t element = queue->elements[__termina_array__index(1024U,
                                                                 queue->head_index)];

        #line 47 "src/service_libraries/queue_u8.fin"
        (*old_elem).__variant = Some;
        #line 47 "src/service_libraries/queue_u8.fin"
        (*old_elem).Some.__0 = element;

        #line 48 "src/service_libraries/queue_u8.fin"
        queue->head_index = (size_t)(queue->head_index + 1U) % 1024U;

        #line 49 "src/service_libraries/queue_u8.fin"
        queue->num_elements = queue->num_elements - 1U;

    } else
    {
        
        #line 51 "src/service_libraries/queue_u8.fin"
        (*old_elem).__variant = None;

    }

    #line 53 "src/service_libraries/queue_u8.fin"
    return;

}

void get_num_enqueued_elems(const QueueU8 * const queue,
                            size_t * const nelems) {
    
    #line 57 "src/service_libraries/queue_u8.fin"
    *nelems = queue->num_elements;

    #line 58 "src/service_libraries/queue_u8.fin"
    return;

}
