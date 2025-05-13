#ifndef __TASKS__HK_FDIR_MNG__HK_FDIR_H__
#define __TASKS__HK_FDIR_MNG__HK_FDIR_H__

#include <termina.h>

#include "service_libraries/errors.h"
#include "service_libraries/pus_services/pus_service12/pus_service12.h"
#include "service_libraries/pus_services/pus_service19/pus_service19.h"
#include "service_libraries/pus_services/pus_service3/pus_service3.h"
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

#include "option.h"

extern const size_t num_actions_per_second;

typedef struct {
    __termina_id_t __task_id;
    __termina_id_t __task_msg_queue_id;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const,
                         __status_int32_t * const);
    } pus_service_4;
    struct {
        void * __that;
        void (* manage_event_action)(void * const, uint16_t);
    } pus_service_19;
    struct {
        void * __that;
        void (* build_and_tx_tm_5_x)(void * const, __status_int32_t * const,
                                     uint16_t, FaultInfo);
        void (* is_Ev_ID_enabled_ext)(void * const, uint16_t, _Bool * const);
    } pus_service_5;
    struct {
        void * __that;
        void (* do_monitoring)(void * const, uint16_t, uint16_t * const,
                               FaultInfo * const, _Bool * const);
        void (* is_PMON_enabled)(void * const, size_t, _Bool * const);
    } pus_service_12;
    struct {
        void * __that;
        void (* exec_tc)(void * const, TCHandlerT * const,
                         __status_int32_t * const);
    } pus_service_3;
    __termina_allocator_t a_tc_handler_pool;
    __termina_out_port_t action_tc_message_queue_output;
    __termina_id_t hkfdir_message_queue_input;
    __termina_id_t hk_fdir_timer_ev;
} HouseKeepingFDIR;

void __HouseKeepingFDIR__termina_task(void * const arg);

__status_int32_t HouseKeepingFDIR__do_fdir(HouseKeepingFDIR * const self);

__status_int32_t HouseKeepingFDIR__do_hk_fdir(void * const __this,
                                              TimeVal _current_time);

__status_int32_t HouseKeepingFDIR__exec_tc(void * const __this,
                                           __termina_box_t tc_handler);

#endif
