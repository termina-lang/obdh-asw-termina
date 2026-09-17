#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2_H__

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
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* write_led)(const __termina_event_t * const __ev, void * const __this, uint8_t led, uint8_t value, __status_int32_t * const status);
    } gpio_driver;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* notify_tm_1_7)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t flags_ack, __status_int32_t * const status);
        void (* send_tm_1_4_device_address_not_valid)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint32_t device_address, __status_int32_t * const status);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint8_t N, __status_int32_t * const status);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, size_t tc_bytes, __status_int32_t * const status);
        void (* send_tm_1_8_device_command_exec_error)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, uint32_t on_off_command, __status_int32_t * const status);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const __ev, void * const __this, uint16_t tc_packet_id, uint16_t tc_packet_seq_ctrl, __status_int32_t * const status);
    } pus_service_1;
} CPUSService2;

void CPUSService2__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);

#endif
