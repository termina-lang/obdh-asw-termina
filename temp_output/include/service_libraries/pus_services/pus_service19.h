#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE19_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/event_list.h"

#define event_action_max_bytes 242

#define max_event_action_definitions 16

#define event_action_queue_dimension 8

typedef struct {
    _Bool enabled;
    uint16_t event_ID;
} EventActionConfig;

typedef struct {
    void * __that;
    void (* exec19_1TC)(void * const, const TCDescriptorT * const,
                        Result * const);
    void (* exec19_2TC)(void * const, const TCDescriptorT * const,
                        Result * const);
    void (* exec19_4TC)(void * const, const TCDescriptorT * const,
                        Result * const);
    void (* exec19_5TC)(void * const, const TCDescriptorT * const,
                        Result * const);
    void (* manage_event_actions)(void * const, EventList * const);
    void (* get_pending_action_number)(void * const, size_t *);
    void (* extract_action)(void * const, size_t, TCDescriptorT * const);
} PUSS19Iface;

typedef struct {
    __termina_resource_t __resource;
    TMCounterIface tm_counter;
    __termina_pool_t * a_tm_descriptor_pool;
    TMChannelIface tm_channel;
    PUSS5Iface pus_service_5;
    size_t pending_action_head[4U];
    size_t pending_action_number[4U];
    TCDescriptorT pending_action_queue_4HS[event_action_queue_dimension];
    TCDescriptorT pending_action_queue_3MS[event_action_queue_dimension];
    TCDescriptorT pending_action_queue_2LS[event_action_queue_dimension];
    TCDescriptorT pending_action_queue_1I[event_action_queue_dimension];
    TCDescriptorT event_action_packets[max_event_action_definitions];
    EventActionConfig event_action_config[max_event_action_definitions];
} PUSService19;

_Bool PUSService19__get_event_action_config(const PUSService19 * const self,
                                            uint16_t evID, size_t * const index,
                                            _Bool * const enabled);

_Bool PUSService19__get_free_event_action_index(const PUSService19 * const self,
                                                size_t * const index);

void PUSService19__exec19_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

void PUSService19__exec19_2TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

void PUSService19__exec19_4TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

void PUSService19__exec19_5TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

void PUSService19__extract_action(void * const __this, size_t index,
                                  TCDescriptorT * const action_packet);

void PUSService19__get_pending_action_number(void * const __this,
                                             size_t paction_num[4U]);

void PUSService19__manage_event_actions(void * const __this,
                                        EventList * const event_list);

#endif
