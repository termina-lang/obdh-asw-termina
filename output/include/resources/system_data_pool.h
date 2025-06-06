#ifndef __RESOURCES__SYSTEM_DATA_POOL_H__
#define __RESOURCES__SYSTEM_DATA_POOL_H__

#include <termina.h>

#include "option.h"

typedef enum {
    DataPoolItemType__u8_t,
    DataPoolItemType__u32_t,
    DataPoolItemType__NoValidPID
} __enum_DataPoolItemType_t;

typedef struct {
    __enum_DataPoolItemType_t __variant;
} DataPoolItemType;

DataPoolItemType sys_data_pool_get_item_type(uint16_t PID);

_Bool sys_data_pool_is_valid_PID(uint16_t PID);

_Bool sys_data_pool_is_PID_update_via_TC_enabled(uint16_t PID);

#endif
