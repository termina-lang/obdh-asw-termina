
#include "service_libraries/pus_services/pus_service20/pus_service20.h"

void PUSService20__build_tm_20_2(const PUSService20 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter,
                                 MyResult * const result) {
    
    #line 28 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    startup_tm(p_tm_handler);

    #line 30 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    append_u8_appdata_field(p_tm_handler, 1U, result);

    #line 31 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    append_u16_appdata_field(p_tm_handler,
                             (uint16_t)self->exec_tc_req_status_update.PID,
                             result);

    #line 33 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

    #line 36 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (item_type.__variant == DataPoolItemType__u8_t) {
        
        #line 37 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint8_t u8_SDP_value = 0U;

        #line 38 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        u8_SDP_value = atomic_load(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID]);

        #line 39 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        append_u8_appdata_field(p_tm_handler, u8_SDP_value, result);

    } else
    #line 41 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (item_type.__variant == DataPoolItemType__u32_t) {
        
        #line 42 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint32_t u32_SDP_value = 0U;

        #line 43 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        u32_SDP_value = atomic_load(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID]);

        #line 44 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        append_u32_appdata_field(p_tm_handler, u32_SDP_value, result);

    } else
    {
        
        #line 47 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        (*result).__variant = MyResult__Error;

    }

    #line 51 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 51 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 51 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 52 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 54 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    close_tm(p_tm_handler, 20U, 2U, tm_seq_counter, current_obt);

    #line 56 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return;

}

