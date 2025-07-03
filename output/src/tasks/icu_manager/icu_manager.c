
#include "tasks/icu_manager/icu_manager.h"

__status_int32_t ICUManager__process_action_tc(const __termina_event_t * const __ev,
                                               void * const __this,
                                               __termina_box_t tc_handler) {
    
    #line 124 "src/tasks/icu_manager/icu_manager.fin"
    ICUManager * self = (ICUManager *)__this;

    #line 126 "src/tasks/icu_manager/icu_manager.fin"
    __status_int32_t ret;
    #line 126 "src/tasks/icu_manager/icu_manager.fin"
    ret.__variant = Success;

    #line 127 "src/tasks/icu_manager/icu_manager.fin"
    _Bool reebot_flag = 0;

    #line 129 "src/tasks/icu_manager/icu_manager.fin"
    TCExecutionCtrl execution_status = handle_tc(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    #line 133 "src/tasks/icu_manager/icu_manager.fin"
    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
        
        #line 135 "src/tasks/icu_manager/icu_manager.fin"
        __termina_out_port__send(__ev, self->hkfdir_message_queue_output,
                                 (void *)&tc_handler);

    } else
    #line 137 "src/tasks/icu_manager/icu_manager.fin"
    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
        
        #line 139 "src/tasks/icu_manager/icu_manager.fin"
        __termina_out_port__send(__ev, self->bkg_message_queue_output,
                                 (void *)&tc_handler);

    } else
    #line 142 "src/tasks/icu_manager/icu_manager.fin"
    if (execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
        
        #line 144 "src/tasks/icu_manager/icu_manager.fin"
        self->tc_executor.PUS_prio_exec_tc(__ev, self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret,
                                           &reebot_flag);

        #line 145 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                     tc_handler);

        #line 147 "src/tasks/icu_manager/icu_manager.fin"
        if (reebot_flag) {
            
            #line 148 "src/tasks/icu_manager/icu_manager.fin"
            reebot_flag = 0;

            __termina_exec__reboot();

        }

    } else
    {
        
        #line 154 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                     tc_handler);

    }

    #line 160 "src/tasks/icu_manager/icu_manager.fin"
    return ret;

}

__status_int32_t ICUManager__process_tc(const __termina_event_t * const __ev,
                                        void * const __this,
                                        __termina_box_t tc_handler) {
    
    #line 52 "src/tasks/icu_manager/icu_manager.fin"
    ICUManager * self = (ICUManager *)__this;

    #line 54 "src/tasks/icu_manager/icu_manager.fin"
    __status_int32_t ret;
    #line 54 "src/tasks/icu_manager/icu_manager.fin"
    ret.__variant = Success;

    #line 55 "src/tasks/icu_manager/icu_manager.fin"
    _Bool reebot_flag = 0;

    #line 57 "src/tasks/icu_manager/icu_manager.fin"
    TCStatus current_tc_status = try_tc_acceptation(&(*(TCHandlerT *)tc_handler.data).tc_descriptor);

    #line 61 "src/tasks/icu_manager/icu_manager.fin"
    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Accepted) {
        
        #line 63 "src/tasks/icu_manager/icu_manager.fin"
        self->tc_executor.mng_tc_acceptation(__ev, self->tc_executor.__that,
                                             (TCHandlerT *)tc_handler.data,
                                             &ret);

        #line 67 "src/tasks/icu_manager/icu_manager.fin"
        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlHK_FDIRTC) {
            
            #line 69 "src/tasks/icu_manager/icu_manager.fin"
            __termina_out_port__send(__ev, self->hkfdir_message_queue_output,
                                     (void *)&tc_handler);

        } else
        #line 71 "src/tasks/icu_manager/icu_manager.fin"
        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlBKGTC) {
            
            #line 73 "src/tasks/icu_manager/icu_manager.fin"
            __termina_out_port__send(__ev, self->bkg_message_queue_output,
                                     (void *)&tc_handler);

        } else
        #line 76 "src/tasks/icu_manager/icu_manager.fin"
        if (current_tc_status.execution_status.__variant == TCExecutionCtrl__ExecCtrlPrioTC) {
            
            #line 78 "src/tasks/icu_manager/icu_manager.fin"
            self->tc_executor.PUS_prio_exec_tc(__ev, self->tc_executor.__that,
                                               (TCHandlerT *)tc_handler.data,
                                               &ret, &reebot_flag);

            #line 80 "src/tasks/icu_manager/icu_manager.fin"
            self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                         tc_handler);

            #line 82 "src/tasks/icu_manager/icu_manager.fin"
            if (reebot_flag) {
                
                #line 83 "src/tasks/icu_manager/icu_manager.fin"
                reebot_flag = 0;

                __termina_exec__reboot();

            }

        } else
        {
            
            #line 90 "src/tasks/icu_manager/icu_manager.fin"
            self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                         tc_handler);

        }

    } else
    #line 95 "src/tasks/icu_manager/icu_manager.fin"
    if (current_tc_status.acceptation_status.__variant == TCAcceptationStatus__Rejected) {
        
        #line 97 "src/tasks/icu_manager/icu_manager.fin"
        self->tc_executor.mng_tc_rejection(__ev, self->tc_executor.__that,
                                           (TCHandlerT *)tc_handler.data, &ret);

        #line 98 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                     tc_handler);

    } else
    {
        
        #line 102 "src/tasks/icu_manager/icu_manager.fin"
        self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                     tc_handler);

    }

    #line 107 "src/tasks/icu_manager/icu_manager.fin"
    return ret;

}

void __ICUManager__termina_task(void * arg) {
    
    ICUManager * self = (ICUManager *)arg;

    int32_t status = 0L;

    __termina_event_t event;

    __status_int32_t result;
    result.__variant = Success;

    __termina_box_t process_tc__msg_data;
    __termina_box_t process_action_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &event, &status);

        if (status != 0L) {
            break;
        }

        switch (event.port_id) {
            
            case __ICUManager__tc_message_queue_input:

                __termina_msg_queue__recv(self->tc_message_queue_input,
                                          (void *)&process_tc__msg_data,
                                          &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->tc_message_queue_input,
                                                           status);
                }

                result = ICUManager__process_tc(&event, self,
                                                process_tc__msg_data);

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

                result = ICUManager__process_action_tc(&event, self,
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
