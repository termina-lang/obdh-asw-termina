#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1_H__

#include <termina.h>

#include "resources/tm_channel.h"
#include "resources/tm_counter.h"
#include "service_libraries/pus_services/pus_service1/internal.h"
#include "service_libraries/pus_services/pus_service1/tc_acceptance.h"
#include "service_libraries/pus_tc_handler.h"

#include "option.h"

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

typedef struct {
    void * __that;
    void (* notify_tm_1_1)(void * const, uint16_t, uint16_t, uint8_t,
                           __status_int32_t * const);
    void (* send_tm_1_2)(void * const, const TCStatus * const,
                         const TCHandler * const, __status_int32_t * const);
    void (* notify_tm_1_3)(void * const, uint16_t, uint16_t, uint8_t,
                           __status_int32_t * const);
    void (* send_tm_1_4_short_pack_length)(void * const, uint16_t, uint16_t,
                                           size_t, __status_int32_t * const);
    void (* send_tm_1_4_num_of_instr_not_valid)(void * const, uint16_t,
                                                uint16_t, uint8_t,
                                                __status_int32_t * const);
    void (* send_tm_1_4_device_address_not_valid)(void * const, uint16_t,
                                                  uint16_t, uint32_t,
                                                  __status_int32_t * const);
    void (* send_tm_1_4_SID_not_valid)(void * const, uint16_t, uint16_t,
                                       uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_mem_address_not_valid)(void * const, uint16_t, uint16_t,
                                               uint8_t, uint32_t,
                                               __status_int32_t * const);
    void (* send_tm_1_4_mem_id_read_only)(void * const, uint16_t, uint16_t,
                                          uint8_t, __status_int32_t * const);
    void (* send_tm_1_4_EvID_not_valid)(void * const, uint16_t, uint16_t,
                                        uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_PID_not_valid)(void * const, uint16_t, uint16_t,
                                       uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_PMON_undefined)(void * const, uint16_t, uint16_t,
                                        uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_PMON_defined)(void * const, uint16_t, uint16_t,
                                      uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_PMON_enabled)(void * const, uint16_t, uint16_t,
                                      uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_PMONID_invalid)(void * const, uint16_t, uint16_t,
                                        uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_PMON_definition_invalid)(void * const, uint16_t,
                                                 uint16_t, uint16_t,
                                                 __status_int32_t * const);
    void (* send_tm_1_4_ev_action_enabled)(void * const, uint16_t, uint16_t,
                                           uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_ev_action_rejected)(void * const, uint16_t, uint16_t,
                                            uint16_t, __status_int32_t * const);
    void (* send_tm_1_4_ev_action_undefined)(void * const, uint16_t, uint16_t,
                                             uint16_t,
                                             __status_int32_t * const);
    void (* send_tm_1_4_PID_stats_undefined)(void * const, uint16_t, uint16_t,
                                             uint16_t,
                                             __status_int32_t * const);
    void (* send_tm_1_4_PID_read_only_via_TC)(void * const, uint16_t, uint16_t,
                                              uint16_t,
                                              __status_int32_t * const);
    void (* send_tm_1_4_error_in_acceptance)(void * const, uint16_t, uint16_t,
                                             __status_int32_t * const);
    void (* notify_tm_1_7)(void * const, uint16_t, uint16_t, uint8_t,
                           __status_int32_t * const);
    void (* send_tm_1_8_max_ev_actions_defined)(void * const, uint16_t,
                                                uint16_t, uint16_t,
                                                __status_int32_t * const);
    void (* send_tm_1_8_tm_exceed_limit_appdata)(void * const, uint16_t,
                                                 uint16_t,
                                                 __status_int32_t * const);
    void (* send_tm_1_8_device_command_exec_error)(void * const, uint16_t,
                                                   uint16_t, uint32_t,
                                                   __status_int32_t * const);
    void (* send_tm_1_8_not_free_stats_config)(void * const, uint16_t, uint16_t,
                                               uint16_t,
                                               __status_int32_t * const);
    void (* send_tm_1_8_mem_access_error)(void * const, uint16_t, uint16_t,
                                          uint8_t, __status_int32_t * const);
} PUSService1Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionOBT * const);
    } obt_manager;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const,
                                   void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const, void * const,
                         __termina_box_t, __status_int32_t * const);
    } tm_channel;
} PUSService1;

void PUSService1__notify_tm_1_1(const __termina_event_t * const __ev,
                                void * const __this, uint16_t tc_packet_id,
                                uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                                __status_int32_t * const status);

void PUSService1__notify_tm_1_3(const __termina_event_t * const __ev,
                                void * const __this, uint16_t tc_packet_id,
                                uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                                __status_int32_t * const status);

void PUSService1__notify_tm_1_7(const __termina_event_t * const __ev,
                                void * const __this, uint16_t tc_packet_id,
                                uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                                __status_int32_t * const status);

void PUSService1__send_tm_1_2(const __termina_event_t * const __ev,
                              void * const __this,
                              const TCStatus * const tc_status,
                              const TCHandler * const tc_handler,
                              __status_int32_t * const status);

void PUSService1__send_tm_1_4_EvID_not_valid(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t EvID,
                                             __status_int32_t * const status);

void PUSService1__send_tm_1_4_PID_not_valid(const __termina_event_t * const __ev,
                                            void * const __this,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_seq_ctrl,
                                            uint16_t PID,
                                            __status_int32_t * const status);

