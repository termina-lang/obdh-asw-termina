
#include "service_libraries/pus_services/pus_service4/pus_service4.h"

uint32_t PUSService4__SDP_get_mean(const PUSService4 * const self,
                                   size_t pid_index) {
    
    #line 918 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 919 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 920 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 921 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t mean_value = 0U;

    #line 923 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 926 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 927 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 928 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                           pid_index)].samples + 1U);

    } else
    #line 930 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 931 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 932 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                    pid_index)].mean_value * self->param_stats[__termina_array__index(4U,
                                                                                                                                                      pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[__termina_array__index(4U,
                                                                                                                                                                                                                                                  pid_index)].samples + 1U);

    } else
    {
        

    }

    #line 939 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return mean_value;

}

_Bool PUSService4__SDP_param_higher_than_limit(const PUSService4 * const self,
                                               size_t pid_index) {
    
    #line 834 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_higher = 0;

    #line 835 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 836 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 837 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 839 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 842 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 843 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 844 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].max) {
            
            #line 845 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    #line 848 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 849 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 850 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value > self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].max) {
            
            #line 851 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_higher = 1;

        }

    } else
    {
        

    }

    #line 859 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return is_higher;

}

_Bool PUSService4__SDP_param_lower_than_limit(const PUSService4 * const self,
                                              size_t pid_index) {
    
    #line 865 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    _Bool is_lower = 0;

    #line 866 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                       pid_index)];

    #line 867 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t u8_SDP_value = 0U;

    #line 868 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t u32_SDP_value = 0U;

    #line 870 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 873 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 874 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 875 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if ((uint32_t)u8_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                              pid_index)].min) {
            
            #line 876 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    #line 879 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 880 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 881 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (u32_SDP_value < self->param_stats[__termina_array__index(4U,
                                                                     pid_index)].min) {
            
            #line 882 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            is_lower = 1;

        }

    } else
    {
        

    }

    #line 890 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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
    PSExecTCReqStatus next_status;
    #line 178 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 180 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 180 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 180 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 182 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 182 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 183 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 186 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 185 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 188 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 189 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 191 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 192 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count, current_obt,
                     &result);

        #line 194 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 196 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 198 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 199 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 199 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 203 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 204 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 204 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 209 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 209 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 213 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U && result.__variant == MyResult__Ok; i = i + 1U) {
        
        #line 215 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->stats_config_table.defined[__termina_array__index(4U,
                                                                    i)] == 1) {
            
            #line 217 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __option_box_t tm_handler2;
            #line 217 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            tm_handler2.__variant = None;

            #line 218 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                          &tm_handler2);

            #line 222 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (tm_handler2.__variant == Some) {
                
                #line 220 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                #line 224 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 225 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                   &tm_count);

                #line 227 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                PUSService4__build_tm_4_2(self,
                                          (TMHandlerT *)b_tm_handler2.data,
                                          tm_count, i, &result);

                #line 229 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 231 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler2, &result);

                    #line 233 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 234 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 234 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 238 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                    #line 239 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 239 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 243 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U, i)].samples = 0U;

                #line 244 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_obt_update;
                #line 244 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.finetime = 0U;
                #line 244 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_obt_update.seconds = 0U;

                #line 245 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt_update);

                #line 246 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->stats_config_table.start_time[__termina_array__index(4U,
                                                                           i)] = current_obt_update;

            } else
            {
                
                #line 249 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 249 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 255 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (result.__variant == MyResult__Ok) {
        
        #line 257 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __option_box_t tm_handler3;
        #line 257 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        tm_handler3.__variant = None;

        #line 258 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 262 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 260 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 264 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t tm_count3 = 0U;

            #line 265 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count3);

            #line 267 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 268 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         current_obt, &result);

            #line 270 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 272 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler3,
                                         &result);

                #line 274 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 275 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 275 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 279 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

                #line 280 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 280 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 284 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 284 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        

    }

    #line 295 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_6TC(PUSService4 * const self) {
    
    #line 301 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 301 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 302 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 302 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 304 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 304 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 304 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 306 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 306 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 307 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 311 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 309 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 313 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 314 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 316 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 318 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 319 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 322 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 324 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 326 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 327 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 327 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 331 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 332 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 332 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 338 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 340 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                result = PUSService4__add_PID_stats(self);

                #line 342 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 344 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 345 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    #line 347 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 349 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 351 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 352 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 352 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 356 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 357 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 357 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    #line 360 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 360 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 361 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 365 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 363 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 367 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 368 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 370 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 371 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, current_obt, &result);

                        #line 373 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 375 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 377 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 378 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 378 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 382 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 383 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 383 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 387 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 387 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 394 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 395 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_8_not_free_stats_config((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                                       self->exec_tc_req_status_update.PID,
                                                       current_obt, &result);

                    #line 398 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 400 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 402 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 403 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 403 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 407 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 408 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 408 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 416 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 417 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 420 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 422 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 424 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 425 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 425 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 429 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 430 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 430 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 437 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 437 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 441 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__exec4_7TC(PUSService4 * const self) {
    
    #line 447 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 447 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 448 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

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
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 457 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 455 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 459 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 460 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 462 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 464 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 465 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 468 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 470 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 472 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 473 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 473 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 477 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 478 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 478 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 484 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 486 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                result = PUSService4__delete_PID_stats(self);

                #line 488 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 490 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 491 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    #line 493 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 495 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 497 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 498 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 498 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 502 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 503 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 503 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    #line 506 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    __option_box_t tm_handler2;
                    #line 506 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    tm_handler2.__variant = None;

                    #line 507 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                  &tm_handler2);

                    #line 511 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (tm_handler2.__variant == Some) {
                        
                        #line 509 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                        #line 513 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        uint16_t tm_count2 = 0U;

                        #line 514 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                           &tm_count2);

                        #line 516 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                            &current_obt);

                        #line 517 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                     tm_count2, current_obt, &result);

                        #line 519 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 521 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler2, &result);

                            #line 523 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 524 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 524 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 528 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                            #line 529 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 529 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 534 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 534 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                    }

                } else
                {
                    
                    #line 541 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 542 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    build_tm_1_4_PID_stats_undefined((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     self->exec_tc_req_status_update.PID,
                                                     current_obt, &result);

                    #line 545 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 547 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 549 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 550 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 550 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 554 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 555 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 555 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 564 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 565 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 568 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 570 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 572 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 573 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 573 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 577 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 578 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 578 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 584 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 584 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 588 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PS4ExecTCReqStatusUpdate PUSService4__get_TC_params(const PUSService4 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 594 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PS4ExecTCReqStatusUpdate tc_data;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.N = 0U;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.PID = 0U;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_id = 0U;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.tc_num_bytes = 0U;
    #line 596 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.valid_index = 0U;

    #line 605 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 606 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 607 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 609 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (*subtype == 6U || *subtype == 7U) {
        
        #line 611 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

        #line 612 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    }

    #line 615 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService4__manage_error_in_acceptance(const PUSService4 * const self) {
    
    #line 663 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 663 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 664 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 664 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 666 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 666 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 666 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 668 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 668 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 669 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 673 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 671 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 675 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 676 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 678 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 679 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 682 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 684 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 686 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 687 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 687 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 691 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 692 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 692 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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

