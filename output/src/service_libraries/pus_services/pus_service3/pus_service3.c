
#include "service_libraries/pus_services/pus_service3/pus_service3.h"

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, size_t index,
                                MyResult * const result) {
    
    #line 422 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    startup_tm(p_tm_handler);

    #line 423 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    append_u16_appdata_field(p_tm_handler,
                             self->hk_config_table[__termina_array__index(8U,
                                                                          index)].SID,
                             result);

    #line 425 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint16_t PID = 0U;

    #line 426 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint32_t u32_SDP_value = 0U;

    #line 427 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t u8_SDP_value = 0U;

    #line 429 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t j = 0U; j < 16U && j < (size_t)self->hk_config_table[__termina_array__index(8U,
                                                                                            index)].num_params; j = j + 1U) {
        
        #line 431 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        PID = self->hk_config_table[__termina_array__index(8U,
                                                           index)].params_def[__termina_array__index(16U,
                                                                                                     j)];

        #line 432 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

        #line 435 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            #line 436 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

            #line 437 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            append_u8_appdata_field(p_tm_handler, u8_SDP_value, result);

        } else
        #line 439 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (item_type.__variant == DataPoolItemType__u32_t) {
            
            #line 440 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

            #line 441 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            append_u32_appdata_field(p_tm_handler, u32_SDP_value, result);

        } else
        {
            
            #line 444 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*result).__variant = MyResult__Error;

        }

    }

    #line 450 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 450 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 450 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 451 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 453 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    close_tm(p_tm_handler, 3U, 25U, tm_seq_counter, current_obt);

    #line 456 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__do_hk(void * const __this,
                        __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 707 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 707 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 709 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        #line 711 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            #line 713 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->hk_config_table[__termina_array__index(8U,
                                                         i)].interval_control = self->hk_config_table[__termina_array__index(8U,
                                                                                                                             i)].interval_control + 1U;

            #line 715 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control >= self->hk_config_table[__termina_array__index(8U,
                                                                                                                                  i)].interval) {
                
                #line 717 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control = 0U;

                #line 719 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler;
                #line 719 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler.__variant = None;

                #line 720 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler);

                #line 724 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler.__variant == Some) {
                    
                    #line 722 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    #line 726 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count = 0U;

                    #line 727 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count);

                    #line 729 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    PUSService3__build_tm_3_25(self,
                                               (TMHandlerT *)b_tm_handler.data,
                                               tm_count, i, &result);

                    #line 731 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 733 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 735 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 736 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            (*action_status).__variant = Failure;
                            #line 736 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            (*action_status).Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 741 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->pus_service_5.build_and_tx_tm_5_2(self->pus_service_5.__that,
                                                                action_status);

                        #line 742 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 748 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).__variant = Failure;
                    #line 748 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    #line 756 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
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
    
    #line 298 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 298 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 299 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 299 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 301 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 301 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 301 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 303 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 303 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 304 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 308 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 306 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 310 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 311 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 313 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 315 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 316 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 319 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 321 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 323 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 324 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 324 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 329 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 329 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 334 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 336 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 338 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 339 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 341 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 343 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 345 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 346 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 346 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 350 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 351 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 351 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 354 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                #line 355 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 357 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 357 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 358 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 362 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 360 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 364 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 365 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 367 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 368 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 370 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 372 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

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
                                                     b_tm_handler2);

                        #line 380 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 380 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 384 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 384 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 390 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 391 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 393 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 395 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 397 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 398 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 398 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 402 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 403 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 403 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 410 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 410 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 415 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_5TC(PUSService3 * const self) {
    
    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 51 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 51 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 53 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 53 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 53 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 55 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 55 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 56 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 60 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 58 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 62 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 63 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 65 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 67 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 68 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 71 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 73 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 75 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 76 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 76 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 80 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 81 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 81 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 87 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 89 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 91 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 92 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 94 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 96 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 98 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 99 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 99 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 103 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 104 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 104 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 107 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 1;

                #line 108 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 110 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 110 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 111 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 115 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 113 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 117 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 118 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 119 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 120 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 122 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 124 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 126 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 127 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 127 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 131 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 132 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 132 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 137 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 137 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 143 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 144 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 147 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 149 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 151 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 152 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 152 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 156 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 157 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 157 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 165 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 165 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 170 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_6TC(PUSService3 * const self) {
    
    #line 175 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 175 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 176 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 176 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 180 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 180 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 181 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 185 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 183 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 187 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 188 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 190 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 192 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 193 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            #line 196 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 198 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 200 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 201 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 201 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 205 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 206 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 206 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 212 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            #line 214 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 216 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 217 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 219 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 221 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 223 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 224 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 224 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 228 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 229 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 229 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 232 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 0;

                #line 233 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 235 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 235 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 236 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 240 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 238 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 242 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 243 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 244 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 245 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    #line 247 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 249 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 251 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 252 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 252 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 256 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 257 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 257 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 261 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 261 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 267 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 268 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                #line 271 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 273 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 275 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 276 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 276 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 280 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 281 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 281 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 288 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 288 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 293 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PS3TCData PUSService3__get_TC_params(const PUSService3 * const self,
                                     TCHandlerT * const tc_handler,
                                     uint8_t * const subtype,
                                     MyResult * const result) {
    
    #line 462 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PS3TCData tc_data;
    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.N = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.SID = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.collection_interval = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_id = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.tc_num_bytes = 0U;

    #line 472 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 473 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 474 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 475 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 476 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.SID);

    #line 478 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (*subtype == 31U) {
        
        #line 480 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data.collection_interval);

    }

    #line 485 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService3__manage_error_in_acceptance(const PUSService3 * const self) {
    
    #line 532 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 532 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 533 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 533 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 535 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 535 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 535 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 537 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 537 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 538 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 542 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 540 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 544 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 545 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 547 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 548 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
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
        
        #line 566 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 566 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 570 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__manage_short_pack_length_error(const PUSService3 * const self) {
    
    #line 491 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 491 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 492 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 492 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 494 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 494 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 494 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 496 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 496 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 497 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 501 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 499 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 503 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 504 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 506 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 507 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &result);

        #line 509 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 511 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 513 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 514 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 514 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 518 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 519 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 519 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 523 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 523 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 527 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

