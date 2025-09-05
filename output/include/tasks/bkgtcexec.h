#ifndef __TASKS__BKGTCEXEC_H__
#define __TASKS__BKGTCEXEC_H__

#include <termina.h>

#include "resources/system_data_pool.h"
#include "resources/tm_counter.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service20.h"
#include "service_libraries/pus_services/pus_service6.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    struct {
        void * __that;
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const,
                                                 void * const, uint16_t,
                                                 uint16_t,
                                                 __status_int32_t * const);
    } pus_service_1;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const,
                         TCHandler * const, __status_int32_t * const);
    } pus_service_6;
    struct {
        void * __that;
        void (* exec_tc)(const __termina_event_t * const, void * const,
                         TCHandler * const, __status_int32_t * const);
    } pus_service_20;
    __termina_allocator_t a_tc_handler_pool;
    __termina_id_t bkg_message_queue_input;
} PUSBKGTCExecutor;

void __PUSBKGTCExecutor__termina_task(void * const arg);

__status_int32_t PUSBKGTCExecutor__exec_tc(const __termina_event_t * const __ev,
                                           void * const __this,
                                           __termina_box_t tc_handler);

#endif