PSExecTCReqStatus PUSService4__manage_short_pack_length_error(const PUSService4 * const self) {
    
    #line 621 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    PSExecTCReqStatus next_status;
    #line 621 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 622 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MyResult result;
    #line 622 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    result.__variant = MyResult__Ok;

    #line 624 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    MissionObt current_obt;
    #line 624 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.finetime = 0U;
    #line 624 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    current_obt.seconds = 0U;

    #line 626 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    __option_box_t tm_handler;
    #line 626 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    tm_handler.__variant = None;

    #line 627 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 631 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (tm_handler.__variant == Some) {
        
        #line 629 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 633 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint16_t tm_count = 0U;

        #line 634 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 636 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 637 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 640 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 642 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 644 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 645 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 645 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 649 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 650 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 650 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 654 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 654 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 658 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    return next_status;

}

PSExecTCReqStatus PUSService4__manage_tm_limit_app_data_reached(const PUSService4 * const self) {
    
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
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
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

void PUSService4__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService4 * self = (PUSService4 *)__this;

    #line 750 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint8_t subtype = 0U;

    #line 752 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 756 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 758 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            MyResult result;
            #line 758 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            result.__variant = MyResult__Ok;

            #line 759 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status_update = PUSService4__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 761 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 762 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 762 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 764 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 768 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 770 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 1U) {
                
                #line 772 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_1TC(self);

            } else
            #line 774 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 6U) {
                
                #line 776 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_6TC(self);

            } else
            #line 778 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (subtype == 7U) {
                
                #line 780 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__exec4_7TC(self);

            } else
            {
                
                #line 784 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 784 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 787 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 754 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 789 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 791 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 794 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__manage_error_in_acceptance(self);

            } else
            #line 796 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 799 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__manage_tm_limit_app_data_reached(self);

            } else
            #line 801 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 803 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->exec_tc_req_status = PUSService4__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 811 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 754 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 813 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).__variant = Failure;
            #line 813 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 814 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 823 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 825 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 828 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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
    
    #line 895 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 896 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    uint32_t SDP_value = 0U;

    #line 899 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 900 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        uint8_t aux_value = 0U;

        #line 901 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 902 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = (uint32_t)aux_value;

    } else
    #line 904 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 905 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else
    {
        

    }

    #line 911 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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

    #line 1017 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 1019 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            #line 1021 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U, i)].samples = 0U;

            #line 1022 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            MissionObt current_obt;
            #line 1022 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.finetime = 0U;
            #line 1022 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            current_obt.seconds = 0U;

            #line 1023 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 1024 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.start_time[__termina_array__index(4U,
                                                                       i)] = current_obt;

        } else
        {
            
            #line 1028 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 1033 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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

    #line 944 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 946 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
        if (PUSService4__is_stats_index_defined(self, i) == 1) {
            
            #line 948 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            uint16_t PID = self->stats_config_table.PID[__termina_array__index(4U,
                                                                               i)];

            #line 950 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            if (self->param_stats[__termina_array__index(4U, i)].samples > 0U) {
                
                #line 952 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_higher_than_limit(self, i) == 1) {
                    
                    #line 954 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    #line 955 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max = system_data_pool_item;

                    #line 956 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 956 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 956 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 960 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_time);

                    #line 961 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].max_obt = current_time;

                } else
                #line 964 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                if (PUSService4__SDP_param_lower_than_limit(self, i) == 1) {
                    
                    #line 966 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                     PID);

                    #line 967 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min = system_data_pool_item;

                    #line 968 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    MissionObt current_time;
                    #line 968 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.finetime = 0U;
                    #line 968 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    current_time.seconds = 0U;

                    #line 972 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_time);

                    #line 973 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                    self->param_stats[__termina_array__index(4U,
                                                             i)].min_obt = current_time;

                } else
                {
                    

                }

                #line 979 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = PUSService4__SDP_get_mean(self,
                                                                                                    i);

            } else
            {
                
                #line 984 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                uint32_t system_data_pool_item = PUSService4__get_data_pool_item(self,
                                                                                 PID);

                #line 985 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max = system_data_pool_item;

                #line 986 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min = system_data_pool_item;

                #line 987 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].mean_value = system_data_pool_item;

                #line 988 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                MissionObt current_time;
                #line 988 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.finetime = 0U;
                #line 988 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                current_time.seconds = 0U;

                #line 992 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_time);

                #line 993 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].max_obt = current_time;

                #line 994 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
                self->param_stats[__termina_array__index(4U,
                                                         i)].min_obt = current_time;

            }

            #line 999 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->param_stats[__termina_array__index(4U,
                                                     i)].samples = self->param_stats[__termina_array__index(4U,
                                                                                                            i)].samples + 1U;

        } else
        {
            
            #line 1004 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
            self->stats_config_table.defined[__termina_array__index(4U, i)] = 0;

        }

    }

    #line 1011 "src/service_libraries/pus_services/pus_service4/pus_service4.fin"
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
