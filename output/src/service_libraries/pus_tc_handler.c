
#include "service_libraries/pus_tc_handler.h"

void tc_handler_build(TCHandler * const tc_handler) {
    
    #line 55 "src/service_libraries/pus_tc_handler.fin"
    tc_get_fields(tc_handler->tc_descriptor.tc_bytes, &tc_handler->packet_header, &tc_handler->df_header, &tc_handler->packet_error_ctrl);

    #line 60 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->app_data_index = 11U;

    #line 62 "src/service_libraries/pus_tc_handler.fin"
    return;

}

_Bool tc_handler_is_valid_next_appdata_field(const TCHandler * const tc_handler, size_t field_size) {
    
    #line 76 "src/service_libraries/pus_tc_handler.fin"
    _Bool res = 0;

    #line 78 "src/service_libraries/pus_tc_handler.fin"
    size_t required_size = tc_handler->app_data_index + field_size;

    #line 80 "src/service_libraries/pus_tc_handler.fin"
    if (required_size <= tc_handler->tc_descriptor.tc_num_bytes) {
        
        #line 81 "src/service_libraries/pus_tc_handler.fin"
        res = 1;

    }

    #line 84 "src/service_libraries/pus_tc_handler.fin"
    return res;

}

__status_int32_t tc_handler_get_u8_appdata_field(TCHandler * const tc_handler, uint8_t * const data) {
    
    #line 101 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 101 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 103 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 1U)) {
        
        #line 105 "src/service_libraries/pus_tc_handler.fin"
        *data = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U, tc_handler->app_data_index)];

        #line 106 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 1U;

    } else
    {
        
        #line 110 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 110 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 114 "src/service_libraries/pus_tc_handler.fin"
    return status;

}

__status_int32_t tc_handler_get_u16_appdata_field(TCHandler * const tc_handler, uint16_t * const data) {
    
    #line 130 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 130 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 132 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 2U)) {
        
        #line 134 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint16(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U, 2U, tc_handler->app_data_index, tc_handler->app_data_index + 2U)]);

        #line 135 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 2U;

    } else
    {
        
        #line 139 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 139 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 143 "src/service_libraries/pus_tc_handler.fin"
    return status;

}

__status_int32_t tc_handler_get_u32_appdata_field(TCHandler * const tc_handler, uint32_t * const data) {
    
    #line 159 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 159 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 161 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 4U)) {
        
        #line 163 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint32(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U, 4U, tc_handler->app_data_index, tc_handler->app_data_index + 4U)]);

        #line 164 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 4U;

    } else
    {
        
        #line 168 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 168 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 172 "src/service_libraries/pus_tc_handler.fin"
    return status;

}
