
#include "service_libraries/pus_services/pus_service3/pus_service3.h"

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, size_t index,
                                MyResult * const result) {
    
    #line 421 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    startup_tm(p_tm_handler);

    #line 422 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    append_u16_appdata_field(p_tm_handler,
                             self->hk_config_table[__termina_array__index(8U,
                                                                          index)].SID,
                             result);

    #line 424 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint16_t PID = 0U;

    #line 425 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint32_t u32_SDP_value = 0U;

    #line 426 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t u8_SDP_value = 0U;

    #line 428 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t j = 0U; j < 16U && j < (size_t)self->hk_config_table[__termina_array__index(8U,
                                                                                            index)].num_params; j = j + 1U) {
        
        #line 430 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        PID = self->hk_config_table[__termina_array__index(8U,
                                                           index)].params_def[__termina_array__index(16U,
                                                                                                     j)];

        #line 431 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

        #line 434 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            #line 435 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

            #line 436 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            append_u8_appdata_field(p_tm_handler, u8_SDP_value, result);

        } else
        #line 438 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (item_type.__variant == DataPoolItemType__u32_t) {
            
            #line 439 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

            #line 440 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            append_u32_appdata_field(p_tm_handler, u32_SDP_value, result);

        } else
        {
            
            #line 443 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*result).__variant = MyResult__Error;

        }

    }

    #line 449 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 449 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 449 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 450 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 452 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    close_tm(p_tm_handler, 3U, 25U, tm_seq_counter, current_obt);

    #line 455 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__do_hk(void * const __this,
                        __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 706 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 706 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 708 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        #line 710 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            #line 712 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->hk_config_table[__termina_array__index(8U,
                                                         i)].interval_control = self->hk_config_table[__termina_array__index(8U,
                                                                                                                             i)].interval_control + 1U;

            #line 714 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control >= self->hk_config_table[__termina_array__index(8U,
                                                                                                                                  i)].interval) {
                
                #line 716 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control = 0U;

                #line 718 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler;
                #line 718 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler.__variant = None;

                #line 719 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler);

                #line 723 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler.__variant == Some) {
                    
                    #line 721 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    #line 725 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count = 0U;

                    #line 726 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count);

                    #line 728 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    PUSService3__build_tm_3_25(self,
                                               (TMHandlerT *)b_tm_handler.data,
                                               tm_count, i, &result);

                    #line 730 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 732 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 734 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 735 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            (*action_status).__variant = Failure;
                            #line 735 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            (*action_status).Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 740 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->pus_service_5.build_and_tx_tm_5_2(self->pus_service_5.__that,
                                                                action_status);

                        #line 741 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 747 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).__variant = Failure;
                    #line 747 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    #line 755 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
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
    
    #line 34 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    IndexFound index_found;
    #line 34 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    index_found.found = 0;
    #line 34 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    index_found.index = 0U;

    #line 36 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 8U && index_found.found == 0; i = i + 1U) {
        
        #line 38 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.SID == self->hk_config_table[__termina_array__index(8U,
                                                                                                        i)].SID) {
            
            #line 40 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            index_found.found = 1;

            #line 41 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            index_found.index = i;

        }

    }

    #line 44 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return index_found;

}

