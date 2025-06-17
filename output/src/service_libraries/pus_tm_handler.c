
#include "service_libraries/pus_tm_handler.h"

const uint16_t APID = 0x32CU;

const uint16_t destinationID = 0x78U;

const size_t tm_app_data_offset = 19U;

__status_int32_t append_u8_appdata_field(TMHandlerT * const tm_handler,
                                         uint8_t data) {
    
    __status_int32_t status;
    status.__variant = Success;

    if (tm_handler->app_data_index < 256U) {
        
        tm_handler->tm_descriptor.tm_bytes[__termina_array__index(256U,
                                                                  tm_handler->app_data_index)] = data;

        tm_handler->app_data_index = tm_handler->app_data_index + 1U;

        status.__variant = Success;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    return status;

}

__status_int32_t append_u16_appdata_field(TMHandlerT * const tm_handler,
                                          uint16_t data) {
    
    __status_int32_t status;
    status.__variant = Success;

    if ((size_t)(tm_handler->app_data_index + 1U) < 256U) {
        
        serialize_uint16(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U,
                                                                                    2U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 2U)]);

        tm_handler->app_data_index = tm_handler->app_data_index + 2U;

        status.__variant = Success;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    return status;

}

__status_int32_t append_u32_appdata_field(TMHandlerT * const tm_handler,
                                          uint32_t data) {
    
    __status_int32_t status;
    status.__variant = Success;

    if ((size_t)(tm_handler->app_data_index + 3U) < 256U) {
        
        serialize_uint32(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U,
                                                                                    4U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 4U)]);

        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

        status.__variant = Success;

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    return status;

}

void tm_handler_build_packet_header(TMHandlerT * const tm_handler,
                                    uint16_t tm_seq_counter) {
    
    tm_handler->packet_header.packet_id = ccsds_pus_tm_build_packet_id(APID);

    tm_handler->packet_header.packet_seq_ctrl = tm_seq_counter & 0x3FFFU;

    tm_handler->packet_header.packet_length = (uint16_t)(tm_handler->app_data_index - 7U);

    return;

}

void tm_handler_build_df_header(TMHandlerT * const tm_handler, uint8_t tm_type,
                                uint8_t tm_subtype, MissionObt current_obt) {
    
    tm_handler->df_header.version = 0x20U;

    tm_handler->df_header.type = tm_type;

    tm_handler->df_header.subtype = tm_subtype;

    tm_handler->df_header.msg_type_counter = 0U;

    tm_handler->df_header.destinationID = destinationID;

    tm_handler->df_header.obt_secs = current_obt.seconds;

    tm_handler->df_header.obt_finetime = current_obt.finetime;

    return;

}

void close_tm(TMHandlerT * const tm_handler, uint8_t type, uint8_t subtype,
              uint16_t tm_count, MissionObt current_obt) {
    
    tm_handler_build_packet_header(tm_handler, tm_count);

    tm_handler_build_df_header(tm_handler, type, subtype, current_obt);

    ccsds_pus_tm_set_fields(&tm_handler->tm_descriptor.tm_bytes[0U],
                            &tm_handler->packet_header, &tm_handler->df_header);

    tm_handler->tm_descriptor.tm_num_bytes = (size_t)tm_handler->packet_header.packet_length + 7U;

    return;

}

void startup_tm(TMHandlerT * const tm_handler) {
    
    tm_handler->tm_descriptor.tm_num_bytes = 256U;

    tm_handler->app_data_index = tm_app_data_offset;

    return;

}
