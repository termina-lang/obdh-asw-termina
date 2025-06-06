
#include "resources/uart.h"

void UARTDriver__disable_RF(UARTDriver * const self) {
    
    #line 129 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    #line 130 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_rf;

    #line 131 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TF(UARTDriver * const self) {
    
    #line 123 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    #line 124 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_tf;

    #line 125 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RI(UARTDriver * const self) {
    
    #line 111 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 112 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ri;

    #line 113 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RX(UARTDriver * const self) {
    
    #line 105 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 106 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_rxe;

    #line 107 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TI(UARTDriver * const self) {
    
    #line 117 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0x8U;

    #line 118 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ti;

    #line 119 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TX(UARTDriver * const self) {
    
    #line 99 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 100 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_txe;

    #line 101 "src/resources/uart.fin"
    return;

}

_Bool UARTDriver__rf_data_ready(const UARTDriver * const self) {
    
    #line 93 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0x1U;

    #line 94 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_rf) != 0U;

}

void UARTDriver__enqueue_rx(void * const __this,
                            __option_size_t * const tc_completed) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 145 "src/resources/uart.fin"
    __status_int32_t status;
    #line 145 "src/resources/uart.fin"
    status.__variant = Success;

    #line 146 "src/resources/uart.fin"
    (*tc_completed).__variant = None;

    #line 148 "src/resources/uart.fin"
    for (size_t i = 0U; i < queue_max_noe && (is_full(&self->uart_rx_queue) == 0 && UARTDriver__rf_data_ready(self) && status.__variant == Failure == 0 && self->rx_status.__variant == RXStatus__FinishedTCRx == 0); i = i + 1U) {
        
        #line 154 "src/resources/uart.fin"
        uint8_t byte = (uint8_t)self->registers->data;

        #line 158 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__SyncBytesRx) {
            
            #line 160 "src/resources/uart.fin"
            if (byte == self->sync_word[__termina_array__index(4U,
                                                               self->aux_index)]) {
                
                #line 162 "src/resources/uart.fin"
                if (3U == self->aux_index) {
                    
                    #line 163 "src/resources/uart.fin"
                    self->aux_index = 0U;

                    #line 164 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__SyncLengthRx;

                } else
                {
                    
                    #line 166 "src/resources/uart.fin"
                    self->aux_index = self->aux_index + 1U;

                }

            } else
            {
                
                #line 170 "src/resources/uart.fin"
                self->aux_index = 0U;

            }

        } else
        #line 174 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__SyncLengthRx) {
            
            #line 176 "src/resources/uart.fin"
            self->raw_rx_tc_length[__termina_array__index(2U,
                                                          self->aux_index)] = byte;

            #line 177 "src/resources/uart.fin"
            self->aux_index = self->aux_index + 1U;

            #line 179 "src/resources/uart.fin"
            if (2U == self->aux_index) {
                
                #line 181 "src/resources/uart.fin"
                self->tc_num_bytes = (size_t)deserialize_uint16(self->raw_rx_tc_length);

                #line 183 "src/resources/uart.fin"
                if (self->tc_num_bytes < 256U) {
                    
                    #line 185 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__TCBytesRx;

                } else
                {
                    
                    #line 189 "src/resources/uart.fin"
                    self->rx_status.__variant = RXStatus__SyncBytesRx;

                }

                #line 192 "src/resources/uart.fin"
                self->aux_index = 0U;

            }

        } else
        #line 197 "src/resources/uart.fin"
        if (self->rx_status.__variant == RXStatus__TCBytesRx) {
            
            #line 199 "src/resources/uart.fin"
            status = enqueue(&self->uart_rx_queue, byte);

            #line 200 "src/resources/uart.fin"
            self->aux_index = self->aux_index + 1U;

            #line 202 "src/resources/uart.fin"
            if (self->aux_index == self->tc_num_bytes) {
                
                #line 204 "src/resources/uart.fin"
                self->rx_status.__variant = RXStatus__FinishedTCRx;

            }

        } else
        {
            

        }

    }

    #line 215 "src/resources/uart.fin"
    if (self->rx_status.__variant == RXStatus__FinishedTCRx) {
        
        #line 217 "src/resources/uart.fin"
        (*tc_completed).__variant = Some;
        #line 217 "src/resources/uart.fin"
        (*tc_completed).Some.__0 = self->tc_num_bytes;

        #line 218 "src/resources/uart.fin"
        self->rx_status.__variant = RXStatus__SyncBytesRx;

        #line 219 "src/resources/uart.fin"
        self->aux_index = 0U;

    }

    #line 223 "src/resources/uart.fin"
    return;

}

void UARTDriver__enqueue_rx__mutex_lock(void * const __this,
                                        __option_size_t * const tc_completed) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__enqueue_rx(self, tc_completed);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__enqueue_rx__task_lock(void * const __this,
                                       __option_size_t * const tc_completed) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__enqueue_rx(__this, tc_completed);
    __termina_task__unlock(lock);

}

void UARTDriver__enqueue_rx__event_lock(void * const __this,
                                        __option_size_t * const tc_completed) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__enqueue_rx(__this, tc_completed);
    __termina_event__unlock(lock);

}

void UARTDriver__initialize(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 343 "src/resources/uart.fin"
    UARTDriver__enable_RX(self);

    #line 344 "src/resources/uart.fin"
    UARTDriver__enable_TX(self);

    #line 345 "src/resources/uart.fin"
    UARTDriver__enable_RI(self);

    #line 346 "src/resources/uart.fin"
    UARTDriver__enable_TI(self);

    #line 347 "src/resources/uart.fin"
    UARTDriver__disable_TF(self);

    #line 348 "src/resources/uart.fin"
    UARTDriver__disable_RF(self);

    #line 350 "src/resources/uart.fin"
    return;

}

