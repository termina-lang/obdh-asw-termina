
#include "service_libraries/pus_tm_handler.h"

const uint16_t APID = 0x32CU;

const uint16_t destinationID = 0x78U;

const size_t tm_app_data_offset = 19U;

void append_u8_appdata_field(TMHandlerT * const tm_handler, uint8_t data,
                             __status_int32_t * const status) {
    
    #line 57 "src/service_libraries/pus_tm_handler.fin"
    if (tm_handler->app_data_index < 256U) {
        
        #line 59 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->tm_descriptor.tm_bytes[__termina_array__index(256U,
                                                                  tm_handler->app_data_index)] = data;

        #line 60 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 1U;

        #line 61 "src/service_libraries/pus_tm_handler.fin"
        (*status).__variant = Success;

    } else
    {
        
        #line 65 "src/service_libraries/pus_tm_handler.fin"
        (*status).__variant = Failure;
        #line 65 "src/service_libraries/pus_tm_handler.fin"
        (*status).Failure.__0 = BUILD_TM_ERROR;

    }

    #line 69 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void append_u16_appdata_field(TMHandlerT * const tm_handler, uint16_t data,
                              __status_int32_t * const status) {
    
    #line 83 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 1U) < 256U) {
        
        #line 85 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint16(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U,
                                                                                    2U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 2U)]);

        #line 86 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 2U;

        #line 87 "src/service_libraries/pus_tm_handler.fin"
        (*status).__variant = Success;

    } else
    {
        
        #line 91 "src/service_libraries/pus_tm_handler.fin"
        (*status).__variant = Failure;
        #line 91 "src/service_libraries/pus_tm_handler.fin"
        (*status).Failure.__0 = BUILD_TM_ERROR;

    }

    #line 94 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void append_u32_appdata_field(TMHandlerT * const tm_handler, uint32_t data,
                              __status_int32_t * const status) {
    
    #line 108 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 3U) < 256U) {
        
        #line 110 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint32(data,
                         &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U,
                                                                                    4U,
                                                                                    tm_handler->app_data_index,
                                                                                    tm_handler->app_data_index + 4U)]);

        #line 111 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

        #line 112 "src/service_libraries/pus_tm_handler.fin"
        (*status).__variant = Success;

    } else
    {
        
        #line 116 "src/service_libraries/pus_tm_handler.fin"
        (*status).__variant = Failure;
        #line 116 "src/service_libraries/pus_tm_handler.fin"
        (*status).Failure.__0 = BUILD_TM_ERROR;

    }

    #line 120 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void tm_handler_build_packet_header(TMHandlerT * const tm_handler,
                                    uint16_t tm_seq_counter) {
    
    #line 135 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_id = ccsds_pus_tm_build_packet_id(APID);

    #line 137 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_seq_ctrl = tm_seq_counter & 0x3FFFU;

    #line 139 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_length = (uint16_t)(tm_handler->app_data_index - 7U);

    #line 141 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void tm_handler_build_df_header(TMHandlerT * const tm_handler, uint8_t tm_type,
                                uint8_t tm_subtype, MissionObt current_obt) {
    
    #line 157 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.version = 0x20U;

    #line 158 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.type = tm_type;

    #line 159 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.subtype = tm_subtype;

    #line 160 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.msg_type_counter = 0U;

    #line 161 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.destinationID = destinationID;

    #line 162 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_secs = current_obt.seconds;

    #line 163 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_finetime = current_obt.finetime;

    #line 165 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void close_tm(TMHandlerT * const tm_handler, uint8_t type, uint8_t subtype,
              uint16_t tm_count, MissionObt current_obt) {
    
    #line 183 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_packet_header(tm_handler, tm_count);

    #line 184 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_df_header(tm_handler, type, subtype, current_obt);

    #line 186 "src/service_libraries/pus_tm_handler.fin"
    ccsds_pus_tm_set_fields(&tm_handler->tm_descriptor.tm_bytes[0U],
                            &tm_handler->packet_header, &tm_handler->df_header);

    #line 188 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = (size_t)tm_handler->packet_header.packet_length + 7U;

    #line 190 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void startup_tm(TMHandlerT * const tm_handler) {
    
    #line 204 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = 256U;

    #line 205 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->app_data_index = tm_app_data_offset;

    #line 207 "src/service_libraries/pus_tm_handler.fin"
    return;

}
