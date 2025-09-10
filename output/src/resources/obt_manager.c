
#include "resources/obt_manager.h"

void OBTManager__get_current_obt(const __termina_event_t * const __ev, void * const __this, MissionOBT * const current_obt) {
    
    #line 48 "src/resources/obt_manager.fin"
    OBTManager * self = (OBTManager *)__this;

    #line 48 "src/resources/obt_manager.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 50 "src/resources/obt_manager.fin"
    uint32_t fine_time_increment = 0U;

    #line 51 "src/resources/obt_manager.fin"
    TimeVal time_val_from_power_on;
    #line 51 "src/resources/obt_manager.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 51 "src/resources/obt_manager.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 55 "src/resources/obt_manager.fin"
    self->system_port.clock_get_uptime(__ev, &time_val_from_power_on);

    #line 56 "src/resources/obt_manager.fin"
    TimeVal interval;
    #line 56 "src/resources/obt_manager.fin"
    interval.tv_sec = 0U;
    #line 56 "src/resources/obt_manager.fin"
    interval.tv_usec = 0U;

    #line 61 "src/resources/obt_manager.fin"
    interval = substract_TimeVal(time_val_from_power_on, self->ref_time_val_from_power_on);

    #line 63 "src/resources/obt_manager.fin"
    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    #line 64 "src/resources/obt_manager.fin"
    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    #line 66 "src/resources/obt_manager.fin"
    current_obt->seconds = (uint32_t)(self->ref_obt.seconds + interval.tv_sec) + (uint32_t)(fine_time_increment >> 16U);

    #line 67 "src/resources/obt_manager.fin"
    current_obt->finetime = (uint16_t)(fine_time_increment & 0xFFFFU);

    #line 69 "src/resources/obt_manager.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 69 "src/resources/obt_manager.fin"
    return;

}

void OBTManager__set_obt(const __termina_event_t * const __ev, void * const __this, MissionOBT next_obt) {
    
    #line 30 "src/resources/obt_manager.fin"
    OBTManager * self = (OBTManager *)__this;

    #line 30 "src/resources/obt_manager.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 32 "src/resources/obt_manager.fin"
    self->ref_obt = next_obt;

    #line 33 "src/resources/obt_manager.fin"
    self->system_port.clock_get_uptime(__ev, &self->ref_time_val_from_power_on);

    #line 35 "src/resources/obt_manager.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 35 "src/resources/obt_manager.fin"
    return;

}
