
#include "service_libraries/pus_services/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const __termina_event_t * const __ev,
                                   const PUSService4 * const self,
                                   size_t pid_index) {
    
    #line 503 "src/service_libraries/pus_services/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 504 "src/service_libraries/pus_services/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 505 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 506 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t mean_value = 0U;

    #line 508 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 511 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 512 "src/service_libraries/pus_services/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 513 "src/service_libraries/pus_services/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else
    #line 515 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 516 "src/service_libraries/pus_services/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 517 "src/service_libraries/pus_services/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else
    {
        

    }

    #line 524 "src/service_libraries/pus_services/pus_service4.fin"
    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const __termina_event_t * const __ev,
                                               const PUSService4 * const self,
                                               size_t pid_index) {
    
    #line 419 "src/service_libraries/pus_services/pus_service4.fin"
    _Bool is_higher = 0;

    #line 420 "src/service_libraries/pus_services/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 421 "src/service_libraries/pus_services/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 422 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 424 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 427 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 428 "src/service_libraries/pus_services/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 429 "src/service_libraries/pus_services/pus_service4.fin"
        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].max) {
            
            #line 430 "src/service_libraries/pus_services/pus_service4.fin"
            is_higher = 1;

        }

    } else
    #line 433 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 434 "src/service_libraries/pus_services/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 435 "src/service_libraries/pus_services/pus_service4.fin"
        if (u32_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].max) {
            
            #line 436 "src/service_libraries/pus_services/pus_service4.fin"
            is_higher = 1;

        }

    } else
    {
        

    }

    #line 444 "src/service_libraries/pus_services/pus_service4.fin"
    return is_higher;

}

_Bool PUSService4__SDP_param_lower_than_limit(const __termina_event_t * const __ev,
                                              const PUSService4 * const self,
                                              size_t pid_index) {
    
    #line 450 "src/service_libraries/pus_services/pus_service4.fin"
    _Bool is_lower = 0;

    #line 451 "src/service_libraries/pus_services/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 452 "src/service_libraries/pus_services/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 453 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 455 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 458 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 459 "src/service_libraries/pus_services/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 460 "src/service_libraries/pus_services/pus_service4.fin"
        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].min) {
            
            #line 461 "src/service_libraries/pus_services/pus_service4.fin"
            is_lower = 1;

        }

    } else
    #line 464 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 465 "src/service_libraries/pus_services/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 466 "src/service_libraries/pus_services/pus_service4.fin"
        if (u32_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].min) {
            
            #line 467 "src/service_libraries/pus_services/pus_service4.fin"
            is_lower = 1;

        }

    } else
    {
        

    }

    #line 475 "src/service_libraries/pus_services/pus_service4.fin"
    return is_lower;

}

__status_int32_t PUSService4__get_PID_defined_stats_index(const __termina_event_t * const __ev,
                                                          PUSService4 * const self) {
    
    #line 36 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 36 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Failure;
    #line 36 "src/service_libraries/pus_services/pus_service4.fin"
    status.Failure.__0 = INVALID_PID_ERROR;

    #line 38 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status.__variant == Failure; i = i + 1U) {
        
        #line 40 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->exec_tc_req_status_update.PID == self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                       i)]) {
            
            #line 42 "src/service_libraries/pus_services/pus_service4.fin"
            if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                        i)] == 1) {
                
                #line 44 "src/service_libraries/pus_services/pus_service4.fin"
                if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                    
                    #line 46 "src/service_libraries/pus_services/pus_service4.fin"
                    self->exec_tc_req_status_update.valid_index = i;

                    #line 47 "src/service_libraries/pus_services/pus_service4.fin"
                    status.__variant = Success;

                } else
                {
                    
                    #line 50 "src/service_libraries/pus_services/pus_service4.fin"
                    self->stats_config_table.defined[__termina_array__index(4U,
                                                                            i)] = 0;

                }

            }

        }

    }

    #line 57 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

