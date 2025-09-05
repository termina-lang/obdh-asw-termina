#ifndef __TASKS__TC_RX_H__
#define __TASKS__TC_RX_H__

#include <termina.h>

#include "resources/uart.h"
#include "service_libraries/errors.h"
#include "service_libraries/pus_tc_handler.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    __termina_allocator_t a_tc_handler_pool;
    __termina_out_port_t tc_message_queue_output;
    __termina_id_t rx_frame;
    struct {
        void * __that;
        void (* receive)(const __termina_event_t * const, void * const,
                         __option_uint8_t * const);
    } uart;
    TCDescriptor telecommand;
} TCRXBottomHalfTask;

void __TCRXBottomHalfTask__termina_task(void * const arg);

__status_int32_t TCRXBottomHalfTask__get_tc(const __termina_event_t * const __ev,
                                            void * const __this,
                                            size_t frame_size);

#endif
