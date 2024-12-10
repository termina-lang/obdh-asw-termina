
#include "tasks/hk_fdir_mng/tc_executor.h"

Result PUSHKFDIRTCExcutor__exec_tc(PUSHKFDIRTCExcutor * const self,
                                   __termina_box_t tc_descriptor) {
    
    Result res;
    res.__variant = Result__Ok;

    uint8_t tc_type = get_type((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

    uint8_t subtype = get_subtype((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

    if (tc_type == 3) {
        
        if (subtype == 5) {
            
            (self->pus_service_3.exec3_5TC)(self->pus_service_3.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else if (subtype == 6) {
            
            (self->pus_service_3.exec3_6TC)(self->pus_service_3.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else if (subtype == 31) {
            
            (self->pus_service_3.exec3_31TC)(self->pus_service_3.__that,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             &res);

        } else {
            

        }

    } else if (tc_type == 5) {
        
        if (subtype == 5) {
            
            (self->pus_service_5.exec5_5TC)(self->pus_service_5.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else if (subtype == 6) {
            
            (self->pus_service_5.exec5_6TC)(self->pus_service_5.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else {
            

        }

    } else if (tc_type == 12) {
        
        if (subtype == 1) {
            
            (self->pus_service_12.exec12_1TC)(self->pus_service_12.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 2) {
            
            (self->pus_service_12.exec12_2TC)(self->pus_service_12.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 5) {
            
            (self->pus_service_12.exec12_5TC)(self->pus_service_12.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else {
            

        }

    } else if (tc_type == 19) {
        
        if (subtype == 1) {
            
            (self->pus_service_19.exec19_1TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 2) {
            
            (self->pus_service_19.exec19_2TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 4) {
            
            (self->pus_service_19.exec19_4TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 5) {
            
            (self->pus_service_19.exec19_5TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else {
            

        }

    } else {
        

    }

    __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    return res;

}
