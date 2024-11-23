#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE12_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/serialize.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/event_list.h"
#include "resources/system_data_pool.h"

#define max_num_pmon_ids 8

typedef enum {
    CheckState__MonitorUnselected,
    CheckState__MonitorUnchecked,
    CheckState__MonitorAboveHighLimit,
    CheckState__MonitorBelowLowLimit,
    CheckState__MonitorWithinLimits
} __enum_CheckState_t;

typedef struct {
    __enum_CheckState_t __variant;
} CheckState;

typedef struct {
    CheckState prev_state;
    CheckState state;
    TimeVal transitionY2K;
    _Bool enabled;
    uint16_t PID;
    uint8_t interval;
    uint8_t interval_control;
} ParamMonitoringConfiguration;

typedef struct {
    uint16_t high_limit_rid;
    uint16_t high_limit;
    uint16_t low_limit_rid;
    uint16_t low_limit;
} ParamLimitCheckDefinition;

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

void trigger_event(EventList * const event_list, uint16_t RID, uint16_t PID,
                   uint16_t PID_value, uint16_t limit, Result * const res);

void update_state(ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                  size_t PMONID, CheckState new_state);

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
