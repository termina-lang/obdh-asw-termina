#ifndef __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__
#define __TASKS__ICU_MANAGER__MNG_TC_EXECUTOR_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service9.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service128.h"
#include "resources/tm_counter.h"
#include "resources/tm_channel.h"

typedef struct {
    void * __that;
    void (* PUS_prio_exec_tc)(void * const, const TCDescriptorT * const,
                              Result * const);
    void (* mng_tc_acceptation)(void * const, const TCDescriptorT * const,
                                Result * const);
    void (* mng_tc_rejection)(void * const, const TCDescriptorT * const,
                              Result * const);
} MngTCExecIface;

typedef struct {
    __termina_resource_t __resource;
    PUSS17Iface pus_service_17;
    __termina_pool_t * a_tm_descriptor_pool;
    TMCounterIface tm_counter;
    TMChannelIface tm_channel;
} ManagerTCExecutor;

void ManagerTCExecutor__PUS_prio_exec_tc(void * const __this,
                                         const TCDescriptorT * const prio_tc,
                                         Result * const ret);

void ManagerTCExecutor__mng_tc_acceptation(void * const __this,
                                           const TCDescriptorT * const tc_descriptor,
                                           Result * const ret);

void ManagerTCExecutor__mng_tc_rejection(void * const __this,
                                         const TCDescriptorT * const tc_descriptor,
                                         Result * const ret);

#endif
