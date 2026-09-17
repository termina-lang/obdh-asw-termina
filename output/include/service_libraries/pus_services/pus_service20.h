#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service20/types.h"

#include "option.h"

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* notify_tm_1_7)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* send_tm_1_4_PID_not_valid)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PID, __status_int32_t * const status);
        void (* send_tm_1_4_PID_read_only_via_TC)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t PID, __status_int32_t * const status);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t N, __status_int32_t * const status);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, size_t tc_bytes, __status_int32_t * const status);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
    } pus_service_1;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const __ev, void * const __this, MissionOBT * const current_obt);
    } obt_manager;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const __ev, void * const __this, uint16_t * const count);
    } tm_counter;
    __termina_allocator_t tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const __ev, void * const __this, __termina_box_t tm_handler, __status_int32_t * const status);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    PS20ExecTCReqStatusUpdate exec_tc_req_status_update;
} CPUSService20;

void CPUSService20__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);

#endif
