
#include "service_libraries/pus_services/pus_service128/pus_service128.h"

PSExecTCReqStatus PUSService128__exec128_1TC(const __termina_event_t * const __ev,
                                             PUSService128 * const self) {
    
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PSExecTCReqStatus next_status;
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.status.__variant = Success;

    #line 27 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    _Bool ack_enabled = 0;

    #line 29 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MissionObt current_obt;
    #line 29 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.finetime = 0U;
    #line 29 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.seconds = 0U;

    #line 31 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __option_box_t tm_handler1;
    #line 31 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tm_handler1.__variant = None;

    #line 32 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler1);

    #line 36 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (tm_handler1.__variant == Some) {
        
        #line 34 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        #line 38 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        uint16_t tm_count1 = 0U;

        #line 39 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count1);

        #line 40 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 41 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &next_status.status, &ack_enabled);

        #line 43 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (ack_enabled) {
            
            #line 45 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (next_status.status.__variant == Success) {
                
                #line 47 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler1, &next_status.status);

            } else
            {
                
                #line 52 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

            }

        } else
        {
            
            #line 58 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else
    {
        
        #line 64 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.status.__variant = Failure;
        #line 64 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 70 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->exec_tc_req_status_update.reebot_flag = 1;

    #line 73 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (next_status.status.__variant == Success) {
        
        #line 75 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __option_box_t tm_handler2;
        #line 75 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        tm_handler2.__variant = None;

        #line 76 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 80 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 78 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 82 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            uint16_t tm_count2 = 0U;

            #line 83 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count2);

            #line 84 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 85 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &next_status.status, &ack_enabled);

            #line 87 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (ack_enabled) {
                
                #line 89 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 91 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2,
                                             &next_status.status);

                } else
                {
                    
                    #line 95 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else
            {
                
                #line 101 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else
        {
            
            #line 107 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.status.__variant = Failure;
            #line 107 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 116 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return next_status;

}

PSExecTCReqStatus PUSService128__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                            const PUSService128 * const self) {
    
    #line 134 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PSExecTCReqStatus next_status;
    #line 134 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 134 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.status.__variant = Success;

    #line 136 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MissionObt current_obt;
    #line 136 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.finetime = 0U;
    #line 136 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.seconds = 0U;

    #line 138 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __option_box_t tm_handler;
    #line 138 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tm_handler.__variant = None;

    #line 139 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 143 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (tm_handler.__variant == Some) {
        
        #line 141 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 145 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        uint16_t tm_count = 0U;

        #line 146 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 148 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 149 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 152 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (next_status.status.__variant == Success) {
            
            #line 154 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 158 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 164 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.status.__variant = Failure;
        #line 164 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 168 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return next_status;

}

PSExecTCReqStatus PUSService128__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                  const PUSService128 * const self) {
    
    #line 173 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PSExecTCReqStatus next_status;
    #line 173 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 173 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    next_status.status.__variant = Success;

    #line 175 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    MissionObt current_obt;
    #line 175 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.finetime = 0U;
    #line 175 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    current_obt.seconds = 0U;

    #line 177 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __option_box_t tm_handler;
    #line 177 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tm_handler.__variant = None;

    #line 178 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 182 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (tm_handler.__variant == Some) {
        
        #line 180 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 184 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        uint16_t tm_count = 0U;

        #line 185 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 187 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 188 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 191 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (next_status.status.__variant == Success) {
            
            #line 193 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 197 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 203 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.status.__variant = Failure;
        #line 203 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 207 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return next_status;

}

void PUSService128__exec_tc(const __termina_event_t * const __ev,
                            void * const __this, TCHandlerT * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag) {
    
    #line 210 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PUSService128 * self = (PUSService128 *)__this;

    #line 210 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 212 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 214 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 218 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 220 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 221 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 222 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 224 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

        } else
        #line 229 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 231 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (subtype == 1U) {
                
                #line 233 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status = PUSService128__exec128_1TC(__ev,
                                                                      self);

            } else
            {
                
                #line 237 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 237 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 238 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 250 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 252 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 248 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 257 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 259 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status = PUSService128__manage_error_in_acceptance(__ev,
                                                                                 self);

        } else
        #line 261 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 263 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status = PUSService128__manage_tm_limit_app_data_reached(__ev,
                                                                                       self);

        } else
        {
            
            #line 268 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).__variant = Failure;
            #line 268 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 276 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 277 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 280 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    *reebot_flag = self->exec_tc_req_status_update.reebot_flag;

    #line 283 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 283 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return;

}

PS128ExecTCReqStatusUpdate PUSService128__get_TC_params(const __termina_event_t * const __ev,
                                                        const PUSService128 * const self,
                                                        TCHandlerT * const tc_handler,
                                                        uint8_t * const subtype) {
    
    #line 123 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 125 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PS128ExecTCReqStatusUpdate tc_data;
    #line 125 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.flags_ack = 0U;
    #line 125 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 125 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.packet_id = 0U;
    #line 125 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    tc_data.reebot_flag = 0;

    #line 128 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return tc_data;

}
