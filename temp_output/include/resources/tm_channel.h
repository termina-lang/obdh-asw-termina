#ifndef __RESOURCES__TM_CHANNEL_H__
#define __RESOURCES__TM_CHANNEL_H__

#include <termina.h>

#include "option.h"
#include "resources/uart.h"
#include "service_libraries/tm_ccsds_pus_format.h"

typedef struct {
    void * __that;
    void (* send_tm)(void * const, __termina_box_t, Result * const);
} TMChannelIface;

typedef struct {
    __termina_resource_t __resource;
    __termina_pool_t * a_tm_descriptor_pool;
    CharDevSend uart;
} TMChannel;

void TMChannel__send_tm(void * const __this, __termina_box_t tm_descriptor,
                        Result * const result);

#endif
