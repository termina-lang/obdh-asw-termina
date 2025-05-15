
#include "resources/tm_channel.h"

void TMChannel__send_tm(void * const __this, __termina_box_t tm_handler,
                        MyResult * const result) {
    
    TMChannel * self = (TMChannel *)__this;

    CharDevResult queue_state;
    queue_state.__variant = CharDevResult__Success;

    self->uart.send(self->uart.__that,
                    (*(TMHandlerT *)tm_handler.data).tm_descriptor.tm_bytes,
                    (*(TMHandlerT *)tm_handler.data).tm_descriptor.tm_num_bytes,
                    &queue_state);

    if (queue_state.__variant == CharDevResult__Success) {
        
        (*result).__variant = MyResult__Ok;

    } else {
        
        (*result).__variant = MyResult__Error;

    }

    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that, tm_handler);

    return;

}

void TMChannel__send_tm__mutex_lock(void * const __this,
                                    __termina_box_t tm_handler,
                                    MyResult * const result) {
    
    TMChannel * self = (TMChannel *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    TMChannel__send_tm(self, tm_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void TMChannel__send_tm__task_lock(void * const __this,
                                   __termina_box_t tm_handler,
                                   MyResult * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    TMChannel__send_tm(__this, tm_handler, result);
    __termina_task__unlock(lock);

}

void TMChannel__send_tm__event_lock(void * const __this,
                                    __termina_box_t tm_handler,
                                    MyResult * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    TMChannel__send_tm(__this, tm_handler, result);
    __termina_event__unlock(lock);

}
