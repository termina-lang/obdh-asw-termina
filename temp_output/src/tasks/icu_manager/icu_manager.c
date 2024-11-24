
#include "tasks/icu_manager/icu_manager.h"

Result ICUManager__PUS_prio_exec_tc(ICUManager * const self) {
    
    Result ret;
    ret.__variant = Result__Ok;

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        uint8_t tc_type = get_type(self->current_tc.tc_bytes);

        if (tc_type == 17) {
            
            (self->pus_service_3.exec3_6TC)(self->pus_service_3.__that,
                                            &self->current_tc,
                                            (TMDescriptorT *)descriptor.data,
                                            tm_count);

        } else {
            
            ret.__variant = Result__Error;

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, &ret);

    } else {
        
        ret.__variant = Result__Error;

    }

    return ret;

}

Result ICUManager__mng_tc_acceptation(ICUManager * const self) {
    
    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    Result ret;
    ret.__variant = Result__Ok;

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_1((TMDescriptorT *)descriptor.data, tm_count,
                     &self->current_tc);

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, &ret);

    } else {
        
        ret.__variant = Result__Error;

    }

    return ret;

}

Result ICUManager__mng_tc_rejection(ICUManager * const self) {
    
    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    Result ret;
    ret.__variant = Result__Ok;

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_1_2(&self->current_tc_status, (TMDescriptorT *)descriptor.data,
                     tm_count, &self->current_tc);

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, &ret);

    } else {
        
        ret.__variant = Result__Error;

    }

    return ret;

}

Result ICUManager__process_action_tc(ICUManager * const self,
                                     __termina_box_t tc_descriptor) {
    
    Result ret;
    ret.__variant = Result__Ok;

    self->current_tc = *(TCDescriptorT *)tc_descriptor.data;

    TCExecutionCtrl execution_status = handle_tc((TCDescriptorT *)tc_descriptor.data);

    if (execution_status.__variant == TCExecutionCtrl__Undefined) {
        
        ret.__variant = Result__Error;

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
        
        ret = ICUManager__PUS_prio_exec_tc(self);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        ret = ICUManager__PUS_prio_exec_tc(self);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
        
        __termina_msg_queue__send(self->hkfdir_message_queue_output,
                                  (void *)&tc_descriptor);

    } else {
        
        __termina_msg_queue__send(self->bkg_message_queue_output,
                                  (void *)&tc_descriptor);

    }

    return ret;

}

Result ICUManager__process_tc(ICUManager * const self,
                              __termina_box_t tc_descriptor) {
    
    Result ret;
    ret.__variant = Result__Ok;

    self->current_tc = *(TCDescriptorT *)tc_descriptor.data;

    self->current_tc_status = try_tc_acceptation((TCDescriptorT *)tc_descriptor.data);

    if (self->current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Undefined) {
        
        ret.__variant = Result__Error;

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (self->current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        ret = ICUManager__mng_tc_rejection(self);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else {
        
        ret = ICUManager__mng_tc_acceptation(self);

        if (self->current_tc_status.execution_status.__variant == TCExecutionCtrl__Undefined) {
            
            ret.__variant = Result__Error;

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        } else if (self->current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
            
            ret = ICUManager__PUS_prio_exec_tc(self);

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        } else if (self->current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            ret = ICUManager__PUS_prio_exec_tc(self);

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        } else if (self->current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            __termina_msg_queue__send(self->hkfdir_message_queue_output,
                                      (void *)&tc_descriptor);

        } else {
            
            __termina_msg_queue__send(self->bkg_message_queue_output,
                                      (void *)&tc_descriptor);

        }

    }

    return ret;

}
