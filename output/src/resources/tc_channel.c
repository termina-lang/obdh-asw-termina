
#include "resources/tc_channel.h"

void CTCChannel__enqueue_rx(const __termina_event_t * const __ev, void * const __this, uint8_t byte, __result_bool__int32_t * const result) {
    
    #line 52 "src/resources/tc_channel.fin"
    CTCChannel * self = (CTCChannel *)__this;

    #line 52 "src/resources/tc_channel.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 54 "src/resources/tc_channel.fin"
    (*result).__variant = Ok;
    #line 54 "src/resources/tc_channel.fin"
    (*result).Ok.__0 = 0;

    #line 56 "src/resources/tc_channel.fin"
    for (size_t i = 0U; i < queue_max_noe && (is_full(&self->tc_rx_queue) == 0 && (*result).__variant == Error == 0 && self->rx_status.__variant == TCRxStatus__FinishedTCRx == 0); i = i + 1U) {
        
        #line 63 "src/resources/tc_channel.fin"
        if (self->rx_status.__variant == TCRxStatus__SyncBytesRx) {
            
            #line 65 "src/resources/tc_channel.fin"
            if (byte == self->sync_word[__termina_array__index(4U, self->aux_index)]) {
                
                #line 67 "src/resources/tc_channel.fin"
                if (3U == self->aux_index) {
                    
                    #line 68 "src/resources/tc_channel.fin"
                    self->aux_index = 0U;

                    #line 69 "src/resources/tc_channel.fin"
                    self->rx_status.__variant = TCRxStatus__SyncLengthRx;

                } else
                {
                    
                    #line 71 "src/resources/tc_channel.fin"
                    self->aux_index = self->aux_index + 1U;

                }

            } else
            {
                
                #line 75 "src/resources/tc_channel.fin"
                self->aux_index = 0U;

            }

        } else
        #line 79 "src/resources/tc_channel.fin"
        if (self->rx_status.__variant == TCRxStatus__SyncLengthRx) {
            
            #line 81 "src/resources/tc_channel.fin"
            self->raw_rx_tc_length[__termina_array__index(2U, self->aux_index)] = byte;

            #line 82 "src/resources/tc_channel.fin"
            self->aux_index = self->aux_index + 1U;

            #line 84 "src/resources/tc_channel.fin"
            if (2U == self->aux_index) {
                
                #line 86 "src/resources/tc_channel.fin"
                self->tc_num_bytes = (size_t)deserialize_uint16(self->raw_rx_tc_length);

                #line 88 "src/resources/tc_channel.fin"
                if (self->tc_num_bytes < 256U) {
                    
                    #line 90 "src/resources/tc_channel.fin"
                    self->rx_status.__variant = TCRxStatus__TCBytesRx;

                } else
                {
                    
                    #line 94 "src/resources/tc_channel.fin"
                    self->rx_status.__variant = TCRxStatus__SyncBytesRx;

                }

                #line 96 "src/resources/tc_channel.fin"
                self->aux_index = 0U;

            }

        } else
        #line 101 "src/resources/tc_channel.fin"
        if (self->rx_status.__variant == TCRxStatus__TCBytesRx) {
            
            #line 103 "src/resources/tc_channel.fin"
            __status_int32_t status = enqueue(&self->tc_rx_queue, byte);

            #line 106 "src/resources/tc_channel.fin"
            if (status.__variant == Success) {
                
                #line 108 "src/resources/tc_channel.fin"
                self->aux_index = self->aux_index + 1U;

                #line 110 "src/resources/tc_channel.fin"
                if (self->aux_index == self->tc_num_bytes) {
                    
                    #line 112 "src/resources/tc_channel.fin"
                    self->rx_status.__variant = TCRxStatus__FinishedTCRx;

                }

            } else
            {
                
                #line 116 "src/resources/tc_channel.fin"
                int32_t error_code = status.Failure.__0;

                #line 117 "src/resources/tc_channel.fin"
                (*result).__variant = Error;
                #line 117 "src/resources/tc_channel.fin"
                (*result).Error.__0 = error_code;

            }

        } else
        {
            

        }

    }

    #line 128 "src/resources/tc_channel.fin"
    if ((*result).__variant == Ok && self->rx_status.__variant == TCRxStatus__FinishedTCRx) {
        
        #line 130 "src/resources/tc_channel.fin"
        self->aux_index = 0U;

        #line 131 "src/resources/tc_channel.fin"
        (*result).__variant = Ok;
        #line 131 "src/resources/tc_channel.fin"
        (*result).Ok.__0 = 1;

    }

    #line 135 "src/resources/tc_channel.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 135 "src/resources/tc_channel.fin"
    return;

}

