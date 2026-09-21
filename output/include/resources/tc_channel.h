#ifndef RESOURCES__TC_CHANNEL_H__
#define RESOURCES__TC_CHANNEL_H__

#include <termina.h>

#include "drivers/char_dev.h"
#include "service_libraries/errors.h"
#include "service_libraries/queue_u8.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef enum {
    TCRxStatus__SyncBytesRx,
    TCRxStatus__SyncLengthRx,
    TCRxStatus__TCBytesRx,
    TCRxStatus__FinishedTCRx
} termina__enum__TCRxStatus_t;

typedef struct {
    termina__enum__TCRxStatus_t _variant;
} TCRxStatus;

typedef struct {
    termina__resource_lock_type_t _lock_type;
    QueueU8 tc_rx_queue;
    TCRxStatus rx_status;
    size_t tc_num_bytes;
    uint8_t raw_rx_tc_length[2U];
    size_t aux_index;
    uint8_t sync_word[4U];
} CTCChannel;

void CTCChannel__dequeue(const termina__event_t * const termina__ev, void * const termina__this, Option__u8 * const obyte);

void CTCChannel__enqueue(const termina__event_t * const termina__ev, void * const termina__this, const uint8_t byte, CharDevIrqStatus * const status);

#endif
