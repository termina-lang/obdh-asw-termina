#ifndef __DRIVERS__CHAR_DEV_H__
#define __DRIVERS__CHAR_DEV_H__

#include <termina.h>

#include "option.h"

typedef enum {
    CharDevIrqStatus__RxComplete,
    CharDevIrqStatus__IrqOk,
    CharDevIrqStatus__IrqError
} __enum_CharDevIrqStatus_t;

typedef struct {
    size_t __0;
} __enum_CharDevIrqStatus__RxComplete_params_t;

typedef struct {
    int32_t __0;
} __enum_CharDevIrqStatus__IrqError_params_t;

typedef struct {
    __enum_CharDevIrqStatus_t __variant;
    union {
        __enum_CharDevIrqStatus__RxComplete_params_t RxComplete;
        __enum_CharDevIrqStatus__IrqError_params_t IrqError;
    };
} CharDevIrqStatus;

#endif
