
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const PUSService4 * const self,
                                   size_t pid_index) {
    
    #line 961 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 962 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 963 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 964 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t mean_value = 0U;

    #line 966 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 969 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 970 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 971 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else
    #line 973 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 974 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 975 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else
    {
        

    }

    #line 982 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const PUSService4 * const self,
                                               size_t pid_index) {
    
    #line 877 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_higher = 0;

    #line 878 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 879 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 880 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 882 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 885 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 886 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 887 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].max) {
            
            #line 888 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    #line 891 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 892 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 893 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].max) {
            
            #line 894 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    {
        

    }

    #line 902 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_higher;

}

_Bool PUSService4__SDP_param_lower_than_limit(const PUSService4 * const self,
                                              size_t pid_index) {
    
    #line 908 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_lower = 0;

    #line 909 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 910 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 911 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 913 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 916 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 917 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 918 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].min) {
            
            #line 919 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    #line 922 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 923 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 924 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].min) {
            
            #line 925 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    {
        

    }

    #line 933 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_lower;

}

MyResult PUSService4__get_PID_defined_stats_index(PUSService4 * const self) {
    
    #line 35 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 35 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Error;

    #line 37 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Error; i = i + 1U) {
        
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
                    result.__variant = MyResult__Ok;

                } else
                {
                    
                    #line 48 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->stats_config_table.defined[__termina_array__index(4U,
                                                                            i)] = 0;

                }

            }

        }

    }

    #line 54 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return result;

}

MyResult PUSService4__get_free_index(const PUSService4 * const self,
                                     size_t * const index) {
    
    #line 59 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 59 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Error;

    #line 61 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Error; i = i + 1U) {
        
        #line 63 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 0 || sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                                                                                               i)]) == 0) {
            
            #line 65 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            *index = i;

            #line 66 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            result.__variant = MyResult__Ok;

        }

    }

    #line 69 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return result;

}

MyResult PUSService4__add_PID_stats(PUSService4 * const self) {
    
    #line 96 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 96 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 99 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result = PUSService4__get_PID_defined_stats_index(self);

    #line 101 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (result.__variant == MyResult__Error) {
        
        #line 103 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        size_t index = 0U;

        #line 104 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        result = PUSService4__get_free_index(self, &index);

        #line 105 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->exec_tc_req_status_update.valid_index = index;

    }

    #line 108 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (result.__variant == MyResult__Ok) {
        
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
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 118 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.start_time[__termina_array__index(4U,
                                                                   PID_index)] = current_obt;

    }

    #line 122 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return result;

}

void PUSService4__build_tm_4_2(const PUSService4 * const self,
                               TMHandlerT * const p_tm_handler,
                               uint16_t tm_seq_counter, size_t index,
                               MyResult * const result) {
    
    #line 151 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    startup_tm(p_tm_handler);

    #line 153 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 153 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 153 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 154 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 156 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->stats_config_table.start_time[__termina_array__index(4U,
                                                                                        index)].seconds,
                             result);

    #line 157 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler, current_obt.seconds, result);

    #line 158 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u8_appdata_field(p_tm_handler, self->exec_tc_req_status_update.N,
                            result);

    #line 159 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u16_appdata_field(p_tm_handler,
                             self->stats_config_table.PID[__termina_array__index(4U,
                                                                                 index)],
                             result);

    #line 160 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].samples,
                             result);

    #line 161 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].max,
                             result);

    #line 162 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].max_obt.seconds,
                             result);

    #line 163 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].min,
                             result);

    #line 164 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].min_obt.seconds,
                             result);

    #line 165 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    append_u32_appdata_field(p_tm_handler,
                             self->param_stats[__termina_array__index(4U,
                                                                      index)].mean_value,
                             result);

    #line 167 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if ((*result).__variant == MyResult__Ok) {
        
        #line 168 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        close_tm(p_tm_handler, 4U, 2U, tm_seq_counter, current_obt);

    }

    #line 171 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

MyResult PUSService4__delete_PID_stats(PUSService4 * const self) {
    
    #line 127 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 127 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Error;

    #line 128 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    size_t PID_index = 0U;

    #line 129 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result = PUSService4__get_PID_defined_stats_index(self);

    #line 131 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (result.__variant == MyResult__Ok) {
        
        #line 132 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U,
                                                                PID_index)] = 0;

    }

    #line 135 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return result;

}

void PUSService4__delete_all_stats(PUSService4 * const self) {
    
    #line 141 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 142 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

    }

    #line 145 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

