
#include <termina.h>

#include "app.h"

#include "resources/system_data_pool.h"

#include "resources/uart.h"

#include "service_libraries/event_list.h"

#include "service_libraries/pus_services/pus_service1/pus_service1.h"

#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

#include "service_libraries/pus_services/pus_service19.h"

#include "service_libraries/pus_services/pus_service2.h"

#include "service_libraries/pus_services/pus_service3.h"

#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

#include "service_libraries/pus_services/pus_service9.h"

#include "service_libraries/queue_u8.h"

#include "service_libraries/tc_ccsds_pus_format.h"

#include "tasks/hk_fdir_mng/hk_fdir.h"

void __termina_app__init_globals() {
    
    for (size_t __i0 = 0; __i0 < sdp_num_params; __i0 = __i0 + 1) {
        system_data_pool.values[__i0] = 0;
    }

    return;

}
