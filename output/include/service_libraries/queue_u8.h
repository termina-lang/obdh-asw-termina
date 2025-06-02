#ifndef __SERVICE_LIBRARIES__QUEUE_U8_H__
#define __SERVICE_LIBRARIES__QUEUE_U8_H__

#include <termina.h>

#include "option.h"

extern const size_t queue_max_noe;

typedef struct {
    uint8_t elements[1024U];
    size_t head_index;
    size_t num_elements;
} QueueU8;

_Bool is_full(const QueueU8 * const queue);

_Bool is_empty(const QueueU8 * const queue);

__status_int32_t enqueue(QueueU8 * const queue, uint8_t new_elem);

void dequeue(QueueU8 * const queue, __option_uint8_t * const old_elem);

void get_num_enqueued_elems(const QueueU8 * const queue, size_t * const nelems);

#endif
