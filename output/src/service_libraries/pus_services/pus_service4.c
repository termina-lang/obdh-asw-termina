
#include "service_libraries/pus_services/pus_service4.h"

static uint32_t CPUSService4__SDP_get_mean(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t pid_index);

static _Bool CPUSService4__SDP_param_higher_than_limit(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t pid_index);

static _Bool CPUSService4__SDP_param_lower_than_limit(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t pid_index);

static Status__i32 CPUSService4__get_PID_defined_stats_index(const termina__event_t * const termina__ev, CPUSService4 * const self);

static IndexStatus CPUSService4__get_free_index(const termina__event_t * const termina__ev, const CPUSService4 * const self);

static Status__i32 CPUSService4__add_PID_stats(const termina__event_t * const termina__ev, CPUSService4 * const self);

static Status__i32 CPUSService4__delete_PID_stats(const termina__event_t * const termina__ev, CPUSService4 * const self);

static Status__i32 CPUSService4__exec4_1TC(const termina__event_t * const termina__ev, CPUSService4 * const self);

static Status__i32 CPUSService4__exec4_6TC(const termina__event_t * const termina__ev, CPUSService4 * const self);

static Status__i32 CPUSService4__exec4_7TC(const termina__event_t * const termina__ev, CPUSService4 * const self);

static uint32_t CPUSService4__get_data_pool_item(const termina__event_t * const termina__ev, const CPUSService4 * const self, uint16_t PID);

static _Bool CPUSService4__is_stats_index_defined(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t stats_index);

static uint32_t CPUSService4__SDP_get_mean(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t pid_index) {
    
    (void)termina__ev;

    #line 491 "src/service_libraries/pus_services/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[termina__check__array_index(4U, pid_index)];

    #line 492 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t mean_value = 0U;

    #line 494 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 497 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u8_t) {
        
        #line 498 "src/service_libraries/pus_services/pus_service4.fin"
        uint8_t u8_SDP_value = 0U;

        #line 499 "src/service_libraries/pus_services/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 500 "src/service_libraries/pus_services/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[termina__check__array_index(4U, pid_index)].mean_value * self->param_stats[termina__check__array_index(4U, pid_index)].samples) + (uint32_t)u8_SDP_value) / (uint32_t)(self->param_stats[termina__check__array_index(4U, pid_index)].samples + 1U);

    } else
    #line 502 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u32_t) {
        
        #line 503 "src/service_libraries/pus_services/pus_service4.fin"
        uint32_t u32_SDP_value = 0U;

        #line 504 "src/service_libraries/pus_services/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 505 "src/service_libraries/pus_services/pus_service4.fin"
        mean_value = (uint32_t)((uint32_t)(self->param_stats[termina__check__array_index(4U, pid_index)].mean_value * self->param_stats[termina__check__array_index(4U, pid_index)].samples) + u32_SDP_value) / (uint32_t)(self->param_stats[termina__check__array_index(4U, pid_index)].samples + 1U);

    } else
    {
        

    }

    #line 512 "src/service_libraries/pus_services/pus_service4.fin"
    return mean_value;

}

static _Bool CPUSService4__SDP_param_higher_than_limit(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t pid_index) {
    
    (void)termina__ev;

    #line 407 "src/service_libraries/pus_services/pus_service4.fin"
    _Bool is_higher = false;

    #line 408 "src/service_libraries/pus_services/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[termina__check__array_index(4U, pid_index)];

    #line 410 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 413 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u8_t) {
        
        #line 414 "src/service_libraries/pus_services/pus_service4.fin"
        uint8_t u8_SDP_value = 0U;

        #line 415 "src/service_libraries/pus_services/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 416 "src/service_libraries/pus_services/pus_service4.fin"
        if ((uint32_t)u8_SDP_value > self->param_stats[termina__check__array_index(4U, pid_index)].max) {
            
            #line 417 "src/service_libraries/pus_services/pus_service4.fin"
            is_higher = true;

        }

    } else
    #line 420 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u32_t) {
        
        #line 421 "src/service_libraries/pus_services/pus_service4.fin"
        uint32_t u32_SDP_value = 0U;

        #line 422 "src/service_libraries/pus_services/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 423 "src/service_libraries/pus_services/pus_service4.fin"
        if (u32_SDP_value > self->param_stats[termina__check__array_index(4U, pid_index)].max) {
            
            #line 424 "src/service_libraries/pus_services/pus_service4.fin"
            is_higher = true;

        }

    } else
    {
        

    }

    #line 432 "src/service_libraries/pus_services/pus_service4.fin"
    return is_higher;

}

