#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service4/pus_service4_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* update_all_stats)(void * const);
    void (* startup)(void * const);
} PUSS4Iface;

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
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    StatsConfig stats_config_table;
    StatsDef param_stats[4U];
    PS4ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService4;

uint32_t PUSService4__SDP_get_mean(const __termina_event_t * const __ev,
                                   const PUSService4 * const self,
                                   size_t pid_index);

_Bool PUSService4__SDP_param_higher_than_limit(const __termina_event_t * const __ev,
                                               const PUSService4 * const self,
                                               size_t pid_index);

_Bool PUSService4__SDP_param_lower_than_limit(const __termina_event_t * const __ev,
                                              const PUSService4 * const self,
                                              size_t pid_index);

__status_int32_t PUSService4__get_PID_defined_stats_index(const __termina_event_t * const __ev,
                                                          PUSService4 * const self);

IndexStatus PUSService4__get_free_index(const __termina_event_t * const __ev,
                                        const PUSService4 * const self);

__status_int32_t PUSService4__add_PID_stats(const __termina_event_t * const __ev,
                                            PUSService4 * const self);

__status_int32_t PUSService4__delete_PID_stats(const __termina_event_t * const __ev,
                                               PUSService4 * const self);

void PUSService4__delete_all_stats(const __termina_event_t * const __ev,
                                   PUSService4 * const self);

__status_int32_t PUSService4__exec4_1TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self);

__status_int32_t PUSService4__exec4_6TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self);

__status_int32_t PUSService4__exec4_7TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self);

void PUSService4__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);

uint32_t PUSService4__get_data_pool_item(const __termina_event_t * const __ev,
                                         const PUSService4 * const self,
                                         uint16_t PID);

_Bool PUSService4__is_stats_index_defined(const __termina_event_t * const __ev,
                                          const PUSService4 * const self,
                                          size_t index);

void PUSService4__startup(const __termina_event_t * const __ev,
                          void * const __this);

void PUSService4__update_all_stats(const __termina_event_t * const __ev,
                                   void * const __this);

#endif
