#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE4__PUS_SERVICE4_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service4/pus_service4_help.h"

#include "option.h"
#include "result.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* update_all_stats)(void * const);
    void (* startup)(void * const);
} PUSS4Iface;

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
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    StatsConfig stats_config_table;
    StatsDef param_stats[4U];
    PS4ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService4;

uint32_t PUSService4__SDP_get_mean(const PUSService4 * const self,
                                   size_t pid_index);

_Bool PUSService4__SDP_param_higher_than_limit(const PUSService4 * const self,
                                               size_t pid_index);

_Bool PUSService4__SDP_param_lower_than_limit(const PUSService4 * const self,
                                              size_t pid_index);

MyResult PUSService4__get_PID_defined_stats_index(PUSService4 * const self);

MyResult PUSService4__get_free_index(const PUSService4 * const self,
                                     size_t * const index);

MyResult PUSService4__add_PID_stats(PUSService4 * const self);

void PUSService4__build_tm_4_2(const PUSService4 * const self,
                               TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, size_t index,
                               MyResult * const result);

MyResult PUSService4__delete_PID_stats(PUSService4 * const self);

void PUSService4__delete_all_stats(PUSService4 * const self);

PSExecTCReqStatus PUSService4__exec4_1TC(PUSService4 * const self);

PSExecTCReqStatus PUSService4__exec4_6TC(PUSService4 * const self);

PSExecTCReqStatus PUSService4__exec4_7TC(PUSService4 * const self);

PS4ExecTCReqStatusUpdate PUSService4__get_TC_params(const PUSService4 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result);

PSExecTCReqStatus PUSService4__manage_error_in_acceptance(const PUSService4 * const self);

PSExecTCReqStatus PUSService4__manage_short_pack_length_error(const PUSService4 * const self);

PSExecTCReqStatus PUSService4__manage_tm_limit_app_data_reached(const PUSService4 * const self);

void PUSService4__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);
void PUSService4__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService4__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status);
void PUSService4__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);

uint32_t PUSService4__get_data_pool_item(const PUSService4 * const self,
                                         uint16_t PID);

_Bool PUSService4__is_stats_index_defined(const PUSService4 * const self,
                                          size_t index);

void PUSService4__startup(void * const __this);
void PUSService4__startup__mutex_lock(void * const __this);
void PUSService4__startup__task_lock(void * const __this);
void PUSService4__startup__event_lock(void * const __this);

void PUSService4__update_all_stats(void * const __this);
void PUSService4__update_all_stats__mutex_lock(void * const __this);
void PUSService4__update_all_stats__task_lock(void * const __this);
void PUSService4__update_all_stats__event_lock(void * const __this);

#endif
