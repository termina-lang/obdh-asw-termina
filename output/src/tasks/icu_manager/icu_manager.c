
#include "tasks/icu_manager/icu_manager.h"

__status_int32_t ICUManager__process_action_tc(void * const __this,
                                               __termina_box_t tc_handler) {
    
    ICUManager * self = (ICUManager *)__this;

    #line 78 "src/tasks/icu_manager/icu_manager.fin"
    __status_int32_t ret;
    #line 78 "src/tasks/icu_manager/icu_manager.fin"
    ret.__variant = Success;

    #line 79 "src/tasks/icu_manager/icu_manager.fin"
    _Bool reebot_flag = 0;

    #line 81 "src/tasks/icu_manager/icu_manager.fin"
    TCExecutionCtrl execution_status = handle_tc(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    #line 85 "src/tasks/icu_manager/icu_manager.fin"
    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
        
        #line 87 "src/tasks/icu_manager/icu_manager.fin"
        __termina_out_port__send(self->hkfdir_message_queue_output,
                                 (void *)&tc_handler);

    } else
    #line 89 "src/tasks/icu_manager/icu_manager.fin"
    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
        
        #line 91 "src/tasks/icu_manager/icu_manager.fin"
        __termina_out_port__send(self->bkg_message_queue_output,
                                 (void *)&tc_handler);

    } else
    #line 94 "src/tasks/icu_manager/icu_manager.fin"
    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        #line 97 "src/tasks/icu_manager/icu_manager.fin"
        self->tc_executor.PUS_prio_exec_tc(self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret,
                                           &reebot_flag);

        #line 98 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

        #line 100 "src/tasks/icu_manager/icu_manager.fin"
        if (reebot_flag) {
            
            #line 101 "src/tasks/icu_manager/icu_manager.fin"
            reebot_flag = 0;

            __termina_exec__reboot();

        }

    } else
    {
        
        #line 107 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    }

    #line 113 "src/tasks/icu_manager/icu_manager.fin"
    return ret;

}

__status_int32_t ICUManager__process_tc(void * const __this,
                                        __termina_box_t tc_handler) {
    
    ICUManager * self = (ICUManager *)__this;

    #line 15 "src/tasks/icu_manager/icu_manager.fin"
    __status_int32_t ret;
    #line 15 "src/tasks/icu_manager/icu_manager.fin"
    ret.__variant = Success;

    #line 16 "src/tasks/icu_manager/icu_manager.fin"
    _Bool reebot_flag = 0;

    #line 18 "src/tasks/icu_manager/icu_manager.fin"
    TCStatus current_tc_status = try_tc_acceptation(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    #line 22 "src/tasks/icu_manager/icu_manager.fin"
    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
        
        #line 24 "src/tasks/icu_manager/icu_manager.fin"
        self->tc_executor.mng_tc_acceptation(self->tc_executor.__that,
                                             (TCHandlerT *)tc_handler.data,
                                             &ret);

        #line 28 "src/tasks/icu_manager/icu_manager.fin"
        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            #line 30 "src/tasks/icu_manager/icu_manager.fin"
            __termina_out_port__send(self->hkfdir_message_queue_output,
                                     (void *)&tc_handler);

        } else
        #line 32 "src/tasks/icu_manager/icu_manager.fin"
        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
            
            #line 34 "src/tasks/icu_manager/icu_manager.fin"
            __termina_out_port__send(self->bkg_message_queue_output,
                                     (void *)&tc_handler);

        } else
        #line 37 "src/tasks/icu_manager/icu_manager.fin"
        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            #line 40 "src/tasks/icu_manager/icu_manager.fin"
            self->tc_executor.PUS_prio_exec_tc(self->tc_executor.__that,
                                               (TCHandlerT *)tc_handler.data,
                                               &ret, &reebot_flag);

            #line 42 "src/tasks/icu_manager/icu_manager.fin"
            self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                         tc_handler);

            #line 44 "src/tasks/icu_manager/icu_manager.fin"
            if (reebot_flag) {
                
                #line 45 "src/tasks/icu_manager/icu_manager.fin"
                reebot_flag = 0;

                __termina_exec__reboot();

            }

        } else
        {
            
            #line 53 "src/tasks/icu_manager/icu_manager.fin"
            self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                         tc_handler);

        }

    } else
    #line 58 "src/tasks/icu_manager/icu_manager.fin"
    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        #line 60 "src/tasks/icu_manager/icu_manager.fin"
        self->tc_executor.mng_tc_rejection(self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret);

        #line 61 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    } else
    {
        
        #line 65 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that,
                                     tc_handler);

    }

    #line 70 "src/tasks/icu_manager/icu_manager.fin"
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
