
#include "resources/tm_channel.h"

void TMChannel__send_tm(void * const __this, __termina_box_t tm_handler,
                        MyResult * const result) {
    
    TMChannel * self = (TMChannel *)__this;

    #line 21 "src/resources/tm_channel.fin"
    CharDevResult queue_state;
    #line 21 "src/resources/tm_channel.fin"
    queue_state.__variant = CharDevResult__Success;

    #line 23 "src/resources/tm_channel.fin"
    self->uart.send(self->uart.__that,
                    (*(TMHandlerT *)tm_handler.data).tm_descriptor.tm_bytes,
                    (*(TMHandlerT *)tm_handler.data).tm_descriptor.tm_num_bytes,
                    &queue_state);

    #line 25 "src/resources/tm_channel.fin"
    if (queue_state.__variant == CharDevResult__Success) {
        
        #line 27 "src/resources/tm_channel.fin"
        (*result).__variant = MyResult__Ok;

    } else
    {
        
        #line 31 "src/resources/tm_channel.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 35 "src/resources/tm_channel.fin"
    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that, tm_handler);

    #line 37 "src/resources/tm_channel.fin"
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
