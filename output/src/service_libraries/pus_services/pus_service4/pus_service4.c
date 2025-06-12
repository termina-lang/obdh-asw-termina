
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const __termina_event_t * const __ev,
                                   const PUSService4 * const self,
                                   size_t pid_index) {
    
    #line 898 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 899 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 900 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 901 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t mean_value = 0U;

    #line 903 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 906 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 907 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 908 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else
    #line 910 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 911 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 912 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else
    {
        

    }

    #line 919 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const __termina_event_t * const __ev,
                                               const PUSService4 * const self,
                                               size_t pid_index) {
    
    #line 814 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_higher = 0;

    #line 815 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 816 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 817 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 819 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 822 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 823 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 824 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].max) {
            
            #line 825 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    #line 828 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 829 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 830 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].max) {
            
            #line 831 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    {
        

    }

    #line 839 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_higher;

}

_Bool PUSService4__SDP_param_lower_than_limit(const __termina_event_t * const __ev,
                                              const PUSService4 * const self,
                                              size_t pid_index) {
    
    #line 845 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_lower = 0;

    #line 846 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 847 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 848 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 850 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 853 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 854 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 855 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].min) {
            
            #line 856 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    #line 859 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 860 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 861 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].min) {
            
            #line 862 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    {
        

    }

    #line 870 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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
    for (size_t i = 0U; i < 4U && status.__variant == Success; i = i + 1U) {
        
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

__status_int32_t PUSService4__get_free_index(const __termina_event_t * const __ev,
                                             const PUSService4 * const self,
                                             size_t * const index) {
    
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Failure;
    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.Failure.__0 = NO_FREE_STATS_INDEX_ERROR;

    #line 63 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status.__variant == Failure; i = i + 1U) {
        
        #line 65 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 0 || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                                                                               i)]) == 0) {
            
            #line 67 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            *index = i;

            #line 68 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            status.__variant = Success;

        }

    }

    #line 71 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

__status_int32_t PUSService4__add_PID_stats(const __termina_event_t * const __ev,
                                            PUSService4 * const self) {
    
    #line 98 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 98 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 100 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    #line 102 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 104 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        size_t index = 0U;

        #line 105 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        status = PUSService4__get_free_index(__ev, self, &index);

        #line 106 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->exec_tc_req_status_update.valid_index = index;

    }

    #line 109 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 111 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        size_t PID_index = self->exec_tc_req_status_update.valid_index;

        #line 113 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 1;

        #line 114 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.PID[__termina_array__index(4U,
                                                            PID_index)] = self->exec_tc_req_status_update.PID;

        #line 116 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->param_stats[__termina_array__index(4U, PID_index)].samples = 0U;

        #line 117 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        MissionObt current_obt;
        #line 117 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        current_obt.finetime = 0U;
        #line 117 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        current_obt.seconds = 0U;

        #line 118 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 119 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.start_time[__termina_array__index(4U,
                                                                   PID_index)] = current_obt;

    }

    #line 123 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

void PUSService4__build_tm_4_2(const __termina_event_t * const __ev,
                               const PUSService4 * const self,
                               TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, size_t index,
                               __status_int32_t * const status) {
    
    #line 152 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    startup_tm(p_tm_handler);

    #line 154 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 154 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 154 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 155 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                        &current_obt);

    #line 157 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->stats_config_table.start_time[__termina_array__index(4U,
                                                                                        index)].seconds,
                             status);

    #line 158 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler, current_obt.seconds, status);

    #line 159 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u8_appdata_field(p_tm_handler, self->exec_tc_req_status_update.N,
                            status);

    #line 160 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u16_appdata_field(p_tm_handler,
                             self->stats_config_table.PID[__termina_array__index(4U,
                                                                                 index)],
                             status);

    #line 161 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].samples,
                             status);

    #line 162 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].max,
                             status);

    #line 163 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].max_obt.seconds,
                             status);

    #line 164 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].min,
                             status);

    #line 165 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].min_obt.seconds,
                             status);

    #line 166 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].mean_value,
                             status);

    #line 168 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if ((*status).__variant == Success) {
        
        #line 169 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    #line 172 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

__status_int32_t PUSService4__delete_PID_stats(const __termina_event_t * const __ev,
                                               PUSService4 * const self) {
    
    #line 128 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __status_int32_t status;
    #line 128 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status.__variant = Success;

    #line 129 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    size_t PID_index = 0U;

    #line 130 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    status = PUSService4__get_PID_defined_stats_index(__ev, self);

    #line 132 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (status.__variant == Success) {
        
        #line 133 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 0;

    }

    #line 136 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return status;

}

void PUSService4__delete_all_stats(const __termina_event_t * const __ev,
                                   PUSService4 * const self) {
    
    #line 142 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 143 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

    }

    #line 146 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

