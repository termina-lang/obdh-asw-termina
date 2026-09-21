#ifndef TASKS__HK_FDIR_MNG__HK_FDIR_H__
#define TASKS__HK_FDIR_MNG__HK_FDIR_H__

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
    termina__id_t _task_id;
    termina__id_t _task_msg_queue_id;
    struct {
        void * _that;
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
    } pus_service_1;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
        void (* update_all_stats)(const termina__event_t * const termina__ev, void * const termina__this);
    } pus_service_4;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
        void (* extract_action)(const termina__event_t * const termina__ev, void * const termina__this, const size_t action_index, TCHandler * const action_packet);
        void (* get_pending_action_number)(const termina__event_t * const termina__ev, void * const termina__this, size_t paction_num[4U]);
        void (* manage_event_action)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t evID);
    } pus_service_19;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
        void (* is_Ev_ID_enabled_ext)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t Ev_ID, _Bool * const p_enabled);
        void (* send_tm_5_x)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t evID, const FaultInfo * const fault_info, Status__i32 * const status);
    } pus_service_5;
    struct {
        void * _that;
        void (* do_monitoring)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t PMONID, uint16_t * const evID, FaultInfo * const fault_info, _Bool * const event_triggered, Status__i32 * const status);
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
        void (* is_PMON_enabled)(const termina__event_t * const termina__ev, void * const termina__this, const size_t PMONID, _Bool * const is_enabled);
    } pus_service_12;
    struct {
        void * _that;
        void (* do_hk)(const termina__event_t * const termina__ev, void * const termina__this, Status__i32 * const action_status);
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
        void (* update_params)(const termina__event_t * const termina__ev, void * const termina__this);
    } pus_service_3;
    termina__allocator_t tc_handler_pool;
    termina__out_port_t action_tc_message_queue_output;
    termina__id_t hkfdir_message_queue_input;
    termina__id_t hk_fdir_timer_ev;
} CHousekeepingFDIRTask;

void termina__task_entry__CHousekeepingFDIRTask(void * const arg);

Status__i32 CHousekeepingFDIRTask__check_pending_actions(const termina__event_t * const termina__ev, void * const termina__this);

Status__i32 CHousekeepingFDIRTask__do_fdir(const termina__event_t * const termina__ev, void * const termina__this);

Status__i32 CHousekeepingFDIRTask__do_hk_fdir(const termina__event_t * const termina__ev, void * const termina__this, const TimeVal termina__ignored__current_time);

Status__i32 CHousekeepingFDIRTask__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, const termina__box_t tc_handler);

#endif
