#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICE1_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICE1_H__

#include <termina.h>
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/tm_ccsds_pus_format.h"
#include "libraries/crc.h"
#include "libraries/serialize.h"

typedef enum {
    TCAcceptationStatus__Accepted,
    TCAcceptationStatus__Rejected
} __enum_TCAcceptationStatus_t;

typedef struct {
    __enum_TCAcceptationStatus_t __variant;
} TCAcceptationStatus;

typedef enum {
    TCErrorType__CRCError,
    TCErrorType__APIDError,
    TCErrorType__SourceIDError,
    TCErrorType__TypeError,
    TCErrorType__SubTypeError
} __enum_TCErrorType_t;

typedef struct {
    __enum_TCErrorType_t __variant;
} TCErrorType;

typedef enum {
    TCExecutionCtrl__ExecCtrlPrioTC,
    TCExecutionCtrl__ExecCtrlReboot,
    TCExecutionCtrl__ExecCtrlHK_FDIRTC,
    TCExecutionCtrl__ExecCtrlBKGTC
} __enum_TCExecutionCtrl_t;

typedef struct {
    __enum_TCExecutionCtrl_t __variant;
} TCExecutionCtrl;

typedef struct {
    TCAcceptationStatus acceptation_status;
    TCExecutionCtrl execution_status;
    TCErrorType error_code;
} TCStatus;

_Bool is_crc_valid(const TCDescriptorT * tc_descriptor);

_Bool is_apid_valid(const TCDescriptorT * tc_descriptor);

_Bool is_sourceID_valid(const TCDescriptorT * tc_descriptor);

void try_tc_acceptation(TCStatus * status, const TCDescriptorT * tc_descriptor);

void build_tm_1_1(TMDescriptorT * p_tm_descriptor, uint16_t tm_seq_counter,
                  const TCDescriptorT * tc_descriptor);

void build_tm_1_2(const TCStatus * status, TMDescriptorT * p_tm_descriptor,
                  uint16_t tm_seq_counter, const TCDescriptorT * tc_descriptor);

void build_tm_1_7(TMDescriptorT * p_tm_descriptor, uint16_t tm_seq_counter,
                  const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_3_X_SIDnotvalid(TMDescriptorT * p_tm_descriptor,
                                     uint16_t tm_seq_counter, uint16_t SID,
                                     const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_20_X_PIDnotvalid(TMDescriptorT * p_tm_descriptor,
                                      uint16_t tm_seq_counter, uint16_t PID,
                                      const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_5_X_RIDunknown(TMDescriptorT * p_tm_descriptor,
                                    uint16_t tm_seq_counter, uint16_t RID,
                                    const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_12_X_PMONIDundefined(TMDescriptorT * p_tm_descriptor,
                                          uint16_t tm_seq_counter,
                                          uint16_t PMONID,
                                          const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_12_X_PMONIDdefined(TMDescriptorT * p_tm_descriptor,
                                        uint16_t tm_seq_counter,
                                        uint16_t PMONID,
                                        const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_12_X_PMONIDnotvalid(TMDescriptorT * p_tm_descriptor,
                                         uint16_t tm_seq_counter,
                                         uint16_t PMONID,
                                         const TCDescriptorT * tc_descriptor);

#endif
