
#include "service_libraries/pus_services/pus_service128/pus_service128.h"

PSExecTCReqStatus PUSService128__exec128_1TC(PUSService128 * const self) {
    
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PSExecTCReqStatus next_status;
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 27 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MyResult result;
    #line 27 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    result.__variant = MyResult__Ok;

    #line 28 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    _Bool ack_enabled = 0;

    #line 30 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MissionObt current_obt;
    #line 30 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.finetime = 0U;
    #line 30 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.seconds = 0U;

    #line 32 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __option_box_t tm_handler1;
    #line 32 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tm_handler1.__variant = None;

    #line 33 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler1);

    #line 37 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (tm_handler1.__variant == Some) {
        
        #line 35 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        #line 39 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        uint16_t tm_count1 = 0U;

        #line 40 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count1);

        #line 41 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 42 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &result, &ack_enabled);

        #line 44 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (ack_enabled) {
            
            #line 46 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 48 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler1,
                                         &result);

                #line 50 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 51 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 51 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 55 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

                #line 56 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 56 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 61 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else
    {
        
        #line 67 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 67 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 73 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->exec_tc_req_status_update.reebot_flag = 1;

    #line 76 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (next_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 78 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __option_box_t tm_handler2;
        #line 78 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        tm_handler2.__variant = None;

        #line 79 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 83 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 81 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 85 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            uint16_t tm_count2 = 0U;

            #line 86 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 87 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 88 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 90 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (ack_enabled) {
                
                #line 92 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 94 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler2, &result);

                    #line 96 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 97 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 97 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 101 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                    #line 102 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 102 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 107 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else
        {
            
            #line 113 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 113 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 122 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return next_status;

}

PS128ExecTCReqStatusUpdate PUSService128__get_TC_params(const PUSService128 * const self,
                                                        TCHandlerT * const tc_handler,
                                                        uint8_t * const subtype) {
    
    #line 129 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 131 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PS128ExecTCReqStatusUpdate tc_data;
    #line 131 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.flags_ack = 0U;
    #line 131 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 131 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.packet_id = 0U;
    #line 131 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.reebot_flag = 0;

    #line 132 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 133 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 134 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 136 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService128__manage_error_in_acceptance(const PUSService128 * const self) {
    
    #line 142 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PSExecTCReqStatus next_status;
    #line 142 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 143 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MyResult result;
    #line 143 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    result.__variant = MyResult__Ok;

    #line 145 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MissionObt current_obt;
    #line 145 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.finetime = 0U;
    #line 145 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.seconds = 0U;

    #line 147 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __option_box_t tm_handler;
    #line 147 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tm_handler.__variant = None;

    #line 148 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 152 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (tm_handler.__variant == Some) {
        
        #line 150 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 154 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        uint16_t tm_count = 0U;

        #line 155 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 157 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 158 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 161 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 163 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 165 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 166 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 166 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 170 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 171 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 171 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 176 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 176 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 180 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return next_status;

}

PSExecTCReqStatus PUSService128__manage_tm_limit_app_data_reached(const PUSService128 * const self) {
    
    #line 185 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PSExecTCReqStatus next_status;
    #line 185 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 186 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MyResult result;
    #line 186 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    result.__variant = MyResult__Ok;

    #line 188 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MissionObt current_obt;
    #line 188 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.finetime = 0U;
    #line 188 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.seconds = 0U;

    #line 190 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __option_box_t tm_handler;
    #line 190 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tm_handler.__variant = None;

    #line 191 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 195 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (tm_handler.__variant == Some) {
        
        #line 193 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 197 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        uint16_t tm_count = 0U;

        #line 198 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 200 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 201 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 204 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 206 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 208 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 209 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 209 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 213 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 214 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 214 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 219 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 219 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 223 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return next_status;

}

void PUSService128__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag) {
    
    PUSService128 * self = (PUSService128 *)__this;

    #line 228 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 230 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 234 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 236 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update = PUSService128__get_TC_params(self,
                                                                           tc_handler,
                                                                           &subtype);

            #line 237 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else
        #line 240 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 242 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (subtype == 1U) {
                
                #line 244 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status = PUSService128__exec128_1TC(self);

            } else
            {
                
                #line 248 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 248 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 252 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 232 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 254 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 256 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 259 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status = PUSService128__manage_error_in_acceptance(self);

            } else
            #line 261 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 264 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status = PUSService128__manage_tm_limit_app_data_reached(self);

            } else
            {
                

            }

        } else
        #line 274 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 232 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 276 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).__variant = Failure;
            #line 276 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 277 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 287 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 289 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        *reebot_flag = self->exec_tc_req_status_update.reebot_flag;

        #line 290 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 294 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return;

}

void PUSService128__exec_tc__mutex_lock(void * const __this,
                                        TCHandlerT * const tc_handler,
                                        __status_int32_t * const action_status,
                                        _Bool * const reebot_flag) {
    
    PUSService128 * self = (PUSService128 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService128__exec_tc(self, tc_handler, action_status, reebot_flag);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService128__exec_tc__task_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status,
                                       _Bool * const reebot_flag) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService128__exec_tc(__this, tc_handler, action_status, reebot_flag);
    __termina_task__unlock(lock);

}

void PUSService128__exec_tc__event_lock(void * const __this,
                                        TCHandlerT * const tc_handler,
                                        __status_int32_t * const action_status,
                                        _Bool * const reebot_flag) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService128__exec_tc(__this, tc_handler, action_status, reebot_flag);
    __termina_event__unlock(lock);

}
