#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__TC_ACCEPTANCE_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE1__TC_ACCEPTANCE_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service1/internal.h"

#include "option.h"
#include "result.h"

TCExecutionCtrl handle_tc(const TCDescriptor * const tc_descriptor);

TCStatus try_tc_acceptation(const TCDescriptor * const tc_descriptor);

#endif
