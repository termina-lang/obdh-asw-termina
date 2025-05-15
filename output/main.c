
#include <termina.h>

#include "app.h"

void __termina_app__init_globals();

static uint8_t __pool_tc_pool_memory[__termina_pool__size(sizeof(TCHandlerT),
                                                          20U)];
static uint8_t __pool_tm_pool_memory[__termina_pool__size(sizeof(TMHandlerT),
                                                          20U)];

static void __termina_app__init_tasks(int32_t * const status) {
    
    *status = 0L;

    if (0L == *status) {
        
        hk_fdir.__task_id = __hk_fdir__task_id;

        hk_fdir.__task_msg_queue_id = __hk_fdir__task_msg_queue_id;

        __termina_task__init(__hk_fdir__task_id, 6, 4096U,
                             __HouseKeepingFDIR__termina_task, &hk_fdir,
                             status);

    }

    if (0L == *status) {
        
        icu_manager.__task_id = __icu_manager__task_id;

        icu_manager.__task_msg_queue_id = __icu_manager__task_msg_queue_id;

        __termina_task__init(__icu_manager__task_id, 5, 4096U,
                             __ICUManager__termina_task, &icu_manager, status);

    }

    if (0L == *status) {
        
        pus_bkg_tc_executor.__task_id = __pus_bkg_tc_executor__task_id;

        pus_bkg_tc_executor.__task_msg_queue_id = __pus_bkg_tc_executor__task_msg_queue_id;

        __termina_task__init(__pus_bkg_tc_executor__task_id, 8, 4096U,
                             __PUSBKGTCExecutor__termina_task,
                             &pus_bkg_tc_executor, status);

    }

    if (0L == *status) {
        
        tc_rx_bottom_half_task.__task_id = __tc_rx_bottom_half_task__task_id;

        tc_rx_bottom_half_task.__task_msg_queue_id = __tc_rx_bottom_half_task__task_msg_queue_id;

        __termina_task__init(__tc_rx_bottom_half_task__task_id, 4, 4096U,
                             __TCRXBottomHalfTask__termina_task,
                             &tc_rx_bottom_half_task, status);

    }

}

static void __termina_app__init_handlers(int32_t * const status) {
    
    *status = 0L;

    init.__handler_id = __init__handler_id;

    uart_hdlr.__handler_id = __uart_hdlr__handler_id;

}

static void __termina_app__init_emitters(int32_t * const status) {
    
    *status = 0L;

    if (0L == *status) {
        
        __termina_periodic_timer_connection_t connection;
        connection.type = __TerminaEmitterConnectionType__Task;
        connection.task.task_msg_queue_id = __hk_fdir__task_msg_queue_id;
        connection.task.sink_msgq_id = __hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id;
        connection.task.sink_port_id = __HouseKeepingFDIR__hk_fdir_timer_ev;

        hk_fdir.hk_fdir_timer_ev = __hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id;

        __termina_periodic_timer__init(__hk_fdir_timer__timer_id, &connection,
                                       &hk_fdir_timer.period, status);

    }

    if (0L == *status) {
        
        __termina_interrupt_connection_t connection;
        connection.type = __TerminaEmitterConnectionType__Handler;
        connection.handler.handler_object = (void *)&uart_hdlr;
        connection.handler.handler_action = UARTIrqHandler__irq_handler;

        __termina_interrupt__init(3, &connection, status);

    }

}

static void __termina_app__init_mutexes(int32_t * const status) {
    
    *status = 0L;

    if (0L == *status) {
        
        pus_service_9.__mutex_id = __pus_service_9__mutex_id;

        __termina_mutex__init(__pus_service_9__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 5, status);

    }

    if (0L == *status) {
        
        system_entry.__mutex_id = __system_entry__mutex_id;

        __termina_mutex__init(__system_entry__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 5, status);

    }

    if (0L == *status) {
        
        tc_pool.__mutex_id = __tc_pool__mutex_id;

        __termina_mutex__init(__tc_pool__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 4, status);

    }

    if (0L == *status) {
        
        telemetry_channel.__mutex_id = __telemetry_channel__mutex_id;

        __termina_mutex__init(__telemetry_channel__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 5, status);

    }

    if (0L == *status) {
        
        telemetry_counter.__mutex_id = __telemetry_counter__mutex_id;

        __termina_mutex__init(__telemetry_counter__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 5, status);

    }

    if (0L == *status) {
        
        tm_pool.__mutex_id = __tm_pool__mutex_id;

        __termina_mutex__init(__tm_pool__mutex_id,
                              __TerminaMutexPolicy__Ceiling, 5, status);

    }

}

