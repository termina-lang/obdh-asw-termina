
#include "service_libraries/pus_services/pus_service20/pus_service20.h"

void PUSService20__build_tm_20_2(const __termina_event_t * const __ev,
                                 const PUSService20 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter,
                                 __status_int32_t * const status) {
    
    #line 28 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    startup_tm(p_tm_handler);

    #line 30 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    append_u8_appdata_field(p_tm_handler, 1U, status);

    #line 31 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    append_u16_appdata_field(p_tm_handler,
                             (uint16_t)self->exec_tc_req_status_update.PID,
                             status);

    #line 33 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

    #line 36 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 37 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint8_t u8_SDP_value = 0U;

        #line 38 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID]);

        #line 39 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        append_u8_appdata_field(p_tm_handler, u8_SDP_value, status);

    } else
    #line 41 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 42 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint32_t u32_SDP_value = 0U;

        #line 43 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

        #line 44 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        append_u32_appdata_field(p_tm_handler, u32_SDP_value, status);

    } else
    {
        
        #line 47 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        (*status).__variant = Failure;
        #line 47 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        (*status).Failure.__0 = INVALID_PID_ERROR;

    }

    #line 51 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 51 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 51 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 52 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                        &current_obt);

    #line 54 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    close_tm(p_tm_handler, 20U, 2U, tm_seq_counter, current_obt);

    #line 56 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return;

}

