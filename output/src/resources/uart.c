
#include "resources/uart.h"

void UARTDriver__disable_RF(UARTDriver * const self) {
    
    #line 90 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    #line 91 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_rf;

    #line 92 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TF(UARTDriver * const self) {
    
    #line 84 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    #line 85 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_tf;

    #line 86 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RI(UARTDriver * const self) {
    
    #line 72 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 73 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ri;

    #line 74 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RX(UARTDriver * const self) {
    
    #line 66 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 67 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_rxe;

    #line 68 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TI(UARTDriver * const self) {
    
    #line 78 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0x8U;

    #line 79 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ti;

    #line 80 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TX(UARTDriver * const self) {
    
    #line 59 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 60 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_txe;

    #line 61 "src/resources/uart.fin"
    return;

}

void UARTDriver__initialize(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 242 "src/resources/uart.fin"
    UARTDriver__enable_RX(self);

    #line 243 "src/resources/uart.fin"
    UARTDriver__enable_TX(self);

    #line 244 "src/resources/uart.fin"
    UARTDriver__enable_RI(self);

    #line 245 "src/resources/uart.fin"
    UARTDriver__enable_TI(self);

    #line 246 "src/resources/uart.fin"
    UARTDriver__disable_TF(self);

    #line 247 "src/resources/uart.fin"
    UARTDriver__disable_RF(self);

    #line 249 "src/resources/uart.fin"
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

void UARTDriver__release_tx(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 98 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 100 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 102 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_queue, &num_elements);

        #line 104 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 105 "src/resources/uart.fin"
        __option_uint8_t extracted_elem;
        #line 105 "src/resources/uart.fin"
        extracted_elem.__variant = None;

        #line 109 "src/resources/uart.fin"
        for (size_t i = 0U; i < 4U && sent_bytes < num_elements; i = i + 1U) {
            
            #line 111 "src/resources/uart.fin"
            dequeue(&self->uart_queue, &extracted_elem);

            #line 114 "src/resources/uart.fin"
            if (extracted_elem.__variant == Some) {
                
                #line 113 "src/resources/uart.fin"
                uint8_t elem = extracted_elem.Some.__0;

                #line 115 "src/resources/uart.fin"
                self->registers->data = (uint32_t)elem;

                #line 116 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            } else
            {
                

            }

        }

        #line 127 "src/resources/uart.fin"
        if (sent_bytes < num_elements) {
            
            #line 129 "src/resources/uart.fin"
            self->rem_bytes = 1;

        } else
        {
            
            #line 133 "src/resources/uart.fin"
            self->rem_bytes = 0;

        }

    }

    #line 139 "src/resources/uart.fin"
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
    
    #line 53 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 54 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(void * const __this, const uint8_t output_bytes[256U],
                      size_t nbytes, CharDevResult * const result) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 146 "src/resources/uart.fin"
    (*result).__variant = CharDevResult__Success;

    #line 148 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 150 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 151 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_queue, &num_elements);

        #line 153 "src/resources/uart.fin"
        if ((size_t)(1024U - num_elements) >= nbytes) {
            
            #line 155 "src/resources/uart.fin"
            QueueResult inner_queue_result;
            #line 155 "src/resources/uart.fin"
            inner_queue_result.__variant = QueueResult__Success;

            #line 156 "src/resources/uart.fin"
            size_t queued_bytes = 0U;

            #line 157 "src/resources/uart.fin"
            _Bool error = 0;

            #line 159 "src/resources/uart.fin"
            for (size_t i = 0U; i < 256U && (queued_bytes < nbytes && error == 0); i = i + 1U) {
                
                #line 161 "src/resources/uart.fin"
                inner_queue_result = enqueue(&self->uart_queue,
                                             output_bytes[__termina_array__index(256U,
                                                                                 i)]);

                #line 163 "src/resources/uart.fin"
                if (inner_queue_result.__variant == QueueResult__QueueFull) {
                    
                    #line 165 "src/resources/uart.fin"
                    error = 1;

                    #line 166 "src/resources/uart.fin"
                    (*result).__variant = CharDevResult__TXFIFOFull;

                } else
                {
                    
                    #line 169 "src/resources/uart.fin"
                    queued_bytes = queued_bytes + 1U;

                }

            }

        } else
        {
            
            #line 178 "src/resources/uart.fin"
            (*result).__variant = CharDevResult__TXFIFOFull;

        }

    } else
    {
        
        #line 185 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 187 "src/resources/uart.fin"
        if (UARTDriver__tf_is_empty(self)) {
            
            #line 189 "src/resources/uart.fin"
            for (size_t i = 0U; i < 4U && sent_bytes < nbytes; i = i + 1U) {
                
                #line 191 "src/resources/uart.fin"
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(256U,
                                                                                      i)];

                #line 192 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            }

        }

        #line 198 "src/resources/uart.fin"
        if (sent_bytes < nbytes) {
            
            #line 200 "src/resources/uart.fin"
            self->rem_bytes = 1;

            #line 202 "src/resources/uart.fin"
            size_t left_bytes = nbytes - sent_bytes;

            #line 203 "src/resources/uart.fin"
            size_t num_elements = 0U;

            #line 205 "src/resources/uart.fin"
            get_num_enqueued_elems(&self->uart_queue, &num_elements);

            #line 207 "src/resources/uart.fin"
            if ((size_t)(1024U - num_elements) >= left_bytes) {
                
                #line 209 "src/resources/uart.fin"
                QueueResult inner_queue_result;
                #line 209 "src/resources/uart.fin"
                inner_queue_result.__variant = QueueResult__Success;

                #line 210 "src/resources/uart.fin"
                _Bool error = 0;

                #line 212 "src/resources/uart.fin"
                for (size_t i = 0U; i < 256U && (i < left_bytes && error == 0); i = i + 1U) {
                    
                    #line 214 "src/resources/uart.fin"
                    inner_queue_result = enqueue(&self->uart_queue,
                                                 output_bytes[__termina_array__index(256U,
                                                                                     i + sent_bytes)]);

                    #line 216 "src/resources/uart.fin"
                    if (inner_queue_result.__variant == QueueResult__QueueFull) {
                        
                        #line 218 "src/resources/uart.fin"
                        error = 1;

                        #line 219 "src/resources/uart.fin"
                        (*result).__variant = CharDevResult__TXFIFOFull;

                    } else
                    {
                        

                    }

                }

            } else
            {
                
                #line 229 "src/resources/uart.fin"
                (*result).__variant = CharDevResult__TXFIFOFull;

            }

        }

    }

    #line 236 "src/resources/uart.fin"
    return;

}

void UARTDriver__send__mutex_lock(void * const __this,
                                  const uint8_t output_bytes[256U],
                                  size_t nbytes, CharDevResult * const result) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__send(self, output_bytes, nbytes, result);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__send__task_lock(void * const __this,
                                 const uint8_t output_bytes[256U],
                                 size_t nbytes, CharDevResult * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__send(__this, output_bytes, nbytes, result);
    __termina_task__unlock(lock);

}

void UARTDriver__send__event_lock(void * const __this,
                                  const uint8_t output_bytes[256U],
                                  size_t nbytes, CharDevResult * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__send(__this, output_bytes, nbytes, result);
    __termina_event__unlock(lock);

}

_Bool UARTDriver__tf_is_full(const UARTDriver * const self) {
    
    #line 48 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 49 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}
