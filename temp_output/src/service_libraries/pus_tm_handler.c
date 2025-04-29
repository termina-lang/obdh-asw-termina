
#include "service_libraries/pus_tm_handler.h"

const uint16_t base_length = 7U;

const uint16_t APID = 0x32CU;

const uint16_t destinationID = 0x78U;

const size_t tm_app_data_offset = 19U;

void append_u8_appdata_field(TMHandlerT * const tm_handler, uint8_t data,
                             Result * const result) {
    
    if (tm_handler->app_data_index < max_send_size) {
        
        tm_handler->tm_descriptor.tm_bytes[__termina_array__index(max_send_size,
                                                                  tm_handler->app_data_index)] = data;

        tm_handler->app_data_index = tm_handler->app_data_index + 1U;

        (*result).__variant = Result__Ok;

    } else {
        
        (*result).__variant = Result__Error;

    }

    return;

}

void append_u16_appdata_field(TMHandlerT * const tm_handler, uint16_t data,
                              Result * const result) {
    
    if ((size_t)(tm_handler->app_data_index + 1U) < max_send_size) {
        
        serialize_uint16(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(max_send_size,
                                                                                    2U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 2U)]);

        tm_handler->app_data_index = tm_handler->app_data_index + 2U;

        (*result).__variant = Result__Ok;

    } else {
        
        (*result).__variant = Result__Error;

    }

    return;

}

void append_u32_appdata_field(TMHandlerT * const tm_handler, uint32_t data,
                              Result * const result) {
    
    if ((size_t)(tm_handler->app_data_index + 3U) < max_send_size) {
        
        serialize_uint32(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(max_send_size,
                                                                                    4U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 4U)]);

        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

        (*result).__variant = Result__Ok;

    } else {
        
        (*result).__variant = Result__Error;

    }

    return;

}

void append_TimeVal_as_u32_appdata_field(TMHandlerT * const tm_handler,
                                         TimeVal time, Result * const result) {
    
    uint32_t data = time.tv_sec;

    if ((size_t)(tm_handler->app_data_index + 3U) < max_send_size) {
        
        serialize_uint32(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(max_send_size,
                                                                                    4U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 4U)]);

        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

        (*result).__variant = Result__Ok;

    } else {
        
        (*result).__variant = Result__Error;

    }

    return;

}

void tm_handler_build_packet_header(TMHandlerT * const tm_handler,
                                    uint16_t tm_seq_counter) {
    
    tm_handler->packet_header.packet_id = ccsds_pus_tm_build_packet_id(APID);

    tm_handler->packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3U,
                                                                                   tm_seq_counter);

    tm_handler->packet_header.packet_length = (uint16_t)(tm_handler->app_data_index - 7U);

    return;

}

void tm_handler_build_df_header(TMHandlerT * const tm_handler, uint8_t tm_type,
                                uint8_t tm_subtype) {
    
    tm_handler->df_header.version = ccsds_pus_tm_build_df_header_version(0x1U);

    tm_handler->df_header.type = tm_type;

    tm_handler->df_header.subtype = tm_subtype;

    tm_handler->df_header.msg_type_counter = 0U;

    tm_handler->df_header.destinationID = destinationID;

    tm_handler->df_header.obt_secs = 0U;

    tm_handler->df_header.obt_finetime = 0U;

    return;

}

void close_tm(TMHandlerT * const tm_handler, uint8_t type, uint8_t subtype,
              uint16_t tm_count, Result * const result) {
    
    (*result).__variant = Result__Ok;

    tm_handler_build_packet_header(tm_handler, tm_count);

    tm_handler_build_df_header(tm_handler, type, subtype);

    ccsds_pus_tm_set_fields(&tm_handler->tm_descriptor.tm_bytes[0U],
                            &tm_handler->packet_header, &tm_handler->df_header);

    tm_handler->tm_descriptor.tm_num_bytes = (size_t)tm_handler->packet_header.packet_length + 7U;

    return;

}

void startup_tm(TMHandlerT * const tm_handler) {
    
    tm_handler->tm_descriptor.tm_num_bytes = max_send_size;

    tm_handler->app_data_index = tm_app_data_offset;

    return;

}
