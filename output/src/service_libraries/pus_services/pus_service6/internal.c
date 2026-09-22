
#include "service_libraries/pus_services/pus_service6/internal.h"

const size_t max_num_of_bytes_memory_load = 256U;

const size_t banks_number = 8U;

const size_t bank_size = 16777216U;

Status__i32 build_tm_6_6(TMHandler * const p_tm_handler, const uint16_t tm_seq_counter, const MissionOBT current_obt, const PS6ExecTCReqStatusUpdate * const mem_data) {
    
    #line 30 "src/service_libraries/pus_services/pus_service6/internal.fin"
    startup_tm(p_tm_handler);

    #line 31 "src/service_libraries/pus_services/pus_service6/internal.fin"
    Status__i32 status = append_u8_appdata_field(p_tm_handler, mem_data->mem_id);

    #line 32 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 33 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, 1U);

    }

    #line 35 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 36 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, mem_data->address);

    }

    #line 38 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 39 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, mem_data->length);

    }

    #line 41 "src/service_libraries/pus_services/pus_service6/internal.fin"
    for (size_t i = 0U; i < 256U - tm_app_data_offset && (status._variant == Status__Success && i < (size_t)mem_data->length); i = i + 1U) {
        
        #line 42 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, mem_data->data[termina__check__array_index(256U, i)]);

    }

    #line 44 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 45 "src/service_libraries/pus_services/pus_service6/internal.fin"
        close_tm(p_tm_handler, 6U, 6U, tm_seq_counter, current_obt);

    }

    #line 48 "src/service_libraries/pus_services/pus_service6/internal.fin"
    return status;

}

Status__i32 build_tm_6_10(TMHandler * const p_tm_handler, const uint16_t tm_seq_counter, const MissionOBT current_obt, const PS6ExecTCReqStatusUpdate * const mem_data, const uint16_t checksum) {
    
    #line 54 "src/service_libraries/pus_services/pus_service6/internal.fin"
    startup_tm(p_tm_handler);

    #line 55 "src/service_libraries/pus_services/pus_service6/internal.fin"
    Status__i32 status = append_u8_appdata_field(p_tm_handler, mem_data->mem_id);

    #line 56 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 57 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u8_appdata_field(p_tm_handler, 1U);

    }

    #line 59 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 60 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u32_appdata_field(p_tm_handler, mem_data->address);

    }

    #line 62 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 63 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, mem_data->length);

    }

    #line 65 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 66 "src/service_libraries/pus_services/pus_service6/internal.fin"
        status = append_u16_appdata_field(p_tm_handler, checksum);

    }

    #line 68 "src/service_libraries/pus_services/pus_service6/internal.fin"
    if (status._variant == Status__Success) {
        
        #line 69 "src/service_libraries/pus_services/pus_service6/internal.fin"
        close_tm(p_tm_handler, 6U, 10U, tm_seq_counter, current_obt);

    }

    #line 72 "src/service_libraries/pus_services/pus_service6/internal.fin"
    return status;

}
