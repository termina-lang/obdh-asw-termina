#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2_H__

#include <termina.h>

#include "resources/gpio_driver.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service2/types.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"
#include "service_libraries/tm_ccsds_pus_format.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandler * const, __status_int32_t * const);
} PUSS2Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* write_led)(const __termina_event_t * const, void * const, uint8_t, uint8_t, __status_int32_t * const);
    } gpio_driver;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_4_device_address_not_valid)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint32_t, __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint8_t, __status_int32_t * const);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const, void * const, uint16_t, uint16_t, size_t, __status_int32_t * const);
        void (* send_tm_1_8_device_command_exec_error)(const __termina_event_t * const, void * const, uint16_t, uint16_t, uint32_t, __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const, void * const, uint16_t, uint16_t, __status_int32_t * const);
    } pus_service_1;
} PUSService2;

__status_int32_t PUSService2__dev_drv_on_off(const __termina_event_t * const __ev, PUSService2 * const self, const PS2ExecTCReqStatusUpdate * const exec_tc_req_status_update);

_Bool PUSService2__device_drv_is_on_off_address_valid(const __termina_event_t * const __ev, const PUSService2 * const self, const PS2ExecTCReqStatusUpdate * const exec_tc_req_status_update);

__status_int32_t PUSService2__exec2_1TC(const __termina_event_t * const __ev, PUSService2 * const self, const PS2ExecTCReqStatusUpdate * const exec_tc_req_status_update);

void PUSService2__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status);

#endif
