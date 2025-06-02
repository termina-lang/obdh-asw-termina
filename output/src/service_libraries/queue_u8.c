
#include "service_libraries/queue_u8.h"

const size_t queue_max_noe = 1024U;

_Bool is_full(const QueueU8 * const queue) {
    
    #line 14 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_full = queue->num_elements == queue_max_noe;

    #line 15 "src/service_libraries/queue_u8.fin"
    return queue_is_full;

}

_Bool is_empty(const QueueU8 * const queue) {
    
    #line 19 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_empty = queue->num_elements == 0U;

    #line 20 "src/service_libraries/queue_u8.fin"
    return queue_is_empty;

}

__status_int32_t enqueue(QueueU8 * const queue, uint8_t new_elem) {
    
    #line 25 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_full = is_full(&*queue);

    #line 26 "src/service_libraries/queue_u8.fin"
    __status_int32_t status;
    #line 26 "src/service_libraries/queue_u8.fin"
    status.__variant = Success;

    #line 28 "src/service_libraries/queue_u8.fin"
    if (0 == queue_is_full) {
        
        #line 29 "src/service_libraries/queue_u8.fin"
        size_t next_tail_index = (size_t)(queue->head_index + queue->num_elements) % queue_max_noe;

        #line 30 "src/service_libraries/queue_u8.fin"
        queue->elements[__termina_array__index(queue_max_noe,
                                               next_tail_index)] = new_elem;

        #line 31 "src/service_libraries/queue_u8.fin"
        queue->num_elements = queue->num_elements + 1U;

    } else
    {
        
        #line 33 "src/service_libraries/queue_u8.fin"
        status.__variant = Failure;
        #line 33 "src/service_libraries/queue_u8.fin"
        status.Failure.__0 = -(1L);

    }

    #line 35 "src/service_libraries/queue_u8.fin"
    return status;

}

void dequeue(QueueU8 * const queue, __option_uint8_t * const old_elem) {
    
    #line 40 "src/service_libraries/queue_u8.fin"
    _Bool queue_is_empty = is_empty(&*queue);

    #line 42 "src/service_libraries/queue_u8.fin"
    if (0 == queue_is_empty) {
        
        #line 43 "src/service_libraries/queue_u8.fin"
        uint8_t element = queue->elements[__termina_array__index(queue_max_noe,
                                                                 queue->head_index)];

        #line 44 "src/service_libraries/queue_u8.fin"
        (*old_elem).__variant = Some;
        #line 44 "src/service_libraries/queue_u8.fin"
        (*old_elem).Some.__0 = element;

        #line 45 "src/service_libraries/queue_u8.fin"
        queue->head_index = (size_t)(queue->head_index + 1U) % queue_max_noe;

        #line 46 "src/service_libraries/queue_u8.fin"
        queue->num_elements = queue->num_elements - 1U;

    } else
    {
        
        #line 48 "src/service_libraries/queue_u8.fin"
        (*old_elem).__variant = None;

    }

    #line 50 "src/service_libraries/queue_u8.fin"
    return;

}

void get_num_enqueued_elems(const QueueU8 * const queue,
                            size_t * const nelems) {
    
    #line 54 "src/service_libraries/queue_u8.fin"
    *nelems = queue->num_elements;

    #line 55 "src/service_libraries/queue_u8.fin"
    return;

}
