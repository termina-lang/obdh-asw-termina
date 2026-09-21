#ifndef TASKS__BKGTCEXEC_H__
#define TASKS__BKGTCEXEC_H__

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
    termina__id_t _task_id;
    termina__id_t _task_msg_queue_id;
    struct {
        void * _that;
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
    } pus_service_1;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
    } pus_service_6;
    struct {
        void * _that;
        void (* exec_tc)(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);
    } pus_service_20;
    termina__allocator_t tc_handler_pool;
    termina__id_t bkg_message_queue_input;
} CBKGTCExecutorTask;

void termina__task_entry__CBKGTCExecutorTask(void * const arg);

Status__i32 CBKGTCExecutorTask__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, termina__box_t tc_handler);

#endif