static _Bool CPUSService4__SDP_param_lower_than_limit(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t pid_index) {
    
    (void)termina__ev;

    #line 438 "src/service_libraries/pus_services/pus_service4.fin"
    _Bool is_lower = false;

    #line 439 "src/service_libraries/pus_services/pus_service4.fin"
    uint16_t PID = self->stats_config_table.PID[termina__check__array_index(4U, pid_index)];

    #line 441 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 444 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u8_t) {
        
        #line 445 "src/service_libraries/pus_services/pus_service4.fin"
        uint8_t u8_SDP_value = 0U;

        #line 446 "src/service_libraries/pus_services/pus_service4.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 447 "src/service_libraries/pus_services/pus_service4.fin"
        if ((uint32_t)u8_SDP_value < self->param_stats[termina__check__array_index(4U, pid_index)].min) {
            
            #line 448 "src/service_libraries/pus_services/pus_service4.fin"
            is_lower = true;

        }

    } else
    #line 451 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u32_t) {
        
        #line 452 "src/service_libraries/pus_services/pus_service4.fin"
        uint32_t u32_SDP_value = 0U;

        #line 453 "src/service_libraries/pus_services/pus_service4.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

        #line 454 "src/service_libraries/pus_services/pus_service4.fin"
        if (u32_SDP_value < self->param_stats[termina__check__array_index(4U, pid_index)].min) {
            
            #line 455 "src/service_libraries/pus_services/pus_service4.fin"
            is_lower = true;

        }

    } else
    {
        

    }

    #line 463 "src/service_libraries/pus_services/pus_service4.fin"
    return is_lower;

}

static Status__i32 CPUSService4__get_PID_defined_stats_index(const termina__event_t * const termina__ev, CPUSService4 * const self) {
    
    (void)termina__ev;

    #line 36 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = { ._variant = Status__Failure, .Failure = { ._0 = INVALID_PID_ERROR } };

    #line 38 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status._variant == Status__Failure; i = i + 1U) {
        
        #line 40 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->exec_tc_req_status_update.PID == self->stats_config_table.PID[termina__check__array_index(4U, i)]) {
            
            #line 42 "src/service_libraries/pus_services/pus_service4.fin"
            if (self->stats_config_table.defined[termina__check__array_index(4U, i)] == true) {
                
                #line 44 "src/service_libraries/pus_services/pus_service4.fin"
                if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                    
                    #line 46 "src/service_libraries/pus_services/pus_service4.fin"
                    self->exec_tc_req_status_update.valid_index = i;

                    #line 47 "src/service_libraries/pus_services/pus_service4.fin"
                    status._variant = Status__Success;

                } else
                {
                    
                    #line 50 "src/service_libraries/pus_services/pus_service4.fin"
                    self->stats_config_table.defined[termina__check__array_index(4U, i)] = false;

                }

            }

        }

    }

    #line 57 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

