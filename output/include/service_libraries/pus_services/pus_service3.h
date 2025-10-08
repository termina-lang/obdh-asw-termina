#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service3/internal.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* do_hk)(void * const, __status_int32_t * const);
    void (* exec_tc)(void * const, TCHandler * const, __status_int32_t * const);
    void (* update_params)(void * const);
} PUSS3Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    uint32_t random_seed;
    struct {
        void * __that;
        void (* send_tm_5_2)(const __termina_event_t * const, void * const, __status_int32_t * const);
    } pus_service_5;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_4_SID_not_valid)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint16_t, __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const, void * const, uint16_t, uint16_t, size_t, __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
    } pus_service_1;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const, MissionOBT * const);
    } obt_manager;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const, void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const, void * const, __termina_box_t, __status_int32_t * const);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    HKConfiguration hk_config_table[8U];
} PUSService3;

void PUSService3__do_hk(const __termina_event_t * const __ev, void * const __this, __status_int32_t * const action_status);

__option_size_t PUSService3__get_SIDindex(const __termina_event_t * const __ev, const PUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

__status_int32_t PUSService3__exec3_31TC(const __termina_event_t * const __ev, PUSService3 * const self, PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

__status_int32_t PUSService3__exec3_5TC(const __termina_event_t * const __ev, PUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

__status_int32_t PUSService3__exec3_6TC(const __termina_event_t * const __ev, PUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

void PUSService3__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);

void PUSService3__update_params(const __termina_event_t * const __ev, void * const __this);

#endif
