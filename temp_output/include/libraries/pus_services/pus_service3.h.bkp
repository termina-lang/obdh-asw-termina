#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__

#include <termina.h>

#include "option.h"
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/tm_ccsds_pus_format.h"
#include "libraries/pus_services/pus_service1.h"
#include "libraries/serialize.h"

#define max_num_of_SIDs 8

#define max_params_per_SID 16

typedef struct {
    _Bool enabled;
    uint8_t SID;
    uint16_t interval;
    uint16_t interval_control;
    uint8_t num_params;
    uint8_t params_def[max_params_per_SID];
} hk_configuration;

_Bool get_SIDindex(const hk_configuration hk_config_table[max_num_of_SIDs],
                   uint8_t SID, size_t * index);

void enable_config(const TCDescriptorT * tc_descriptor,
                   TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                   hk_configuration hk_config_table[max_num_of_SIDs],
                   _Bool new_enable_config);

void exec3_5TC(const TCDescriptorT * tc_descriptor,
               TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
               hk_configuration hk_config_table[max_num_of_SIDs]);

void exec3_6TC(const TCDescriptorT * tc_descriptor,
               TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
               hk_configuration hk_config_table[max_num_of_SIDs]);

void exec3_31TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                hk_configuration hk_config_table[max_num_of_SIDs]);

void PUS_service_3_execTC(const TCDescriptorT * tc_descriptor,
                          TMDescriptorT * tm_descriptor,
                          uint16_t tm_seq_counter,
                          hk_configuration hk_config_table[max_num_of_SIDs]);

#endif