static IndexStatus CPUSService4__get_free_index(const termina__event_t * const termina__ev, const CPUSService4 * const self) {
    
    (void)termina__ev;

    #line 62 "src/service_libraries/pus_services/pus_service4.fin"
    IndexStatus id_status = { .index = 0U, .status = { ._variant = Status__Failure, .Failure = { ._0 = NO_FREE_STATS_INDEX_ERROR } } };

    #line 64 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U && id_status.status._variant == Status__Failure; i = i + 1U) {
        
        #line 66 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->stats_config_table.defined[termina__check__array_index(4U, i)] == false || sys_data_pool_is_valid_PID(self->stats_config_table.PID[termina__check__array_index(4U, i)]) == false) {
            
            #line 68 "src/service_libraries/pus_services/pus_service4.fin"
            id_status.index = i;

            #line 69 "src/service_libraries/pus_services/pus_service4.fin"
            id_status.status._variant = Status__Success;

        }

    }

    #line 72 "src/service_libraries/pus_services/pus_service4.fin"
    return id_status;

}

static Status__i32 CPUSService4__add_PID_stats(const termina__event_t * const termina__ev, CPUSService4 * const self) {
    
    #line 98 "src/service_libraries/pus_services/pus_service4.fin"
    IndexStatus index_status = { .index = 0U, .status = { ._variant = Status__Success } };

    #line 99 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = CPUSService4__get_PID_defined_stats_index(termina__ev, self);

    #line 101 "src/service_libraries/pus_services/pus_service4.fin"
    if (status._variant == Status__Failure) {
        
        #line 103 "src/service_libraries/pus_services/pus_service4.fin"
        index_status = CPUSService4__get_free_index(termina__ev, self);

        #line 104 "src/service_libraries/pus_services/pus_service4.fin"
        self->exec_tc_req_status_update.valid_index = index_status.index;

    }

    #line 107 "src/service_libraries/pus_services/pus_service4.fin"
    if (index_status.status._variant == Status__Success) {
        
        #line 109 "src/service_libraries/pus_services/pus_service4.fin"
        size_t PID_index = self->exec_tc_req_status_update.valid_index;

        #line 111 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.defined[termina__check__array_index(4U, PID_index)] = true;

        #line 112 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.PID[termina__check__array_index(4U, PID_index)] = self->exec_tc_req_status_update.PID;

        #line 114 "src/service_libraries/pus_services/pus_service4.fin"
        self->param_stats[termina__check__array_index(4U, PID_index)].samples = 0U;

        #line 115 "src/service_libraries/pus_services/pus_service4.fin"
        MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

        #line 116 "src/service_libraries/pus_services/pus_service4.fin"
        self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_obt);

        #line 117 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.start_time[termina__check__array_index(4U, PID_index)] = current_obt;

        #line 118 "src/service_libraries/pus_services/pus_service4.fin"
        status._variant = Status__Success;

    } else
    {
        
        #line 122 "src/service_libraries/pus_services/pus_service4.fin"
        status._variant = Status__Failure;
        #line 122 "src/service_libraries/pus_services/pus_service4.fin"
        status.Failure._0 = NO_FREE_STATS_INDEX_ERROR;

    }

    #line 125 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

