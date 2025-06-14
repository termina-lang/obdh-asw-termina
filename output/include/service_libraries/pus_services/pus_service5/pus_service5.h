#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5__PUS_SERVICE5_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandlerT * const,
                     __status_int32_t * const);
    void (* is_Ev_ID_enabled_ext)(void * const, uint16_t, _Bool * const);
    void (* build_and_tx_tm_5_x)(void * const, __status_int32_t * const,
                                 uint16_t, FaultInfo);
    void (* build_and_tx_tm_5_2)(void * const, __status_int32_t * const);
} PUSS5Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionObt * const);
    } pus_service_9;
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
    PS5ExecTCReqStatusUpdate exec_tc_req_status_update;
    PSExecTCReqStatus exec_tc_req_status;
    uint32_t Ev_ID_enable_config[4U];
} PUSService5;

void PUSService5__build_and_tx_tm_5_2(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status);

void PUSService5__build_and_tx_tm_5_x(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info);

__status_int32_t PUSService5__exec5_5TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self);

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self);

void PUSService5__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status);

_Bool PUSService5__is_Ev_ID_enabled(const __termina_event_t * const __ev,
                                    const PUSService5 * const self,
                                    uint16_t Ev_ID);

void PUSService5__is_Ev_ID_enabled_ext(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled);

#endif
