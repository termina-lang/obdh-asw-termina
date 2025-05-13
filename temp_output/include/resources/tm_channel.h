#ifndef __RESOURCES__TM_CHANNEL_H__
#define __RESOURCES__TM_CHANNEL_H__

#include <termina.h>

#include "resources/uart.h"
#include "service_libraries/pus_tm_handler.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* send_tm)(void * const, __termina_box_t, MyResult * const);
} TMChannelIface;

typedef struct {
    __termina_id_t __mutex_id;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send)(void * const, const uint8_t *, size_t,
                      CharDevResult * const);
    } uart;
} TMChannel;

void TMChannel__send_tm(void * const __this, __termina_box_t tm_handler,
                        MyResult * const result);
void TMChannel__send_tm__mutex_lock(void * const __this,
                                    __termina_box_t tm_handler,
                                    MyResult * const result);
void TMChannel__send_tm__task_lock(void * const __this,
                                   __termina_box_t tm_handler,
                                   MyResult * const result);
void TMChannel__send_tm__event_lock(void * const __this,
                                    __termina_box_t tm_handler,
                                    MyResult * const result);

#endif
