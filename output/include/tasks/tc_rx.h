#ifndef TASKS__TC_RX_H__
#define TASKS__TC_RX_H__

#include <termina.h>

#include "resources/tc_channel.h"
#include "service_libraries/errors.h"
#include "service_libraries/pus_tc_handler.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    termina__id_t _task_id;
    termina__id_t _task_msg_queue_id;
    termina__allocator_t tc_handler_pool;
    termina__out_port_t tc_message_queue_output;
    termina__id_t frame_ready_input;
    struct {
        void * _that;
        void (* dequeue)(const termina__event_t * const termina__ev, void * const termina__this, Option__u8 * const byte);
    } tc_channel;
} CTXRxBottomHalfTask;

void termina__task_entry__CTXRxBottomHalfTask(void * const arg);

Status__i32 CTXRxBottomHalfTask__get_tc(const termina__event_t * const termina__ev, void * const termina__this, size_t size);

#endif