IndexStatus PUSService4__get_free_index(const __termina_event_t * const __ev,
                                        const PUSService4 * const self) {
    
    #line 62 "src/service_libraries/pus_services/pus_service4.fin"
    IndexStatus id_status;
    #line 62 "src/service_libraries/pus_services/pus_service4.fin"
    id_status.index = 0U;
    #line 62 "src/service_libraries/pus_services/pus_service4.fin"
    id_status.status.__variant = Failure;
    #line 62 "src/service_libraries/pus_services/pus_service4.fin"
    id_status.status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    #line 64 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U;
         i < 4U && id_status.status.__variant == Failure;
         i = i + 1U) {
        
        #line 66 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U, i)] == 0
            || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                              i)]) == 0) {
            
            #line 68 "src/service_libraries/pus_services/pus_service4.fin"
            id_status.index = i;

            #line 69 "src/service_libraries/pus_services/pus_service4.fin"
            id_status.status.__variant = Success;

        }

    }

    #line 72 "src/service_libraries/pus_services/pus_service4.fin"
    return id_status;

}

__status_int32_t PUSService4__add_PID_stats(const __termina_event_t * const __ev,
                                            PUSService4 * const self) {
    
    #line 98 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 98 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Success;

    #line 99 "src/service_libraries/pus_services/pus_service4.fin"
    IndexStatus index_status;
    #line 99 "src/service_libraries/pus_services/pus_service4.fin"
    index_status.index = 0U;
    #line 99 "src/service_libraries/pus_services/pus_service4.fin"
    index_status.status.__variant = Success;

    #line 100 "src/service_libraries/pus_services/pus_service4.fin"
    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    #line 102 "src/service_libraries/pus_services/pus_service4.fin"
    if (status.__variant == Failure) {
        
        #line 104 "src/service_libraries/pus_services/pus_service4.fin"
        index_status = PUSService4__get_free_index(__ev, self);

        #line 105 "src/service_libraries/pus_services/pus_service4.fin"
        self->exec_tc_req_status_update.valid_index = index_status.index;

    }

    #line 108 "src/service_libraries/pus_services/pus_service4.fin"
    if (index_status.status.__variant == Success) {
        
        #line 110 "src/service_libraries/pus_services/pus_service4.fin"
        size_t PID_index = self->exec_tc_req_status_update.valid_index;

        #line 112 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 1;

        #line 113 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.PID[__termina_array__index(4U,
                                                            PID_index)] = self->exec_tc_req_status_update.PID;

        #line 115 "src/service_libraries/pus_services/pus_service4.fin"
        self->param_stats[__termina_array__index(4U, PID_index)].samples = 0U;

        #line 116 "src/service_libraries/pus_services/pus_service4.fin"
        MissionOBT current_obt;
        #line 116 "src/service_libraries/pus_services/pus_service4.fin"
        current_obt.finetime = 0U;
        #line 116 "src/service_libraries/pus_services/pus_service4.fin"
        current_obt.seconds = 0U;

        #line 117 "src/service_libraries/pus_services/pus_service4.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 118 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.start_time[__termina_array__index(4U,
                                                                   PID_index)] = current_obt;

        #line 119 "src/service_libraries/pus_services/pus_service4.fin"
        status.__variant = Success;

    } else
    {
        
        #line 123 "src/service_libraries/pus_services/pus_service4.fin"
        status.__variant = Failure;
        #line 123 "src/service_libraries/pus_services/pus_service4.fin"
        status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    }

    #line 126 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__delete_PID_stats(const __termina_event_t * const __ev,
                                               PUSService4 * const self) {
    
    #line 131 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 131 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Success;

    #line 132 "src/service_libraries/pus_services/pus_service4.fin"
    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    #line 134 "src/service_libraries/pus_services/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 135 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                self->exec_tc_req_status_update.valid_index)] = 0;

    }

    #line 138 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

void PUSService4__delete_all_stats(const __termina_event_t * const __ev,
                                   PUSService4 * const self) {
    
    #line 144 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 145 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

    }

    #line 148 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}

