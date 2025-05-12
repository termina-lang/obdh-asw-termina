#ifndef __SERVICE_LIBRARIES__TC_CCSDS_PUS_FORMAT_H__
#define __SERVICE_LIBRARIES__TC_CCSDS_PUS_FORMAT_H__

#include <termina.h>

#include "service_libraries/serialize.h"

#include "option.h"

extern const size_t max_tc_size;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint16_t packet_length;
} CCSDSPUSTCPacketHeaderT;

typedef struct {
    uint8_t flag_ver_ack;
    uint8_t type;
    uint8_t subtype;
    uint16_t sourceID;
} CCSDSPUSTCDFHeaderT;

typedef struct {
    uint8_t tc_bytes[max_tc_size];
    size_t tc_num_bytes;
} TCDescriptorT;

uint16_t get_packet_id(const uint8_t tc_bytes[max_tc_size]);

uint16_t get_APID(const uint8_t tc_bytes[max_tc_size]);

uint16_t get_seq_flags(uint16_t packet_seq_ctrl);

uint16_t get_seq_count(uint16_t packet_seq_ctrl);

uint16_t get_packet_length(const uint8_t tc_bytes[max_tc_size]);

uint16_t get_packet_seq_ctrl(const uint8_t tc_bytes[max_tc_size]);

uint8_t get_ack(uint8_t flag_ver_ack);

uint8_t get_type(const uint8_t tc_bytes[max_tc_size]);

uint8_t get_subtype(const uint8_t tc_bytes[max_tc_size]);

uint8_t get_source_id(const uint8_t tc_bytes[max_tc_size]);

void tc_get_fields(const uint8_t tc_bytes[max_tc_size],
                   CCSDSPUSTCPacketHeaderT * const p_tc_packet_header,
                   CCSDSPUSTCDFHeaderT * const p_tc_df_header,
                   uint16_t * const p_tc_packet_err_ctrl);

#endif
