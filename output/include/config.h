#ifndef CONFIG_H__
#define CONFIG_H__

#define CBKGTCExecutorTask__bkg_message_queue_input 0

#define CHousekeepingFDIRTask__hk_fdir_timer_ev 0
#define CHousekeepingFDIRTask__hkfdir_message_queue_input 1

#define COBDHManagerTask__action_tc_message_queue_input 0
#define COBDHManagerTask__tc_message_queue_input 1

#define CTXRxBottomHalfTask__frame_ready_input 0

#define hk_fdir_timer__emitter_id 0
#define irq_2__emitter_id 1
#define system_init__emitter_id 2

#define obt_manager__mutex_id 0
#define tc_pool__mutex_id 1
#define tm_channel__mutex_id 2
#define tm_counter__mutex_id 3
#define tm_pool__mutex_id 4

#define bkg_tc_executor__task_id 0
#define hk_fdir__task_id 1
#define obdh_manager__task_id 2
#define tc_rx_bottom_half_task__task_id 3

#define init_hdlr__handler_id 0
#define uart_hdlr__handler_id 1

#define tc_rx_bottom_half_task__task_msg_queue_id 0
#define obdh_manager__task_msg_queue_id 1
#define hk_fdir__task_msg_queue_id 2
#define bkg_tc_executor__task_msg_queue_id 3
#define hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id 4
#define tc_message_queue__channel_msg_queue_id 5
#define rx_task_message_queue__channel_msg_queue_id 6
#define hkfdir_message_queue__channel_msg_queue_id 7
#define bkg_message_queue__channel_msg_queue_id 8
#define action_tc_message_queue__channel_msg_queue_id 9

#define tc_pool__pool_id 0
#define tm_pool__pool_id 1

#define hk_fdir_timer__timer_id 0

#define TERMINA__APP_CONFIG__POOLS 2

#define TERMINA__APP_CONFIG__TASKS 4

#define TERMINA__APP_CONFIG__PERIODIC_TIMERS 1

#define TERMINA__APP_CONFIG__MUTEXES 5

#define TERMINA__APP_CONFIG__MESSAGE_QUEUES 10

#define TERMINA__APP_CONFIG__MESSAGE_BUFFER_MEMORY (  \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(termina__event_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U + 5U, \
            sizeof(termina__event_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            1U + 10U, \
            sizeof(termina__event_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(termina__event_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            1U, \
            sizeof(TimeVal) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(termina__box_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(size_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(termina__box_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(termina__box_t) \
        ) \
    + \
        TERMINA__APP_CONFIG__MESSAGE_QUEUE_BUFFER( \
            5U, \
            sizeof(termina__box_t) \
        ) \
    )

#define TERMINA__TIME__MICROSECONDS_PER_TICK 10000

#define TERMINA__INTERRUPT__NUMBER_OF_INTERRUPTS 16

#define TERMINA__PROFILE__DEBUG

#endif
