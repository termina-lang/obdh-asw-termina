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
    __termina_resource_lock_type_t __lock_type;
    uint32_t random_seed;
    struct {
        void * __that;
        void (* build_and_tx_tm_5_2)(const __termina_event_t * const,
                                     void * const, __status_int32_t * const);
    } pus_service_5;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const,
                                   void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const, void * const,
                         __termina_box_t, __status_int32_t * const);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    PS3ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    HKConfiguration hk_config_table[8U];
} PUSService3;

void PUSService3__build_tm_3_25(const __termina_event_t * const __ev,
                                const PUSService3 * const self,
                                TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, size_t index,
                                __status_int32_t * const status);

void PUSService3__do_hk(const __termina_event_t * const __ev,
                        void * const __this,
                        __status_int32_t * const action_status);

IndexFound PUSService3__get_SIDindex(const __termina_event_t * const __ev,
                                     PUSService3 * const self);

PSExecTCReqStatus PUSService3__exec3_31TC(const __termina_event_t * const __ev,
                                          PUSService3 * const self);

PSExecTCReqStatus PUSService3__exec3_5TC(const __termina_event_t * const __ev,
                                         PUSService3 * const self);

PSExecTCReqStatus PUSService3__exec3_6TC(const __termina_event_t * const __ev,
                                         PUSService3 * const self);

PSExecTCReqStatus PUSService3__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                          const PUSService3 * const self);

PSExecTCReqStatus PUSService3__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                              const PUSService3 * const self);

PSExecTCReqStatus PUSService3__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                const PUSService3 * const self);

void PUSService3__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);

void PUSService3__update_params(const __termina_event_t * const __ev,
                                void * const __this);

#endif
