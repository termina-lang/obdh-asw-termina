
#include "tasks/icu_manager/mng_tc_executor.h"

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         const TCDescriptorT * const prio_tc,
                                         Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __termina_resource__lock(&self->__resource);

    uint8_t tc_type = get_type(prio_tc->tc_bytes);

    if (tc_type == 17U) {
        
        (self->pus_service_17.exec17_1TC)(self->pus_service_17.__that, prio_tc,
                                          ret);

    } else {
        
        (*ret).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCDescriptorT * const tc_descriptor,
                                           Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_1((TMDescriptorT *)descriptor.data, tm_count, tc_descriptor);

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, ret);

    } else {
        
        (*ret).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void ManagerTCExecutor__mng_tc_rejection(void * const __this,
                                         const TCDescriptorT * const tc_descriptor,
                                         Result * const ret) {
    
    ManagerTCExecutor * self = (ManagerTCExecutor *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    TCStatus tc_status = try_tc_acceptation(tc_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_2(&tc_status, (TMDescriptorT *)descriptor.data, tm_count,
                     tc_descriptor);

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, ret);

    } else {
        
        (*ret).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
