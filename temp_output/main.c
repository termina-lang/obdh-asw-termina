
#include <termina.h>

#include "app.h"

void __termina_app__init_globals();

_Atomic uint32_t u32_system_data_pool[sdp_num_u32_params];
_Atomic uint8_t u8_system_data_pool[sdp_num_u8_params];

static uint8_t __pool_tc_pool_memory[__termina_pool__size(sizeof(TCHandlerT),
                                                          20U)];
static uint8_t __pool_tm_pool_memory[__termina_pool__size(sizeof(TMHandlerT),
                                                          20U)];

static void __termina_app__init_tasks(Status * const status) {
    
    status->__variant = Status__Success;

    if (Status__Success == status->__variant) {
        
        hk_fdir.__task_msg_queue_id = __hk_fdir__task_msg_queue_id;

        __termina_task__init(__hk_fdir__task_id, 255, 4096U,
                             __HouseKeepingFDIR__termina_task, &hk_fdir,
                             status);

    }

    if (Status__Success == status->__variant) {
        
        icu_manager.__task_msg_queue_id = __icu_manager__task_msg_queue_id;

        __termina_task__init(__icu_manager__task_id, 255, 4096U,
                             __ICUManager__termina_task, &icu_manager, status);

    }

    if (Status__Success == status->__variant) {
        
        pus_bkg_tc_executor.__task_msg_queue_id = __pus_bkg_tc_executor__task_msg_queue_id;

        __termina_task__init(__pus_bkg_tc_executor__task_id, 255, 4096U,
                             __PUSBKGTCExecutor__termina_task,
                             &pus_bkg_tc_executor, status);

    }

    if (Status__Success == status->__variant) {
        
        tc_rx_bottom_half_task.__task_msg_queue_id = __tc_rx_bottom_half_task__task_msg_queue_id;

        __termina_task__init(__tc_rx_bottom_half_task__task_id, 255, 4096U,
                             __TCRXBottomHalfTask__termina_task,
                             &tc_rx_bottom_half_task, status);

    }

}

