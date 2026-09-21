
#include "resources/tm_channel.h"

void CTMChannel__send_tm(const termina__event_t * const termina__ev, void * const termina__this, termina__box_t tm_handler, Status__i32 * const status) {
    
    #line 52 "src/resources/tm_channel.fin"
    CTMChannel * self = (CTMChannel *)termina__this;

    #line 52 "src/resources/tm_channel.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 54 "src/resources/tm_channel.fin"
    TMDescriptor tm_descriptor = (*(TMHandler *)tm_handler.data).tm_descriptor;

    #line 57 "src/resources/tm_channel.fin"
    uint8_t frame_header[6U] = { 0xBEU, 0xBAU, 0xBEU, 0xEFU, 0U, 0U };

    #line 61 "src/resources/tm_channel.fin"
    serialize_uint16((uint16_t)tm_descriptor.tm_num_bytes, &frame_header[4U]);

    #line 63 "src/resources/tm_channel.fin"
    for (size_t i = 0U; i < 6U; i = i + 1U) {
        
        #line 65 "src/resources/tm_channel.fin"
        self->char_dev.send(termina__ev, self->char_dev._that, frame_header[termina__check__array_index(6U, i)], status);

    }

    #line 70 "src/resources/tm_channel.fin"
    for (size_t i = 0U; i < 256U && (i < tm_descriptor.tm_num_bytes && (*status)._variant == Status__Success); i = i + 1U) {
        
        #line 72 "src/resources/tm_channel.fin"
        self->char_dev.send(termina__ev, self->char_dev._that, tm_descriptor.tm_bytes[termina__check__array_index(256U, i)], status);

    }

    #line 77 "src/resources/tm_channel.fin"
    self->tm_handler_pool.free(termina__ev, self->tm_handler_pool._that, tm_handler);

    #line 79 "src/resources/tm_channel.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 79 "src/resources/tm_channel.fin"
    return;

}
