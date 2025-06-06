
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(void * const __this,
                                      __status_int32_t * const status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 343 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 343 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 344 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 348 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        startup_tm((TMHandlerT *)b_tm_handler.data);

        #line 351 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                 EvID_build_tm_error, status);

        #line 353 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 355 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 356 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count);

            #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MissionObt current_obt;
            #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            #line 360 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     status);

        } else
        {
            
            #line 365 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 369 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 369 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 373 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
                                                      __status_int32_t * const status) {
    
    #line 326 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    startup_tm(p_tm_handler);

    #line 327 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, ev_ID, status);

    #line 328 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, fault_info.PID, status);

    #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, status);

    #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_mask, status);

    #line 331 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_expected_value,
                             status);

    #line 332 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    #line 333 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 333 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 333 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 334 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 335 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    #line 337 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_tm_5_x_param_out_of_limit(const PUSService5 * const self,
                                                  TMHandlerT * const p_tm_handler,
                                                  uint16_t tm_seq_counter,
                                                  ParamOutOfLimitInfo fault_info,
                                                  uint16_t ev_ID,
                                                  __status_int32_t * const status) {
    
    #line 310 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    startup_tm(p_tm_handler);

    #line 311 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, ev_ID, status);

    #line 312 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u16_appdata_field(p_tm_handler, fault_info.PID, status);

    #line 313 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_value, status);

    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    append_u32_appdata_field(p_tm_handler, fault_info.PID_limit, status);

    #line 315 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = (uint8_t)get_Ev_ID_enable_config_index(ev_ID);

    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 317 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 318 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    close_tm(p_tm_handler, 5U, subtype, tm_seq_counter, current_obt);

    #line 320 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x(void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 379 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 379 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 380 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 384 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 382 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 386 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 387 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 390 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 391 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            PUSService5__build_tm_5_x_param_out_of_limit(self,
                                                         (TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         fault_value_info, evID,
                                                         status);

        } else
        #line 393 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 394 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            PUSService5__build_tm_5_x_param_check_value_fail(self,
                                                             (TMHandlerT *)b_tm_handler.data,
                                                             tm_count,
                                                             fault_value_info,
                                                             evID, status);

        } else
        {
            
            #line 397 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*status).__variant = Failure;
            #line 397 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*status).Failure.__0 = INVALID_FAULT_INFO_ERROR;

        }

        #line 401 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 403 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     status);

        } else
        {
            
            #line 407 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 413 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 413 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 417 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
    _Bool ack_enabled = 0;

    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.status.__variant = Success;

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
                                                current_obt,
                                                &next_status.status);

            #line 84 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (next_status.status.__variant == Success) {
                
                #line 86 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &next_status.status);

            } else
            {
                
                #line 90 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 96 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 98 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 100 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 101 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 103 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 105 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 107 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 111 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 115 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 118 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

                #line 120 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 120 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 121 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 125 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 123 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 127 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 130 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 132 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 134 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 136 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 140 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 145 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 150 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.status.__variant = Failure;
                    #line 150 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 156 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 157 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &next_status.status);

                #line 160 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 162 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 166 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 175 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.__variant = Failure;
        #line 175 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 179 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__exec5_6TC(PUSService5 * const self) {
    
    #line 185 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.status.__variant = Success;

    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 191 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 195 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 193 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 197 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 198 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 200 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 201 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 204 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 206 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 207 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt,
                                                &next_status.status);

            #line 210 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (next_status.status.__variant == Success) {
                
                #line 212 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &next_status.status);

            } else
            {
                
                #line 216 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 223 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 225 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 227 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 228 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 230 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 232 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 234 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 238 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 242 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 245 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 248 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 252 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 250 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 254 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 255 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 256 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 257 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 259 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 261 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 263 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 267 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 271 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.status.__variant = Failure;
                    #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

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
                                            current_obt, &next_status.status);

                #line 285 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 287 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 291 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 299 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.__variant = Failure;
        #line 299 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 303 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_error_in_acceptance(const PUSService5 * const self) {
    
    #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.status.__variant = Success;

    #line 463 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 463 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 463 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 465 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 465 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 466 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 470 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 468 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 472 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 473 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 475 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 476 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 479 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (next_status.status.__variant == Success) {
            
            #line 481 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &next_status.status);

        } else
        {
            
            #line 485 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 491 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.__variant = Failure;
        #line 491 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 495 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_short_pack_length_error(const PUSService5 * const self) {
    
    #line 423 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 423 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 423 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.status.__variant = Success;

    #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 427 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 427 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 428 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 432 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 430 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 434 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 435 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 437 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 438 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 441 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (next_status.status.__variant == Success) {
            
            #line 443 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &next_status.status);

        } else
        {
            
            #line 447 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 452 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.__variant = Failure;
        #line 452 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 456 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

PSExecTCReqStatus PUSService5__manage_tm_limit_app_data_reached(const PUSService5 * const self) {
    
    #line 500 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PSExecTCReqStatus next_status;
    #line 500 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 500 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    next_status.status.__variant = Success;

    #line 502 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 502 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 502 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 504 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 504 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 505 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 509 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 507 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 511 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 512 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 514 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 515 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 518 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (next_status.status.__variant == Success) {
            
            #line 520 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &next_status.status);

        } else
        {
            
            #line 524 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 529 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.__variant = Failure;
        #line 529 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 533 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return next_status;

}

void PUSService5__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService5 * self = (PUSService5 *)__this;

    #line 538 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 540 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 544 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 546 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 547 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 548 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 549 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 550 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                              &self->exec_tc_req_status_update.N);

            #line 551 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                               &self->exec_tc_req_status_update.EvID);

            #line 553 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 555 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 559 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 559 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 560 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 565 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 567 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 5U) {
                
                #line 569 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__exec5_5TC(self);

            } else
            #line 571 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 6U) {
                
                #line 573 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status = PUSService5__exec5_6TC(self);

            } else
            {
                
                #line 577 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 577 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 578 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 589 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 591 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 587 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 596 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 599 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status = PUSService5__manage_error_in_acceptance(self);

        } else
        #line 601 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 604 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status = PUSService5__manage_tm_limit_app_data_reached(self);

        } else
        #line 606 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 608 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status = PUSService5__manage_short_pack_length_error(self);

        } else
        #line 610 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == INVALID_FAULT_INFO_ERROR) {
            

        } else
        {
            
            #line 616 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 616 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 623 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 624 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 628 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
