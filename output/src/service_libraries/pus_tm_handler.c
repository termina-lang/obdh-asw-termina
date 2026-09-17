
#include "service_libraries/pus_tm_handler.h"

const uint16_t APID = 0x32CU;

const uint16_t DESTINATION_ID = 0x78U;

const size_t tm_app_data_offset = 19U;

__status_int32_t append_u8_appdata_field(TMHandler * const tm_handler, uint8_t data) {
    
    #line 58 "src/service_libraries/pus_tm_handler.fin"
    __status_int32_t status = { .__variant = Success };

    #line 60 "src/service_libraries/pus_tm_handler.fin"
    if (tm_handler->app_data_index < 256U) {
        
        #line 62 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->tm_descriptor.tm_bytes[__termina_array__index(256U, tm_handler->app_data_index)] = data;

        #line 63 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 1U;

    } else
    {
        
        #line 67 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Failure;
        #line 67 "src/service_libraries/pus_tm_handler.fin"
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    #line 71 "src/service_libraries/pus_tm_handler.fin"
    return status;

}

__status_int32_t append_u16_appdata_field(TMHandler * const tm_handler, uint16_t data) {
    
    #line 85 "src/service_libraries/pus_tm_handler.fin"
    __status_int32_t status = { .__variant = Success };

    #line 87 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 1U) < 256U) {
        
        #line 89 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint16(data, &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U, 2U, tm_handler->app_data_index, tm_handler->app_data_index + 2U)]);

        #line 90 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 2U;

    } else
    {
        
        #line 94 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Failure;
        #line 94 "src/service_libraries/pus_tm_handler.fin"
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    #line 97 "src/service_libraries/pus_tm_handler.fin"
    return status;

}

__status_int32_t append_u32_appdata_field(TMHandler * const tm_handler, uint32_t data) {
    
    #line 111 "src/service_libraries/pus_tm_handler.fin"
    __status_int32_t status = { .__variant = Success };

    #line 113 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 3U) < 256U) {
        
        #line 115 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint32(data, &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U, 4U, tm_handler->app_data_index, tm_handler->app_data_index + 4U)]);

        #line 116 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

    } else
    {
        
        #line 120 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Failure;
        #line 120 "src/service_libraries/pus_tm_handler.fin"
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    #line 124 "src/service_libraries/pus_tm_handler.fin"
    return status;

}

void tm_handler_build_packet_header(TMHandler * const tm_handler, uint16_t tm_seq_counter) {
    
    #line 139 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_id = ccsds_pus_tm_build_packet_id(APID);

    #line 141 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_seq_ctrl = tm_seq_counter & 0x3FFFU;

    #line 143 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_length = (uint16_t)(size_t)(tm_handler->app_data_index - 7U);

    #line 145 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void tm_handler_build_df_header(TMHandler * const tm_handler, uint8_t tm_type, uint8_t tm_subtype, MissionOBT current_obt) {
    
    #line 161 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.version = 0x20U;

    #line 162 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.type = tm_type;

    #line 163 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.subtype = tm_subtype;

    #line 164 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.msg_type_counter = 0U;

    #line 165 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.destinationID = DESTINATION_ID;

    #line 166 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_secs = current_obt.seconds;

    #line 167 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_finetime = current_obt.finetime;

    #line 169 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void close_tm(TMHandler * const tm_handler, uint8_t type, uint8_t subtype, uint16_t tm_count, MissionOBT current_obt) {
    
    #line 187 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_packet_header(tm_handler, tm_count);

    #line 188 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_df_header(tm_handler, type, subtype, current_obt);

    #line 190 "src/service_libraries/pus_tm_handler.fin"
    ccsds_pus_tm_set_fields(&tm_handler->tm_descriptor.tm_bytes[0U], &tm_handler->packet_header, &tm_handler->df_header);

    #line 192 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = (size_t)tm_handler->packet_header.packet_length + 7U;

    #line 194 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void startup_tm(TMHandler * const tm_handler) {
    
    #line 208 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = 256U;

    #line 209 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->app_data_index = tm_app_data_offset;

    #line 211 "src/service_libraries/pus_tm_handler.fin"
    return;

}
