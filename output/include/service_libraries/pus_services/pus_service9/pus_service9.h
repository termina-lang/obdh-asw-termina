#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE9__PUS_SERVICE9_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service9/pus_service9_help.h"

#include "option.h"
#include "result.h"

typedef struct {
    void * __that;
    void (* get_current_obt)(void * const, MissionObt * const);
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS9Iface;

typedef struct {
    __termina_id_t __mutex_id;
    struct {
        void (* clock_get_uptime)(TimeVal * const);
    } system_port;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
    PS9ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    TimeVal ref_time_val_from_power_on;
    MissionObt ref_obt;
} PUSService9;

MissionObt PUSService9__inner_get_current_obt(const PUSService9 * const self);

void PUSService9__set_obt(PUSService9 * const self);

PSExecTCReqStatus PUSService9__exec9_129TC(PUSService9 * const self);

PS9ExecTCReqStatusUpdate PUSService9__get_TC_params(const PUSService9 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result);

PSExecTCReqStatus PUSService9__manage_error_in_acceptance(const PUSService9 * const self);

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const PUSService9 * const self);

PSExecTCReqStatus PUSService9__manage_tm_limit_app_data_reached(const PUSService9 * const self);

void PUSService9__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);
void PUSService9__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService9__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status);
void PUSService9__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);

void PUSService9__get_current_obt(void * const __this,
                                  MissionObt * const current_obt);
void PUSService9__get_current_obt__mutex_lock(void * const __this,
                                              MissionObt * const current_obt);
void PUSService9__get_current_obt__task_lock(void * const __this,
                                             MissionObt * const current_obt);
void PUSService9__get_current_obt__event_lock(void * const __this,
                                              MissionObt * const current_obt);

#endif
