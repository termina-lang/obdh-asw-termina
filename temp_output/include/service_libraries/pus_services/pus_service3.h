#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE3_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/serialize.h"
#include "resources/system_data_pool.h"
#include "tasks/tm_channel.h"
#include "resources/tm_counter.h"

#define max_num_of_SIDs 8

#define max_params_per_SID 16

typedef struct {
    _Bool enabled;
    uint8_t SID;
    uint16_t interval;
    uint16_t interval_control;
    uint8_t num_params;
    uint8_t params_def[max_params_per_SID];
} HKConfiguration;

typedef struct {
    void * __that;
    void (* do_hk)(void * const, Result * const);
    void (* exec3_5TC)(void * const, const TCDescriptorT * const,
                       TMDescriptorT * const, uint16_t);
    void (* exec3_6TC)(void * const, const TCDescriptorT * const,
                       TMDescriptorT * const, uint16_t);
    void (* exec3_31TC)(void * const, const TCDescriptorT * const,
                        TMDescriptorT * const, uint16_t);
} PUSS3Iface;

typedef struct {
    __termina_resource_t __resource;
    TMCounterIface tm_counter;
    __termina_pool_t * a_tm_descriptor_pool;
    TMChannelIface tm_channel;
    _Atomic uint16_t * system_data_pool;
    HKConfiguration hk_config_table[max_num_of_SIDs];
} PUSService3;

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMDescriptorT * const p_tm_descriptor,
                                uint16_t tm_seq_counter, size_t index);

void PUSService3__do_hk(void * const __this, Result * const result);

_Bool PUSService3__get_SIDindex(const PUSService3 * const self, uint8_t SID,
                                size_t * const index);

void PUSService3__exec3_31TC(void * const __this,
                             const TCDescriptorT * const tc_descriptor,
                             TMDescriptorT * const tm_descriptor,
                             uint16_t tm_seq_counter);

void PUSService3__exec3_5TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            TMDescriptorT * const tm_descriptor,
                            uint16_t tm_seq_counter);

void PUSService3__exec3_6TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            TMDescriptorT * const tm_descriptor,
                            uint16_t tm_seq_counter);

#endif
