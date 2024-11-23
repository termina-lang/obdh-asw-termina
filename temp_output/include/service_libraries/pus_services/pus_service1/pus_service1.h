#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

#define TM_1_8_TC_3_X_invalid_SID 1

#define TM_1_8_TC_20_X_invalid_PID 2

#define TM_1_8_TC_5_X_unknown_RID 3

#define TM_1_8_TC_12_X_PMONID_undefined 4

#define TM_1_8_TC_12_X_PMONID_defined 5

#define TM_1_8_TC_12_X_invalid_PMONID 6

#define TM_1_8_TC_19_X_ev_action_is_enabled 8

#define TM_1_8_TC_19_1_max_ev_actions_reached 9

#define TM_1_8_TC_19_1_ev_action_rejected 10

#define TM_1_8_TC_19_X_ev_action_not_defined 11

#define TM_1_8_TC_2_X_device_not_valid 12

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor);

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor);

void build_tm_1_1(TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * const tc_descriptor);

void build_tm_1_2(const TCStatus * const status,
                  TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * const tc_descriptor);

void build_tm_1_7(TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter,
                  const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_3_X_SIDnotvalid(TMDescriptorT * const p_tm_descriptor,
                                     uint16_t tm_seq_counter, uint16_t SID,
                                     const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_20_X_PIDnotvalid(TMDescriptorT * const p_tm_descriptor,
                                      uint16_t tm_seq_counter, uint16_t PID,
                                      const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_5_X_RIDunknown(TMDescriptorT * const p_tm_descriptor,
                                    uint16_t tm_seq_counter, uint16_t RID,
                                    const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_12_X_PMONIDundefined(TMDescriptorT * const p_tm_descriptor,
                                          uint16_t tm_seq_counter,
                                          uint16_t PMONID,
                                          const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_12_X_PMONIDdefined(TMDescriptorT * const p_tm_descriptor,
                                        uint16_t tm_seq_counter,
                                        uint16_t PMONID,
                                        const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_12_X_PMONIDnotvalid(TMDescriptorT * const p_tm_descriptor,
                                         uint16_t tm_seq_counter,
                                         uint16_t PMONID,
                                         const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_19_X_event_action_enabled(TMDescriptorT * const p_tm_descriptor,
                                               uint16_t tm_seq_counter,
                                               uint16_t event_ID,
                                               const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_19_1_max_event_actions(TMDescriptorT * const p_tm_descriptor,
                                            uint16_t tm_seq_counter,
                                            uint16_t event_ID,
                                            const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_19_1_event_action_rejected(TMDescriptorT * const p_tm_descriptor,
                                                uint16_t tm_seq_counter,
                                                uint16_t event_ID,
                                                const TCDescriptorT * const tc_descriptor);

void build_tm_1_8_tc_19_X_event_action_not_defined(TMDescriptorT * const p_tm_descriptor,
                                                   uint16_t tm_seq_counter,
                                                   uint16_t event_ID,
                                                   const TCDescriptorT * const tc_descriptor);

#endif
