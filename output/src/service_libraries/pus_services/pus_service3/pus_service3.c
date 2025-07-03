
#include "service_libraries/pus_services/pus_service3/pus_service3.h"

void PUSService3__do_hk(const __termina_event_t * const __ev,
                        void * const __this,
                        __status_int32_t * const action_status) {
    
    #line 566 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PUSService3 * self = (PUSService3 *)__this;

    #line 566 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 568 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __status_int32_t do_hk_status;
    #line 568 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    do_hk_status.__variant = Success;

    #line 570 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U;
         i < 8U && (*action_status).__variant == Success;
         i = i + 1U) {
        
        #line 572 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            #line 574 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->hk_config_table[__termina_array__index(8U,
                                                         i)].interval_control = self->hk_config_table[__termina_array__index(8U,
                                                                                                                             i)].interval_control + 1U;

            #line 576 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control >= self->hk_config_table[__termina_array__index(8U,
                                                                                                                                  i)].interval) {
                
                #line 578 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             i)].interval_control = 0U;

                #line 580 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler;
                #line 580 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler.__variant = None;

                #line 581 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler);

                #line 585 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler.__variant == Some) {
                    
                    #line 583 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    #line 587 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count = 0U;

                    #line 588 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count);

                    #line 591 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    startup_tm((TMHandlerT *)b_tm_handler.data);

                    #line 592 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    do_hk_status = append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                                            self->hk_config_table[__termina_array__index(8U,
                                                                                                         i)].SID);

                    #line 594 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t PID = 0U;

                    #line 595 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint32_t u32_SDP_value = 0U;

                    #line 596 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint8_t u8_SDP_value = 0U;

                    #line 598 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    for (size_t j = 0U;
                         j < 16U
                         && (j < (size_t)self->hk_config_table[__termina_array__index(8U,
                                                                                      i)].num_params
                             && do_hk_status.__variant == Success);
                         j = j + 1U) {
                        
                        #line 600 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        PID = self->hk_config_table[__termina_array__index(8U,
                                                                           i)].params_def[__termina_array__index(16U,
                                                                                                                 j)];

                        #line 601 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

                        #line 604 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (item_type.__variant == DataPoolItemType__u8_t) {
                            
                            #line 605 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

                            #line 606 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            do_hk_status = append_u8_appdata_field((TMHandlerT *)b_tm_handler.data,
                                                                   u8_SDP_value);

                        } else
                        #line 608 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 609 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

                            #line 610 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            do_hk_status = append_u32_appdata_field((TMHandlerT *)b_tm_handler.data,
                                                                    u32_SDP_value);

                        } else
                        {
                            
                            #line 613 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            do_hk_status.__variant = Failure;
                            #line 613 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            do_hk_status.Failure.__0 = SDP_ITEM_TYPE_ERROR;

                        }

                    }

                    #line 619 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    MissionObt current_obt;
                    #line 619 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    current_obt.finetime = 0U;
                    #line 619 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    current_obt.seconds = 0U;

                    #line 620 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 622 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (do_hk_status.__variant == Success) {
                        
                        #line 623 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        close_tm((TMHandlerT *)b_tm_handler.data, 3U, 25U,
                                 tm_count, current_obt);

                        #line 624 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &do_hk_status);

                    } else
                    {
                        
                        #line 628 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->pus_service_5.build_and_tx_tm_5_2(__ev,
                                                                self->pus_service_5.__that,
                                                                &do_hk_status);

                        #line 629 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 635 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).__variant = Failure;
                    #line 635 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    #line 643 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 643 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

IndexFound PUSService3__get_SIDindex(const __termina_event_t * const __ev,
                                     const PUSService3 * const self) {
    
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

__status_int32_t PUSService3__exec3_31TC(const __termina_event_t * const __ev,
                                         PUSService3 * const self) {
    
    #line 293 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    _Bool ack_enabled = 0;

    #line 294 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __status_int32_t status;
    #line 294 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    status.__variant = Success;

    #line 296 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 296 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 296 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 298 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 298 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 299 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 303 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 301 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 305 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 306 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 308 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 310 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 311 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 314 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 316 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 320 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 326 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev,
                                                                              self);

            #line 328 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 330 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 331 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.tc_data.flags_ack,
                                      current_obt, &ack_enabled);

                #line 333 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (ack_enabled) {
                    
                    #line 335 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (status.__variant == Success) {
                        
                        #line 337 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 341 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 346 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 349 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                #line 350 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 352 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 352 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 353 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 357 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 355 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 359 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 360 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 362 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 363 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 365 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (ack_enabled) {
                        
                        #line 367 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (status.__variant == Success) {
                            
                            #line 369 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 373 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 378 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 382 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status.__variant = Failure;
                    #line 382 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 388 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 389 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.tc_data.packet_id,
                                                    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.tc_data.SID,
                                                    current_obt);

                #line 391 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (status.__variant == Success) {
                    
                    #line 393 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 397 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 405 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        status.__variant = Failure;
        #line 405 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 410 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return status;

}

