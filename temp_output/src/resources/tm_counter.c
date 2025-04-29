
#include "resources/tm_counter.h"

void TMCounter__get_next_tm_count(void * const __this, uint16_t * const count) {
    
    TMCounter * self = (TMCounter *)__this;

    *count = self->tm_count;

    self->tm_count = (uint16_t)(self->tm_count + 1U) & 0x3FFFU;

    return;

}

void TMCounter__get_next_tm_count__mutex_lock(void * const __this,
                                              uint16_t * const count) {
    
    TMCounter * self = (TMCounter *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    TMCounter__get_next_tm_count(self, count);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void TMCounter__get_next_tm_count__task_lock(void * const __this,
                                             uint16_t * const count) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    TMCounter__get_next_tm_count(__this, count);
    __termina_task__unlock(lock);

}

void TMCounter__get_next_tm_count__event_lock(void * const __this,
                                              uint16_t * const count) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    TMCounter__get_next_tm_count(__this, count);
    __termina_event__unlock(lock);

}
