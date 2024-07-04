#ifndef __TASKS__HKFDIRMNG_H__
#define __TASKS__HKFDIRMNG_H__

#include <termina.h>

#include "option.h"
#include "libraries/pus_services/pus_service3.h"
#include "libraries/pus_services/pus_service12.h"
#include "libraries/pus_services/pus_service5.h"
#include "libraries/pus_services/pus_services.h"
#include "libraries/event_list.h"
#include "libraries/tm_ccsds_pus_format.h"
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/serialize.h"
#include "handlers/init.h"
#include "resources/tm_counter.h"

typedef struct {
    __termina_task_t __task;
    __termina_out_port_t tm_message_queue_output;
    TMCounterIface tm_counter;
    _Atomic uint16_t * system_data_pool;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_pool_t * a_tm_descriptor_pool;
    uint32_t RID_enable_config[4];
    EventList event_list;
    ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids];
    ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids];
    HKConfiguration hk_config_table[max_num_of_SIDs];
    __termina_in_port_t hkfdir_message_queue_input;
    __termina_sink_port_t hk_fdir_timer_ev;
} HK_FDIR_Manager;

void HK_FDIR_Manager__pus_serv5_build_event_list_tms(HK_FDIR_Manager * const self);

Result HK_FDIR_Manager__exec_tc(HK_FDIR_Manager * const self,
                                __termina_dyn_t tc_descriptor);

Result HK_FDIR_Manager__do_hk_fdir(HK_FDIR_Manager * const self,
                                   TimeVal _current_time);

Result HK_FDIR_Manager__pus_serv3_do_hk(HK_FDIR_Manager * const self);

void HK_FDIR_Manager__pus_serv3_build_tm_3_25(const HK_FDIR_Manager * const self,
                                              TMDescriptorT * p_tm_descriptor,
                                              uint16_t tm_seq_counter,
                                              size_t index);

Result HK_FDIR_Manager__pus_serv12_do_monitoring(HK_FDIR_Manager * const self);

#endif
