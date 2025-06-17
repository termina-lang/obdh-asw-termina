
#include "service_libraries/pus_tc_handler.h"

void tc_handler_build_from_descriptor(TCHandlerT * const tc_handler,
                                      const TCDescriptorT * const telecommand) {
    
    for (size_t i = 0U; i < 256U && i < telecommand->tc_num_bytes; i = i + 1U) {
        
        tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                  i)] = telecommand->tc_bytes[__termina_array__index(256U,
                                                                                                                     i)];

    }

    tc_handler->tc_descriptor.tc_num_bytes = telecommand->tc_num_bytes;

    tc_get_fields(telecommand->tc_bytes, &tc_handler->packet_header,
                  &tc_handler->df_header, &tc_handler->packet_error_ctrl);

    tc_handler->app_data_index = 11U;

    return;

}

_Bool tc_handler_is_valid_next_appdata_field(const TCHandlerT * const tc_handler,
                                             size_t field_size) {
    
    _Bool res = 0;

    size_t required_size = tc_handler->app_data_index + field_size;

    if (required_size <= tc_handler->tc_descriptor.tc_num_bytes) {
        
        res = 1;

    }

    return res;

}

__status_int32_t tc_handler_get_u8_appdata_field(TCHandlerT * const tc_handler,
                                                 uint8_t * const data) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 1U)) {
        
        *data = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                          tc_handler->app_data_index)];

        tc_handler->app_data_index = tc_handler->app_data_index + 1U;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    return status;

}

__status_int32_t tc_handler_get_u16_appdata_field(TCHandlerT * const tc_handler,
                                                  uint16_t * const data) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 2U)) {
        
        *data = deserialize_uint16(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              2U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 2U)]);

        tc_handler->app_data_index = tc_handler->app_data_index + 2U;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    return status;

}

__status_int32_t tc_handler_get_u32_appdata_field(TCHandlerT * const tc_handler,
                                                  uint32_t * const data) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 4U)) {
        
        *data = deserialize_uint32(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              4U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 4U)]);

        tc_handler->app_data_index = tc_handler->app_data_index + 4U;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

    }

    return status;

}
