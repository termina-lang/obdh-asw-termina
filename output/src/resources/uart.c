
#include "resources/uart.h"

const size_t hw_fifo_size = 1U;

void UARTDriver__disable_RF(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 216 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    #line 217 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_rf;

    #line 218 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TF(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 206 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    #line 207 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_tf;

    #line 208 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TI(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 196 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0xFFFFFFF7U;

    #line 197 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_ti;

    #line 198 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RI(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 176 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 177 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ri;

    #line 178 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RX(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 166 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 167 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_rxe;

    #line 168 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TI(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 186 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0x8U;

    #line 187 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ti;

    #line 188 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TX(const __termina_event_t * const __ev, UARTDriver * const self) {
    
    #line 156 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 157 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_txe;

    #line 158 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__rf_data_ready(const __termina_event_t * const __ev, const UARTDriver * const self) {
    
    #line 147 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0x1U;

    #line 148 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_rf) != 0U;

}

void UARTDriver__enqueue_rx(const __termina_event_t * const __ev, void * const __this, __option_size_t * const tc_completed) {
    
    #line 245 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 245 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 247 "src/resources/uart.fin"
    __status_int32_t status;
    #line 247 "src/resources/uart.fin"
    status.__variant = Success;

    #line 248 "src/resources/uart.fin"
    (*tc_completed).__variant = None;

    #line 250 "src/resources/uart.fin"
    for (size_t i = 0U; i < queue_max_noe && (is_full(&self->uart_rx_queue) == 0 && UARTDriver__rf_data_ready(__ev, self) && status.__variant == Failure == 0 && self->rx_status.__variant == RXStatus__FinishedTCRx == 0); i = i + 1U) {
        
        #line 256 "src/resources/uart.fin"
        uint8_t byte = (uint8_t)self->registers->data;

        #line 260 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__SyncBytesRx) {
            
            #line 262 "src/resources/uart.fin"
            if (byte == self->sync_word[__termina_array__index(4U, self->aux_index)]) {
                
                #line 264 "src/resources/uart.fin"
                if (3U == self->aux_index) {
                    
                    #line 265 "src/resources/uart.fin"
                    self->aux_index = 0U;

                    #line 266 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__SyncLengthRx;

                } else
                {
                    
                    #line 268 "src/resources/uart.fin"
                    self->aux_index = self->aux_index + 1U;

                }

            } else
            {
                
                #line 272 "src/resources/uart.fin"
                self->aux_index = 0U;

            }

        } else
        #line 276 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__SyncLengthRx) {
            
            #line 278 "src/resources/uart.fin"
            self->raw_rx_tc_length[__termina_array__index(2U, self->aux_index)] = byte;

            #line 279 "src/resources/uart.fin"
            self->aux_index = self->aux_index + 1U;

            #line 281 "src/resources/uart.fin"
            if (2U == self->aux_index) {
                
                #line 283 "src/resources/uart.fin"
                self->tc_num_bytes = (size_t)deserialize_uint16(self->raw_rx_tc_length);

                #line 285 "src/resources/uart.fin"
                if (self->tc_num_bytes < 256U) {
                    
                    #line 287 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__TCBytesRx;

                } else
                {
                    
                    #line 291 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__SyncBytesRx;

                }

                #line 294 "src/resources/uart.fin"
                self->aux_index = 0U;

            }

        } else
        #line 299 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__TCBytesRx) {
            
            #line 301 "src/resources/uart.fin"
            status = enqueue(&self->uart_rx_queue, byte);

            #line 302 "src/resources/uart.fin"
            self->aux_index = self->aux_index + 1U;

            #line 304 "src/resources/uart.fin"
            if (self->aux_index == self->tc_num_bytes) {
                
                #line 306 "src/resources/uart.fin"
                self->rx_status.__variant = RXStatus__FinishedTCRx;

            }

        } else
        {
            

        }

    }

    #line 317 "src/resources/uart.fin"
    if (self->rx_status.__variant == RXStatus__FinishedTCRx) {
        
        #line 319 "src/resources/uart.fin"
        (*tc_completed).__variant = Some;
        #line 319 "src/resources/uart.fin"
        (*tc_completed).Some.__0 = self->tc_num_bytes;

        #line 320 "src/resources/uart.fin"
        self->rx_status.__variant = RXStatus__SyncBytesRx;

        #line 321 "src/resources/uart.fin"
        self->aux_index = 0U;

    }

    #line 325 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 325 "src/resources/uart.fin"
    return;

}

