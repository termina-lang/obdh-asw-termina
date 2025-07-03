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
    ParamMonitoringTransition param_mon_transitions_table[1U];
    uint8_t monitoring_transition_counter;
    ParamMonitoringConfiguration param_mon_config_table[16U];
    PS12ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    DoMonitoringReqStatusUpdate do_monitoring_req_status_update;
    DoMonitoringReqStatus do_monitoring_req_status;
} PUSService12;

_Bool PUSService12__PID_has_expected_masked_value(const __termina_event_t * const __ev,
                                                  const PUSService12 * const self,
                                                  const ParamValueCheckDefinition * const expected_value_check_definition);

_Bool PUSService12__PID_is_above_upper_limit(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def);

_Bool PUSService12__PID_is_below_lower_limit(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             const ParamLimitCheckDefinition * const limit_check_def);

void PUSService12__add_monitoring_transition(const __termina_event_t * const __ev,
                                             PUSService12 * const self);

void PUSService12__add_valid_mng_mon_def(const __termina_event_t * const __ev,
                                         PUSService12 * const self);

_Bool PUSService12__are_status_equal(const __termina_event_t * const __ev,
                                     const PUSService12 * const self,
                                     CheckState status1, CheckState status2);

ParamValueCheckDefinition PUSService12__get_expected_value_monitoring_definition(const __termina_event_t * const __ev,
                                                                                 const PUSService12 * const self);

CheckValueStatus PUSService12__check_PID_status_exp_val_monitoring(const __termina_event_t * const __ev,
                                                                   const PUSService12 * const self);

ParamLimitCheckDefinition PUSService12__get_limits_monitoring_definition(const __termina_event_t * const __ev,
                                                                         const PUSService12 * const self);

CheckLimitsStatus PUSService12__check_PID_status_limits_monitoring(const __termina_event_t * const __ev,
                                                                   const PUSService12 * const self);

_Bool PUSService12__is_expected_value_monitoring(const __termina_event_t * const __ev,
                                                 const PUSService12 * const self);

_Bool PUSService12__is_limits_monitoring(const __termina_event_t * const __ev,
                                         const PUSService12 * const self);

_Bool PUSService12__is_valid_PMONID(const __termina_event_t * const __ev,
                                    const PUSService12 * const self);

_Bool PUSService12__manage_new_status(const __termina_event_t * const __ev,
                                      PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_expected_value(const __termina_event_t * const __ev,
                                                          PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_interval_control(const __termina_event_t * const __ev,
                                                            PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_param_above_upper_limit(const __termina_event_t * const __ev,
                                                                   PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_param_below_lower_limit(const __termina_event_t * const __ev,
                                                                   PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_param_within_limits(const __termina_event_t * const __ev,
                                                               PUSService12 * const self);

DoMonitoringReqStatus PUSService12__manage_unexpected_value(const __termina_event_t * const __ev,
                                                            PUSService12 * const self);

void PUSService12__do_monitoring(const __termina_event_t * const __ev,
                                 void * const __this, uint16_t PMONID,
                                 uint16_t * const evID,
                                 FaultInfo * const fault_info,
                                 _Bool * const event_triggered);

__status_int32_t PUSService12__exec12_1TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self);

void PUSService12__set_unchecked(const __termina_event_t * const __ev,
                                 PUSService12 * const self);

__status_int32_t PUSService12__exec12_2TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self);

__status_int32_t PUSService12__exec12_5TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self);

__status_int32_t PUSService12__exec12_6TC(const __termina_event_t * const __ev,
                                          PUSService12 * const self);

void PUSService12__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);

MonitorCheckType PUSService12__get_PMON_type(const __termina_event_t * const __ev,
                                             const PUSService12 * const self,
                                             size_t PMONID);

void PUSService12__is_PMON_enabled(const __termina_event_t * const __ev,
                                   void * const __this, size_t PMONID,
                                   _Bool * const is_enabled);

#endif
