
#include <rtems.h>

#include <termina.h>

#include "app.h"

void __termina_app__init_globals();

#define __HouseKeepingFDIR__hkfdir_message_queue_input 0
#define __HouseKeepingFDIR__hk_fdir_timer_ev 1

#define __ICUManager__action_tc_message_queue_input 0
#define __ICUManager__tc_message_queue_input 1

#define __PUSBKGTCExecutor__bkg_message_queue_input 0

#define __TCRXBottomHalfTask__byte_message_queue_input 0

 _Atomic uint16_t system_data_pool[sdp_num_params];

static uint8_t __pool_tc_pool_memory[__termina_pool__size(sizeof(TCDescriptorT),
                                                          20U)];
static uint8_t __pool_tm_pool_memory[__termina_pool__size(sizeof(TMDescriptorT),
                                                          20U)];

static rtems_task __rtems_task__HouseKeepingFDIR(rtems_task_argument arg) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0U;
    size_t size = 0U;

    Result result;
    result.__variant = Result__Ok;

    TimeVal do_hk_fdir__msg_data;
    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        status = rtems_message_queue_receive(self->__task.msgq_id, &next_msg,
                                             &size, RTEMS_WAIT,
                                             RTEMS_NO_TIMEOUT);

        if (RTEMS_SUCCESSFUL != status) {
            break;
        }

        switch (next_msg) {
            
            case __HouseKeepingFDIR__hk_fdir_timer_ev:

                status = rtems_message_queue_receive(self->hk_fdir_timer_ev,
                                                     (void *)&do_hk_fdir__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1U);
                }

                result = HouseKeepingFDIR__do_hk_fdir(self,
                                                      do_hk_fdir__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1U);
                }

                break;

            case __HouseKeepingFDIR__hkfdir_message_queue_input:

                status = rtems_message_queue_receive(self->hkfdir_message_queue_input,
                                                     (void *)&exec_tc__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1U);
                }

                result = HouseKeepingFDIR__exec_tc(self, exec_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1U);
                }

                break;

            default:

                rtems_shutdown_executive(1U);

                break;

        }

    }

    rtems_shutdown_executive(1U);

    return;

}

static rtems_task __rtems_task__ICUManager(rtems_task_argument arg) {
    
    ICUManager * self = (ICUManager *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0U;
    size_t size = 0U;

    Result result;
    result.__variant = Result__Ok;

    __termina_box_t process_tc__msg_data;
    __termina_box_t process_action_tc__msg_data;

    for (;;) {
        
        status = rtems_message_queue_receive(self->__task.msgq_id, &next_msg,
                                             &size, RTEMS_WAIT,
                                             RTEMS_NO_TIMEOUT);

        if (RTEMS_SUCCESSFUL != status) {
            break;
        }

        switch (next_msg) {
            
            case __ICUManager__tc_message_queue_input:

                status = rtems_message_queue_receive(self->tc_message_queue_input,
                                                     (void *)&process_tc__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1U);
                }

                result = ICUManager__process_tc(self, process_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1U);
                }

                break;

            case __ICUManager__action_tc_message_queue_input:

                status = rtems_message_queue_receive(self->action_tc_message_queue_input,
                                                     (void *)&process_action_tc__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1U);
                }

                result = ICUManager__process_action_tc(self,
                                                       process_action_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1U);
                }

                break;

            default:

                rtems_shutdown_executive(1U);

                break;

        }

    }

    rtems_shutdown_executive(1U);

    return;

}

static rtems_task __rtems_task__PUSBKGTCExecutor(rtems_task_argument arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0U;
    size_t size = 0U;

    Result result;
    result.__variant = Result__Ok;

    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        status = rtems_message_queue_receive(self->__task.msgq_id, &next_msg,
                                             &size, RTEMS_WAIT,
                                             RTEMS_NO_TIMEOUT);

        if (RTEMS_SUCCESSFUL != status) {
            break;
        }

        switch (next_msg) {
            
            case __PUSBKGTCExecutor__bkg_message_queue_input:

                status = rtems_message_queue_receive(self->bkg_message_queue_input,
                                                     (void *)&exec_tc__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1U);
                }

                result = PUSBKGTCExecutor__exec_tc(self, exec_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1U);
                }

                break;

            default:

                rtems_shutdown_executive(1U);

                break;

        }

    }

    rtems_shutdown_executive(1U);

    return;

}

