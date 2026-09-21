#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/system_data_pool.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service12/internal.h"
#include "service_libraries/pus_services/pus_service5.h"

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* notify_tm_1_3)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* notify_tm_1_7)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_4_PID_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PID, Status__i32 * const status);
        void (* send_tm_1_4_PMONID_invalid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PMONID, Status__i32 * const status);
        void (* send_tm_1_4_PMON_definition_invalid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PMONID, Status__i32 * const status);
        void (* send_tm_1_4_PMON_enabled)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PMONID, Status__i32 * const status);
        void (* send_tm_1_4_PMON_undefined)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PMONID, Status__i32 * const status);
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t N, Status__i32 * const status);
        void (* send_tm_1_4_short_pack_length)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, size_t tc_bytes, Status__i32 * const status);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
    } pus_service_1;
    struct {
        void * _that;
        void (* get_current_obt)(const termina__event_t * const termina__ev, void * const termina__this, MissionOBT * const current_obt);
    } obt_manager;
    struct {
        void * _that;
        void (* get_next_tm_count)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t * const count);
    } tm_counter;
    termina__allocator_t tm_handler_pool;
    struct {
        void * _that;
        void (* send_tm)(const termina__event_t * const termina__ev, void * const termina__this, termina__box_t tm_handler, Status__i32 * const status);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    ParamMonitoringTransition param_mon_transitions_table[1U];
    uint8_t monitoring_transition_counter;
    ParamMonitoringConfiguration param_mon_config_table[16U];
    PS12ExecTCReqStatusUpdate exec_tc_req_status_update;
    DoMonitoringReqStatusUpdate do_monitoring_req_status_update;
    DoMonitoringReqStatus do_monitoring_req_status;
} CPUSService12;

void CPUSService12__do_monitoring(const termina__event_t * const termina__ev, void * const termina__this, uint16_t PMONID, uint16_t * const evID, FaultInfo * const fault_info, _Bool * const event_triggered, Status__i32 * const status);

void CPUSService12__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);

void CPUSService12__is_PMON_enabled(const termina__event_t * const termina__ev, void * const termina__this, size_t PMONID, _Bool * const is_enabled);

#endif
