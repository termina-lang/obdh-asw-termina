
#include "service_libraries/pus_services/pus_service17/pus_service17.h"

void PUSService17__build_tm_17_2(const PUSService17 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter) {
    
    #line 79 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    startup_tm(p_tm_handler);

    #line 80 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 80 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 80 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 84 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    #line 85 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    close_tm(p_tm_handler, 17U, 2U, tm_seq_counter, current_obt);

    #line 86 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return;

}

PSExecTCReqStatus PUSService17__exec17_1TC(PUSService17 * const self) {
    
    #line 100 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 100 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 101 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 101 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 102 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    _Bool ack_enabled = 0;

    #line 104 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 104 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 104 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 106 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler1;
    #line 106 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler1.__variant = None;

    #line 107 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler1);

    #line 111 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler1.__variant == Some) {
        
        #line 109 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        #line 113 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count1 = 0U;

        #line 114 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count1);

        #line 115 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 116 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &result, &ack_enabled);

        #line 118 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (ack_enabled) {
            
            #line 120 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 122 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler1,
                                         &result);

                #line 124 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 125 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 125 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 129 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

                #line 130 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 130 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 135 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else
    {
        
        #line 141 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 141 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 147 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (next_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 149 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler2;
        #line 149 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler2.__variant = None;

        #line 150 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 154 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 152 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 156 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count2 = 0U;

            #line 157 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 158 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            PUSService17__build_tm_17_2(self, (TMHandlerT *)b_tm_handler2.data,
                                        tm_count2);

            #line 159 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler2,
                                     &result);

            #line 161 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 162 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 162 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 167 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 167 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 176 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (next_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 178 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler3;
        #line 178 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler3.__variant = None;

        #line 179 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 183 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 181 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 185 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count3 = 0U;

            #line 186 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count3);

            #line 187 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 188 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 190 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (ack_enabled) {
                
                #line 192 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 194 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler3, &result);

                    #line 196 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 197 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 197 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 201 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                    #line 202 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 202 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 207 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 213 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 213 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 221 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PS17ExecTCReqStatusUpdate PUSService17__get_TC_params(const PUSService17 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype) {
    
    #line 235 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 237 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PS17ExecTCReqStatusUpdate tc_data;
    #line 237 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.flags_ack = 0U;
    #line 237 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 237 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = 0U;

    #line 238 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 239 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 240 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 242 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService17__manage_error_in_acceptance(const PUSService17 * const self) {
    
    #line 254 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 254 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 255 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 255 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 257 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 257 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 257 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 259 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 259 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 260 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 264 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 262 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 266 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 267 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 269 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 270 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 273 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 275 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 277 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 278 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 278 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 282 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 283 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 283 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 288 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 288 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 292 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PSExecTCReqStatus PUSService17__manage_tm_limit_app_data_reached(const PUSService17 * const self) {
    
    #line 303 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 303 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 304 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 304 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 306 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 306 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 306 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 308 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 308 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 309 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 313 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 311 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 315 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 316 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 318 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 319 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 322 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 324 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 326 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 327 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 327 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 331 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 332 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 332 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 337 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 337 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 341 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    #line 357 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 359 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 363 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 365 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update = PUSService17__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype);

            #line 366 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else
        #line 369 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 371 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (subtype == 1U) {
                
                #line 373 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__exec17_1TC(self);

            } else
            {
                
                #line 377 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 377 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 381 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 361 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 383 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 385 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 388 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__manage_error_in_acceptance(self);

            } else
            #line 390 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 393 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__manage_tm_limit_app_data_reached(self);

            } else
            {
                

            }

        } else
        #line 403 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 361 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 405 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).__variant = Failure;
            #line 405 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 406 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 416 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 418 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 421 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
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
