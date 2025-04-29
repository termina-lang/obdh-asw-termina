#ifndef __TASKS__BKGTCEXEC_H__
#define __TASKS__BKGTCEXEC_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service20/pus_service20.h"
#include "service_libraries/serialize.h"
#include "resources/system_data_pool.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "resources/tm_counter.h"

typedef struct {
    __termina_id_t __task_msg_queue_id;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const, Result * const);
    } pus_service_20;
    __termina_allocator_t a_tc_handler_pool;
    __termina_id_t bkg_message_queue_input;
} PUSBKGTCExecutor;

void __PUSBKGTCExecutor__termina_task(void * const arg);

Result PUSBKGTCExecutor__exec_tc(void * const __this,
                                 __termina_box_t tc_handler);

#endif
