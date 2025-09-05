#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE20_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service20/types.h"

#include "option.h"

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandler * const, __status_int32_t * const);
} PUSS20Iface;

typedef struct {
    __termina_resource_lock_type_t __lock_type;
    struct {
        void * __that;
        void (* notify_tm_1_3)(const __termina_event_t * const, void * const,
                               uint16_t, uint16_t, uint8_t,
                               __status_int32_t * const);
        void (* notify_tm_1_7)(const __termina_event_t * const, void * const,
                               uint16_t, uint16_t, uint8_t,
                               __status_int32_t * const);
        void (* send_tm_1_4_PID_not_valid)(const __termina_event_t * const,
                                           void * const, uint16_t, uint16_t,
                                           uint16_t, __status_int32_t * const);
        void (* send_tm_1_4_PID_read_only_via_TC)(const __termina_event_t * const,
                                                  void * const, uint16_t,
                                                  uint16_t, uint16_t,
                                                  __status_int32_t * const);
        void (* send_tm_1_4_error_in_acceptance)(const __termina_event_t * const,
                                                 void * const, uint16_t,
                                                 uint16_t,
                                                 __status_int32_t * const);
        void (* send_tm_1_4_num_of_instr_not_valid)(const __termina_event_t * const,
                                                    void * const, uint16_t,
                                                    uint16_t, uint8_t,
                                                    __status_int32_t * const);
        void (* send_tm_1_4_short_pack_length)(const __termina_event_t * const,
                                               void * const, uint16_t, uint16_t,
                                               size_t,
                                               __status_int32_t * const);
        void (* send_tm_1_8_tm_exceed_limit_appdata)(const __termina_event_t * const,
                                                     void * const, uint16_t,
                                                     uint16_t,
                                                     __status_int32_t * const);
    } pus_service_1;
    struct {
        void * __that;
        void (* get_current_obt)(const __termina_event_t * const, void * const,
                                 MissionOBT * const);
    } obt_manager;
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
    _Atomic uint8_t * system_data_pool_u8;
    _Atomic uint32_t * system_data_pool_u32;
    PS20ExecTCReqStatusUpdate exec_tc_req_status_update;
} PUSService20;

__status_int32_t PUSService20__exec20_1TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self);

__status_int32_t PUSService20__exec20_3TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self);

void PUSService20__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandler * const tc_handler,
                           __status_int32_t * const action_status);

#endif
