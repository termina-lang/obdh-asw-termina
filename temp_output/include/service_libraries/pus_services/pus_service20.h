#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "resources/system_data_pool.h"

typedef struct {
    void * __that;
    void (* exec20_1TC)(void * const, const TCDescriptorT * const,
                        Result * const);
    void (* exec20_3TC)(void * const, const TCDescriptorT * const,
                        Result * const);
} PUSS20Iface;

typedef struct {
    __termina_resource_t __resource;
    TMCounterIface tm_counter;
    __termina_pool_t * a_tm_descriptor_pool;
    TMChannelIface tm_channel;
    _Atomic uint16_t * system_data_pool;
} PUSService20;

void PUSService20__build_tm_20_2(const PUSService20 * const self, size_t PID,
                                 TMDescriptorT * const p_tm_descriptor,
                                 uint16_t tm_seq_counter);

void PUSService20__exec20_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

void PUSService20__exec20_3TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result);

#endif
