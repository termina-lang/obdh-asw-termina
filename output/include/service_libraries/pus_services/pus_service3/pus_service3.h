#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3__PUS_SERVICE3_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3__PUS_SERVICE3_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service3/pus_service3_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* do_hk)(void * const, __status_int32_t * const);
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* update_params)(void * const);
} PUSS3Iface;

typedef struct {
    __termina_id_t __mutex_id;
    uint32_t random_seed;
    struct {
        void * __that;
        void (* build_and_tx_tm_5_2)(void * const, __status_int32_t * const);
    } pus_service_5;
    struct {
        void * __that;
        void (* get_current_obt)(void * const, MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    PS3ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    HKConfiguration hk_config_table[8U];
} PUSService3;

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, size_t index,
                                MyResult * const result);

void PUSService3__do_hk(void * const __this,
                        __status_int32_t * const action_status);
void PUSService3__do_hk__mutex_lock(void * const __this,
                                    __status_int32_t * const action_status);
void PUSService3__do_hk__task_lock(void * const __this,
                                   __status_int32_t * const action_status);
void PUSService3__do_hk__event_lock(void * const __this,
                                    __status_int32_t * const action_status);

IndexFound PUSService3__get_SIDindex(PUSService3 * const self);

PSExecTCReqStatus PUSService3__exec3_31TC(PUSService3 * const self);

PSExecTCReqStatus PUSService3__exec3_5TC(PUSService3 * const self);

PSExecTCReqStatus PUSService3__exec3_6TC(PUSService3 * const self);

PS3TCData PUSService3__get_TC_params(const PUSService3 * const self,
                                     TCHandlerT * const tc_handler,
                                     uint8_t * const subtype,
                                     MyResult * const result);

PSExecTCReqStatus PUSService3__manage_error_in_acceptance(const PUSService3 * const self);

PSExecTCReqStatus PUSService3__manage_short_pack_length_error(const PUSService3 * const self);

PSExecTCReqStatus PUSService3__manage_tm_limit_app_data_reached(const PUSService3 * const self);

void PUSService3__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);
void PUSService3__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService3__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status);
void PUSService3__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);

void PUSService3__update_params(void * const __this);
void PUSService3__update_params__mutex_lock(void * const __this);
void PUSService3__update_params__task_lock(void * const __this);
void PUSService3__update_params__event_lock(void * const __this);

#endif
