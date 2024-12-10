
#include "resources/uart.h"

void UARTDriver__disable_RF(UARTDriver * const self) {
    
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    self->registers->control = self->registers->control & riscv_uart_rf;

    return;

}

void UARTDriver__disable_TF(UARTDriver * const self) {
    
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    self->registers->control = self->registers->control & riscv_uart_tf;

    return;

}

void UARTDriver__enable_RI(UARTDriver * const self) {
    
    uint32_t riscv_uart_ri = 0x4U;

    self->registers->control = self->registers->control | riscv_uart_ri;

    return;

}

void UARTDriver__enable_RX(UARTDriver * const self) {
    
    uint32_t riscv_uart_rxe = 0x1U;

    self->registers->control = self->registers->control | riscv_uart_rxe;

    return;

}

void UARTDriver__enable_TI(UARTDriver * const self) {
    
    uint32_t riscv_uart_ti = 0x8U;

    self->registers->control = self->registers->control | riscv_uart_ti;

    return;

}

void UARTDriver__enable_TX(UARTDriver * const self) {
    
    uint32_t riscv_uart_txe = 0x2U;

    self->registers->control = self->registers->control | riscv_uart_txe;

    return;

}

void UARTDriver__initialize(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_resource__lock(&self->__resource);

    UARTDriver__enable_RX(self);

    UARTDriver__enable_TX(self);

    UARTDriver__enable_RI(self);

    UARTDriver__enable_TI(self);

    UARTDriver__disable_TF(self);

    UARTDriver__disable_RF(self);

    __termina_resource__unlock(&self->__resource);

    return;

}

void UARTDriver__release_tx(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_resource__lock(&self->__resource);

    if (self->rem_bytes) {
        
        size_t num_elements = 0U;

        get_num_enqueued_elems(&self->uart_queue, &num_elements);

        size_t sent_bytes = 0U;

        __option_uint8_t extracted_elem;
        extracted_elem.__variant = None;

        for (size_t i = 0U; i < 4U && sent_bytes < num_elements; i = i + 1U) {
            
            dequeue(&self->uart_queue, &extracted_elem);

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

    __termina_resource__unlock(&self->__resource);

    return;

}

_Bool UARTDriver__tf_is_empty(const UARTDriver * const self) {
    
    uint32_t riscv_uart_te = 0x4U;

    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(void * const __this,
                      const uint8_t output_bytes[max_send_size], size_t nbytes,
                      CharDevResult * const result) {
    
    UARTDriver * self = (UARTDriver *)__this;

    __termina_resource__lock(&self->__resource);

    (*result).__variant = CharDevResult__Success;

    if (self->rem_bytes) {
        
        size_t num_elements = 0U;

        get_num_enqueued_elems(&self->uart_queue, &num_elements);

        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            QueueResult inner_queue_result;
            inner_queue_result.__variant = QueueResult__Success;

            size_t queued_bytes = 0U;

            _Bool error = 0;

            for (size_t i = 0U; i < max_send_size && (queued_bytes < nbytes && error == 0); i = i + 1U) {
                
                inner_queue_result = enqueue(&self->uart_queue,
                                             output_bytes[i]);

                if (inner_queue_result.__variant == QueueResult__QueueFull) {
                    
                    error = 1;

                    (*result).__variant = CharDevResult__TXFIFOFull;

                } else {
                    
                    queued_bytes = queued_bytes + 1U;

                }

            }

        } else {
            
            (*result).__variant = CharDevResult__TXFIFOFull;

        }

    } else {
        
        size_t sent_bytes = 0U;

        if (UARTDriver__tf_is_empty(self)) {
            
            for (size_t i = 0U; i < 4U && sent_bytes < nbytes; i = i + 1U) {
                
                self->registers->data = (uint32_t)output_bytes[i];

                sent_bytes = sent_bytes + 1U;

            }

        }

        if (sent_bytes < nbytes) {
            
            self->rem_bytes = 1;

            size_t left_bytes = nbytes - sent_bytes;

            size_t num_elements = 0U;

            get_num_enqueued_elems(&self->uart_queue, &num_elements);

            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                QueueResult inner_queue_result;
                inner_queue_result.__variant = QueueResult__Success;

                _Bool error = 0;

                for (size_t i = 0U; i < max_send_size && (i < left_bytes && error == 0); i = i + 1U) {
                    
                    inner_queue_result = enqueue(&self->uart_queue,
                                                 output_bytes[i + sent_bytes]);

                    if (inner_queue_result.__variant == QueueResult__QueueFull) {
                        
                        error = 1;

                        (*result).__variant = CharDevResult__TXFIFOFull;

                    } else {
                        

                    }

                }

            } else {
                
                (*result).__variant = CharDevResult__TXFIFOFull;

            }

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

_Bool UARTDriver__tf_is_full(const UARTDriver * const self) {
    
    uint32_t riscv_uart_tf = 0x200U;

    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}
