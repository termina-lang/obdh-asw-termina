#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service9/pus_service9_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* get_current_obt)(void * const, MissionObt * const);
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS9Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void (* clock_get_uptime)(const __termina_event_t * const,
                                  TimeVal * const);
    } system_port;
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
    PS9ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    TimeVal ref_time_val_from_power_on;
    MissionObt ref_obt;
} PUSService9;

MissionObt PUSService9__inner_get_current_obt(const __termina_event_t * const __ev,
                                              const PUSService9 * const self);

void PUSService9__set_obt(const __termina_event_t * const __ev,
                          PUSService9 * const self);

PSExecTCReqStatus PUSService9__exec9_129TC(const __termina_event_t * const __ev,
                                           PUSService9 * const self);

PSExecTCReqStatus PUSService9__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                          const PUSService9 * const self);

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                              const PUSService9 * const self);

PSExecTCReqStatus PUSService9__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                const PUSService9 * const self);

void PUSService9__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);

void PUSService9__get_current_obt(const __termina_event_t * const __ev,
                                  void * const __this,
                                  MissionObt * const current_obt);

#endif
