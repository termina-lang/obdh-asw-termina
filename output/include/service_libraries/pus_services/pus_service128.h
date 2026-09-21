#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service128/types.h"
#include "service_libraries/pus_tc_handler.h"

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
    PS128ExecTCReqStatusUpdate exec_tc_req_status_update;
} CPUSService128;

void CPUSService128__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status, _Bool * const reebot_flag);

#endif
