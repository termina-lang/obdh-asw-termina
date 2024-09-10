
#include <rtems.h>

#include <termina.h>

#include "app.h"

#include "libraries/event_list.h"

#include "libraries/pus_services/pus_service1.h"

#include "libraries/pus_services/pus_service12.h"

#include "libraries/pus_services/pus_service128.h"

#include "libraries/pus_services/pus_service19.h"

#include "libraries/pus_services/pus_service2.h"

#include "libraries/pus_services/pus_service3.h"

#include "libraries/pus_services/pus_service5.h"

#include "libraries/pus_services/pus_service9.h"

#include "libraries/queue_u8.h"

#include "libraries/tc_ccsds_pus_format.h"

#include "resources/system_data_pool.h"

#include "resources/uart.h"

extern void __termina_app__init_globals();

_Atomic uint16_t system_data_pool[SDP_num_params];

void __rtems_app__inital_event(TimeVal * current) {
    
    Init * self = &init;

    Result result;

    result.__variant = Result__Ok;

    result = Init__init(self, *current);

    if (result.__variant != Result__Ok) {
        rtems_shutdown_executive(1);
    }

    return;

}

static void __rtems_app__enable_protection() {
    
    Result result;

    result.__variant = Result__Ok;

    uart_drv.__resource.lock = __RTEMSResourceLock__None;

}

static void __rtems_app__init_globals() {
    
    Result result;

    result.__variant = Result__Ok;

    uart_drv.__resource.lock = __RTEMSResourceLock__None;

}

static void __rtems_app__install_emitters(TimeVal * current) {
    
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

    __rtems_app__inital_event(&current);

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