static void __termina_app__init_pools(int32_t * const status) {
    
    *status = 0L;

    if (0L == *status) {
        
        tc_pool.__pool_id = __tc_pool__pool_id;

        __termina_pool__init(&tc_pool, (void *)__pool_tc_pool_memory,
                             sizeof(__pool_tc_pool_memory), sizeof(TCHandlerT),
                             status);

    }

    if (0L == *status) {
        
        tm_pool.__pool_id = __tm_pool__pool_id;

        __termina_pool__init(&tm_pool, (void *)__pool_tm_pool_memory,
                             sizeof(__pool_tm_pool_memory), sizeof(TMHandlerT),
                             status);

    }

}

static void __termina_app__init_msg_queues(int32_t * const status) {
    
    *status = 0L;

    if (0L == *status) {
        
        __termina_msg_queue__init(__hk_fdir__task_msg_queue_id,
                                  sizeof(__termina_id_t), 1U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id,
                                  sizeof(__termina_id_t), 1U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__icu_manager__task_msg_queue_id,
                                  sizeof(__termina_id_t), 1U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__pus_bkg_tc_executor__task_msg_queue_id,
                                  sizeof(__termina_id_t), 1U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__tc_rx_bottom_half_task__task_msg_queue_id,
                                  sizeof(__termina_id_t), 1U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__tc_message_queue__channel_msg_queue_id,
                                  sizeof(__termina_box_t), 10U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__hkfdir_message_queue__channel_msg_queue_id,
                                  sizeof(__termina_box_t), 10U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__byte_message_queue__channel_msg_queue_id,
                                  sizeof(uint8_t), 10U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__bkg_message_queue__channel_msg_queue_id,
                                  sizeof(__termina_box_t), 10U, status);

    }

    if (0L == *status) {
        
        __termina_msg_queue__init(__action_tc_message_queue__channel_msg_queue_id,
                                  sizeof(__termina_box_t), 5U, status);

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

static void __termina_app__init_channel_connections(int32_t * const status) {
    
    *status = 0L;

    action_tc_message_queue.task_msg_queue_id = __icu_manager__task_msg_queue_id;
    action_tc_message_queue.channel_msg_queue_id = __action_tc_message_queue__channel_msg_queue_id;
    action_tc_message_queue.port_id = __ICUManager__action_tc_message_queue_input;

    icu_manager.action_tc_message_queue_input = __action_tc_message_queue__channel_msg_queue_id;

    bkg_message_queue.task_msg_queue_id = __pus_bkg_tc_executor__task_msg_queue_id;
    bkg_message_queue.channel_msg_queue_id = __bkg_message_queue__channel_msg_queue_id;
    bkg_message_queue.port_id = __PUSBKGTCExecutor__bkg_message_queue_input;

    pus_bkg_tc_executor.bkg_message_queue_input = __bkg_message_queue__channel_msg_queue_id;

    byte_message_queue.task_msg_queue_id = __tc_rx_bottom_half_task__task_msg_queue_id;
    byte_message_queue.channel_msg_queue_id = __byte_message_queue__channel_msg_queue_id;
    byte_message_queue.port_id = __TCRXBottomHalfTask__byte_message_queue_input;

    tc_rx_bottom_half_task.byte_message_queue_input = __byte_message_queue__channel_msg_queue_id;

    hkfdir_message_queue.task_msg_queue_id = __hk_fdir__task_msg_queue_id;
    hkfdir_message_queue.channel_msg_queue_id = __hkfdir_message_queue__channel_msg_queue_id;
    hkfdir_message_queue.port_id = __HouseKeepingFDIR__hkfdir_message_queue_input;

    hk_fdir.hkfdir_message_queue_input = __hkfdir_message_queue__channel_msg_queue_id;

    tc_message_queue.task_msg_queue_id = __icu_manager__task_msg_queue_id;
    tc_message_queue.channel_msg_queue_id = __tc_message_queue__channel_msg_queue_id;
    tc_message_queue.port_id = __ICUManager__tc_message_queue_input;

    icu_manager.tc_message_queue_input = __tc_message_queue__channel_msg_queue_id;

}

static void __termina_app__initial_event() {
    
    TimeVal current;
    SystemEntry__clock_get_uptime(&current);

    Init * self = &init;

    __status_int32_t status;
    status.__variant = Success;

    status = Init__init(self, current);

    if (status.__variant != Success) {
        __termina_exec__reboot();
    }

    return;

}

void __termina_app__init(int32_t * const status) {
    
    *status = 0L;

    __termina_app__init_globals();

    __termina_app__init_msg_queues(status);

    if (0L == *status) {
        
        __termina_app__init_channel_connections(status);

    }

    if (0L == *status) {
        
        __termina_app__init_pools(status);

    }

    if (0L == *status) {
        
        __termina_app__initial_event(status);

    }

    if (0L == *status) {
        
        __termina_app__init_mutexes(status);

    }

    if (0L == *status) {
        
        __termina_app__enable_protection();

    }

    if (0L == *status) {
        
        __termina_app__init_emitters(status);

    }

    if (0L == *status) {
        
        __termina_app__init_handlers(status);

    }

    if (0L == *status) {
        
        __termina_app__init_tasks(status);

    }

}
