
#include "service_libraries/pus_services/pus_service3.h"

static __option_size_t CPUSService3__get_SIDindex(const __termina_event_t * const __ev, const CPUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

static __status_int32_t CPUSService3__exec3_31TC(const __termina_event_t * const __ev, CPUSService3 * const self, PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

static __status_int32_t CPUSService3__exec3_5TC(const __termina_event_t * const __ev, CPUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

static __status_int32_t CPUSService3__exec3_6TC(const __termina_event_t * const __ev, CPUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update);

void CPUSService3__do_hk(const __termina_event_t * const __ev, void * const __this, __status_int32_t * const action_status) {
    
    #line 312 "src/service_libraries/pus_services/pus_service3.fin"
    CPUSService3 * self = (CPUSService3 *)__this;

    #line 312 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 314 "src/service_libraries/pus_services/pus_service3.fin"
    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        #line 316 "src/service_libraries/pus_services/pus_service3.fin"
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == true) {
            
            #line 318 "src/service_libraries/pus_services/pus_service3.fin"
            self->hk_config_table[__termina_array__index(8U, i)].interval_control = self->hk_config_table[__termina_array__index(8U, i)].interval_control + 1U;

            #line 320 "src/service_libraries/pus_services/pus_service3.fin"
            if (self->hk_config_table[__termina_array__index(8U, i)].interval_control >= self->hk_config_table[__termina_array__index(8U, i)].interval) {
                
                #line 322 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, i)].interval_control = 0U;

                #line 324 "src/service_libraries/pus_services/pus_service3.fin"
                __option_box_t tm_handler = { .__variant = None };

                #line 325 "src/service_libraries/pus_services/pus_service3.fin"
                self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that, &tm_handler);

                #line 329 "src/service_libraries/pus_services/pus_service3.fin"
                if (tm_handler.__variant == Some) {
                    
                    #line 329 "src/service_libraries/pus_services/pus_service3.fin"
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    #line 331 "src/service_libraries/pus_services/pus_service3.fin"
                    uint16_t tm_count = 0U;

                    #line 332 "src/service_libraries/pus_services/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

                    #line 334 "src/service_libraries/pus_services/pus_service3.fin"
                    startup_tm((TMHandler *)b_tm_handler.data);

                    #line 335 "src/service_libraries/pus_services/pus_service3.fin"
                    __status_int32_t do_hk_status = append_u16_appdata_field((TMHandler *)b_tm_handler.data, self->hk_config_table[__termina_array__index(8U, i)].SID);

                    #line 337 "src/service_libraries/pus_services/pus_service3.fin"
                    uint32_t u32_SDP_value = 0U;

                    #line 338 "src/service_libraries/pus_services/pus_service3.fin"
                    uint8_t u8_SDP_value = 0U;

                    #line 340 "src/service_libraries/pus_services/pus_service3.fin"
                    for (size_t j = 0U; j < 16U && (j < (size_t)self->hk_config_table[__termina_array__index(8U, i)].num_params && do_hk_status.__variant == Success); j = j + 1U) {
                        
                        #line 342 "src/service_libraries/pus_services/pus_service3.fin"
                        uint16_t PID = self->hk_config_table[__termina_array__index(8U, i)].params_def[__termina_array__index(16U, j)];

                        #line 343 "src/service_libraries/pus_services/pus_service3.fin"
                        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

                        #line 346 "src/service_libraries/pus_services/pus_service3.fin"
                        if (item_type.__variant == DataPoolItemType__u8_t) {
                            
                            #line 347 "src/service_libraries/pus_services/pus_service3.fin"
                            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

                            #line 348 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status = append_u8_appdata_field((TMHandler *)b_tm_handler.data, u8_SDP_value);

                        } else
                        #line 350 "src/service_libraries/pus_services/pus_service3.fin"
                        if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 351 "src/service_libraries/pus_services/pus_service3.fin"
                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

                            #line 352 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status = append_u32_appdata_field((TMHandler *)b_tm_handler.data, u32_SDP_value);

                        } else
                        {
                            
                            #line 355 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status.__variant = Failure;
                            #line 355 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status.Failure.__0 = SDP_ITEM_TYPE_ERROR;

                        }

                    }

                    #line 361 "src/service_libraries/pus_services/pus_service3.fin"
                    MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

                    #line 362 "src/service_libraries/pus_services/pus_service3.fin"
                    self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

                    #line 364 "src/service_libraries/pus_services/pus_service3.fin"
                    if (do_hk_status.__variant == Success) {
                        
                        #line 365 "src/service_libraries/pus_services/pus_service3.fin"
                        close_tm((TMHandler *)b_tm_handler.data, 3U, 25U, tm_count, current_obt);

                        #line 366 "src/service_libraries/pus_services/pus_service3.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, &do_hk_status);

                    } else
                    {
                        
                        #line 370 "src/service_libraries/pus_services/pus_service3.fin"
                        self->pus_service_5.send_tm_5_2(__ev, self->pus_service_5.__that, &do_hk_status);

                        #line 371 "src/service_libraries/pus_services/pus_service3.fin"
                        self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that, b_tm_handler);

                    }

                } else
                {
                    
                    #line 377 "src/service_libraries/pus_services/pus_service3.fin"
                    (*action_status).__variant = Failure;
                    #line 377 "src/service_libraries/pus_services/pus_service3.fin"
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    #line 385 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 385 "src/service_libraries/pus_services/pus_service3.fin"
    return;

}

static __option_size_t CPUSService3__get_SIDindex(const __termina_event_t * const __ev, const CPUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update) {
    
    (void)__ev;

    #line 37 "src/service_libraries/pus_services/pus_service3.fin"
    __option_size_t index_found = { .__variant = None };

    #line 39 "src/service_libraries/pus_services/pus_service3.fin"
    for (size_t i = 0U; i < 8U && index_found.__variant == None; i = i + 1U) {
        
        #line 41 "src/service_libraries/pus_services/pus_service3.fin"
        if (exec_tc_req_status_update->SID == self->hk_config_table[__termina_array__index(8U, i)].SID) {
            
            #line 43 "src/service_libraries/pus_services/pus_service3.fin"
            index_found.__variant = Some;
            #line 43 "src/service_libraries/pus_services/pus_service3.fin"
            index_found.Some.__0 = i;

        }

    }

    #line 47 "src/service_libraries/pus_services/pus_service3.fin"
    return index_found;

}

static __status_int32_t CPUSService3__exec3_31TC(const __termina_event_t * const __ev, CPUSService3 * const self, PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update) {
    
    #line 168 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status = { .__variant = Success };

    #line 170 "src/service_libraries/pus_services/pus_service3.fin"
    if (exec_tc_req_status_update->N != 1U) {
        
        #line 172 "src/service_libraries/pus_services/pus_service3.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->N, &status);

    } else
    {
        
        #line 180 "src/service_libraries/pus_services/pus_service3.fin"
        __option_size_t opt_index = CPUSService3__get_SIDindex(__ev, self, exec_tc_req_status_update);

        #line 184 "src/service_libraries/pus_services/pus_service3.fin"
        if (opt_index.__variant == Some) {
            
            #line 184 "src/service_libraries/pus_services/pus_service3.fin"
            size_t index = opt_index.Some.__0;

            #line 186 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->flags_ack, &status);

            #line 192 "src/service_libraries/pus_services/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 194 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, index)].interval = exec_tc_req_status_update->collection_interval;

                #line 195 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, index)].interval_control = 0U;

                #line 197 "src/service_libraries/pus_services/pus_service3.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->flags_ack, &status);

            }

        } else
        {
            
            #line 208 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_SID_not_valid(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->SID, &status);

        }

    }

    #line 220 "src/service_libraries/pus_services/pus_service3.fin"
    return status;

}

static __status_int32_t CPUSService3__exec3_5TC(const __termina_event_t * const __ev, CPUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update) {
    
    #line 52 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status = { .__variant = Success };

    #line 54 "src/service_libraries/pus_services/pus_service3.fin"
    if (exec_tc_req_status_update->N != 1U) {
        
        #line 56 "src/service_libraries/pus_services/pus_service3.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->N, &status);

    } else
    {
        
        #line 64 "src/service_libraries/pus_services/pus_service3.fin"
        __option_size_t opt_index = CPUSService3__get_SIDindex(__ev, self, exec_tc_req_status_update);

        #line 68 "src/service_libraries/pus_services/pus_service3.fin"
        if (opt_index.__variant == Some) {
            
            #line 68 "src/service_libraries/pus_services/pus_service3.fin"
            size_t index = opt_index.Some.__0;

            #line 70 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->flags_ack, &status);

            #line 76 "src/service_libraries/pus_services/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 78 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, index)].enabled = true;

                #line 79 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, index)].interval_control = 0U;

                #line 81 "src/service_libraries/pus_services/pus_service3.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->flags_ack, &status);

            }

        } else
        {
            
            #line 93 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_SID_not_valid(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->SID, &status);

        }

    }

    #line 105 "src/service_libraries/pus_services/pus_service3.fin"
    return status;

}

