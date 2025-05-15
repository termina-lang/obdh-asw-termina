
#include "tasks/tc_rx.h"

__status_int32_t TCRXBottomHalfTask__get_tc(void * const __this, uint8_t data) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)__this;

    #line 29 "src/tasks/tc_rx.fin"
    __status_int32_t ret;
    #line 29 "src/tasks/tc_rx.fin"
    ret.__variant = Success;

    #line 33 "src/tasks/tc_rx.fin"
    if (self->rx_status.__variant == RXStatus__SyncBytesRx) {
        
        #line 35 "src/tasks/tc_rx.fin"
        if (data == self->sync_word[__termina_array__index(4U,
                                                           self->aux_index)]) {
            
            #line 37 "src/tasks/tc_rx.fin"
            if (3U == self->aux_index) {
                
                #line 38 "src/tasks/tc_rx.fin"
                self->aux_index = 0U;

                #line 39 "src/tasks/tc_rx.fin"
                self->rx_status.__variant = RXStatus__SyncLengthRx;

            } else
            {
                
                #line 41 "src/tasks/tc_rx.fin"
                self->aux_index = self->aux_index + 1U;

            }

        } else
        {
            
            #line 45 "src/tasks/tc_rx.fin"
            self->aux_index = 0U;

        }

    } else
    #line 49 "src/tasks/tc_rx.fin"
    if (self->rx_status.__variant == RXStatus__SyncLengthRx) {
        
        #line 51 "src/tasks/tc_rx.fin"
        self->RX_tc_length[__termina_array__index(2U, self->aux_index)] = data;

        #line 52 "src/tasks/tc_rx.fin"
        self->aux_index = self->aux_index + 1U;

        #line 54 "src/tasks/tc_rx.fin"
        if (2U == self->aux_index) {
            
            #line 56 "src/tasks/tc_rx.fin"
            self->telecommand.tc_num_bytes = (size_t)deserialize_uint16(self->RX_tc_length);

            #line 58 "src/tasks/tc_rx.fin"
            if (self->telecommand.tc_num_bytes < 256U) {
                
                #line 60 "src/tasks/tc_rx.fin"
                self->rx_status.__variant = RXStatus__TCBytesRx;

            } else
            {
                
                #line 64 "src/tasks/tc_rx.fin"
                self->rx_status.__variant = RXStatus__SyncBytesRx;

            }

            #line 66 "src/tasks/tc_rx.fin"
            self->aux_index = 0U;

        }

    } else
    {
        
        #line 73 "src/tasks/tc_rx.fin"
        self->telecommand.tc_bytes[__termina_array__index(256U,
                                                          self->aux_index)] = data;

        #line 74 "src/tasks/tc_rx.fin"
        self->aux_index = self->aux_index + 1U;

        #line 76 "src/tasks/tc_rx.fin"
        if (self->aux_index == (size_t)self->telecommand.tc_num_bytes) {
            
            #line 78 "src/tasks/tc_rx.fin"
            self->rx_status.__variant = RXStatus__SyncBytesRx;

            #line 80 "src/tasks/tc_rx.fin"
            __option_box_t tc_handler;
            #line 80 "src/tasks/tc_rx.fin"
            tc_handler.__variant = None;

            #line 81 "src/tasks/tc_rx.fin"
            self->a_tc_handler_pool.alloc(self->a_tc_handler_pool.__that,
                                          &tc_handler);

            #line 85 "src/tasks/tc_rx.fin"
            if (tc_handler.__variant == Some) {
                
                #line 83 "src/tasks/tc_rx.fin"
                __termina_box_t tc_handler_b = tc_handler.Some.__0;

                #line 87 "src/tasks/tc_rx.fin"
                tc_handler_build_from_descriptor((TCHandlerT *)tc_handler_b.data,
                                                 &self->telecommand);

                #line 89 "src/tasks/tc_rx.fin"
                __termina_out_port__send(self->tc_message_queue_output,
                                         (void *)&tc_handler_b);

            } else
            {
                
                #line 92 "src/tasks/tc_rx.fin"
                ret.__variant = Failure;
                #line 92 "src/tasks/tc_rx.fin"
                ret.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 98 "src/tasks/tc_rx.fin"
    return ret;

}

void __TCRXBottomHalfTask__termina_task(void * arg) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)arg;

    int32_t status = 0L;

    uint32_t next_msg = 0U;

    __status_int32_t result;
    result.__variant = Success;

    uint8_t get_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status != 0L) {
            break;
        }

        switch (next_msg) {
            
            case __TCRXBottomHalfTask__byte_message_queue_input:

                __termina_msg_queue__recv(self->byte_message_queue_input,
                                          (void *)&get_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->byte_message_queue_input,
                                                           status);
                }

                result = TCRXBottomHalfTask__get_tc(self, get_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __TCRXBottomHalfTask__byte_message_queue_input,
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
