#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

#include "option.h"
#include "result.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* is_Ev_ID_enabled_ext)(void * const, uint16_t, _Bool * const);
    void (* build_and_tx_tm_5_x)(void * const, __status_int32_t * const,
                                 uint16_t, FaultInfo);
    void (* build_and_tx_tm_5_2)(void * const, __status_int32_t * const);
} PUSS5Iface;

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
    PS5ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    uint32_t Ev_ID_enable_config[4U];
} PUSService5;

void PUSService5__build_and_tx_tm_5_2(void * const __this,
                                      __status_int32_t * const status);
void PUSService5__build_and_tx_tm_5_2__mutex_lock(void * const __this,
                                                  __status_int32_t * const status);
void PUSService5__build_and_tx_tm_5_2__task_lock(void * const __this,
                                                 __status_int32_t * const status);
void PUSService5__build_and_tx_tm_5_2__event_lock(void * const __this,
                                                  __status_int32_t * const status);

void PUSService5__build_tm_5_x_param_check_value_fail(const PUSService5 * const self,
                                                      TMHandlerT * const p_tm_handler,
                                                      uint16_t tm_seq_counter,
                                                      ParamFaultValueInfo fault_info,
                                                      uint16_t ev_ID,
                                                      MyResult * const result);

void PUSService5__build_tm_5_x_param_out_of_limit(const PUSService5 * const self,
                                                  TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  ParamOutOfLimitInfo fault_info,
                                                  uint16_t ev_ID,
                                                  MyResult * const result);

void PUSService5__build_and_tx_tm_5_x(void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info);
void PUSService5__build_and_tx_tm_5_x__mutex_lock(void * const __this,
                                                  __status_int32_t * const status,
                                                  uint16_t evID,
                                                  FaultInfo fault_info);
void PUSService5__build_and_tx_tm_5_x__task_lock(void * const __this,
                                                 __status_int32_t * const status,
                                                 uint16_t evID,
                                                 FaultInfo fault_info);
void PUSService5__build_and_tx_tm_5_x__event_lock(void * const __this,
                                                  __status_int32_t * const status,
                                                  uint16_t evID,
                                                  FaultInfo fault_info);

PSExecTCReqStatus PUSService5__exec5_5TC(PUSService5 * const self);

PSExecTCReqStatus PUSService5__exec5_6TC(PUSService5 * const self);

PS5ExecTCReqStatusUpdate PUSService5__get_TC_params(const PUSService5 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result);

PSExecTCReqStatus PUSService5__manage_error_in_acceptance(const PUSService5 * const self);

PSExecTCReqStatus PUSService5__manage_short_pack_length_error(const PUSService5 * const self);

PSExecTCReqStatus PUSService5__manage_tm_limit_app_data_reached(const PUSService5 * const self);

void PUSService5__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);
void PUSService5__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService5__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status);
void PUSService5__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);

_Bool PUSService5__is_Ev_ID_enabled(const PUSService5 * const self,
                                    uint16_t Ev_ID);

void PUSService5__is_Ev_ID_enabled_ext(void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled);
void PUSService5__is_Ev_ID_enabled_ext__mutex_lock(void * const __this,
                                                   uint16_t Ev_ID,
                                                   _Bool * const p_enabled);
void PUSService5__is_Ev_ID_enabled_ext__task_lock(void * const __this,
                                                  uint16_t Ev_ID,
                                                  _Bool * const p_enabled);
void PUSService5__is_Ev_ID_enabled_ext__event_lock(void * const __this,
                                                   uint16_t Ev_ID,
                                                   _Bool * const p_enabled);

#endif
