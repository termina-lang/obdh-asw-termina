
#include "resources/uart.h"

const size_t hw_fifo_size = 1U;

void UARTDriver__disable_RF(const __termina_event_t * const __ev,
                            UARTDriver * const self) {
    
    #line 136 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    #line 137 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_rf;

    #line 138 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TF(const __termina_event_t * const __ev,
                            UARTDriver * const self) {
    
    #line 130 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    #line 131 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_tf;

    #line 132 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TI(const __termina_event_t * const __ev,
                            UARTDriver * const self) {
    
    #line 124 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0xFFFFFFF7U;

    #line 125 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_ti;

    #line 126 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RI(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    #line 112 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 113 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ri;

    #line 114 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RX(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    #line 106 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 107 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_rxe;

    #line 108 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TI(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    #line 118 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0x8U;

    #line 119 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ti;

    #line 120 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TX(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    #line 100 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 101 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_txe;

    #line 102 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__rf_data_ready(const __termina_event_t * const __ev,
                                const UARTDriver * const self) {
    
    #line 94 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0x1U;

    #line 95 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_rf) != 0U;

}

void UARTDriver__enqueue_rx(const __termina_event_t * const __ev,
                            void * const __this,
                            __option_size_t * const tc_completed) {
    
    #line 150 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 150 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 152 "src/resources/uart.fin"
    __status_int32_t status;
    #line 152 "src/resources/uart.fin"
    status.__variant = Success;

    #line 153 "src/resources/uart.fin"
    (*tc_completed).__variant = None;

    #line 155 "src/resources/uart.fin"
    for (size_t i = 0U; i < queue_max_noe && (is_full(&self->uart_rx_queue) == 0 && UARTDriver__rf_data_ready(__ev,
                                                                                                              self) && status.__variant == Failure == 0 && self->rx_status.__variant == RXStatus__FinishedTCRx == 0); i = i + 1U) {
        
        #line 161 "src/resources/uart.fin"
        uint8_t byte = (uint8_t)self->registers->data;

        #line 165 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__SyncBytesRx) {
            
            #line 167 "src/resources/uart.fin"
            if (byte == self->sync_word[__termina_array__index(4U,
                                                               self->aux_index)]) {
                
                #line 169 "src/resources/uart.fin"
                if (3U == self->aux_index) {
                    
                    #line 170 "src/resources/uart.fin"
                    self->aux_index = 0U;

                    #line 171 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__SyncLengthRx;

                } else
                {
                    
                    #line 173 "src/resources/uart.fin"
                    self->aux_index = self->aux_index + 1U;

                }

            } else
            {
                
                #line 177 "src/resources/uart.fin"
                self->aux_index = 0U;

            }

        } else
        #line 181 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__SyncLengthRx) {
            
            #line 183 "src/resources/uart.fin"
            self->raw_rx_tc_length[__termina_array__index(2U,
                                                          self->aux_index)] = byte;

            #line 184 "src/resources/uart.fin"
            self->aux_index = self->aux_index + 1U;

            #line 186 "src/resources/uart.fin"
            if (2U == self->aux_index) {
                
                #line 188 "src/resources/uart.fin"
                self->tc_num_bytes = (size_t)deserialize_uint16(self->raw_rx_tc_length);

                #line 190 "src/resources/uart.fin"
                if (self->tc_num_bytes < 256U) {
                    
                    #line 192 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__TCBytesRx;

                } else
                {
                    
                    #line 196 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__SyncBytesRx;

                }

                #line 199 "src/resources/uart.fin"
                self->aux_index = 0U;

            }

        } else
        #line 204 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__TCBytesRx) {
            
            #line 206 "src/resources/uart.fin"
            status = enqueue(&self->uart_rx_queue, byte);

            #line 207 "src/resources/uart.fin"
            self->aux_index = self->aux_index + 1U;

            #line 209 "src/resources/uart.fin"
            if (self->aux_index == self->tc_num_bytes) {
                
                #line 211 "src/resources/uart.fin"
                self->rx_status.__variant = RXStatus__FinishedTCRx;

            }

        } else
        {
            

        }

    }

    #line 222 "src/resources/uart.fin"
    if (self->rx_status.__variant == RXStatus__FinishedTCRx) {
        
        #line 224 "src/resources/uart.fin"
        (*tc_completed).__variant = Some;
        #line 224 "src/resources/uart.fin"
        (*tc_completed).Some.__0 = self->tc_num_bytes;

        #line 225 "src/resources/uart.fin"
        self->rx_status.__variant = RXStatus__SyncBytesRx;

        #line 226 "src/resources/uart.fin"
        self->aux_index = 0U;

    }

    #line 230 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 230 "src/resources/uart.fin"
    return;

}

