
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const __termina_event_t * const __ev,
                                   const PUSService4 * const self,
                                   size_t pid_index) {
    
    #line 801 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 802 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 803 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 804 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t mean_value = 0U;

    #line 806 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 809 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 810 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 811 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else
    #line 813 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 814 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 815 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else
    {
        

    }

    #line 822 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const __termina_event_t * const __ev,
                                               const PUSService4 * const self,
                                               size_t pid_index) {
    
    #line 717 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_higher = 0;

    #line 718 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 719 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 720 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 722 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 725 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 726 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 727 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].max) {
            
            #line 728 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    #line 731 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 732 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 733 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].max) {
            
            #line 734 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    {
        

    }

    #line 742 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_higher;

}

_Bool PUSService4__SDP_param_lower_than_limit(const __termina_event_t * const __ev,
                                              const PUSService4 * const self,
                                              size_t pid_index) {
    
    #line 748 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_lower = 0;

    #line 749 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 750 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 751 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 753 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 756 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 757 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 758 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].min) {
            
            #line 759 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    #line 762 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 763 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 764 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].min) {
            
            #line 765 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    {
        

    }

    #line 773 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_lower;

}

__status_int32_t PUSService4__get_PID_defined_stats_index(const __termina_event_t * const __ev,
                                                          PUSService4 * const self) {
    
    #line 35 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 35 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Failure;
    #line 35 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.Failure.__0 = INVALID_PID_ERROR;

    #line 37 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status.__variant == Failure; i = i + 1U) {
        
        #line 39 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.PID == self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                       i)]) {
            
            #line 41 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                        i)] == 1) {
                
                #line 43 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                    
                    #line 45 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->exec_tc_req_status_update.valid_index = i;

                    #line 46 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status.__variant = Success;

                } else
                {
                    
                    #line 49 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->stats_config_table.defined[__termina_array__index(4U,
                                                                            i)] = 0;

                }

            }

        }

    }

    #line 56 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

IndexStatus PUSService4__get_free_index(const __termina_event_t * const __ev,
                                        const PUSService4 * const self) {
    
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    IndexStatus id_status;
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    id_status.index = 0U;
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    id_status.status.__variant = Failure;
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    id_status.status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    #line 63 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U;
         i < 4U && id_status.status.__variant == Failure;
         i = i + 1U) {
        
        #line 65 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U, i)] == 0
            || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                              i)]) == 0) {
            
            #line 67 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            id_status.index = i;

            #line 68 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            id_status.status.__variant = Success;

        }

    }

    #line 71 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return id_status;

}

__status_int32_t PUSService4__add_PID_stats(const __termina_event_t * const __ev,
                                            PUSService4 * const self) {
    
    #line 98 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 98 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 99 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    IndexStatus index_status;
    #line 99 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    index_status.index = 0U;
    #line 99 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    index_status.status.__variant = Success;

    #line 100 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    #line 102 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Failure) {
        
        #line 104 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        index_status = PUSService4__get_free_index(__ev, self);

        #line 105 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->exec_tc_req_status_update.valid_index = index_status.index;

    }

    #line 108 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (index_status.status.__variant == Success) {
        
        #line 110 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        size_t PID_index = self->exec_tc_req_status_update.valid_index;

        #line 112 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 1;

        #line 113 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.PID[__termina_array__index(4U,
                                                            PID_index)] = self->exec_tc_req_status_update.PID;

        #line 115 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->param_stats[__termina_array__index(4U, PID_index)].samples = 0U;

        #line 116 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        MissionObt current_obt;
        #line 116 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        current_obt.finetime = 0U;
        #line 116 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        current_obt.seconds = 0U;

        #line 117 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 118 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.start_time[__termina_array__index(4U,
                                                                   PID_index)] = current_obt;

        #line 119 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.__variant = Success;

    } else
    {
        
        #line 123 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.__variant = Failure;
        #line 123 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    }

    #line 126 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__delete_PID_stats(const __termina_event_t * const __ev,
                                               PUSService4 * const self) {
    
    #line 131 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 131 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 132 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    #line 134 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 135 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                self->exec_tc_req_status_update.valid_index)] = 0;

    }

    #line 138 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

void PUSService4__delete_all_stats(const __termina_event_t * const __ev,
                                   PUSService4 * const self) {
    
    #line 144 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 145 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

    }

    #line 148 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

