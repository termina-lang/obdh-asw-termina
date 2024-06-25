#ifndef __RESOURCES__TMCHANNEL__TMCHANNEL_QUEUE_H__
#define __RESOURCES__TMCHANNEL__TMCHANNEL_QUEUE_H__

#include <termina.h>
#include "modules/tm_ccsds_pus_format.h"

#define queue_max_noe 1024

typedef enum {
    QueueResult__Success,
    QueueResult__QueueFull
} __enum_QueueResult_t;

typedef struct {
    __enum_QueueResult_t __variant;
} QueueResult;

typedef struct {
    void * __that;
    void (* enqueue)(void * __this, uint8_t new_elem, QueueResult * result);
    void (* dequeue)(void * __this, __option_uint8_t * old_elem);
} QueueIO;

typedef struct {
    __termina_resource_t __resource;
    size_t num_elements;
    size_t head_index;
    uint8_t elements[queue_max_noe];
} QueueU8;

void QueueU8__enqueue(void * const __this, uint8_t new_elem,
                      QueueResult * result);

_Bool QueueU8__is_full(const QueueU8 * const self);

void QueueU8__dequeue(void * const __this, __option_uint8_t * old_elem);

_Bool QueueU8__is_empty(const QueueU8 * const self);

#endif
