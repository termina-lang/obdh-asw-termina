
#include "service_libraries/pus_tm_handler.h"

const uint16_t APID = 0x32CU;

const uint16_t destinationID = 0x78U;

const size_t tm_app_data_offset = 19U;

__status_int32_t append_u8_appdata_field(TMHandler * const tm_handler, uint8_t data) {
    
    #line 58 "src/service_libraries/pus_tm_handler.fin"
    __status_int32_t status;
    #line 58 "src/service_libraries/pus_tm_handler.fin"
    status.__variant = Success;

    #line 60 "src/service_libraries/pus_tm_handler.fin"
    if (tm_handler->app_data_index < 256U) {
        
        #line 62 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->tm_descriptor.tm_bytes[__termina_array__index(256U, tm_handler->app_data_index)] = data;

        #line 63 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 1U;

        #line 64 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Success;

    } else
    {
        
        #line 68 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Failure;
        #line 68 "src/service_libraries/pus_tm_handler.fin"
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    #line 72 "src/service_libraries/pus_tm_handler.fin"
    return status;

}

__status_int32_t append_u16_appdata_field(TMHandler * const tm_handler, uint16_t data) {
    
    #line 86 "src/service_libraries/pus_tm_handler.fin"
    __status_int32_t status;
    #line 86 "src/service_libraries/pus_tm_handler.fin"
    status.__variant = Success;

    #line 88 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 1U) < 256U) {
        
        #line 90 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint16(data, &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U, 2U, tm_handler->app_data_index, tm_handler->app_data_index + 2U)]);

        #line 91 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 2U;

        #line 92 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Success;

    } else
    {
        
        #line 96 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Failure;
        #line 96 "src/service_libraries/pus_tm_handler.fin"
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    #line 99 "src/service_libraries/pus_tm_handler.fin"
    return status;

}

__status_int32_t append_u32_appdata_field(TMHandler * const tm_handler, uint32_t data) {
    
    #line 113 "src/service_libraries/pus_tm_handler.fin"
    __status_int32_t status;
    #line 113 "src/service_libraries/pus_tm_handler.fin"
    status.__variant = Success;

    #line 115 "src/service_libraries/pus_tm_handler.fin"
    if ((size_t)(tm_handler->app_data_index + 3U) < 256U) {
        
        #line 117 "src/service_libraries/pus_tm_handler.fin"
        serialize_uint32(data, &tm_handler->tm_descriptor.tm_bytes[__termina_array__slice(256U, 4U, tm_handler->app_data_index, tm_handler->app_data_index + 4U)]);

        #line 118 "src/service_libraries/pus_tm_handler.fin"
        tm_handler->app_data_index = tm_handler->app_data_index + 4U;

        #line 119 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Success;

    } else
    {
        
        #line 123 "src/service_libraries/pus_tm_handler.fin"
        status.__variant = Failure;
        #line 123 "src/service_libraries/pus_tm_handler.fin"
        status.Failure.__0 = BUILD_TM_ERROR;

    }

    #line 127 "src/service_libraries/pus_tm_handler.fin"
    return status;

}

void tm_handler_build_packet_header(TMHandler * const tm_handler, uint16_t tm_seq_counter) {
    
    #line 142 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_id = ccsds_pus_tm_build_packet_id(APID);

    #line 144 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_seq_ctrl = tm_seq_counter & 0x3FFFU;

    #line 146 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->packet_header.packet_length = (uint16_t)(tm_handler->app_data_index - 7U);

    #line 148 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void tm_handler_build_df_header(TMHandler * const tm_handler, uint8_t tm_type, uint8_t tm_subtype, MissionOBT current_obt) {
    
    #line 164 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.version = 0x20U;

    #line 165 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.type = tm_type;

    #line 166 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.subtype = tm_subtype;

    #line 167 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.msg_type_counter = 0U;

    #line 168 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.destinationID = destinationID;

    #line 169 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_secs = current_obt.seconds;

    #line 170 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->df_header.obt_finetime = current_obt.finetime;

    #line 172 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void close_tm(TMHandler * const tm_handler, uint8_t type, uint8_t subtype, uint16_t tm_count, MissionOBT current_obt) {
    
    #line 190 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_packet_header(tm_handler, tm_count);

    #line 191 "src/service_libraries/pus_tm_handler.fin"
    tm_handler_build_df_header(tm_handler, type, subtype, current_obt);

    #line 193 "src/service_libraries/pus_tm_handler.fin"
    ccsds_pus_tm_set_fields(&tm_handler->tm_descriptor.tm_bytes[0U], &tm_handler->packet_header, &tm_handler->df_header);

    #line 195 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = (size_t)tm_handler->packet_header.packet_length + 7U;

    #line 197 "src/service_libraries/pus_tm_handler.fin"
    return;

}

void startup_tm(TMHandler * const tm_handler) {
    
    #line 211 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->tm_descriptor.tm_num_bytes = 256U;

    #line 212 "src/service_libraries/pus_tm_handler.fin"
    tm_handler->app_data_index = tm_app_data_offset;

    #line 214 "src/service_libraries/pus_tm_handler.fin"
    return;

}
