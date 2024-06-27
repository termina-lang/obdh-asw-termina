#ifndef __LIBRARIES__TC_CCSDS_PUS_FORMAT_H__
#define __LIBRARIES__TC_CCSDS_PUS_FORMAT_H__

#include <termina.h>
#include "libraries/serialize.h"

#define tc_max_size UINT16_C(256)

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint16_t packet_length;
} CCSDSPUSTCPacketHeaderT;

typedef struct {
    uint8_t flag_ver_ack;
    uint8_t type;
    uint8_t subtype;
    uint8_t sourceID;
} CCSDSPUSTCDFHeaderT;

typedef struct {
    uint8_t tc_bytes[256];
    uint16_t tc_num_bytes;
} TCDescriptorT;

uint16_t get_packet_id(const uint8_t tc_bytes[256]);

uint16_t get_APID(const uint8_t tc_bytes[256]);

uint16_t get_seq_flags(uint16_t packet_seq_ctrl);

uint16_t get_seq_count(uint16_t packet_seq_ctrl);

uint16_t get_packet_length(const uint8_t tc_bytes[256]);

uint16_t get_packet_seq_ctrl(const uint8_t tc_bytes[256]);

uint8_t get_ack(uint8_t flag_ver_ack);

uint8_t get_type(const uint8_t tc_bytes[256]);

uint8_t get_subtype(const uint8_t tc_bytes[256]);

uint8_t get_source_id(const uint8_t tc_bytes[256]);

void tc_get_fields(const uint8_t tc_bytes[256],
                   CCSDSPUSTCPacketHeaderT * p_tc_packet_header,
                   CCSDSPUSTCDFHeaderT * p_tc_df_header,
                   uint16_t * p_tc_packet_err_ctrl);

#endif
