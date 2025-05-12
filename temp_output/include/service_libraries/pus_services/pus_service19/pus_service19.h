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
    __termina_id_t __mutex_id;
    struct {
        void * __that;
        void (* get_current_obt)(void * const, MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
    size_t pending_action_head[4U];
    size_t pending_action_number[4U];
    TCHandlerT pending_action_queue_4HS[event_action_queue_dimension];
    TCHandlerT pending_action_queue_3MS[event_action_queue_dimension];
    TCHandlerT pending_action_queue_2LS[event_action_queue_dimension];
    TCHandlerT pending_action_queue_1I[event_action_queue_dimension];
    TCHandlerT event_action_packets[max_event_action_definitions];
    EventActionConfig event_action_config[max_event_action_definitions];
    PS19ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService19;

MyResult PUSService19__delete_event_action(PUSService19 * const self);

MyResult PUSService19__disable_event_action(PUSService19 * const self);

MyResult PUSService19__enable_event_action(PUSService19 * const self);

FoundID PUSService19__get_free_event_action_index(const PUSService19 * const self);

FoundID PUSService19__is_ev_action_defined(const PUSService19 * const self,
                                           _Bool * const enabled,
                                           uint16_t evID);

PSExecTCReqStatus PUSService19__exec19_1TC(PUSService19 * const self);

PSExecTCReqStatus PUSService19__exec19_2TC(PUSService19 * const self);

PSExecTCReqStatus PUSService19__exec19_4TC(PUSService19 * const self);

PSExecTCReqStatus PUSService19__exec19_5TC(PUSService19 * const self);

PS19ExecTCReqStatusUpdate PUSService19__get_TC_params(const PUSService19 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result);

PSExecTCReqStatus PUSService19__manage_short_pack_length_error(const PUSService19 * const self);

void PUSService19__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status);
void PUSService19__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);
void PUSService19__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService19__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status);

void PUSService19__extract_action(void * const __this, size_t index,
                                  TCHandlerT * const action_packet);
void PUSService19__extract_action__mutex_lock(void * const __this, size_t index,
                                              TCHandlerT * const action_packet);
void PUSService19__extract_action__task_lock(void * const __this, size_t index,
                                             TCHandlerT * const action_packet);
void PUSService19__extract_action__event_lock(void * const __this, size_t index,
                                              TCHandlerT * const action_packet);

_Bool PUSService19__get_event_action_config(const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled);

void PUSService19__get_pending_action_number(void * const __this,
                                             size_t paction_num[4U]);
void PUSService19__get_pending_action_number__mutex_lock(void * const __this,
                                                         size_t paction_num[4U]);
void PUSService19__get_pending_action_number__task_lock(void * const __this,
                                                        size_t paction_num[4U]);
void PUSService19__get_pending_action_number__event_lock(void * const __this,
                                                         size_t paction_num[4U]);

void PUSService19__manage_event_action(void * const __this, uint16_t evID);
void PUSService19__manage_event_action__mutex_lock(void * const __this,
                                                   uint16_t evID);
void PUSService19__manage_event_action__task_lock(void * const __this,
                                                  uint16_t evID);
void PUSService19__manage_event_action__event_lock(void * const __this,
                                                   uint16_t evID);

#endif
