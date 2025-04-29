
#include "tasks/bkgtcexec.h"

Result PUSBKGTCExecutor__exec_tc(void * const __this,
                                 __termina_box_t tc_handler) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)__this;

    Result res;
    res.__variant = Result__Ok;

    uint8_t tc_type = get_type((*(TCHandlerT *)tc_handler.data).tc_descriptor.tc_bytes);

    if (tc_type == 20U) {
        
        (self->pus_service_20.exec_tc)(self->pus_service_20.__that,
                                       (TCHandlerT *)tc_handler.data, &res);

    } else {
        
        res.__variant = Result__Error;

    }

    (self->a_tc_handler_pool.free)(self->a_tc_handler_pool.__that, tc_handler);

    return res;

}

void __PUSBKGTCExecutor__termina_task(void * arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;

    Status status;
    status.__variant = Status__Success;

    uint32_t next_msg = 0U;

    Result result;
    result.__variant = Result__Ok;

    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status.__variant != Status__Success) {
            break;
        }

        switch (next_msg) {
            
            case __PUSBKGTCExecutor__bkg_message_queue_input:

                __termina_msg_queue__recv(self->bkg_message_queue_input,
                                          (void *)&exec_tc__msg_data, &status);

                if (status.__variant != Status__Success) {
                    __termina_exec__shutdown();
                }

                result = PUSBKGTCExecutor__exec_tc(self, exec_tc__msg_data);

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
