
#include "tasks/tc_rx.h"

Result TCRXBottomHalfTask__get_tc(void * const __this, uint8_t data) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)__this;

    Result ret;
    ret.__variant = Result__Ok;

    if (self->rx_status.__variant == RXStatus__SyncBytesRx) {
        
        if (data == self->sync_word[__termina_array__index(4U,
                                                           self->aux_index)]) {
            
            if (3U == self->aux_index) {
                
                self->aux_index = 0U;

                self->rx_status.__variant = RXStatus__SyncLengthRx;

            } else {
                
                self->aux_index = self->aux_index + 1U;

            }

        } else {
            
            self->aux_index = 0U;

        }

    } else if (self->rx_status.__variant == RXStatus__SyncLengthRx) {
        
        self->RX_tc_length[__termina_array__index(2U, self->aux_index)] = data;

        self->aux_index = self->aux_index + 1U;

        if (2U == self->aux_index) {
            
            self->telecommand.tc_num_bytes = (size_t)deserialize_uint16(self->RX_tc_length);

            if (self->telecommand.tc_num_bytes < max_tc_size) {
                
                self->rx_status.__variant = RXStatus__TCBytesRx;

            } else {
                
                self->rx_status.__variant = RXStatus__SyncBytesRx;

            }

            self->aux_index = 0U;

        }

    } else {
        
        self->telecommand.tc_bytes[__termina_array__index(max_tc_size,
                                                          self->aux_index)] = data;

        self->aux_index = self->aux_index + 1U;

        if (self->aux_index == (size_t)self->telecommand.tc_num_bytes) {
            
            self->rx_status.__variant = RXStatus__SyncBytesRx;

            __option_box_t tc_handler;
            tc_handler.__variant = None;

            (self->a_tc_handler_pool.alloc)(self->a_tc_handler_pool.__that,
                                            &tc_handler);

            if (tc_handler.__variant == Some) {
                
                __termina_box_t tc_handler_b = tc_handler.Some.__0;

                tc_handler_build_from_descriptor((TCHandlerT *)tc_handler_b.data,
                                                 &self->telecommand);

                __termina_out_port__send(self->tc_message_queue_output,
                                         (void *)&tc_handler_b);

            } else {
                
                ret.__variant = Result__Error;

            }

        }

    }

    return ret;

}

void __TCRXBottomHalfTask__termina_task(void * arg) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)arg;

    Status status;
    status.__variant = Status__Success;

    uint32_t next_msg = 0U;

    Result result;
    result.__variant = Result__Ok;

    uint8_t get_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status.__variant != Status__Success) {
            break;
        }

        switch (next_msg) {
            
            case __TCRXBottomHalfTask__byte_message_queue_input:

                __termina_msg_queue__recv(self->byte_message_queue_input,
                                          (void *)&get_tc__msg_data, &status);

                if (status.__variant != Status__Success) {
                    __termina_exec__shutdown();
                }

                result = TCRXBottomHalfTask__get_tc(self, get_tc__msg_data);

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