__status_int32_t PUSService4__exec4_1TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    #line 156 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 157 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 157 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 159 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 159 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 159 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 161 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 161 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 162 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 165 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 164 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 167 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 168 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 170 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 171 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                              self->exec_tc_req_status_update.packet_id,
                              self->exec_tc_req_status_update.packet_seq_ctrl,
                              self->exec_tc_req_status_update.flags_ack,
                              current_obt, &ack_enabled);

        #line 173 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (ack_enabled) {
            
            #line 175 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (status.__variant == Success) {
                
                #line 177 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 181 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 186 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 191 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.__variant = Failure;
        #line 191 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 195 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status.__variant == Success; i = i + 1U) {
        
        #line 197 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            #line 199 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __option_box_t tm_handler2;
            #line 199 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            tm_handler2.__variant = None;

            #line 200 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 204 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 202 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 206 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 208 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 209 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 211 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = build_tm_4_2((TMHandlerT *)b_tm_handler2.data,
                                      tm_count, i,
                                      self->exec_tc_req_status_update.N,
                                      &self->stats_config_table,
                                      self->param_stats, current_obt);

                #line 213 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 215 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2, &status);

                } else
                {
                    
                    #line 219 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

                #line 224 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                #line 225 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_obt_update;
                #line 225 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.finetime = 0U;
                #line 225 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.seconds = 0U;

                #line 226 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt_update);

                #line 227 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else
            {
                
                #line 230 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.__variant = Failure;
                #line 230 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 236 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 238 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __option_box_t tm_handler3;
        #line 238 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        tm_handler3.__variant = None;

        #line 239 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 243 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 241 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 245 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t tm_count3 = 0U;

            #line 246 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count3);

            #line 248 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 249 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            status = build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                  self->exec_tc_req_status_update.packet_id,
                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                  self->exec_tc_req_status_update.flags_ack,
                                  current_obt, &ack_enabled);

            #line 251 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (ack_enabled) {
                
                #line 253 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 255 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler3, &status);

                } else
                {
                    
                    #line 259 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                }

            } else
            {
                
                #line 264 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 268 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            status.__variant = Failure;
            #line 268 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        

    }

    #line 279 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__exec4_6TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    #line 285 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 286 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 286 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 288 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 288 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 288 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 290 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 290 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 291 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 295 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 293 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 297 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 298 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 300 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 302 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 303 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 306 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (status.__variant == Success) {
                
                #line 308 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 312 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 318 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 320 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = PUSService4__add_PID_stats(__ev, self);

                #line 322 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 324 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 325 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 327 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (ack_enabled) {
                        
                        #line 329 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (status.__variant == Success) {
                            
                            #line 331 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 335 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 340 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 343 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 343 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 344 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 348 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 346 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 350 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 351 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 353 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 354 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 356 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (ack_enabled) {
                            
                            #line 358 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (status.__variant == Success) {
                                
                                #line 360 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else
                            {
                                
                                #line 364 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 369 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 373 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        status.__variant = Failure;
                        #line 373 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 380 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 381 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                                tm_count,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                self->exec_tc_req_status_update.PID,
                                                                current_obt);

                    #line 384 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (status.__variant == Success) {
                        
                        #line 386 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 390 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 399 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 400 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.packet_id,
                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.PID,
                                                    current_obt);

                #line 403 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 405 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 409 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 417 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.__variant = Failure;
        #line 417 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 421 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__exec4_7TC(const __termina_event_t * const __ev,
                                        PUSService4 * const self) {
    
    #line 427 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 428 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 428 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 430 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 430 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 430 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 432 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 432 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 433 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 437 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 435 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 439 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 440 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 442 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 444 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 445 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (status.__variant == Success) {
                
                #line 450 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 454 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 461 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 463 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = PUSService4__delete_PID_stats(__ev, self);

                #line 465 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 467 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 468 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 470 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (ack_enabled) {
                        
                        #line 472 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (status.__variant == Success) {
                            
                            #line 474 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 478 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 483 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 486 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 486 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 487 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 491 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 489 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 493 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 494 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 496 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 497 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 499 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (ack_enabled) {
                            
                            #line 501 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (status.__variant == Success) {
                                
                                #line 503 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else
                            {
                                
                                #line 507 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 513 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 519 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        status.__variant = Failure;
                        #line 519 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 526 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 527 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.PID,
                                                              current_obt);

                    #line 530 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (status.__variant == Success) {
                        
                        #line 532 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 536 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 546 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 547 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.packet_id,
                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.PID,
                                                    current_obt);

                #line 550 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 552 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 556 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 563 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.__variant = Failure;
        #line 563 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 567 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

