
#include "service_libraries/pus_services/pus_service4/pus_service4_help.h"

__status_int32_t build_tm_4_2(TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter, size_t index, uint8_t N,
                              const StatsConfig * const stats_config_table,
                              const StatsDef param_stats[4U],
                              MissionObt current_obt) {
    
    #line 57 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    __status_int32_t status;
    #line 57 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    status.__variant = Success;

    #line 58 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    startup_tm(p_tm_handler);

    #line 60 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    status = append_u32_appdata_field(p_tm_handler,
                                      stats_config_table->start_time[__termina_array__index(4U,
                                                                                            index)].seconds);

    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 62 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler, current_obt.seconds);

    }

    #line 64 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 65 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u8_appdata_field(p_tm_handler, N);

    }

    #line 67 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 68 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u16_appdata_field(p_tm_handler,
                                          stats_config_table->PID[__termina_array__index(4U,
                                                                                         index)]);

    }

    #line 70 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 71 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].samples);

    }

    #line 73 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 74 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].max);

    }

    #line 76 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 77 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].max_obt.seconds);

    }

    #line 79 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 80 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].min);

    }

    #line 82 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 83 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].min_obt.seconds);

    }

    #line 85 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 86 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        status = append_u32_appdata_field(p_tm_handler,
                                          param_stats[__termina_array__index(4U,
                                                                             index)].mean_value);

    }

    #line 89 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    if (status.__variant == Success) {
        
        #line 90 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    #line 93 "src/service_libraries/pus_services/pus_service4/pus_service4_help.fin"
    return status;

}
