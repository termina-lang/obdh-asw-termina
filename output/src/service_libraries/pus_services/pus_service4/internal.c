
#include "service_libraries/pus_services/pus_service4/internal.h"

Status__i32 build_tm_4_2(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, size_t stats_index, uint8_t N, const StatsConfig * const stats_config_table, const StatsDef param_stats[4U], MissionOBT current_obt) {
    
    #line 55 "src/service_libraries/pus_services/pus_service4/internal.fin"
    startup_tm(p_tm_handler);

    #line 57 "src/service_libraries/pus_services/pus_service4/internal.fin"
    Status__i32 status = append_u32_appdata_field(p_tm_handler, stats_config_table->start_time[termina__check__array_index(4U, stats_index)].seconds);

    #line 58 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 59 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, current_obt.seconds);

    }

    #line 61 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 62 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, N);

    }

    #line 64 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 65 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, stats_config_table->PID[termina__check__array_index(4U, stats_index)]);

    }

    #line 67 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 68 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, param_stats[termina__check__array_index(4U, stats_index)].samples);

    }

    #line 70 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 71 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, param_stats[termina__check__array_index(4U, stats_index)].max);

    }

    #line 73 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 74 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, param_stats[termina__check__array_index(4U, stats_index)].max_obt.seconds);

    }

    #line 76 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 77 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, param_stats[termina__check__array_index(4U, stats_index)].min);

    }

    #line 79 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 80 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, param_stats[termina__check__array_index(4U, stats_index)].min_obt.seconds);

    }

    #line 82 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 83 "src/service_libraries/pus_services/pus_service4/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, param_stats[termina__check__array_index(4U, stats_index)].mean_value);

    }

    #line 86 "src/service_libraries/pus_services/pus_service4/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 87 "src/service_libraries/pus_services/pus_service4/internal.fin"
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    #line 90 "src/service_libraries/pus_services/pus_service4/internal.fin"
    return status;

}
