
#include "tasks/tc_rx.h"

__status_int32_t TCRXBottomHalfTask__get_tc(const __termina_event_t * const __ev, void * const __this, size_t size) {
    
    #line 15 "src/tasks/tc_rx.fin"
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)__this;

    #line 17 "src/tasks/tc_rx.fin"
    __status_int32_t ret;
    #line 17 "src/tasks/tc_rx.fin"
    ret.__variant = Success;

    #line 19 "src/tasks/tc_rx.fin"
    __option_box_t tc_handler;
    #line 19 "src/tasks/tc_rx.fin"
    tc_handler.__variant = None;

    #line 20 "src/tasks/tc_rx.fin"
    self->a_tc_handler_pool.alloc(__ev, self->a_tc_handler_pool.__that, &tc_handler);

    #line 24 "src/tasks/tc_rx.fin"
    if (tc_handler.__variant == Some) {
        
        #line 24 "src/tasks/tc_rx.fin"
        __termina_box_t tc_handler_b = tc_handler.Some.__0;

        #line 26 "src/tasks/tc_rx.fin"
        for (size_t i = 0U; i < 256U && (i < size && ret.__variant == Success); i = i + 1U) {
            
            #line 28 "src/tasks/tc_rx.fin"
            __option_uint8_t obyte;
            #line 28 "src/tasks/tc_rx.fin"
            obyte.__variant = None;

            #line 29 "src/tasks/tc_rx.fin"
            self->tc_channel.dequeue(__ev, self->tc_channel.__that, &obyte);

            #line 33 "src/tasks/tc_rx.fin"
            if (obyte.__variant == Some) {
                
                #line 33 "src/tasks/tc_rx.fin"
                uint8_t byte = obyte.Some.__0;

                #line 34 "src/tasks/tc_rx.fin"
                (*(TCHandler *)tc_handler_b.data).tc_descriptor.tc_bytes[__termina_array__index(256U, i)] = byte;

            } else
            {
                
                #line 37 "src/tasks/tc_rx.fin"
                ret.__variant = Failure;
                #line 37 "src/tasks/tc_rx.fin"
                ret.Failure.__0 = 13L;

            }

        }

        #line 44 "src/tasks/tc_rx.fin"
        if (ret.__variant == Success) {
            
            #line 46 "src/tasks/tc_rx.fin"
            (*(TCHandler *)tc_handler_b.data).tc_descriptor.tc_num_bytes = size;

            #line 48 "src/tasks/tc_rx.fin"
            tc_handler_build((TCHandler *)tc_handler_b.data);

            #line 50 "src/tasks/tc_rx.fin"
            __termina_out_port__send(__ev, self->tc_message_queue_output, (void *)&tc_handler_b);

        } else
        {
            
            #line 54 "src/tasks/tc_rx.fin"
            self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that, tc_handler_b);

        }

    } else
    {
        
        #line 61 "src/tasks/tc_rx.fin"
        ret.__variant = Failure;
        #line 61 "src/tasks/tc_rx.fin"
        ret.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 66 "src/tasks/tc_rx.fin"
    return ret;

}

void __TCRXBottomHalfTask__termina_task(void * arg) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)arg;

    int32_t status = 0L;

    __termina_event_t event;

    __status_int32_t result;
    result.__variant = Success;

    size_t get_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &event, &status);

        if (status != 0L) {
            break;
        }

        switch (event.port_id) {
            
            case __TCRXBottomHalfTask__rx_tc:

                __termina_msg_queue__recv(self->rx_tc, (void *)&get_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->rx_tc, status);
                }

                result = TCRXBottomHalfTask__get_tc(&event, self, get_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source, __TCRXBottomHalfTask__rx_tc, result.Failure.__0);

                }

                break;

            default:

                __termina_exec__reboot();

                break;

        }

    }

    return;

}
