
#include "service_libraries/pus_services/pus_service4/internal.h"

__status_int32_t build_tm_4_2(TMHandler * const p_tm_handler,
                              uint16_t tm_seq_counter, size_t index, uint8_t N,
                              const StatsConfig * const stats_config_table,
                              const StatsDef param_stats[4U],
                              MissionOBT current_obt) {
    
    #line 55 "src/service_libraries/pus_services/pus_service4/internal.fin"
    __status_int32_t status;
    #line 55 "src/service_libraries/pus_services/pus_service4/internal.fin"
    status.__variant = Success;

    #line 56 "src/service_libraries/pus_services/pus_service4/internal.fin"
    startup_tm(p_tm_handler);

    #line 58 "src/service_libraries/pus_services/pus_service4/internal.fin"
    status = append_u32_appdata_field(p_tm_handler,
                                      stats_config_table->start_time[__termina_array__index(4U,
                                                                                            index)].seconds);

    #line 59 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 60 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, current_obt.seconds);

    }

    #line 62 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 63 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, N);

    }

    #line 65 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 66 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u16_appdata_field(p_tm_handler,
                                          stats_config_table->PID[__termina_array__index(4U,
                                                                                         index)]);

    }

    #line 68 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 69 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].samples);

    }

    #line 71 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 72 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].max);

    }

    #line 74 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 75 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].max_obt.seconds);

    }

    #line 77 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 78 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].min);

    }

    #line 80 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 81 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].min_obt.seconds);

    }

    #line 83 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 84 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].mean_value);

    }

    #line 87 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status.__variant == Success) {
        
        #line 88 "src/service_libraries/pus_services/pus_service4/internal.fin"
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    #line 91 "src/service_libraries/pus_services/pus_service4/internal.fin"
    return status;

}
