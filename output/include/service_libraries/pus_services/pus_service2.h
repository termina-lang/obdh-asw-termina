#ifndef SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2_H__
#define SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2_H__

#include <termina.h>

#include "resources/gpio_driver.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service12.h"
#include "service_libraries/pus_services/pus_service2/internal.h"
#include "service_libraries/pus_services/pus_service2/types.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    termina__resource_lock_type_t _lock_type;
    struct {
        void * _that;
        void (* write_led)(const termina__event_t * const termina__ev, void * const termina__this, uint8_t led, uint8_t value, Status__i32 * const status);
    } gpio_driver;
    struct {
        void * _that;
        void (* notify_tm_1_3)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* notify_tm_1_7)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, Status__i32 * const status);
        void (* send_tm_1_4_device_address_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint32_t device_address, Status__i32 * const status);
        void (* send_tm_1_4_error_in_acceptance)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t N, Status__i32 * const status);
        void (* send_tm_1_4_short_pack_length)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, size_t tc_bytes, Status__i32 * const status);
        void (* send_tm_1_8_device_command_exec_error)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint32_t on_off_command, Status__i32 * const status);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const termina__event_t * const termina__ev, void * const termina__this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, Status__i32 * const status);
    } pus_service_1;
} CPUSService2;

void CPUSService2__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status);

#endif
