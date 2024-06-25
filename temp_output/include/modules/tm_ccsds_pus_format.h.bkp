#ifndef __MODULES__TM_CCSDS_PUS_FORMAT_H__
#define __MODULES__TM_CCSDS_PUS_FORMAT_H__

#include <termina.h>
#include "modules/serialize.h"

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint16_t packet_length;
} CCSDSPUSTMPacketHeaderT;

typedef struct {
    uint8_t version;
    uint8_t type;
    uint8_t subtype;
    uint8_t destinationID;
} CCSDSPUSTMDFHeaderT;

typedef struct {
    uint8_t tm_bytes[256];
    uint16_t tm_num_bytes;
} TMDescriptorT;

uint16_t ccsds_pus_tm_build_packet_id(uint16_t apid);

uint16_t ccsds_pus_tm_build_packet_seq_ctrl(uint16_t sequence_flags,
                                            uint16_t tm_count);

uint32_t ccsds_pus_tm_build_df_header(uint8_t service_type,
                                      uint8_t service_subtype,
                                      uint8_t destinationID);

uint8_t ccsds_pus_tm_build_df_header_version(uint8_t version);

void ccsds_pus_tm_set_fields(uint8_t tm_bytes[10],
                             const CCSDSPUSTMPacketHeaderT * p_tm_packet_header,
                             const CCSDSPUSTMDFHeaderT * p_tm_df_header);

#endif
