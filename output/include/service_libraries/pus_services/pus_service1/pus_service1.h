#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__PUS_SERVICE1_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"
#include "service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.h"

#include "option.h"
#include "result.h"

TCExecutionCtrl handle_tc(const TCDescriptorT * const tc_descriptor);

TCStatus try_tc_acceptation(const TCDescriptorT * const tc_descriptor);

#endif