static rtems_task __rtems_task__TCRXBottomHalfTask(rtems_task_argument arg) {
    
    TCRXBottomHalfTask * self = (TCRXBottomHalfTask *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0U;
    size_t size = 0U;

    Result result;
    result.__variant = Result__Ok;

    uint8_t get_tc__msg_data;

    for (;;) {
        
        status = rtems_message_queue_receive(self->__task.msgq_id, &next_msg,
                                             &size, RTEMS_WAIT,
                                             RTEMS_NO_TIMEOUT);

        if (RTEMS_SUCCESSFUL != status) {
            break;
        }

        switch (next_msg) {
            
            case __TCRXBottomHalfTask__byte_message_queue_input:

                status = rtems_message_queue_receive(self->byte_message_queue_input,
                                                     (void *)&get_tc__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1U);
                }

                result = TCRXBottomHalfTask__get_tc(self, get_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1U);
                }

                break;

            default:

                rtems_shutdown_executive(1U);

                break;

        }

    }

    rtems_shutdown_executive(1U);

    return;

}

void __rtems_periodic_timer__hk_fdir_timer(rtems_id _timer_id,
                                           void * _ignored) {
    
    rtems_status_code status = RTEMS_SUCCESSFUL;

    status = rtems_message_queue_send(hk_fdir_timer.__timer.sink_msgq_id,
                                      &hk_fdir_timer.__timer.current,
                                      sizeof(TimeVal));

    if (RTEMS_SUCCESSFUL == status) {
        
        status = rtems_message_queue_send(hk_fdir_timer.__timer.task_msgq_id,
                                          &hk_fdir_timer.__timer.task_port,
                                          sizeof(uint32_t));
    }

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    __termina__add_timeval(&hk_fdir_timer.__timer.current,
                           &hk_fdir_timer.period);

    status = __rtems__timer_delay_at(hk_fdir_timer.__timer.timer_id,
                                     &hk_fdir_timer.__timer.current,
                                     __rtems_periodic_timer__hk_fdir_timer);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    return;

}

void __rtems_isr__irq_3(void * _ignored) {
    
    UARTIrqHandler * self = &uart_hdlr;

    Result result;
    result.__variant = Result__Ok;

    result = UARTIrqHandler__irq_handler(self, 3U);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    return;

}

void __rtems_app__initial_event(TimeVal * const current) {
    
    Init * self = &init;

    Result result;
    result.__variant = Result__Ok;

    result = Init__init(self, *current);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    return;

}

static void __rtems_app__enable_protection() {
    
    Result result;
    result.__variant = Result__Ok;

    mng_tc_executor.__resource.lock = __RTEMSResourceLock__None;

    pus_service_12.__resource.lock = __RTEMSResourceLock__None;

    pus_service_17.__resource.lock = __RTEMSResourceLock__None;

    pus_service_19.__resource.lock = __RTEMSResourceLock__None;

    pus_service_20.__resource.lock = __RTEMSResourceLock__None;

    pus_service_3.__resource.lock = __RTEMSResourceLock__None;

    pus_service_5.__resource.lock = __RTEMSResourceLock__None;

    tc_pool.__resource.lock = __RTEMSResourceLock__Mutex;
    tc_pool.__resource.mutex.policy = __RTEMSMutexPolicy__Ceiling;
    tc_pool.__resource.mutex.prio_ceiling = 255;

    result = __termina_resource__init(&tc_pool.__resource);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    telemetry_channel.__resource.lock = __RTEMSResourceLock__Mutex;
    telemetry_channel.__resource.mutex.policy = __RTEMSMutexPolicy__Ceiling;
    telemetry_channel.__resource.mutex.prio_ceiling = 255;

    result = __termina_resource__init(&telemetry_channel.__resource);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    telemetry_counter.__resource.lock = __RTEMSResourceLock__Mutex;
    telemetry_counter.__resource.mutex.policy = __RTEMSMutexPolicy__Ceiling;
    telemetry_counter.__resource.mutex.prio_ceiling = 255;

    result = __termina_resource__init(&telemetry_counter.__resource);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    tm_pool.__resource.lock = __RTEMSResourceLock__Mutex;
    tm_pool.__resource.mutex.policy = __RTEMSMutexPolicy__Ceiling;
    tm_pool.__resource.mutex.prio_ceiling = 255;

    result = __termina_resource__init(&tm_pool.__resource);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    uart_drv.__resource.lock = __RTEMSResourceLock__Irq;

}

