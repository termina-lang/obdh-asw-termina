
#include "tasks/tc_rx.h"

__status_int32_t TCRXBottomHalfTask__get_tc(const __termina_event_t * const __ev,
                                            void * const __this,
                                            size_t frame_size) {
    
    #line 17 "src/tasks/tc_rx.fin"
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)__this;

    #line 19 "src/tasks/tc_rx.fin"
    __status_int32_t ret;
    #line 19 "src/tasks/tc_rx.fin"
    ret.__variant = Success;

    #line 21 "src/tasks/tc_rx.fin"
    self->telecommand.tc_num_bytes = frame_size;

    #line 23 "src/tasks/tc_rx.fin"
    for (size_t i = 0U; i < 256U && i < frame_size; i = i + 1U) {
        
        #line 25 "src/tasks/tc_rx.fin"
        __option_uint8_t byte;
        #line 25 "src/tasks/tc_rx.fin"
        byte.__variant = None;

        #line 27 "src/tasks/tc_rx.fin"
        self->uart.receive(__ev, self->uart.__that, &byte);

        #line 30 "src/tasks/tc_rx.fin"
        if (byte.__variant == Some) {
            
            #line 29 "src/tasks/tc_rx.fin"
            uint8_t b = byte.Some.__0;

            #line 31 "src/tasks/tc_rx.fin"
            self->telecommand.tc_bytes[__termina_array__index(256U, i)] = b;

        } else
        {
            

        }

    }

    #line 40 "src/tasks/tc_rx.fin"
    __option_box_t tc_handler;
    #line 40 "src/tasks/tc_rx.fin"
    tc_handler.__variant = None;

    #line 41 "src/tasks/tc_rx.fin"
    self->a_tc_handler_pool.alloc(__ev, self->a_tc_handler_pool.__that,
                                  &tc_handler);

    #line 45 "src/tasks/tc_rx.fin"
    if (tc_handler.__variant == Some) {
        
        #line 43 "src/tasks/tc_rx.fin"
        __termina_box_t tc_handler_b = tc_handler.Some.__0;

        #line 47 "src/tasks/tc_rx.fin"
        tc_handler_build_from_descriptor((TCHandler *)tc_handler_b.data,
                                         &self->telecommand);

        #line 49 "src/tasks/tc_rx.fin"
        __termina_out_port__send(__ev, self->tc_message_queue_output,
                                 (void *)&tc_handler_b);

    } else
    {
        
        #line 53 "src/tasks/tc_rx.fin"
        ret.__variant = Failure;
        #line 53 "src/tasks/tc_rx.fin"
        ret.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 59 "src/tasks/tc_rx.fin"
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
            
            case __TCRXBottomHalfTask__rx_frame:

                __termina_msg_queue__recv(self->rx_frame,
                                          (void *)&get_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->rx_frame,
                                                           status);
                }

                result = TCRXBottomHalfTask__get_tc(&event, self,
                                                    get_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __TCRXBottomHalfTask__rx_frame,
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
