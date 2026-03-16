
#include "resources/tc_channel.h"

void CTCChannel__dequeue(const __termina_event_t * const __ev, void * const __this, __option_uint8_t * const obyte) {
    
    #line 125 "src/resources/tc_channel.fin"
    CTCChannel * self = (CTCChannel *)__this;

    #line 125 "src/resources/tc_channel.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 128 "src/resources/tc_channel.fin"
    dequeue(&self->tc_rx_queue, obyte);

    #line 130 "src/resources/tc_channel.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 130 "src/resources/tc_channel.fin"
    return;

}

void CTCChannel__enqueue(const __termina_event_t * const __ev, void * const __this, uint8_t byte, CharDevIrqStatus * const status) {
    
    #line 43 "src/resources/tc_channel.fin"
    CTCChannel * self = (CTCChannel *)__this;

    #line 43 "src/resources/tc_channel.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 45 "src/resources/tc_channel.fin"
    (*status).__variant = CharDevIrqStatus__IrqOk;

    #line 49 "src/resources/tc_channel.fin"
    if (self->rx_status.__variant == TCRxStatus__SyncBytesRx) {
        
        #line 51 "src/resources/tc_channel.fin"
        if (byte == self->sync_word[__termina_array__index(4U, self->aux_index)]) {
            
            #line 53 "src/resources/tc_channel.fin"
            if (3U == self->aux_index) {
                
                #line 54 "src/resources/tc_channel.fin"
                self->aux_index = 0U;

                #line 55 "src/resources/tc_channel.fin"
                self->rx_status.__variant = TCRxStatus__SyncLengthRx;

            } else
            {
                
                #line 57 "src/resources/tc_channel.fin"
                self->aux_index = self->aux_index + 1U;

            }

        } else
        {
            
            #line 61 "src/resources/tc_channel.fin"
            self->aux_index = 0U;

        }

    } else
    #line 65 "src/resources/tc_channel.fin"
    if (self->rx_status.__variant == TCRxStatus__SyncLengthRx) {
        
        #line 67 "src/resources/tc_channel.fin"
        self->raw_rx_tc_length[__termina_array__index(2U, self->aux_index)] = byte;

        #line 68 "src/resources/tc_channel.fin"
        self->aux_index = self->aux_index + 1U;

        #line 70 "src/resources/tc_channel.fin"
        if (2U == self->aux_index) {
            
            #line 72 "src/resources/tc_channel.fin"
            self->tc_num_bytes = (size_t)deserialize_uint16(self->raw_rx_tc_length);

            #line 74 "src/resources/tc_channel.fin"
            if (self->tc_num_bytes < 256U) {
                
                #line 76 "src/resources/tc_channel.fin"
                self->rx_status.__variant = TCRxStatus__TCBytesRx;

            } else
            {
                
                #line 80 "src/resources/tc_channel.fin"
                self->rx_status.__variant = TCRxStatus__SyncBytesRx;

            }

            #line 82 "src/resources/tc_channel.fin"
            self->aux_index = 0U;

        }

    } else
    #line 87 "src/resources/tc_channel.fin"
    if (self->rx_status.__variant == TCRxStatus__TCBytesRx) {
        
        #line 89 "src/resources/tc_channel.fin"
        __status_int32_t result = enqueue(&self->tc_rx_queue, byte);

        #line 92 "src/resources/tc_channel.fin"
        if (result.__variant == Success) {
            
            #line 94 "src/resources/tc_channel.fin"
            self->aux_index = self->aux_index + 1U;

            #line 96 "src/resources/tc_channel.fin"
            if (self->aux_index == self->tc_num_bytes) {
                
                #line 98 "src/resources/tc_channel.fin"
                self->rx_status.__variant = TCRxStatus__FinishedTCRx;

            }

        } else
        {
            
            #line 102 "src/resources/tc_channel.fin"
            int32_t error_code = result.Failure.__0;

            #line 103 "src/resources/tc_channel.fin"
            (*status).__variant = CharDevIrqStatus__IrqError;
            #line 103 "src/resources/tc_channel.fin"
            (*status).IrqError.__0 = error_code;

        }

    } else
    {
        

    }

    #line 112 "src/resources/tc_channel.fin"
    if ((*status).__variant == CharDevIrqStatus__IrqOk && self->rx_status.__variant == TCRxStatus__FinishedTCRx) {
        
        #line 115 "src/resources/tc_channel.fin"
        self->rx_status.__variant = TCRxStatus__SyncBytesRx;

        #line 116 "src/resources/tc_channel.fin"
        self->aux_index = 0U;

        #line 117 "src/resources/tc_channel.fin"
        (*status).__variant = CharDevIrqStatus__RxComplete;
        #line 117 "src/resources/tc_channel.fin"
        (*status).RxComplete.__0 = self->tc_num_bytes;

    }

    #line 121 "src/resources/tc_channel.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 121 "src/resources/tc_channel.fin"
    return;

}
