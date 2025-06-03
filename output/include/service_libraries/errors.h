#ifndef __SERVICE_LIBRARIES__ERRORS_H__
#define __SERVICE_LIBRARIES__ERRORS_H__

#include <termina.h>

#include "option.h"
#include "result.h"

extern const int32_t TM_POOL_ALLOC_FAILURE;

extern const int32_t TM_SEND_FAILURE;

extern const int32_t BUILD_TM_ERROR;

extern const int32_t ACCEPTANCE_ERROR;

extern const int32_t TC_DATA_OUT_OF_RANGE_ERROR;

extern const int32_t UNREACHABLE_BRANCH_ERROR;

typedef enum {
    MyResult__Ok,
    MyResult__Error
} __enum_MyResult_t;

typedef struct {
    __enum_MyResult_t __variant;
} MyResult;

#endif
