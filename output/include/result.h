#ifndef __RESULT_H__
#define __RESULT_H__

#include <termina.h>

typedef struct {
    _Bool __0;
} __result_bool_int32__Ok_params_t;

typedef struct {
    int32_t __0;
} __result_bool_int32__Error_params_t;

typedef struct {
    __result_bool_int32__Ok_params_t Ok;
    __result_bool_int32__Error_params_t Error;
    __enum_result_t __variant;
} __result_bool__int32_t;

#endif