static __status_int32_t CPUSService3__exec3_6TC(const __termina_event_t * const __ev, CPUSService3 * const self, const PS3ExecTCReqStatusUpdate * const exec_tc_req_status_update) {
    
    #line 110 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status = { .__variant = Success };

    #line 112 "src/service_libraries/pus_services/pus_service3.fin"
    if (exec_tc_req_status_update->N != 1U) {
        
        #line 114 "src/service_libraries/pus_services/pus_service3.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->N, &status);

    } else
    {
        
        #line 122 "src/service_libraries/pus_services/pus_service3.fin"
        __option_size_t opt_index = CPUSService3__get_SIDindex(__ev, self, exec_tc_req_status_update);

        #line 126 "src/service_libraries/pus_services/pus_service3.fin"
        if (opt_index.__variant == Some) {
            
            #line 126 "src/service_libraries/pus_services/pus_service3.fin"
            size_t index = opt_index.Some.__0;

            #line 128 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->flags_ack, &status);

            #line 134 "src/service_libraries/pus_services/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 136 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, index)].enabled = false;

                #line 137 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, index)].interval_control = 0U;

                #line 139 "src/service_libraries/pus_services/pus_service3.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->flags_ack, &status);

            }

        } else
        {
            
            #line 151 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_SID_not_valid(__ev, self->pus_service_1.__that, exec_tc_req_status_update->packet_id, exec_tc_req_status_update->packet_seq_ctrl, exec_tc_req_status_update->SID, &status);

        }

    }

    #line 162 "src/service_libraries/pus_services/pus_service3.fin"
    return status;

}

