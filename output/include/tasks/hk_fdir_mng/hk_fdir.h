#ifndef __TASKS__HK_FDIR_MNG__HK_FDIR_H__
#define __TASKS__HK_FDIR_MNG__HK_FDIR_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/pus_services/pus_service12.h"
#include "service_libraries/pus_services/pus_service19.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service4.h"
#include "service_libraries/pus_services/pus_service5.h"

#include "option.h"

extern const size_t num_actions_per_second;

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    struct {
        void * __that;
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
    } pus_service_1;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
        void (* update_all_stats)(const __termina_event_t * const __ev, void * const __this);
    } pus_service_4;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
        void (* extract_action)(const __termina_event_t * const __ev, void * const __this, size_t action_index, TCHandler * const action_packet);
        void (* get_pending_action_number)(const __termina_event_t * const __ev, void * const __this, size_t paction_num[4U]);
        void (* manage_event_action)(const __termina_event_t * const __ev, void * const __this, uint16_t evID);
    } pus_service_19;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
        void (* is_Ev_ID_enabled_ext)(const __termina_event_t * const __ev, void * const __this, uint16_t Ev_ID, _Bool * const p_enabled);
        void (* send_tm_5_x)(const __termina_event_t * const __ev, void * const __this, uint16_t evID, const FaultInfo * const fault_info, __status_int32_t * const status);
    } pus_service_5;
    struct {
        void * __that;
        void (* do_monitoring)(const __termina_event_t * const __ev, void * const __this, uint16_t PMONID, uint16_t * const evID, FaultInfo * const fault_info, _Bool * const event_triggered, __status_int32_t * const status);
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
        void (* is_PMON_enabled)(const __termina_event_t * const __ev, void * const __this, size_t PMONID, _Bool * const is_enabled);
    } pus_service_12;
    struct {
        void * __that;
        void (* do_hk)(const __termina_event_t * const __ev, void * const __this, __status_int32_t * const action_status);
        void (* exec_tc)(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);
        void (* update_params)(const __termina_event_t * const __ev, void * const __this);
    } pus_service_3;
    __termina_allocator_t tc_handler_pool;
    __termina_out_port_t action_tc_message_queue_output;
    __termina_id_t hkfdir_message_queue_input;
    __termina_id_t hk_fdir_timer_ev;
} CHousekeepingFDIRTask;

void __CHousekeepingFDIRTask__termina_task(void * const arg);

__status_int32_t CHousekeepingFDIRTask__check_pending_actions(const __termina_event_t * const __ev, void * const __this);

__status_int32_t CHousekeepingFDIRTask__do_fdir(const __termina_event_t * const __ev, void * const __this);

__status_int32_t CHousekeepingFDIRTask__do_hk_fdir(const __termina_event_t * const __ev, void * const __this, TimeVal _current_time);

__status_int32_t CHousekeepingFDIRTask__exec_tc(const __termina_event_t * const __ev, void * const __this, __termina_box_t tc_handler);

#endif
