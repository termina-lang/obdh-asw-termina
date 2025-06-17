
#include "service_libraries/pus_services/pus_service17/pus_service17_help.h"

void build_tm_17_2(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                   MissionObt current_obt) {
    
    startup_tm(p_tm_handler);

    close_tm(p_tm_handler, 17U, 2U, tm_seq_counter, current_obt);

    return;

}
