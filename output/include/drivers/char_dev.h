#ifndef DRIVERS__CHAR_DEV_H__
#define DRIVERS__CHAR_DEV_H__

#include <termina.h>

#include "option.h"

typedef enum {
    CharDevIrqStatus__RxComplete,
    CharDevIrqStatus__IrqOk,
    CharDevIrqStatus__IrqError
} termina__enum__CharDevIrqStatus_t;

typedef struct {
    size_t _0;
} termina__enum__CharDevIrqStatus__RxComplete_params_t;

typedef struct {
    int32_t _0;
} termina__enum__CharDevIrqStatus__IrqError_params_t;

typedef struct {
    termina__enum__CharDevIrqStatus_t _variant;
    union {
        termina__enum__CharDevIrqStatus__RxComplete_params_t RxComplete;
        termina__enum__CharDevIrqStatus__IrqError_params_t IrqError;
    };
} CharDevIrqStatus;

#endif
