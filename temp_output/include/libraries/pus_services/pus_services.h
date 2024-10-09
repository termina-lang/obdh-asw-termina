#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service12.h"
#include "service_libraries/pus_services/pus_service5.h"

void PUS_prio_exec_tc(const TCDescriptorT * tc_descriptor,
                      TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter);

void PUS_hk_fdir_exec_tc(const TCDescriptorT * tc_descriptor,
                         TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                         HKConfiguration hk_config_table[max_num_of_SIDs],
                         uint32_t RID_enable_config_table[4],
                         ParamMonitoringConfiguration param_mon_config_table[max_num_pmon_ids],
                         ParamLimitCheckDefinition param_limit_check_definition[max_num_pmon_ids]);

void PUS_bkg_exec_tc(const TCDescriptorT * tc_descriptor,
                     TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                     HKConfiguration hk_config_table[max_num_of_SIDs]);

#endif
