#ifndef __TASKS__ICU_MANAGER__ICU_MANAGER_H__
#define __TASKS__ICU_MANAGER__ICU_MANAGER_H__

#include <termina.h>

#include "option.h"
#include "tasks/icu_manager/mng_tc_executor.h"

typedef struct {
    __termina_task_t __task;
    MngTCExecIface tc_executor;
    __termina_out_port_t bkg_message_queue_output;
    __termina_out_port_t hkfdir_message_queue_output;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_in_port_t action_tc_message_queue_input;
    __termina_in_port_t tc_message_queue_input;
} ICUManager;

Result ICUManager__process_action_tc(ICUManager * const self,
                                     __termina_box_t tc_descriptor);

Result ICUManager__process_tc(ICUManager * const self,
                              __termina_box_t tc_descriptor);

#endif
