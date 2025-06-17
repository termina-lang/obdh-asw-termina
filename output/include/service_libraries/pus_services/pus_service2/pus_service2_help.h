#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__PUS_SERVICE2_HELP_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__PUS_SERVICE2_HELP_H__

#include <termina.h>

#include "resources/gpio_driver.h"
#include "resources/tm_channel.h"
#include "resources/tm_counter.h"
#include "service_libraries/pus_services/pus_service1/pus_service1.h"
#include "service_libraries/pus_services/pus_service9/pus_service9.h"
#include "service_libraries/pus_services/pus_services.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

extern const size_t num_params2;

typedef struct {
    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint8_t flags_ack;
    size_t tc_num_bytes;
    uint8_t N;
    uint32_t dev_address;
} PS2ExecTCReqStatusUpdate;

#endif
