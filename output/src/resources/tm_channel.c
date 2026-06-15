
#include "resources/tm_channel.h"

void CTMChannel__send_tm(const __termina_event_t * const __ev, void * const __this, __termina_box_t tm_handler, __status_int32_t * const status) {
    
    #line 52 "src/resources/tm_channel.fin"
    CTMChannel * self = (CTMChannel *)__this;

    #line 52 "src/resources/tm_channel.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 54 "src/resources/tm_channel.fin"
    TMDescriptor tm_descriptor = (*(TMHandler *)tm_handler.data).tm_descriptor;

    #line 57 "src/resources/tm_channel.fin"
    uint8_t frame_header[6U] = { 0xBEU, 0xBAU, 0xBEU, 0xEFU, 0U, 0U };

    #line 61 "src/resources/tm_channel.fin"
    serialize_uint16((uint16_t)tm_descriptor.tm_num_bytes, &frame_header[4U]);

    #line 63 "src/resources/tm_channel.fin"
    for (size_t i = 0U; i < 6U; i = i + 1U) {
        
        #line 65 "src/resources/tm_channel.fin"
        self->char_dev.send(__ev, self->char_dev.__that, frame_header[__termina_array__index(6U, i)], status);

    }

    #line 70 "src/resources/tm_channel.fin"
    for (size_t i = 0U; i < 256U && (i < tm_descriptor.tm_num_bytes && (*status).__variant == Success); i = i + 1U) {
        
        #line 72 "src/resources/tm_channel.fin"
        self->char_dev.send(__ev, self->char_dev.__that, tm_descriptor.tm_bytes[__termina_array__index(256U, i)], status);

    }

    #line 77 "src/resources/tm_channel.fin"
    self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that, tm_handler);

    #line 79 "src/resources/tm_channel.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 79 "src/resources/tm_channel.fin"
    return;

}
