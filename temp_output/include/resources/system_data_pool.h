#ifndef __RESOURCES__SYSTEM_DATA_POOL_H__
#define __RESOURCES__SYSTEM_DATA_POOL_H__

#include <termina.h>
#include "libraries/pus_services/pus_service3.h"

#define SDP_num_params 64

typedef struct {
    void * __that;
    void (* init)(void * __this);
    void (* write_value)(void * __this, size_t index, uint16_t value);
    void (* read_value)(void * __this, size_t index, uint16_t * r_value);
} SDP_rw_init;

typedef struct {
    __termina_resource_t __resource;
    uint16_t sdp_values[SDP_num_params];
} SystemDataPool;

void SystemDataPool__write_value(void * const __this, size_t index,
                                 uint16_t value);

void SystemDataPool__read_value(void * const __this, size_t index,
                                uint16_t * r_value);

void SystemDataPool__init(void * const __this);

#endif
