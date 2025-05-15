
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

    #line 66 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 66 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 66 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 68 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 68 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 69 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 73 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 71 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 75 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 76 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 78 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 80 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 81 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 84 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 86 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 88 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 89 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 89 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 93 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 94 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 94 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 100 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 102 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 103 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             current_obt, &result);

                #line 105 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 107 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 109 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 110 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 110 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 114 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 115 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 115 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

                #line 118 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler2;
                #line 118 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler2.__variant = None;

                #line 119 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 123 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 121 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 125 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count2 = 0U;

                    #line 126 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count2);

                    #line 127 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    PUSService20__build_tm_20_2(self,
                                                (TMHandlerT *)b_tm_handler2.data,
                                                tm_count2, &result);

                    #line 129 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 131 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler2, &result);

                        #line 133 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            

                        }

                    } else
                    {
                        
                        #line 139 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                        #line 140 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 140 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 146 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 146 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

                #line 151 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                __option_box_t tm_handler3;
                #line 151 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                tm_handler3.__variant = None;

                #line 152 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                              &tm_handler3);

                #line 156 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (tm_handler3.__variant == Some) {
                    
                    #line 154 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                    #line 158 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    uint16_t tm_count3 = 0U;

                    #line 159 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                       &tm_count3);

                    #line 160 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 161 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                                 current_obt, &result);

                    #line 163 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 165 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler3, &result);

                        #line 167 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 168 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 168 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 172 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler3);

                        #line 173 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 173 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                } else
                {
                    
                    #line 178 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 178 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 185 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 186 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 189 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 193 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 194 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 194 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 198 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 199 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 199 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 207 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 207 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 212 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__exec20_3TC(PUSService20 * const self) {
    
    #line 219 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 219 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 220 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 220 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 222 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 222 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 222 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 224 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 224 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 225 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 229 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 227 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 231 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 232 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 234 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 236 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 237 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &result);

            #line 240 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 242 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 244 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 245 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 245 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 249 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 250 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 250 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 256 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (sys_data_pool_is_valid_PID(self->exec_tc_req_status_update.PID)) {
                
                #line 258 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (sys_data_pool_is_PID_update_via_TC_enabled(self->exec_tc_req_status_update.PID)) {
                    
                    #line 260 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 261 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                 current_obt, &result);

                    #line 263 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 265 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 267 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 268 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 268 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 272 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 273 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 273 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                    #line 277 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    DataPoolItemType item_type = sys_data_pool_get_item_type(self->exec_tc_req_status_update.PID);

                    #line 279 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    _Bool succesful_execution = 0;

                    #line 282 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u8_t) {
                        
                        #line 284 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u8[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u8);

                        #line 285 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    #line 287 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (item_type.__variant == DataPoolItemType__u32_t) {
                        
                        #line 289 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        atomic_store(&self->system_data_pool_u32[(size_t)self->exec_tc_req_status_update.PID],
                                     self->exec_tc_req_status_update.tc_20_3_data.PID_value_u32);

                        #line 290 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        succesful_execution = 1;

                    } else
                    {
                        
                        #line 293 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        result.__variant = MyResult__Error;

                    }

                    #line 297 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (succesful_execution) {
                        
                        #line 299 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        __option_box_t tm_handler2;
                        #line 299 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        tm_handler2.__variant = None;

                        #line 300 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                                      &tm_handler2);

                        #line 304 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (tm_handler2.__variant == Some) {
                            
                            #line 302 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                            #line 306 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            uint16_t tm_count2 = 0U;

                            #line 307 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                                               &tm_count2);

                            #line 308 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                                &current_obt);

                            #line 309 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                         tm_count2, current_obt, &result);

                            #line 311 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            if (result.__variant == MyResult__Ok) {
                                
                                #line 313 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                self->tm_channel.send_tm(self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &result);

                                #line 315 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                if (result.__variant == MyResult__Error) {
                                    
                                    #line 316 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    next_status.__variant = PSExecTCReqStatus__Failure;
                                    #line 316 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                    next_status.Failure.__0 = TM_SEND_FAILURE;

                                }

                            } else
                            {
                                
                                #line 320 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                                #line 321 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                next_status.__variant = PSExecTCReqStatus__Error;
                                #line 321 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                                next_status.Error.__0 = BUILD_TM_ERROR;

                            }

                        } else
                        {
                            
                            #line 326 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 326 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    }

                } else
                {
                    
                    #line 335 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                        &current_obt);

                    #line 336 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    build_tm_1_4_PID_read_only_via_TC((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_error_ctrl,
                                                      self->exec_tc_req_status_update.PID,
                                                      current_obt, &result);

                    #line 339 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Ok) {
                        
                        #line 341 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->tm_channel.send_tm(self->tm_channel.__that,
                                                 b_tm_handler, &result);

                        #line 343 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        if (result.__variant == MyResult__Error) {
                            
                            #line 344 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.__variant = PSExecTCReqStatus__Failure;
                            #line 344 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                            next_status.Failure.__0 = TM_SEND_FAILURE;

                        }

                    } else
                    {
                        
                        #line 348 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                        #line 349 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Error;
                        #line 349 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Error.__0 = BUILD_TM_ERROR;

                    }

                }

            } else
            {
                
                #line 356 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                    &current_obt);

                #line 357 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                build_tm_1_4_PID_not_valid((TMHandlerT *)b_tm_handler.data,
                                           tm_count,
                                           self->exec_tc_req_status_update.packet_id,
                                           self->exec_tc_req_status_update.packet_error_ctrl,
                                           self->exec_tc_req_status_update.PID,
                                           current_obt, &result);

                #line 360 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 362 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler, &result);

                    #line 364 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 365 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 365 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 369 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                    #line 370 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 370 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            }

        }

    } else
    {
        
        #line 378 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 378 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 382 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PS20ExecTCReqStatusUpdate PUSService20__get_TC_params(const PUSService20 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype,
                                                      MyResult * const result) {
    
    #line 388 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PS20ExecTCReqStatusUpdate tc_data;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.N = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.PID = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_id = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_20_3_data.PID_value_u32 = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_20_3_data.PID_value_u8 = 0U;
    #line 390 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_num_bytes = 0U;

    #line 401 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 402 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 403 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 404 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    *result = tc_handler_get_u8_appdata_field(tc_handler, &tc_data.N);

    #line 405 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler, &tc_data.PID);

    #line 407 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (*subtype == 3U) {
        
        #line 409 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        DataPoolItemType item_type = sys_data_pool_get_item_type(tc_data.PID);

        #line 412 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (item_type.__variant == DataPoolItemType__u8_t) {
            
            #line 413 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            *result = tc_handler_get_u8_appdata_field(tc_handler,
                                                      &tc_data.tc_20_3_data.PID_value_u8);

        } else
        #line 415 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (item_type.__variant == DataPoolItemType__u32_t) {
            
            #line 416 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            *result = tc_handler_get_u32_appdata_field(tc_handler,
                                                       &tc_data.tc_20_3_data.PID_value_u32);

        } else
        {
            
            #line 419 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*result).__variant = MyResult__Error;

        }

    }

    #line 424 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService20__manage_error_in_acceptance(const PUSService20 * const self) {
    
    #line 473 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 473 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 474 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 474 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 476 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 476 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 476 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 478 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 478 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 479 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 483 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 481 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 485 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 486 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 488 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 489 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 492 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 494 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 496 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 497 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 497 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 501 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 502 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 502 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 507 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 507 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 511 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_short_pack_length_error(const PUSService20 * const self) {
    
    #line 430 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 430 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 431 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 431 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 433 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 433 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 433 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 435 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 435 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 436 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 440 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 438 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 442 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 443 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 445 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 446 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 449 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 451 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 453 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 454 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 454 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 458 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 459 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 459 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 464 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 468 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

