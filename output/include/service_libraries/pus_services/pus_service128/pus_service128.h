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
    __termina_resource_lock_type_t __lock_type;
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
    PS128ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService128;

PSExecTCReqStatus PUSService128__exec128_1TC(const __termina_event_t * const __ev,
                                             PUSService128 * const self);

PSExecTCReqStatus PUSService128__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                            const PUSService128 * const self);

PSExecTCReqStatus PUSService128__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                  const PUSService128 * const self);

void PUSService128__exec_tc(const __termina_event_t * const __ev,
                            void * const __this, TCHandlerT * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag);

PS128ExecTCReqStatusUpdate PUSService128__get_TC_params(const __termina_event_t * const __ev,
                                                        const PUSService128 * const self,
                                                        TCHandlerT * const tc_handler,
                                                        uint8_t * const subtype);

#endif