__status_int32_t PUSService4__exec4_1TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    #line 155 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 155 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Success;

    #line 157 "src/service_libraries/pus_services/pus_service4.fin"
    self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      &status);

    #line 163 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status.__variant == Success; i = i + 1U) {
        
        #line 165 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            #line 167 "src/service_libraries/pus_services/pus_service4.fin"
            __option_box_t tm_handler;
            #line 167 "src/service_libraries/pus_services/pus_service4.fin"
            tm_handler.__variant = None;

            #line 168 "src/service_libraries/pus_services/pus_service4.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 172 "src/service_libraries/pus_services/pus_service4.fin"
            if (tm_handler.__variant == Some) {
                
                #line 170 "src/service_libraries/pus_services/pus_service4.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 174 "src/service_libraries/pus_services/pus_service4.fin"
                MissionOBT current_obt;
                #line 174 "src/service_libraries/pus_services/pus_service4.fin"
                current_obt.finetime = 0U;
                #line 174 "src/service_libraries/pus_services/pus_service4.fin"
                current_obt.seconds = 0U;

                #line 175 "src/service_libraries/pus_services/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 177 "src/service_libraries/pus_services/pus_service4.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 178 "src/service_libraries/pus_services/pus_service4.fin"
                self->obt_manager.get_current_obt(__ev,
                                                  self->obt_manager.__that,
                                                  &current_obt);

                #line 180 "src/service_libraries/pus_services/pus_service4.fin"
                status = build_tm_4_2((TMHandler *)b_tm_handler.data, tm_count,
                                      i, self->exec_tc_req_status_update.N,
                                      &self->stats_config_table,
                                      self->param_stats, current_obt);

                #line 182 "src/service_libraries/pus_services/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 184 "src/service_libraries/pus_services/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 188 "src/service_libraries/pus_services/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 193 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                #line 194 "src/service_libraries/pus_services/pus_service4.fin"
                MissionOBT current_obt_update;
                #line 194 "src/service_libraries/pus_services/pus_service4.fin"
                current_obt_update.finetime = 0U;
                #line 194 "src/service_libraries/pus_services/pus_service4.fin"
                current_obt_update.seconds = 0U;

                #line 195 "src/service_libraries/pus_services/pus_service4.fin"
                self->obt_manager.get_current_obt(__ev,
                                                  self->obt_manager.__that,
                                                  &current_obt_update);

                #line 196 "src/service_libraries/pus_services/pus_service4.fin"
                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else
            {
                
                #line 199 "src/service_libraries/pus_services/pus_service4.fin"
                status.__variant = Failure;
                #line 199 "src/service_libraries/pus_services/pus_service4.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 205 "src/service_libraries/pus_services/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 207 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

    } else
    {
        

    }

    #line 220 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__exec4_6TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    #line 226 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 226 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Success;

    #line 228 "src/service_libraries/pus_services/pus_service4.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 230 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 236 "src/service_libraries/pus_services/pus_service4.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID) == 0) {
        
        #line 238 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(__ev,
                                                      self->pus_service_1.__that,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      &status);

    } else
    {
        
        #line 246 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 252 "src/service_libraries/pus_services/pus_service4.fin"
        if (status.__variant == Success) {
            
            #line 253 "src/service_libraries/pus_services/pus_service4.fin"
            status = PUSService4__add_PID_stats(__ev, self);

        }

        #line 256 "src/service_libraries/pus_services/pus_service4.fin"
        if (status.__variant == Success) {
            
            #line 258 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              &status);

        } else
        {
            
            #line 266 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_8_not_free_stats_config(__ev,
                                                                  self->pus_service_1.__that,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  self->exec_tc_req_status_update.PID,
                                                                  &status);

        }

    }

    #line 276 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__exec4_7TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    #line 282 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 282 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Success;

    #line 284 "src/service_libraries/pus_services/pus_service4.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 286 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 292 "src/service_libraries/pus_services/pus_service4.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID) == 0) {
        
        #line 294 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(__ev,
                                                      self->pus_service_1.__that,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      &status);

    } else
    {
        
        #line 302 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 308 "src/service_libraries/pus_services/pus_service4.fin"
        if (status.__variant == Success) {
            
            #line 309 "src/service_libraries/pus_services/pus_service4.fin"
            status = PUSService4__delete_PID_stats(__ev, self);

        }

        #line 312 "src/service_libraries/pus_services/pus_service4.fin"
        if (status.__variant == Success) {
            
            #line 314 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              &status);

        } else
        {
            
            #line 322 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_4_PID_stats_undefined(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                self->exec_tc_req_status_update.PID,
                                                                &status);

        }

    }

    #line 331 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