void UARTDriver__initialize(const __termina_event_t * const __ev,
                            void * const __this) {
    
    #line 350 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 350 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 352 "src/resources/uart.fin"
    UARTDriver__enable_RX(__ev, self);

    #line 353 "src/resources/uart.fin"
    UARTDriver__enable_TX(__ev, self);

    #line 354 "src/resources/uart.fin"
    UARTDriver__enable_RI(__ev, self);

    #line 355 "src/resources/uart.fin"
    UARTDriver__enable_TI(__ev, self);

    #line 356 "src/resources/uart.fin"
    UARTDriver__disable_TF(__ev, self);

    #line 357 "src/resources/uart.fin"
    UARTDriver__disable_RF(__ev, self);

    #line 359 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 359 "src/resources/uart.fin"
    return;

}

void UARTDriver__receive(const __termina_event_t * const __ev,
                         void * const __this, __option_uint8_t * const byte) {
    
    #line 141 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 141 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 144 "src/resources/uart.fin"
    dequeue(&self->uart_rx_queue, byte);

    #line 146 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 146 "src/resources/uart.fin"
    return;

}

void UARTDriver__release_tx(const __termina_event_t * const __ev,
                            void * const __this) {
    
    #line 235 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 235 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 237 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 239 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 241 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 243 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 244 "src/resources/uart.fin"
        __option_uint8_t extracted_elem;
        #line 244 "src/resources/uart.fin"
        extracted_elem.__variant = None;

        #line 246 "src/resources/uart.fin"
        for (size_t i = 0U; i < hw_fifo_size; i = i + 1U) {
            
            #line 248 "src/resources/uart.fin"
            dequeue(&self->uart_tx_queue, &extracted_elem);

            #line 251 "src/resources/uart.fin"
            if (extracted_elem.__variant == Some) {
                
                #line 250 "src/resources/uart.fin"
                uint8_t elem = extracted_elem.Some.__0;

                #line 252 "src/resources/uart.fin"
                self->registers->data = (uint32_t)elem;

                #line 253 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            } else
            {
                

            }

        }

        #line 262 "src/resources/uart.fin"
        if (sent_bytes < num_elements) {
            
            #line 264 "src/resources/uart.fin"
            self->rem_bytes = 1;

        } else
        {
            
            #line 268 "src/resources/uart.fin"
            self->rem_bytes = 0;

        }

    }

    #line 275 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 275 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__tf_is_empty(const __termina_event_t * const __ev,
                              const UARTDriver * const self) {
    
    #line 89 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 90 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(const __termina_event_t * const __ev, void * const __this,
                      const size_t nbytes, const uint8_t output_bytes[nbytes],
                      __status_int32_t * const status) {
    
    #line 278 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 278 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 282 "src/resources/uart.fin"
    (*status).__variant = Success;

    #line 284 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 286 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 287 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 289 "src/resources/uart.fin"
        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            #line 291 "src/resources/uart.fin"
            for (size_t i = 0U; i < nbytes && (*status).__variant == Failure == 0; i = i + 1U) {
                
                #line 293 "src/resources/uart.fin"
                *status = enqueue(&self->uart_tx_queue,
                                  output_bytes[__termina_array__index(nbytes,
                                                                      i)]);

            }

        } else
        {
            
            #line 298 "src/resources/uart.fin"
            (*status).__variant = Failure;
            #line 298 "src/resources/uart.fin"
            (*status).Failure.__0 = TM_SEND_FAILURE;

        }

    } else
    {
        
        #line 303 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 305 "src/resources/uart.fin"
        if (UARTDriver__tf_is_empty(__ev, self)) {
            
            #line 307 "src/resources/uart.fin"
            for (size_t i = 0U; i < hw_fifo_size; i = i + 1U) {
                
                #line 309 "src/resources/uart.fin"
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(nbytes,
                                                                                      i)];

                #line 311 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            }

        }

        #line 317 "src/resources/uart.fin"
        if (sent_bytes < nbytes) {
            
            #line 319 "src/resources/uart.fin"
            self->rem_bytes = 1;

            #line 321 "src/resources/uart.fin"
            size_t left_bytes = nbytes - sent_bytes;

            #line 322 "src/resources/uart.fin"
            size_t num_elements = 0U;

            #line 324 "src/resources/uart.fin"
            get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

            #line 326 "src/resources/uart.fin"
            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                #line 328 "src/resources/uart.fin"
                for (size_t i = 0U; i < nbytes && (i < left_bytes && (*status).__variant == Failure == 0); i = i + 1U) {
                    
                    #line 330 "src/resources/uart.fin"
                    *status = enqueue(&self->uart_tx_queue,
                                      output_bytes[__termina_array__index(nbytes,
                                                                          i + sent_bytes)]);

                }

            } else
            {
                
                #line 337 "src/resources/uart.fin"
                (*status).__variant = Failure;
                #line 337 "src/resources/uart.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            }

        }

    }

    #line 345 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 345 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__tf_is_full(const __termina_event_t * const __ev,
                             const UARTDriver * const self) {
    
    #line 84 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 85 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}
