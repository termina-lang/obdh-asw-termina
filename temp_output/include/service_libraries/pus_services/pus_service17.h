#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/tc_ccsds_pus_format.h"

typedef enum {
    PS17ExecTCReqStatus__ExecTC,
    PS17ExecTCReqStatus__Error,
    PS17ExecTCReqStatus__Exit
} __enum_PS17ExecTCReqStatus_t;

typedef struct {
    __enum_PS17ExecTCReqStatus_t __variant;
} PS17ExecTCReqStatus;

void build_tm_17_2(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                   Result * const result);

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const, Result * const);
} PUSS17Iface;

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
    PS17ExecTCReqStatus exec_tc_req_status;
} PUSService17;

PS17ExecTCReqStatus PUSService17__exec17_1TC(PUSService17 * const self);

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           Result * const result);
void PUSService17__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result);
void PUSService17__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result);
void PUSService17__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result);

#endif
