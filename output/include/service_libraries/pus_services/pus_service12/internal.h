#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__INTERNAL_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__INTERNAL_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "service_libraries/pus_services/pus_service5.h"

#include "option.h"

typedef enum {
    MonitorCheckType__ExpectedValue,
    MonitorCheckType__Limits,
    MonitorCheckType__Delta,
    MonitorCheckType__Free
} __enum_MonitorCheckType_t;

typedef struct {
    __enum_MonitorCheckType_t __variant;
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
} __enum_MonitorDefinition_t;

typedef struct {
    ParamValueCheckDefinition __0;
} __enum_MonitorDefinition__ParamValueCheck_params_t;

typedef struct {
    ParamLimitCheckDefinition __0;
} __enum_MonitorDefinition__ParamLimitCheck_params_t;

typedef struct {
    ParamDeltaCheckDefinition __0;
} __enum_MonitorDefinition__ParamDeltaCheck_params_t;

typedef struct {
    __enum_MonitorDefinition_t __variant;
    union {
        __enum_MonitorDefinition__ParamValueCheck_params_t ParamValueCheck;
        __enum_MonitorDefinition__ParamLimitCheck_params_t ParamLimitCheck;
        __enum_MonitorDefinition__ParamDeltaCheck_params_t ParamDeltaCheck;
    };
} MonitorDefinition;

typedef enum {
    CheckValueResult__MonitorValueUnexpected,
    CheckValueResult__MonitorValueExpected
} __enum_CheckValueResult_t;

typedef struct {
    __enum_CheckValueResult_t __variant;
} CheckValueResult;

typedef struct {
    CheckValueResult __0;
} __option_CheckValueResult__Some_params_t;

typedef struct {
    __option_CheckValueResult__Some_params_t Some;
    __enum_option_t __variant;
} __option_CheckValueResult_t;

typedef enum {
    CheckLimitsResult__MonitorAboveHighLimit,
    CheckLimitsResult__MonitorBelowLowLimit,
    CheckLimitsResult__MonitorWithinLimits
} __enum_CheckLimitsResult_t;

typedef struct {
    __enum_CheckLimitsResult_t __variant;
} CheckLimitsResult;

typedef struct {
    CheckLimitsResult __0;
} __option_CheckLimitsResult__Some_params_t;

typedef struct {
    __option_CheckLimitsResult__Some_params_t Some;
    __enum_option_t __variant;
} __option_CheckLimitsResult_t;

typedef enum {
    CheckDeltaResult__MonitorDeltaLow,
    CheckDeltaResult__MonitorDeltaHigh,
    CheckDeltaResult__MonitorDeltaWithin
} __enum_CheckDeltaResult_t;

typedef struct {
    __enum_CheckDeltaResult_t __variant;
} CheckDeltaResult;

typedef struct {
    CheckDeltaResult __0;
} __option_CheckDeltaResult__Some_params_t;

typedef struct {
    __option_CheckDeltaResult__Some_params_t Some;
    __enum_option_t __variant;
} __option_CheckDeltaResult_t;

typedef enum {
    CheckState__ParamValueStatus,
    CheckState__ParamLimitStatus,
    CheckState__ParamDeltaStatus,
    CheckState__Unselected
} __enum_CheckState_t;

typedef struct {
    __option_CheckValueResult_t __0;
} __enum_CheckState__ParamValueStatus_params_t;

typedef struct {
    __option_CheckLimitsResult_t __0;
} __enum_CheckState__ParamLimitStatus_params_t;

typedef struct {
    __option_CheckDeltaResult_t __0;
} __enum_CheckState__ParamDeltaStatus_params_t;

typedef struct {
    __enum_CheckState_t __variant;
    union {
        __enum_CheckState__ParamValueStatus_params_t ParamValueStatus;
        __enum_CheckState__ParamLimitStatus_params_t ParamLimitStatus;
        __enum_CheckState__ParamDeltaStatus_params_t ParamDeltaStatus;
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
    __status_int32_t status;
} DoMonitoringReqStatusUpdate;

typedef enum {
    DoMonitoringReqStatus__Init,
    DoMonitoringReqStatus__CheckPMONID,
    DoMonitoringReqStatus__GetMonitoringType,
    DoMonitoringReqStatus__DoLimitsMonitoring,
    DoMonitoringReqStatus__DoExpectedValueMonitoring,
    DoMonitoringReqStatus__GetRequestStatusUpdate,
    DoMonitoringReqStatus__Exit
} __enum_DoMonitoringReqStatus_t;

typedef struct {
    __enum_DoMonitoringReqStatus_t __variant;
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

__status_int32_t build_tm_12_12(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt, uint8_t counter, const ParamMonitoringTransition param_mon_transitions_table[1U]);

#endif
