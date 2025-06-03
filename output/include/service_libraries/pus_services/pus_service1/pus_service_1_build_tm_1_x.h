#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE_1_BUILD_TM_1_X_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE_1_BUILD_TM_1_X_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

#include "option.h"
#include "result.h"

extern const uint8_t TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH;

extern const uint8_t TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR;

extern const uint8_t TM_1_4_TC_2_X_DEVICE_NOT_VALID;

extern const uint8_t TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID;

extern const uint8_t TM_1_4_TC_3_X_INVALID_SID;

extern const uint8_t TM_1_4_TC_4_7_PID_STATS_UNDEFINED;

extern const uint8_t TM_1_4_TC_5_X_INVALID_EV_ID;

extern const uint8_t TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS;

extern const uint8_t TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY;

extern const uint8_t TM_1_4_TC_6_X_OUT_OF_MEMORY_ID_LIMITS;

extern const uint8_t TM_1_4_TC_11_X_SCHED_TC_REJECTED;

extern const uint8_t TM_1_4_TC_11_X_INVALID_SCHED_TIME;

extern const uint8_t TM_1_4_TC_12_X_PMON_UNDEFINED;

extern const uint8_t TM_1_4_TC_12_X_PMON_DEFINED;

extern const uint8_t TM_1_4_TC_12_X_PMON_ENABLED;

extern const uint8_t TM_1_4_TC_12_X_INVALID_PMONID;

extern const uint8_t TM_1_4_TC_12_X_INVALID_PMON_DEFINITION;

extern const uint8_t TM_1_4_TC_15_X_INVALID_PACKET_STORE;

extern const uint8_t TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED;

extern const uint8_t TM_1_4_TC_19_1_EV_ACTION_REJECTED;

extern const uint8_t TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED;

extern const uint8_t TM_1_4_TC_20_X_INVALID_PID;

extern const uint8_t TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC;

extern const uint8_t TM_1_4_ERROR_IN_ACCEPTANCE;

extern const uint8_t TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA;

extern const uint8_t TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR;

extern const uint8_t TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG;

extern const uint8_t TM_1_8_TC_6_X_MEM_ACCESS_FAIL;

extern const uint8_t TM_1_8_TC_11_X_SCHED_TC_POOL_EMPTY;

extern const uint8_t TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED;

void build_tm_1_1(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint16_t tc_packet_id, uint16_t tc_packet_error_ctrl,
                  uint8_t flags_ack, MissionObt current_obt,
                  MyResult * const result, _Bool * const enabled);

void build_tm_1_2(const TCStatus * const status,
                  TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  const TCHandlerT * const tc_handler, MissionObt current_obt,
                  MyResult * const result);

void build_tm_1_3(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint8_t flags_ack, MissionObt current_obt,
                  MyResult * const result, _Bool * const enabled);

void build_tm_1_4_short_pack_length(TMHandlerT * const p_tm_handler,
                                    uint16_t tm_seq_counter,
                                    uint16_t tc_packet_id,
                                    uint16_t tc_packet_error_ctrl,
                                    size_t tc_bytes, MissionObt current_obt,
                                    MyResult * const result);

void build_tm_1_4_num_of_instr_not_valid(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         uint16_t tc_packet_id,
                                         uint16_t tc_packet_error_ctrl,
                                         uint8_t N, MissionObt current_obt,
                                         MyResult * const result);

void build_tm_1_4_device_address_not_valid(TMHandlerT * const p_tm_handler,
                                           uint16_t tm_seq_counter,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_error_ctrl,
                                           uint32_t device_address,
                                           MissionObt current_obt,
                                           MyResult * const result);

void build_tm_1_4_SID_not_valid(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                uint16_t tc_packet_error_ctrl, uint16_t SID,
                                MissionObt current_obt,
                                MyResult * const result);

void build_tm_1_4_mem_address_not_valid(TMHandlerT * const p_tm_handler,
                                        uint16_t tm_seq_counter,
                                        uint16_t tc_packet_id,
                                        uint16_t tc_packet_error_ctrl,
                                        uint8_t mem_id, uint32_t mem_address,
                                        MissionObt current_obt,
                                        MyResult * const result);

void build_tm_1_4_mem_id_read_only(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   uint8_t mem_id, MissionObt current_obt,
                                   MyResult * const result);

void build_tm_1_4_EvID_not_valid(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t EvID,
                                 MissionObt current_obt,
                                 MyResult * const result);

