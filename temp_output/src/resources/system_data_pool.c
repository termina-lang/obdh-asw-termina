
#include "resources/system_data_pool.h"

void SystemDataPool__write_value(void * const __this, size_t index,
                                 uint16_t value) {
    
    SystemDataPool * self = (SystemDataPool *)__this;

    __termina_resource__lock(&self->__resource);

    self->sdp_values[index] = value;

    __termina_resource__unlock(&self->__resource);

    return;

}

void SystemDataPool__read_value(void * const __this, size_t index,
                                uint16_t * r_value) {
    
    SystemDataPool * self = (SystemDataPool *)__this;

    __termina_resource__lock(&self->__resource);

    *r_value = self->sdp_values[index];

    __termina_resource__unlock(&self->__resource);

    return;

}

void SystemDataPool__init(void * const __this) {
    
    SystemDataPool * self = (SystemDataPool *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0; i < SDP_num_params; i = i + 1) {
        
        self->sdp_values[i] = (uint16_t)i;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
