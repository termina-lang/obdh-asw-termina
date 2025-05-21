
#include "service_libraries/pus_services/pus_service17/pus_service17.h"

void PUSService17__build_tm_17_2(const PUSService17 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter) {
    
    #line 28 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    startup_tm(p_tm_handler);

    #line 29 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 29 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 29 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 33 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 34 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    close_tm(p_tm_handler, 17U, 2U, tm_seq_counter, current_obt);

    #line 35 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return;

}

PSExecTCReqStatus PUSService17__exec17_1TC(PUSService17 * const self) {
    
    #line 40 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 40 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 41 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 41 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 42 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    _Bool ack_enabled = 0;

    #line 44 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 44 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 44 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 46 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler1;
    #line 46 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler1.__variant = None;

    #line 47 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler1);

    #line 51 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler1.__variant == Some) {
        
        #line 49 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        #line 53 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count1 = 0U;

        #line 54 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count1);

        #line 55 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 56 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &result, &ack_enabled);

        #line 58 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (ack_enabled) {
            
            #line 60 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 62 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler1,
                                         &result);

                #line 64 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 65 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 65 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 69 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

                #line 70 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 70 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 75 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else
    {
        
        #line 81 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 81 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 87 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (next_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 89 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler2;
        #line 89 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler2.__variant = None;

        #line 90 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 94 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 92 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 96 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count2 = 0U;

            #line 97 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 98 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            PUSService17__build_tm_17_2(self, (TMHandlerT *)b_tm_handler2.data,
                                        tm_count2);

            #line 99 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler2,
                                     &result);

            #line 101 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 102 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 102 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 107 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 107 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 116 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (next_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 118 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler3;
        #line 118 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler3.__variant = None;

        #line 119 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 123 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 121 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 125 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count3 = 0U;

            #line 126 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count3);

            #line 127 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 128 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 130 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (ack_enabled) {
                
                #line 132 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 134 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler3, &result);

                    #line 136 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 137 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 137 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 141 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                    #line 142 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 142 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 147 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 153 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 153 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 161 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PS17ExecTCReqStatusUpdate PUSService17__get_TC_params(const PUSService17 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype) {
    
    #line 166 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 168 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PS17ExecTCReqStatusUpdate tc_data;
    #line 168 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.flags_ack = 0U;
    #line 168 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 168 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = 0U;

    #line 169 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 170 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 171 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 173 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService17__manage_error_in_acceptance(const PUSService17 * const self) {
    
    #line 179 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 179 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 180 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 180 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 182 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 182 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 182 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 184 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 184 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 185 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 189 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 187 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 191 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 192 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 194 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 195 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 198 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 200 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 202 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 203 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 203 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 207 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 208 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 208 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 213 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 213 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 217 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PSExecTCReqStatus PUSService17__manage_tm_limit_app_data_reached(const PUSService17 * const self) {
    
    #line 222 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 222 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 223 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 223 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 225 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 225 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 225 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 227 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 227 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 228 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 232 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 230 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 234 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 235 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 237 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 238 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 241 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 243 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 245 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 246 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 246 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 250 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 251 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 251 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 256 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 256 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 260 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    #line 265 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 267 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 271 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 273 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update = PUSService17__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype);

            #line 274 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else
        #line 277 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 279 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (subtype == 1U) {
                
                #line 281 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__exec17_1TC(self);

            } else
            {
                
                #line 285 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 285 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 289 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 269 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 291 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 293 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 296 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__manage_error_in_acceptance(self);

            } else
            #line 298 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 301 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__manage_tm_limit_app_data_reached(self);

            } else
            {
                

            }

        } else
        #line 311 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 269 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 313 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).__variant = Failure;
            #line 313 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 314 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 324 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 326 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 329 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return;

}

void PUSService17__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService17__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService17__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService17__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService17__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService17__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}
