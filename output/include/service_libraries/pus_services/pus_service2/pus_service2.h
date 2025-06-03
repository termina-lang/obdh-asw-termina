#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__PUS_SERVICE2_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__PUS_SERVICE2_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service2/pus_service2_help.h"

#include "option.h"
#include "result.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS2Iface;

typedef struct {
    __termina_id_t __mutex_id;
    struct {
        void * __that;
        void (* get_current_obt)(void * const, MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* write_led)(void * const, uint8_t, uint8_t, MyResult * const);
    } gpio_driver;
    struct {
        void * __that;
        void (* get_next_tm_count)(void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(void * const, __termina_box_t, MyResult * const);
    } tm_channel;
    PS2ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService2;

MyResult PUSService2__dev_drv_on_off(PUSService2 * const self);

_Bool PUSService2__device_drv_is_on_off_address_valid(const PUSService2 * const self);

PSExecTCReqStatus PUSService2__exec2_1TC(PUSService2 * const self);

PS2ExecTCReqStatusUpdate PUSService2__get_TC_params(const PUSService2 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result);

PSExecTCReqStatus PUSService2__manage_error_in_acceptance(const PUSService2 * const self);

PSExecTCReqStatus PUSService2__manage_short_pack_length_error(const PUSService2 * const self);

PSExecTCReqStatus PUSService2__manage_tm_limit_app_data_reached(const PUSService2 * const self);

void PUSService2__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);
void PUSService2__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);
void PUSService2__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status);
void PUSService2__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status);

#endif