PSExecTCReqStatus PUSService3__manage_tm_limit_app_data_reached(const PUSService3 * const self) {
    
    #line 575 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PSExecTCReqStatus next_status;
    #line 575 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 576 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MyResult result;
    #line 576 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    result.__variant = MyResult__Ok;

    #line 578 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 578 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 578 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 580 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 580 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 581 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 585 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 583 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 587 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 588 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 590 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 591 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                             current_obt, &result);

        #line 594 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 596 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 598 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 599 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 599 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 603 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 604 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 604 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 609 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 609 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 613 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return next_status;

}

void PUSService3__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    #line 619 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t subtype = 0U;

    #line 621 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 625 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 627 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            MyResult result;
            #line 627 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            result.__variant = MyResult__Ok;

            #line 628 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data = PUSService3__get_TC_params(self,
                                                                                 tc_handler,
                                                                                 &subtype,
                                                                                 &result);

            #line 630 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 631 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 631 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 633 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 637 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 639 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 5U) {
                
                #line 641 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_5TC(self);

            } else
            #line 643 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 6U) {
                
                #line 645 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_6TC(self);

            } else
            #line 647 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 31U) {
                
                #line 649 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__exec3_31TC(self);

            } else
            {
                
                #line 653 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 653 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 658 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 623 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 660 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 662 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 665 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_error_in_acceptance(self);

            } else
            #line 667 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 670 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_tm_limit_app_data_reached(self);

            } else
            #line 672 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 674 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status = PUSService3__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 682 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 623 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 684 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).__variant = Failure;
            #line 684 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 685 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 694 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 696 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 699 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
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

    #line 761 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 5U; i = i + 1U) {
        
        #line 763 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint32_t random_noise = (uint32_t)(rand_r(&self->random_seed) % 11U) - 5U;

        #line 764 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint32_t data = 0U;

        #line 766 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        data = atomic_load(&self->system_data_pool_u32[i]);

        #line 767 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        data = data + random_noise;

        #line 769 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        atomic_store(&self->system_data_pool_u32[i], data);

    }

    #line 772 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
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
