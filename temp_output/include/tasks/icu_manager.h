#ifndef __TASKS__ICU_MANAGER_H__
#define __TASKS__ICU_MANAGER_H__

#include <termina.h>

#include "option.h"
#include "libraries/serialize.h"
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/tm_ccsds_pus_format.h"
#include "libraries/crc.h"
#include "libraries/pus_services/pus_service17.h"
#include "libraries/pus_services/pus_service1.h"
#include "libraries/pus_services/pus_service128.h"
#include "libraries/pus_services/pus_service2.h"
#include "libraries/pus_services/pus_service9.h"
#include "resources/tm_counter.h"

typedef struct {
    __termina_task_t __task;
    TCStatus tc_status;
    TMCounterIface tm_counter;
    __termina_out_port_t tm_message_queue_output;
    __termina_out_port_t bkg_message_queue_output;
    __termina_out_port_t hkfdir_message_queue_output;
    __termina_pool_t * a_tm_descriptor_pool;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_in_port_t action_tc_message_queue_input;
    __termina_in_port_t tc_message_queue_input;
} ICUManager;

Result ICUManager__process_tc(ICUManager * const self,
                              __termina_dyn_t tc_descriptor);

Result ICUManager__process_action_tc(ICUManager * const self,
                                     __termina_dyn_t tc_descriptor);

void ICUManager__PUS_prio_exec_tc(const ICUManager * const self,
                                  const TCDescriptorT * tc_descriptor,
                                  TMDescriptorT * tm_descriptor,
                                  uint16_t tm_seq_counter);

#endif
