#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service17/internal.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandler * const, __status_int32_t * const);
} PUSS17Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const,
                               uint16_t, uint16_t, uint8_t,
                               __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const,
                               uint16_t, uint16_t, uint8_t,
                               __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const,
                                                 void * const, uint16_t,
                                                 uint16_t,
                                                 __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const,
                                                     void * const, uint16_t,
                                                     uint16_t,
                                                     __status_int32_t * const);
    } pus_service_1;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionOBT * const);
    } obt_manager;
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
} PUSService17;

__status_int32_t PUSService17__exec17_1TC(const __termina_event_t * const __ev,
                                          PUSService17 * const self);

void PUSService17__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandler * const tc_handler,
                           __status_int32_t * const action_status);

#endif
