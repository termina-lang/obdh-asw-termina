
#include "service_libraries/pus_services/pus_service3.h"

void PUSService3__do_hk(const __termina_event_t * const __ev, void * const __this, __status_int32_t * const action_status) {
    
    #line 298 "src/service_libraries/pus_services/pus_service3.fin"
    PUSService3 * self = (PUSService3 *)__this;

    #line 298 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 300 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t do_hk_status;
    #line 300 "src/service_libraries/pus_services/pus_service3.fin"
    do_hk_status.__variant = Success;

    #line 302 "src/service_libraries/pus_services/pus_service3.fin"
    for (size_t i = 0U; i < 8U && (*action_status).__variant == Success; i = i + 1U) {
        
        #line 304 "src/service_libraries/pus_services/pus_service3.fin"
        if (self->hk_config_table[__termina_array__index(8U, i)].enabled == 1) {
            
            #line 306 "src/service_libraries/pus_services/pus_service3.fin"
            self->hk_config_table[__termina_array__index(8U, i)].interval_control = self->hk_config_table[__termina_array__index(8U, i)].interval_control + 1U;

            #line 308 "src/service_libraries/pus_services/pus_service3.fin"
            if (self->hk_config_table[__termina_array__index(8U, i)].interval_control >= self->hk_config_table[__termina_array__index(8U, i)].interval) {
                
                #line 310 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, i)].interval_control = 0U;

                #line 312 "src/service_libraries/pus_services/pus_service3.fin"
                __option_box_t tm_handler;
                #line 312 "src/service_libraries/pus_services/pus_service3.fin"
                tm_handler.__variant = None;

                #line 313 "src/service_libraries/pus_services/pus_service3.fin"
                self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that, &tm_handler);

                #line 317 "src/service_libraries/pus_services/pus_service3.fin"
                if (tm_handler.__variant == Some) {
                    
                    #line 317 "src/service_libraries/pus_services/pus_service3.fin"
                    __termina_box_t b_tm_handler = tm_handler.Some.__0;

                    #line 319 "src/service_libraries/pus_services/pus_service3.fin"
                    uint16_t tm_count = 0U;

                    #line 320 "src/service_libraries/pus_services/pus_service3.fin"
                    self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

                    #line 322 "src/service_libraries/pus_services/pus_service3.fin"
                    startup_tm((TMHandler *)b_tm_handler.data);

                    #line 323 "src/service_libraries/pus_services/pus_service3.fin"
                    do_hk_status = append_u16_appdata_field((TMHandler *)b_tm_handler.data, self->hk_config_table[__termina_array__index(8U, i)].SID);

                    #line 325 "src/service_libraries/pus_services/pus_service3.fin"
                    uint16_t PID = 0U;

                    #line 326 "src/service_libraries/pus_services/pus_service3.fin"
                    uint32_t u32_SDP_value = 0U;

                    #line 327 "src/service_libraries/pus_services/pus_service3.fin"
                    uint8_t u8_SDP_value = 0U;

                    #line 329 "src/service_libraries/pus_services/pus_service3.fin"
                    for (size_t j = 0U; j < 16U && (j < (size_t)self->hk_config_table[__termina_array__index(8U, i)].num_params && do_hk_status.__variant == Success); j = j + 1U) {
                        
                        #line 331 "src/service_libraries/pus_services/pus_service3.fin"
                        PID = self->hk_config_table[__termina_array__index(8U, i)].params_def[__termina_array__index(16U, j)];

                        #line 332 "src/service_libraries/pus_services/pus_service3.fin"
                        DataPoolItemType item_type = sys_data_pool_get_item_type(PID);

                        #line 335 "src/service_libraries/pus_services/pus_service3.fin"
                        if (item_type.__variant == DataPoolItemType__u8_t) {
                            
                            #line 336 "src/service_libraries/pus_services/pus_service3.fin"
                            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)PID]);

                            #line 337 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status = append_u8_appdata_field((TMHandler *)b_tm_handler.data, u8_SDP_value);

                        } else
                        #line 339 "src/service_libraries/pus_services/pus_service3.fin"
                        if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 340 "src/service_libraries/pus_services/pus_service3.fin"
                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)PID]);

                            #line 341 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status = append_u32_appdata_field((TMHandler *)b_tm_handler.data, u32_SDP_value);

                        } else
                        {
                            
                            #line 344 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status.__variant = Failure;
                            #line 344 "src/service_libraries/pus_services/pus_service3.fin"
                            do_hk_status.Failure.__0 = SDP_ITEM_TYPE_ERROR;

                        }

                    }

                    #line 350 "src/service_libraries/pus_services/pus_service3.fin"
                    MissionOBT current_obt;
                    #line 350 "src/service_libraries/pus_services/pus_service3.fin"
                    current_obt.finetime = 0U;
                    #line 350 "src/service_libraries/pus_services/pus_service3.fin"
                    current_obt.seconds = 0U;

                    #line 351 "src/service_libraries/pus_services/pus_service3.fin"
                    self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

                    #line 353 "src/service_libraries/pus_services/pus_service3.fin"
                    if (do_hk_status.__variant == Success) {
                        
                        #line 354 "src/service_libraries/pus_services/pus_service3.fin"
                        close_tm((TMHandler *)b_tm_handler.data, 3U, 25U, tm_count, current_obt);

                        #line 355 "src/service_libraries/pus_services/pus_service3.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, &do_hk_status);

                    } else
                    {
                        
                        #line 359 "src/service_libraries/pus_services/pus_service3.fin"
                        self->pus_service_5.send_tm_5_2(__ev, self->pus_service_5.__that, &do_hk_status);

                        #line 360 "src/service_libraries/pus_services/pus_service3.fin"
                        self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that, b_tm_handler);

                    }

                } else
                {
                    
                    #line 366 "src/service_libraries/pus_services/pus_service3.fin"
                    (*action_status).__variant = Failure;
                    #line 366 "src/service_libraries/pus_services/pus_service3.fin"
                    (*action_status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    }

    #line 374 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 374 "src/service_libraries/pus_services/pus_service3.fin"
    return;

}

