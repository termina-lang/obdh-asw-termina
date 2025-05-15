
#include "resources/uart.h"

void CRISCVUARTDriver__riscv_getchar(void * const __this,
                                     __option_uint8_t * const uart_data) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    #line 87 "src/resources/uart.fin"
    uint32_t riscv_uart_dr = 0x1U;

    #line 89 "src/resources/uart.fin"
    if ((uint32_t)(self->uart_regs->status & riscv_uart_dr) != 0U) {
        
        #line 90 "src/resources/uart.fin"
        (*uart_data).__variant = Some;
        #line 90 "src/resources/uart.fin"
        (*uart_data).Some.__0 = (uint8_t)self->uart_regs->data;

    } else
    {
        
        #line 93 "src/resources/uart.fin"
        (*uart_data).__variant = None;

    }

    #line 96 "src/resources/uart.fin"
    return;

}

void CRISCVUARTDriver__riscv_getchar__mutex_lock(void * const __this,
                                                 __option_uint8_t * const uart_data) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    CRISCVUARTDriver__riscv_getchar(self, uart_data);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void CRISCVUARTDriver__riscv_getchar__task_lock(void * const __this,
                                                __option_uint8_t * const uart_data) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    CRISCVUARTDriver__riscv_getchar(__this, uart_data);
    __termina_task__unlock(lock);

}

void CRISCVUARTDriver__riscv_getchar__event_lock(void * const __this,
                                                 __option_uint8_t * const uart_data) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    CRISCVUARTDriver__riscv_getchar(__this, uart_data);
    __termina_event__unlock(lock);

}

_Bool CRISCVUARTDriver__riscv_uart_tf_is_full(const CRISCVUARTDriver * const self) {
    
    #line 33 "src/resources/uart.fin"
    uint32_t riscv_uart_tf = 0x200U;

    #line 34 "src/resources/uart.fin"
    return (uint32_t)(self->uart_regs->status & riscv_uart_tf) != 0U;

}

void CRISCVUARTDriver__riscv_putchar(void * const __this, uint8_t c,
                                     __status_int32_t * const status) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    #line 65 "src/resources/uart.fin"
    uint32_t write_timeout = 0U;

    #line 67 "src/resources/uart.fin"
    (*status).__variant = Failure;
    #line 67 "src/resources/uart.fin"
    (*status).Failure.__0 = -(1L);

    #line 69 "src/resources/uart.fin"
    for (uint32_t i = 0U; i < 0xAAAAAU && CRISCVUARTDriver__riscv_uart_tf_is_full(self); i = i + 1U) {
        
        #line 71 "src/resources/uart.fin"
        write_timeout = write_timeout + 1U;

    }

    #line 75 "src/resources/uart.fin"
    if (write_timeout < 0xAAAAAU) {
        
        #line 76 "src/resources/uart.fin"
        self->uart_regs->data = (uint32_t)c;

        #line 77 "src/resources/uart.fin"
        (*status).__variant = Success;

    }

    #line 80 "src/resources/uart.fin"
    return;

}

void CRISCVUARTDriver__riscv_putchar__mutex_lock(void * const __this, uint8_t c,
                                                 __status_int32_t * const status) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    CRISCVUARTDriver__riscv_putchar(self, c, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void CRISCVUARTDriver__riscv_putchar__task_lock(void * const __this, uint8_t c,
                                                __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    CRISCVUARTDriver__riscv_putchar(__this, c, status);
    __termina_task__unlock(lock);

}

void CRISCVUARTDriver__riscv_putchar__event_lock(void * const __this, uint8_t c,
                                                 __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    CRISCVUARTDriver__riscv_putchar(__this, c, status);
    __termina_event__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_enable_RI(void * const __this) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    #line 57 "src/resources/uart.fin"
    uint32_t riscv_uart_ri = 0x4U;

    #line 58 "src/resources/uart.fin"
    self->uart_regs->control = self->uart_regs->control | riscv_uart_ri;

    #line 59 "src/resources/uart.fin"
    return;

}

void CRISCVUARTDriver__riscv_uart_enable_RI__mutex_lock(void * const __this) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    CRISCVUARTDriver__riscv_uart_enable_RI(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void CRISCVUARTDriver__riscv_uart_enable_RI__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    CRISCVUARTDriver__riscv_uart_enable_RI(__this);
    __termina_task__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_enable_RI__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    CRISCVUARTDriver__riscv_uart_enable_RI(__this);
    __termina_event__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_enable_RX(void * const __this) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    #line 51 "src/resources/uart.fin"
    uint32_t riscv_uart_rxe = 0x1U;

    #line 52 "src/resources/uart.fin"
    self->uart_regs->control = self->uart_regs->control | riscv_uart_rxe;

    #line 53 "src/resources/uart.fin"
    return;

}

void CRISCVUARTDriver__riscv_uart_enable_RX__mutex_lock(void * const __this) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    CRISCVUARTDriver__riscv_uart_enable_RX(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void CRISCVUARTDriver__riscv_uart_enable_RX__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    CRISCVUARTDriver__riscv_uart_enable_RX(__this);
    __termina_task__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_enable_RX__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    CRISCVUARTDriver__riscv_uart_enable_RX(__this);
    __termina_event__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_enable_TX(void * const __this) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    #line 45 "src/resources/uart.fin"
    uint32_t riscv_uart_txe = 0x2U;

    #line 46 "src/resources/uart.fin"
    self->uart_regs->control = self->uart_regs->control | riscv_uart_txe;

    #line 47 "src/resources/uart.fin"
    return;

}

void CRISCVUARTDriver__riscv_uart_enable_TX__mutex_lock(void * const __this) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    CRISCVUARTDriver__riscv_uart_enable_TX(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void CRISCVUARTDriver__riscv_uart_enable_TX__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    CRISCVUARTDriver__riscv_uart_enable_TX(__this);
    __termina_task__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_enable_TX__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    CRISCVUARTDriver__riscv_uart_enable_TX(__this);
    __termina_event__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_tf_is_empty(void * const __this,
                                              _Bool * const res) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    #line 38 "src/resources/uart.fin"
    uint32_t riscv_uart_te = 0x4U;

    #line 39 "src/resources/uart.fin"
    *res = (uint32_t)(self->uart_regs->status & riscv_uart_te) != 0U;

    #line 40 "src/resources/uart.fin"
    return;

}

void CRISCVUARTDriver__riscv_uart_tf_is_empty__mutex_lock(void * const __this,
                                                          _Bool * const res) {
    
    CRISCVUARTDriver * self = (CRISCVUARTDriver *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    CRISCVUARTDriver__riscv_uart_tf_is_empty(self, res);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void CRISCVUARTDriver__riscv_uart_tf_is_empty__task_lock(void * const __this,
                                                         _Bool * const res) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    CRISCVUARTDriver__riscv_uart_tf_is_empty(__this, res);
    __termina_task__unlock(lock);

}

void CRISCVUARTDriver__riscv_uart_tf_is_empty__event_lock(void * const __this,
                                                          _Bool * const res) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    CRISCVUARTDriver__riscv_uart_tf_is_empty(__this, res);
    __termina_event__unlock(lock);

}
