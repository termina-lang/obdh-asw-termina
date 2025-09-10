
#include "service_libraries/pus_tc_handler.h"

void tc_handler_build_from_descriptor(TCHandler * const tc_handler, const TCDescriptor * const telecommand) {
    
    #line 56 "src/service_libraries/pus_tc_handler.fin"
    for (size_t i = 0U; i < 256U && i < telecommand->tc_num_bytes; i = i + 1U) {
        
        #line 57 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U, i)] = telecommand->tc_bytes[__termina_array__index(256U, i)];

    }

    #line 59 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->tc_descriptor.tc_num_bytes = telecommand->tc_num_bytes;

    #line 61 "src/service_libraries/pus_tc_handler.fin"
    tc_get_fields(telecommand->tc_bytes, &tc_handler->packet_header, &tc_handler->df_header, &tc_handler->packet_error_ctrl);

    #line 63 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->app_data_index = 11U;

    #line 65 "src/service_libraries/pus_tc_handler.fin"
    return;

}

_Bool tc_handler_is_valid_next_appdata_field(const TCHandler * const tc_handler, size_t field_size) {
    
    #line 79 "src/service_libraries/pus_tc_handler.fin"
    _Bool res = 0;

    #line 81 "src/service_libraries/pus_tc_handler.fin"
    size_t required_size = tc_handler->app_data_index + field_size;

    #line 83 "src/service_libraries/pus_tc_handler.fin"
    if (required_size <= tc_handler->tc_descriptor.tc_num_bytes) {
        
        #line 84 "src/service_libraries/pus_tc_handler.fin"
        res = 1;

    }

    #line 87 "src/service_libraries/pus_tc_handler.fin"
    return res;

}

__status_int32_t tc_handler_get_u8_appdata_field(TCHandler * const tc_handler, uint8_t * const data) {
    
    #line 104 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 104 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 106 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 1U)) {
        
        #line 108 "src/service_libraries/pus_tc_handler.fin"
        *data = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U, tc_handler->app_data_index)];

        #line 109 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 1U;

    } else
    {
        
        #line 113 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 113 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 117 "src/service_libraries/pus_tc_handler.fin"
    return status;

}

__status_int32_t tc_handler_get_u16_appdata_field(TCHandler * const tc_handler, uint16_t * const data) {
    
    #line 133 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 133 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 135 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 2U)) {
        
        #line 137 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint16(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U, 2U, tc_handler->app_data_index, tc_handler->app_data_index + 2U)]);

        #line 138 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 2U;

    } else
    {
        
        #line 142 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 142 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 146 "src/service_libraries/pus_tc_handler.fin"
    return status;

}

__status_int32_t tc_handler_get_u32_appdata_field(TCHandler * const tc_handler, uint32_t * const data) {
    
    #line 162 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 162 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 164 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 4U)) {
        
        #line 166 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint32(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U, 4U, tc_handler->app_data_index, tc_handler->app_data_index + 4U)]);

        #line 167 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 4U;

    } else
    {
        
        #line 171 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 171 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 175 "src/service_libraries/pus_tc_handler.fin"
    return status;

}