PSExecTCReqStatus PUSService20__exec20_1TC(PUSService20 * const self) {
    
    #line 63 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 63 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 64 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 64 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

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
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 74 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 72 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 76 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 77 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 79 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 81 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 82 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 85 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 87 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 89 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 90 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 90 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 94 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 95 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 95 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 101 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 103 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 104 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &result, &ack_enabled);

                #line 106 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (ack_enabled) {
                    
                    #line 108 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 110 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 112 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 113 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 113 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 117 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 118 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 118 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 122 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 125 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler2;
                #line 125 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler2.__variant = None;

                #line 126 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 130 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 128 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 132 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count2 = 0U;

                    #line 133 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 134 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    PUSService20__build_tm_20_2(self,
                                                (TMHandlerT *)b_tm_handler2.data,
                                                tm_count2, &result);

                    #line 136 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 138 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 140 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            

                        }

                    } else
                    {
                        
                        #line 146 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 147 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 147 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 153 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 153 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

                #line 158 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler3;
                #line 158 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler3.__variant = None;

                #line 159 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler3);

                #line 163 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler3.__variant == Some) {
                    
                    #line 161 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    #line 165 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count3 = 0U;

                    #line 166 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count3);

                    #line 167 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 168 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 170 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 172 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 174 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler3, &result);

                            #line 176 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 177 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 177 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 181 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler3);

                            #line 182 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 182 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 186 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler3);

                    }

                } else
                {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 191 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 198 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 199 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 202 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 204 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 206 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 207 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 207 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 211 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 212 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 212 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 220 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 220 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 225 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__exec20_3TC(PUSService20 * const self) {
    
    #line 232 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 232 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 233 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 233 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 234 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    _Bool ack_enabled = 0;

    #line 236 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 236 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 236 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 238 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 238 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 239 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 243 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 241 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 245 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 246 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 248 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 250 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 251 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 254 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 256 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 258 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 259 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 259 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 263 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 264 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 264 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 270 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 272 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
                    #line 274 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 275 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &result, &ack_enabled);

                    #line 277 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (ack_enabled) {
                        
                        #line 279 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Ok) {
                            
                            #line 281 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_channel.send_tm(self->tm_channel.__that,
                                                     b_tm_handler, &result);

                            #line 283 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (result.__variant == MyResult__Error) {
                                
                                #line 284 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                next_status.__variant = PSExecTCReqStatus__Failure;
                                #line 284 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                next_status.Failure.__0 = TM_SEND_FAILURE;

                            }

                        } else
                        {
                            
                            #line 288 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                         b_tm_handler);

                            #line 289 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Error;
                            #line 289 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Error.__0 = BUILD_TM_ERROR;

                        }

                    } else
                    {
                        
                        #line 293 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                    #line 297 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                    #line 299 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    _Bool succesful_execution = 0;

                    #line 302 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u8_t) {
                        
                        #line 304 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                        #line 305 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    #line 307 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u32_t) {
                        
                        #line 309 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                        #line 310 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    {
                        
                        #line 313 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        result.__variant = MyResult__Error;

                    }

                    #line 317 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (succesful_execution) {
                        
                        #line 319 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        __option_box_t tm_handler2;
                        #line 319 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        tm_handler2.__variant = None;

                        #line 320 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 324 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 322 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 326 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint16_t tm_count2 = 0U;

                            #line 327 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 328 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 329 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2,
                                         self->exec_tc_req_status_update.flags_ack,
                                         current_obt, &result, &ack_enabled);

                            #line 331 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (ack_enabled) {
                                
                                #line 333 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                if (result.__variant == MyResult__Ok) {
                                    
                                    #line 335 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->tm_channel.send_tm(self->tm_channel.__that,
                                                             b_tm_handler2,
                                                             &result);

                                    #line 337 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    if (result.__variant == MyResult__Error) {
                                        
                                        #line 338 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                        next_status.__variant = PSExecTCReqStatus__Failure;
                                        #line 338 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                        next_status.Failure.__0 = TM_SEND_FAILURE;

                                    }

                                } else
                                {
                                    
                                    #line 342 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                                 b_tm_handler2);

                                    #line 343 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    next_status.__variant = PSExecTCReqStatus__Error;
                                    #line 343 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    next_status.Error.__0 = BUILD_TM_ERROR;

                                }

                            } else
                            {
                                
                                #line 347 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 352 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 352 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 361 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 362 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      current_obt, &result);

                    #line 365 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 367 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 369 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 370 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 370 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 374 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 375 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 375 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 382 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 383 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 386 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 388 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 391 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 391 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 395 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 396 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 396 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 404 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 404 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 408 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PS20ExecTCReqStatusUpdate PUSService20__get_TC_params(const PUSService20 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    #line 414 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PS20ExecTCReqStatusUpdate tc_data;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.N = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.PID = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.flags_ack = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_id = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_20_3_data.PID_value_u32 = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_20_3_data.PID_value_u8 = 0U;
    #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_num_bytes = 0U;

    #line 428 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 429 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 430 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 431 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 432 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 433 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    #line 435 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (*subtype == 3U) {
        
        #line 437 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        DataPoolItemType item_type = sys_data_pool_get_item_type(tc_data.PID);

        #line 440 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            #line 441 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                      &tc_data.tc_20_3_data.PID_value_u8);

        } else
        #line 443 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (item_type.__variant == DataPoolItemType__u32_t) {
            
            #line 444 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                       &tc_data.tc_20_3_data.PID_value_u32);

        } else
        {
            
            #line 447 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*result).__variant = MyResult__Error;

        }

    }

    #line 452 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService20__manage_error_in_acceptance(const PUSService20 * const self) {
    
    #line 501 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 501 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 502 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 502 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 504 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 504 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 504 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 506 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 506 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 507 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 511 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 509 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 513 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 514 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 516 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 517 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 520 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 522 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 524 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 525 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 525 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 529 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 530 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 530 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 535 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 535 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 539 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const PUSService20 * const self) {
    
    #line 458 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 458 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 459 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 459 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 461 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 461 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 461 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 463 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 463 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 468 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 466 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 470 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 471 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 473 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 474 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 477 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 479 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 481 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 482 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 482 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 486 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 487 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 487 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 492 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 492 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 496 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_tm_limit_app_data_reached(const PUSService20 * const self) {
    
    #line 544 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 544 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 545 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 545 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 547 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 547 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 547 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 549 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 549 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 550 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 554 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 552 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 556 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 557 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 559 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 560 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 563 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 565 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 567 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 568 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 568 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 572 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 573 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 573 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 578 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 578 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 582 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

void PUSService20__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService20 * self = (PUSService20 *)__this;

    #line 588 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    uint8_t subtype = 0U;

    #line 590 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 594 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 596 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            MyResult result;
            #line 596 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            result.__variant = MyResult__Ok;

            #line 598 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update = PUSService20__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          &result);

            #line 600 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 601 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 601 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 603 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 607 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 609 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 1U) {
                
                #line 611 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__exec20_1TC(self);

            } else
            #line 613 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U) {
                
                #line 615 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__exec20_3TC(self);

            } else
            {
                
                #line 619 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 619 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 623 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 592 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 625 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 627 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 630 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__manage_error_in_acceptance(self);

            } else
            #line 632 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 635 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__manage_tm_limit_app_data_reached(self);

            } else
            #line 637 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 639 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 647 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 592 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 649 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Failure;
            #line 649 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 650 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 659 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 661 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 664 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return;

}

void PUSService20__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService20 * self = (PUSService20 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService20__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService20__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService20__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService20__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService20__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}
