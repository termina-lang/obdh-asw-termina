#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_HELP_H__

#include <termina.h>

#include "service_libraries/crc.h"
#include "service_libraries/pus_tc_handler.h"
#include "service_libraries/pus_tm_handler.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

extern const uint8_t ACCEPT_ACK_ENABLED_MASK;

extern const uint8_t EXEC_START_ACK_ENABLED_MASK;

extern const uint8_t EXEC_PROGRESS_ACK_ENABLED_MASK;

extern const uint8_t EXEC_COMPLETION_ACK_ENABLED_MASK;

typedef enum {
    TCAcceptationStatus__Accepted,
    TCAcceptationStatus__Rejected,
    TCAcceptationStatus__Undefined
} __enum_TCAcceptationStatus_t;

typedef struct {
    __enum_TCAcceptationStatus_t __variant;
} TCAcceptationStatus;

typedef enum {
    TCErrorType__CRCError,
    TCErrorType__APIDError,
    TCErrorType__SourceIDError,
    TCErrorType__TypeError,
    TCErrorType__SubTypeError,
    TCErrorType__Undefined
} __enum_TCErrorType_t;

typedef struct {
    __enum_TCErrorType_t __variant;
} TCErrorType;

typedef enum {
    TCExecutionCtrl__ExecCtrlPrioTC,
    TCExecutionCtrl__ExecCtrlHK_FDIRTC,
    TCExecutionCtrl__ExecCtrlBKGTC,
    TCExecutionCtrl__Undefined
} __enum_TCExecutionCtrl_t;

typedef struct {
    __enum_TCExecutionCtrl_t __variant;
} TCExecutionCtrl;

typedef struct {
    TCAcceptationStatus acceptation_status;
    TCExecutionCtrl execution_status;
    TCErrorType error_code;
} TCStatus;

typedef enum {
    TCVerifyStage__Acceptation,
    TCVerifyStage__ExecStart,
    TCVerifyStage__Progress,
    TCVerifyStage__ExecCompletion
} __enum_TCVerifyStage_t;

typedef struct {
    __enum_TCVerifyStage_t __variant;
} TCVerifyStage;

_Bool is_crc_valid(const TCDescriptorT * const tc_descriptor);

_Bool is_apid_valid(const TCDescriptorT * const tc_descriptor);

_Bool is_sourceID_valid(const TCDescriptorT * const tc_descriptor);

_Bool is_tc_ack_accept_enabled(uint8_t flags_ack);

_Bool is_tc_ack_start_exec_enabled(uint8_t flags_ack);

_Bool is_tc_ack_progress_exec_enabled(uint8_t flags_ack);

_Bool is_tc_ack_completion_exec_enabled(uint8_t flags_ack);

uint8_t get_failure_subtype(TCVerifyStage verify_stage);

void build_tm_1_X_no_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, MissionObt current_obt,
                                  MyResult * const result);

void build_tm_1_X_u8_failure_data(TMHandlerT * const p_tm_handler,
                                  uint16_t tm_seq_counter,
                                  uint16_t tc_packet_id,
                                  uint16_t tc_packet_error_ctrl,
                                  TCVerifyStage verify_stage,
                                  uint8_t failure_code, uint8_t failure_data,
                                  MissionObt current_obt,
                                  MyResult * const result);

void build_tm_1_X_u16_failure_data(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   TCVerifyStage verify_stage,
                                   uint8_t failure_code, uint16_t failure_data,
                                   MissionObt current_obt,
                                   MyResult * const result);

void build_tm_1_X_u32_failure_data(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   TCVerifyStage verify_stage,
                                   uint8_t failure_code, uint32_t failure_data,
                                   MissionObt current_obt,
                                   MyResult * const result);

void build_tm_1_X_u8_u32_failure_data(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      TCVerifyStage verify_stage,
                                      uint8_t failure_code,
                                      uint8_t failure_data1,
                                      uint32_t failure_data2,
                                      MissionObt current_obt,
                                      MyResult * const result);

#endif
