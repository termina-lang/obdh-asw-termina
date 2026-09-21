#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service17/internal.h"

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* notify_tm_1_3)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t flags_ack, Status__i32 * const status);
        void (* notify_tm_1_7)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, const uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, const uint16_t tc_packet_id, const uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
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
    PS17ExecTCReqStatusUpdate exec_tc_req_status_update;
} CPUSService17;

void CPUSService17__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);

#endif
