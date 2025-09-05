#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service19/types.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandler * const, __status_int32_t * const);
    void (* manage_event_action)(void * const, uint16_t);
    void (* get_pending_action_number)(void * const, size_t *);
    void (* extract_action)(void * const, size_t, TCHandler * const);
} PUSS19Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const,
                               uint16_t, uint16_t, uint8_t,
                               __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const,
                               uint16_t, uint16_t, uint8_t,
                               __status_int32_t * const);
        void (* send_tm_1_4_EvID_not_valid)(const __termina_event_t * const,
                                            void * const, uint16_t, uint16_t,
                                            uint16_t, __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const,
                                                 void * const, uint16_t,
                                                 uint16_t,
                                                 __status_int32_t * const);
        void (* send_tm_1_4_ev_action_enabled)(const __termina_event_t * const,
                                               void * const, uint16_t, uint16_t,
                                               uint16_t,
                                               __status_int32_t * const);
        void (* send_tm_1_4_ev_action_rejected)(const __termina_event_t * const,
                                                void * const, uint16_t,
                                                uint16_t, uint16_t,
                                                __status_int32_t * const);
        void (* send_tm_1_4_ev_action_undefined)(const __termina_event_t * const,
                                                 void * const, uint16_t,
                                                 uint16_t, uint16_t,
                                                 __status_int32_t * const);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const,
                                                    void * const, uint16_t,
                                                    uint16_t, uint8_t,
                                                    __status_int32_t * const);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const,
                                               void * const, uint16_t, uint16_t,
                                               size_t,
                                               __status_int32_t * const);
        void (* send_tm_1_8_max_ev_actions_defined)(const __termina_event_t * const,
                                                    void * const, uint16_t,
                                                    uint16_t, uint16_t,
                                                    __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const,
                                                     void * const, uint16_t,
                                                     uint16_t,
                                                     __status_int32_t * const);
    } pus_service_1;
    size_t pending_action_head[4U];
    size_t pending_action_number[4U];
    TCHandler pending_action_queue_4HS[8U];
    TCHandler pending_action_queue_3MS[8U];
    TCHandler pending_action_queue_2LS[8U];
    TCHandler pending_action_queue_1I[8U];
    TCHandler event_action_packets[16U];
    EventActionConfig event_action_config[16U];
    PS19ExecTCReqStatusUpdate exec_tc_req_status_update;
} PUSService19;

__status_int32_t PUSService19__delete_event_action(const __termina_event_t * const __ev,
                                                   PUSService19 * const self);

__status_int32_t PUSService19__disable_event_action(const __termina_event_t * const __ev,
                                                    PUSService19 * const self);

__status_int32_t PUSService19__enable_event_action(const __termina_event_t * const __ev,
                                                   PUSService19 * const self);

FoundID PUSService19__get_free_event_action_index(const __termina_event_t * const __ev,
                                                  const PUSService19 * const self);

FoundID PUSService19__is_ev_action_defined(const __termina_event_t * const __ev,
                                           const PUSService19 * const self,
                                           uint16_t evID);

__status_int32_t PUSService19__exec19_1TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self);

__status_int32_t PUSService19__exec19_2TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self);

__status_int32_t PUSService19__exec19_4TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self);

__status_int32_t PUSService19__exec19_5TC(const __termina_event_t * const __ev,
                                          PUSService19 * const self);

void PUSService19__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandler * const tc_handler,
                           __status_int32_t * const action_status);

void PUSService19__extract_action(const __termina_event_t * const __ev,
                                  void * const __this, size_t index,
                                  TCHandler * const action_packet);

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev,
                                             void * const __this,
                                             size_t paction_num[4U]);

void PUSService19__manage_event_action(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t evID);

#endif
