
#include "resources/tm_channel.h"

void TMChannel__send_tm(const __termina_event_t * const __ev,
                        void * const __this, __termina_box_t tm_handler,
                        __status_int32_t * const status) {
    
    TMChannel * self = (TMChannel *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    TMDescriptorT tm_descriptor = (*(TMHandlerT *)tm_handler.data).tm_descriptor;

    uint8_t frame_header[6U];
    frame_header[0U] = 0xBEU;
    frame_header[1U] = 0xBAU;
    frame_header[2U] = 0xBEU;
    frame_header[3U] = 0xEFU;
    frame_header[4U] = 0U;
    frame_header[5U] = 0U;

    serialize_uint16((uint16_t)tm_descriptor.tm_num_bytes, &frame_header[4U]);

    self->uart.send(__ev, self->uart.__that, 6U, frame_header, status);

    for (size_t i = 0U; i < 256U && (i < tm_descriptor.tm_num_bytes && (*status).__variant == Success); i = i + 1U) {
        
        size_t index = (size_t)i;

        self->uart.send(__ev, self->uart.__that, 1U,
                        &tm_descriptor.tm_bytes[__termina_array__slice(256U, 1U,
                                                                       index,
                                                                       index + 1U)],
                        status);

    }

    self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                 tm_handler);

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
