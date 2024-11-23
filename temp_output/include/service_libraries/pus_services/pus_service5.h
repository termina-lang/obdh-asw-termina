#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/serialize.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/event_list.h"

#define informative_RIDs 3

#define low_severity_anomaly_RIDs 4

#define medium_severity_anomaly_RIDs 0

#define high_severity_anomaly_RIDs 16

#define offset_mask 0x1F

typedef enum {
    RIDType__Informative,
    RIDType__LowSeverityAnomaly,
    RIDType__MediumSeverityAnomaly,
    RIDType__HighSeverityAnomaly,
    RIDType__RIDNotValid
} __enum_RIDType_t;

typedef struct {
    __enum_RIDType_t __variant;
} RIDType;

RIDType get_RID_type(uint16_t RID);

size_t get_RID_enable_config_index(uint16_t RID);

uint8_t get_RID_enable_config_offset(uint16_t RID);

void build_tm_5_x(TMDescriptorT * const p_tm_descriptor,
                  uint16_t tm_seq_counter, const EventInfo * const event,
                  size_t index);

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