PSExecTCReqStatus PUSService4__exec4_1TC(const __termina_event_t * const __ev,
                                         PUSService4 * const self) {
    
    #line 178 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 179 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 179 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 179 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.status.__variant = Success;

    #line 181 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 181 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 181 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 183 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 183 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 184 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 187 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 186 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 189 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 190 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 192 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 193 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &next_status.status, &ack_enabled);

        #line 195 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (ack_enabled) {
            
            #line 197 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (next_status.status.__variant == Success) {
                
                #line 199 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 203 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 208 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 213 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.__variant = Failure;
        #line 213 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 217 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && next_status.status.__variant == Success; i = i + 1U) {
        
        #line 219 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            #line 221 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __option_box_t tm_handler2;
            #line 221 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            tm_handler2.__variant = None;

            #line 222 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 226 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 224 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 228 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 229 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 231 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                PUSService4__build_tm_4_2(__ev, self,
                                          (TMHandlerT *)b_tm_handler2.data,
                                          tm_count, i, &next_status.status);

                #line 233 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 235 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2,
                                             &next_status.status);

                } else
                {
                    
                    #line 239 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

                #line 244 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                #line 245 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_obt_update;
                #line 245 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.finetime = 0U;
                #line 245 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.seconds = 0U;

                #line 246 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt_update);

                #line 247 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else
            {
                
                #line 250 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.status.__variant = Failure;
                #line 250 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 256 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (next_status.status.__variant == Success) {
        
        #line 258 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __option_box_t tm_handler3;
        #line 258 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        tm_handler3.__variant = None;

        #line 259 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 263 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 261 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 265 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t tm_count3 = 0U;

            #line 266 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count3);

            #line 268 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 269 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &next_status.status, &ack_enabled);

            #line 271 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (ack_enabled) {
                
                #line 273 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 275 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler3,
                                             &next_status.status);

                } else
                {
                    
                    #line 279 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                }

            } else
            {
                
                #line 284 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 288 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.status.__variant = Failure;
            #line 288 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        

    }

    #line 299 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_6TC(const __termina_event_t * const __ev,
                                         PUSService4 * const self) {
    
    #line 305 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 306 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 306 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 306 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.status.__variant = Success;

    #line 308 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 308 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 308 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 310 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 310 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 311 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 315 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 313 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 317 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 318 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 320 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 322 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 323 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt,
                                                &next_status.status);

            #line 326 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (next_status.status.__variant == Success) {
                
                #line 328 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 332 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 338 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 340 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.status = PUSService4__add_PID_stats(__ev, self);

                #line 342 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 344 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 345 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 347 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (ack_enabled) {
                        
                        #line 349 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 351 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 355 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 360 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 363 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 363 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 364 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 368 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 366 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 370 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 371 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 373 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 374 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 376 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (ack_enabled) {
                            
                            #line 378 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 380 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 384 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 389 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 393 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.status.__variant = Failure;
                        #line 393 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 400 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 401 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.PID,
                                                       current_obt,
                                                       &next_status.status);

                    #line 404 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 406 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 410 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 419 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 420 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &next_status.status);

                #line 423 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 425 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 429 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 437 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.__variant = Failure;
        #line 437 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 441 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_7TC(const __termina_event_t * const __ev,
                                         PUSService4 * const self) {
    
    #line 447 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.status.__variant = Success;

    #line 450 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 450 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 450 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 452 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 452 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 453 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 457 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 455 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 459 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 460 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 462 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 464 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 465 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt,
                                                &next_status.status);

            #line 468 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (next_status.status.__variant == Success) {
                
                #line 470 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 474 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 481 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 483 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.status = PUSService4__delete_PID_stats(__ev, self);

                #line 485 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 487 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 488 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 490 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (ack_enabled) {
                        
                        #line 492 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 494 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 498 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 503 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 506 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 506 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 507 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(__ev,
                                                  self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 511 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 509 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 513 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 514 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(__ev,
                                                           self->tm_counter.__that,
                                                           &tm_count2);

                        #line 516 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(__ev,
                                                            self->pus_service_9.__that,
                                                            &current_obt);

                        #line 517 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &next_status.status,
                                     &ack_enabled);

                        #line 519 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (ack_enabled) {
                            
                            #line 521 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (next_status.status.__variant == Success) {
                                
                                #line 523 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &next_status.status);

                            } else
                            {
                                
                                #line 527 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 533 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 539 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.status.__variant = Failure;
                        #line 539 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 546 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 547 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.PID,
                                                     current_obt,
                                                     &next_status.status);

                    #line 550 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 552 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 556 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 566 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 567 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &next_status.status);

                #line 570 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 572 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 576 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 583 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.__variant = Failure;
        #line 583 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 587 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                          const PUSService4 * const self) {
    
    #line 632 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 632 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 632 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.status.__variant = Success;

    #line 634 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 634 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 634 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 636 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 636 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 641 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 639 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 643 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 644 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 646 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 647 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 650 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (next_status.status.__variant == Success) {
            
            #line 652 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 656 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 662 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.__variant = Failure;
        #line 662 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 666 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                              const PUSService4 * const self) {
    
    #line 594 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 594 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 594 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.status.__variant = Success;

    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 598 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 598 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 599 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 603 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 601 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 605 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 606 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 608 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 609 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 612 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (next_status.status.__variant == Success) {
            
            #line 614 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 618 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 623 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.__variant = Failure;
        #line 623 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 627 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                const PUSService4 * const self) {
    
    #line 671 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 671 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 671 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.status.__variant = Success;

    #line 673 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 673 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 673 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 675 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 675 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 676 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 680 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 678 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 682 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 683 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 685 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 686 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 689 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (next_status.status.__variant == Success) {
            
            #line 691 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 695 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 701 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.__variant = Failure;
        #line 701 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 705 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

void PUSService4__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 709 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 709 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 711 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 713 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 717 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 719 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 720 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 721 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 722 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 724 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 6U || subtype == 7U) {
                
                #line 726 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                  &self->exec_tc_req_status_update.N);

                #line 727 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                                   &self->exec_tc_req_status_update.PID);

            }

            #line 730 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 732 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 736 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 736 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 737 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 742 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 744 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 1U) {
                
                #line 746 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_1TC(__ev, self);

            } else
            #line 748 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 6U) {
                
                #line 750 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_6TC(__ev, self);

            } else
            #line 752 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 7U) {
                
                #line 754 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_7TC(__ev, self);

            } else
            {
                
                #line 758 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 758 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 759 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 770 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 772 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 768 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 777 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 780 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status = PUSService4__manage_error_in_acceptance(__ev,
                                                                               self);

        } else
        #line 782 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 785 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status = PUSService4__manage_tm_limit_app_data_reached(__ev,
                                                                                     self);

        } else
        #line 787 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 789 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status = PUSService4__manage_short_pack_length_error(__ev,
                                                                                   self);

        } else
        #line 791 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (error_code == NO_FREE_STATS_INDEX_ERROR) {
            

        } else
        {
            
            #line 797 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).__variant = Failure;
            #line 797 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 804 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 805 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 808 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 808 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

uint32_t PUSService4__get_data_pool_item(const __termina_event_t * const __ev,
                                         const PUSService4 * const self,
                                         uint16_t PID) {
    
    #line 875 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 876 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t SDP_value = 0U;

    #line 879 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 880 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint8_t aux_value = 0U;

        #line 881 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 882 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = (uint32_t)aux_value;

    } else
    #line 884 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 885 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else
    {
        

    }

    #line 891 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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
    
    #line 995 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 995 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 997 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 999 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            #line 1001 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            #line 1002 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            MissionObt current_obt;
            #line 1002 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.finetime = 0U;
            #line 1002 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.seconds = 0U;

            #line 1003 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 1004 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else
        {
            
            #line 1008 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 1013 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1013 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

void PUSService4__update_all_stats(const __termina_event_t * const __ev,
                                   void * const __this) {
    
    #line 922 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PUSService4 * self = (PUSService4 *)__this;

    #line 922 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 924 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 926 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(__ev, self, i) == 1) {
            
            #line 928 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            #line 930 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                #line 932 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_higher_than_limit(__ev, self,
                                                             i) == 1) {
                    
                    #line 934 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    #line 935 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    #line 936 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 936 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 936 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 940 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_time);

                    #line 941 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else
                #line 944 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_lower_than_limit(__ev, self,
                                                            i) == 1) {
                    
                    #line 946 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                     self,
                                                                                     PID);

                    #line 947 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    #line 948 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 948 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 948 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 952 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_time);

                    #line 953 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else
                {
                    

                }

                #line 959 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(__ev,
                                                                                                    self,
                                                                                                    i);

            } else
            {
                
                #line 964 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(__ev,
                                                                                 self,
                                                                                 PID);

                #line 965 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max = system_data_pool_item;

                #line 966 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min = system_data_pool_item;

                #line 967 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = system_data_pool_item;

                #line 968 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_time;
                #line 968 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.finetime = 0U;
                #line 968 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.seconds = 0U;

                #line 972 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_time);

                #line 973 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max_obt = current_time;

                #line 974 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min_obt = current_time;

            }

            #line 979 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U,
                                                     i)].samples = self->param_stats[__termina_array__index(4U,
                                                                                                            i)].samples + 1U;

        } else
        {
            
            #line 984 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 991 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 991 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}
