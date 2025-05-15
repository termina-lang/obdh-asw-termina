
#include "resources/tm_channel.h"

void TMChannel__send_tm(void * const __this, __termina_box_t tm_handler,
                        MyResult * const result) {
    
    TMChannel * self = (TMChannel *)__this;

    #line 20 "src/resources/tm_channel.fin"
    TMDescriptorT tm_descriptor = (*(TMHandlerT *)tm_handler.data).tm_descriptor;

    #line 22 "src/resources/tm_channel.fin"
    uint8_t frame_header[6U];
    #line 22 "src/resources/tm_channel.fin"
    for (size_t __i0 = 0U; __i0 < 6U; __i0 = __i0 + 1U) {
        #line 22 "src/resources/tm_channel.fin"
        frame_header[__i0] = 0U;
    }

    #line 23 "src/resources/tm_channel.fin"
    uint32_t write_timeout = 0U;

    #line 24 "src/resources/tm_channel.fin"
    _Bool check = 0;

    #line 26 "src/resources/tm_channel.fin"
    (*result).__variant = MyResult__Ok;

    #line 28 "src/resources/tm_channel.fin"
    frame_header[0U] = 0xBEU;

    #line 29 "src/resources/tm_channel.fin"
    frame_header[1U] = 0xBAU;

    #line 30 "src/resources/tm_channel.fin"
    frame_header[2U] = 0xBEU;

    #line 31 "src/resources/tm_channel.fin"
    frame_header[3U] = 0xEFU;

    #line 34 "src/resources/tm_channel.fin"
    serialize_uint16((uint16_t)tm_descriptor.tm_num_bytes, &frame_header[4U]);

    #line 36 "src/resources/tm_channel.fin"
    __status_int32_t status;
    #line 36 "src/resources/tm_channel.fin"
    status.__variant = Success;

    #line 38 "src/resources/tm_channel.fin"
    for (uint8_t i = 0U; i < 6U && status.__variant == Success; i = i + 1U) {
        
        #line 40 "src/resources/tm_channel.fin"
        self->uart.riscv_putchar(self->uart.__that,
                                 frame_header[__termina_array__index(6U,
                                                                     (size_t)i)],
                                 &status);

    }

    #line 44 "src/resources/tm_channel.fin"
    for (size_t j = 0U; j < 256U && (j < tm_descriptor.tm_num_bytes && status.__variant == Success); j = j + 1U) {
        
        #line 46 "src/resources/tm_channel.fin"
        self->uart.riscv_putchar(self->uart.__that,
                                 tm_descriptor.tm_bytes[__termina_array__index(256U,
                                                                               (size_t)j)],
                                 &status);

    }

    #line 50 "src/resources/tm_channel.fin"
    self->uart.riscv_uart_tf_is_empty(self->uart.__that, &check);

    #line 52 "src/resources/tm_channel.fin"
    for (uint32_t k = 0U; k < 0xAAAAAU && check == 0; k = k + 1U) {
        
        #line 54 "src/resources/tm_channel.fin"
        self->uart.riscv_uart_tf_is_empty(self->uart.__that, &check);

        #line 55 "src/resources/tm_channel.fin"
        write_timeout = write_timeout + 1U;

    }

    #line 59 "src/resources/tm_channel.fin"
    if (write_timeout < 0xAAAAAU) {
        

    }

    #line 65 "src/resources/tm_channel.fin"
    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that, tm_handler);

    #line 68 "src/resources/tm_channel.fin"
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
