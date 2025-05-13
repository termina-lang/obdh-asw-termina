#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__PUS_SERVICE12_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__PUS_SERVICE12_HELP_H__

#include <termina.h>

#include "resources/system_data_pool.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

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
    CheckValueStatus__MonitorUnchecked,
    CheckValueStatus__MonitorValueUnexpected,
    CheckValueStatus__MonitorValueExpected
} __enum_CheckValueStatus_t;

typedef struct {
    __enum_CheckValueStatus_t __variant;
} CheckValueStatus;

typedef enum {
    CheckLimitsStatus__MonitorUnchecked,
    CheckLimitsStatus__MonitorAboveHighLimit,
    CheckLimitsStatus__MonitorBelowLowLimit,
    CheckLimitsStatus__MonitorWithinLimits
} __enum_CheckLimitsStatus_t;

typedef struct {
    __enum_CheckLimitsStatus_t __variant;
} CheckLimitsStatus;

typedef enum {
    CheckDeltaStatus__MonitorUnchecked,
    CheckDeltaStatus__MonitorDeltaLow,
    CheckDeltaStatus__MonitorDeltaHigh,
    CheckDeltaStatus__MonitorDeltaWithin
} __enum_CheckDeltaStatus_t;

typedef struct {
    __enum_CheckDeltaStatus_t __variant;
} CheckDeltaStatus;

typedef enum {
    CheckState__ParamValueStatus,
    CheckState__ParamLimitStatus,
    CheckState__ParamDeltaStatus,
    CheckState__Unselected
} __enum_CheckState_t;

typedef struct {
    CheckValueStatus __0;
} __enum_CheckState__ParamValueStatus_params_t;

typedef struct {
    CheckLimitsStatus __0;
} __enum_CheckState__ParamLimitStatus_params_t;

typedef struct {
    CheckDeltaStatus __0;
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
    MissionObt transition_obt;
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
    MissionObt trans_obt;
} ParamMonitoringTransition;

typedef struct {
    uint16_t PMONID;
    uint16_t EvID;
    MonitorDefinition current_monitor_definition;
    FaultInfo fault_info;
    CheckState new_status;
    _Bool event_triggered;
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
    uint16_t packet_error_ctrl;
    size_t tc_num_bytes;
    PS12TC_1_2_6_Data tc_data_1_2_6;
    PS12TC_5_Data tc_data_5;
} PS12ExecTCReqStatusUpdate;

uint8_t get_check_status_index(CheckState status);

uint8_t get_type_index(MonitorCheckType type);

_Bool are_status_equal(CheckState status1, CheckState status2);

MonitorCheckType get_check_type(uint8_t aux);

_Bool is_valid_check_limit_def(const MonitorDefinition * const param_limit_check_definition);

#endif