static Status__i32 CPUSService4__delete_PID_stats(const termina__event_t * const termina__ev, CPUSService4 * const self) {
    
    #line 130 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = CPUSService4__get_PID_defined_stats_index(termina__ev, self);

    #line 132 "src/service_libraries/pus_services/pus_service4.fin"
    if (status._variant == Status__Success) {
        
        #line 133 "src/service_libraries/pus_services/pus_service4.fin"
        self->stats_config_table.defined[termina__check__array_index(4U, self->exec_tc_req_status_update.valid_index)] = false;

    }

    #line 136 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

static Status__i32 CPUSService4__exec4_1TC(const termina__event_t * const termina__ev, CPUSService4 * const self) {
    
    #line 143 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 145 "src/service_libraries/pus_services/pus_service4.fin"
    self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

    #line 151 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U && status._variant == Status__Success; i = i + 1U) {
        
        #line 153 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->stats_config_table.defined[termina__check__array_index(4U, i)] == true) {
            
            #line 155 "src/service_libraries/pus_services/pus_service4.fin"
            Option__box tm_handler = { ._variant = Option__None };

            #line 156 "src/service_libraries/pus_services/pus_service4.fin"
            self->tm_handler_pool.alloc(termina__ev, self->tm_handler_pool._that, &tm_handler);

            #line 160 "src/service_libraries/pus_services/pus_service4.fin"
            if (tm_handler._variant == Option__Some) {
                
                #line 160 "src/service_libraries/pus_services/pus_service4.fin"
                termina__box_t b_tm_handler = tm_handler.Some._0;

                #line 162 "src/service_libraries/pus_services/pus_service4.fin"
                MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

                #line 163 "src/service_libraries/pus_services/pus_service4.fin"
                uint16_t tm_count = 0U;

                #line 165 "src/service_libraries/pus_services/pus_service4.fin"
                self->tm_counter.get_next_tm_count(termina__ev, self->tm_counter._that, &tm_count);

                #line 166 "src/service_libraries/pus_services/pus_service4.fin"
                self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_obt);

                #line 168 "src/service_libraries/pus_services/pus_service4.fin"
                status = build_tm_4_2((TMHandler *)b_tm_handler.data, tm_count, i, self->exec_tc_req_status_update.N, &self->stats_config_table, self->param_stats, current_obt);

                #line 170 "src/service_libraries/pus_services/pus_service4.fin"
                if (status._variant == Status__Success) {
                    
                    #line 172 "src/service_libraries/pus_services/pus_service4.fin"
                    self->tm_channel.send_tm(termina__ev, self->tm_channel._that, b_tm_handler, &status);

                } else
                {
                    
                    #line 176 "src/service_libraries/pus_services/pus_service4.fin"
                    self->tm_handler_pool.free(termina__ev, self->tm_handler_pool._that, b_tm_handler);

                }

                #line 181 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].samples = 0U;

                #line 182 "src/service_libraries/pus_services/pus_service4.fin"
                MissionOBT current_obt_update = { .finetime = 0U, .seconds = 0U };

                #line 183 "src/service_libraries/pus_services/pus_service4.fin"
                self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_obt_update);

                #line 184 "src/service_libraries/pus_services/pus_service4.fin"
                self->stats_config_table.start_time[termina__check__array_index(4U, i)] = current_obt_update;

            } else
            {
                
                #line 187 "src/service_libraries/pus_services/pus_service4.fin"
                status._variant = Status__Failure;
                #line 187 "src/service_libraries/pus_services/pus_service4.fin"
                status.Failure._0 = TM_POOL_ALLOC_FAILURE;

            }

        }

    }

    #line 193 "src/service_libraries/pus_services/pus_service4.fin"
    if (status._variant == Status__Success) {
        
        #line 195 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

    } else
    {
        

    }

    #line 208 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

