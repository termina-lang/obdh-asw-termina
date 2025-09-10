
#include "service_libraries/pus_services/pus_service17/internal.h"

void build_tm_17_2(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt) {
    
    #line 36 "src/service_libraries/pus_services/pus_service17/internal.fin"
    startup_tm(p_tm_handler);

    #line 37 "src/service_libraries/pus_services/pus_service17/internal.fin"
    close_tm(p_tm_handler, 17U, 2U, tm_seq_counter, current_obt);

    #line 38 "src/service_libraries/pus_services/pus_service17/internal.fin"
    return;

}
