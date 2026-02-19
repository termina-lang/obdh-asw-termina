#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6__INTERNAL_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE6__INTERNAL_H__

#include <termina.h>

#include "resources/obt_manager.h"
#include "resources/tm_channel.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_tm_handler.h"

#include "option.h"
#include "result.h"

extern const size_t max_num_of_bytes_memory_load;

extern const size_t banks_number;

extern const size_t bank_size;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t mem_id;
    uint8_t N;
    uint32_t address;
    uint16_t length;
    uint8_t data[256U];
} PS6ExecTCReqStatusUpdate;

__status_int32_t build_tm_6_6(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt, const PS6ExecTCReqStatusUpdate * const mem_data);

__status_int32_t build_tm_6_10(TMHandler * const p_tm_handler, uint16_t tm_seq_counter, MissionOBT current_obt, const PS6ExecTCReqStatusUpdate * const mem_data, uint16_t checksum);

#endif