void CPUSService3__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 225 "src/service_libraries/pus_services/pus_service3.fin"
    CPUSService3 * self = (CPUSService3 *)__this;

    #line 225 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 227 "src/service_libraries/pus_services/pus_service3.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 228 "src/service_libraries/pus_services/pus_service3.fin"
    PS3ExecTCReqStatusUpdate exec_tc_req_status_update = { .N = 0U, .SID = 0U, .collection_interval = 0U, .flags_ack = 0U, .packet_id = 0U, .packet_seq_ctrl = 0U, .tc_num_bytes = 0U };

    #line 230 "src/service_libraries/pus_services/pus_service3.fin"
    exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 231 "src/service_libraries/pus_services/pus_service3.fin"
    exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 232 "src/service_libraries/pus_services/pus_service3.fin"
    exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 233 "src/service_libraries/pus_services/pus_service3.fin"
    exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 235 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status = tc_handler_get_u8_appdata_field(tc_handler, &exec_tc_req_status_update.N);

    #line 237 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 238 "src/service_libraries/pus_services/pus_service3.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &exec_tc_req_status_update.SID);

    }

    #line 241 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success && subtype == 31U) {
        
        #line 242 "src/service_libraries/pus_services/pus_service3.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &exec_tc_req_status_update.collection_interval);

    }

    #line 245 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 247 "src/service_libraries/pus_services/pus_service3.fin"
        if (subtype == 5U) {
            
            #line 249 "src/service_libraries/pus_services/pus_service3.fin"
            status = CPUSService3__exec3_5TC(__ev, self, &exec_tc_req_status_update);

        } else
        #line 251 "src/service_libraries/pus_services/pus_service3.fin"
        if (subtype == 6U) {
            
            #line 253 "src/service_libraries/pus_services/pus_service3.fin"
            status = CPUSService3__exec3_6TC(__ev, self, &exec_tc_req_status_update);

        } else
        #line 255 "src/service_libraries/pus_services/pus_service3.fin"
        if (subtype == 31U) {
            
            #line 257 "src/service_libraries/pus_services/pus_service3.fin"
            status = CPUSService3__exec3_31TC(__ev, self, &exec_tc_req_status_update);

        } else
        {
            
            #line 261 "src/service_libraries/pus_services/pus_service3.fin"
            status.__variant = Failure;
            #line 261 "src/service_libraries/pus_services/pus_service3.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 269 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 271 "src/service_libraries/pus_services/pus_service3.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 274 "src/service_libraries/pus_services/pus_service3.fin"
        int32_t error_code = status.Failure.__0;

        #line 277 "src/service_libraries/pus_services/pus_service3.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 279 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, exec_tc_req_status_update.packet_id, exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 284 "src/service_libraries/pus_services/pus_service3.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 286 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, exec_tc_req_status_update.packet_id, exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 291 "src/service_libraries/pus_services/pus_service3.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 293 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, exec_tc_req_status_update.packet_id, exec_tc_req_status_update.packet_seq_ctrl, exec_tc_req_status_update.tc_num_bytes, action_status);

        } else
        {
            
            #line 301 "src/service_libraries/pus_services/pus_service3.fin"
            (*action_status).__variant = Failure;
            #line 301 "src/service_libraries/pus_services/pus_service3.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 308 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 308 "src/service_libraries/pus_services/pus_service3.fin"
    return;

}

void CPUSService3__update_params(const __termina_event_t * const __ev, void * const __this) {
    
    #line 388 "src/service_libraries/pus_services/pus_service3.fin"
    CPUSService3 * self = (CPUSService3 *)__this;

    #line 388 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 390 "src/service_libraries/pus_services/pus_service3.fin"
    for (size_t i = 0U; i < 5U; i = i + 1U) {
        
        #line 392 "src/service_libraries/pus_services/pus_service3.fin"
        uint32_t random_noise = (uint32_t)(rand_r(&self->random_seed) % 11U) - 5U;

        #line 393 "src/service_libraries/pus_services/pus_service3.fin"
        uint32_t data = 0U;

        #line 395 "src/service_libraries/pus_services/pus_service3.fin"
        data = atomic_load(&self->system_data_pool_u32[i]);

        #line 396 "src/service_libraries/pus_services/pus_service3.fin"
        data = data + random_noise;

        #line 398 "src/service_libraries/pus_services/pus_service3.fin"
        atomic_store(&self->system_data_pool_u32[i], data);

    }

    #line 401 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 401 "src/service_libraries/pus_services/pus_service3.fin"
    return;

}
