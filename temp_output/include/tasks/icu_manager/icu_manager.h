#ifndef __TASKS__ICU_MANAGER__ICU_MANAGER_H__
#define __TASKS__ICU_MANAGER__ICU_MANAGER_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service9.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service128.h"
#include "resources/tm_counter.h"

typedef struct {
    __termina_task_t __task;
    TCStatus current_tc_status;
    TCDescriptorT current_tc;
    PUSS3Iface pus_service_3;
    TMCounterIface tm_counter;
    TMChannelIface tm_channel;
    __termina_out_port_t bkg_message_queue_output;
    __termina_out_port_t hkfdir_message_queue_output;
    __termina_pool_t * a_tm_descriptor_pool;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_in_port_t action_tc_message_queue_input;
    __termina_in_port_t tc_message_queue_input;
} ICUManager;

Result ICUManager__PUS_prio_exec_tc(ICUManager * const self);

Result ICUManager__mng_tc_acceptation(ICUManager * const self);

Result ICUManager__mng_tc_rejection(ICUManager * const self);

Result ICUManager__process_action_tc(ICUManager * const self,
                                     __termina_box_t tc_descriptor);

Result ICUManager__process_tc(ICUManager * const self,
                              __termina_box_t tc_descriptor);

#endif
