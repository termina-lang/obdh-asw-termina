#ifndef __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__
#define __SERVICE_LIBRARIES__PUS_SERVICES__PUS_SERVICE5_H__

#include <termina.h>

#include "service_libraries/pus_services/pus_service5/internal.h"

#include "option.h"

typedef enum {
    FaultInfo__ParamOutOfLimit,
    FaultInfo__ParamFaultValue,
    FaultInfo__Empty
} __enum_FaultInfo_t;

typedef struct {
    ParamOutOfLimitInfo __0;
} __enum_FaultInfo__ParamOutOfLimit_params_t;

typedef struct {
    ParamFaultValueInfo __0;
} __enum_FaultInfo__ParamFaultValue_params_t;

typedef struct {
    __enum_FaultInfo_t __variant;
    union {
        __enum_FaultInfo__ParamOutOfLimit_params_t ParamOutOfLimit;
        __enum_FaultInfo__ParamFaultValue_params_t ParamFaultValue;
    };
} FaultInfo;

typedef struct {
    void * __that;
    void (* exec_tc)(void * const, TCHandler * const, __status_int32_t * const);
    void (* is_Ev_ID_enabled_ext)(void * const, uint16_t, _Bool * const);
    void (* send_tm_5_x)(void * const, uint16_t, FaultInfo,
                         __status_int32_t * const);
    void (* send_tm_5_2)(void * const, __status_int32_t * const);
} PUSS5Iface;

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
        void (* send_tm_1_4_EvID_not_valid)(const __termina_event_t * const,
                                            void * const, uint16_t, uint16_t,
                                            uint16_t, __status_int32_t * const);
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
    PS5ExecTCReqStatusUpdate exec_tc_req_status_update;
    uint32_t Ev_ID_enable_config[4U];
} PUSService5;

__status_int32_t PUSService5__exec5_5TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self);

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self);

void PUSService5__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandler * const tc_handler,
                          __status_int32_t * const action_status);

_Bool PUSService5__is_Ev_ID_enabled(const __termina_event_t * const __ev,
                                    const PUSService5 * const self,
                                    uint16_t Ev_ID);

void PUSService5__is_Ev_ID_enabled_ext(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled);

void PUSService5__send_tm_5_2(const __termina_event_t * const __ev,
                              void * const __this,
                              __status_int32_t * const status);

void PUSService5__send_tm_5_x(const __termina_event_t * const __ev,
                              void * const __this, uint16_t evID,
                              FaultInfo fault_info,
                              __status_int32_t * const status);

#endif
