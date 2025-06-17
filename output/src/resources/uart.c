
#include "resources/uart.h"

const size_t hw_fifo_size = 1U;

void UARTDriver__disable_RF(const __termina_event_t * const __ev,
                            UARTDriver * const self) {
    
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    self->registers->control = self->registers->control & riscv_uart_rf;

    return;

}

void UARTDriver__disable_TF(const __termina_event_t * const __ev,
                            UARTDriver * const self) {
    
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    self->registers->control = self->registers->control & riscv_uart_tf;

    return;

}

void UARTDriver__disable_TI(const __termina_event_t * const __ev,
                            UARTDriver * const self) {
    
    uint32_t riscv_uart_ti = 0xFFFFFFF7U;

    self->registers->control = self->registers->control & riscv_uart_ti;

    return;

}

void UARTDriver__enable_RI(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    uint32_t riscv_uart_ri = 0x4U;

    self->registers->control = self->registers->control | riscv_uart_ri;

    return;

}

void UARTDriver__enable_RX(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    uint32_t riscv_uart_rxe = 0x1U;

    self->registers->control = self->registers->control | riscv_uart_rxe;

    return;

}

void UARTDriver__enable_TI(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    uint32_t riscv_uart_ti = 0x8U;

    self->registers->control = self->registers->control | riscv_uart_ti;

    return;

}

void UARTDriver__enable_TX(const __termina_event_t * const __ev,
                           UARTDriver * const self) {
    
    uint32_t riscv_uart_txe = 0x2U;

    self->registers->control = self->registers->control | riscv_uart_txe;

    return;

}

_Bool UARTDriver__rf_data_ready(const __termina_event_t * const __ev,
                                const UARTDriver * const self) {
    
    uint32_t riscv_uart_rf = 0x1U;

    return (uint32_t)(self->registers->status & riscv_uart_rf) != 0U;

}

void UARTDriver__enqueue_rx(const __termina_event_t * const __ev,
                            void * const __this,
                            __option_size_t * const tc_completed) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    (*tc_completed).__variant = None;

    for (size_t i = 0U; i < queue_max_noe && (is_full(&self->uart_rx_queue) == 0 && UARTDriver__rf_data_ready(__ev,
                                                                                                              self) && status.__variant == Failure == 0 && self->rx_status.__variant == RXStatus__FinishedTCRx == 0); i = i + 1U) {
        
        uint8_t byte = (uint8_t)self->registers->data;

        if (self->rx_status.__variant == RXStatus__SyncBytesRx) {
            
            if (byte == self->sync_word[__termina_array__index(4U,
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
            
            self->raw_rx_tc_length[__termina_array__index(2U,
                                                          self->aux_index)] = byte;

            self->aux_index = self->aux_index + 1U;

            if (2U == self->aux_index) {
                
                self->tc_num_bytes = (size_t)deserialize_uint16(self->raw_rx_tc_length);

                if (self->tc_num_bytes < 256U) {
                    
                    self->rx_status.__variant = RXStatus__TCBytesRx;

                } else {
                    
                    self->rx_status.__variant = RXStatus__SyncBytesRx;

                }

                self->aux_index = 0U;

            }

        } else if (self->rx_status.__variant == RXStatus__TCBytesRx) {
            
            status = enqueue(&self->uart_rx_queue, byte);

            self->aux_index = self->aux_index + 1U;

            if (self->aux_index == self->tc_num_bytes) {
                
                self->rx_status.__variant = RXStatus__FinishedTCRx;

            }

        } else {
            

        }

    }

    if (self->rx_status.__variant == RXStatus__FinishedTCRx) {
        
        (*tc_completed).__variant = Some;
        (*tc_completed).Some.__0 = self->tc_num_bytes;

        self->rx_status.__variant = RXStatus__SyncBytesRx;

        self->aux_index = 0U;

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void UARTDriver__initialize(const __termina_event_t * const __ev,
                            void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    UARTDriver__enable_RX(__ev, self);

    UARTDriver__enable_TX(__ev, self);

    UARTDriver__enable_RI(__ev, self);

    UARTDriver__enable_TI(__ev, self);

    UARTDriver__disable_TF(__ev, self);

    UARTDriver__disable_RF(__ev, self);

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void UARTDriver__receive(const __termina_event_t * const __ev,
                         void * const __this, __option_uint8_t * const byte) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    dequeue(&self->uart_rx_queue, byte);

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void UARTDriver__release_tx(const __termina_event_t * const __ev,
                            void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    if (self->rem_bytes) {
        
        size_t num_elements = 0U;

        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        size_t sent_bytes = 0U;

        __option_uint8_t extracted_elem;
        extracted_elem.__variant = None;

        for (size_t i = 0U; i < hw_fifo_size; i = i + 1U) {
            
            dequeue(&self->uart_tx_queue, &extracted_elem);

            if (extracted_elem.__variant == Some) {
                
                uint8_t elem = extracted_elem.Some.__0;

                self->registers->data = (uint32_t)elem;

                sent_bytes = sent_bytes + 1U;

            } else {
                

            }

        }

        if (sent_bytes < num_elements) {
            
            self->rem_bytes = 1;

        } else {
            
            self->rem_bytes = 0;

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

_Bool UARTDriver__tf_is_empty(const __termina_event_t * const __ev,
                              const UARTDriver * const self) {
    
    uint32_t riscv_uart_te = 0x4U;

    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(const __termina_event_t * const __ev, void * const __this,
                      const size_t nbytes, const uint8_t output_bytes[nbytes],
                      __status_int32_t * const status) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    (*status).__variant = Success;

    if (self->rem_bytes) {
        
        size_t num_elements = 0U;

        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            for (size_t i = 0U; i < nbytes && (*status).__variant == Failure == 0; i = i + 1U) {
                
                *status = enqueue(&self->uart_tx_queue,
                                  output_bytes[__termina_array__index(nbytes,
                                                                      i)]);

            }

        } else {
            
            (*status).__variant = Failure;
            (*status).Failure.__0 = TM_SEND_FAILURE;

        }

    } else {
        
        size_t sent_bytes = 0U;

        if (UARTDriver__tf_is_empty(__ev, self)) {
            
            for (size_t i = 0U; i < hw_fifo_size; i = i + 1U) {
                
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(nbytes,
                                                                                      i)];

                sent_bytes = sent_bytes + 1U;

            }

        }

        if (sent_bytes < nbytes) {
            
            self->rem_bytes = 1;

            size_t left_bytes = nbytes - sent_bytes;

            size_t num_elements = 0U;

            get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                for (size_t i = 0U; i < nbytes && (i < left_bytes && (*status).__variant == Failure == 0); i = i + 1U) {
                    
                    *status = enqueue(&self->uart_tx_queue,
                                      output_bytes[__termina_array__index(nbytes,
                                                                          i + sent_bytes)]);

                }

            } else {
                
                (*status).__variant = Failure;
                (*status).Failure.__0 = TM_SEND_FAILURE;

            }

        }

    }

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

_Bool UARTDriver__tf_is_full(const __termina_event_t * const __ev,
                             const UARTDriver * const self) {
    
    uint32_t riscv_uart_tf = 0x200U;

    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}
