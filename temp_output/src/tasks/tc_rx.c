
#include "tasks/tc_rx.h"

Result TCRXBottomHalfTask__get_tc(TCRXBottomHalfTask * const self,
                                  uint8_t data) {
    
    Result ret;
    ret.__variant = Result__Ok;

    if (self->rx_status.__variant == RXStatus__TCBytesRx) {
        
        self->telecommand.tc_bytes[self->aux_index] = data;

        self->aux_index = self->aux_index + 1;

        if (self->aux_index == (size_t)self->telecommand.tc_num_bytes) {
            
            self->rx_status.__variant = RXStatus__SyncBytesRx;

            __option_box_t tc_descriptor;
            tc_descriptor.__variant = None;

            __termina_pool__alloc(self->a_tc_descriptor_pool, &tc_descriptor);

            if (tc_descriptor.__variant == Some) {
                
                __termina_box_t descriptor = tc_descriptor.Some.__0;

                for (size_t i = 0; i < max_tc_size && i < self->telecommand.tc_num_bytes; i = i + 1) {
                    
                    (*(TCDescriptorT *)descriptor.data).tc_bytes[i] = self->telecommand.tc_bytes[i];

                }

                (*(TCDescriptorT *)descriptor.data).tc_num_bytes = self->telecommand.tc_num_bytes;

                __termina_msg_queue__send(self->tc_message_queue_output,
                                          (void *)&descriptor);

            } else {
                
                ret.__variant = Result__Error;

            }

        }

    } else if (self->rx_status.__variant == RXStatus__SyncLengthRx) {
        
        self->RX_tc_length[self->aux_index] = data;

        self->aux_index = self->aux_index + 1;

        if (2 == self->aux_index) {
            
            self->telecommand.tc_num_bytes = (size_t)deserialize_uint16(self->RX_tc_length);

            if (self->telecommand.tc_num_bytes < max_tc_size) {
                
                self->rx_status.__variant = RXStatus__TCBytesRx;

            } else {
                
                self->rx_status.__variant = RXStatus__SyncBytesRx;

            }

            self->aux_index = 0;

        }

    } else {
        
        if (data == self->sync_word[self->aux_index]) {
            
            if (3 == self->aux_index) {
                
                self->aux_index = 0;

                self->rx_status.__variant = RXStatus__SyncLengthRx;

            } else {
                
                self->aux_index = self->aux_index + 1;

            }

        } else {
            
            self->aux_index = 0;

        }

    }

    return ret;

}
