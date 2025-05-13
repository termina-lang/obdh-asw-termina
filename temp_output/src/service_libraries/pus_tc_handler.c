
#include "service_libraries/pus_tc_handler.h"

TCHandlerT tc_handler_init() {
    
    TCHandlerT tc_handler;
    tc_handler.app_data_index = 0U;
    tc_handler.df_header.flag_ver_ack = 0U;
    tc_handler.df_header.sourceID = 0U;
    tc_handler.df_header.subtype = 0U;
    tc_handler.df_header.type = 0U;
    tc_handler.packet_error_ctrl = 0U;
    tc_handler.packet_header.packet_id = 0U;
    tc_handler.packet_header.packet_length = 0U;
    tc_handler.packet_header.packet_seq_ctrl = 0U;
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        tc_handler.tc_descriptor.tc_bytes[__i0] = 0U;
    }
    tc_handler.tc_descriptor.tc_num_bytes = 0U;

    return tc_handler;

}

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

    tc_handler->app_data_index = 10U;

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

MyResult tc_handler_get_u8_appdata_field(TCHandlerT * const tc_handler,
                                         uint8_t * const data) {
    
    MyResult res;
    res.__variant = MyResult__Ok;

    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 1U)) {
        
        *data = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                          tc_handler->app_data_index)];

        tc_handler->app_data_index = tc_handler->app_data_index + 1U;

    } else {
        
        res.__variant = MyResult__Error;

    }

    return res;

}

MyResult tc_handler_get_u16_appdata_field(TCHandlerT * const tc_handler,
                                          uint16_t * const data) {
    
    MyResult res;
    res.__variant = MyResult__Ok;

    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 2U)) {
        
        *data = deserialize_uint16(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              2U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 2U)]);

        tc_handler->app_data_index = tc_handler->app_data_index + 2U;

    } else {
        
        res.__variant = MyResult__Error;

    }

    return res;

}

MyResult tc_handler_get_u32_appdata_field(TCHandlerT * const tc_handler,
                                          uint32_t * const data) {
    
    MyResult res;
    res.__variant = MyResult__Ok;

    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 4U)) {
        
        *data = deserialize_uint32(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              4U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 4U)]);

        tc_handler->app_data_index = tc_handler->app_data_index + 4U;

    } else {
        
        res.__variant = MyResult__Error;

    }

    return res;

}