void PUSService4__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 573 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 573 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 575 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 575 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 576 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 578 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 582 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 584 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 585 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 586 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 587 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 589 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 6U || subtype == 7U) {
                
                #line 591 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.N);

                #line 592 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 593 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = tc_handler_get_u16_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.PID);

                }

            }

            #line 597 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (status.__variant == Success) {
                
                #line 599 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 603 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.__variant = Failure;
                #line 603 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 604 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 609 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 611 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 613 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 1U) {
                
                #line 615 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = PUSService4__exec4_1TC(__ev, self);

            } else
            #line 617 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 6U) {
                
                #line 619 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = PUSService4__exec4_6TC(__ev, self);

            } else
            #line 621 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 7U) {
                
                #line 623 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status = PUSService4__exec4_7TC(__ev, self);

            } else
            {
                
                #line 627 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.__variant = Failure;
                #line 627 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 638 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 640 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 636 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        int32_t error_code = status.Failure.__0;

        #line 645 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 647 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).__variant = Success;

            #line 649 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __option_box_t tm_handler;
            #line 649 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            tm_handler.__variant = None;

            #line 650 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 654 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (tm_handler.__variant == Some) {
                
                #line 652 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 656 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 657 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_obt;
                #line 657 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt.finetime = 0U;
                #line 657 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt.seconds = 0U;

                #line 659 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 660 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 662 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 664 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 667 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 669 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 672 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 674 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 684 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (status.__variant == Success) {
                    
                    #line 686 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 690 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 696 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.__variant = Failure;
                #line 696 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 703 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).__variant = Failure;
            #line 703 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 709 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 711 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 711 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

uint32_t PUSService4__get_data_pool_item(const __termina_event_t * const __ev,
                                         const PUSService4 * const self,
                                         uint16_t PID) {
    
    #line 778 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 779 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t SDP_value = 0U;

    #line 782 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 783 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint8_t aux_value = 0U;

        #line 784 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 785 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = (uint32_t)aux_value;

    } else
    #line 787 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 788 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else
    {
        

    }

    #line 794 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return SDP_value;

}

_Bool PUSService4__is_stats_index_defined(const __termina_event_t * const __ev,
                                          const PUSService4 * const self,
                                          size_t index) {
    
    #line 76 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_defined = 0;

    #line 78 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (index < 4U) {
        
        #line 80 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    index)] == 1) {
            
            #line 82 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                               index)])) {
                
                #line 84 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                is_defined = 1;

            } else
            {
                

            }

        }

    }

    #line 92 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_defined;

}

void PUSService4__startup(const __termina_event_t * const __ev,
                          void * const __this) {
    
    #line 898 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 898 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 900 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 902 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            #line 904 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            #line 905 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            MissionObt current_obt;
            #line 905 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.finetime = 0U;
            #line 905 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.seconds = 0U;

            #line 906 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 907 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else
        {
            
            #line 911 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 916 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 916 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

void PUSService4__update_all_stats(const __termina_event_t * const __ev,
                                   void * const __this) {
    
    #line 825 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 825 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 827 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 829 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            #line 831 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            #line 833 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                #line 835 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_higher_than_limit(__ev, self,
                                                             i) == 1) {
                    
                    #line 837 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    #line 838 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    #line 839 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 839 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 839 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 843 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_time);

                    #line 844 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else
                #line 847 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_lower_than_limit(__ev, self,
                                                            i) == 1) {
                    
                    #line 849 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    #line 850 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    #line 851 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 851 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 851 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 855 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_time);

                    #line 856 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else
                {
                    

                }

                #line 862 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(__ev,
                                                                                                    self,
                                                                                                    i);

            } else
            {
                
                #line 867 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                 self,
                                                                                 PID);

                #line 868 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max = system_data_pool_item;

                #line 869 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min = system_data_pool_item;

                #line 870 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = system_data_pool_item;

                #line 871 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_time;
                #line 871 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.finetime = 0U;
                #line 871 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.seconds = 0U;

                #line 875 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_time);

                #line 876 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max_obt = current_time;

                #line 877 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min_obt = current_time;

            }

            #line 882 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U,
                                                     i)].samples = self->param_stats[__termina_array__index(4U,
                                                                                                            i)].samples + 1U;

        } else
        {
            
            #line 887 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 894 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 894 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}
