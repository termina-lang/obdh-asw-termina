
#include "service_libraries/pus_services/pus_service3/pus_service3.h"

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMHandlerT * const p_tm_handler,
                                uint16_t tm_seq_counter, size_t index,
                                MyResult * const result) {
    
    startup_tm(p_tm_handler);

    append_u16_appdata_field(p_tm_handler,
                             self->hk_config_table[__termina_array__index(8U,
                                                                          index)].SID,
                             result);

    uint16_t PID = 0U;

    uint32_t u32_SDP_value = 0U;

    uint8_t u8_SDP_value = 0U;

    for (size_t j = 0U; j < 16U && j < (size_t)self->hk_config_table[__termina_array__index(8U,
                                                                                            index)].num_params; j = j + 1U) {
        
        PID = self->hk_config_table[__termina_array__index(8U,
                                                           index)].params_def[__termina_array__index(16U,
                                                                                                     j)];

        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

            append_u8_appdata_field(p_tm_handler, u8_SDP_value, result);

        } else if (item_type.__variant == DataPoolItemType__u32_t) {
            
            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

            append_u32_appdata_field(p_tm_handler, u32_SDP_value, result);

        } else {
            
            (*result).__variant = MyResult__Error;

        }

    }

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    close_tm(p_tm_handler, 3U, 25U, tm_seq_counter, current_obt);

    return;

}

void PUSService3__do_hk(void * const __this,
                        __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    MyResult result;
    result.__variant = MyResult__Ok;

    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            self->hk_config_table[__termina_array__index(8U,
                                                         i)].interval_control = self->hk_config_table[__termina_array__index(8U,
                                                                                                                             i)].interval_control + 1U;

            if (self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control >= self->hk_config_table[__termina_array__index(8U,
                                                                                                                                  i)].interval) {
                
                self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control = 0U;

                __option_box_t tm_handler;
                tm_handler.__variant = None;

                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler);

                if (tm_handler.__variant == Some) {
                    
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    uint16_t tm_count = 0U;

                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count);

                    PUSService3__build_tm_3_25(self,
                                               (TMHandlerT *)b_tm_handler.data,
                                               tm_count, i, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            (*action_status).__variant = Failure;
                            (*action_status).Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->pus_service_5.build_and_tx_tm_5_2(self->pus_service_5.__that,
                                                                action_status);

                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else {
                    
                    (*action_status).__variant = Failure;
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

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
    
    IndexFound index_found;
    index_found.found = 0;
    index_found.index = 0U;

    for (size_t i = 0U; i < 8U && index_found.found == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status_update.tc_data.SID == self->hk_config_table[__termina_array__index(8U,
                                                                                                        i)].SID) {
            
            index_found.found = 1;

            index_found.index = i;

        }

    }

    return index_found;

}

PSExecTCReqStatus PUSService3__exec3_31TC(PUSService3 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            if (self->exec_tc_req_status_update.index.found) {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_5TC(PUSService3 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            if (self->exec_tc_req_status_update.index.found) {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 1;

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService3__exec3_6TC(PUSService3 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.tc_data.packet_id,
                                                self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                                self->exec_tc_req_status_update.tc_data.N,
                                                current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(self);

            if (self->exec_tc_req_status_update.index.found) {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 0;

                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                __option_box_t tm_handler2;
                tm_handler2.__variant = None;

                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                if (tm_handler2.__variant == Some) {
                    
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    uint16_t tm_count2 = 0U;

                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 current_obt, &result);

                    if (result.__variant == MyResult__Ok) {
                        
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        if (result.__variant == MyResult__Error) {
                            
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else {
                        
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        next_status.__variant = PSExecTCReqStatus__Error;
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else {
                
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.tc_data.packet_id,
                                           self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                           self->exec_tc_req_status_update.tc_data.SID,
                                           current_obt, &result);

                if (result.__variant == MyResult__Ok) {
                    
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    if (result.__variant == MyResult__Error) {
                        
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else {
                    
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    next_status.__variant = PSExecTCReqStatus__Error;
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PS3TCData PUSService3__get_TC_params(const PUSService3 * const self,
                                     TCHandlerT * const tc_handler,
                                     uint8_t * const subtype,
                                     MyResult * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS3TCData tc_data;
    tc_data.N = 0U;
    tc_data.SID = 0U;
    tc_data.collection_interval = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_num_bytes = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.SID);

    if (*subtype == 31U) {
        
        *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                  &tc_data.collection_interval);

    }

    return tc_data;

}

PSExecTCReqStatus PUSService3__manage_error_in_acceptance(const PUSService3 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                         self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                         current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService3__manage_short_pack_length_error(const PUSService3 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.tc_data.packet_id,
                                       self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                       current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PSExecTCReqStatus PUSService3__manage_tm_limit_app_data_reached(const PUSService3 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.tc_data.packet_id,
                                             self->exec_tc_req_status_update.tc_data.packet_error_ctrl,
                                             current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

void PUSService3__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService3 * self = (PUSService3 *)__this;

    uint8_t subtype = 0U;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            MyResult result;
            result.__variant = MyResult__Ok;

            self->exec_tc_req_status_update.tc_data = PUSService3__get_TC_params(self,
                                                                                 tc_handler,
                                                                                 &subtype,
                                                                                 &result);

            if (result.__variant == MyResult__Error) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 5U) {
                
                self->exec_tc_req_status = PUSService3__exec3_5TC(self);

            } else if (subtype == 6U) {
                
                self->exec_tc_req_status = PUSService3__exec3_6TC(self);

            } else if (subtype == 31U) {
                
                self->exec_tc_req_status = PUSService3__exec3_31TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (error_code == ACCEPTANCE_ERROR) {
                
                self->exec_tc_req_status = PUSService3__manage_error_in_acceptance(self);

            } else if (error_code == BUILD_TM_ERROR) {
                
                self->exec_tc_req_status = PUSService3__manage_tm_limit_app_data_reached(self);

            } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                self->exec_tc_req_status = PUSService3__manage_short_pack_length_error(self);

            } else {
                

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = failure_code;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

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
