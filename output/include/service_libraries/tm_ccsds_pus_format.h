#ifndef __SERVICE_LIBRARIES__TM_CCSDS_PUS_FORMAT_H__
#define __SERVICE_LIBRARIES__TM_CCSDS_PUS_FORMAT_H__

#include <termina.h>

#include "resources/uart.h"
#include "service_libraries/serialize.h"

#include "option.h"
#include "result.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint16_t packet_length;
} CCSDSPUSTMPacketHeaderT;

typedef struct {
    uint8_t version;
    uint8_t type;
    uint8_t subtype;
    uint16_t msg_type_counter;
    uint16_t destinationID;
    uint32_t obt_secs;
    uint16_t obt_finetime;
} CCSDSPUSTMDFHeaderT;

typedef struct {
    uint8_t tm_bytes[256U];
    size_t tm_num_bytes;
} TMDescriptorT;

uint16_t ccsds_pus_tm_build_packet_id(uint16_t apid);

uint16_t ccsds_pus_tm_build_packet_seq_ctrl(uint16_t sequence_flags,
                                            uint16_t tm_count);

uint32_t ccsds_pus_tm_build_df_header(uint8_t service_type,
                                      uint8_t service_subtype,
                                      uint8_t destinationID);

uint8_t ccsds_pus_tm_build_df_header_version(uint8_t version);

void ccsds_pus_tm_set_fields(uint8_t tm_bytes[10U],
                             const CCSDSPUSTMPacketHeaderT * const p_tm_packet_header,
                             const CCSDSPUSTMDFHeaderT * const p_tm_df_header);

#endif
