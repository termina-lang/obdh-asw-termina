#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_HELP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/crc.h"
#include "service_libraries/serialize.h"

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
    TCExecutionCtrl__ExecCtrlReboot,
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

#define base_length 7

_Bool is_crc_valid(const TCDescriptorT * const tc_descriptor);

_Bool is_apid_valid(const TCDescriptorT * const tc_descriptor);

_Bool is_sourceID_valid(const TCDescriptorT * const tc_descriptor);

void build_tm(TMDescriptorT * const p_tm_descriptor, uint16_t tm_seq_counter,
              const TCDescriptorT * const tc_descriptor, uint16_t tm_plength,
              uint8_t tm_type, uint8_t tm_subtype);

#endif
