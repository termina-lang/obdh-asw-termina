#ifndef __TASKS__BKGTCEXEC_H__
#define __TASKS__BKGTCEXEC_H__

#include <termina.h>

#include "resources/system_data_pool.h"
#include "resources/tm_counter.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service20/pus_service20.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
    struct {
        void * __that;
        void (* get_current_obt)(void * const, MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const,
                         __status_int32_t * const);
    } pus_service_20;
    __termina_allocator_t a_tc_handler_pool;
    __termina_id_t bkg_message_queue_input;
} PUSBKGTCExecutor;

void __PUSBKGTCExecutor__termina_task(void * const arg);

void PUSBKGTCExecutor__manage_error_in_acceptance(const PUSBKGTCExecutor * const self,
                                                  const TCHandlerT * const tc_handler,
                                                  __status_int32_t * const ret);

__status_int32_t PUSBKGTCExecutor__exec_tc(void * const __this,
                                           __termina_box_t tc_handler);

#endif
