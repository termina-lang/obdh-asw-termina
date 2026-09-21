#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__INTERNAL_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__INTERNAL_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "service_libraries/pus_services/pus_service5.h"

#include "option.h"

typedef enum {
    MonitorCheckType__ExpectedValue,
    MonitorCheckType__Limits,
    MonitorCheckType__Delta,
    MonitorCheckType__Free
} termina__enum__MonitorCheckType_t;

typedef struct {
    termina__enum__MonitorCheckType_t _variant;
} MonitorCheckType;

typedef struct {
    uint32_t mask_value;
    uint32_t expected_value;
    uint16_t EvID;
} ParamValueCheckDefinition;

typedef struct {
    uint32_t low_limit;
    uint16_t low_limit_evID;
    uint32_t high_limit;
    uint16_t high_limit_evID;
} ParamLimitCheckDefinition;

typedef struct {
    uint16_t low_delta_threshold;
    uint16_t low_delta_EvID;
    uint16_t high_delta_threshold;
    uint16_t high_delta_EvID;
    uint8_t consecutive_delta_values;
} ParamDeltaCheckDefinition;

typedef enum {
    MonitorDefinition__ParamValueCheck,
    MonitorDefinition__ParamLimitCheck,
    MonitorDefinition__ParamDeltaCheck,
    MonitorDefinition__Unselected
} termina__enum__MonitorDefinition_t;

typedef struct {
    ParamValueCheckDefinition _0;
} termina__enum__MonitorDefinition__ParamValueCheck_params_t;

typedef struct {
    ParamLimitCheckDefinition _0;
} termina__enum__MonitorDefinition__ParamLimitCheck_params_t;

typedef struct {
    ParamDeltaCheckDefinition _0;
} termina__enum__MonitorDefinition__ParamDeltaCheck_params_t;

typedef struct {
    termina__enum__MonitorDefinition_t _variant;
    union {
        termina__enum__MonitorDefinition__ParamValueCheck_params_t ParamValueCheck;
        termina__enum__MonitorDefinition__ParamLimitCheck_params_t ParamLimitCheck;
        termina__enum__MonitorDefinition__ParamDeltaCheck_params_t ParamDeltaCheck;
    };
} MonitorDefinition;

typedef enum {
    CheckValueResult__MonitorValueUnexpected,
    CheckValueResult__MonitorValueExpected
} termina__enum__CheckValueResult_t;

typedef struct {
    termina__enum__CheckValueResult_t _variant;
} CheckValueResult;

typedef struct {
    CheckValueResult _0;
} termina__enum__Option__CheckValueResult__Some_params_t;

typedef struct {
    termina__enum__Option__CheckValueResult__Some_params_t Some;
    termina__enum__Option_t _variant;
} Option__CheckValueResult;

typedef enum {
    CheckLimitsResult__MonitorAboveHighLimit,
    CheckLimitsResult__MonitorBelowLowLimit,
    CheckLimitsResult__MonitorWithinLimits
} termina__enum__CheckLimitsResult_t;

typedef struct {
    termina__enum__CheckLimitsResult_t _variant;
} CheckLimitsResult;

typedef struct {
    CheckLimitsResult _0;
} termina__enum__Option__CheckLimitsResult__Some_params_t;

typedef struct {
    termina__enum__Option__CheckLimitsResult__Some_params_t Some;
    termina__enum__Option_t _variant;
} Option__CheckLimitsResult;

typedef enum {
    CheckDeltaResult__MonitorDeltaLow,
    CheckDeltaResult__MonitorDeltaHigh,
    CheckDeltaResult__MonitorDeltaWithin
} termina__enum__CheckDeltaResult_t;

typedef struct {
    termina__enum__CheckDeltaResult_t _variant;
} CheckDeltaResult;

typedef struct {
    CheckDeltaResult _0;
} termina__enum__Option__CheckDeltaResult__Some_params_t;

typedef struct {
    termina__enum__Option__CheckDeltaResult__Some_params_t Some;
    termina__enum__Option_t _variant;
} Option__CheckDeltaResult;

typedef enum {
    CheckState__ParamValueStatus,
    CheckState__ParamLimitStatus,
    CheckState__ParamDeltaStatus,
    CheckState__Unselected
} termina__enum__CheckState_t;

typedef struct {
    Option__CheckValueResult _0;
} termina__enum__CheckState__ParamValueStatus_params_t;

typedef struct {
    Option__CheckLimitsResult _0;
} termina__enum__CheckState__ParamLimitStatus_params_t;

typedef struct {
    Option__CheckDeltaResult _0;
} termina__enum__CheckState__ParamDeltaStatus_params_t;

typedef struct {
    termina__enum__CheckState_t _variant;
    union {
        termina__enum__CheckState__ParamValueStatus_params_t ParamValueStatus;
        termina__enum__CheckState__ParamLimitStatus_params_t ParamLimitStatus;
        termina__enum__CheckState__ParamDeltaStatus_params_t ParamDeltaStatus;
    };
} CheckState;

typedef struct {
    uint16_t PID;
    MonitorCheckType type;
    _Bool enabled;
    MonitorDefinition definition;
    uint8_t repetition;
    uint8_t repetition_control;
    uint8_t interval;
    uint8_t interval_control;
    MissionOBT transition_obt;
    CheckState temp_state;
    CheckState current_state;
} ParamMonitoringConfiguration;

typedef struct {
    uint16_t PMONID;
    uint16_t PID;
    MonitorCheckType type;
    uint32_t mask_value;
    uint32_t limit_value;
    uint32_t new_value;
    CheckState prev_status;
    CheckState new_status;
    MissionOBT trans_obt;
} ParamMonitoringTransition;

typedef struct {
    uint16_t PMONID;
    uint16_t EvID;
    MonitorDefinition current_monitor_definition;
    FaultInfo fault_info;
    CheckState new_status;
    CheckState prev_status;
    _Bool event_triggered;
    Status__i32 status;
} DoMonitoringReqStatusUpdate;

typedef enum {
    DoMonitoringReqStatus__Init,
    DoMonitoringReqStatus__CheckPMONID,
    DoMonitoringReqStatus__GetMonitoringType,
    DoMonitoringReqStatus__DoLimitsMonitoring,
    DoMonitoringReqStatus__DoExpectedValueMonitoring,
    DoMonitoringReqStatus__GetRequestStatusUpdate,
    DoMonitoringReqStatus__Exit
} termina__enum__DoMonitoringReqStatus_t;

typedef struct {
    termina__enum__DoMonitoringReqStatus_t _variant;
} DoMonitoringReqStatus;

typedef struct {
    uint8_t N;
    uint16_t PMONID;
} PS12TC_1_2_6_Data;

typedef struct {
    uint8_t N;
    uint16_t PMONID;
    ParamMonitoringConfiguration mon_config;
} PS12TC_5_Data;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    PS12TC_1_2_6_Data tc_data_1_2_6;
    PS12TC_5_Data tc_data_5;
} PS12ExecTCReqStatusUpdate;

uint8_t get_check_status_index(CheckState status);

uint8_t get_type_index(MonitorCheckType type);

_Bool are_status_equal(CheckState status1, CheckState status2);

MonitorCheckType get_check_type(uint8_t aux);

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition);

Status__i32 build_tm_12_12(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt, uint8_t counter, const ParamMonitoringTransition param_mon_transitions_table[1U]);

#endif
