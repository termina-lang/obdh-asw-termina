#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19__PUS_SERVICE19_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19__PUS_SERVICE19_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service19/pus_service19_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* manage_event_action)(void * const, uint16_t);
    void (* get_pending_action_number)(void * const, size_t *);
    void (* extract_action)(void * const, size_t, TCHandlerT * const);
} PUSS19Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const,
                                   void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const, void * const,
                         __termina_box_t, __status_int32_t * const);
    } tm_channel;
    size_t pending_action_head[4U];
    size_t pending_action_number[4U];
    TCHandlerT pending_action_queue_4HS[8U];
    TCHandlerT pending_action_queue_3MS[8U];
    TCHandlerT pending_action_queue_2LS[8U];
    TCHandlerT pending_action_queue_1I[8U];
    TCHandlerT event_action_packets[16U];
    EventActionConfig event_action_config[16U];
    PS19ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
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
                                           _Bool * const enabled,
                                           uint16_t evID);

PSExecTCReqStatus PUSService19__exec19_1TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self);

PSExecTCReqStatus PUSService19__exec19_2TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self);

PSExecTCReqStatus PUSService19__exec19_4TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self);

PSExecTCReqStatus PUSService19__exec19_5TC(const __termina_event_t * const __ev,
                                           PUSService19 * const self);

PSExecTCReqStatus PUSService19__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                           const PUSService19 * const self);

PSExecTCReqStatus PUSService19__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                               const PUSService19 * const self);

PSExecTCReqStatus PUSService19__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                 const PUSService19 * const self);

void PUSService19__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);

void PUSService19__extract_action(const __termina_event_t * const __ev,
                                  void * const __this, size_t index,
                                  TCHandlerT * const action_packet);

_Bool PUSService19__get_event_action_config(const __termina_event_t * const __ev,
                                            const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled);

void PUSService19__get_pending_action_number(const __termina_event_t * const __ev,
                                             void * const __this,
                                             size_t paction_num[4U]);

void PUSService19__manage_event_action(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t evID);

#endif
