
#include "tasks/icu_manager/icu_manager.h"

Result ICUManager__process_action_tc(void * const __this,
                                     __termina_box_t tc_handler) {
    
    ICUManager * self = (ICUManager *)__this;

    Result ret;
    ret.__variant = Result__Ok;

    TCExecutionCtrl execution_status = handle_tc(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
        
        (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                             (TCHandlerT *)tc_handler.data,
                                             &ret);

        (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                       tc_handler);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
        
        __termina_out_port__send(self->hkfdir_message_queue_output,
                                 (void *)&tc_handler);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
        
        __termina_out_port__send(self->bkg_message_queue_output,
                                 (void *)&tc_handler);

    } else if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                             (TCHandlerT *)tc_handler.data,
                                             &ret);

        (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                       tc_handler);

    } else {
        
        ret.__variant = Result__Error;

        (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                       tc_handler);

    }

    return ret;

}

Result ICUManager__process_tc(void * const __this, __termina_box_t tc_handler) {
    
    ICUManager * self = (ICUManager *)__this;

    Result ret;
    ret.__variant = Result__Ok;

    TCStatus current_tc_status = try_tc_acceptation(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
        
        (self->tc_executor.mng_tc_acceptation)(self->tc_executor.__that,
                                               (TCHandlerT *)tc_handler.data,
                                               &ret);

        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlReboot) {
            
            (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                                 (TCHandlerT *)tc_handler.data,
                                                 &ret);

            (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                           tc_handler);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            __termina_out_port__send(self->hkfdir_message_queue_output,
                                     (void *)&tc_handler);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
            
            __termina_out_port__send(self->bkg_message_queue_output,
                                     (void *)&tc_handler);

        } else if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            (self->tc_executor.PUS_prio_exec_tc)(self->tc_executor.__that,
                                                 (TCHandlerT *)tc_handler.data,
                                                 &ret);

            (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                           tc_handler);

        } else {
            
            ret.__variant = Result__Error;

            (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                           tc_handler);

        }

    } else if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        (self->tc_executor.mng_tc_rejection)(self->tc_executor.__that,
                                             (TCHandlerT *)tc_handler.data,
                                             &ret);

        (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                       tc_handler);

    } else {
        
        ret.__variant = Result__Error;

        (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that,
                                       tc_handler);

    }

    return ret;

}

void __ICUManager__termina_task(void * arg) {
    
    ICUManager * self = (ICUManager *)arg;

    Status status;
    status.__variant = Status__Success;

    uint32_t next_msg = 0U;

    Result result;
    result.__variant = Result__Ok;

    __termina_box_t process_tc__msg_data;
    __termina_box_t process_action_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status.__variant != Status__Success) {
            break;
        }

        switch (next_msg) {
            
            case __ICUManager__tc_message_queue_input:

                __termina_msg_queue__recv(self->tc_message_queue_input,
                                          (void *)&process_tc__msg_data,
                                          &status);

                if (status.__variant != Status__Success) {
                    __termina_exec__shutdown();
                }

                result = ICUManager__process_tc(self, process_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    __termina_exec__shutdown();
                }

                break;

            case __ICUManager__action_tc_message_queue_input:

                __termina_msg_queue__recv(self->action_tc_message_queue_input,
                                          (void *)&process_action_tc__msg_data,
                                          &status);

                if (status.__variant != Status__Success) {
                    __termina_exec__shutdown();
                }

                result = ICUManager__process_action_tc(self,
                                                       process_action_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    __termina_exec__shutdown();
                }

                break;

            default:

                __termina_exec__shutdown();

                break;

        }

    }

    __termina_exec__shutdown();

    return;

}
