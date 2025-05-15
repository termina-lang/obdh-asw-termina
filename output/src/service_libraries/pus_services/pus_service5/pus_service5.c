
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(void * const __this,
                                      __status_int32_t * const status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 348 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 348 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 349 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 353 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 351 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 355 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        startup_tm((TMHandlerT *)b_tm_handler.data);

        #line 356 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                 EvID_build_tm_error, &result);

        #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 360 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count);

            #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MissionObt current_obt;
            #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 363 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 364 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            #line 365 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 367 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 368 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Failure;
                #line 368 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            } else
            {
                
                #line 370 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Success;

            }

        } else
        {
            
            #line 375 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 379 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 379 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 383 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_2__mutex_lock(void * const __this,
                                                  __status_int32_t * const status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService5__build_and_tx_tm_5_2(self, status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService5__build_and_tx_tm_5_2__task_lock(void * const __this,
                                                 __status_int32_t * const status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__build_and_tx_tm_5_2(__this, status);
    __termina_task__unlock(lock);

}

void PUSService5__build_and_tx_tm_5_2__event_lock(void * const __this,
                                                  __status_int32_t * const status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__build_and_tx_tm_5_2(__this, status);
    __termina_event__unlock(lock);

}

void PUSService5__build_tm_5_x_param_check_value_fail(const PUSService5 * const self,
                                                      TMHandlerT * const p_tm_handler,
                                                      uint16_t tm_seq_counter,
                                                      ParamFaultValueInfo fault_info,
                                                      uint16_t ev_ID,
                                                      MyResult * const result) {
    
    #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    startup_tm(p_tm_handler);

    #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, ev_ID, result);

    #line 331 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, fault_info.PID, result);

    #line 332 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, result);

    #line 333 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_mask, result);

    #line 334 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_expected_value,
                             result);

    #line 335 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    #line 336 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 336 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 336 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 337 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 338 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    #line 340 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_tm_5_x_param_out_of_limit(const PUSService5 * const self,
                                                  TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  ParamOutOfLimitInfo fault_info,
                                                  uint16_t ev_ID,
                                                  MyResult * const result) {
    
    #line 313 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    startup_tm(p_tm_handler);

    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, ev_ID, result);

    #line 315 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, fault_info.PID, result);

    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, result);

    #line 317 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_limit, result);

    #line 318 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    #line 319 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 319 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 319 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 320 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 321 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    #line 323 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x(void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 391 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 391 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 392 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 396 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 394 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 398 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 399 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 402 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 401 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 403 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            PUSService5__build_tm_5_x_param_out_of_limit(self,
                                                         (TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         fault_value_info, evID,
                                                         &result);

        } else
        #line 405 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 401 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 406 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            PUSService5__build_tm_5_x_param_check_value_fail(self,
                                                             (TMHandlerT *)b_tm_handler.data,
                                                             tm_count,
                                                             fault_value_info,
                                                             evID, &result);

        } else
        {
            
            #line 409 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            result.__variant = MyResult__Error;

        }

        #line 413 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 415 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 417 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 418 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Failure;
                #line 418 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            } else
            {
                
                #line 420 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Success;

            }

        } else
        {
            
            #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 431 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 431 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 435 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x__mutex_lock(void * const __this,
                                                  __status_int32_t * const status,
                                                  uint16_t evID,
                                                  FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService5__build_and_tx_tm_5_x(self, status, evID, fault_info);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService5__build_and_tx_tm_5_x__task_lock(void * const __this,
                                                 __status_int32_t * const status,
                                                 uint16_t evID,
                                                 FaultInfo fault_info) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__build_and_tx_tm_5_x(__this, status, evID, fault_info);
    __termina_task__unlock(lock);

}

void PUSService5__build_and_tx_tm_5_x__event_lock(void * const __this,
                                                  __status_int32_t * const status,
                                                  uint16_t evID,
                                                  FaultInfo fault_info) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__build_and_tx_tm_5_x(__this, status, evID, fault_info);
    __termina_event__unlock(lock);

}

