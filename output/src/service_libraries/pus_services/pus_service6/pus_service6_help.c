
#include "service_libraries/pus_services/pus_service6/pus_service6_help.h"

const size_t max_num_of_bytes_memory_load = 256U;

const size_t banks_number = 8U;

const size_t bank_size = 16384U;

__status_int32_t build_tm_6_6(TMHandlerT * const p_tm_handler,
                              uint16_t tm_seq_counter, MissionObt current_obt,
                              const PS6ExecTCReqStatusUpdate * const mem_data) {
    
    #line 29 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    __status_int32_t status;
    #line 29 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    status.__variant = Success;

    #line 31 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    startup_tm(p_tm_handler);

    #line 32 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    status = append_u8_appdata_field(p_tm_handler, mem_data->mem_id);

    #line 33 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 34 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u8_appdata_field(p_tm_handler, 1U);

    }

    #line 36 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 37 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u32_appdata_field(p_tm_handler, mem_data->address);

    }

    #line 39 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 40 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u16_appdata_field(p_tm_handler, mem_data->length);

    }

    #line 42 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    for (size_t i = 0U;
         i < 256U - tm_app_data_offset
         && (status.__variant == Success && i < (size_t)mem_data->length);
         i = i + 1U) {
        
        #line 43 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u8_appdata_field(p_tm_handler,
                                         mem_data->data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                               i)]);

    }

    #line 45 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 46 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        close_tm(p_tm_handler, 6U, 6U, tm_seq_counter, current_obt);

    }

    #line 49 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    return status;

}

__status_int32_t build_tm_6_10(TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, MissionObt current_obt,
                               const PS6ExecTCReqStatusUpdate * const mem_data,
                               uint16_t checksum) {
    
    #line 55 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    __status_int32_t status;
    #line 55 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    status.__variant = Success;

    #line 56 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    startup_tm(p_tm_handler);

    #line 57 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    status = append_u8_appdata_field(p_tm_handler, mem_data->mem_id);

    #line 58 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 59 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u8_appdata_field(p_tm_handler, 1U);

    }

    #line 61 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 62 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u32_appdata_field(p_tm_handler, mem_data->address);

    }

    #line 64 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 65 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u16_appdata_field(p_tm_handler, mem_data->length);

    }

    #line 67 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 68 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        status = append_u16_appdata_field(p_tm_handler, checksum);

    }

    #line 70 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    if (status.__variant == Success) {
        
        #line 71 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
        close_tm(p_tm_handler, 6U, 10U, tm_seq_counter, current_obt);

    }

    #line 74 "src/service_libraries/pus_services/pus_service6/pus_service6_help.fin"
    return status;

}
