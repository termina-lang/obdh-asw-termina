#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICES_H__

#include <termina.h>

#include "service_libraries/errors.h"

#include "option.h"

typedef enum {
    PSExecTCReqStatus__Init,
    PSExecTCReqStatus__ExecTC,
    PSExecTCReqStatus__Error,
    PSExecTCReqStatus__Failure,
    PSExecTCReqStatus__Exit
} __enum_PSExecTCReqStatus_t;

typedef struct {
    int32_t __0;
} __enum_PSExecTCReqStatus__Error_params_t;

typedef struct {
    int32_t __0;
} __enum_PSExecTCReqStatus__Failure_params_t;

typedef struct {
    __enum_PSExecTCReqStatus_t __variant;
    union {
        __enum_PSExecTCReqStatus__Error_params_t Error;
        __enum_PSExecTCReqStatus__Failure_params_t Failure;
    };
} PSExecTCReqStatus;

typedef enum {
    MyResult__Ok,
    MyResult__Error
} __enum_MyResult_t;

typedef struct {
    __enum_MyResult_t __variant;
} MyResult;

#endif
