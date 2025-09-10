
#include "tasks/bkgtcexec.h"

__status_int32_t PUSBKGTCExecutor__exec_tc(const __termina_event_t * const __ev, void * const __this, __termina_box_t tc_handler) {
    
    #line 48 "src/tasks/bkgtcexec.fin"
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)__this;

    #line 50 "src/tasks/bkgtcexec.fin"
    __status_int32_t res;
    #line 50 "src/tasks/bkgtcexec.fin"
    res.__variant = Success;

    #line 52 "src/tasks/bkgtcexec.fin"
    uint8_t tc_type = get_type((*(TCHandler *)tc_handler.data).tc_descriptor.tc_bytes);

    #line 54 "src/tasks/bkgtcexec.fin"
    if (tc_type == 20U) {
        
        #line 56 "src/tasks/bkgtcexec.fin"
        self->pus_service_20.exec_tc(__ev, self->pus_service_20.__that, (TCHandler *)tc_handler.data, &res);

    } else
    #line 58 "src/tasks/bkgtcexec.fin"
    if (tc_type == 6U) {
        
        #line 60 "src/tasks/bkgtcexec.fin"
        self->pus_service_6.exec_tc(__ev, self->pus_service_6.__that, (TCHandler *)tc_handler.data, &res);

    } else
    {
        
        #line 64 "src/tasks/bkgtcexec.fin"
        self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, (*(TCHandler *)tc_handler.data).packet_header.packet_id, (*(TCHandler *)tc_handler.data).packet_header.packet_seq_ctrl, &res);

    }

    #line 71 "src/tasks/bkgtcexec.fin"
    self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that, tc_handler);

    #line 73 "src/tasks/bkgtcexec.fin"
    return res;

}

void __PUSBKGTCExecutor__termina_task(void * arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;

    int32_t status = 0L;

    __termina_event_t event;

    __status_int32_t result;
    result.__variant = Success;

    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &event, &status);

        if (status != 0L) {
            break;
        }

        switch (event.port_id) {
            
            case __PUSBKGTCExecutor__bkg_message_queue_input:

                __termina_msg_queue__recv(self->bkg_message_queue_input, (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->bkg_message_queue_input, status);
                }

                result = PUSBKGTCExecutor__exec_tc(&event, self, exec_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source, __PUSBKGTCExecutor__bkg_message_queue_input, result.Failure.__0);

                }

                break;

            default:

                __termina_exec__reboot();

                break;

        }

    }

    return;

}
