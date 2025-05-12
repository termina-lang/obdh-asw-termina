#ifndef __TASKS__ICU_MANAGER__ICU_MANAGER_H__
#define __TASKS__ICU_MANAGER__ICU_MANAGER_H__

#include <termina.h>

#include "tasks/icu_manager/mng_tc_executor.h"

#include "option.h"

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    struct {
        void * __that;
        void (* PUS_prio_exec_tc)(void * const, TCHandlerT * const,
                                  __status_int32_t * const);
    } tc_executor;
    __termina_out_port_t bkg_message_queue_output;
    __termina_out_port_t hkfdir_message_queue_output;
    __termina_allocator_t a_tc_handler_pool;
    __termina_id_t action_tc_message_queue_input;
    __termina_id_t tc_message_queue_input;
} ICUManager;

void __ICUManager__termina_task(void * const arg);

__status_int32_t ICUManager__process_action_tc(void * const __this,
                                               __termina_box_t tc_handler);

__status_int32_t ICUManager__process_tc(void * const __this,
                                        __termina_box_t tc_handler);

#endif
