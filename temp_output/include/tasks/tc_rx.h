#ifndef __TASKS__TC_RX_H__
#define __TASKS__TC_RX_H__

#include <termina.h>
#include "libraries/tc_ccsds_pus_format.h"
#include "libraries/serialize.h"

typedef enum {
    RXStatus__SyncBytesRx,
    RXStatus__SyncLengthRx,
    RXStatus__TCBytesRx
} __enum_RXStatus_t;

typedef struct {
    __enum_RXStatus_t __variant;
} RXStatus;

typedef struct {
    __termina_task_t __task;
    __termina_pool_t * a_tc_descriptor_pool;
    __termina_out_port_t tc_message_queue_output;
    __termina_in_port_t byte_message_queue_input;
    TCDescriptorT telecommand;
    uint8_t RX_tc_length[2];
    size_t aux_index;
    uint8_t sync_word[4];
    RXStatus rx_status;
} TCRXBottomHalfTask;

Result TCRXBottomHalfTask__get_tc(TCRXBottomHalfTask * const self,
                                  uint8_t data);

#endif
