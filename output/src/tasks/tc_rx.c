
#include "tasks/tc_rx.h"

__status_int32_t TCRXBottomHalfTask__get_tc(const __termina_event_t * const __ev,
                                            void * const __this,
                                            size_t frame_size) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)__this;

    __status_int32_t ret;
    ret.__variant = Success;

    self->telecommand.tc_num_bytes = frame_size;

    for (size_t i = 0U; i < 256U && i < frame_size; i = i + 1U) {
        
        __option_uint8_t byte;
        byte.__variant = None;

        self->uart.receive(__ev, self->uart.__that, &byte);

        if (byte.__variant == Some) {
            
            uint8_t b = byte.Some.__0;

            self->telecommand.tc_bytes[__termina_array__index(256U, i)] = b;

        } else {
            

        }

    }

    __option_box_t tc_handler;
    tc_handler.__variant = None;

    self->a_tc_handler_pool.alloc(__ev, self->a_tc_handler_pool.__that,
                                  &tc_handler);

    if (tc_handler.__variant == Some) {
        
        __termina_box_t tc_handler_b = tc_handler.Some.__0;

        tc_handler_build_from_descriptor((TCHandlerT *)tc_handler_b.data,
                                         &self->telecommand);

        __termina_out_port__send(__ev, self->tc_message_queue_output,
                                 (void *)&tc_handler_b);

    } else {
        
        ret.__variant = Failure;
        ret.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

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
