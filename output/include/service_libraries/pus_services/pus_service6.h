#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service6/internal.h"

#include "option.h"

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* notify_tm_1_7)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
        void (* send_tm_1_4_mem_address_not_valid)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t mem_id, uint32_t mem_address, __status_int32_t * const status);
        void (* send_tm_1_4_mem_id_read_only)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t mem_id, __status_int32_t * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t N, __status_int32_t * const status);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, size_t tc_bytes, __status_int32_t * const status);
        void (* send_tm_1_8_mem_access_error)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t mem_ID, __status_int32_t * const status);
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
    volatile uint8_t (* memory)[16777216U];
    _Bool mem_id_write_permissions[8U];
    PS6ExecTCReqStatusUpdate exec_tc_req_status_update;
} CPUSService6;

void CPUSService6__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);

#endif
