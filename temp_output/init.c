
#include <termina.h>

#include "app.h"

#include "libraries/pus_services/pus_service3.h"

#include "libraries/tc_ccsds_pus_format.h"

void __termina_app__init_globals() {
    
    hk_timer.period.tv_sec = 1;
    hk_timer.period.tv_usec = 0;

    return;

}
