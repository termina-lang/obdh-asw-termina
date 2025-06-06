
#include "resources/tm_channel.h"

void TMChannel__send_tm(void * const __this, __termina_box_t tm_handler,
                        __status_int32_t * const status) {
    
    TMChannel * self = (TMChannel *)__this;

    #line 54 "src/resources/tm_channel.fin"
    TMDescriptorT tm_descriptor = (*(TMHandlerT *)tm_handler.data).tm_descriptor;

    #line 57 "src/resources/tm_channel.fin"
    uint8_t frame_header[6U];
    #line 57 "src/resources/tm_channel.fin"
    frame_header[0U] = 0xBEU;
    #line 57 "src/resources/tm_channel.fin"
    frame_header[1U] = 0xBAU;
    #line 57 "src/resources/tm_channel.fin"
    frame_header[2U] = 0xBEU;
    #line 57 "src/resources/tm_channel.fin"
    frame_header[3U] = 0xEFU;
    #line 57 "src/resources/tm_channel.fin"
    frame_header[4U] = 0U;
    #line 57 "src/resources/tm_channel.fin"
    frame_header[5U] = 0U;

    #line 61 "src/resources/tm_channel.fin"
    serialize_uint16((uint16_t)tm_descriptor.tm_num_bytes, &frame_header[4U]);

    #line 64 "src/resources/tm_channel.fin"
    self->uart.send(self->uart.__that, 6U, frame_header, status);

    #line 67 "src/resources/tm_channel.fin"
    for (size_t i = 0U; i < 256U && (i < tm_descriptor.tm_num_bytes && (*status).__variant == Success); i = i + 1U) {
        
        #line 69 "src/resources/tm_channel.fin"
        size_t index = (size_t)i;

        #line 71 "src/resources/tm_channel.fin"
        self->uart.send(self->uart.__that, 1U,
                        &tm_descriptor.tm_bytes[__termina_array__slice(256U, 1U,
                                                                       index,
                                                                       index + 1U)],
                        status);

    }

    #line 76 "src/resources/tm_channel.fin"
    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that, tm_handler);

    #line 78 "src/resources/tm_channel.fin"
    return;

}

void TMChannel__send_tm__mutex_lock(void * const __this,
                                    __termina_box_t tm_handler,
                                    __status_int32_t * const status) {
    
    TMChannel * self = (TMChannel *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    TMChannel__send_tm(self, tm_handler, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void TMChannel__send_tm__task_lock(void * const __this,
                                   __termina_box_t tm_handler,
                                   __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    TMChannel__send_tm(__this, tm_handler, status);
    __termina_task__unlock(lock);

}

void TMChannel__send_tm__event_lock(void * const __this,
                                    __termina_box_t tm_handler,
                                    __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    TMChannel__send_tm(__this, tm_handler, status);
    __termina_event__unlock(lock);

}
