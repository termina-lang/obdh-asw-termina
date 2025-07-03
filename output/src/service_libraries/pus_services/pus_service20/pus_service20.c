
#include "service_libraries/pus_services/pus_service20/pus_service20.h"

__status_int32_t PUSService20__exec20_1TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    #line 29 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __status_int32_t status;
    #line 29 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    status.__variant = Success;

    #line 30 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    _Bool ack_enabled = 0;

    #line 32 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 32 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 32 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 34 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 34 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 35 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 39 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 37 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 41 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 42 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 44 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 46 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 47 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 50 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 52 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 56 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 63 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 65 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 66 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 68 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (ack_enabled) {
                    
                    #line 70 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 72 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 76 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 81 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 84 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler2;
                #line 84 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler2.__variant = None;

                #line 85 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 89 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 87 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 91 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count2 = 0U;

                    #line 92 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 94 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    startup_tm((TMHandlerT *)b_tm_handler2.data);

                    #line 96 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = append_u8_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                     1U);

                    #line 98 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 99 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        status = append_u16_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                          (uint16_t)self->exec_tc_req_status_update.PID);

                    }

                    #line 102 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 103 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                        #line 106 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (item_type.__variant == DataPoolItemType__u8_t) {
                            
                            #line 107 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint8_t u8_SDP_value = 0U;

                            #line 108 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID]);

                            #line 109 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status = append_u8_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                             u8_SDP_value);

                        } else
                        #line 111 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 112 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint32_t u32_SDP_value = 0U;

                            #line 113 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

                            #line 114 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status = append_u32_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                              u32_SDP_value);

                        } else
                        {
                            
                            #line 117 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status.__variant = Failure;
                            #line 117 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status.Failure.__0 = INVALID_PID_ERROR;

                        }

                    }

                    #line 122 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 124 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 126 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        close_tm((TMHandlerT *)b_tm_handler.data, 20U, 2U,
                                 tm_count, current_obt);

                        #line 127 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2, &status);

                    } else
                    {
                        
                        #line 131 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 138 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.__variant = Failure;
                    #line 138 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

                #line 143 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler3;
                #line 143 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler3.__variant = None;

                #line 144 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler3);

                #line 148 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler3.__variant == Some) {
                    
                    #line 146 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    #line 150 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count3 = 0U;

                    #line 151 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count3);

                    #line 152 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 153 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler3.data,
                                          tm_count3,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 155 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 157 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (status.__variant == Success) {
                            
                            #line 159 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler3, &status);

                        } else
                        {
                            
                            #line 163 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler3);

                        }

                    } else
                    {
                        
                        #line 168 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler3);

                    }

                } else
                {
                    
                    #line 173 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.__variant = Failure;
                    #line 173 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 180 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 181 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.packet_id,
                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.PID,
                                                    current_obt);

                #line 184 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (status.__variant == Success) {
                    
                    #line 186 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 190 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 199 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.__variant = Failure;
        #line 199 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 204 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return status;

}

__status_int32_t PUSService20__exec20_3TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    #line 211 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __status_int32_t status;
    #line 211 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    status.__variant = Success;

    #line 212 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    _Bool ack_enabled = 0;

    #line 214 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 214 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 214 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 216 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 216 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 217 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 221 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 219 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 223 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 224 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 226 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 228 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 229 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 232 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 234 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 238 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 245 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 247 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
                    #line 249 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 250 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_3((TMHandlerT *)b_tm_handler.data,
                                          tm_count,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 252 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 254 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (status.__variant == Success) {
                            
                            #line 256 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 260 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 265 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 269 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                    #line 271 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    _Bool succesful_execution = 0;

                    #line 274 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u8_t) {
                        
                        #line 276 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                        #line 277 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    #line 279 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u32_t) {
                        
                        #line 281 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                        #line 282 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    {
                        
                        #line 285 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        status.__variant = Failure;
                        #line 285 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        status.Failure.__0 = INVALID_PID_ERROR;

                    }

                    #line 289 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (succesful_execution) {
                        
                        #line 291 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        __option_box_t tm_handler2;
                        #line 291 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        tm_handler2.__variant = None;

                        #line 292 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 296 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 294 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 298 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint16_t tm_count2 = 0U;

                            #line 299 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 300 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 301 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                                  tm_count2,
                                                  self->exec_tc_req_status_update.packet_id,
                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 303 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (ack_enabled) {
                                
                                #line 305 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 307 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 311 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 316 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 321 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status.__variant = Failure;
                            #line 321 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 330 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 331 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
                                                               tm_count,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.PID,
                                                               current_obt);

                    #line 334 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 336 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 340 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 348 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 349 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                    tm_count,
                                                    self->exec_tc_req_status_update.packet_id,
                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                    self->exec_tc_req_status_update.PID,
                                                    current_obt);

                #line 352 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (status.__variant == Success) {
                    
                    #line 354 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 358 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 367 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.__variant = Failure;
        #line 367 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 371 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return status;

}

void PUSService20__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 377 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PUSService20 * self = (PUSService20 *)__this;

    #line 377 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 379 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __status_int32_t status;
    #line 379 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    status.__variant = Success;

    #line 380 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 382 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 386 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 388 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 389 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 391 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 392 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            #line 393 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 394 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.PID);

            }

            #line 397 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U && status.__variant == Success) {
                
                #line 399 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                #line 402 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 403 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                } else
                #line 405 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 406 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                } else
                {
                    
                    #line 409 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.__variant = Failure;
                    #line 409 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            }

            #line 414 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 420 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 424 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 426 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 428 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 1U) {
                
                #line 430 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = PUSService20__exec20_1TC(__ev, self);

            } else
            #line 432 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U) {
                
                #line 434 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = PUSService20__exec20_3TC(__ev, self);

            } else
            {
                
                #line 438 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.__variant = Failure;
                #line 438 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 450 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (status.__variant == Success) {
        
        #line 452 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 448 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        int32_t error_code = status.Failure.__0;

        #line 457 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR
            || error_code == INVALID_PID_ERROR) {
            
            #line 459 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Success;

            #line 461 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            __option_box_t tm_handler;
            #line 461 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            tm_handler.__variant = None;

            #line 462 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 466 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (tm_handler.__variant == Some) {
                
                #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 468 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                uint16_t tm_count = 0U;

                #line 469 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                MissionObt current_obt;
                #line 469 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                current_obt.finetime = 0U;
                #line 469 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                current_obt.seconds = 0U;

                #line 471 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 472 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 474 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 476 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 479 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 481 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 484 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 486 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                #line 489 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == INVALID_PID_ERROR) {
                    
                    #line 490 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                        tm_count,
                                                        self->exec_tc_req_status_update.packet_id,
                                                        self->exec_tc_req_status_update.packet_seq_ctrl,
                                                        self->exec_tc_req_status_update.PID,
                                                        current_obt);

                } else
                {
                    

                }

                #line 500 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (status.__variant == Success) {
                    
                    #line 502 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 506 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 512 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.__variant = Failure;
                #line 512 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 519 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Failure;
            #line 519 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 525 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 527 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 527 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return;

}
