
#include "service_libraries/pus_tc_handler.h"

void tc_handler_build_from_descriptor(TCHandlerT * const tc_handler,
                                      const TCDescriptorT * const telecommand) {
    
    #line 41 "src/service_libraries/pus_tc_handler.fin"
    for (size_t i = 0U; i < 256U && i < telecommand->tc_num_bytes; i = i + 1U) {
        
        #line 42 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                  i)] = telecommand->tc_bytes[__termina_array__index(256U,
                                                                                                                     i)];

    }

    #line 44 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->tc_descriptor.tc_num_bytes = telecommand->tc_num_bytes;

    #line 46 "src/service_libraries/pus_tc_handler.fin"
    tc_get_fields(telecommand->tc_bytes, &tc_handler->packet_header,
                  &tc_handler->df_header, &tc_handler->packet_error_ctrl);

    #line 48 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->app_data_index = 11U;

    #line 50 "src/service_libraries/pus_tc_handler.fin"
    return;

}

_Bool tc_handler_is_valid_next_appdata_field(const TCHandlerT * const tc_handler,
                                             size_t field_size) {
    
    #line 64 "src/service_libraries/pus_tc_handler.fin"
    _Bool res = 0;

    #line 66 "src/service_libraries/pus_tc_handler.fin"
    size_t required_size = tc_handler->app_data_index + field_size;

    #line 68 "src/service_libraries/pus_tc_handler.fin"
    if (required_size <= tc_handler->tc_descriptor.tc_num_bytes) {
        
        #line 70 "src/service_libraries/pus_tc_handler.fin"
        res = 1;

    }

    #line 74 "src/service_libraries/pus_tc_handler.fin"
    return res;

}

__status_int32_t tc_handler_get_u8_appdata_field(TCHandlerT * const tc_handler,
                                                 uint8_t * const data) {
    
    #line 91 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 91 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 93 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 1U)) {
        
        #line 95 "src/service_libraries/pus_tc_handler.fin"
        *data = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                          tc_handler->app_data_index)];

        #line 96 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 1U;

    } else
    {
        
        #line 100 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 100 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 104 "src/service_libraries/pus_tc_handler.fin"
    return status;

}

__status_int32_t tc_handler_get_u16_appdata_field(TCHandlerT * const tc_handler,
                                                  uint16_t * const data) {
    
    #line 120 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 120 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 122 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 2U)) {
        
        #line 124 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint16(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              2U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 2U)]);

        #line 125 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 2U;

    } else
    {
        
        #line 129 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 129 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 133 "src/service_libraries/pus_tc_handler.fin"
    return status;

}

__status_int32_t tc_handler_get_u32_appdata_field(TCHandlerT * const tc_handler,
                                                  uint32_t * const data) {
    
    #line 149 "src/service_libraries/pus_tc_handler.fin"
    __status_int32_t status;
    #line 149 "src/service_libraries/pus_tc_handler.fin"
    status.__variant = Success;

    #line 151 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 4U)) {
        
        #line 153 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint32(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              4U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 4U)]);

        #line 154 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 4U;

    } else
    {
        
        #line 158 "src/service_libraries/pus_tc_handler.fin"
        status.__variant = Failure;
        #line 158 "src/service_libraries/pus_tc_handler.fin"
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    #line 162 "src/service_libraries/pus_tc_handler.fin"
    return status;

}
