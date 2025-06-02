
#include "resources/uart.h"

void UARTDriver__disable_RF(UARTDriver * const self) {
    
    #line 96 "src/resources/uart.fin"
    uint32_t riscv_uart_rf = 0xFFFFFBFFU;

    #line 97 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_rf;

    #line 98 "src/resources/uart.fin"
    return;

}

void UARTDriver__disable_TF(UARTDriver * const self) {
    
    #line 90 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0xFFFFFCFFU;

    #line 91 "src/resources/uart.fin"
    self->registers->control = self->registers->control & riscv_uart_tf;

    #line 92 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RI(UARTDriver * const self) {
    
    #line 78 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 79 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ri;

    #line 80 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_RX(UARTDriver * const self) {
    
    #line 72 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 73 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_rxe;

    #line 74 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TI(UARTDriver * const self) {
    
    #line 84 "src/resources/uart.fin"
    uint32_t riscv_uart_ti = 0x8U;

    #line 85 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_ti;

    #line 86 "src/resources/uart.fin"
    return;

}

void UARTDriver__enable_TX(UARTDriver * const self) {
    
    #line 66 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 67 "src/resources/uart.fin"
    self->registers->control = self->registers->control | riscv_uart_txe;

    #line 68 "src/resources/uart.fin"
    return;

}

void UARTDriver__initialize(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 223 "src/resources/uart.fin"
    UARTDriver__enable_RX(self);

    #line 224 "src/resources/uart.fin"
    UARTDriver__enable_TX(self);

    #line 225 "src/resources/uart.fin"
    UARTDriver__enable_RI(self);

    #line 226 "src/resources/uart.fin"
    UARTDriver__enable_TI(self);

    #line 227 "src/resources/uart.fin"
    UARTDriver__disable_TF(self);

    #line 228 "src/resources/uart.fin"
    UARTDriver__disable_RF(self);

    #line 230 "src/resources/uart.fin"
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

_Bool UARTDriver__tf_is_full(const UARTDriver * const self) {
    
    #line 55 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 56 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_tf) != 0U;

}

void UARTDriver__release_tx(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 104 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 106 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 108 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_queue, &num_elements);

        #line 110 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 111 "src/resources/uart.fin"
        __option_uint8_t extracted_elem;
        #line 111 "src/resources/uart.fin"
        extracted_elem.__variant = None;

        #line 113 "src/resources/uart.fin"
        for (size_t i = 0U; i < queue_max_noe && (sent_bytes < num_elements && UARTDriver__tf_is_full(self) == 0); i = i + 1U) {
            
            #line 116 "src/resources/uart.fin"
            dequeue(&self->uart_queue, &extracted_elem);

            #line 119 "src/resources/uart.fin"
            if (extracted_elem.__variant == Some) {
                
                #line 118 "src/resources/uart.fin"
                uint8_t elem = extracted_elem.Some.__0;

                #line 120 "src/resources/uart.fin"
                self->registers->data = (uint32_t)elem;

                #line 121 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            } else
            {
                

            }

        }

        #line 132 "src/resources/uart.fin"
        if (sent_bytes < num_elements) {
            
            #line 134 "src/resources/uart.fin"
            self->rem_bytes = 1;

        } else
        {
            
            #line 138 "src/resources/uart.fin"
            self->rem_bytes = 0;

        }

    }

    #line 144 "src/resources/uart.fin"
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
    
    #line 60 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 61 "src/resources/uart.fin"
    return (uint32_t)(self->registers->status & riscv_uart_te) != 0U;

}

void UARTDriver__send(void * const __this, const size_t nbytes,
                      const uint8_t output_bytes[nbytes],
                      __status_int32_t * const result) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 151 "src/resources/uart.fin"
    (*result).__variant = Success;

    #line 153 "src/resources/uart.fin"
    if (self->rem_bytes) {
        
        #line 155 "src/resources/uart.fin"
        size_t num_elements = 0U;

        #line 156 "src/resources/uart.fin"
        get_num_enqueued_elems(&self->uart_queue, &num_elements);

        #line 158 "src/resources/uart.fin"
        if ((size_t)(queue_max_noe - num_elements) >= nbytes) {
            
            #line 160 "src/resources/uart.fin"
            size_t queued_bytes = 0U;

            #line 162 "src/resources/uart.fin"
            for (size_t i = 0U; i < nbytes && (queued_bytes < nbytes && (*result).__variant == Failure == 0); i = i + 1U) {
                
                #line 164 "src/resources/uart.fin"
                *result = enqueue(&self->uart_queue,
                                  output_bytes[__termina_array__index(nbytes,
                                                                      i)]);

                #line 166 "src/resources/uart.fin"
                if ((*result).__variant == Failure == 0) {
                    
                    #line 167 "src/resources/uart.fin"
                    queued_bytes = queued_bytes + 1U;

                }

            }

        } else
        {
            
            #line 173 "src/resources/uart.fin"
            (*result).__variant = Failure;
            #line 173 "src/resources/uart.fin"
            (*result).Failure.__0 = -(1L);

        }

    } else
    {
        
        #line 178 "src/resources/uart.fin"
        size_t sent_bytes = 0U;

        #line 180 "src/resources/uart.fin"
        if (UARTDriver__tf_is_empty(self)) {
            
            #line 182 "src/resources/uart.fin"
            for (size_t i = 0U; i < nbytes && UARTDriver__tf_is_full(self) == 0; i = i + 1U) {
                
                #line 184 "src/resources/uart.fin"
                self->registers->data = (uint32_t)output_bytes[__termina_array__index(nbytes,
                                                                                      i)];

                #line 185 "src/resources/uart.fin"
                sent_bytes = sent_bytes + 1U;

            }

        }

        #line 191 "src/resources/uart.fin"
        if (sent_bytes < nbytes) {
            
            #line 193 "src/resources/uart.fin"
            self->rem_bytes = 1;

            #line 195 "src/resources/uart.fin"
            size_t left_bytes = nbytes - sent_bytes;

            #line 196 "src/resources/uart.fin"
            size_t num_elements = 0U;

            #line 198 "src/resources/uart.fin"
            get_num_enqueued_elems(&self->uart_queue, &num_elements);

            #line 200 "src/resources/uart.fin"
            if ((size_t)(queue_max_noe - num_elements) >= left_bytes) {
                
                #line 202 "src/resources/uart.fin"
                for (size_t i = 0U; i < nbytes && (i < left_bytes && (*result).__variant == Failure == 0); i = i + 1U) {
                    
                    #line 204 "src/resources/uart.fin"
                    *result = enqueue(&self->uart_queue,
                                      output_bytes[__termina_array__index(nbytes,
                                                                          i + sent_bytes)]);

                }

            } else
            {
                
                #line 210 "src/resources/uart.fin"
                (*result).__variant = Failure;
                #line 210 "src/resources/uart.fin"
                (*result).Failure.__0 = -(1L);

            }

        }

    }

    #line 217 "src/resources/uart.fin"
    return;

}

void UARTDriver__send__mutex_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const result) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__send(self, nbytes, output_bytes, result);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__send__task_lock(void * const __this, const size_t nbytes,
                                 const uint8_t output_bytes[nbytes],
                                 __status_int32_t * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__send(__this, nbytes, output_bytes, result);
    __termina_task__unlock(lock);

}

void UARTDriver__send__event_lock(void * const __this, const size_t nbytes,
                                  const uint8_t output_bytes[nbytes],
                                  __status_int32_t * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__send(__this, nbytes, output_bytes, result);
    __termina_event__unlock(lock);

}
