#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service5/internal.h"

#include "option.h"

typedef enum {
    FaultInfo__ParamOutOfLimit,
    FaultInfo__ParamFaultValue,
    FaultInfo__Empty
} termina__enum__FaultInfo_t;

typedef struct {
    ParamOutOfLimitInfo _0;
} termina__enum__FaultInfo__ParamOutOfLimit_params_t;

typedef struct {
    ParamFaultValueInfo _0;
} termina__enum__FaultInfo__ParamFaultValue_params_t;

typedef struct {
    termina__enum__FaultInfo_t _variant;
    union {
        termina__enum__FaultInfo__ParamOutOfLimit_params_t ParamOutOfLimit;
        termina__enum__FaultInfo__ParamFaultValue_params_t ParamFaultValue;
    };
} FaultInfo;

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* notify_tm_1_3)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* notify_tm_1_7)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_4_EvID_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint16_t EvID, Status__i32 * const status);
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
    PS5ExecTCReqStatusUpdate exec_tc_req_status_update;
    uint32_t Ev_ID_enable_config[4U];
} CPUSService5;

void CPUSService5__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);

void CPUSService5__is_Ev_ID_enabled_ext(const termina__event_t * const termina__ev, void * const termina__this, uint16_t Ev_ID, _Bool * const p_enabled);

void CPUSService5__send_tm_5_2(const termina__event_t * const termina__ev, void * const termina__this, Status__i32 * const status);

void CPUSService5__send_tm_5_x(const termina__event_t * const termina__ev, void * const termina__this, uint16_t evID, const FaultInfo * const fault_info, Status__i32 * const status);

#endif