static Status__i32 CPUSService4__exec4_6TC(const termina__event_t * const termina__ev, CPUSService4 * const self) {
    
    #line 214 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 216 "src/service_libraries/pus_services/pus_service4.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 218 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 224 "src/service_libraries/pus_services/pus_service4.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID) == false) {
        
        #line 226 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.PID, &status);

    } else
    {
        
        #line 234 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 240 "src/service_libraries/pus_services/pus_service4.fin"
        if (status._variant == Status__Success) {
            
            #line 241 "src/service_libraries/pus_services/pus_service4.fin"
            status = CPUSService4__add_PID_stats(termina__ev, self);

        }

        #line 244 "src/service_libraries/pus_services/pus_service4.fin"
        if (status._variant == Status__Success) {
            
            #line 246 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        } else
        {
            
            #line 254 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_8_not_free_stats_config(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.PID, &status);

        }

    }

    #line 264 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

static Status__i32 CPUSService4__exec4_7TC(const termina__event_t * const termina__ev, CPUSService4 * const self) {
    
    #line 270 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 272 "src/service_libraries/pus_services/pus_service4.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 274 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 280 "src/service_libraries/pus_services/pus_service4.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID) == false) {
        
        #line 282 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.PID, &status);

    } else
    {
        
        #line 290 "src/service_libraries/pus_services/pus_service4.fin"
        self->pus_service_1.notify_tm_1_3(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 296 "src/service_libraries/pus_services/pus_service4.fin"
        if (status._variant == Status__Success) {
            
            #line 297 "src/service_libraries/pus_services/pus_service4.fin"
            status = CPUSService4__delete_PID_stats(termina__ev, self);

        }

        #line 300 "src/service_libraries/pus_services/pus_service4.fin"
        if (status._variant == Status__Success) {
            
            #line 302 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.notify_tm_1_7(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        } else
        {
            
            #line 310 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_4_PID_stats_undefined(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.PID, &status);

        }

    }

    #line 319 "src/service_libraries/pus_services/pus_service4.fin"
    return status;

}

void CPUSService4__exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const action_status) {
    
    #line 322 "src/service_libraries/pus_services/pus_service4.fin"
    CPUSService4 * self = (CPUSService4 *)termina__this;

    #line 322 "src/service_libraries/pus_services/pus_service4.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 324 "src/service_libraries/pus_services/pus_service4.fin"
    Status__i32 status = { ._variant = Status__Success };

    #line 325 "src/service_libraries/pus_services/pus_service4.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 327 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 328 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 329 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 330 "src/service_libraries/pus_services/pus_service4.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 332 "src/service_libraries/pus_services/pus_service4.fin"
    if (subtype == 6U || subtype == 7U) {
        
        #line 334 "src/service_libraries/pus_services/pus_service4.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.N);

        #line 335 "src/service_libraries/pus_services/pus_service4.fin"
        if (status._variant == Status__Success) {
            
            #line 336 "src/service_libraries/pus_services/pus_service4.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.PID);

        }

    }

    #line 341 "src/service_libraries/pus_services/pus_service4.fin"
    if (status._variant == Status__Success) {
        
        #line 343 "src/service_libraries/pus_services/pus_service4.fin"
        if (subtype == 1U) {
            
            #line 345 "src/service_libraries/pus_services/pus_service4.fin"
            status = CPUSService4__exec4_1TC(termina__ev, self);

        } else
        #line 347 "src/service_libraries/pus_services/pus_service4.fin"
        if (subtype == 6U) {
            
            #line 349 "src/service_libraries/pus_services/pus_service4.fin"
            status = CPUSService4__exec4_6TC(termina__ev, self);

        } else
        #line 351 "src/service_libraries/pus_services/pus_service4.fin"
        if (subtype == 7U) {
            
            #line 353 "src/service_libraries/pus_services/pus_service4.fin"
            status = CPUSService4__exec4_7TC(termina__ev, self);

        } else
        {
            
            #line 357 "src/service_libraries/pus_services/pus_service4.fin"
            status._variant = Status__Failure;
            #line 357 "src/service_libraries/pus_services/pus_service4.fin"
            status.Failure._0 = ACCEPTANCE_ERROR;

        }

    }

    #line 364 "src/service_libraries/pus_services/pus_service4.fin"
    if (status._variant == Status__Success) {
        
        #line 366 "src/service_libraries/pus_services/pus_service4.fin"
        (*action_status)._variant = Status__Success;

    } else
    {
        
        #line 369 "src/service_libraries/pus_services/pus_service4.fin"
        int32_t error_code = status.Failure._0;

        #line 371 "src/service_libraries/pus_services/pus_service4.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 373 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, &status);

        } else
        #line 378 "src/service_libraries/pus_services/pus_service4.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 380 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, &status);

        } else
        #line 385 "src/service_libraries/pus_services/pus_service4.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 387 "src/service_libraries/pus_services/pus_service4.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(termina__ev, self->pus_service_1._that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_num_bytes, &status);

        } else
        {
            
            #line 395 "src/service_libraries/pus_services/pus_service4.fin"
            (*action_status)._variant = Status__Failure;
            #line 395 "src/service_libraries/pus_services/pus_service4.fin"
            (*action_status).Failure._0 = error_code;

        }

    }

    #line 401 "src/service_libraries/pus_services/pus_service4.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 401 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}

