#ifndef __TASKS__HK_FDIR_MNG__HK_FDIR_H__
#define __TASKS__HK_FDIR_MNG__HK_FDIR_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service12/pus_service12.h"
#include "service_libraries/pus_services/pus_service19.h"

#define num_actions_per_second 2

typedef struct {
    __termina_task_t __task;
    PUSS19Iface pus_service_19;
    PUSS5Iface pus_service_5;
    PUSS12Iface pus_service_12;
    PUSS3Iface pus_service_3;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_out_port_t action_tc_message_queue_output;
    __termina_sink_port_t hk_fdir_timer_ev;
} HouseKeepingFDIR;

void HouseKeepingFDIR__manage_actions(HouseKeepingFDIR * const self);

Result HouseKeepingFDIR__do_hk_fdir(HouseKeepingFDIR * const self,
                                    TimeVal _current_time);

#endif
