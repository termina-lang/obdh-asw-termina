#ifndef __TASKS__HKFDIRMNG_H__
#define __TASKS__HKFDIRMNG_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service12.h"
#include "service_libraries/pus_services/pus_service5.h"
#include "service_libraries/pus_services/pus_service19.h"
#include "service_libraries/event_list.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/serialize.h"
#include "handlers/init.h"
#include "resources/tm_counter.h"
#include "resources/system_data_pool.h"

typedef struct {
    __termina_task_t __task;
    __termina_out_port_t action_tc_message_queue_output;
    __termina_out_port_t tm_message_queue_output;
    TMCounterIface tm_counter;
    _Atomic uint16_t * system_data_pool;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_pool_t * a_tm_descriptor_pool;
    TCDescriptorT pus_serv19_event_action_packets[max_event_action_definitions];
    EventActionConfig pus_serv19_event_action_config[max_event_action_definitions];
    uint32_t pus_serv5_RID_enable_config[4];
    EventList event_list;
    ParamLimitCheckDefinition pus_serv12_param_limit_check_definition[max_num_pmon_ids];
    ParamMonitoringConfiguration pus_serv12_param_mon_config_table[max_num_pmon_ids];
    HKConfiguration pus_serv3_hk_config_table[max_num_of_SIDs];
    __termina_in_port_t hkfdir_message_queue_input;
    __termina_sink_port_t hk_fdir_timer_ev;
} HK_FDIR_Manager;

Result HK_FDIR_Manager__pus_serv19_manage_event_actions(HK_FDIR_Manager * const self);

Result HK_FDIR_Manager__do_hk_fdir(HK_FDIR_Manager * const self,
                                   TimeVal _current_time);

Result HK_FDIR_Manager__pus_serv5_build_event_list_tms(HK_FDIR_Manager * const self);

Result HK_FDIR_Manager__pus_serv3_do_hk(HK_FDIR_Manager * const self);

void HK_FDIR_Manager__pus_serv3_build_tm_3_25(const HK_FDIR_Manager * const self,
                                              TMDescriptorT * p_tm_descriptor,
                                              uint16_t tm_seq_counter,
                                              size_t index);

Result HK_FDIR_Manager__pus_serv12_do_monitoring(HK_FDIR_Manager * const self);

Result HK_FDIR_Manager__PUS_hk_fdir_exec_tc(HK_FDIR_Manager * const self,
                                            __termina_dyn_t tc_descriptor);

#endif