PSExecTCReqStatus PUSService5__exec5_5TC(PUSService5 * const self) {
    
    #line 59 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 59 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 62 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 62 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 62 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 64 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 64 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 65 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 69 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 67 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 71 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 72 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 74 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 75 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 78 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 80 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 81 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 84 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 86 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 88 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 89 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 89 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 93 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 94 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 94 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 99 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 101 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 103 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 104 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 106 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 108 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 110 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 111 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 111 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 115 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 116 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 116 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 119 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

                #line 121 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 121 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 122 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 126 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 124 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 130 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 131 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 133 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 135 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 137 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 138 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 138 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 142 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 143 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 143 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 148 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 148 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 154 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 155 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &result);

                #line 158 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 160 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 162 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 163 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 163 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 167 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 168 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 168 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 176 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 176 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 180 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__exec5_6TC(PUSService5 * const self) {
    
    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 187 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 187 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 189 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 189 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 189 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 191 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 191 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 192 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 196 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 194 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 198 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 199 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 201 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 202 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 205 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 207 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 208 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 211 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 213 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 215 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 216 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 216 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 220 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 221 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 221 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 227 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 229 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 231 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 232 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 234 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 236 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 238 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 239 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 239 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 243 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 244 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 244 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

                #line 249 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 249 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 250 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 254 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 252 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 256 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 257 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 258 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 259 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 261 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 263 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 265 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 266 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 266 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 270 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 271 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 271 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 281 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 282 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &result);

                #line 285 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 287 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 289 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 290 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 290 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 294 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 295 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 295 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 302 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 302 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 306 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PS5ExecTCReqStatusUpdate PUSService5__get_TC_params(const PUSService5 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 440 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PS5ExecTCReqStatusUpdate tc_data;
    #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.EvID = 0U;
    #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.N = 0U;
    #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_id = 0U;
    #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.tc_num_bytes = 0U;

    #line 449 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 450 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 451 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 452 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 453 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.EvID);

    #line 455 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService5__manage_error_in_acceptance(const PUSService5 * const self) {
    
    #line 503 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 503 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 504 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 504 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 506 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 506 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 506 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 508 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 508 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 509 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 513 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 511 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 515 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 516 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 518 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 519 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 522 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 524 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 526 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 527 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 527 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 531 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 532 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 532 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 537 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 537 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 541 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_short_pack_length_error(const PUSService5 * const self) {
    
    #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 462 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 462 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 466 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 466 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 467 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 471 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 473 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 474 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 476 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 477 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 480 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 482 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 484 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 485 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 485 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 489 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 490 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 490 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 494 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 494 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 498 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_tm_limit_app_data_reached(const PUSService5 * const self) {
    
    #line 546 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 546 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 547 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 547 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 549 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 549 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 549 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 551 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 551 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 552 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 556 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 554 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 558 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 559 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 561 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 562 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 565 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 567 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 569 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 570 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 570 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 574 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 575 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 575 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 580 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 580 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 584 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

void PUSService5__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 589 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = 0U;

    #line 591 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 595 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 597 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MyResult result;
            #line 597 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            result.__variant = MyResult__Ok;

            #line 598 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update = PUSService5__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 600 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 601 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 601 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 603 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 607 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 609 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 5U) {
                
                #line 611 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__exec5_5TC(self);

            } else
            #line 613 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 6U) {
                
                #line 615 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__exec5_6TC(self);

            } else
            {
                
                #line 619 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 619 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 622 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 593 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 624 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 626 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 629 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__manage_error_in_acceptance(self);

            } else
            #line 631 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 634 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__manage_tm_limit_app_data_reached(self);

            } else
            #line 636 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 638 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 646 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 593 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 648 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 648 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 649 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 658 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 660 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 663 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService5__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService5__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService5__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

_Bool PUSService5__is_Ev_ID_enabled(const PUSService5 * const self,
                                    uint16_t Ev_ID) {
    
    #line 35 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool enabled = 0;

    #line 36 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    size_t index = get_Ev_ID_enable_config_index(Ev_ID);

    #line 37 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t offset = get_Ev_ID_enable_config_offset(Ev_ID);

    #line 39 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (index < 4U) {
        
        #line 41 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((uint32_t)((uint32_t)(self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                   index)] >> offset) & 0x1U) != 0U) {
            
            #line 42 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            enabled = 1;

        }

    }

    #line 46 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return enabled;

}

void PUSService5__is_Ev_ID_enabled_ext(void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 51 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *p_enabled = PUSService5__is_Ev_ID_enabled(self, Ev_ID);

    #line 53 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__is_Ev_ID_enabled_ext__mutex_lock(void * const __this,
                                                   uint16_t Ev_ID,
                                                   _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService5__is_Ev_ID_enabled_ext(self, Ev_ID, p_enabled);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService5__is_Ev_ID_enabled_ext__task_lock(void * const __this,
                                                  uint16_t Ev_ID,
                                                  _Bool * const p_enabled) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService5__is_Ev_ID_enabled_ext(__this, Ev_ID, p_enabled);
    __termina_task__unlock(lock);

}

void PUSService5__is_Ev_ID_enabled_ext__event_lock(void * const __this,
                                                   uint16_t Ev_ID,
                                                   _Bool * const p_enabled) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService5__is_Ev_ID_enabled_ext(__this, Ev_ID, p_enabled);
    __termina_event__unlock(lock);

}