IndexFound PUSService3__get_SIDindex(const __termina_event_t * const __ev, const PUSService3 * const self) {
    
    #line 39 "src/service_libraries/pus_services/pus_service3.fin"
    IndexFound index_found;
    #line 39 "src/service_libraries/pus_services/pus_service3.fin"
    index_found.found = 0;
    #line 39 "src/service_libraries/pus_services/pus_service3.fin"
    index_found.index = 0U;

    #line 41 "src/service_libraries/pus_services/pus_service3.fin"
    for (size_t i = 0U; i < 8U && index_found.found == 0; i = i + 1U) {
        
        #line 43 "src/service_libraries/pus_services/pus_service3.fin"
        if (self->exec_tc_req_status_update.tc_data.SID == self->hk_config_table[__termina_array__index(8U, i)].SID) {
            
            #line 45 "src/service_libraries/pus_services/pus_service3.fin"
            index_found.found = 1;

            #line 46 "src/service_libraries/pus_services/pus_service3.fin"
            index_found.index = i;

        }

    }

    #line 49 "src/service_libraries/pus_services/pus_service3.fin"
    return index_found;

}

__status_int32_t PUSService3__exec3_31TC(const __termina_event_t * const __ev, PUSService3 * const self) {
    
    #line 160 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status;
    #line 160 "src/service_libraries/pus_services/pus_service3.fin"
    status.__variant = Success;

    #line 162 "src/service_libraries/pus_services/pus_service3.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 164 "src/service_libraries/pus_services/pus_service3.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    {
        
        #line 172 "src/service_libraries/pus_services/pus_service3.fin"
        self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev, self);

        #line 174 "src/service_libraries/pus_services/pus_service3.fin"
        if (self->exec_tc_req_status_update.index.found) {
            
            #line 176 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 182 "src/service_libraries/pus_services/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 184 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, self->exec_tc_req_status_update.index.index)].interval = self->exec_tc_req_status_update.tc_data.collection_interval;

                #line 185 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 187 "src/service_libraries/pus_services/pus_service3.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 196 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_SID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.SID, &status);

        }

    }

    #line 206 "src/service_libraries/pus_services/pus_service3.fin"
    return status;

}

__status_int32_t PUSService3__exec3_5TC(const __termina_event_t * const __ev, PUSService3 * const self) {
    
    #line 54 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status;
    #line 54 "src/service_libraries/pus_services/pus_service3.fin"
    status.__variant = Success;

    #line 56 "src/service_libraries/pus_services/pus_service3.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 58 "src/service_libraries/pus_services/pus_service3.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    {
        
        #line 66 "src/service_libraries/pus_services/pus_service3.fin"
        self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev, self);

        #line 68 "src/service_libraries/pus_services/pus_service3.fin"
        if (self->exec_tc_req_status_update.index.found) {
            
            #line 70 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 76 "src/service_libraries/pus_services/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 78 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, self->exec_tc_req_status_update.index.index)].enabled = 1;

                #line 79 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 81 "src/service_libraries/pus_services/pus_service3.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 91 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_SID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.SID, &status);

        }

    }

    #line 101 "src/service_libraries/pus_services/pus_service3.fin"
    return status;

}

__status_int32_t PUSService3__exec3_6TC(const __termina_event_t * const __ev, PUSService3 * const self) {
    
    #line 106 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status;
    #line 106 "src/service_libraries/pus_services/pus_service3.fin"
    status.__variant = Success;

    #line 108 "src/service_libraries/pus_services/pus_service3.fin"
    if (self->exec_tc_req_status_update.tc_data.N != 1U) {
        
        #line 110 "src/service_libraries/pus_services/pus_service3.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.N, &status);

    } else
    {
        
        #line 118 "src/service_libraries/pus_services/pus_service3.fin"
        self->exec_tc_req_status_update.index = PUSService3__get_SIDindex(__ev, self);

        #line 120 "src/service_libraries/pus_services/pus_service3.fin"
        if (self->exec_tc_req_status_update.index.found) {
            
            #line 122 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            #line 128 "src/service_libraries/pus_services/pus_service3.fin"
            if (status.__variant == Success) {
                
                #line 130 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, self->exec_tc_req_status_update.index.index)].enabled = 0;

                #line 131 "src/service_libraries/pus_services/pus_service3.fin"
                self->hk_config_table[__termina_array__index(8U, self->exec_tc_req_status_update.index.index)].interval_control = 0U;

                #line 133 "src/service_libraries/pus_services/pus_service3.fin"
                self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.flags_ack, &status);

            }

        } else
        {
            
            #line 143 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_SID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.SID, &status);

        }

    }

    #line 154 "src/service_libraries/pus_services/pus_service3.fin"
    return status;

}

