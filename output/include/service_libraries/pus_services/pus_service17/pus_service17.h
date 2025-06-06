#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17__PUS_SERVICE17_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17__PUS_SERVICE17_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service17/pus_service17_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS17Iface;

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
    PS17ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService17;

void PUSService17__build_tm_17_2(const PUSService17 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter);

PSExecTCReqStatus PUSService17__exec17_1TC(PUSService17 * const self);

PSExecTCReqStatus PUSService17__manage_error_in_acceptance(const PUSService17 * const self);

PSExecTCReqStatus PUSService17__manage_tm_limit_app_data_reached(const PUSService17 * const self);

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);
void PUSService17__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);
void PUSService17__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService17__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);

PS17ExecTCReqStatusUpdate PUSService17__get_TC_params(const PUSService17 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype);

#endif