void UARTDriver__initialize(const __termina_event_t * const __ev, void * const __this) {
    
    #line 467 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 467 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 469 "src/resources/uart.fin"
    UARTDriver__enable_RX(__ev, self);

    #line 470 "src/resources/uart.fin"
    UARTDriver__enable_TX(__ev, self);

    #line 471 "src/resources/uart.fin"
    UARTDriver__enable_RI(__ev, self);

    #line 472 "src/resources/uart.fin"
    UARTDriver__enable_TI(__ev, self);

    #line 473 "src/resources/uart.fin"
    UARTDriver__disable_TF(__ev, self);

    #line 474 "src/resources/uart.fin"
    UARTDriver__disable_RF(__ev, self);

    #line 476 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 476 "src/resources/uart.fin"
    return;

}

void UARTDriver__receive(const __termina_event_t * const __ev, void * const __this, __option_uint8_t * const byte) {
    
    #line 227 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 227 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 230 "src/resources/uart.fin"
    dequeue(&self->uart_rx_queue, byte);

    #line 232 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 232 "src/resources/uart.fin"
    return;

}

void UARTDriver__release_tx(const __termina_event_t * const __ev, void * const __this) {
    
    #line 335 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 335 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 337 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 339 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 341 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 343 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 344 "src/resources/uart.fin"
        __option_uint8_t extracted_elem;
        #line 344 "src/resources/uart.fin"
        extracted_elem.__variant = None;

        #line 346 "src/resources/uart.fin"
        for (size_t i = 0U; i < hw_fifo_size; i = i + 1U) {
            
            #line 348 "src/resources/uart.fin"
            dequeue(&self->uart_tx_queue, &extracted_elem);

            #line 351 "src/resources/uart.fin"
            if (extracted_elem.__variant == Some) {
                
                #line 351 "src/resources/uart.fin"
                uint8_t elem = extracted_elem.Some.__0;

                #line 352 "src/resources/uart.fin"
                self->registers->data = (uint32_t)elem;

                #line 353 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            } else
            {
                

            }

        }

        #line 362 "src/resources/uart.fin"
        if (sent_bytes < num_elements) {
            
            #line 364 "src/resources/uart.fin"
            self->rem_bytes = 1;

        } else
        {
            
            #line 368 "src/resources/uart.fin"
            self->rem_bytes = 0;

        }

    }

    #line 375 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 375 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__tf_is_empty(const __termina_event_t * const __ev, const UARTDriver * const self) {
    
    #line 137 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 138 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(const __termina_event_t * const __ev, void * const __this, const size_t nbytes, const uint8_t output_bytes[nbytes], __status_int32_t * const status) {
    
    #line 389 "src/resources/uart.fin"
    UARTDriver * self = (UARTDriver *)__this;

    #line 389 "src/resources/uart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 393 "src/resources/uart.fin"
    (*status).__variant = Success;

    #line 395 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 397 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 398 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 400 "src/resources/uart.fin"
        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            #line 402 "src/resources/uart.fin"
            for (size_t i = 0U; i < nbytes && (*status).__variant == Failure == 0; i = i + 1U) {
                
                #line 404 "src/resources/uart.fin"
                *status = enqueue(&self->uart_tx_queue, output_bytes[__termina_array__index(nbytes, i)]);

            }

        } else
        {
            
            #line 409 "src/resources/uart.fin"
            (*status).__variant = Failure;
            #line 409 "src/resources/uart.fin"
            (*status).Failure.__0 = TM_SEND_FAILURE;

        }

    } else
    {
        
        #line 414 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 416 "src/resources/uart.fin"
        if (UARTDriver__tf_is_empty(__ev, self)) {
            
            #line 418 "src/resources/uart.fin"
            for (size_t i = 0U; i < hw_fifo_size && i < nbytes; i = i + 1U) {
                
                #line 420 "src/resources/uart.fin"
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(nbytes, i)];

                #line 422 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            }

        }

        #line 428 "src/resources/uart.fin"
        if (sent_bytes < nbytes) {
            
            #line 430 "src/resources/uart.fin"
            self->rem_bytes = 1;

            #line 432 "src/resources/uart.fin"
            size_t left_bytes = nbytes - sent_bytes;

            #line 433 "src/resources/uart.fin"
            size_t num_elements = 0U;

            #line 435 "src/resources/uart.fin"
            get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

            #line 437 "src/resources/uart.fin"
            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                #line 439 "src/resources/uart.fin"
                for (size_t i = 0U; i < nbytes && (i < left_bytes && (*status).__variant == Failure == 0); i = i + 1U) {
                    
                    #line 441 "src/resources/uart.fin"
                    *status = enqueue(&self->uart_tx_queue, output_bytes[__termina_array__index(nbytes, i + sent_bytes)]);

                }

            } else
            {
                
                #line 448 "src/resources/uart.fin"
                (*status).__variant = Failure;
                #line 448 "src/resources/uart.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            }

        }

    }

    #line 456 "src/resources/uart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 456 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__tf_is_full(const __termina_event_t * const __ev, const UARTDriver * const self) {
    
    #line 127 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 128 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}