void PUSService3__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 211 "src/service_libraries/pus_services/pus_service3.fin"
    PUSService3 * self = (PUSService3 *)__this;

    #line 211 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 213 "src/service_libraries/pus_services/pus_service3.fin"
    __status_int32_t status;
    #line 213 "src/service_libraries/pus_services/pus_service3.fin"
    status.__variant = Success;

    #line 214 "src/service_libraries/pus_services/pus_service3.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 216 "src/service_libraries/pus_services/pus_service3.fin"
    self->exec_tc_req_status_update.tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 217 "src/service_libraries/pus_services/pus_service3.fin"
    self->exec_tc_req_status_update.tc_data.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 218 "src/service_libraries/pus_services/pus_service3.fin"
    self->exec_tc_req_status_update.tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 219 "src/service_libraries/pus_services/pus_service3.fin"
    self->exec_tc_req_status_update.tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 221 "src/service_libraries/pus_services/pus_service3.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.N);

    #line 223 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 224 "src/service_libraries/pus_services/pus_service3.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.SID);

    }

    #line 227 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success && subtype == 31U) {
        
        #line 228 "src/service_libraries/pus_services/pus_service3.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.tc_data.collection_interval);

    }

    #line 231 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 233 "src/service_libraries/pus_services/pus_service3.fin"
        if (subtype == 5U) {
            
            #line 235 "src/service_libraries/pus_services/pus_service3.fin"
            status = PUSService3__exec3_5TC(__ev, self);

        } else
        #line 237 "src/service_libraries/pus_services/pus_service3.fin"
        if (subtype == 6U) {
            
            #line 239 "src/service_libraries/pus_services/pus_service3.fin"
            status = PUSService3__exec3_6TC(__ev, self);

        } else
        #line 241 "src/service_libraries/pus_services/pus_service3.fin"
        if (subtype == 31U) {
            
            #line 243 "src/service_libraries/pus_services/pus_service3.fin"
            status = PUSService3__exec3_31TC(__ev, self);

        } else
        {
            
            #line 247 "src/service_libraries/pus_services/pus_service3.fin"
            status.__variant = Failure;
            #line 247 "src/service_libraries/pus_services/pus_service3.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 255 "src/service_libraries/pus_services/pus_service3.fin"
    if (status.__variant == Success) {
        
        #line 257 "src/service_libraries/pus_services/pus_service3.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 260 "src/service_libraries/pus_services/pus_service3.fin"
        int32_t error_code = status.Failure.__0;

        #line 263 "src/service_libraries/pus_services/pus_service3.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 265 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 270 "src/service_libraries/pus_services/pus_service3.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 272 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, action_status);

        } else
        #line 277 "src/service_libraries/pus_services/pus_service3.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 279 "src/service_libraries/pus_services/pus_service3.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.tc_data.packet_id, self->exec_tc_req_status_update.tc_data.packet_seq_ctrl, self->exec_tc_req_status_update.tc_data.tc_num_bytes, action_status);

        } else
        {
            
            #line 287 "src/service_libraries/pus_services/pus_service3.fin"
            (*action_status).__variant = Failure;
            #line 287 "src/service_libraries/pus_services/pus_service3.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 294 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 294 "src/service_libraries/pus_services/pus_service3.fin"
    return;

}

void PUSService3__update_params(const __termina_event_t * const __ev, void * const __this) {
    
    #line 377 "src/service_libraries/pus_services/pus_service3.fin"
    PUSService3 * self = (PUSService3 *)__this;

    #line 377 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 379 "src/service_libraries/pus_services/pus_service3.fin"
    for (size_t i = 0U; i < 5U; i = i + 1U) {
        
        #line 381 "src/service_libraries/pus_services/pus_service3.fin"
        uint32_t random_noise = (uint32_t)(rand_r(&self->random_seed) % 11U) - 5U;

        #line 382 "src/service_libraries/pus_services/pus_service3.fin"
        uint32_t data = 0U;

        #line 384 "src/service_libraries/pus_services/pus_service3.fin"
        data = atomic_load(&self->system_data_pool_u32[i]);

        #line 385 "src/service_libraries/pus_services/pus_service3.fin"
        data = data + random_noise;

        #line 387 "src/service_libraries/pus_services/pus_service3.fin"
        atomic_store(&self->system_data_pool_u32[i], data);

    }

    #line 390 "src/service_libraries/pus_services/pus_service3.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 390 "src/service_libraries/pus_services/pus_service3.fin"
    return;

}
