#ifndef SERVICE_LIBRARIES__PUS_TM_HANDLER_H__
#define SERVICE_LIBRARIES__PUS_TM_HANDLER_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "service_libraries/errors.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    TMDescriptor tm_descriptor;
    CCSDSPUSTMPacketHeader packet_header;
    CCSDSPUSTMDFHeader df_header;
    size_t app_data_index;
} TMHandler;

extern const uint16_t APID;

extern const uint16_t DESTINATION_ID;

extern const size_t tm_app_data_offset;

Status__i32 append_u8_appdata_field(TMHandler * const tm_handler, const uint8_t data);

Status__i32 append_u16_appdata_field(TMHandler * const tm_handler, const uint16_t data);

Status__i32 append_u32_appdata_field(TMHandler * const tm_handler, const uint32_t data);

void tm_handler_build_packet_header(TMHandler * const tm_handler, const uint16_t tm_seq_counter);

void tm_handler_build_df_header(TMHandler * const tm_handler, const uint8_t tm_type, const uint8_t tm_subtype, const MissionOBT current_obt);

void close_tm(TMHandler * const tm_handler, const uint8_t type, const uint8_t subtype, const uint16_t tm_count, const MissionOBT current_obt);

void startup_tm(TMHandler * const tm_handler);

#endif