void build_tm_1_4_PID_not_valid(TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                uint16_t tc_packet_error_ctrl, uint16_t PID,
                                MissionObt current_obt,
                                MyResult * const result);

void build_tm_1_4_PMON_undefined(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                                 MissionObt current_obt,
                                 MyResult * const result);

void build_tm_1_4_PMON_defined(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, uint16_t tc_packet_id,
                               uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                               MissionObt current_obt, MyResult * const result);

void build_tm_1_4_PMON_enabled(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, uint16_t tc_packet_id,
                               uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                               MissionObt current_obt, MyResult * const result);

void build_tm_1_4_PMONID_invalid(TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter, uint16_t tc_packet_id,
                                 uint16_t tc_packet_error_ctrl, uint16_t PMONID,
                                 MissionObt current_obt,
                                 MyResult * const result);

void build_tm_1_4_PMON_definition_invalid(TMHandlerT * const p_tm_handler,
                                          uint16_t tm_seq_counter,
                                          uint16_t tc_packet_id,
                                          uint16_t tc_packet_error_ctrl,
                                          uint16_t PMONID,
                                          MissionObt current_obt,
                                          MyResult * const result);

void build_tm_1_4_ev_action_enabled(TMHandlerT * const p_tm_handler,
                                    uint16_t tm_seq_counter,
                                    uint16_t tc_packet_id,
                                    uint16_t tc_packet_error_ctrl,
                                    uint16_t event_ID, MissionObt current_obt,
                                    MyResult * const result);

void build_tm_1_4_ev_action_rejected(TMHandlerT * const p_tm_handler,
                                     uint16_t tm_seq_counter,
                                     uint16_t tc_packet_id,
                                     uint16_t tc_packet_error_ctrl,
                                     uint16_t event_ID, MissionObt current_obt,
                                     MyResult * const result);

void build_tm_1_4_ev_action_undefined(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      uint16_t event_ID, MissionObt current_obt,
                                      MyResult * const result);

void build_tm_1_4_PID_stats_undefined(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      uint16_t PID, MissionObt current_obt,
                                      MyResult * const result);

void build_tm_1_4_PID_read_only_via_TC(TMHandlerT * const p_tm_handler,
                                       uint16_t tm_seq_counter,
                                       uint16_t tc_packet_id,
                                       uint16_t tc_packet_error_ctrl,
                                       uint16_t PID, MissionObt current_obt,
                                       MyResult * const result);

void build_tm_1_4_error_in_acceptance(TMHandlerT * const p_tm_handler,
                                      uint16_t tm_seq_counter,
                                      uint16_t tc_packet_id,
                                      uint16_t tc_packet_error_ctrl,
                                      MissionObt current_obt,
                                      MyResult * const result);

void build_tm_1_7(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  uint8_t flags_ack, MissionObt current_obt,
                  MyResult * const result, _Bool * const enabled);

void build_tm_1_8_max_ev_actions_defined(TMHandlerT * const p_tm_handler,
                                         uint16_t tm_seq_counter,
                                         uint16_t tc_packet_id,
                                         uint16_t tc_packet_error_ctrl,
                                         uint16_t evID, MissionObt current_obt,
                                         MyResult * const result);

void build_tm_1_8_tm_exceed_limit_appdata(TMHandlerT * const p_tm_handler,
                                          uint16_t tm_seq_counter,
                                          uint16_t tc_packet_id,
                                          uint16_t tc_packet_error_ctrl,
                                          MissionObt current_obt,
                                          MyResult * const result);

void build_tm_1_8_device_command_exec_error(TMHandlerT * const p_tm_handler,
                                            uint16_t tm_seq_counter,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_error_ctrl,
                                            uint32_t on_off_command,
                                            MissionObt current_obt,
                                            MyResult * const result);

void build_tm_1_8_not_free_stats_config(TMHandlerT * const p_tm_handler,
                                        uint16_t tm_seq_counter,
                                        uint16_t tc_packet_id,
                                        uint16_t tc_packet_error_ctrl,
                                        uint16_t PID, MissionObt current_obt,
                                        MyResult * const result);

void build_tm_1_8_mem_access_error(TMHandlerT * const p_tm_handler,
                                   uint16_t tm_seq_counter,
                                   uint16_t tc_packet_id,
                                   uint16_t tc_packet_error_ctrl,
                                   uint8_t mem_ID, MissionObt current_obt,
                                   MyResult * const result);

#endif
