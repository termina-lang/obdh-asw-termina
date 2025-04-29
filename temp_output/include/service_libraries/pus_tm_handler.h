#ifndef __SERVICE_LIBRARIES__PUS_TM_HANDLER_H__
#define __SERVICE_LIBRARIES__PUS_TM_HANDLER_H__

#include <termina.h>

#include "option.h"
#include "service_libraries/tm_ccsds_pus_format.h"
#include "service_libraries/serialize.h"

typedef struct {
    TMDescriptorT tm_descriptor;
    CCSDSPUSTMPacketHeaderT packet_header;
    CCSDSPUSTMDFHeaderT df_header;
    size_t app_data_index;
} TMHandlerT;

extern const uint16_t base_length;

extern const uint16_t APID;

extern const uint16_t destinationID;

extern const size_t tm_app_data_offset;

void append_u8_appdata_field(TMHandlerT * const tm_handler, uint8_t data,
                             Result * const result);

void append_u16_appdata_field(TMHandlerT * const tm_handler, uint16_t data,
                              Result * const result);

void append_u32_appdata_field(TMHandlerT * const tm_handler, uint32_t data,
                              Result * const result);

void append_TimeVal_as_u32_appdata_field(TMHandlerT * const tm_handler,
                                         TimeVal time, Result * const result);

void tm_handler_build_packet_header(TMHandlerT * const tm_handler,
                                    uint16_t tm_seq_counter);

void tm_handler_build_df_header(TMHandlerT * const tm_handler, uint8_t tm_type,
                                uint8_t tm_subtype);

void close_tm(TMHandlerT * const tm_handler, uint8_t type, uint8_t subtype,
              uint16_t tm_count, Result * const result);

void startup_tm(TMHandlerT * const tm_handler);

#endif
