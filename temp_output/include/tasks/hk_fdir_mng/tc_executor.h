#ifndef __TASKS__HK_FDIR_MNG__TC_EXECUTOR_H__
#define __TASKS__HK_FDIR_MNG__TC_EXECUTOR_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service12/pus_service12.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service19.h"

typedef struct {
    __termina_task_t __task;
    PUSS19Iface pus_service_19;
    PUSS5Iface pus_service_5;
    PUSS12Iface pus_service_12;
    PUSS3Iface pus_service_3;
    TMCounterIface tm_counter;
    TMChannelIface tm_channel;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_pool_t * a_tm_descriptor_pool;
    __termina_in_port_t hkfdir_message_queue_input;
} PUSHKFDIRTCExcutor;

Result PUSHKFDIRTCExcutor__exec_tc(PUSHKFDIRTCExcutor * const self,
                                   __termina_box_t tc_descriptor);

#endif