void PUSService4__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandler * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 334 "src/service_libraries/pus_services/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 334 "src/service_libraries/pus_services/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 336 "src/service_libraries/pus_services/pus_service4.fin"
    __status_int32_t status;
    #line 336 "src/service_libraries/pus_services/pus_service4.fin"
    status.__variant = Success;

    #line 337 "src/service_libraries/pus_services/pus_service4.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 339 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 340 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 341 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 342 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 344 "src/service_libraries/pus_services/pus_service4.fin"
    if (subtype == 6U || subtype == 7U) {
        
        #line 346 "src/service_libraries/pus_services/pus_service4.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler,
                                                 &self->exec_tc_req_status_update.N);

        #line 347 "src/service_libraries/pus_services/pus_service4.fin"
        if (status.__variant == Success) {
            
            #line 348 "src/service_libraries/pus_services/pus_service4.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler,
                                                      &self->exec_tc_req_status_update.PID);

        }

    }

    #line 353 "src/service_libraries/pus_services/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 355 "src/service_libraries/pus_services/pus_service4.fin"
        if (subtype == 1U) {
            
            #line 357 "src/service_libraries/pus_services/pus_service4.fin"
            status = PUSService4__exec4_1TC(__ev, self);

        } else
        #line 359 "src/service_libraries/pus_services/pus_service4.fin"
        if (subtype == 6U) {
            
            #line 361 "src/service_libraries/pus_services/pus_service4.fin"
            status = PUSService4__exec4_6TC(__ev, self);

        } else
        #line 363 "src/service_libraries/pus_services/pus_service4.fin"
        if (subtype == 7U) {
            
            #line 365 "src/service_libraries/pus_services/pus_service4.fin"
            status = PUSService4__exec4_7TC(__ev, self);

        } else
        {
            
            #line 369 "src/service_libraries/pus_services/pus_service4.fin"
            status.__variant = Failure;
            #line 369 "src/service_libraries/pus_services/pus_service4.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 376 "src/service_libraries/pus_services/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 378 "src/service_libraries/pus_services/pus_service4.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 374 "src/service_libraries/pus_services/pus_service4.fin"
        int32_t error_code = status.Failure.__0;

        #line 383 "src/service_libraries/pus_services/pus_service4.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 385 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                &status);

        } else
        #line 390 "src/service_libraries/pus_services/pus_service4.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 392 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    &status);

        } else
        #line 397 "src/service_libraries/pus_services/pus_service4.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 399 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_num_bytes,
                                                              &status);

        } else
        {
            
            #line 407 "src/service_libraries/pus_services/pus_service4.fin"
            (*action_status).__variant = Failure;
            #line 407 "src/service_libraries/pus_services/pus_service4.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 413 "src/service_libraries/pus_services/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 413 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}

uint32_t PUSService4__get_data_pool_item(const __termina_event_t * const __ev,
                                         const PUSService4 * const self,
                                         uint16_t PID) {
    
    #line 480 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 481 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t SDP_value = 0U;

    #line 484 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 485 "src/service_libraries/pus_services/pus_service4.fin"
        uint8_t aux_value = 0U;

        #line 486 "src/service_libraries/pus_services/pus_service4.fin"
        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 487 "src/service_libraries/pus_services/pus_service4.fin"
        SDP_value = (uint32_t)aux_value;

    } else
    #line 489 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 490 "src/service_libraries/pus_services/pus_service4.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else
    {
        

    }

    #line 496 "src/service_libraries/pus_services/pus_service4.fin"
    return SDP_value;

}

_Bool PUSService4__is_stats_index_defined(const __termina_event_t * const __ev,
                                          const PUSService4 * const self,
                                          size_t index) {
    
    #line 77 "src/service_libraries/pus_services/pus_service4.fin"
    _Bool is_defined = 0;

    #line 79 "src/service_libraries/pus_services/pus_service4.fin"
    if (index < 4U) {
        
        #line 81 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    index)] == 1) {
            
            #line 83 "src/service_libraries/pus_services/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                               index)])) {
                
                #line 85 "src/service_libraries/pus_services/pus_service4.fin"
                is_defined = 1;

            } else
            {
                

            }

        }

    }

    #line 93 "src/service_libraries/pus_services/pus_service4.fin"
    return is_defined;

}