PSExecTCReqStatus PUSService4__exec4_1TC(PUSService4 * const self) {
    
    #line 177 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 177 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 178 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 179 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 179 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

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
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 187 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 186 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 189 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 190 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 192 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 193 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &result, &ack_enabled);

        #line 195 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (ack_enabled) {
            
            #line 197 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 199 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 201 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 202 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 202 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 206 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 207 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 207 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 211 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 216 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 216 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 220 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Ok; i = i + 1U) {
        
        #line 222 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            #line 224 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __option_box_t tm_handler2;
            #line 224 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            tm_handler2.__variant = None;

            #line 225 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 229 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 227 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 231 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 232 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                   &tm_count);

                #line 234 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                PUSService4__build_tm_4_2(self,
                                          (TMHandlerT *)b_tm_handler2.data,
                                          tm_count, i, &result);

                #line 236 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 238 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler2, &result);

                    #line 240 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 241 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 241 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 245 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                    #line 246 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 246 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 250 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                #line 251 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_obt_update;
                #line 251 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.finetime = 0U;
                #line 251 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.seconds = 0U;

                #line 252 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt_update);

                #line 253 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else
            {
                
                #line 256 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 256 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 262 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (result.__variant == MyResult__Ok) {
        
        #line 264 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __option_box_t tm_handler3;
        #line 264 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        tm_handler3.__variant = None;

        #line 265 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 269 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 267 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 271 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t tm_count3 = 0U;

            #line 272 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count3);

            #line 274 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 275 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 277 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (ack_enabled) {
                
                #line 279 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 281 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler3, &result);

                    #line 283 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 284 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 284 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 288 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                    #line 289 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 289 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 293 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 297 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 297 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        

    }

    #line 308 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_6TC(PUSService4 * const self) {
    
    #line 314 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 314 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 315 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 316 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 316 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 318 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 318 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 318 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 320 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 320 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 321 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 325 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 323 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 327 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 328 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 330 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 332 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 333 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 336 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 338 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 340 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 341 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 341 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 345 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 346 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 346 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 352 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 354 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                result = PUSService4__add_PID_stats(self);

                #line 356 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 358 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 359 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 361 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (ack_enabled) {
                        
                        #line 363 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 365 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 367 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 368 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 368 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 372 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 373 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 373 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 377 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 380 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 380 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 381 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 385 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 383 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 387 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 388 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 390 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 391 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 393 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (ack_enabled) {
                            
                            #line 395 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 397 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 399 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 400 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 400 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 404 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 405 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 405 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 409 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 413 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 413 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 420 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 421 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.PID,
                                                       current_obt, &result);

                    #line 424 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 426 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 428 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 429 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 429 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 433 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 434 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 434 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 442 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 443 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 446 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 450 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 451 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 451 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 455 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 456 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 456 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 463 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 463 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 467 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_7TC(PUSService4 * const self) {
    
    #line 473 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 473 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 474 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool ack_enabled = 0;

    #line 475 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 475 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 477 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 477 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 477 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 479 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 479 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 480 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 484 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 482 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 486 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 487 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 489 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 491 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 492 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 495 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 497 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 499 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 500 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 500 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 504 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 505 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 505 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 511 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 513 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                result = PUSService4__delete_PID_stats(self);

                #line 515 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 517 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 518 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 520 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (ack_enabled) {
                        
                        #line 522 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 524 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 526 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 527 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 527 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 531 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 532 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 532 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 536 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 539 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 539 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 540 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 544 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 542 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 546 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 547 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 549 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 550 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2,
                                     self->exec_tc_req_status_update.flags_ack,
                                     current_obt, &result, &ack_enabled);

                        #line 552 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (ack_enabled) {
                            
                            #line 554 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 556 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 558 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 559 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 559 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 563 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 564 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 564 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 569 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 575 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 575 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 582 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 583 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.PID,
                                                     current_obt, &result);

                    #line 586 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 588 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 590 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 591 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 591 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 595 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 605 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 606 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 609 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 611 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 613 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 614 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 614 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 618 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 619 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 619 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 625 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 625 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 629 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PS4ExecTCReqStatusUpdate PUSService4__get_TC_params(const PUSService4 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 635 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PS4ExecTCReqStatusUpdate tc_data;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.N = 0U;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.PID = 0U;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.flags_ack = 0U;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_id = 0U;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.tc_num_bytes = 0U;
    #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.valid_index = 0U;

    #line 647 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 648 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 649 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 650 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 652 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (*subtype == 6U || *subtype == 7U) {
        
        #line 654 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

        #line 655 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    }

    #line 658 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService4__manage_error_in_acceptance(const PUSService4 * const self) {
    
    #line 706 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 706 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 707 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 707 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 709 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 709 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 709 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 711 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 711 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 712 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 716 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 714 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 718 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 719 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 721 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 722 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 725 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 727 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 729 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 730 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 730 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 734 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 735 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 735 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 740 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 740 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 744 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__manage_short_pack_length_error(const PUSService4 * const self) {
    
    #line 664 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 664 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 665 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 665 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 667 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 667 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 667 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 669 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 669 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 670 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 674 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 672 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 676 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 677 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 679 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 680 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 683 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 685 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 687 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 688 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 688 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 692 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 693 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 693 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 697 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 697 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 701 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__manage_tm_limit_app_data_reached(const PUSService4 * const self) {
    
    #line 749 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 749 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 750 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 750 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 752 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 752 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 752 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 754 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 754 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 755 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 759 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 757 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 761 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 762 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 764 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 765 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 768 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 770 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 772 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 773 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 773 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 777 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 778 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 778 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 783 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 783 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 787 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

