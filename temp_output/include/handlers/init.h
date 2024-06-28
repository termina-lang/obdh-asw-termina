#ifndef __HANDLERS__INIT_H__
#define __HANDLERS__INIT_H__

#include <termina.h>

#include "option.h"
#include "resources/uart.h"

#define SDP_num_params 64

typedef struct {
    _Atomic uint16_t * system_data_pool;
    CharDevInit uart;
} Init;

Result Init__init(Init * const self, TimeVal _boot_time);

#endif
