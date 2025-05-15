
#include "tasks/bkgtcexec.h"

__status_int32_t PUSBKGTCExecutor__exec_tc(void * const __this,
                                           __termina_box_t tc_handler) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)__this;

    __status_int32_t res;
    res.__variant = Success;

    uint8_t tc_type = get_type((*(TCHandlerT *)tc_handler.data).tc_descriptor.tc_bytes);

    if (tc_type == 20U) {
        
        self->pus_service_20.exec_tc(self->pus_service_20.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else {
        
        res.__variant = Failure;
        res.Failure.__0 = ACCEPTANCE_ERROR;

    }

    self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that, tc_handler);

    return res;

}

void __PUSBKGTCExecutor__termina_task(void * arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;

    int32_t status = 0L;

    uint32_t next_msg = 0U;

    __status_int32_t result;
    result.__variant = Success;

    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status != 0L) {
            break;
        }

        switch (next_msg) {
            
            case __PUSBKGTCExecutor__bkg_message_queue_input:

                __termina_msg_queue__recv(self->bkg_message_queue_input,
                                          (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->bkg_message_queue_input,
                                                           status);
                }

                result = PUSBKGTCExecutor__exec_tc(self, exec_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __PUSBKGTCExecutor__bkg_message_queue_input,
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
