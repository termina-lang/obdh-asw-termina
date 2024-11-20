#ifndef __APP_H__
#define __APP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service5.h"
#include "service_libraries/pus_services/pus_service9.h"
#include "service_libraries/pus_services/pus_service12.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service19.h"
#include "resources/uart.h"

extern PeriodicTimer hk_fdir_timer;

extern _Atomic uint16_t system_data_pool;

#endif
