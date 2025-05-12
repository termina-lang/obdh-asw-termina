
#include "tasks/icu_manager/icu_manager.h"

__status_int32_t ICUManager__process_action_tc(void * const __this,
                                               __termina_box_t tc_handler) {
    
    ICUManager * self = (ICUManager *)__this;

    __status_int32_t ret;
    ret.__variant = Success;

    TCExecutionCtrl execution_status = handle_tc(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
        
        self->tc_executor.PUS_prio_exec_tc(self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret);

        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
        
        __termina_out_port__send(self->hkfdir_message_queue_output,
                                 (void *)&tc_handler);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
        
        __termina_out_port__send(self->bkg_message_queue_output,
                                 (void *)&tc_handler);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        self->tc_executor.PUS_prio_exec_tc(self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret);

        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    } else {
        
        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    }

    return ret;

}

__status_int32_t ICUManager__process_tc(void * const __this,
                                        __termina_box_t tc_handler) {
    
    ICUManager * self = (ICUManager *)__this;

    __status_int32_t ret;
    ret.__variant = Success;

    TCStatus current_tc_status = try_tc_acceptation(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
        
        self->tc_executor.mng_tc_acceptation(self->tc_executor.__that,
                                             (TCHandlerT *)tc_handler.data,
                                             &ret);

        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
            
            self->tc_executor.PUS_prio_exec_tc(self->tc_executor.__that,
                                               (TCHandlerT *)tc_handler.data,
                                               &ret);

            self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                         tc_handler);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            __termina_out_port__send(self->hkfdir_message_queue_output,
                                     (void *)&tc_handler);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
            
            __termina_out_port__send(self->bkg_message_queue_output,
                                     (void *)&tc_handler);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            self->tc_executor.PUS_prio_exec_tc(self->tc_executor.__that,
                                               (TCHandlerT *)tc_handler.data,
                                               &ret);

            self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                         tc_handler);

        } else {
            
            self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                         tc_handler);

        }

    } else if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        self->tc_executor.mng_tc_rejection(self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret);

        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    } else {
        
        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    }

    return ret;

}

void __ICUManager__termina_task(void * arg) {
    
    ICUManager * self = (ICUManager *)arg;

    int32_t status = 0L;

    uint32_t next_msg = 0U;

    __status_int32_t result;
    result.__variant = Success;

    __termina_box_t process_tc__msg_data;
    __termina_box_t process_action_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status != 0L) {
            break;
        }

        switch (next_msg) {
            
            case __ICUManager__tc_message_queue_input:

                __termina_msg_queue__recv(self->tc_message_queue_input,
                                          (void *)&process_tc__msg_data,
                                          &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->tc_message_queue_input,
                                                           status);
                }

                result = ICUManager__process_tc(self, process_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __ICUManager__tc_message_queue_input,
                                                     result.Failure.__0);

                }

                break;

            case __ICUManager__action_tc_message_queue_input:

                __termina_msg_queue__recv(self->action_tc_message_queue_input,
                                          (void *)&process_action_tc__msg_data,
                                          &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->action_tc_message_queue_input,
                                                           status);
                }

                result = ICUManager__process_action_tc(self,
                                                       process_action_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __ICUManager__action_tc_message_queue_input,
                                                     result.Failure.__0);

                }

                break;

            default:

                __termina_exec__reboot();

                break;

        }

    }

    return;

}
