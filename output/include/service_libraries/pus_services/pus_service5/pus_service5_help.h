#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_HELP_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"

#include "option.h"

extern const uint16_t informative_Ev_IDs;

extern const uint16_t low_severity_anomaly_Ev_IDs;

extern const uint16_t medium_severity_anomaly_Ev_IDs;

extern const uint16_t high_severity_anomaly_Ev_IDs;

extern const uint16_t offset_mask;

extern const uint16_t EvID_build_tm_error;

typedef enum {
    Ev_IDType__Informative,
    Ev_IDType__LowSeverityAnomaly,
    Ev_IDType__MediumSeverityAnomaly,
    Ev_IDType__HighSeverityAnomaly,
    Ev_IDType__Ev_IDNotValid
} __enum_Ev_IDType_t;

typedef struct {
    __enum_Ev_IDType_t __variant;
} Ev_IDType;

typedef struct {
    uint16_t PID;
    uint32_t PID_value;
    uint32_t PID_limit;
} ParamOutOfLimitInfo;

typedef struct {
    uint16_t PID;
    uint32_t PID_value;
    uint32_t PID_mask;
    uint32_t PID_expected_value;
} ParamFaultValueInfo;

typedef enum {
    FaultInfo__ParamOutOfLimit,
    FaultInfo__ParamFaultValue,
    FaultInfo__Empty
} __enum_FaultInfo_t;

typedef struct {
    ParamOutOfLimitInfo __0;
} __enum_FaultInfo__ParamOutOfLimit_params_t;

typedef struct {
    ParamFaultValueInfo __0;
} __enum_FaultInfo__ParamFaultValue_params_t;

typedef struct {
    __enum_FaultInfo_t __variant;
    union {
        __enum_FaultInfo__ParamOutOfLimit_params_t ParamOutOfLimit;
        __enum_FaultInfo__ParamFaultValue_params_t ParamFaultValue;
    };
} FaultInfo;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_error_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint16_t EvID;
} PS5ExecTCReqStatusUpdate;

Ev_IDType get_Ev_ID_type(uint16_t Ev_ID);

_Bool is_Ev_ID_valid(uint16_t evID);

size_t get_Ev_ID_enable_config_index(uint16_t Ev_ID);

uint8_t get_Ev_ID_enable_config_offset(uint16_t Ev_ID);

void build_tm_5_x_param_out_of_limit(TMHandlerT * const p_tm_handler,
                                     uint16_t tm_seq_counter,
                                     ParamOutOfLimitInfo fault_info,
                                     uint16_t ev_ID, MissionObt current_obt,
                                     __status_int32_t * const status);

void build_tm_5_x_param_check_value_fail(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         ParamFaultValueInfo fault_info,
                                         uint16_t ev_ID, MissionObt current_obt,
                                         __status_int32_t * const status);

#endif
