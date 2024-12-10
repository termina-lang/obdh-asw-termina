#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE17_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/tc_ccsds_pus_format.h"

void build_tm_17_2(TMDescriptorT * const tm_descriptor,
                   uint16_t tm_seq_counter);

typedef struct {
    void * __that;
    void (* exec17_1TC)(void * const, const TCDescriptorT * const,
                        Result * const);
} PUSS17Iface;

typedef struct {
    __termina_resource_t __resource;
    TMCounterIface tm_counter;
    __termina_pool_t * a_tm_descriptor_pool;
    TMChannelIface tm_channel;
} PUSService17;

void PUSService17__exec17_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

#endif