void PUSService4__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService4 * self = (PUSService4 *)__this;

    #line 793 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t subtype = 0U;

    #line 795 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 799 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 801 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            MyResult result;
            #line 801 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            result.__variant = MyResult__Ok;

            #line 802 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update = PUSService4__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 804 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 805 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 805 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 807 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 811 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 813 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 1U) {
                
                #line 815 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_1TC(self);

            } else
            #line 817 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 6U) {
                
                #line 819 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_6TC(self);

            } else
            #line 821 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 7U) {
                
                #line 823 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_7TC(self);

            } else
            {
                
                #line 827 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 827 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 830 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 797 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 832 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 834 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 837 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__manage_error_in_acceptance(self);

            } else
            #line 839 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 842 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__manage_tm_limit_app_data_reached(self);

            } else
            #line 844 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 846 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 854 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 797 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 856 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).__variant = Failure;
            #line 856 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 857 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 866 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 868 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 871 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

void PUSService4__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    PUSService4 * self = (PUSService4 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService4__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService4__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService4__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

uint32_t PUSService4__get_data_pool_item(const PUSService4 * const self,
                                         uint16_t PID) {
    
    #line 938 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 939 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t SDP_value = 0U;

    #line 942 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 943 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint8_t aux_value = 0U;

        #line 944 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 945 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = (uint32_t)aux_value;

    } else
    #line 947 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 948 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else
    {
        

    }

    #line 954 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return SDP_value;

}

_Bool PUSService4__is_stats_index_defined(const PUSService4 * const self,
                                          size_t index) {
    
    #line 74 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_defined = 0;

    #line 76 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (index < 4U) {
        
        #line 78 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    index)] == 1) {
            
            #line 80 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->stats_config_table.PID[__termina_array__index(4U,
                                                                                               index)])) {
                
                #line 82 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                is_defined = 1;

            } else
            {
                

            }

        }

    }

    #line 90 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_defined;

}

void PUSService4__startup(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    #line 1060 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 1062 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            #line 1064 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            #line 1065 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            MissionObt current_obt;
            #line 1065 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.finetime = 0U;
            #line 1065 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.seconds = 0U;

            #line 1066 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1067 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else
        {
            
            #line 1071 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 1076 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

void PUSService4__startup__mutex_lock(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService4__startup(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService4__startup__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__startup(__this);
    __termina_task__unlock(lock);

}

void PUSService4__startup__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__startup(__this);
    __termina_event__unlock(lock);

}

void PUSService4__update_all_stats(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    #line 987 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 989 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            #line 991 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            #line 993 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                #line 995 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_higher_than_limit(self, i) == 1) {
                    
                    #line 997 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    #line 998 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    #line 999 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 999 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 999 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 1003 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_time);

                    #line 1004 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else
                #line 1007 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_lower_than_limit(self, i) == 1) {
                    
                    #line 1009 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    #line 1010 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    #line 1011 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 1011 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 1011 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 1015 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_time);

                    #line 1016 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else
                {
                    

                }

                #line 1022 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(self,
                                                                                                    i);

            } else
            {
                
                #line 1027 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                 PID);

                #line 1028 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max = system_data_pool_item;

                #line 1029 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min = system_data_pool_item;

                #line 1030 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = system_data_pool_item;

                #line 1031 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_time;
                #line 1031 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.finetime = 0U;
                #line 1031 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.seconds = 0U;

                #line 1035 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_time);

                #line 1036 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max_obt = current_time;

                #line 1037 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min_obt = current_time;

            }

            #line 1042 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U,
                                                     i)].samples = self->param_stats[__termina_array__index(4U,
                                                                                                            i)].samples + 1U;

        } else
        {
            
            #line 1047 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 1054 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return;

}

void PUSService4__update_all_stats__mutex_lock(void * const __this) {
    
    PUSService4 * self = (PUSService4 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService4__update_all_stats(self);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService4__update_all_stats__task_lock(void * const __this) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService4__update_all_stats(__this);
    __termina_task__unlock(lock);

}

void PUSService4__update_all_stats__event_lock(void * const __this) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService4__update_all_stats(__this);
    __termina_event__unlock(lock);

}
