#ifndef __RESOURCES__OBT_MANAGER_H__
#define __RESOURCES__OBT_MANAGER_H__

#include <termina.h>

#include "service_libraries/timeval.h"

#include "option.h"

typedef struct {
    uint32_t seconds;
    uint16_t finetime;
} MissionOBT;

typedef struct {
    void * __that;
    void (* get_current_obt)(void * const, MissionOBT * const);
    void (* set_obt)(void * const, MissionOBT);
} OBTManagerIface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void (* clock_get_uptime)(const __termina_event_t * const,
                                  TimeVal * const);
    } system_port;
    TimeVal ref_time_val_from_power_on;
    MissionOBT ref_obt;
} OBTManager;

void OBTManager__get_current_obt(const __termina_event_t * const __ev,
                                 void * const __this,
                                 MissionOBT * const current_obt);

void OBTManager__set_obt(const __termina_event_t * const __ev,
                         void * const __this, MissionOBT next_obt);

#endif
