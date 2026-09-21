#ifndef RESOURCES__SYSTEM_DATA_POOL_H__
#define RESOURCES__SYSTEM_DATA_POOL_H__

#include <termina.h>

#include "option.h"

typedef enum {
    DataPoolItemType__u8_t,
    DataPoolItemType__u32_t,
    DataPoolItemType__NoValidPID
} termina__enum__DataPoolItemType_t;

typedef struct {
    termina__enum__DataPoolItemType_t _variant;
} DataPoolItemType;

DataPoolItemType sys_data_pool_get_item_type(const uint16_t PID);

_Bool sys_data_pool_is_valid_PID(const uint16_t PID);

_Bool sys_data_pool_is_PID_update_via_TC_enabled(const uint16_t PID);

#endif
