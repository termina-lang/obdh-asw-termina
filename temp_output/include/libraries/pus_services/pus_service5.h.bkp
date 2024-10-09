#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/serialize.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/event_list.h"

#define informative_RIDs UINT16_C(3)

#define low_severity_anomaly_RIDs UINT16_C(4)

#define medium_severity_anomaly_RIDs UINT16_C(0)

#define high_severity_anomaly_RIDs UINT16_C(16)

#define offset_mask UINT16_C(0x1F)

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

_Bool is_RID_enabled(uint16_t RID, const uint32_t RID_enable_config_table[4]);

void exec5_5TC(const TCDescriptorT * tc_descriptor,
               TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
               uint32_t RID_enable_config_table[4]);

void exec5_6TC(const TCDescriptorT * tc_descriptor,
               TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
               uint32_t RID_enable_config_table[4]);

void PUS_service_5_execTC(const TCDescriptorT * tc_descriptor,
                          TMDescriptorT * tm_descriptor,
                          uint16_t tm_seq_counter,
                          uint32_t RID_enable_config_table[4]);

void build_tm_5_x(TMDescriptorT * p_tm_descriptor, uint16_t tm_seq_counter,
                  const EventInfo * event, size_t index);

#endif
