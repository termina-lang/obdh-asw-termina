
#include "tasks/icu_manager.h"

Result ICUManager__process_tc(ICUManager * const self,
                              __termina_dyn_t tc_descriptor) {
    
    Result ret;
    ret.__variant = Result__Ok;

    try_tc_acceptation(&self->tc_status, (TCDescriptorT *)tc_descriptor.data);

    if (self->tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        __option_dyn_t tm_descriptor;
        tm_descriptor.__variant = None;

        __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

        if (tm_descriptor.__variant == None) {
            

        } else {
            
            __option_dyn_params_t __Some = tm_descriptor.Some;

            uint16_t tm_count = 0;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            build_tm_1_2(&self->tc_status, (TMDescriptorT *)__Some.__0.data,
                         tm_count, (TCDescriptorT *)tc_descriptor.data);

            __termina_msg_queue__send(self->tm_message_queue_output,
                                      (void *)&__Some.__0);

        }

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    } else {
        
        __option_dyn_t tm_descriptor;
        tm_descriptor.__variant = None;

        __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

        if (tm_descriptor.__variant == None) {
            

        } else {
            
            __option_dyn_params_t __Some = tm_descriptor.Some;

            uint16_t tm_count = 0;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            build_tm_1_1((TMDescriptorT *)__Some.__0.data, tm_count,
                         (TCDescriptorT *)tc_descriptor.data);

            __termina_msg_queue__send(self->tm_message_queue_output,
                                      (void *)&__Some.__0);

        }

        if (self->tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
            
            __option_dyn_t tm_descriptor2;
            tm_descriptor2.__variant = None;

            __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor2);

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

            if (tm_descriptor2.__variant == None) {
                

            } else {
                
                __option_dyn_params_t __Some = tm_descriptor2.Some;

                uint16_t tm_count = 0;

                (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                     &tm_count);

                ICUManager__PUS_prio_exec_tc(self,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             (TMDescriptorT *)__Some.__0.data,
                                             tm_count);

                __termina_msg_queue__send(self->tm_message_queue_output,
                                          (void *)&__Some.__0);

            }

        } else if (self->tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            __option_dyn_t tm_descriptor3;
            tm_descriptor3.__variant = None;

            __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor3);

            __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

            if (tm_descriptor3.__variant == None) {
                

            } else {
                
                __option_dyn_params_t __Some = tm_descriptor3.Some;

                uint16_t tm_count = 0;

                (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                     &tm_count);

                ICUManager__PUS_prio_exec_tc(self,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             (TMDescriptorT *)__Some.__0.data,
                                             tm_count);

                __termina_msg_queue__send(self->tm_message_queue_output,
                                          (void *)&__Some.__0);

            }

        } else if (self->tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            __termina_msg_queue__send(self->hkfdir_message_queue_output,
                                      (void *)&tc_descriptor);

        } else {
            
            __termina_msg_queue__send(self->bkg_message_queue_output,
                                      (void *)&tc_descriptor);

        }

    }

    return ret;

}

Result ICUManager__process_action_tc(ICUManager * const self,
                                     __termina_dyn_t tc_descriptor) {
    
    Result ret;
    ret.__variant = Result__Ok;

    TCExecutionCtrl execution_status = handle_tc((TCDescriptorT *)tc_descriptor.data);

    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
        
        __option_dyn_t tm_descriptor2;
        tm_descriptor2.__variant = None;

        __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor2);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        if (tm_descriptor2.__variant == None) {
            

        } else {
            
            __option_dyn_params_t __Some = tm_descriptor2.Some;

            uint16_t tm_count = 0;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            ICUManager__PUS_prio_exec_tc(self,
                                         (TCDescriptorT *)tc_descriptor.data,
                                         (TMDescriptorT *)__Some.__0.data,
                                         tm_count);

            __termina_msg_queue__send(self->tm_message_queue_output,
                                      (void *)&__Some.__0);

        }

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        __option_dyn_t tm_descriptor3;
        tm_descriptor3.__variant = None;

        __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor3);

        __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

        if (tm_descriptor3.__variant == None) {
            

        } else {
            
            __option_dyn_params_t __Some = tm_descriptor3.Some;

            uint16_t tm_count = 0;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            ICUManager__PUS_prio_exec_tc(self,
                                         (TCDescriptorT *)tc_descriptor.data,
                                         (TMDescriptorT *)__Some.__0.data,
                                         tm_count);

            __termina_msg_queue__send(self->tm_message_queue_output,
                                      (void *)&__Some.__0);

        }

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
        
        __termina_msg_queue__send(self->hkfdir_message_queue_output,
                                  (void *)&tc_descriptor);

    } else {
        
        __termina_msg_queue__send(self->bkg_message_queue_output,
                                  (void *)&tc_descriptor);

    }

    return ret;

}

void ICUManager__PUS_prio_exec_tc(const ICUManager * const self,
                                  const TCDescriptorT * tc_descriptor,
                                  TMDescriptorT * tm_descriptor,
                                  uint16_t tm_seq_counter) {
    
    uint8_t tc_type = get_type(tc_descriptor->tc_bytes);

    if (tc_type == 17) {
        
        PUS_service_17_execTC(tc_descriptor, tm_descriptor, tm_seq_counter);

    } else {
        

    }

    return;

}
