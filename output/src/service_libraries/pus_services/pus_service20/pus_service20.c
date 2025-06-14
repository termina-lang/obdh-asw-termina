
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
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &status);

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
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &status, &ack_enabled);

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
                    append_u8_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                            1U, &status);

                    #line 98 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 99 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        append_u16_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                 (uint16_t)self->exec_tc_req_status_update.PID,
                                                 &status);

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
                            append_u8_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                    u8_SDP_value, &status);

                        } else
                        #line 111 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (item_type.__variant == DataPoolItemType__u32_t) {
                            
                            #line 112 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint32_t u32_SDP_value = 0U;

                            #line 113 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

                            #line 114 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            append_u32_appdata_field((TMHandlerT *)b_tm_handler2.data,
                                                     u32_SDP_value, &status);

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
                    close_tm((TMHandlerT *)b_tm_handler.data, 20U, 2U, tm_count,
                             current_obt);

                    #line 126 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 128 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2, &status);

                    } else
                    {
                        
                        #line 132 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 139 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.__variant = Failure;
                    #line 139 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

                #line 144 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler3;
                #line 144 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler3.__variant = None;

                #line 145 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler3);

                #line 149 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler3.__variant == Some) {
                    
                    #line 147 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    #line 151 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count3 = 0U;

                    #line 152 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count3);

                    #line 153 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 154 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &status, &ack_enabled);

                    #line 156 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 158 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (status.__variant == Success) {
                            
                            #line 160 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler3, &status);

                        } else
                        {
                            
                            #line 164 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler3);

                        }

                    } else
                    {
                        
                        #line 169 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler3);

                    }

                } else
                {
                    
                    #line 174 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.__variant = Failure;
                    #line 174 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 181 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 182 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &status);

                #line 185 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (status.__variant == Success) {
                    
                    #line 187 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 200 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.__variant = Failure;
        #line 200 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 205 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return status;

}

__status_int32_t PUSService20__exec20_3TC(const __termina_event_t * const __ev,
                                          PUSService20 * const self) {
    
    #line 212 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __status_int32_t status;
    #line 212 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    status.__variant = Success;

    #line 213 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    _Bool ack_enabled = 0;

    #line 215 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 215 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 215 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 217 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 217 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 218 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 222 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 220 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 224 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 225 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 227 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 229 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 230 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &status);

            #line 233 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 235 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 239 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 246 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 248 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
                    #line 250 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 251 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &status, &ack_enabled);

                    #line 253 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 255 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (status.__variant == Success) {
                            
                            #line 257 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler, &status);

                        } else
                        {
                            
                            #line 261 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 266 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 270 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                    #line 272 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    _Bool succesful_execution = 0;

                    #line 275 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u8_t) {
                        
                        #line 277 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                        #line 278 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    #line 280 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u32_t) {
                        
                        #line 282 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                        #line 283 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    {
                        
                        #line 286 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        status.__variant = Failure;
                        #line 286 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        status.Failure.__0 = INVALID_PID_ERROR;

                    }

                    #line 290 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (succesful_execution) {
                        
                        #line 292 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        __option_box_t tm_handler2;
                        #line 292 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        tm_handler2.__variant = None;

                        #line 293 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 297 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 295 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 299 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint16_t tm_count2 = 0U;

                            #line 300 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 301 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 302 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.flags_ack,
                                         current_obt, &status, &ack_enabled);

                            #line 304 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (ack_enabled) {
                                
                                #line 306 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 308 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &status);

                                } else
                                {
                                    
                                    #line 312 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                }

                            } else
                            {
                                
                                #line 317 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 322 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status.__variant = Failure;
                            #line 322 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 331 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 332 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      current_obt, &status);

                    #line 335 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (status.__variant == Success) {
                        
                        #line 337 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 341 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 349 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 350 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &status);

                #line 353 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (status.__variant == Success) {
                    
                    #line 355 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 359 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 368 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.__variant = Failure;
        #line 368 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 372 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return status;

}

void PUSService20__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 378 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PUSService20 * self = (PUSService20 *)__this;

    #line 378 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 380 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __status_int32_t status;
    #line 380 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    status.__variant = Success;

    #line 381 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 383 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 387 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 389 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 391 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 392 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 393 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            #line 394 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 395 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.PID);

            }

            #line 398 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U && status.__variant == Success) {
                
                #line 400 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                #line 403 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 404 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                } else
                #line 406 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 407 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status = tc_handler_get_u32_appdata_field(tc_handler,
                                                              &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                } else
                {
                    
                    #line 410 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.__variant = Failure;
                    #line 410 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    status.Failure.__0 = INVALID_PID_ERROR;

                }

            }

            #line 415 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (status.__variant == Success) {
                
                #line 417 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 421 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 425 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 427 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 429 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 1U) {
                
                #line 431 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = PUSService20__exec20_1TC(__ev, self);

            } else
            #line 433 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U) {
                
                #line 435 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status = PUSService20__exec20_3TC(__ev, self);

            } else
            {
                
                #line 439 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.__variant = Failure;
                #line 439 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 451 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (status.__variant == Success) {
        
        #line 453 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 449 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        int32_t error_code = status.Failure.__0;

        #line 458 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR || error_code == INVALID_PID_ERROR) {
            
            #line 460 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Success;

            #line 462 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            __option_box_t tm_handler;
            #line 462 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            tm_handler.__variant = None;

            #line 463 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 467 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (tm_handler.__variant == Some) {
                
                #line 465 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 469 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                uint16_t tm_count = 0U;

                #line 470 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                MissionObt current_obt;
                #line 470 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                current_obt.finetime = 0U;
                #line 470 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                current_obt.seconds = 0U;

                #line 472 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 473 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 475 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 477 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     current_obt, &status);

                } else
                #line 480 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 482 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                                         current_obt, &status);

                } else
                #line 485 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 487 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.packet_id,
                                                   self->exec_tc_req_status_update.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_num_bytes,
                                                   current_obt, &status);

                } else
                #line 490 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (error_code == INVALID_PID_ERROR) {
                    
                    #line 491 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                               tm_count,
                                               self->exec_tc_req_status_update.packet_id,
                                               self->exec_tc_req_status_update.packet_error_ctrl,
                                               self->exec_tc_req_status_update.PID,
                                               current_obt, &status);

                } else
                {
                    

                }

                #line 501 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (status.__variant == Success) {
                    
                    #line 503 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 507 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 513 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.__variant = Failure;
                #line 513 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 520 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Failure;
            #line 520 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 526 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 528 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 528 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return;

}
