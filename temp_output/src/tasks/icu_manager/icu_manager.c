
#include "tasks/icu_manager/icu_manager.h"

Result ICUManager__process_action_tc(ICUManager * const self,
                                     __termina_box_t tc_descriptor) {
    
    Result ret;
    ret.__variant = Result__Ok;

    TCExecutionCtrl execution_status = handle_tc((TCDescriptorT *)tc_descriptor.data);

    if (execution_status.__variant == TCExecutionCtrl__Undefined) {
        
        ret.__variant = Result__Error;

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
        
        (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             &ret);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             &ret);

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

    TCStatus current_tc_status = try_tc_acceptation((TCDescriptorT *)tc_descriptor.data);

    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Undefined) {
        
        ret.__variant = Result__Error;

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        (self->tc_executor.mng_tc_rejection)(self->tc_executor.__that,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             &ret);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else {
        
        (self->tc_executor.mng_tc_acceptation)(self->tc_executor.__that,
                                               (TCDescriptorT *)tc_descriptor.data,
                                               &ret);

        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__Undefined) {
            
            ret.__variant = Result__Error;

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
            
            (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                                 (TCDescriptorT *)tc_descriptor.data,
                                                 &ret);

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                                 (TCDescriptorT *)tc_descriptor.data,
                                                 &ret);

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            __termina_msg_queue__send(self->hkfdir_message_queue_output,
                                      (void *)&tc_descriptor);

        } else {
            
            __termina_msg_queue__send(self->bkg_message_queue_output,
                                      (void *)&tc_descriptor);

        }

    }

    return ret;

}
