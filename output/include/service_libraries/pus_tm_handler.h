#ifndef __SERVICE_LIBRARIES__PUS_TM_HANDLER_H__
#define __SERVICE_LIBRARIES__PUS_TM_HANDLER_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "service_libraries/errors.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"
#include "result.h"

typedef struct {
    TMDescriptor tm_descriptor;
    CCSDSPUSTMPacketHeader packet_header;
    CCSDSPUSTMDFHeader df_header;
    size_t app_data_index;
} TMHandler;

extern const uint16_t APID;

extern const uint16_t destinationID;

extern const size_t tm_app_data_offset;

__status_int32_t append_u8_appdata_field(TMHandler * const tm_handler, uint8_t data);

__status_int32_t append_u16_appdata_field(TMHandler * const tm_handler, uint16_t data);

__status_int32_t append_u32_appdata_field(TMHandler * const tm_handler, uint32_t data);

void tm_handler_build_packet_header(TMHandler * const tm_handler, uint16_t tm_seq_counter);

void tm_handler_build_df_header(TMHandler * const tm_handler, uint8_t tm_type, uint8_t tm_subtype, MissionOBT current_obt);

void close_tm(TMHandler * const tm_handler, uint8_t type, uint8_t subtype, uint16_t tm_count, MissionOBT current_obt);

void startup_tm(TMHandler * const tm_handler);

#endif
