
#include <rtems.h>

#include <termina.h>

#include "app.h"

void __termina_app__init_globals();

#define __HouseKeepingFDIR__hk_fdir_timer_ev 0

#define __PUSBKGTCExecutor__bkg_message_queue_input 0

#define __PUSHKFDIRTCExcutor__hkfdir_message_queue_input 0

 _Atomic uint16_t system_data_pool[sdp_num_params];

static rtems_task __rtems_task__HouseKeepingFDIR(rtems_task_argument arg) {
    
    HouseKeepingFDIR * self = (HouseKeepingFDIR *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0;
    size_t size = 0;

    Result result;
    result.__variant = Result__Ok;

    TimeVal do_hk_fdir__msg_data;

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
                    rtems_shutdown_executive(1);
                }

                result = HouseKeepingFDIR__do_hk_fdir(self,
                                                      do_hk_fdir__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1);
                }

                break;

            default:

                rtems_shutdown_executive(1);

                break;

        }

    }

    rtems_shutdown_executive(1);

    return;

}

static rtems_task __rtems_task__PUSBKGTCExecutor(rtems_task_argument arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0;
    size_t size = 0;

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
                    rtems_shutdown_executive(1);
                }

                result = PUSBKGTCExecutor__exec_tc(self, exec_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1);
                }

                break;

            default:

                rtems_shutdown_executive(1);

                break;

        }

    }

    rtems_shutdown_executive(1);

    return;

}

static rtems_task __rtems_task__PUSHKFDIRTCExcutor(rtems_task_argument arg) {
    
    PUSHKFDIRTCExcutor * self = (PUSHKFDIRTCExcutor *)arg;
    rtems_status_code status = RTEMS_SUCCESSFUL;
    uint32_t next_msg = 0;
    size_t size = 0;

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
            
            case __PUSHKFDIRTCExcutor__hkfdir_message_queue_input:

                status = rtems_message_queue_receive(self->hkfdir_message_queue_input,
                                                     (void *)&exec_tc__msg_data,
                                                     &size, RTEMS_NO_WAIT,
                                                     RTEMS_NO_TIMEOUT);

                if (RTEMS_SUCCESSFUL != status) {
                    rtems_shutdown_executive(1);
                }

                result = PUSHKFDIRTCExcutor__exec_tc(self, exec_tc__msg_data);

                if (result.__variant != Result__Ok) {
                    rtems_shutdown_executive(1);
                }

                break;

            default:

                rtems_shutdown_executive(1);

                break;

        }

    }

    rtems_shutdown_executive(1);

    return;

}

static void __rtems_app__enable_protection() {
    
    Result result;
    result.__variant = Result__Ok;

}

static void __rtems_app__init_globals() {
    
    Result result;
    result.__variant = Result__Ok;

}

static void __rtems_app__install_emitters(TimeVal * const current) {
    
    rtems_status_code status = RTEMS_SUCCESSFUL;

}

static void __rtems_app__create_tasks() {
    
    rtems_status_code status = RTEMS_SUCCESSFUL;

}

rtems_task Init(rtems_task_argument _ignored) {
    
    TimeVal current;

    __termina__clock_get_uptime(&current);

    __termina_app__init_globals();

    __rtems_app__init_globals();

    __rtems_app__enable_protection();

    __rtems_app__install_emitters(&current);

    __rtems_app__create_tasks();

    rtems_task_delete(RTEMS_SELF);

}

#define CONFIGURE_MAXIMUM_TASKS 1
#define CONFIGURE_MAXIMUM_MESSAGE_QUEUES 0
#define CONFIGURE_MAXIMUM_TIMERS 0
#define CONFIGURE_MAXIMUM_SEMAPHORES 0

#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_MICROSECONDS_PER_TICK 10000

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT

#include <rtems/confdefs.h>
