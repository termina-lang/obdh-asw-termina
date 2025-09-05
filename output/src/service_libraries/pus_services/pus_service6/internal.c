
#include "service_libraries/pus_services/pus_service6/internal.h"

const size_t max_num_of_bytes_memory_load = 256U;

const size_t banks_number = 8U;

const size_t bank_size = 1U << 24U;

__status_int32_t build_tm_6_6(TMHandler * const p_tm_handler,
                              uint16_t tm_seq_counter, MissionOBT current_obt,
                              const PS6ExecTCReqStatusUpdate * const mem_data) {
    
    #line 30 "src/service_libraries/pus_services/pus_service6/internal.fin"
    __status_int32_t status;
    #line 30 "src/service_libraries/pus_services/pus_service6/internal.fin"
    status.__variant = Success;

    #line 32 "src/service_libraries/pus_services/pus_service6/internal.fin"
    startup_tm(p_tm_handler);

    #line 33 "src/service_libraries/pus_services/pus_service6/internal.fin"
    status = append_u8_appdata_field(p_tm_handler, mem_data->mem_id);

    #line 34 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 35 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, 1U);

    }

    #line 37 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 38 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, mem_data->address);

    }

    #line 40 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 41 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, mem_data->length);

    }

    #line 43 "src/service_libraries/pus_services/pus_service6/internal.fin"
    for (size_t i = 0U;
         i < 256U - tm_app_data_offset
         && (status.__variant == Success && i < (size_t)mem_data->length);
         i = i + 1U) {
        
        #line 44 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u8_appdata_field(p_tm_handler,
                                         mem_data->data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                               i)]);

    }

    #line 46 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 47 "src/service_libraries/pus_services/pus_service6/internal.fin"
        close_tm(p_tm_handler, 6U, 6U, tm_seq_counter, current_obt);

    }

    #line 50 "src/service_libraries/pus_services/pus_service6/internal.fin"
    return status;

}

__status_int32_t build_tm_6_10(TMHandler * const p_tm_handler,
                               uint16_t tm_seq_counter, MissionOBT current_obt,
                               const PS6ExecTCReqStatusUpdate * const mem_data,
                               uint16_t checksum) {
    
    #line 56 "src/service_libraries/pus_services/pus_service6/internal.fin"
    __status_int32_t status;
    #line 56 "src/service_libraries/pus_services/pus_service6/internal.fin"
    status.__variant = Success;

    #line 57 "src/service_libraries/pus_services/pus_service6/internal.fin"
    startup_tm(p_tm_handler);

    #line 58 "src/service_libraries/pus_services/pus_service6/internal.fin"
    status = append_u8_appdata_field(p_tm_handler, mem_data->mem_id);

    #line 59 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 60 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, 1U);

    }

    #line 62 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 63 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, mem_data->address);

    }

    #line 65 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 66 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, mem_data->length);

    }

    #line 68 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 69 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, checksum);

    }

    #line 71 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status.__variant == Success) {
        
        #line 72 "src/service_libraries/pus_services/pus_service6/internal.fin"
        close_tm(p_tm_handler, 6U, 10U, tm_seq_counter, current_obt);

    }

    #line 75 "src/service_libraries/pus_services/pus_service6/internal.fin"
    return status;

}