PSExecTCReqStatus PUSService20__exec20_1TC(const __termina_event_t * const __ev,
                                           PUSService20 * const self) {
    
    #line 63 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 63 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 63 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.status.__variant = Success;

    #line 65 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    _Bool ack_enabled = 0;

    #line 67 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 67 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 67 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 69 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 69 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 70 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 74 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 72 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 76 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 77 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 79 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 81 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 82 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt,
                                                &next_status.status);

            #line 85 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (next_status.status.__variant == Success) {
                
                #line 87 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 91 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 98 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 100 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 101 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &next_status.status, &ack_enabled);

                #line 103 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (ack_enabled) {
                    
                    #line 105 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 107 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 111 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 116 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 119 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler2;
                #line 119 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler2.__variant = None;

                #line 120 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 124 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 122 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 126 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count2 = 0U;

                    #line 127 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 128 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    PUSService20__build_tm_20_2(__ev, self,
                                                (TMHandlerT *)b_tm_handler2.data,
                                                tm_count2, &next_status.status);

                    #line 130 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 132 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler2,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 136 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 143 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.status.__variant = Failure;
                    #line 143 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

                #line 148 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler3;
                #line 148 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler3.__variant = None;

                #line 149 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler3);

                #line 153 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler3.__variant == Some) {
                    
                    #line 151 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    #line 155 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count3 = 0U;

                    #line 156 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count3);

                    #line 157 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 158 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 160 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 162 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 164 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler3,
                                                     &next_status.status);

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
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler3);

                    }

                } else
                {
                    
                    #line 178 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.status.__variant = Failure;
                    #line 178 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 185 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 186 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &next_status.status);

                #line 189 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 195 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 204 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.__variant = Failure;
        #line 204 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 209 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__exec20_3TC(const __termina_event_t * const __ev,
                                           PUSService20 * const self) {
    
    #line 216 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 216 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 216 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.status.__variant = Success;

    #line 217 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    _Bool ack_enabled = 0;

    #line 219 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 219 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 219 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 221 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 221 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 222 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 226 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 224 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 228 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 229 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 231 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 233 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 234 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt,
                                                &next_status.status);

            #line 237 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (next_status.status.__variant == Success) {
                
                #line 239 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 243 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 250 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 252 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
                    #line 254 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 255 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &next_status.status,
                                 &ack_enabled);

                    #line 257 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 259 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (next_status.status.__variant == Success) {
                            
                            #line 261 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler,
                                                     &next_status.status);

                        } else
                        {
                            
                            #line 265 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                        }

                    } else
                    {
                        
                        #line 270 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 274 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                    #line 276 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    _Bool succesful_execution = 0;

                    #line 279 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u8_t) {
                        
                        #line 281 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                        #line 282 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    #line 284 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u32_t) {
                        
                        #line 286 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                        #line 287 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    {
                        
                        #line 290 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.status.__variant = Failure;
                        #line 290 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.status.Failure.__0 = INVALID_PID_ERROR;

                    }

                    #line 294 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (succesful_execution) {
                        
                        #line 296 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        __option_box_t tm_handler2;
                        #line 296 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        tm_handler2.__variant = None;

                        #line 297 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 301 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 299 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 303 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint16_t tm_count2 = 0U;

                            #line 304 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count2);

                            #line 305 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 306 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.flags_ack,
                                         current_obt, &next_status.status,
                                         &ack_enabled);

                            #line 308 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (ack_enabled) {
                                
                                #line 310 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                if (next_status.status.__variant == Success) {
                                    
                                    #line 312 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &next_status.status);

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
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 326 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.status.__variant = Failure;
                            #line 326 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 335 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 336 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      current_obt,
                                                      &next_status.status);

                    #line 339 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (next_status.status.__variant == Success) {
                        
                        #line 341 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler,
                                                 &next_status.status);

                    } else
                    {
                        
                        #line 345 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                }

            } else
            {
                
                #line 353 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 354 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &next_status.status);

                #line 357 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 359 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &next_status.status);

                } else
                {
                    
                    #line 363 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 372 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.__variant = Failure;
        #line 372 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 376 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                           const PUSService20 * const self) {
    
    #line 423 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 423 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 423 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.status.__variant = Success;

    #line 425 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 425 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 425 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 427 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 427 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 428 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 432 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 430 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 434 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 435 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 437 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 438 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 441 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (next_status.status.__variant == Success) {
            
            #line 443 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 447 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 453 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.__variant = Failure;
        #line 453 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 457 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                               const PUSService20 * const self) {
    
    #line 384 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 384 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 384 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.status.__variant = Success;

    #line 386 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 386 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 386 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 388 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 388 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 389 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 393 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 391 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 395 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 396 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 398 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 399 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 402 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (next_status.status.__variant == Success) {
            
            #line 404 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 408 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 414 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.__variant = Failure;
        #line 414 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 418 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                 const PUSService20 * const self) {
    
    #line 462 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 462 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 462 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.status.__variant = Success;

    #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 466 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 466 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 467 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 471 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 469 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 473 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 474 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 476 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 477 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 480 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (next_status.status.__variant == Success) {
            
            #line 482 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 486 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 492 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.__variant = Failure;
        #line 492 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 496 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

void PUSService20__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 500 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PUSService20 * self = (PUSService20 *)__this;

    #line 500 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 502 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 504 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 508 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 510 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 511 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 512 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 513 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 514 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                              &self->exec_tc_req_status_update.N);

            #line 515 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                               &self->exec_tc_req_status_update.PID);

            #line 517 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U) {
                
                #line 519 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                #line 522 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u8_t) {
                    
                    #line 523 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->exec_tc_req_status.status = tc_handler_get_u8_appdata_field(tc_handler,
                                                                                      &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                } else
                #line 525 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (item_type.__variant == DataPoolItemType__u32_t) {
                    
                    #line 526 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->exec_tc_req_status.status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                                       &self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                } else
                {
                    
                    #line 529 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->exec_tc_req_status.status.__variant = Failure;
                    #line 529 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->exec_tc_req_status.status.Failure.__0 = INVALID_PID_ERROR;

                }

            }

            #line 534 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 536 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 540 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 544 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 546 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 1U) {
                
                #line 548 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__exec20_1TC(__ev, self);

            } else
            #line 550 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U) {
                
                #line 552 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__exec20_3TC(__ev, self);

            } else
            {
                
                #line 556 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 556 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 557 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 568 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 570 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 566 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 575 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 577 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status = PUSService20__manage_error_in_acceptance(__ev,
                                                                                self);

        } else
        #line 579 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 581 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status = PUSService20__manage_tm_limit_app_data_reached(__ev,
                                                                                      self);

        } else
        #line 583 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 585 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status = PUSService20__manage_short_pack_length_error(__ev,
                                                                                    self);

        } else
        #line 587 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (error_code == INVALID_PID_ERROR) {
            

        } else
        {
            
            #line 593 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Failure;
            #line 593 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 601 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 602 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 606 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 606 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return;

}
