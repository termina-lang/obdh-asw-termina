
#include "service_libraries/pus_services/pus_service3/pus_service3.h"

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, size_t index,
                                MyResult * const result) {
    
    #line 461 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    startup_tm(p_tm_handler);

    #line 462 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    append_u16_appdata_field(p_tm_handler,
                             self->hk_config_table[__termina_array__index(8U,
                                                                          index)].SID,
                             result);

    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint16_t PID = 0U;

    #line 465 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint32_t u32_SDP_value = 0U;

    #line 466 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t u8_SDP_value = 0U;

    #line 468 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t j = 0U; j < 16U && j < (size_t)self->hk_config_table[__termina_array__index(8U,
                                                                                            index)].num_params; j = j + 1U) {
        
        #line 470 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        PID = self->hk_config_table[__termina_array__index(8U,
                                                           index)].params_def[__termina_array__index(16U,
                                                                                                     j)];

        #line 471 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

        #line 474 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            #line 475 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

            #line 476 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            append_u8_appdata_field(p_tm_handler, u8_SDP_value, result);

        } else
        #line 478 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (item_type.__variant == DataPoolItemType__u32_t) {
            
            #line 479 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

            #line 480 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            append_u32_appdata_field(p_tm_handler, u32_SDP_value, result);

        } else
        {
            
            #line 483 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*result).__variant = MyResult__Error;

        }

    }

    #line 489 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 489 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 489 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 490 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 492 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    close_tm(p_tm_handler, 3U, 25U, tm_seq_counter, current_obt);

    #line 495 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__do_hk(void * const __this,
                        __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 749 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 749 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 751 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        #line 753 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            #line 755 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->hk_config_table[__termina_array__index(8U,
                                                         i)].interval_control = self->hk_config_table[__termina_array__index(8U,
                                                                                                                             i)].interval_control + 1U;

            #line 757 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control >= self->hk_config_table[__termina_array__index(8U,
                                                                                                                                  i)].interval) {
                
                #line 759 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control = 0U;

                #line 761 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler;
                #line 761 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler.__variant = None;

                #line 762 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler);

                #line 766 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler.__variant == Some) {
                    
                    #line 764 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    #line 768 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count = 0U;

                    #line 769 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count);

                    #line 771 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    PUSService3__build_tm_3_25(self,
                                               (TMHandlerT *)b_tm_handler.data,
                                               tm_count, i, &result);

                    #line 773 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 775 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 777 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 778 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            (*action_status).__variant = Failure;
                            #line 778 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            (*action_status).Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 783 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->pus_service_5.build_and_tx_tm_5_2(self->pus_service_5.__that,
                                                                action_status);

                        #line 784 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 790 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).__variant = Failure;
                    #line 790 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    #line 798 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__do_hk__mutex_lock(void * const __this,
                                    __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService3__do_hk(self, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService3__do_hk__task_lock(void * const __this,
                                   __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService3__do_hk(__this, action_status);
    __termina_task__unlock(lock);

}

void PUSService3__do_hk__event_lock(void * const __this,
                                    __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService3__do_hk(__this, action_status);
    __termina_event__unlock(lock);

}

IndexFound PUSService3__get_SIDindex(PUSService3 * const self) {
    
    #line 35 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    IndexFound index_found;
    #line 35 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    index_found.found = 0;
    #line 35 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    index_found.index = 0U;

    #line 37 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 8U && index_found.found == 0; i = i + 1U) {
        
        #line 39 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.SID == self->hk_config_table[__termina_array__index(8U,
                                                                                                        i)].SID) {
            
            #line 41 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            index_found.found = 1;

            #line 42 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            index_found.index = i;

        }

    }

    #line 45 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return index_found;

}

