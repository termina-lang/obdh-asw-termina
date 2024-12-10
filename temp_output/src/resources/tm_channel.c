
#include "resources/tm_channel.h"

void TMChannel__send_tm(void * const __this, __termina_box_t tm_descriptor,
                        Result * const result) {
    
    TMChannel * self = (TMChannel *)__this;

    __termina_resource__lock(&self->__resource);

    CharDevResult queue_state;
    queue_state.__variant = CharDevResult__Success;

    (self->uart.send)(self->uart.__that,
                      (*(TMDescriptorT *)tm_descriptor.data).tm_bytes,
                      (*(TMDescriptorT *)tm_descriptor.data).tm_num_bytes,
                      &queue_state);

    if (queue_state.__variant == CharDevResult__Success) {
        
        (*result).__variant = Result__Ok;

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_pool__free(self->a_tm_descriptor_pool, tm_descriptor);

    __termina_resource__unlock(&self->__resource);

    return;

}
