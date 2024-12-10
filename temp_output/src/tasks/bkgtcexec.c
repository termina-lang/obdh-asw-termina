
#include "tasks/bkgtcexec.h"

Result PUSBKGTCExecutor__exec_tc(PUSBKGTCExecutor * const self,
                                 __termina_box_t tc_descriptor) {
    
    Result res;
    res.__variant = Result__Ok;

    uint8_t tc_type = get_type((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

    uint8_t subtype = get_subtype((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

    if (tc_type == 20U) {
        
        if (subtype == 1U) {
            
            (self->pus_service_20.exec20_1TC)(self->pus_service_20.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 3U) {
            
            (self->pus_service_20.exec20_3TC)(self->pus_service_20.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else {
            

        }

    } else {
        

    }

    __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    return res;

}
