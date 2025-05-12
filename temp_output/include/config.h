#ifndef __CONFIG_H__
#define __CONFIG_H__

#define __HouseKeepingFDIR__hk_fdir_timer_ev 0
#define __HouseKeepingFDIR__hkfdir_message_queue_input 1

#define __ICUManager__action_tc_message_queue_input 0
#define __ICUManager__tc_message_queue_input 1

#define __PUSBKGTCExecutor__bkg_message_queue_input 0

#define __TCRXBottomHalfTask__byte_message_queue_input 0

#define __pus_service_9__mutex_id 0
#define __system_entry__mutex_id 1
#define __tc_pool__mutex_id 2
#define __telemetry_channel__mutex_id 3
#define __telemetry_counter__mutex_id 4
#define __tm_pool__mutex_id 5

#define __hk_fdir__task_id 0
#define __icu_manager__task_id 1
#define __pus_bkg_tc_executor__task_id 2
#define __tc_rx_bottom_half_task__task_id 3

#define __init__handler_id 0
#define __uart_hdlr__handler_id 1

#define __hk_fdir__task_msg_queue_id 0
#define __hk_fdir__hk_fdir_timer_ev__sink_msg_queue_id 1
#define __icu_manager__task_msg_queue_id 2
#define __pus_bkg_tc_executor__task_msg_queue_id 3
#define __tc_rx_bottom_half_task__task_msg_queue_id 4
#define __tc_message_queue__channel_msg_queue_id 5
#define __hkfdir_message_queue__channel_msg_queue_id 6
#define __byte_message_queue__channel_msg_queue_id 7
#define __bkg_message_queue__channel_msg_queue_id 8
#define __action_tc_message_queue__channel_msg_queue_id 9

#define __tc_pool__pool_id 0
#define __tm_pool__pool_id 1

#define __hk_fdir_timer__timer_id 0

#define __TERMINA_APP_CONFIG_POOLS 2

#define __TERMINA_APP_CONFIG_TASKS 4

#define __TERMINA_APP_CONFIG_PERIODIC_TIMERS 1

#define __TERMINA_APP_CONFIG_MUTEXES 6

#define __TERMINA_APP_CONFIG_MESSAGE_QUEUES 10

#define __TERMINA_APP_CONFIG_MESSAGE_BUFFER_MEMORY (  \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            1U, \
            sizeof(TimeVal) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(__termina_box_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(__termina_box_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(uint8_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            10U, \
            sizeof(__termina_box_t) \
        ) \
    + \
        __TERMINA_APP_CONFIG_MESSAGE_QUEUE_BUFFER( \
            5U, \
            sizeof(__termina_box_t) \
        ) \
    )

#define __TERMINA_MICROSECONDS_PER_TICK 10000

#endif
