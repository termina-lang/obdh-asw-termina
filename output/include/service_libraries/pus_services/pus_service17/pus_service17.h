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
    PS17ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService17;

__status_int32_t PUSService17__exec17_1TC(const __termina_event_t * const __ev,
                                          PUSService17 * const self);

void PUSService17__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);

#endif
