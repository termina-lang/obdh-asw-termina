
#include "resources/uart.h"

void UARTDriver__getchar(void * const __this,
                         __option_uint8_t * const uart_data) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 153 "src/resources/uart.fin"
    uint32_t riscv_uart_dr = 0x1U;

    #line 155 "src/resources/uart.fin"
    if ((uint32_t)(self->uart_regs->status & riscv_uart_dr) != 0U) {
        
        #line 156 "src/resources/uart.fin"
        (*uart_data).__variant = Some;
        #line 156 "src/resources/uart.fin"
        (*uart_data).Some.__0 = (uint8_t)self->uart_regs->data;

    } else
    {
        
        #line 159 "src/resources/uart.fin"
        (*uart_data).__variant = None;

    }

    #line 162 "src/resources/uart.fin"
    return;

}

void UARTDriver__getchar__mutex_lock(void * const __this,
                                     __option_uint8_t * const uart_data) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__getchar(self, uart_data);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__getchar__task_lock(void * const __this,
                                    __option_uint8_t * const uart_data) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__getchar(__this, uart_data);
    __termina_task__unlock(lock);

}

void UARTDriver__getchar__event_lock(void * const __this,
                                     __option_uint8_t * const uart_data) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__getchar(__this, uart_data);
    __termina_event__unlock(lock);

}

_Bool UARTDriver__uart_tf_is_full(const UARTDriver * const self) {
    
    #line 75 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 76 "src/resources/uart.fin"
    return (uint32_t)(self->uart_regs->status & riscv_uart_tf) != 0U;

}

void UARTDriver__putchar(void * const __this, uint8_t c,
                         __status_int32_t * const status) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 126 "src/resources/uart.fin"
    uint32_t write_timeout = 0U;

    #line 128 "src/resources/uart.fin"
    (*status).__variant = Failure;
    #line 128 "src/resources/uart.fin"
    (*status).Failure.__0 = -(1L);

    #line 130 "src/resources/uart.fin"
    for (uint32_t i = 0U; i < 0xAAAAAU && UARTDriver__uart_tf_is_full(self); i = i + 1U) {
        
        #line 132 "src/resources/uart.fin"
        write_timeout = write_timeout + 1U;

    }

    #line 136 "src/resources/uart.fin"
    if (write_timeout < 0xAAAAAU) {
        
        #line 137 "src/resources/uart.fin"
        self->uart_regs->data = (uint32_t)c;

        #line 138 "src/resources/uart.fin"
        (*status).__variant = Success;

    }

    #line 141 "src/resources/uart.fin"
    return;

}

void UARTDriver__putchar__mutex_lock(void * const __this, uint8_t c,
                                     __status_int32_t * const status) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__putchar(self, c, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__putchar__task_lock(void * const __this, uint8_t c,
                                    __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__putchar(__this, c, status);
    __termina_task__unlock(lock);

}

void UARTDriver__putchar__event_lock(void * const __this, uint8_t c,
                                     __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__putchar(__this, c, status);
    __termina_event__unlock(lock);

}

void UARTDriver__uart_enable_RI(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 112 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 113 "src/resources/uart.fin"
    self->uart_regs->control = self->uart_regs->control | riscv_uart_ri;

    #line 114 "src/resources/uart.fin"
    return;

}

void UARTDriver__uart_enable_RI__mutex_lock(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__uart_enable_RI(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__uart_enable_RI__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__uart_enable_RI(__this);
    __termina_task__unlock(lock);

}

void UARTDriver__uart_enable_RI__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__uart_enable_RI(__this);
    __termina_event__unlock(lock);

}

void UARTDriver__uart_enable_RX(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 103 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 104 "src/resources/uart.fin"
    self->uart_regs->control = self->uart_regs->control | riscv_uart_rxe;

    #line 105 "src/resources/uart.fin"
    return;

}

void UARTDriver__uart_enable_RX__mutex_lock(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__uart_enable_RX(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__uart_enable_RX__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__uart_enable_RX(__this);
    __termina_task__unlock(lock);

}

void UARTDriver__uart_enable_RX__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__uart_enable_RX(__this);
    __termina_event__unlock(lock);

}

void UARTDriver__uart_enable_TX(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 94 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 95 "src/resources/uart.fin"
    self->uart_regs->control = self->uart_regs->control | riscv_uart_txe;

    #line 96 "src/resources/uart.fin"
    return;

}

void UARTDriver__uart_enable_TX__mutex_lock(void * const __this) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__uart_enable_TX(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__uart_enable_TX__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__uart_enable_TX(__this);
    __termina_task__unlock(lock);

}

void UARTDriver__uart_enable_TX__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__uart_enable_TX(__this);
    __termina_event__unlock(lock);

}

void UARTDriver__uart_tf_is_empty(void * const __this, _Bool * const res) {
    
    UARTDriver * self = (UARTDriver *)__this;

    #line 85 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 86 "src/resources/uart.fin"
    *res = (uint32_t)(self->uart_regs->status & riscv_uart_te) != 0U;

    #line 87 "src/resources/uart.fin"
    return;

}

void UARTDriver__uart_tf_is_empty__mutex_lock(void * const __this,
                                              _Bool * const res) {
    
    UARTDriver * self = (UARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    UARTDriver__uart_tf_is_empty(self, res);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void UARTDriver__uart_tf_is_empty__task_lock(void * const __this,
                                             _Bool * const res) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    UARTDriver__uart_tf_is_empty(__this, res);
    __termina_task__unlock(lock);

}

void UARTDriver__uart_tf_is_empty__event_lock(void * const __this,
                                              _Bool * const res) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    UARTDriver__uart_tf_is_empty(__this, res);
    __termina_event__unlock(lock);

}
