
#include <termina.h>

#include "app.h"

static uint8_t termina__pool_memory__tc_pool[termina__pool__size(sizeof(TCHandler), 10U)];
static uint8_t termina__pool_memory__tm_pool[termina__pool__size(sizeof(TMHandler), 10U)];

static void termina__app__init_tasks(int32_t * const status) {
    
    *status = 0L;

    bkg_tc_executor._task_id = bkg_tc_executor__task_id;

    bkg_tc_executor._task_msg_queue_id = bkg_tc_executor__task_msg_queue_id;

    termina__task__init(bkg_tc_executor__task_id, 8, 4096U, &termina__task_entry__CBKGTCExecutorTask, &bkg_tc_executor, status);

    if (0L == *status) {
        
        hk_fdir._task_id = hk_fdir__task_id;

        hk_fdir._task_msg_queue_id = hk_fdir__task_msg_queue_id;

        termina__task__init(hk_fdir__task_id, 6, 4096U, &termina__task_entry__CHousekeepingFDIRTask, &hk_fdir, status);

    }

    if (0L == *status) {
        
        obdh_manager._task_id = obdh_manager__task_id;

        obdh_manager._task_msg_queue_id = obdh_manager__task_msg_queue_id;

        termina__task__init(obdh_manager__task_id, 5, 4096U, &termina__task_entry__COBDHManagerTask, &obdh_manager, status);

    }

    if (0L == *status) {
        
        tc_rx_bottom_half_task._task_id = tc_rx_bottom_half_task__task_id;

        tc_rx_bottom_half_task._task_msg_queue_id = tc_rx_bottom_half_task__task_msg_queue_id;

        termina__task__init(tc_rx_bottom_half_task__task_id, 4, 4096U, &termina__task_entry__CTXRxBottomHalfTask, &tc_rx_bottom_half_task, status);

    }

}

static void termina__app__init_handlers(void) {
    
    init_hdlr._handler_id = init_hdlr__handler_id;

    uart_hdlr._handler_id = uart_hdlr__handler_id;

}

static void termina__app__init_emitters(int32_t * const status) {
    
    termina__periodic_timer_connection_t timer_connection;

    termina__interrupt_connection_t interrupt_connection;

    *status = 0L;

    timer_connection.type = termina__emitter_connection_type__task;
    timer_connection.task.task_msg_queue_id = hk_fdir__task_msg_queue_id;
    timer_connection.task.sink_msgq_id = hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id;
    timer_connection.task.sink_port_id = CHousekeepingFDIRTask__hk_fdir_timer_ev;

    hk_fdir.hk_fdir_timer_ev = hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id;

    termina__periodic_timer__init(hk_fdir_timer__timer_id, hk_fdir_timer__emitter_id, &timer_connection, &hk_fdir_timer.period, status);

    if (0L == *status) {
        
        interrupt_connection.type = termina__emitter_connection_type__handler;
        interrupt_connection.handler.handler_object = (void *)&uart_hdlr;
        interrupt_connection.handler.handler_id = uart_hdlr__handler_id;
        interrupt_connection.handler.handler_action = &CCharDevIRQHandler__irq_handler;

        termina__interrupt__init(2, irq_2__emitter_id, &interrupt_connection, status);

    }

}

static void termina__app__init_mutexes(int32_t * const status) {
    
    MutexProtocol protocol;

    *status = 0L;

    protocol._variant = MutexProtocol__Ceiling;
    protocol.Ceiling._0 = 5;

    termina__mutex__init(obt_manager__mutex_id, protocol, status);

    if (0L == *status) {
        
        protocol._variant = MutexProtocol__Ceiling;
        protocol.Ceiling._0 = 4;

        termina__mutex__init(tc_pool__mutex_id, protocol, status);

    }

    if (0L == *status) {
        
        protocol._variant = MutexProtocol__Ceiling;
        protocol.Ceiling._0 = 5;

        termina__mutex__init(tm_channel__mutex_id, protocol, status);

    }

    if (0L == *status) {
        
        protocol._variant = MutexProtocol__Ceiling;
        protocol.Ceiling._0 = 5;

        termina__mutex__init(tm_counter__mutex_id, protocol, status);

    }

    if (0L == *status) {
        
        protocol._variant = MutexProtocol__Ceiling;
        protocol.Ceiling._0 = 5;

        termina__mutex__init(tm_pool__mutex_id, protocol, status);

    }

}

static void termina__app__init_pools(int32_t * const status) {
    
    *status = 0L;

    tc_pool.pool_id = tc_pool__pool_id;

    termina__pool__init(&tc_pool, (void *)termina__pool_memory__tc_pool, sizeof(termina__pool_memory__tc_pool), sizeof(TCHandler), status);

    if (0L == *status) {
        
        tm_pool.pool_id = tm_pool__pool_id;

        termina__pool__init(&tm_pool, (void *)termina__pool_memory__tm_pool, sizeof(termina__pool_memory__tm_pool), sizeof(TMHandler), status);

    }

}