void UARTDriver__initialize__mutex_lock(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__initialize(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__initialize__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__initialize(__this);
    __termina_task__unlock(lock);

}

void UARTDriver__initialize__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__initialize(__this);
    __termina_event__unlock(lock);

}

void UARTDriver__receive(void * const __this, __option_uint8_t * const byte) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 137 "src/resources/uart.fin"
    dequeue(&self->uart_rx_queue, byte);

    #line 139 "src/resources/uart.fin"
    return;

}

void UARTDriver__receive__mutex_lock(void * const __this,
                                     __option_uint8_t * const byte) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__receive(self, byte);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__receive__task_lock(void * const __this,
                                    __option_uint8_t * const byte) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__receive(__this, byte);
    __termina_task__unlock(lock);

}

void UARTDriver__receive__event_lock(void * const __this,
                                     __option_uint8_t * const byte) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__receive(__this, byte);
    __termina_event__unlock(lock);

}

_Bool UARTDriver__tf_is_full(const UARTDriver * const self) {
    
    #line 83 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 84 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}

void UARTDriver__release_tx(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 230 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 232 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 234 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 236 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 237 "src/resources/uart.fin"
        __option_uint8_t extracted_elem;
        #line 237 "src/resources/uart.fin"
        extracted_elem.__variant = None;

        #line 239 "src/resources/uart.fin"
        for (size_t i = 0U; i < queue_max_noe && (sent_bytes < num_elements && UARTDriver__tf_is_full(self) == 0); i = i + 1U) {
            
            #line 242 "src/resources/uart.fin"
            dequeue(&self->uart_tx_queue, &extracted_elem);

            #line 245 "src/resources/uart.fin"
            if (extracted_elem.__variant == Some) {
                
                #line 244 "src/resources/uart.fin"
                uint8_t elem = extracted_elem.Some.__0;

                #line 246 "src/resources/uart.fin"
                self->registers->data = (uint32_t)elem;

                #line 247 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            } else
            {
                

            }

        }

        #line 256 "src/resources/uart.fin"
        if (sent_bytes < num_elements) {
            
            #line 258 "src/resources/uart.fin"
            self->rem_bytes = 1;

        } else
        {
            
            #line 262 "src/resources/uart.fin"
            self->rem_bytes = 0;

        }

    }

    #line 268 "src/resources/uart.fin"
    return;

}

void UARTDriver__release_tx__mutex_lock(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__release_tx(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__release_tx__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__release_tx(__this);
    __termina_task__unlock(lock);

}

void UARTDriver__release_tx__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__release_tx(__this);
    __termina_event__unlock(lock);

}

_Bool UARTDriver__tf_is_empty(const UARTDriver * const self) {
    
    #line 88 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 89 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(void * const __this, const size_t nbytes,
                      const uint8_t output_bytes[nbytes],
                      __status_int32_t * const status) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 275 "src/resources/uart.fin"
    (*status).__variant = Success;

    #line 277 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 279 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 280 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

        #line 282 "src/resources/uart.fin"
        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            #line 284 "src/resources/uart.fin"
            for (size_t i = 0U; i < nbytes && (*status).__variant == Failure == 0; i = i + 1U) {
                
                #line 286 "src/resources/uart.fin"
                *status = enqueue(&self->uart_tx_queue,
                                  output_bytes[__termina_array__index(nbytes,
                                                                      i)]);

            }

        } else
        {
            
            #line 291 "src/resources/uart.fin"
            (*status).__variant = Failure;
            #line 291 "src/resources/uart.fin"
            (*status).Failure.__0 = TM_SEND_FAILURE;

        }

    } else
    {
        
        #line 296 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 298 "src/resources/uart.fin"
        if (UARTDriver__tf_is_empty(self)) {
            
            #line 300 "src/resources/uart.fin"
            for (size_t i = 0U; i < nbytes && UARTDriver__tf_is_full(self) == 0; i = i + 1U) {
                
                #line 302 "src/resources/uart.fin"
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(nbytes,
                                                                                      i)];

                #line 303 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            }

        }

        #line 309 "src/resources/uart.fin"
        if (sent_bytes < nbytes) {
            
            #line 311 "src/resources/uart.fin"
            self->rem_bytes = 1;

            #line 313 "src/resources/uart.fin"
            size_t left_bytes = nbytes - sent_bytes;

            #line 314 "src/resources/uart.fin"
            size_t num_elements = 0U;

            #line 316 "src/resources/uart.fin"
            get_num_enqueued_elems(&self->uart_tx_queue, &num_elements);

            #line 318 "src/resources/uart.fin"
            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                #line 320 "src/resources/uart.fin"
                for (size_t i = 0U; i < nbytes && (i < left_bytes && (*status).__variant == Failure == 0); i = i + 1U) {
                    
                    #line 322 "src/resources/uart.fin"
                    *status = enqueue(&self->uart_tx_queue,
                                      output_bytes[__termina_array__index(nbytes,
                                                                          i + sent_bytes)]);

                }

            } else
            {
                
                #line 328 "src/resources/uart.fin"
                (*status).__variant = Failure;
                #line 328 "src/resources/uart.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            }

        }

    }

    #line 336 "src/resources/uart.fin"
    return;

}

void UARTDriver__send__mutex_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const status) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__send(self, nbytes, output_bytes, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__send__task_lock(void * const __this, const size_t nbytes,
                                 const uint8_t output_bytes[nbytes],
                                 __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__send(__this, nbytes, output_bytes, status);
    __termina_task__unlock(lock);

}

void UARTDriver__send__event_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__send(__this, nbytes, output_bytes, status);
    __termina_event__unlock(lock);

}