PSExecTCReqStatus PUSService20__manage_tm_limit_app_data_reached(const PUSService20 * const self) {
    
    #line 516 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    PSExecTCReqStatus next_status;
    #line 516 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 517 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MyResult result;
    #line 517 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    result.__variant = MyResult__Ok;

    #line 519 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    MissionObt current_obt;
    #line 519 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.finetime = 0U;
    #line 519 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    current_obt.seconds = 0U;

    #line 521 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    __option_box_t tm_handler;
    #line 521 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    tm_handler.__variant = None;

    #line 522 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 526 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (tm_handler.__variant == Some) {
        
        #line 524 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 528 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        uint16_t tm_count = 0U;

        #line 529 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 531 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 532 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 535 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 537 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 539 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 540 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 540 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 544 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 545 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 545 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 550 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 550 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 554 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    return next_status;

}

void PUSService20__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService20 * self = (PUSService20 *)__this;

    #line 560 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    uint8_t subtype = 0U;

    #line 562 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 566 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 568 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            MyResult result;
            #line 568 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            result.__variant = MyResult__Ok;

            #line 570 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status_update = PUSService20__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype,
                                                                          &result);

            #line 572 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 573 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 573 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 575 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 579 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 581 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 1U) {
                
                #line 583 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__exec20_1TC(self);

            } else
            #line 585 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (subtype == 3U) {
                
                #line 587 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__exec20_3TC(self);

            } else
            {
                
                #line 591 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 591 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 595 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 564 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 597 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 599 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 602 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__manage_error_in_acceptance(self);

            } else
            #line 604 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 607 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__manage_tm_limit_app_data_reached(self);

            } else
            #line 609 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 611 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
                self->exec_tc_req_status = PUSService20__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 619 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 564 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 621 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).__variant = Failure;
            #line 621 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 622 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 631 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 633 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 636 "src/service_libraries/pus_services/pus_service20/pus_service20.fin"
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
