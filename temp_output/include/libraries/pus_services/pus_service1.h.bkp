#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICE1_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICE1_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/crc.h"
#include "service_libraries/serialize.h"

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

#define TM_1_8_TC_3_X_invalid_SID UINT16_C(1)

#define TM_1_8_TC_20_X_invalid_PID UINT16_C(2)

#define TM_1_8_TC_5_X_unknown_RID UINT16_C(3)

#define TM_1_8_TC_12_X_PMONID_undefined UINT16_C(4)

#define TM_1_8_TC_12_X_PMONID_defined UINT16_C(5)

#define TM_1_8_TC_12_X_invalid_PMONID UINT16_C(6)

#define TM_1_8_TC_19_X_ev_action_is_enabled UINT16_C(8)

#define TM_1_8_TC_19_1_max_ev_actions_reached UINT16_C(9)

#define TM_1_8_TC_19_1_ev_action_rejected UINT16_C(10)

#define TM_1_8_TC_19_X_ev_action_not_defined UINT16_C(11)

#define TM_1_8_TC_2_X_device_not_valid UINT16_C(12)

_Bool is_crc_valid(const TCDescriptorT * tc_descriptor);

_Bool is_apid_valid(const TCDescriptorT * tc_descriptor);

_Bool is_sourceID_valid(const TCDescriptorT * tc_descriptor);

TCExecutionCtrl handle_tc(const TCDescriptorT * tc_descriptor);

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

void build_tm_1_8_tc_19_X_event_action_enabled(TMDescriptorT * p_tm_descriptor,
                                               uint16_t tm_seq_counter,
                                               uint16_t event_ID,
                                               const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_19_1_max_event_actions(TMDescriptorT * p_tm_descriptor,
                                            uint16_t tm_seq_counter,
                                            uint16_t event_ID,
                                            const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_19_1_event_action_rejected(TMDescriptorT * p_tm_descriptor,
                                                uint16_t tm_seq_counter,
                                                uint16_t event_ID,
                                                const TCDescriptorT * tc_descriptor);

void build_tm_1_8_tc_19_X_event_action_not_defined(TMDescriptorT * p_tm_descriptor,
                                                   uint16_t tm_seq_counter,
                                                   uint16_t event_ID,
                                                   const TCDescriptorT * tc_descriptor);

#endif
