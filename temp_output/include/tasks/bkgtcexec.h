#ifndef __TASKS__BKGTCEXEC_H__
#define __TASKS__BKGTCEXEC_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service20.h"
#include "service_libraries/serialize.h"
#include "resources/system_data_pool.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "resources/tm_counter.h"

typedef struct {
    __termina_task_t __task;
    PUSS20Iface pus_service_20;
    TMCounterIface tm_counter;
    TMChannelIface tm_channel;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_pool_t * a_tm_descriptor_pool;
    __termina_in_port_t bkg_message_queue_input;
} PUSBKGTCExecutor;

Result PUSBKGTCExecutor__exec_tc(PUSBKGTCExecutor * const self,
                                 __termina_box_t tc_descriptor);

#endif