static uint32_t CPUSService4__get_data_pool_item(const termina__event_t * const termina__ev, const CPUSService4 * const self, uint16_t PID) {
    
    (void)termina__ev;

    #line 468 "src/service_libraries/pus_services/pus_service4.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

    #line 469 "src/service_libraries/pus_services/pus_service4.fin"
    uint32_t SDP_value = 0U;

    #line 472 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u8_t) {
        
        #line 473 "src/service_libraries/pus_services/pus_service4.fin"
        uint8_t aux_value = 0U;

        #line 474 "src/service_libraries/pus_services/pus_service4.fin"
        aux_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

        #line 475 "src/service_libraries/pus_services/pus_service4.fin"
        SDP_value = (uint32_t)aux_value;

    } else
    #line 477 "src/service_libraries/pus_services/pus_service4.fin"
    if (item_type._variant == DataPoolItemType__u32_t) {
        
        #line 478 "src/service_libraries/pus_services/pus_service4.fin"
        SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

    } else
    {
        

    }

    #line 484 "src/service_libraries/pus_services/pus_service4.fin"
    return SDP_value;

}

static _Bool CPUSService4__is_stats_index_defined(const termina__event_t * const termina__ev, const CPUSService4 * const self, size_t stats_index) {
    
    (void)termina__ev;

    #line 77 "src/service_libraries/pus_services/pus_service4.fin"
    _Bool is_defined = false;

    #line 79 "src/service_libraries/pus_services/pus_service4.fin"
    if (stats_index < 4U) {
        
        #line 81 "src/service_libraries/pus_services/pus_service4.fin"
        if (self->stats_config_table.defined[termina__check__array_index(4U, stats_index)] == true) {
            
            #line 83 "src/service_libraries/pus_services/pus_service4.fin"
            if (sys_data_pool_is_valid_PID(self->stats_config_table.PID[termina__check__array_index(4U, stats_index)])) {
                
                #line 85 "src/service_libraries/pus_services/pus_service4.fin"
                is_defined = true;

            } else
            {
                

            }

        }

    }

    #line 93 "src/service_libraries/pus_services/pus_service4.fin"
    return is_defined;

}

void CPUSService4__startup(const termina__event_t * const termina__ev, void * const termina__this) {
    
    #line 588 "src/service_libraries/pus_services/pus_service4.fin"
    CPUSService4 * self = (CPUSService4 *)termina__this;

    #line 588 "src/service_libraries/pus_services/pus_service4.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 590 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 592 "src/service_libraries/pus_services/pus_service4.fin"
        if (CPUSService4__is_stats_index_defined(termina__ev, self, i) == true) {
            
            #line 594 "src/service_libraries/pus_services/pus_service4.fin"
            self->param_stats[termina__check__array_index(4U, i)].samples = 0U;

            #line 595 "src/service_libraries/pus_services/pus_service4.fin"
            MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

            #line 596 "src/service_libraries/pus_services/pus_service4.fin"
            self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_obt);

            #line 597 "src/service_libraries/pus_services/pus_service4.fin"
            self->stats_config_table.start_time[termina__check__array_index(4U, i)] = current_obt;

        } else
        {
            
            #line 601 "src/service_libraries/pus_services/pus_service4.fin"
            self->stats_config_table.defined[termina__check__array_index(4U, i)] = false;

        }

    }

    #line 606 "src/service_libraries/pus_services/pus_service4.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 606 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}