static void termina__app__init_msg_queues(int32_t * const status) {
    
    *status = 0L;

    termina__msg_queue__init(tc_rx_bottom_half_task__task_msg_queue_id, sizeof(termina__event_t), 10U, status);

    if (0L == *status) {
        
        termina__msg_queue__init(obdh_manager__task_msg_queue_id, sizeof(termina__event_t), 10U + 5U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(hk_fdir__task_msg_queue_id, sizeof(termina__event_t), 1U + 10U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(bkg_tc_executor__task_msg_queue_id, sizeof(termina__event_t), 10U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id, sizeof(TimeVal), 1U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(tc_message_queue__channel_msg_queue_id, sizeof(termina__box_t), 10U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(rx_task_message_queue__channel_msg_queue_id, sizeof(size_t), 10U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(hkfdir_message_queue__channel_msg_queue_id, sizeof(termina__box_t), 10U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(bkg_message_queue__channel_msg_queue_id, sizeof(termina__box_t), 10U, status);

    }

    if (0L == *status) {
        
        termina__msg_queue__init(action_tc_message_queue__channel_msg_queue_id, sizeof(termina__box_t), 5U, status);

    }

}

static void termina__app__enable_protection(void) {
    
    obt_manager._lock_type.type = termina__resource_lock_type__mutex;
    obt_manager._lock_type.mutex.mutex_id = obt_manager__mutex_id;

    tc_channel._lock_type.type = termina__resource_lock_type__irq;

    tm_channel._lock_type.type = termina__resource_lock_type__mutex;
    tm_channel._lock_type.mutex.mutex_id = tm_channel__mutex_id;

    tm_counter._lock_type.type = termina__resource_lock_type__mutex;
    tm_counter._lock_type.mutex.mutex_id = tm_counter__mutex_id;

    uart_drv._lock_type.type = termina__resource_lock_type__irq;

    tc_pool._lock_type.type = termina__resource_lock_type__mutex;
    tc_pool._lock_type.mutex.mutex_id = tc_pool__mutex_id;

    tm_pool._lock_type.type = termina__resource_lock_type__mutex;
    tm_pool._lock_type.mutex.mutex_id = tm_pool__mutex_id;

}

static void termina__app__init_channel_connections(void) {
    
    action_tc_message_queue.task_id = obdh_manager__task_id;
    action_tc_message_queue.task_msg_queue_id = obdh_manager__task_msg_queue_id;
    action_tc_message_queue.channel_msg_queue_id = action_tc_message_queue__channel_msg_queue_id;
    action_tc_message_queue.port_id = COBDHManagerTask__action_tc_message_queue_input;

    obdh_manager.action_tc_message_queue_input = action_tc_message_queue__channel_msg_queue_id;

    bkg_message_queue.task_id = bkg_tc_executor__task_id;
    bkg_message_queue.task_msg_queue_id = bkg_tc_executor__task_msg_queue_id;
    bkg_message_queue.channel_msg_queue_id = bkg_message_queue__channel_msg_queue_id;
    bkg_message_queue.port_id = CBKGTCExecutorTask__bkg_message_queue_input;

    bkg_tc_executor.bkg_message_queue_input = bkg_message_queue__channel_msg_queue_id;

    hkfdir_message_queue.task_id = hk_fdir__task_id;
    hkfdir_message_queue.task_msg_queue_id = hk_fdir__task_msg_queue_id;
    hkfdir_message_queue.channel_msg_queue_id = hkfdir_message_queue__channel_msg_queue_id;
    hkfdir_message_queue.port_id = CHousekeepingFDIRTask__hkfdir_message_queue_input;

    hk_fdir.hkfdir_message_queue_input = hkfdir_message_queue__channel_msg_queue_id;

    rx_task_message_queue.task_id = tc_rx_bottom_half_task__task_id;
    rx_task_message_queue.task_msg_queue_id = tc_rx_bottom_half_task__task_msg_queue_id;
    rx_task_message_queue.channel_msg_queue_id = rx_task_message_queue__channel_msg_queue_id;
    rx_task_message_queue.port_id = CTXRxBottomHalfTask__frame_ready_input;

    tc_rx_bottom_half_task.frame_ready_input = rx_task_message_queue__channel_msg_queue_id;

    tc_message_queue.task_id = obdh_manager__task_id;
    tc_message_queue.task_msg_queue_id = obdh_manager__task_msg_queue_id;
    tc_message_queue.channel_msg_queue_id = tc_message_queue__channel_msg_queue_id;
    tc_message_queue.port_id = COBDHManagerTask__tc_message_queue_input;

    obdh_manager.tc_message_queue_input = tc_message_queue__channel_msg_queue_id;

}

static void termina__app__initial_event(void) {
    
    termina__event_t event;
    event.emitter_id = system_init__emitter_id;
    event.owner.type = termina__active_entity__handler;
    event.owner.handler.handler_id = init_hdlr__handler_id;
    event.port_id = 0;

    TimeVal current;
    SystemEntry__clock_get_uptime(&event, &current);

    CInitHandler * self = &init_hdlr;

    Status__i32 result;

    result = CInitHandler__init(&event, self, current);

    if (result._variant != Status__Success) {
        
        ExceptSource source;
        source._variant = ExceptSource__Handler;
        source.Handler._0 = init_hdlr__handler_id;

        termina__except__action_failure(source, 0U, result.Failure._0);

    }

    return;

}

void termina__app__init(int32_t * const status) {
    
    *status = 0L;

    termina__app__init_globals();

    termina__app__init_msg_queues(status);

    if (0L == *status) {
        
        termina__app__init_channel_connections();

        termina__app__init_pools(status);

    }

    if (0L == *status) {
        
        termina__app__initial_event();

        termina__app__init_mutexes(status);

    }

    if (0L == *status) {
        
        termina__app__enable_protection();

        termina__app__init_emitters(status);

    }

    if (0L == *status) {
        
        termina__app__init_handlers();

        termina__app__init_tasks(status);

    }

}