PSExecTCReqStatus PUSService3__exec3_31TC(PUSService3 * const self) {
    
    #line 297 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 297 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 298 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 298 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 300 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 300 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 300 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 302 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 302 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 303 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 307 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 305 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 309 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 310 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 312 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 314 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 315 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 318 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 320 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 322 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 323 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 323 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 327 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 333 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 335 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 337 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 338 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 340 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 342 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 344 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 345 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 345 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 349 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 350 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 350 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 353 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                #line 354 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 356 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 356 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 357 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 361 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 359 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 363 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 364 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 366 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 367 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 369 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 371 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 373 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 374 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 374 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 378 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 379 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 379 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 383 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 383 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 389 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 390 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 392 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 394 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 396 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 397 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 397 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 401 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 402 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 402 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 409 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 409 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 414 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_5TC(PUSService3 * const self) {
    
    #line 49 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 49 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 52 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 52 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 52 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 54 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 54 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 55 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 59 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 57 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 61 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 62 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 64 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 66 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 67 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 70 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 72 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 74 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 75 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 75 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 79 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 80 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 80 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 86 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 88 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 90 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 91 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 93 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 95 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 97 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 98 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 98 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 102 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 103 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 103 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 106 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 1;

                #line 107 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 109 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 109 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 110 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 114 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 112 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 116 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 117 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 118 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 119 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 121 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 123 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 125 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 126 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 126 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 130 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 131 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 131 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 136 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 136 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 142 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 143 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 146 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 148 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 150 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 151 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 151 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 155 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 156 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 156 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 164 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 164 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 169 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_6TC(PUSService3 * const self) {
    
    #line 174 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 174 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 175 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 175 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 177 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 177 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 177 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 179 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 179 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 180 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 184 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 182 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 186 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 187 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 189 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 191 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 192 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 195 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 197 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 199 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 200 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 200 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 204 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 205 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 205 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 211 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 213 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 215 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 216 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 218 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 220 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 222 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 223 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 223 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 227 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 228 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 228 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 231 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 0;

                #line 232 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 234 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 234 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 235 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 239 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 237 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 241 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 242 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 243 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 244 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 246 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 248 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 250 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 251 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 251 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 255 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 256 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 256 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 260 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 260 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 266 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 267 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 270 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 272 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 274 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 275 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 275 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 279 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 280 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 280 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 287 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 287 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 292 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PS3TCData PUSService3__get_TC_params(const PUSService3 * const self,
                                     TCHandlerT * const tc_handler,
                                     uint8_t * const subtype,
                                     MyResult * const result) {
    
    #line 461 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PS3TCData tc_data;
    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.N = 0U;
    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.SID = 0U;
    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.collection_interval = 0U;
    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_id = 0U;
    #line 463 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.tc_num_bytes = 0U;

    #line 471 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 472 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 473 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 474 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 475 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.SID);

    #line 477 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (*subtype == 31U) {
        
        #line 479 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data.collection_interval);

    }

    #line 484 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService3__manage_error_in_acceptance(const PUSService3 * const self) {
    
    #line 531 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 531 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 532 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 532 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 534 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 534 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 534 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 536 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 536 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 537 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 541 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 539 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 543 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 544 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 546 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 547 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                         current_obt, &result);

        #line 550 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 552 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 554 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 555 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 555 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 559 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 560 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 560 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
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

PSExecTCReqStatus PUSService3__manage_short_pack_length_error(const PUSService3 * const self) {
    
    #line 490 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 490 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 491 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 491 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 493 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 493 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 493 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 495 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 495 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 496 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 500 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 498 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 502 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 505 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 506 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &result);

        #line 508 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 510 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 512 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 513 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 513 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 517 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 518 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 518 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 522 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 522 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 526 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__manage_tm_limit_app_data_reached(const PUSService3 * const self) {
    
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
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
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

void PUSService3__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 618 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t subtype = 0U;

    #line 620 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 624 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 626 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            MyResult result;
            #line 626 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            result.__variant = MyResult__Ok;

            #line 627 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data = PUSService3__get_TC_params(self,
                                                                                 tc_handler,
                                                                                 &subtype,
                                                                                 &result);

            #line 629 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 630 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 630 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 632 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 636 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 638 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 5U) {
                
                #line 640 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_5TC(self);

            } else
            #line 642 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 6U) {
                
                #line 644 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_6TC(self);

            } else
            #line 646 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 31U) {
                
                #line 648 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_31TC(self);

            } else
            {
                
                #line 652 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 652 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 657 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 622 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 659 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 661 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 664 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_error_in_acceptance(self);

            } else
            #line 666 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 669 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_tm_limit_app_data_reached(self);

            } else
            #line 671 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 673 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 681 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 622 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 683 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).__variant = Failure;
            #line 683 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 684 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 693 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 695 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 698 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
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