__status_int32_t PUSService3__exec3_5TC(const __termina_event_t * const __ev,
                                        PUSService3 * const self) {
    
    #line 50 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    _Bool ack_enabled = 0;

    #line 51 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __status_int32_t status;
    #line 51 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    status.__variant = Success;

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
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 60 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 58 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 62 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 63 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 65 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 67 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 68 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 71 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 73 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 77 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 83 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev,
                                                                              self);

            #line 85 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 87 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 88 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.tc_data.flags_ack,
                                      current_obt, &ack_enabled);

                #line 90 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (ack_enabled) {
                    
                    #line 92 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (status.__variant == Success) {
                        
                        #line 94 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 98 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 103 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

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
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 114 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 112 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 116 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 117 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 118 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 119 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 121 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (ack_enabled) {
                        
                        #line 123 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (status.__variant == Success) {
                            
                            #line 125 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 129 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 133 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 138 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status.__variant = Failure;
                    #line 138 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 144 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 145 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.tc_data.packet_id,
                                                    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.tc_data.SID,
                                                    current_obt);

                #line 148 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (status.__variant == Success) {
                    
                    #line 150 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 154 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 163 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        status.__variant = Failure;
        #line 163 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 168 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return status;

}

__status_int32_t PUSService3__exec3_6TC(const __termina_event_t * const __ev,
                                        PUSService3 * const self) {
    
    #line 173 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    _Bool ack_enabled = 0;

    #line 174 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __status_int32_t status;
    #line 174 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    status.__variant = Success;

    #line 176 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    MissionObt current_obt;
    #line 176 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.finetime = 0U;
    #line 176 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    current_obt.seconds = 0U;

    #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __option_box_t tm_handler;
    #line 178 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    tm_handler.__variant = None;

    #line 179 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 183 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (tm_handler.__variant == Some) {
        
        #line 181 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 185 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint16_t tm_count = 0U;

        #line 186 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 188 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.N != 1U) {
            
            #line 190 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 191 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.tc_data.packet_id,
                                                         self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.tc_data.N,
                                                         current_obt);

            #line 194 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 196 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 200 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 207 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev,
                                                                              self);

            #line 209 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (self->exec_tc_req_status_update.index.found) {
                
                #line 211 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 212 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.tc_data.packet_id,
                                      self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.tc_data.flags_ack,
                                      current_obt, &ack_enabled);

                #line 214 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (ack_enabled) {
                    
                    #line 216 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (status.__variant == Success) {
                        
                        #line 218 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 222 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 226 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 229 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].enabled = 0;

                #line 230 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U,
                                                             self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 232 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __option_box_t tm_handler2;
                #line 232 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                tm_handler2.__variant = None;

                #line 233 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 237 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 235 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 239 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    uint16_t tm_count2 = 0U;

                    #line 240 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 241 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 242 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.tc_data.packet_id,
                                          self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.tc_data.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 244 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    if (ack_enabled) {
                        
                        #line 246 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        if (status.__variant == Success) {
                            
                            #line 248 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 251 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 255 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 259 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status.__variant = Failure;
                    #line 259 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 265 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 266 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = build_tm_1_4_SID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.tc_data.packet_id,
                                                    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.tc_data.SID,
                                                    current_obt);

                #line 269 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (status.__variant == Success) {
                    
                    #line 271 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 275 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 283 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        status.__variant = Failure;
        #line 283 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 288 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return status;

}

void PUSService3__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 415 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PUSService3 * self = (PUSService3 *)__this;

    #line 415 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 417 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __status_int32_t status;
    #line 417 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    status.__variant = Success;

    #line 418 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 420 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 424 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 426 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

            #line 427 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 428 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 429 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 430 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.tc_data.N);

            #line 431 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 432 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.tc_data.SID);

            }

            #line 436 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 31U && status.__variant == Success) {
                
                #line 438 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.tc_data.collection_interval);

            }

            #line 442 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 444 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 448 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status.__variant = Failure;
                #line 448 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 449 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 454 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 456 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 458 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 5U) {
                
                #line 460 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = PUSService3__exec3_5TC(__ev, self);

            } else
            #line 462 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 6U) {
                
                #line 464 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = PUSService3__exec3_6TC(__ev, self);

            } else
            #line 466 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (subtype == 31U) {
                
                #line 468 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status = PUSService3__exec3_31TC(__ev, self);

            } else
            {
                
                #line 472 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status.__variant = Failure;
                #line 472 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 486 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 488 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 484 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        int32_t error_code = status.Failure.__0;

        #line 493 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 495 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).__variant = Success;

            #line 497 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            __option_box_t tm_handler;
            #line 497 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            tm_handler.__variant = None;

            #line 498 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 502 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            if (tm_handler.__variant == Some) {
                
                #line 500 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 504 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                uint16_t tm_count = 0U;

                #line 505 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                MissionObt current_obt;
                #line 505 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                current_obt.finetime = 0U;
                #line 505 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                current_obt.seconds = 0U;

                #line 507 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 508 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 510 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 512 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.tc_data.packet_id,
                                                              self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 515 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 517 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.tc_data.packet_id,
                                                                  self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 520 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 522 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.tc_data.packet_id,
                                                            self->exec_tc_req_status_update.tc_data.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_data.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 532 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                if (status.__variant == Success) {
                    
                    #line 534 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 538 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 544 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status.__variant = Failure;
                #line 544 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 551 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).__variant = Failure;
            #line 551 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 557 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 560 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 560 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}

void PUSService3__update_params(const __termina_event_t * const __ev,
                                void * const __this) {
    
    #line 646 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    PUSService3 * self = (PUSService3 *)__this;

    #line 646 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 648 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    for (size_t i = 0U; i < 5U; i = i + 1U) {
        
        #line 650 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint32_t random_noise = (uint32_t)(rand_r(&self->random_seed) % 11U) - 5U;

        #line 651 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        uint32_t data = 0U;

        #line 653 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        data = atomic_load(&self->system_data_pool_u32[i]);

        #line 654 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        data = data + random_noise;

        #line 656 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
        atomic_store(&self->system_data_pool_u32[i], data);

    }

    #line 659 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 659 "src/service_libraries/pus_services/pus_service3/pus_service3.fin"
    return;

}
