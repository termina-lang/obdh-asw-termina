#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service6/internal.h"

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* notify_tm_1_3)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t flags_ack, Status__i32 * const status);
        void (* notify_tm_1_7)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
        void (* send_tm_1_4_mem_address_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t mem_id, const uint32_t mem_address, Status__i32 * const status);
        void (* send_tm_1_4_mem_id_read_only)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t mem_id, Status__i32 * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t N, Status__i32 * const status);
        void (* send_tm_1_4_short_pack_length)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const size_t tc_bytes, Status__i32 * const status);
        void (* send_tm_1_8_mem_access_error)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t mem_ID, Status__i32 * const status);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
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
        void (* send_tm)(const termina__event_t * const termina__ev, void * const termina__this, const termina__box_t tm_handler, Status__i32 * const status);
    } tm_channel;
    volatile uint8_t (* memory)[16777216U];
    _Bool mem_id_write_permissions[8U];
    PS6ExecTCReqStatusUpdate exec_tc_req_status_update;
} CPUSService6;

void CPUSService6__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);

#endif
