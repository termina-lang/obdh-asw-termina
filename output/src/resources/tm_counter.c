
#include "resources/tm_counter.h"

void TMCounter__get_next_tm_count(void * const __this, uint16_t * const count) {
    
    TMCounter * self = (TMCounter *)__this;

    #line 12 "src/resources/tm_counter.fin"
    *count = self->tm_count;

    #line 13 "src/resources/tm_counter.fin"
    self->tm_count = (uint16_t)(self->tm_count + 1U) & 0x3FFFU;

    #line 15 "src/resources/tm_counter.fin"
    return;

}

void TMCounter__get_next_tm_count__mutex_lock(void * const __this,
                                              uint16_t * const count) {
    
    TMCounter * self = (TMCounter *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    TMCounter__get_next_tm_count(self, count);
    __termina_mutex__unlock(self->__mutex_id, &__status);

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
