#ifndef SERVICE_LIBRARIES__PUS_TC_HANDLER_H__
#define SERVICE_LIBRARIES__PUS_TC_HANDLER_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    TCDescriptor tc_descriptor;
    CCSDSPUSTCPacketHeader packet_header;
    CCSDSPUSTCDFHeader df_header;
    uint16_t packet_error_ctrl;
    size_t app_data_index;
} TCHandler;

void tc_handler_build(TCHandler * const tc_handler);

_Bool tc_handler_is_valid_next_appdata_field(const TCHandler * const tc_handler, const size_t field_size);

Status__i32 tc_handler_get_u8_appdata_field(TCHandler * const tc_handler, uint8_t * const data);

Status__i32 tc_handler_get_u16_appdata_field(TCHandler * const tc_handler, uint16_t * const data);

Status__i32 tc_handler_get_u32_appdata_field(TCHandler * const tc_handler, uint32_t * const data);

#endif