void PUSService1__send_tm_1_4_PID_read_only_via_TC(const __termina_event_t * const __ev,
                                                   void * const __this,
                                                   uint16_t tc_packet_id,
                                                   uint16_t tc_packet_seq_ctrl,
                                                   uint16_t PID,
                                                   __status_int32_t * const status);

void PUSService1__send_tm_1_4_PID_stats_undefined(const __termina_event_t * const __ev,
                                                  void * const __this,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  uint16_t PID,
                                                  __status_int32_t * const status);

void PUSService1__send_tm_1_4_PMONID_invalid(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t PMONID,
                                             __status_int32_t * const status);

void PUSService1__send_tm_1_4_PMON_defined(const __termina_event_t * const __ev,
                                           void * const __this,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_seq_ctrl,
                                           uint16_t PMONID,
                                           __status_int32_t * const status);

void PUSService1__send_tm_1_4_PMON_definition_invalid(const __termina_event_t * const __ev,
                                                      void * const __this,
                                                      uint16_t tc_packet_id,
                                                      uint16_t tc_packet_seq_ctrl,
                                                      uint16_t PMONID,
                                                      __status_int32_t * const status);

void PUSService1__send_tm_1_4_PMON_enabled(const __termina_event_t * const __ev,
                                           void * const __this,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_seq_ctrl,
                                           uint16_t PMONID,
                                           __status_int32_t * const status);

void PUSService1__send_tm_1_4_PMON_undefined(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t PMONID,
                                             __status_int32_t * const status);

void PUSService1__send_tm_1_4_SID_not_valid(const __termina_event_t * const __ev,
                                            void * const __this,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_seq_ctrl,
                                            uint16_t SID,
                                            __status_int32_t * const status);

void PUSService1__send_tm_1_4_device_address_not_valid(const __termina_event_t * const __ev,
                                                       void * const __this,
                                                       uint16_t tc_packet_id,
                                                       uint16_t tc_packet_seq_ctrl,
                                                       uint32_t device_address,
                                                       __status_int32_t * const status);

void PUSService1__send_tm_1_4_error_in_acceptance(const __termina_event_t * const __ev,
                                                  void * const __this,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  __status_int32_t * const status);

void PUSService1__send_tm_1_4_ev_action_enabled(const __termina_event_t * const __ev,
                                                void * const __this,
                                                uint16_t tc_packet_id,
                                                uint16_t tc_packet_seq_ctrl,
                                                uint16_t event_ID,
                                                __status_int32_t * const status);

void PUSService1__send_tm_1_4_ev_action_rejected(const __termina_event_t * const __ev,
                                                 void * const __this,
                                                 uint16_t tc_packet_id,
                                                 uint16_t tc_packet_seq_ctrl,
                                                 uint16_t event_ID,
                                                 __status_int32_t * const status);

void PUSService1__send_tm_1_4_ev_action_undefined(const __termina_event_t * const __ev,
                                                  void * const __this,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  uint16_t event_ID,
                                                  __status_int32_t * const status);

void PUSService1__send_tm_1_4_mem_address_not_valid(const __termina_event_t * const __ev,
                                                    void * const __this,
                                                    uint16_t tc_packet_id,
                                                    uint16_t tc_packet_seq_ctrl,
                                                    uint8_t mem_id,
                                                    uint32_t mem_address,
                                                    __status_int32_t * const status);

void PUSService1__send_tm_1_4_mem_id_read_only(const __termina_event_t * const __ev,
                                               void * const __this,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               uint8_t mem_id,
                                               __status_int32_t * const status);

void PUSService1__send_tm_1_4_num_of_instr_not_valid(const __termina_event_t * const __ev,
                                                     void * const __this,
                                                     uint16_t tc_packet_id,
                                                     uint16_t tc_packet_seq_ctrl,
                                                     uint8_t N,
                                                     __status_int32_t * const status);

void PUSService1__send_tm_1_4_short_pack_length(const __termina_event_t * const __ev,
                                                void * const __this,
                                                uint16_t tc_packet_id,
                                                uint16_t tc_packet_seq_ctrl,
                                                size_t tc_bytes,
                                                __status_int32_t * const status);

void PUSService1__send_tm_1_8_device_command_exec_error(const __termina_event_t * const __ev,
                                                        void * const __this,
                                                        uint16_t tc_packet_id,
                                                        uint16_t tc_packet_seq_ctrl,
                                                        uint32_t on_off_command,
                                                        __status_int32_t * const status);

void PUSService1__send_tm_1_8_max_ev_actions_defined(const __termina_event_t * const __ev,
                                                     void * const __this,
                                                     uint16_t tc_packet_id,
                                                     uint16_t tc_packet_seq_ctrl,
                                                     uint16_t evID,
                                                     __status_int32_t * const status);

void PUSService1__send_tm_1_8_mem_access_error(const __termina_event_t * const __ev,
                                               void * const __this,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               uint8_t mem_ID,
                                               __status_int32_t * const status);

void PUSService1__send_tm_1_8_not_free_stats_config(const __termina_event_t * const __ev,
                                                    void * const __this,
                                                    uint16_t tc_packet_id,
                                                    uint16_t tc_packet_seq_ctrl,
                                                    uint16_t PID,
                                                    __status_int32_t * const status);

void PUSService1__send_tm_1_8_tm_exceed_limit_appdata(const __termina_event_t * const __ev,
                                                      void * const __this,
                                                      uint16_t tc_packet_id,
                                                      uint16_t tc_packet_seq_ctrl,
                                                      __status_int32_t * const status);

#endif
