#ifndef RESOURCES__OBT_MANAGER_H__
#define RESOURCES__OBT_MANAGER_H__

#include <termina.h>

#include "service_libraries/timeval.h"

#include "option.h"

typedef struct {
    uint32_t seconds;
    uint16_t finetime;
} MissionOBT;

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void (* clock_get_uptime)(const termina__event_t * const termina__ev, TimeVal * const current_time);
    } system_api;
    TimeVal ref_time_val_from_power_on;
    MissionOBT ref_obt;
} COBTManager;

void COBTManager__get_current_obt(const termina__event_t * const termina__ev, void * const termina__this, MissionOBT * const current_obt);

void COBTManager__set_obt(const termina__event_t * const termina__ev, void * const termina__this, MissionOBT next_obt);

#endif
