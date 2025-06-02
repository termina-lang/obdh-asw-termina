
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(void * const __this,
                                      __status_int32_t * const status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 373 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 373 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 375 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 375 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 376 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 380 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 378 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 382 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        startup_tm((TMHandlerT *)b_tm_handler.data);

        #line 383 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                 EvID_build_tm_error, &result);

        #line 385 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 387 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 388 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count);

            #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MissionObt current_obt;
            #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 390 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 391 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            #line 392 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 394 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 395 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Failure;
                #line 395 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            } else
            {
                
                #line 397 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Success;

            }

        } else
        {
            
            #line 402 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 406 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 406 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 410 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
    
    #line 356 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    startup_tm(p_tm_handler);

    #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, ev_ID, result);

    #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, fault_info.PID, result);

    #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, result);

    #line 360 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_mask, result);

    #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_expected_value,
                             result);

    #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    #line 363 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 363 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 363 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 364 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 365 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    #line 367 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_tm_5_x_param_out_of_limit(const PUSService5 * const self,
                                                  TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  ParamOutOfLimitInfo fault_info,
                                                  uint16_t ev_ID,
                                                  MyResult * const result) {
    
    #line 340 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    startup_tm(p_tm_handler);

    #line 341 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, ev_ID, result);

    #line 342 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, fault_info.PID, result);

    #line 343 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, result);

    #line 344 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_limit, result);

    #line 345 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 347 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 348 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x(void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 416 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 416 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 418 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 418 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 419 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 423 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 421 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 426 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 429 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 428 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 430 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            PUSService5__build_tm_5_x_param_out_of_limit(self,
                                                         (TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         fault_value_info, evID,
                                                         &result);

        } else
        #line 432 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 428 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 433 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            PUSService5__build_tm_5_x_param_check_value_fail(self,
                                                             (TMHandlerT *)b_tm_handler.data,
                                                             tm_count,
                                                             fault_value_info,
                                                             evID, &result);

        } else
        {
            
            #line 436 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            result.__variant = MyResult__Error;

        }

        #line 440 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 444 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 445 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Failure;
                #line 445 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).Failure.__0 = TM_SEND_FAILURE;

            } else
            {
                
                #line 447 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                (*status).__variant = Success;

            }

        } else
        {
            
            #line 452 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 458 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 458 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 462 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
    _Bool ack_enabled = 0;

    #line 61 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 61 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 63 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 63 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 63 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 65 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 65 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 66 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 70 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 68 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 72 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 73 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 75 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 76 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 79 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 81 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 82 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 85 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 87 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 89 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 90 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 90 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 94 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 95 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 95 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 100 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 102 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 104 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 105 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 107 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 109 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 111 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 113 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 114 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 114 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 118 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 119 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 119 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 123 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 126 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

                #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 133 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 131 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 135 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 136 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 137 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 138 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 140 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 142 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 144 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 146 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 147 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 147 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 151 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 152 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 152 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 157 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 162 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 162 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 168 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 169 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &result);

                #line 172 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 174 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 176 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 177 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 177 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 181 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 182 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 182 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 194 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__exec5_6TC(PUSService5 * const self) {
    
    #line 200 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 200 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 201 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 202 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 202 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 204 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 204 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 204 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 206 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 206 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 207 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 211 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 209 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 213 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 214 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 216 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 217 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 220 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 222 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 223 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 226 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 228 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 230 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 231 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 231 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 235 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 236 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 236 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 242 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 244 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 246 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 249 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 251 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 253 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 255 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 256 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 256 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 260 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 261 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 261 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 265 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 268 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

                #line 270 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 270 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 271 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 273 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 277 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 278 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 279 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 280 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 282 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 284 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 286 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 288 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 289 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 289 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 293 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 294 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 294 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 298 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 302 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 302 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 308 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 309 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &result);

                #line 312 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 317 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 317 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 321 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 322 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 322 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 333 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PS5ExecTCReqStatusUpdate PUSService5__get_TC_params(const PUSService5 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 467 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PS5ExecTCReqStatusUpdate tc_data;
    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.EvID = 0U;
    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.N = 0U;
    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.flags_ack = 0U;
    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_id = 0U;
    #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.tc_num_bytes = 0U;

    #line 477 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 478 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 479 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 480 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 481 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 482 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.EvID);

    #line 484 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService5__manage_error_in_acceptance(const PUSService5 * const self) {
    
    #line 532 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 532 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 533 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 533 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 535 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 535 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 535 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 537 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 537 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 538 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 542 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 540 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 544 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 545 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 547 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 548 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 551 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 553 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 555 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 556 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 556 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 560 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 561 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 561 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 566 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 566 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 570 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_short_pack_length_error(const PUSService5 * const self) {
    
    #line 490 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 490 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 491 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 491 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 493 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 493 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 493 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 495 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 495 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 496 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 500 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 498 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 502 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 503 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 505 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 506 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 509 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 511 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 513 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 514 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 514 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 518 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 519 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 519 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 523 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 523 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 527 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_tm_limit_app_data_reached(const PUSService5 * const self) {
    
    #line 575 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 575 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 576 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MyResult result;
    #line 576 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    result.__variant = MyResult__Ok;

    #line 578 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 578 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 578 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 580 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 580 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 581 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 585 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 583 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 587 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 588 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 590 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 591 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 594 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 596 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 598 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 599 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 599 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 603 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 604 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 604 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 609 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 609 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 613 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

void PUSService5__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 618 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = 0U;

    #line 620 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 624 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 626 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MyResult result;
            #line 626 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            result.__variant = MyResult__Ok;

            #line 627 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update = PUSService5__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 629 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 630 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 630 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 632 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 636 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 638 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 5U) {
                
                #line 640 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__exec5_5TC(self);

            } else
            #line 642 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 6U) {
                
                #line 644 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__exec5_6TC(self);

            } else
            {
                
                #line 648 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 648 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 651 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 622 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 653 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 655 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 658 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__manage_error_in_acceptance(self);

            } else
            #line 660 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 663 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__manage_tm_limit_app_data_reached(self);

            } else
            #line 665 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 667 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 675 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 622 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 677 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 677 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 678 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 687 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 689 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 692 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