PSExecTCReqStatus PUSService3__exec3_31TC(PUSService3 * const self) {
    
    #line 324 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 324 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 325 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    _Bool ack_enabled = 0;

    #line 326 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 326 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 330 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 330 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 331 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 335 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 333 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 337 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 338 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 340 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 342 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 343 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 346 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 348 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 350 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 351 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 351 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 355 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 356 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 356 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 361 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 363 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 365 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 366 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.tc_data.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 368 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (ack_enabled) {
                    
                    #line 370 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 372 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 374 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 375 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 375 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 379 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 380 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 380 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 384 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 387 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                #line 388 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 390 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 390 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 391 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 395 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 393 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 397 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 398 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 400 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 401 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 403 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (ack_enabled) {
                        
                        #line 405 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 407 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 409 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 410 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 410 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 414 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 415 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 415 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 419 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 423 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 423 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 429 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 430 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 432 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 434 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 436 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 437 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 437 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 441 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 442 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 442 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 449 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 449 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 454 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_5TC(PUSService3 * const self) {
    
    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 51 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    _Bool ack_enabled = 0;

    #line 52 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 52 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 54 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 54 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 54 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 56 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 56 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 57 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 61 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 59 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 63 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 64 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 66 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 68 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 69 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 72 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 74 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 76 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 77 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 77 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 81 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 82 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 82 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 88 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 90 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 92 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 93 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.tc_data.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 95 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (ack_enabled) {
                    
                    #line 97 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 99 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 101 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 102 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 102 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 106 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 107 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 107 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 111 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 114 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 1;

                #line 115 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 117 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 117 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 118 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 122 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 120 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 124 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 125 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 126 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 127 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 129 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (ack_enabled) {
                        
                        #line 131 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 133 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 135 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 136 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 136 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 140 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 141 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 141 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 145 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 150 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 150 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 156 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 157 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 160 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 162 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 164 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 165 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 165 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 169 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 170 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 170 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 183 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_6TC(PUSService3 * const self) {
    
    #line 188 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 188 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 189 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    _Bool ack_enabled = 0;

    #line 190 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 190 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 192 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 192 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 192 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 194 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 194 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 195 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 199 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 197 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 201 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 202 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 204 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 206 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 207 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 210 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 212 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 214 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 215 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 215 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 219 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 220 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 220 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 226 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 228 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 230 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 231 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.tc_data.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 233 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (ack_enabled) {
                    
                    #line 235 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 237 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 239 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 240 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 240 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 244 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 245 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 245 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 249 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 252 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 0;

                #line 253 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 255 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 255 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 256 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 260 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 258 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 262 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 263 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 264 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 265 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.tc_data.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 267 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (ack_enabled) {
                        
                        #line 269 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 271 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 273 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 274 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 274 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 278 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 279 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 279 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 283 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 287 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 287 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 293 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 294 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 297 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 299 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 301 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 302 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 302 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 306 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 307 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 307 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 314 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 314 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 319 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PS3TCData PUSService3__get_TC_params(const PUSService3 * const self,
                                     TCHandlerT * const tc_handler,
                                     uint8_t * const subtype,
                                     MyResult * const result) {
    
    #line 501 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PS3TCData tc_data;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.N = 0U;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.SID = 0U;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.collection_interval = 0U;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.flags_ack = 0U;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_id = 0U;
    #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.tc_num_bytes = 0U;

    #line 513 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 514 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 515 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 516 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 517 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 518 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.SID);

    #line 520 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (*subtype == 31U) {
        
        #line 522 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data.collection_interval);

    }

    #line 527 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService3__manage_error_in_acceptance(const PUSService3 * const self) {
    
    #line 574 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 574 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 575 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 575 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 577 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 577 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 577 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 579 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 579 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 580 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 584 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 582 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 586 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 587 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 589 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 590 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                         current_obt, &result);

        #line 593 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 595 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 597 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 598 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 598 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 602 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 603 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 603 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 608 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 608 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 612 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__manage_short_pack_length_error(const PUSService3 * const self) {
    
    #line 533 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 533 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 534 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 534 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 536 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 536 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 536 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 538 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 538 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 539 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 543 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 541 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 545 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 546 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 548 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 549 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &result);

        #line 551 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 553 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 555 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 556 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 556 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 560 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 561 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 561 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 565 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 565 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 569 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__manage_tm_limit_app_data_reached(const PUSService3 * const self) {
    
    #line 617 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 617 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 618 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 618 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 620 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 620 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 620 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 622 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 622 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 623 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 627 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 625 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 629 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 630 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 632 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 633 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                             current_obt, &result);

        #line 636 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 638 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 640 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 641 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 641 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 645 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 646 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 646 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 651 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 651 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 655 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

void PUSService3__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 661 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t subtype = 0U;

    #line 663 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 667 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 669 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            MyResult result;
            #line 669 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            result.__variant = MyResult__Ok;

            #line 670 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data = PUSService3__get_TC_params(self,
                                                                                 tc_handler,
                                                                                 &subtype,
                                                                                 &result);

            #line 672 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 673 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 673 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 675 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 679 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 681 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 5U) {
                
                #line 683 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_5TC(self);

            } else
            #line 685 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 6U) {
                
                #line 687 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_6TC(self);

            } else
            #line 689 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 31U) {
                
                #line 691 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_31TC(self);

            } else
            {
                
                #line 695 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 695 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 700 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 665 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 702 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 704 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 707 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_error_in_acceptance(self);

            } else
            #line 709 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 712 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_tm_limit_app_data_reached(self);

            } else
            #line 714 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 716 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 724 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 665 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 726 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).__variant = Failure;
            #line 726 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 727 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 736 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 738 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 741 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService3__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService3__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService3__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService3__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService3__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

void PUSService3__update_params(void * const __this) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 803 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 5U; i = i + 1U) {
        
        #line 805 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint32_t random_noise = (uint32_t)(rand_r(&self->random_seed) % 11U) - 5U;

        #line 806 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint32_t data = 0U;

        #line 808 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        data = atomic_load(&self->system_data_pool_u32[i]);

        #line 809 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        data = data + random_noise;

        #line 811 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        atomic_store(&self->system_data_pool_u32[i], data);

    }

    #line 814 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__update_params__mutex_lock(void * const __this) {
    
    PUSService3 * self = (PUSService3 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService3__update_params(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService3__update_params__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService3__update_params(__this);
    __termina_task__unlock(lock);

}

void PUSService3__update_params__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService3__update_params(__this);
    __termina_event__unlock(lock);

}
