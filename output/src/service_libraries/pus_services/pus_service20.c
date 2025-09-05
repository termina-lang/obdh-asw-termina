
#include "service_libraries/pus_services/pus_service20.h"

__status_int32_t PUSService20__exec20_1TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    #line 28 "src/service_libraries/pus_services/pus_service20.fin"
    __status_int32_t status;
    #line 28 "src/service_libraries/pus_services/pus_service20.fin"
    status.__variant = Success;

    #line 30 "src/service_libraries/pus_services/pus_service20.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 32 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 38 "src/service_libraries/pus_services/pus_service20.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID) == 0) {
        
        #line 40 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(__ev,
                                                      self->pus_service_1.__that,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      &status);

    } else
    {
        
        #line 48 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 54 "src/service_libraries/pus_services/pus_service20.fin"
        __option_box_t tm_handler;
        #line 54 "src/service_libraries/pus_services/pus_service20.fin"
        tm_handler.__variant = None;

        #line 55 "src/service_libraries/pus_services/pus_service20.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        #line 59 "src/service_libraries/pus_services/pus_service20.fin"
        if (tm_handler.__variant == Some) {
            
            #line 57 "src/service_libraries/pus_services/pus_service20.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 61 "src/service_libraries/pus_services/pus_service20.fin"
            MissionOBT current_obt;
            #line 61 "src/service_libraries/pus_services/pus_service20.fin"
            current_obt.finetime = 0U;
            #line 61 "src/service_libraries/pus_services/pus_service20.fin"
            current_obt.seconds = 0U;

            #line 62 "src/service_libraries/pus_services/pus_service20.fin"
            uint16_t tm_count = 0U;

            #line 64 "src/service_libraries/pus_services/pus_service20.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 66 "src/service_libraries/pus_services/pus_service20.fin"
            startup_tm((TMHandler *)b_tm_handler.data);

            #line 68 "src/service_libraries/pus_services/pus_service20.fin"
            status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                             1U);

            #line 70 "src/service_libraries/pus_services/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 71 "src/service_libraries/pus_services/pus_service20.fin"
                status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                  (uint16_t)self->exec_tc_req_status_update.PID);

            }

            #line 74 "src/service_libraries/pus_services/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 75 "src/service_libraries/pus_services/pus_service20.fin"
                DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                #line 78 "src/service_libraries/pus_services/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 79 "src/service_libraries/pus_services/pus_service20.fin"
                    uint8_t u8_SDP_value = 0U;

                    #line 80 "src/service_libraries/pus_services/pus_service20.fin"
                    u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID]);

                    #line 81 "src/service_libraries/pus_services/pus_service20.fin"
                    status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                     u8_SDP_value);

                } else
                #line 83 "src/service_libraries/pus_services/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 84 "src/service_libraries/pus_services/pus_service20.fin"
                    uint32_t u32_SDP_value = 0U;

                    #line 85 "src/service_libraries/pus_services/pus_service20.fin"
                    u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

                    #line 86 "src/service_libraries/pus_services/pus_service20.fin"
                    status = append_u32_appdata_field((TMHandler *)b_tm_handler.data,
                                                      u32_SDP_value);

                } else
                {
                    
                    #line 89 "src/service_libraries/pus_services/pus_service20.fin"
                    status.__variant = Failure;
                    #line 89 "src/service_libraries/pus_services/pus_service20.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            }

            #line 94 "src/service_libraries/pus_services/pus_service20.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                              &current_obt);

            #line 96 "src/service_libraries/pus_services/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 97 "src/service_libraries/pus_services/pus_service20.fin"
                close_tm((TMHandler *)b_tm_handler.data, 20U, 2U, tm_count,
                         current_obt);

                #line 98 "src/service_libraries/pus_services/pus_service20.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 100 "src/service_libraries/pus_services/pus_service20.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 106 "src/service_libraries/pus_services/pus_service20.fin"
            status.__variant = Failure;
            #line 106 "src/service_libraries/pus_services/pus_service20.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

        #line 111 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

    }

    #line 119 "src/service_libraries/pus_services/pus_service20.fin"
    return status;

}

__status_int32_t PUSService20__exec20_3TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    #line 126 "src/service_libraries/pus_services/pus_service20.fin"
    __status_int32_t status;
    #line 126 "src/service_libraries/pus_services/pus_service20.fin"
    status.__variant = Success;

    #line 128 "src/service_libraries/pus_services/pus_service20.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 130 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 136 "src/service_libraries/pus_services/pus_service20.fin"
    if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID) == 0) {
        
        #line 138 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.send_tm_1_4_PID_not_valid(__ev,
                                                      self->pus_service_1.__that,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      &status);

    } else
    #line 144 "src/service_libraries/pus_services/pus_service20.fin"
    if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID) == 0) {
        
        #line 146 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.send_tm_1_4_PID_read_only_via_TC(__ev,
                                                             self->pus_service_1.__that,
                                                             self->exec_tc_req_status_update.packet_id,
                                                             self->exec_tc_req_status_update.packet_seq_ctrl,
                                                             self->exec_tc_req_status_update.PID,
                                                             &status);

    } else
    {
        
        #line 154 "src/service_libraries/pus_services/pus_service20.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 160 "src/service_libraries/pus_services/pus_service20.fin"
        if (status.__variant == Success) {
            
            #line 162 "src/service_libraries/pus_services/pus_service20.fin"
            DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

            #line 165 "src/service_libraries/pus_services/pus_service20.fin"
            if (item_type.__variant == DataPoolItemType__u8_t) {
                
                #line 166 "src/service_libraries/pus_services/pus_service20.fin"
                atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID - 11U],
                             self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

            } else
            #line 168 "src/service_libraries/pus_services/pus_service20.fin"
            if (item_type.__variant == DataPoolItemType__u32_t) {
                
                #line 169 "src/service_libraries/pus_services/pus_service20.fin"
                atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID - 0U],
                             self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

            } else
            {
                
                #line 172 "src/service_libraries/pus_services/pus_service20.fin"
                status.__variant = Failure;
                #line 172 "src/service_libraries/pus_services/pus_service20.fin"
                status.Failure.__0 = INVALID_PID_ERROR;

            }

        }

        #line 178 "src/service_libraries/pus_services/pus_service20.fin"
        if (status.__variant == Success) {
            
            #line 180 "src/service_libraries/pus_services/pus_service20.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              &status);

        }

    }

    #line 190 "src/service_libraries/pus_services/pus_service20.fin"
    return status;

}

