#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__PUS_SERVICE2_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE2__PUS_SERVICE2_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service2/pus_service2_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
} PUSS2Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionObt * const);
    } pus_service_9;
    struct {
        void * __that;
        void (* write_led)(const __termina_event_t * const, void * const,
                           uint8_t, uint8_t, __status_int32_t * const);
    } gpio_driver;
    struct {
        void * __that;
        void (* get_next_tm_count)(const __termina_event_t * const,
                                   void * const, uint16_t * const);
    } tm_counter;
    __termina_allocator_t a_tm_handler_pool;
    struct {
        void * __that;
        void (* send_tm)(const __termina_event_t * const, void * const,
                         __termina_box_t, __status_int32_t * const);
    } tm_channel;
    PS2ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
} PUSService2;

__status_int32_t PUSService2__dev_drv_on_off(const __termina_event_t * const __ev,
                                             PUSService2 * const self);

_Bool PUSService2__device_drv_is_on_off_address_valid(const __termina_event_t * const __ev,
                                                      const PUSService2 * const self);

PSExecTCReqStatus PUSService2__exec2_1TC(const __termina_event_t * const __ev,
                                         PUSService2 * const self);

PSExecTCReqStatus PUSService2__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                          const PUSService2 * const self);

PSExecTCReqStatus PUSService2__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                              const PUSService2 * const self);

PSExecTCReqStatus PUSService2__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                const PUSService2 * const self);

void PUSService2__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);

#endif
