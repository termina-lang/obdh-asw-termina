
#include "tasks/bkgtcexec.h"

Status__i32 CBKGTCExecutorTask__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, termina__box_t tc_handler) {
    
    #line 48 "src/tasks/bkgtcexec.fin"
    CBKGTCExecutorTask * self = (CBKGTCExecutorTask *)termina__this;

    #line 50 "src/tasks/bkgtcexec.fin"
    Status__i32 res = { ._variant = Status__Success };

    #line 52 "src/tasks/bkgtcexec.fin"
    uint8_t tc_type = get_type((*(TCHandler *)tc_handler.data).tc_descriptor.tc_bytes);

    #line 54 "src/tasks/bkgtcexec.fin"
    if (tc_type == 20U) {
        
        #line 56 "src/tasks/bkgtcexec.fin"
        self->pus_service_20.exec_tc(termina__ev, self->pus_service_20._that, (TCHandler *)tc_handler.data, &res);

    } else
    #line 58 "src/tasks/bkgtcexec.fin"
    if (tc_type == 6U) {
        
        #line 60 "src/tasks/bkgtcexec.fin"
        self->pus_service_6.exec_tc(termina__ev, self->pus_service_6._that, (TCHandler *)tc_handler.data, &res);

    } else
    {
        
        #line 64 "src/tasks/bkgtcexec.fin"
        self->pus_service_1.send_tm_1_4_error_in_acceptance(termina__ev, self->pus_service_1._that, (*(TCHandler *)tc_handler.data).packet_header.packet_id, (*(TCHandler *)tc_handler.data).packet_header.packet_seq_ctrl, &res);

    }

    #line 71 "src/tasks/bkgtcexec.fin"
    self->tc_handler_pool.free(termina__ev, self->tc_handler_pool._that, tc_handler);

    #line 73 "src/tasks/bkgtcexec.fin"
    return res;

}

void termina__task_entry__CBKGTCExecutorTask(void * arg) {
    
    CBKGTCExecutorTask * self = (CBKGTCExecutorTask *)arg;

    int32_t status = 0L;

    termina__event_t event;

    Status__i32 result;

    termina__box_t exec_tc__msg_data;

    for (;;) {
        
        termina__msg_queue__recv(self->_task_msg_queue_id, &event, &status);

        if (status != 0L) {
            break;
        }

        switch (event.port_id) {
            
            case CBKGTCExecutorTask__bkg_message_queue_input:

                termina__msg_queue__recv(self->bkg_message_queue_input, (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    termina__except__msg_queue_recv_error(self->bkg_message_queue_input, status);
                }

                result = CBKGTCExecutorTask__exec_tc(&event, self, exec_tc__msg_data);

                if (result._variant != Status__Success) {
                    
                    ExceptSource source;
                    source._variant = ExceptSource__Task;
                    source.Task._0 = self->_task_id;

                    termina__except__action_failure(source, CBKGTCExecutorTask__bkg_message_queue_input, result.Failure._0);

                }

                break;

            default:

                termina__exec__reboot();

                break;

        }

    }

    return;

}
