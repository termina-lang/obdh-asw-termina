#ifndef __TASKS__TC_RX_H__
#define __TASKS__TC_RX_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/pus_tc_handler.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef enum {
    RXStatus__SyncBytesRx,
    RXStatus__SyncLengthRx,
    RXStatus__TCBytesRx
} __enum_RXStatus_t;

typedef struct {
    __enum_RXStatus_t __variant;
} RXStatus;

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    __termina_allocator_t a_tc_handler_pool;
    __termina_out_port_t tc_message_queue_output;
    __termina_id_t byte_message_queue_input;
    TCDescriptorT telecommand;
    uint8_t RX_tc_length[2U];
    size_t aux_index;
    uint8_t sync_word[4U];
    RXStatus rx_status;
} TCRXBottomHalfTask;

void __TCRXBottomHalfTask__termina_task(void * const arg);

__status_int32_t TCRXBottomHalfTask__get_tc(void * const __this, uint8_t data);

#endif
