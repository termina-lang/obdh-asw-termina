
#include "service_libraries/pus_services/pus_service4/pus_service4_help.h"

__status_int32_t build_tm_4_2(TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter, size_t index, uint8_t N,
                              const StatsConfig * const stats_config_table,
                              const StatsDef param_stats[4U],
                              MissionObt current_obt) {
    
    __status_int32_t status;
    status.__variant = Success;

    startup_tm(p_tm_handler);

    status = append_u32_appdata_field(p_tm_handler,
                                      stats_config_table->start_time[__termina_array__index(4U,
                                                                                            index)].seconds);

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler, current_obt.seconds);

    }

    if (status.__variant == Success) {
        
        status = append_u8_appdata_field(p_tm_handler, N);

    }

    if (status.__variant == Success) {
        
        status = append_u16_appdata_field(p_tm_handler,
                                          stats_config_table->PID[__termina_array__index(4U,
                                                                                         index)]);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].samples);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].max);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].max_obt.seconds);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].min);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].min_obt.seconds);

    }

    if (status.__variant == Success) {
        
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].mean_value);

    }

    if (status.__variant == Success) {
        
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    return status;

}
