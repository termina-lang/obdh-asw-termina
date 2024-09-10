
#include <termina.h>

#include "app.h"

#include "libraries/event_list.h"

#include "libraries/pus_services/pus_service1.h"

#include "libraries/pus_services/pus_service12.h"

#include "libraries/pus_services/pus_service128.h"

#include "libraries/pus_services/pus_service19.h"

#include "libraries/pus_services/pus_service2.h"

#include "libraries/pus_services/pus_service3.h"

#include "libraries/pus_services/pus_service5.h"

#include "libraries/pus_services/pus_service9.h"

#include "libraries/queue_u8.h"

#include "libraries/tc_ccsds_pus_format.h"

#include "resources/system_data_pool.h"

#include "resources/uart.h"

void __termina_app__init_globals() {
    
    hk_fdir_timer.period.tv_sec = 1;
    hk_fdir_timer.period.tv_usec = 0;
    uart_drv.registers = (volatile UARTRegs *)0xFC001000;
    uart_drv.rem_bytes = 0;
    for (size_t __i0 = 0; __i0 < queue_max_noe; __i0 = __i0 + 1) {
        uart_drv.uart_queue.elements[__i0] = 0;
    }
    uart_drv.uart_queue.head_index = 0;
    uart_drv.uart_queue.num_elements = 0;
    init.system_data_pool = system_data_pool;
    init.uart.__that = &uart_drv;
    init.uart.initialize = UARTDriver__initialize;

    return;

}
