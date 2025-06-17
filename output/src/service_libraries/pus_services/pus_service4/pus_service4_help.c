
#include "service_libraries/pus_services/pus_service4/pus_service4_help.h"

void build_tm_4_2(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                  size_t index, uint8_t N,
                  const StatsConfig * const stats_config_table,
                  const StatsDef param_stats[4U], MissionObt current_obt,
                  __status_int32_t * const status) {
    
    startup_tm(p_tm_handler);

    append_u32_appdata_field(p_tm_handler,
                             stats_config_table->start_time[__termina_array__index(4U,
                                                                                   index)].seconds,
                             status);

    append_u32_appdata_field(p_tm_handler, current_obt.seconds, status);

    append_u8_appdata_field(p_tm_handler, N, status);

    append_u16_appdata_field(p_tm_handler,
                             stats_config_table->PID[__termina_array__index(4U,
                                                                            index)],
                             status);

    append_u32_appdata_field(p_tm_handler,
                             param_stats[__termina_array__index(4U,
                                                                index)].samples,
                             status);

    append_u32_appdata_field(p_tm_handler,
                             param_stats[__termina_array__index(4U, index)].max,
                             status);

    append_u32_appdata_field(p_tm_handler,
                             param_stats[__termina_array__index(4U,
                                                                index)].max_obt.seconds,
                             status);

    append_u32_appdata_field(p_tm_handler,
                             param_stats[__termina_array__index(4U, index)].min,
                             status);

    append_u32_appdata_field(p_tm_handler,
                             param_stats[__termina_array__index(4U,
                                                                index)].min_obt.seconds,
                             status);

    append_u32_appdata_field(p_tm_handler,
                             param_stats[__termina_array__index(4U,
                                                                index)].mean_value,
                             status);

    if ((*status).__variant == Success) {
        
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    return;

}
