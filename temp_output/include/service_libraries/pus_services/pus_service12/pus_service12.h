#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__PUS_SERVICE12_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12__PUS_SERVICE12_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

typedef struct {
    void * __that;
    void (* do_monitoring)(void * const, EventList * const, Result * const);
    void (* exec12_1TC)(void * const, const TCDescriptorT * const,
                        TMDescriptorT * const, uint16_t);
    void (* exec12_2TC)(void * const, const TCDescriptorT * const,
                        TMDescriptorT * const, uint16_t);
    void (* exec12_5TC)(void * const, const TCDescriptorT * const,
                        TMDescriptorT * const, uint16_t);
} PUSS12Iface;

typedef struct {
    __termina_resource_t __resource;
    _Atomic uint16_t * system_data_pool;
    ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids];
    ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids];
} PUSService12;

void PUSService12__do_monitoring(void * const __this,
                                 EventList * const event_list,
                                 Result * const result);

void PUSService12__exec12_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter);

void PUSService12__exec12_2TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter);

void PUSService12__exec12_5TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter);

#endif