void CTCChannel__receive_tc(const __termina_event_t * const __ev, void * const __this, TCDescriptor * const tc_descriptor, __status_int32_t * const status) {
    
    #line 139 "src/resources/tc_channel.fin"
    CTCChannel * self = (CTCChannel *)__this;

    #line 139 "src/resources/tc_channel.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 143 "src/resources/tc_channel.fin"
    (*status).__variant = Success;

    #line 145 "src/resources/tc_channel.fin"
    if (self->rx_status.__variant == TCRxStatus__FinishedTCRx) {
        
        #line 147 "src/resources/tc_channel.fin"
        size_t num_bytes = 0U;

        #line 148 "src/resources/tc_channel.fin"
        get_num_enqueued_elems(&self->tc_rx_queue, &num_bytes);

        #line 150 "src/resources/tc_channel.fin"
        if (num_bytes >= self->tc_num_bytes) {
            
            #line 152 "src/resources/tc_channel.fin"
            for (size_t i = 0U; i < queue_max_noe && (*status).__variant == Success; i = i + 1U) {
                
                #line 154 "src/resources/tc_channel.fin"
                __option_uint8_t obyte;
                #line 154 "src/resources/tc_channel.fin"
                obyte.__variant = None;

                #line 155 "src/resources/tc_channel.fin"
                dequeue(&self->tc_rx_queue, &obyte);

                #line 159 "src/resources/tc_channel.fin"
                if (obyte.__variant == Some) {
                    
                    #line 159 "src/resources/tc_channel.fin"
                    uint8_t byte = obyte.Some.__0;

                    #line 160 "src/resources/tc_channel.fin"
                    if ((*status).__variant == Success) {
                        
                        #line 161 "src/resources/tc_channel.fin"
                        tc_descriptor->tc_bytes[__termina_array__index(256U, i)] = byte;

                    }

                } else
                {
                    
                    #line 165 "src/resources/tc_channel.fin"
                    (*status).__variant = Failure;
                    #line 165 "src/resources/tc_channel.fin"
                    (*status).Failure.__0 = 13L;

                }

            }

            #line 172 "src/resources/tc_channel.fin"
            if ((*status).__variant == Success) {
                
                #line 173 "src/resources/tc_channel.fin"
                tc_descriptor->tc_num_bytes = self->tc_num_bytes;

            }

        } else
        {
            
            #line 177 "src/resources/tc_channel.fin"
            (*status).__variant = Failure;
            #line 177 "src/resources/tc_channel.fin"
            (*status).Failure.__0 = 13L;

        }

        #line 181 "src/resources/tc_channel.fin"
        self->rx_status.__variant = TCRxStatus__SyncBytesRx;

        #line 182 "src/resources/tc_channel.fin"
        self->aux_index = 0U;

    } else
    {
        
        #line 185 "src/resources/tc_channel.fin"
        (*status).__variant = Failure;
        #line 185 "src/resources/tc_channel.fin"
        (*status).Failure.__0 = 13L;

    }

    #line 188 "src/resources/tc_channel.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 188 "src/resources/tc_channel.fin"
    return;

}
