#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20__PUS_SERVICE20_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service20/pus_service20_help.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const, Result * const);
} PUSS20Iface;

typedef struct {
    __termina_id_t __mutex_id;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, Result * const);
    } tm_channel;
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    PS20ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService20;

void PUSService20__build_tm_20_2(const PUSService20 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter,
                                 Result * const result);

PSExecTCReqStatus PUSService20__exec20_1TC(PUSService20 * const self);

PSExecTCReqStatus PUSService20__exec20_3TC(PUSService20 * const self);

PS20ExecTCReqStatusUpdate PUSService20__get_TC_params(const PUSService20 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      Result * const result);

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const PUSService20 * const self);

void PUSService20__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           Result * const result);
void PUSService20__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result);
void PUSService20__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result);
void PUSService20__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result);

#endif
