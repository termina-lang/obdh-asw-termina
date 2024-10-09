
#include <rtems.h>

#include <termina.h>

void __termina_app__init_globals();

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
