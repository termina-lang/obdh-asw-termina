#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service3/internal.h"

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    uint32_t random_seed;
    struct {
        void * _that;
        void (* send_tm_5_2)(const termina__event_t * const termina__ev, void * const termina__this, Status__i32 * const status);
    } pus_service_5;
    struct {
        void * _that;
        void (* notify_tm_1_3)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t flags_ack, Status__i32 * const status);
        void (* notify_tm_1_7)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_4_SID_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint16_t SID, Status__i32 * const status);
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t N, Status__i32 * const status);
        void (* send_tm_1_4_short_pack_length)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const size_t tc_bytes, Status__i32 * const status);
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
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    HKConfiguration hk_config_table[8U];
} CPUSService3;

void CPUSService3__do_hk(const termina__event_t * const termina__ev, void * const termina__this, Status__i32 * const action_status);

void CPUSService3__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);

void CPUSService3__update_params(const termina__event_t * const termina__ev, void * const termina__this);

#endif
