#ifndef __APP_H__
#define __APP_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"
#include "service_libraries/pus_services/pus_service9.h"
#include "service_libraries/pus_services/pus_service12/pus_service12.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service19.h"
#include "service_libraries/pus_services/pus_service20.h"
#include "resources/uart.h"
#include "tasks/hk_fdir_mng/hk_fdir.h"
#include "tasks/hk_fdir_mng/tc_executor.h"
#include "tasks/bkgtcexec.h"

extern _Atomic uint16_t system_data_pool[sdp_num_params];

#endif
