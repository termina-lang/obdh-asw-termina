#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICE19_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICE19_H__

#include <termina.h>

#include "option.h"
#include "libraries/pus_services/pus_service5.h"
#include "libraries/pus_services/pus_service1.h"
#include "libraries/serialize.h"
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/tm_ccsds_pus_format.h"

#define max_event_action_definitions 16

#define event_action_queue_dimension 8

#define event_action_max_bytes 242

typedef struct {
    _Bool enabled;
    uint16_t event_ID;
} EventActionConfig;

_Bool get_event_action_config(uint16_t evID, size_t * index, _Bool * enabled,
                              const EventActionConfig event_action_config_table[max_event_action_definitions]);

_Bool get_free_event_action_index(size_t * index,
                                  const EventActionConfig event_action_config_table[max_event_action_definitions]);

void exec19_1TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions],
                TCDescriptorT event_action_packs[max_event_action_definitions]);

void exec19_2TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions]);

void exec19_4TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions]);

void exec19_5TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                EventActionConfig event_action_config_table[max_event_action_definitions]);

void PUS_service_19_execTC(const TCDescriptorT * tc_descriptor,
                           TMDescriptorT * tm_descriptor,
                           uint16_t tm_seq_counter,
                           EventActionConfig event_action_config_table[max_event_action_definitions],
                           TCDescriptorT event_action_packs[max_event_action_definitions]);

#endif
