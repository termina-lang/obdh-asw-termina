#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_HELP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/serialize.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
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

#endif
