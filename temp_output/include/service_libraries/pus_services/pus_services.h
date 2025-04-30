#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__

#include <termina.h>

#include "option.h"

typedef enum {
    PSExecTCReqStatus__Init,
    PSExecTCReqStatus__ExecTC,
    PSExecTCReqStatus__Error,
    PSExecTCReqStatus__Exit
} __enum_PSExecTCReqStatus_t;

typedef struct {
    __enum_PSExecTCReqStatus_t __variant;
} PSExecTCReqStatus;

#endif
