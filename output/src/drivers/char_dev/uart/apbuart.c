
#include "drivers/char_dev/uart/apbuart.h"

const size_t hw_fifo_size = 1U;

void CAPBUARTDriver__disable_RF(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 161 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    #line 162 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control & riscv_uart_rf;

    #line 163 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__disable_TF(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 151 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    #line 152 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control & riscv_uart_tf;

    #line 153 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__disable_TI(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 141 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_ti = 0xFFFFFFF7U;

    #line 142 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control & riscv_uart_ti;

    #line 143 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__enable_RI(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 121 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 122 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control | riscv_uart_ri;

    #line 123 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__enable_RX(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 111 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 112 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control | riscv_uart_rxe;

    #line 113 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__enable_TI(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 131 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_ti = 0x8U;

    #line 132 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control | riscv_uart_ti;

    #line 133 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__enable_TX(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 101 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 102 "src/drivers/char_dev/uart/apbuart.fin"
    self->registers->control = self->registers->control | riscv_uart_txe;

    #line 103 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__initialize(const __termina_event_t * const __ev, void * const __this) {
    
    #line 327 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver * self = (CAPBUARTDriver *)__this;

    #line 327 "src/drivers/char_dev/uart/apbuart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 329 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver__enable_RX(__ev, self);

    #line 330 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver__enable_TX(__ev, self);

    #line 331 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver__enable_RI(__ev, self);

    #line 332 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver__enable_TI(__ev, self);

    #line 333 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver__disable_TF(__ev, self);

    #line 334 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver__disable_RF(__ev, self);

    #line 336 "src/drivers/char_dev/uart/apbuart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 336 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__release_tx(const __termina_event_t * const __ev, CAPBUARTDriver * const self) {
    
    #line 197 "src/drivers/char_dev/uart/apbuart.fin"
    if (self->rem_bytes) {
        
        #line 199 "src/drivers/char_dev/uart/apbuart.fin"
        size_t num_elements = 0U;

        #line 201 "src/drivers/char_dev/uart/apbuart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 203 "src/drivers/char_dev/uart/apbuart.fin"
        size_t sent_bytes = 0U;

        #line 204 "src/drivers/char_dev/uart/apbuart.fin"
        __option_uint8_t extracted_elem;
        #line 204 "src/drivers/char_dev/uart/apbuart.fin"
        extracted_elem.__variant = None;

        #line 206 "src/drivers/char_dev/uart/apbuart.fin"
        for (size_t i = 0U; i < hw_fifo_size; i = i + 1U) {
            
            #line 208 "src/drivers/char_dev/uart/apbuart.fin"
            dequeue(&self->uart_tx_queue, &extracted_elem);

            #line 211 "src/drivers/char_dev/uart/apbuart.fin"
            if (extracted_elem.__variant == Some) {
                
                #line 211 "src/drivers/char_dev/uart/apbuart.fin"
                uint8_t elem = extracted_elem.Some.__0;

                #line 212 "src/drivers/char_dev/uart/apbuart.fin"
                self->registers->data = (uint32_t)elem;

                #line 213 "src/drivers/char_dev/uart/apbuart.fin"
                sent_bytes = sent_bytes + 1U;

            } else
            {
                

            }

        }

        #line 222 "src/drivers/char_dev/uart/apbuart.fin"
        if (sent_bytes < num_elements) {
            
            #line 224 "src/drivers/char_dev/uart/apbuart.fin"
            self->rem_bytes = 1;

        } else
        {
            
            #line 228 "src/drivers/char_dev/uart/apbuart.fin"
            self->rem_bytes = 0;

        }

    }

    #line 235 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

void CAPBUARTDriver__notify_irq(const __termina_event_t * const __ev, void * const __this, __result_bool__int32_t * const result) {
    
    #line 167 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver * self = (CAPBUARTDriver *)__this;

    #line 167 "src/drivers/char_dev/uart/apbuart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 169 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t uart_status = self->registers->status;

    #line 170 "src/drivers/char_dev/uart/apbuart.fin"
    (*result).__variant = Ok;
    #line 170 "src/drivers/char_dev/uart/apbuart.fin"
    (*result).Ok.__0 = 0;

    #line 172 "src/drivers/char_dev/uart/apbuart.fin"
    if ((uint32_t)(uart_status & 0x4U) != 0U) {
        
        #line 174 "src/drivers/char_dev/uart/apbuart.fin"
        CAPBUARTDriver__release_tx(__ev, self);

    }

    #line 178 "src/drivers/char_dev/uart/apbuart.fin"
    if ((uint32_t)(uart_status & 0x1U) != 0U) {
        
        #line 180 "src/drivers/char_dev/uart/apbuart.fin"
        uint8_t byte = (uint8_t)self->registers->data;

        #line 181 "src/drivers/char_dev/uart/apbuart.fin"
        self->rx_queue.enqueue_rx(__ev, self->rx_queue.__that, byte, result);

    }

    #line 185 "src/drivers/char_dev/uart/apbuart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 185 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

_Bool CAPBUARTDriver__rf_data_ready(const __termina_event_t * const __ev, const CAPBUARTDriver * const self) {
    
    #line 92 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_rf = 0x1U;

    #line 93 "src/drivers/char_dev/uart/apbuart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_rf) != 0U;

}

_Bool CAPBUARTDriver__tf_is_empty(const __termina_event_t * const __ev, const CAPBUARTDriver * const self) {
    
    #line 82 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 83 "src/drivers/char_dev/uart/apbuart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void CAPBUARTDriver__send(const __termina_event_t * const __ev, void * const __this, const size_t nbytes, const uint8_t output_bytes[nbytes], __status_int32_t * const status) {
    
    #line 249 "src/drivers/char_dev/uart/apbuart.fin"
    CAPBUARTDriver * self = (CAPBUARTDriver *)__this;

    #line 249 "src/drivers/char_dev/uart/apbuart.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 253 "src/drivers/char_dev/uart/apbuart.fin"
    (*status).__variant = Success;

    #line 255 "src/drivers/char_dev/uart/apbuart.fin"
    if (self->rem_bytes) {
        
        #line 257 "src/drivers/char_dev/uart/apbuart.fin"
        size_t num_elements = 0U;

        #line 258 "src/drivers/char_dev/uart/apbuart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 260 "src/drivers/char_dev/uart/apbuart.fin"
        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            #line 262 "src/drivers/char_dev/uart/apbuart.fin"
            for (size_t i = 0U; i < nbytes && (*status).__variant == Failure == 0; i = i + 1U) {
                
                #line 264 "src/drivers/char_dev/uart/apbuart.fin"
                *status = enqueue(&self->uart_tx_queue, output_bytes[__termina_array__index(nbytes, i)]);

            }

        } else
        {
            
            #line 269 "src/drivers/char_dev/uart/apbuart.fin"
            (*status).__variant = Failure;
            #line 269 "src/drivers/char_dev/uart/apbuart.fin"
            (*status).Failure.__0 = TM_SEND_FAILURE;

        }

    } else
    {
        
        #line 274 "src/drivers/char_dev/uart/apbuart.fin"
        size_t sent_bytes = 0U;

        #line 276 "src/drivers/char_dev/uart/apbuart.fin"
        if (CAPBUARTDriver__tf_is_empty(__ev, self)) {
            
            #line 278 "src/drivers/char_dev/uart/apbuart.fin"
            for (size_t i = 0U; i < hw_fifo_size && i < nbytes; i = i + 1U) {
                
                #line 280 "src/drivers/char_dev/uart/apbuart.fin"
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(nbytes, i)];

                #line 282 "src/drivers/char_dev/uart/apbuart.fin"
                sent_bytes = sent_bytes + 1U;

            }

        }

        #line 288 "src/drivers/char_dev/uart/apbuart.fin"
        if (sent_bytes < nbytes) {
            
            #line 290 "src/drivers/char_dev/uart/apbuart.fin"
            self->rem_bytes = 1;

            #line 292 "src/drivers/char_dev/uart/apbuart.fin"
            size_t left_bytes = nbytes - sent_bytes;

            #line 293 "src/drivers/char_dev/uart/apbuart.fin"
            size_t num_elements = 0U;

            #line 295 "src/drivers/char_dev/uart/apbuart.fin"
            get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

            #line 297 "src/drivers/char_dev/uart/apbuart.fin"
            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                #line 299 "src/drivers/char_dev/uart/apbuart.fin"
                for (size_t i = 0U; i < nbytes && (i < left_bytes && (*status).__variant == Failure == 0); i = i + 1U) {
                    
                    #line 301 "src/drivers/char_dev/uart/apbuart.fin"
                    *status = enqueue(&self->uart_tx_queue, output_bytes[__termina_array__index(nbytes, i + sent_bytes)]);

                }

            } else
            {
                
                #line 308 "src/drivers/char_dev/uart/apbuart.fin"
                (*status).__variant = Failure;
                #line 308 "src/drivers/char_dev/uart/apbuart.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            }

        }

    }

    #line 316 "src/drivers/char_dev/uart/apbuart.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 316 "src/drivers/char_dev/uart/apbuart.fin"
    return;

}

_Bool CAPBUARTDriver__tf_is_full(const __termina_event_t * const __ev, const CAPBUARTDriver * const self) {
    
    #line 72 "src/drivers/char_dev/uart/apbuart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 73 "src/drivers/char_dev/uart/apbuart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}
