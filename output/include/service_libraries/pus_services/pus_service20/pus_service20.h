#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service20/pus_service20_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS20Iface;

typedef struct {
    __termina_id_t __mutex_id;
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
        void (* send_tm)(void * const, __termina_box_t,
                         __status_int32_t * const);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    PS20ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService20;

void PUSService20__build_tm_20_2(const PUSService20 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter,
                                 __status_int32_t * const status);

PSExecTCReqStatus PUSService20__exec20_1TC(PUSService20 * const self);

PSExecTCReqStatus PUSService20__exec20_3TC(PUSService20 * const self);

PSExecTCReqStatus PUSService20__manage_error_in_acceptance(const PUSService20 * const self);

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const PUSService20 * const self);

PSExecTCReqStatus PUSService20__manage_tm_limit_app_data_reached(const PUSService20 * const self);

void PUSService20__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);
void PUSService20__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);
void PUSService20__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService20__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);

#endif
