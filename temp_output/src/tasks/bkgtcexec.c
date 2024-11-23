
#include "tasks/bkgtcexec.h"

Result PUSBKGTCExecutor__exec_tc(PUSBKGTCExecutor * const self,
                                 __termina_box_t tc_descriptor) {
    
    Result res;
    res.__variant = Result__Ok;

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        uint8_t tc_type = get_type((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

        uint8_t subtype = get_subtype((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

        if (tc_type == 20) {
            
            if (subtype == 1) {
                
                (self->pus_service_20.exec20_1TC)(self->pus_service_20.__that,
                                                  (TCDescriptorT *)tc_descriptor.data,
                                                  (TMDescriptorT *)descriptor.data,
                                                  tm_count, &res);

            } else if (subtype == 3) {
                
                (self->pus_service_20.exec20_3TC)(self->pus_service_20.__that,
                                                  (TCDescriptorT *)tc_descriptor.data,
                                                  (TMDescriptorT *)descriptor.data,
                                                  tm_count);

            } else {
                

            }

        } else {
            

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, &res);

    } else {
        
        res.__variant = Result__Error;

    }

    __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    return res;

}
