#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

typedef struct {
    void * __that;
    void (* build_event_list_tms)(void * const, EventList * const,
                                  Result * const);
    void (* exec5_5TC)(void * const, const TCDescriptorT * const,
                       TMDescriptorT * const, uint16_t);
    void (* exec5_6TC)(void * const, const TCDescriptorT * const,
                       TMDescriptorT * const, uint16_t);
    void (* is_RID_enabled_ext)(void * const, uint16_t, _Bool * const);
} PUSS5Iface;

typedef struct {
    __termina_resource_t __resource;
    TMCounterIface tm_counter;
    __termina_pool_t * a_tm_descriptor_pool;
    TMChannelIface tm_channel;
    uint32_t RID_enable_config[4];
} PUSService5;

_Bool PUSService5__is_RID_enabled(const PUSService5 * const self, uint16_t RID);

void PUSService5__build_event_list_tms(void * const __this,
                                       EventList * const event_list,
                                       Result * const result);

void PUSService5__exec5_5TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            TMDescriptorT * const tm_descriptor,
                            uint16_t tm_seq_counter);

void PUSService5__exec5_6TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            TMDescriptorT * const tm_descriptor,
                            uint16_t tm_seq_counter);

void PUSService5__is_RID_enabled_ext(void * const __this, uint16_t RID,
                                     _Bool * const p_enabled);

#endif
