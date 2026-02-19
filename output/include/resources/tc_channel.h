#ifndef __RESOURCES__TC_CHANNEL_H__
#define __RESOURCES__TC_CHANNEL_H__

#include <termina.h>

#include "drivers/char_dev.h"
#include "service_libraries/errors.h"
#include "service_libraries/queue_u8.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"
#include "result.h"

typedef enum {
    TCRxStatus__SyncBytesRx,
    TCRxStatus__SyncLengthRx,
    TCRxStatus__TCBytesRx,
    TCRxStatus__FinishedTCRx
} __enum_TCRxStatus_t;

typedef struct {
    __enum_TCRxStatus_t __variant;
} TCRxStatus;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    QueueU8 tc_rx_queue;
    TCRxStatus rx_status;
    size_t tc_num_bytes;
    uint8_t raw_rx_tc_length[2U];
    size_t aux_index;
    uint8_t sync_word[4U];
} CTCChannel;

void CTCChannel__enqueue_rx(const __termina_event_t * const __ev, void * const __this, uint8_t byte, __result_bool__int32_t * const result);

void CTCChannel__receive_tc(const __termina_event_t * const __ev, void * const __this, TCDescriptor * const tc_descriptor, __status_int32_t * const status);

#endif
