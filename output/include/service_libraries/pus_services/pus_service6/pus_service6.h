#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6__PUS_SERVICE6_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6__PUS_SERVICE6_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service6/pus_service6_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS6Iface;

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
    volatile uint8_t (* memory)[16777216U];
    _Bool mem_id_write_permisssions[8U];
    PS6ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService6;

uint16_t PUSService6__check_data(const __termina_event_t * const __ev,
                                 PUSService6 * const self);

_Bool PUSService6__is_address_valid(const __termina_event_t * const __ev,
                                    const PUSService6 * const self);

_Bool PUSService6__is_mem_id_write_enabled(const __termina_event_t * const __ev,
                                           const PUSService6 * const self);

__status_int32_t PUSService6__write_data(const __termina_event_t * const __ev,
                                         PUSService6 * const self);

__status_int32_t PUSService6__exec6_2TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self);

__status_int32_t PUSService6__read_data(const __termina_event_t * const __ev,
                                        PUSService6 * const self);

__status_int32_t PUSService6__exec6_5TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self);

__status_int32_t PUSService6__exec6_9TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self);

void PUSService6__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);

#endif
