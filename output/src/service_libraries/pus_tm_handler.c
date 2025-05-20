
#include "service_libraries/pus_tm_handler.h"

const uint16_t base_length = 7U;

const uint16_t APID = 0x32CU;

const uint16_t destinationID = 0x78U;

const size_t tm_app_data_offset = 19U;

void append_u8_appdata_field(TMHandlerT * const tm_handler, uint8_t data,
                             MyResult * const result) {
    
    #line 24 "src/service_libraries/pus_tm_handler.fin"
    if (tm_handler->app_data_index < 256U) {
        
        #line 26 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->tm_descriptor.tm_bytes[__termina_array__index(256U,
                                                                  tm_handler->app_data_index)] = data;

        #line 27 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 1U;

        #line 28 "src/service_libraries/pus_tm_handler.fin"
        (*result).__variant = MyResult__Ok;

    } else
    {
        
        #line 32 "src/service_libraries/pus_tm_handler.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 36 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void append_u16_appdata_field(TMHandlerT * const tm_handler, uint16_t data,
                              MyResult * const result) {
    
    #line 41 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 1U) < 256U) {
        
        #line 43 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint16(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U,
                                                                                    2U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 2U)]);

        #line 44 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 2U;

        #line 45 "src/service_libraries/pus_tm_handler.fin"
        (*result).__variant = MyResult__Ok;

    } else
    {
        
        #line 49 "src/service_libraries/pus_tm_handler.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 52 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void append_u32_appdata_field(TMHandlerT * const tm_handler, uint32_t data,
                              MyResult * const result) {
    
    #line 57 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 3U) < 256U) {
        
        #line 59 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint32(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U,
                                                                                    4U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 4U)]);

        #line 60 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

        #line 61 "src/service_libraries/pus_tm_handler.fin"
        (*result).__variant = MyResult__Ok;

    } else
    {
        
        #line 65 "src/service_libraries/pus_tm_handler.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 69 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void tm_handler_build_packet_header(TMHandlerT * const tm_handler,
                                    uint16_t tm_seq_counter) {
    
    #line 76 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_id = ccsds_pus_tm_build_packet_id(APID);

    #line 79 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_seq_ctrl = tm_seq_counter & 0x3FFFU;

    #line 81 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_length = (uint16_t)(tm_handler->app_data_index - 7U);

    #line 83 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void tm_handler_build_df_header(TMHandlerT * const tm_handler, uint8_t tm_type,
                                uint8_t tm_subtype, MissionObt current_obt) {
    
    #line 89 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.version = 0x20U;

    #line 90 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.type = tm_type;

    #line 91 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.subtype = tm_subtype;

    #line 92 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.msg_type_counter = 0U;

    #line 93 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.destinationID = destinationID;

    #line 94 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_secs = current_obt.seconds;

    #line 95 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_finetime = current_obt.finetime;

    #line 97 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void close_tm(TMHandlerT * const tm_handler, uint8_t type, uint8_t subtype,
              uint16_t tm_count, MissionObt current_obt) {
    
    #line 103 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_packet_header(tm_handler, tm_count);

    #line 104 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_df_header(tm_handler, type, subtype, current_obt);

    #line 106 "src/service_libraries/pus_tm_handler.fin"
    ccsds_pus_tm_set_fields(&tm_handler->tm_descriptor.tm_bytes[0U],
                            &tm_handler->packet_header, &tm_handler->df_header);

    #line 108 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = (size_t)tm_handler->packet_header.packet_length + 7U;

    #line 110 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void startup_tm(TMHandlerT * const tm_handler) {
    
    #line 115 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = 256U;

    #line 116 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->app_data_index = tm_app_data_offset;

    #line 118 "src/service_libraries/pus_tm_handler.fin"
    return;

}