static void __rtems_app__init_globals() {
    
    Result result;
    result.__variant = Result__Ok;

    mng_tc_executor.__resource.lock = __RTEMSResourceLock__None;

    pus_service_12.__resource.lock = __RTEMSResourceLock__None;

    pus_service_17.__resource.lock = __RTEMSResourceLock__None;

    pus_service_19.__resource.lock = __RTEMSResourceLock__None;

    pus_service_20.__resource.lock = __RTEMSResourceLock__None;

    pus_service_3.__resource.lock = __RTEMSResourceLock__None;

    pus_service_5.__resource.lock = __RTEMSResourceLock__None;

    telemetry_channel.__resource.lock = __RTEMSResourceLock__None;

    telemetry_counter.__resource.lock = __RTEMSResourceLock__None;

    uart_drv.__resource.lock = __RTEMSResourceLock__None;

    tc_pool.__resource.lock = __RTEMSResourceLock__None;

    result = __termina_pool__init(&tc_pool, (void *)__pool_tc_pool_memory,
                                  sizeof(__pool_tc_pool_memory),
                                  sizeof(TCDescriptorT));

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    tm_pool.__resource.lock = __RTEMSResourceLock__None;

    result = __termina_pool__init(&tm_pool, (void *)__pool_tm_pool_memory,
                                  sizeof(__pool_tm_pool_memory),
                                  sizeof(TMDescriptorT));

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1U);
    }

    rtems_status_code status = RTEMS_SUCCESSFUL;

    status = __rtems__create_msg_queue(1U, sizeof(uint32_t),
                                       &hk_fdir.__task.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_msg_queue(1U, sizeof(TimeVal),
                                       &hk_fdir.hk_fdir_timer_ev);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_msg_queue(1U, sizeof(uint32_t),
                                       &icu_manager.__task.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_msg_queue(1U, sizeof(uint32_t),
                                       &pus_bkg_tc_executor.__task.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_msg_queue(1U, sizeof(uint32_t),
                                       &tc_rx_bottom_half_task.__task.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    tc_message_queue.task_msgq_id = icu_manager.__task.msgq_id;
    tc_message_queue.task_port = __ICUManager__tc_message_queue_input;
    tc_message_queue.message_size = sizeof(__termina_box_t);

    status = __rtems__create_msg_queue(10U, sizeof(__termina_box_t),
                                       &tc_message_queue.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    hkfdir_message_queue.task_msgq_id = hk_fdir.__task.msgq_id;
    hkfdir_message_queue.task_port = __HouseKeepingFDIR__hkfdir_message_queue_input;
    hkfdir_message_queue.message_size = sizeof(__termina_box_t);

    status = __rtems__create_msg_queue(10U, sizeof(__termina_box_t),
                                       &hkfdir_message_queue.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    byte_message_queue.task_msgq_id = tc_rx_bottom_half_task.__task.msgq_id;
    byte_message_queue.task_port = __TCRXBottomHalfTask__byte_message_queue_input;
    byte_message_queue.message_size = sizeof(uint8_t);

    status = __rtems__create_msg_queue(10U, sizeof(uint8_t),
                                       &byte_message_queue.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    bkg_message_queue.task_msgq_id = pus_bkg_tc_executor.__task.msgq_id;
    bkg_message_queue.task_port = __PUSBKGTCExecutor__bkg_message_queue_input;
    bkg_message_queue.message_size = sizeof(__termina_box_t);

    status = __rtems__create_msg_queue(10U, sizeof(__termina_box_t),
                                       &bkg_message_queue.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    action_tc_message_queue.task_msgq_id = icu_manager.__task.msgq_id;
    action_tc_message_queue.task_port = __ICUManager__action_tc_message_queue_input;
    action_tc_message_queue.message_size = sizeof(__termina_box_t);

    status = __rtems__create_msg_queue(5U, sizeof(__termina_box_t),
                                       &action_tc_message_queue.msgq_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    hk_fdir_timer.__timer.task_msgq_id = hk_fdir.__task.msgq_id;
    hk_fdir_timer.__timer.sink_msgq_id = hk_fdir.hk_fdir_timer_ev;
    hk_fdir_timer.__timer.task_port = __HouseKeepingFDIR__hk_fdir_timer_ev;

    hk_fdir.hkfdir_message_queue_input = hkfdir_message_queue.msgq_id;

    icu_manager.action_tc_message_queue_input = action_tc_message_queue.msgq_id;

    icu_manager.tc_message_queue_input = tc_message_queue.msgq_id;

    pus_bkg_tc_executor.bkg_message_queue_input = bkg_message_queue.msgq_id;

    tc_rx_bottom_half_task.byte_message_queue_input = byte_message_queue.msgq_id;

    status = __rtems__create_timer(&hk_fdir_timer.__timer.timer_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

}

static void __rtems_app__install_emitters(TimeVal * const current) {
    
    rtems_status_code status = RTEMS_SUCCESSFUL;

    if (RTEMS_SUCCESSFUL == status) {
        
        hk_fdir_timer.__timer.current = *current;

        __termina__add_timeval(&hk_fdir_timer.__timer.current,
                               &hk_fdir_timer.period);

        status = __rtems__timer_delay_at(hk_fdir_timer.__timer.timer_id,
                                         &hk_fdir_timer.__timer.current,
                                         __rtems_periodic_timer__hk_fdir_timer);
    }

    if (RTEMS_SUCCESSFUL == status) {
        
        status = __rtems__install_isr(3U, __rtems_isr__irq_3);

    }

}

static void __rtems_app__create_tasks() {
    
    rtems_status_code status = RTEMS_SUCCESSFUL;

    status = __rtems__create_task(255, 4096U, __rtems_task__HouseKeepingFDIR,
                                  (rtems_task_argument)&hk_fdir,
                                  &hk_fdir.__task.task_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_task(255, 4096U, __rtems_task__ICUManager,
                                  (rtems_task_argument)&icu_manager,
                                  &icu_manager.__task.task_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_task(255, 4096U, __rtems_task__PUSBKGTCExecutor,
                                  (rtems_task_argument)&pus_bkg_tc_executor,
                                  &pus_bkg_tc_executor.__task.task_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

    status = __rtems__create_task(255, 4096U, __rtems_task__TCRXBottomHalfTask,
                                  (rtems_task_argument)&tc_rx_bottom_half_task,
                                  &tc_rx_bottom_half_task.__task.task_id);

    if (RTEMS_SUCCESSFUL != status) {
        rtems_shutdown_executive(1U);
    }

}

rtems_task Init(rtems_task_argument _ignored) {
    
    TimeVal current;

    __termina__clock_get_uptime(&current);

    __termina_app__init_globals();

    __rtems_app__init_globals();

    __rtems_app__initial_event(&current);

    __rtems_app__enable_protection();

    __rtems_app__install_emitters(&current);

    __rtems_app__create_tasks();

    rtems_task_delete(RTEMS_SELF);

}

#define CONFIGURE_MAXIMUM_TASKS 5
#define CONFIGURE_MAXIMUM_MESSAGE_QUEUES 10
#define CONFIGURE_MAXIMUM_TIMERS 1
#define CONFIGURE_MAXIMUM_SEMAPHORES 4

#define CONFIGURE_MESSAGE_BUFFER_MEMORY (  \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            1U, \
            sizeof(TimeVal) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            1U, \
            sizeof(uint32_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            10U, \
            sizeof(__termina_box_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            10U, \
            sizeof(__termina_box_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            10U, \
            sizeof(uint8_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            10U, \
            sizeof(__termina_box_t) \
        ) \
    + \
        CONFIGURE_MESSAGE_BUFFERS_FOR_QUEUE( \
            5U, \
            sizeof(__termina_box_t) \
        ) \
    )

#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_MICROSECONDS_PER_TICK 10000

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT

#include <rtems/confdefs.h>
