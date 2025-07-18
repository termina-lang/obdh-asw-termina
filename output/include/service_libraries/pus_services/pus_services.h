#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__

#include <termina.h>

#include "resources/system_data_pool.h"
#include "resources/tm_counter.h"
#include "service_libraries/errors.h"
#include "service_libraries/pus_tc_handler.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef enum {
    PSExecTCReqStatus__Init,
    PSExecTCReqStatus__ExecTC,
    PSExecTCReqStatus__Exit
} __enum_PSExecTCReqStatus_t;

typedef struct {
    __enum_PSExecTCReqStatus_t __variant;
} PSExecTCReqStatus;

typedef struct {
    uint32_t seconds;
    uint16_t finetime;
} MissionObt;

#endif