void PUSService20__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandler * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 194 "src/service_libraries/pus_services/pus_service20.fin"
    PUSService20 * self = (PUSService20 *)__this;

    #line 194 "src/service_libraries/pus_services/pus_service20.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 196 "src/service_libraries/pus_services/pus_service20.fin"
    __status_int32_t status;
    #line 196 "src/service_libraries/pus_services/pus_service20.fin"
    status.__variant = Success;

    #line 197 "src/service_libraries/pus_services/pus_service20.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 199 "src/service_libraries/pus_services/pus_service20.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 200 "src/service_libraries/pus_services/pus_service20.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 201 "src/service_libraries/pus_services/pus_service20.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 202 "src/service_libraries/pus_services/pus_service20.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 204 "src/service_libraries/pus_services/pus_service20.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler,
                                             &self->exec_tc_req_status_update.N);

    #line 206 "src/service_libraries/pus_services/pus_service20.fin"
    if (status.__variant == Success) {
        
        #line 207 "src/service_libraries/pus_services/pus_service20.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler,
                                                  &self->exec_tc_req_status_update.PID);

    }

    #line 210 "src/service_libraries/pus_services/pus_service20.fin"
    if (status.__variant == Success && subtype == 3U) {
        
        #line 212 "src/service_libraries/pus_services/pus_service20.fin"
        DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

        #line 215 "src/service_libraries/pus_services/pus_service20.fin"
        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            #line 216 "src/service_libraries/pus_services/pus_service20.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

        } else
        #line 218 "src/service_libraries/pus_services/pus_service20.fin"
        if (item_type.__variant == DataPoolItemType__u32_t) {
            
            #line 219 "src/service_libraries/pus_services/pus_service20.fin"
            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                      &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

        } else
        {
            
            #line 222 "src/service_libraries/pus_services/pus_service20.fin"
            status.__variant = Failure;
            #line 222 "src/service_libraries/pus_services/pus_service20.fin"
            status.Failure.__0 = INVALID_PID_ERROR;

        }

    }

    #line 228 "src/service_libraries/pus_services/pus_service20.fin"
    if (status.__variant == Success) {
        
        #line 230 "src/service_libraries/pus_services/pus_service20.fin"
        if (subtype == 1U) {
            
            #line 232 "src/service_libraries/pus_services/pus_service20.fin"
            status = PUSService20__exec20_1TC(__ev, self);

        } else
        #line 234 "src/service_libraries/pus_services/pus_service20.fin"
        if (subtype == 3U) {
            
            #line 236 "src/service_libraries/pus_services/pus_service20.fin"
            status = PUSService20__exec20_3TC(__ev, self);

        } else
        {
            
            #line 240 "src/service_libraries/pus_services/pus_service20.fin"
            status.__variant = Failure;
            #line 240 "src/service_libraries/pus_services/pus_service20.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 248 "src/service_libraries/pus_services/pus_service20.fin"
    if (status.__variant == Success) {
        
        #line 250 "src/service_libraries/pus_services/pus_service20.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 246 "src/service_libraries/pus_services/pus_service20.fin"
        int32_t error_code = status.Failure.__0;

        #line 255 "src/service_libraries/pus_services/pus_service20.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 257 "src/service_libraries/pus_services/pus_service20.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                action_status);

        } else
        #line 262 "src/service_libraries/pus_services/pus_service20.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 264 "src/service_libraries/pus_services/pus_service20.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    action_status);

        } else
        #line 269 "src/service_libraries/pus_services/pus_service20.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 271 "src/service_libraries/pus_services/pus_service20.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_num_bytes,
                                                              action_status);

        } else
        #line 277 "src/service_libraries/pus_services/pus_service20.fin"
        if (error_code == INVALID_PID_ERROR) {
            
            #line 279 "src/service_libraries/pus_services/pus_service20.fin"
            self->pus_service_1.send_tm_1_4_PID_not_valid(__ev,
                                                          self->pus_service_1.__that,
                                                          self->exec_tc_req_status_update.packet_id,
                                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                                          self->exec_tc_req_status_update.PID,
                                                          action_status);

        } else
        {
            
            #line 286 "src/service_libraries/pus_services/pus_service20.fin"
            (*action_status).__variant = Failure;
            #line 286 "src/service_libraries/pus_services/pus_service20.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 292 "src/service_libraries/pus_services/pus_service20.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 292 "src/service_libraries/pus_services/pus_service20.fin"
    return;

}