static void __termina_app__init_emitters(Status * const status) {
    
    status->__variant = Status__Success;

    if (Status__Success == status->__variant) {
        
        __termina_periodic_timer_connection_t connection;
        connection.type = __TerminaEmitterConnectionType__Task;
        connection.task.task_msg_queue_id = __hk_fdir__task_msg_queue_id;
        connection.task.sink_msgq_id = __hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id;
        connection.task.sink_port_id = __HouseKeepingFDIR__hk_fdir_timer_ev;

        hk_fdir.hk_fdir_timer_ev = __hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id;

        __termina_periodic_timer__init(__hk_fdir_timer__timer_id, &connection,
                                       &hk_fdir_timer.period, status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_interrupt_connection_t connection;
        connection.type = __TerminaEmitterConnectionType__Handler;
        connection.handler.handler_object = (void *)&uart_hdlr;
        connection.handler.handler_action = UARTIrqHandler__irq_handler;

        __termina_interrupt__init(3, &connection, status);

    }

}

static void __termina_app__init_mutexes(Status * const status) {
    
    status->__variant = Status__Success;

    if (Status__Success == status->__variant) {
        
        tc_pool.__mutex_id = __tc_pool__mutex_id;

        __termina_mutex__init(__tc_pool__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 255, status);

    }

    if (Status__Success == status->__variant) {
        
        telemetry_channel.__mutex_id = __telemetry_channel__mutex_id;

        __termina_mutex__init(__telemetry_channel__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 255, status);

    }

    if (Status__Success == status->__variant) {
        
        telemetry_counter.__mutex_id = __telemetry_counter__mutex_id;

        __termina_mutex__init(__telemetry_counter__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 255, status);

    }

    if (Status__Success == status->__variant) {
        
        tm_pool.__mutex_id = __tm_pool__mutex_id;

        __termina_mutex__init(__tm_pool__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 255, status);

    }

}

static void __termina_app__init_pools(Status * const status) {
    
    status->__variant = Status__Success;

    if (Status__Success == status->__variant) {
        
        tc_pool.__pool_id = __tc_pool__pool_id;

        __termina_pool__init(&tc_pool, (void *)__pool_tc_pool_memory,
                             sizeof(__pool_tc_pool_memory), sizeof(TCHandlerT),
                             status);

    }

    if (Status__Success == status->__variant) {
        
        tm_pool.__pool_id = __tm_pool__pool_id;

        __termina_pool__init(&tm_pool, (void *)__pool_tm_pool_memory,
                             sizeof(__pool_tm_pool_memory), sizeof(TMHandlerT),
                             status);

    }

}

static void __termina_app__init_msg_queues(Status * const status) {
    
    status->__variant = Status__Success;

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__hk_fdir__task_msg_queue_id, 1U,
                                  sizeof(__termina_id_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id,
                                  1U, sizeof(__termina_id_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__icu_manager__task_msg_queue_id, 1U,
                                  sizeof(__termina_id_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__pus_bkg_tc_executor__task_msg_queue_id, 1U,
                                  sizeof(__termina_id_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__tc_rx_bottom_half_task__task_msg_queue_id,
                                  1U, sizeof(__termina_id_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__tc_message_queue__channel_msg_queue_id, 10U,
                                  sizeof(__termina_box_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__hkfdir_message_queue__channel_msg_queue_id,
                                  10U, sizeof(__termina_box_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__byte_message_queue__channel_msg_queue_id,
                                  10U, sizeof(uint8_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__bkg_message_queue__channel_msg_queue_id,
                                  10U, sizeof(__termina_box_t), status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_msg_queue__init(__action_tc_message_queue__channel_msg_queue_id,
                                  5U, sizeof(__termina_box_t), status);

    }

}

static void __termina_app__enable_protection() {
    
    hk_fdir.a_tc_handler_pool.alloc = __termina_pool__alloc__mutex_lock;
    hk_fdir.a_tc_handler_pool.free = __termina_pool__free__mutex_lock;

    icu_manager.a_tc_handler_pool.alloc = __termina_pool__alloc__mutex_lock;
    icu_manager.a_tc_handler_pool.free = __termina_pool__free__mutex_lock;

    pus_bkg_tc_executor.a_tc_handler_pool.alloc = __termina_pool__alloc__mutex_lock;
    pus_bkg_tc_executor.a_tc_handler_pool.free = __termina_pool__free__mutex_lock;

    tc_rx_bottom_half_task.a_tc_handler_pool.alloc = __termina_pool__alloc__mutex_lock;
    tc_rx_bottom_half_task.a_tc_handler_pool.free = __termina_pool__free__mutex_lock;

    init.gpio_driver.init_gpio = GPIODriver__init_gpio__event_lock;

    init.uart.initialize = UARTDriver__initialize__event_lock;

    uart_hdlr.uart.release_tx = UARTDriver__release_tx__event_lock;

}

static void __termina_app__init_channel_connections(Status * const status) {
    
    status->__variant = Status__Success;

    action_tc_message_queue.task_msg_queue_id = __icu_manager__task_msg_queue_id;
    action_tc_message_queue.channel_msg_queue_id = __action_tc_message_queue__channel_msg_queue_id;
    action_tc_message_queue.port_id = __ICUManager__action_tc_message_queue_input;

    bkg_message_queue.task_msg_queue_id = __pus_bkg_tc_executor__task_msg_queue_id;
    bkg_message_queue.channel_msg_queue_id = __bkg_message_queue__channel_msg_queue_id;
    bkg_message_queue.port_id = __PUSBKGTCExecutor__bkg_message_queue_input;

    byte_message_queue.task_msg_queue_id = __tc_rx_bottom_half_task__task_msg_queue_id;
    byte_message_queue.channel_msg_queue_id = __byte_message_queue__channel_msg_queue_id;
    byte_message_queue.port_id = __TCRXBottomHalfTask__byte_message_queue_input;

    hkfdir_message_queue.task_msg_queue_id = __hk_fdir__task_msg_queue_id;
    hkfdir_message_queue.channel_msg_queue_id = __hkfdir_message_queue__channel_msg_queue_id;
    hkfdir_message_queue.port_id = __HouseKeepingFDIR__hkfdir_message_queue_input;

    tc_message_queue.task_msg_queue_id = __icu_manager__task_msg_queue_id;
    tc_message_queue.channel_msg_queue_id = __tc_message_queue__channel_msg_queue_id;
    tc_message_queue.port_id = __ICUManager__tc_message_queue_input;

}

static void __termina_app__initial_event() {
    
    TimeVal current;
    SystemEntry__clock_get_uptime(&current);

    Init * self = &init;

    Result result;
    result.__variant = Result__Ok;

    result = Init__init(self, current);

    if (result.__variant != Result__Ok) {
        __termina_exec__shutdown();
    }

    return;

}

void __termina_app__init(Status * const status) {
    
    status->__variant = Status__Success;

    __termina_app__init_globals();

    __termina_app__init_msg_queues(status);

    if (Status__Success == status->__variant) {
        
        __termina_app__init_channel_connections(status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_app__init_pools(status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_app__initial_event(status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_app__init_mutexes(status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_app__enable_protection();

    }

    if (Status__Success == status->__variant) {
        
        __termina_app__init_emitters(status);

    }

    if (Status__Success == status->__variant) {
        
        __termina_app__init_tasks(status);

    }

}
