#ifndef __LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__
#define __LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__

#include <termina.h>

#include "option.h"
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/tm_ccsds_pus_format.h"
#include "libraries/pus_services/pus_service17.h"
#include "libraries/pus_services/pus_service3.h"

void PUS_prio_exec_tc(const TCDescriptorT * tc_descriptor,
                      TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter);

void PUS_hk_fdir_exec_tc(const TCDescriptorT * tc_descriptor,
                         TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                         HKConfiguration hk_config_table[max_num_of_SIDs]);

#endif