void PUSService4__startup(const __termina_event_t * const __ev,
                          void * const __this) {
    
    #line 600 "src/service_libraries/pus_services/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 600 "src/service_libraries/pus_services/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 602 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 604 "src/service_libraries/pus_services/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            #line 606 "src/service_libraries/pus_services/pus_service4.fin"
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            #line 607 "src/service_libraries/pus_services/pus_service4.fin"
            MissionOBT current_obt;
            #line 607 "src/service_libraries/pus_services/pus_service4.fin"
            current_obt.finetime = 0U;
            #line 607 "src/service_libraries/pus_services/pus_service4.fin"
            current_obt.seconds = 0U;

            #line 608 "src/service_libraries/pus_services/pus_service4.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                              &current_obt);

            #line 609 "src/service_libraries/pus_services/pus_service4.fin"
            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else
        {
            
            #line 613 "src/service_libraries/pus_services/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 618 "src/service_libraries/pus_services/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 618 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}

void PUSService4__update_all_stats(const __termina_event_t * const __ev,
                                   void * const __this) {
    
    #line 527 "src/service_libraries/pus_services/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 527 "src/service_libraries/pus_services/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 529 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 531 "src/service_libraries/pus_services/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            #line 533 "src/service_libraries/pus_services/pus_service4.fin"
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            #line 535 "src/service_libraries/pus_services/pus_service4.fin"
            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                #line 537 "src/service_libraries/pus_services/pus_service4.fin"
                if (PUSService4__SDP_param_higher_than_limit(__ev, self,
                                                             i) == 1) {
                    
                    #line 539 "src/service_libraries/pus_services/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    #line 540 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    #line 541 "src/service_libraries/pus_services/pus_service4.fin"
                    MissionOBT current_time;
                    #line 541 "src/service_libraries/pus_services/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 541 "src/service_libraries/pus_services/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 545 "src/service_libraries/pus_services/pus_service4.fin"
                    self->obt_manager.get_current_obt(__ev,
                                                      self->obt_manager.__that,
                                                      &current_time);

                    #line 546 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else
                #line 549 "src/service_libraries/pus_services/pus_service4.fin"
                if (PUSService4__SDP_param_lower_than_limit(__ev, self,
                                                            i) == 1) {
                    
                    #line 551 "src/service_libraries/pus_services/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    #line 552 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    #line 553 "src/service_libraries/pus_services/pus_service4.fin"
                    MissionOBT current_time;
                    #line 553 "src/service_libraries/pus_services/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 553 "src/service_libraries/pus_services/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 557 "src/service_libraries/pus_services/pus_service4.fin"
                    self->obt_manager.get_current_obt(__ev,
                                                      self->obt_manager.__that,
                                                      &current_time);

                    #line 558 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else
                {
                    

                }

                #line 564 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(__ev,
                                                                                                    self,
                                                                                                    i);

            } else
            {
                
                #line 569 "src/service_libraries/pus_services/pus_service4.fin"
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                 self,
                                                                                 PID);

                #line 570 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max = system_data_pool_item;

                #line 571 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min = system_data_pool_item;

                #line 572 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = system_data_pool_item;

                #line 573 "src/service_libraries/pus_services/pus_service4.fin"
                MissionOBT current_time;
                #line 573 "src/service_libraries/pus_services/pus_service4.fin"
                current_time.finetime = 0U;
                #line 573 "src/service_libraries/pus_services/pus_service4.fin"
                current_time.seconds = 0U;

                #line 577 "src/service_libraries/pus_services/pus_service4.fin"
                self->obt_manager.get_current_obt(__ev,
                                                  self->obt_manager.__that,
                                                  &current_time);

                #line 578 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max_obt = current_time;

                #line 579 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min_obt = current_time;

            }

            #line 584 "src/service_libraries/pus_services/pus_service4.fin"
            self->param_stats[__termina_array__index(4U,
                                                     i)].samples = self->param_stats[__termina_array__index(4U,
                                                                                                            i)].samples + 1U;

        } else
        {
            
            #line 589 "src/service_libraries/pus_services/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 596 "src/service_libraries/pus_services/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 596 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}
