#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICE12_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICE12_H__

#include <termina.h>

#include "option.h"
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/tm_ccsds_pus_format.h"
#include "libraries/serialize.h"
#include "libraries/pus_services/pus_service1.h"
#include "libraries/pus_services/pus_service3.h"
#include "libraries/event_list.h"

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

void exec12_1TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids]);

void exec12_2TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids]);

void exec12_5TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids]);

void PUS_service_12_execTC(const TCDescriptorT * tc_descriptor,
                           TMDescriptorT * tm_descriptor,
                           uint16_t tm_seq_counter,
                           ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                           ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids]);

void trigger_event(EventList * event_list, uint16_t RID, uint16_t PID,
                   uint16_t PID_value, uint16_t limit, Result * res);

void update_state(ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                  size_t PMONID, CheckState new_state);

#endif
