
#include "service_libraries/pus_tc_handler.h"

TCHandlerT tc_handler_init() {
    
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    TCHandlerT tc_handler;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.app_data_index = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.df_header.flag_ver_ack = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.df_header.sourceID = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.df_header.subtype = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.df_header.type = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.packet_error_ctrl = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.packet_header.packet_id = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.packet_header.packet_length = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.packet_header.packet_seq_ctrl = 0U;
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 18 "src/service_libraries/pus_tc_handler.fin"
        tc_handler.tc_descriptor.tc_bytes[__i0] = 0U;
    }
    #line 18 "src/service_libraries/pus_tc_handler.fin"
    tc_handler.tc_descriptor.tc_num_bytes = 0U;

    #line 20 "src/service_libraries/pus_tc_handler.fin"
    return tc_handler;

}

void tc_handler_build_from_descriptor(TCHandlerT * const tc_handler,
                                      const TCDescriptorT * const telecommand) {
    
    #line 26 "src/service_libraries/pus_tc_handler.fin"
    for (size_t i = 0U; i < 256U && i < telecommand->tc_num_bytes; i = i + 1U) {
        
        #line 27 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                  i)] = telecommand->tc_bytes[__termina_array__index(256U,
                                                                                                                     i)];

    }

    #line 29 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->tc_descriptor.tc_num_bytes = telecommand->tc_num_bytes;

    #line 31 "src/service_libraries/pus_tc_handler.fin"
    tc_get_fields(telecommand->tc_bytes, &tc_handler->packet_header,
                  &tc_handler->df_header, &tc_handler->packet_error_ctrl);

    #line 33 "src/service_libraries/pus_tc_handler.fin"
    tc_handler->app_data_index = 11U;

    #line 35 "src/service_libraries/pus_tc_handler.fin"
    return;

}

_Bool tc_handler_is_valid_next_appdata_field(const TCHandlerT * const tc_handler,
                                             size_t field_size) {
    
    #line 41 "src/service_libraries/pus_tc_handler.fin"
    _Bool res = 0;

    #line 43 "src/service_libraries/pus_tc_handler.fin"
    size_t required_size = tc_handler->app_data_index + field_size;

    #line 45 "src/service_libraries/pus_tc_handler.fin"
    if (required_size <= tc_handler->tc_descriptor.tc_num_bytes) {
        
        #line 47 "src/service_libraries/pus_tc_handler.fin"
        res = 1;

    }

    #line 51 "src/service_libraries/pus_tc_handler.fin"
    return res;

}

MyResult tc_handler_get_u8_appdata_field(TCHandlerT * const tc_handler,
                                         uint8_t * const data) {
    
    #line 57 "src/service_libraries/pus_tc_handler.fin"
    MyResult res;
    #line 57 "src/service_libraries/pus_tc_handler.fin"
    res.__variant = MyResult__Ok;

    #line 59 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 1U)) {
        
        #line 61 "src/service_libraries/pus_tc_handler.fin"
        *data = tc_handler->tc_descriptor.tc_bytes[__termina_array__index(256U,
                                                                          tc_handler->app_data_index)];

        #line 62 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 1U;

    } else
    {
        
        #line 66 "src/service_libraries/pus_tc_handler.fin"
        res.__variant = MyResult__Error;

    }

    #line 70 "src/service_libraries/pus_tc_handler.fin"
    return res;

}

MyResult tc_handler_get_u16_appdata_field(TCHandlerT * const tc_handler,
                                          uint16_t * const data) {
    
    #line 76 "src/service_libraries/pus_tc_handler.fin"
    MyResult res;
    #line 76 "src/service_libraries/pus_tc_handler.fin"
    res.__variant = MyResult__Ok;

    #line 78 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 2U)) {
        
        #line 80 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint16(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              2U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 2U)]);

        #line 81 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 2U;

    } else
    {
        
        #line 85 "src/service_libraries/pus_tc_handler.fin"
        res.__variant = MyResult__Error;

    }

    #line 89 "src/service_libraries/pus_tc_handler.fin"
    return res;

}

MyResult tc_handler_get_u32_appdata_field(TCHandlerT * const tc_handler,
                                          uint32_t * const data) {
    
    #line 95 "src/service_libraries/pus_tc_handler.fin"
    MyResult res;
    #line 95 "src/service_libraries/pus_tc_handler.fin"
    res.__variant = MyResult__Ok;

    #line 97 "src/service_libraries/pus_tc_handler.fin"
    if (tc_handler_is_valid_next_appdata_field(&*tc_handler, 4U)) {
        
        #line 99 "src/service_libraries/pus_tc_handler.fin"
        *data = deserialize_uint32(&tc_handler->tc_descriptor.tc_bytes[__termina_array__slice(256U,
                                                                                              4U,
                                                                                              tc_handler->app_data_index,
                                                                                              tc_handler->app_data_index + 4U)]);

        #line 100 "src/service_libraries/pus_tc_handler.fin"
        tc_handler->app_data_index = tc_handler->app_data_index + 4U;

    } else
    {
        
        #line 104 "src/service_libraries/pus_tc_handler.fin"
        res.__variant = MyResult__Error;

    }

    #line 108 "src/service_libraries/pus_tc_handler.fin"
    return res;

}
