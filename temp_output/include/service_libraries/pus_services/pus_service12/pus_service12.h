#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__PUS_SERVICE12_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__PUS_SERVICE12_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* do_monitoring)(void * const, uint16_t, uint16_t * const,
                           FaultInfo * const, _Bool * const);
    void (* is_PMON_enabled)(void * const, size_t, _Bool * const);
} PUSS12Iface;

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
    ParamMonitoringTransition param_mon_transitions_table[max_num_transitions];
    uint8_t monitoring_transition_counter;
    ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids];
    PS12ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    DoMonitoringReqStatusUpdate do_monitoring_req_status_update;
    DoMonitoringReqStatus do_monitoring_req_status;
} PUSService12;

_Bool PUSService12__PID_has_expected_masked_value(const PUSService12 * const self,
                                                  const ParamValueCheckDefinition * const expected_value_check_definition);

_Bool PUSService12__PID_is_above_upper_limit(const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def);

_Bool PUSService12__PID_is_below_lower_limit(const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def);

void PUSService12__build_tm_12_12(const PUSService12 * const self,
                                  TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  MyResult * const result);

void PUSService12__add_monitoring_transition(PUSService12 * const self);

void PUSService12__add_valid_mng_mon_def(PUSService12 * const self);

_Bool PUSService12__are_status_equal(const PUSService12 * const self,
                                     CheckState status1, CheckState status2);

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const PUSService12 * const self);

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const PUSService12 * const self);

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const PUSService12 * const self);

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const PUSService12 * const self);

_Bool PUSService12__is_expected_value_monitoring(const PUSService12 * const self);

_Bool PUSService12__is_limits_monitoring(const PUSService12 * const self);

_Bool PUSService12__is_valid_PMONID(const PUSService12 * const self);

_Bool PUSService12__manage_new_status(PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_expected_value(PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_interval_control(PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_param_within_limits(PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_unexpected_value(PUSService12 * const self);

void PUSService12__do_monitoring(void * const __this, uint16_t PMONID,
                                 uint16_t * const evID,
                                 FaultInfo * const fault_info,
                                 _Bool * const event_triggered);
void PUSService12__do_monitoring__mutex_lock(void * const __this,
                                             uint16_t PMONID,
                                             uint16_t * const evID,
                                             FaultInfo * const fault_info,
                                             _Bool * const event_triggered);
void PUSService12__do_monitoring__task_lock(void * const __this,
                                            uint16_t PMONID,
                                            uint16_t * const evID,
                                            FaultInfo * const fault_info,
                                            _Bool * const event_triggered);
void PUSService12__do_monitoring__event_lock(void * const __this,
                                             uint16_t PMONID,
                                             uint16_t * const evID,
                                             FaultInfo * const fault_info,
                                             _Bool * const event_triggered);

PSExecTCReqStatus PUSService12__exec12_1TC(PUSService12 * const self);

void PUSService12__set_unchecked(PUSService12 * const self);

PSExecTCReqStatus PUSService12__exec12_2TC(PUSService12 * const self);

PSExecTCReqStatus PUSService12__exec12_5TC(PUSService12 * const self);

PSExecTCReqStatus PUSService12__exec12_6TC(PUSService12 * const self);

MonitorDefinition PUSService12__get_PMON_limit_check_definition(const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                MyResult * const result);

MonitorDefinition PUSService12__get_PMON_value_check_definition(const PUSService12 * const self,
                                                                TCHandlerT * const tc_handler,
                                                                MyResult * const result);

PS12ExecTCReqStatusUpdate PUSService12__get_TC_params(const PUSService12 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result);

PSExecTCReqStatus PUSService12__manage_short_pack_length_error(const PUSService12 * const self);

void PUSService12__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);
void PUSService12__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);
void PUSService12__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService12__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);

MonitorCheckType PUSService12__get_PMON_type(const PUSService12 * const self,
                                             size_t PMONID);

void PUSService12__is_PMON_enabled(void * const __this, size_t PMONID,
                                   _Bool * const is_enabled);
void PUSService12__is_PMON_enabled__mutex_lock(void * const __this,
                                               size_t PMONID,
                                               _Bool * const is_enabled);
void PUSService12__is_PMON_enabled__task_lock(void * const __this,
                                              size_t PMONID,
                                              _Bool * const is_enabled);
void PUSService12__is_PMON_enabled__event_lock(void * const __this,
                                               size_t PMONID,
                                               _Bool * const is_enabled);

#endif
