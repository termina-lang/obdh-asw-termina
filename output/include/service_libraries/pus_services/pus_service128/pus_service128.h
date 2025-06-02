#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128__PUS_SERVICE128_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE128__PUS_SERVICE128_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service128/pus_service128_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const, __status_int32_t * const,
                     _Bool * const);
} PUSS128Iface;

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
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
    PS128ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService128;

PSExecTCReqStatus PUSService128__exec128_1TC(PUSService128 * const self);

PS128ExecTCReqStatusUpdate PUSService128__get_TC_params(const PUSService128 * const self,
                                                        TCHandlerT * const tc_handler,
                                                        uint8_t * const subtype);

PSExecTCReqStatus PUSService128__manage_error_in_acceptance(const PUSService128 * const self);

PSExecTCReqStatus PUSService128__manage_tm_limit_app_data_reached(const PUSService128 * const self);

void PUSService128__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag);
void PUSService128__exec_tc__mutex_lock(void * const __this,
                                        TCHandlerT * const tc_handler,
                                        __status_int32_t * const action_status,
                                        _Bool * const reebot_flag);
void PUSService128__exec_tc__task_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status,
                                       _Bool * const reebot_flag);
void PUSService128__exec_tc__event_lock(void * const __this,
                                        TCHandlerT * const tc_handler,
                                        __status_int32_t * const action_status,
                                        _Bool * const reebot_flag);

#endif
