#ifndef __SERVICE_LIBRARIES__PUS_TC_HANDLER_H__
#define __SERVICE_LIBRARIES__PUS_TC_HANDLER_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    TCDescriptorT tc_descriptor;
    CCSDSPUSTCPacketHeaderT packet_header;
    CCSDSPUSTCDFHeaderT df_header;
    uint16_t packet_error_ctrl;
    size_t app_data_index;
} TCHandlerT;

TCHandlerT tc_handler_init();

void tc_handler_build_from_descriptor(TCHandlerT * const tc_handler,
                                      const TCDescriptorT * const telecommand);

_Bool tc_handler_is_valid_next_appdata_field(const TCHandlerT * const tc_handler,
                                             size_t field_size);

__status_int32_t tc_handler_get_u8_appdata_field(TCHandlerT * const tc_handler,
                                                 uint8_t * const data);

__status_int32_t tc_handler_get_u16_appdata_field(TCHandlerT * const tc_handler,
                                                  uint16_t * const data);

__status_int32_t tc_handler_get_u32_appdata_field(TCHandlerT * const tc_handler,
                                                  uint32_t * const data);

#endif