void CPUSService4__update_all_stats(const termina__event_t * const termina__ev, void * const termina__this) {
    
    #line 515 "src/service_libraries/pus_services/pus_service4.fin"
    CPUSService4 * self = (CPUSService4 *)termina__this;

    #line 515 "src/service_libraries/pus_services/pus_service4.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 517 "src/service_libraries/pus_services/pus_service4.fin"
    for (size_t i = 0U; i < 4U; i = i + 1U) {
        
        #line 519 "src/service_libraries/pus_services/pus_service4.fin"
        if (CPUSService4__is_stats_index_defined(termina__ev, self, i) == true) {
            
            #line 521 "src/service_libraries/pus_services/pus_service4.fin"
            uint16_t PID = self->stats_config_table.PID[termina__check__array_index(4U, i)];

            #line 523 "src/service_libraries/pus_services/pus_service4.fin"
            if (self->param_stats[termina__check__array_index(4U, i)].samples > 0U) {
                
                #line 525 "src/service_libraries/pus_services/pus_service4.fin"
                if (CPUSService4__SDP_param_higher_than_limit(termina__ev, self, i) == true) {
                    
                    #line 527 "src/service_libraries/pus_services/pus_service4.fin"
                    uint32_t system_data_pool_item = CPUSService4__get_data_pool_item(termina__ev, self, PID);

                    #line 528 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[termina__check__array_index(4U, i)].max = system_data_pool_item;

                    #line 529 "src/service_libraries/pus_services/pus_service4.fin"
                    MissionOBT current_time = { .finetime = 0U, .seconds = 0U };

                    #line 533 "src/service_libraries/pus_services/pus_service4.fin"
                    self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_time);

                    #line 534 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[termina__check__array_index(4U, i)].max_obt = current_time;

                } else
                #line 537 "src/service_libraries/pus_services/pus_service4.fin"
                if (CPUSService4__SDP_param_lower_than_limit(termina__ev, self, i) == true) {
                    
                    #line 539 "src/service_libraries/pus_services/pus_service4.fin"
                    uint32_t system_data_pool_item = CPUSService4__get_data_pool_item(termina__ev, self, PID);

                    #line 540 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[termina__check__array_index(4U, i)].min = system_data_pool_item;

                    #line 541 "src/service_libraries/pus_services/pus_service4.fin"
                    MissionOBT current_time = { .finetime = 0U, .seconds = 0U };

                    #line 545 "src/service_libraries/pus_services/pus_service4.fin"
                    self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_time);

                    #line 546 "src/service_libraries/pus_services/pus_service4.fin"
                    self->param_stats[termina__check__array_index(4U, i)].min_obt = current_time;

                } else
                {
                    

                }

                #line 552 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].mean_value = CPUSService4__SDP_get_mean(termina__ev, self, i);

            } else
            {
                
                #line 557 "src/service_libraries/pus_services/pus_service4.fin"
                uint32_t system_data_pool_item = CPUSService4__get_data_pool_item(termina__ev, self, PID);

                #line 558 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].max = system_data_pool_item;

                #line 559 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].min = system_data_pool_item;

                #line 560 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].mean_value = system_data_pool_item;

                #line 561 "src/service_libraries/pus_services/pus_service4.fin"
                MissionOBT current_time = { .finetime = 0U, .seconds = 0U };

                #line 565 "src/service_libraries/pus_services/pus_service4.fin"
                self->obt_manager.get_current_obt(termina__ev, self->obt_manager._that, &current_time);

                #line 566 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].max_obt = current_time;

                #line 567 "src/service_libraries/pus_services/pus_service4.fin"
                self->param_stats[termina__check__array_index(4U, i)].min_obt = current_time;

            }

            #line 572 "src/service_libraries/pus_services/pus_service4.fin"
            self->param_stats[termina__check__array_index(4U, i)].samples = self->param_stats[termina__check__array_index(4U, i)].samples + 1U;

        } else
        {
            
            #line 577 "src/service_libraries/pus_services/pus_service4.fin"
            self->stats_config_table.defined[termina__check__array_index(4U, i)] = false;

        }

    }

    #line 584 "src/service_libraries/pus_services/pus_service4.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 584 "src/service_libraries/pus_services/pus_service4.fin"
    return;

}
