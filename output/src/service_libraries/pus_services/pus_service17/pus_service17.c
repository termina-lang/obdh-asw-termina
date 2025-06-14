
#include "service_libraries/pus_services/pus_service17/pus_service17.h"

__status_int32_t PUSService17__exec17_1TC(const __termina_event_t * const __ev,
                                          PUSService17 * const self) {
    
    #line 80 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __status_int32_t status;
    #line 80 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    status.__variant = Success;

    #line 81 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    _Bool ack_enabled = 0;

    #line 83 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 83 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 83 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 85 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler1;
    #line 85 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler1.__variant = None;

    #line 86 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler1);

    #line 90 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler1.__variant == Some) {
        
        #line 88 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        #line 92 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count1 = 0U;

        #line 93 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count1);

        #line 94 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 95 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &status, &ack_enabled);

        #line 97 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (ack_enabled) {
            
            #line 99 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (status.__variant == Success) {
                
                #line 101 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler1, &status);

            } else
            {
                
                #line 105 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

            }

        } else
        {
            
            #line 110 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else
    {
        
        #line 116 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        status.__variant = Failure;
        #line 116 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 122 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (status.__variant == Success) {
        
        #line 124 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler2;
        #line 124 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler2.__variant = None;

        #line 125 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 129 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 127 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 131 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count2 = 0U;

            #line 133 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count2);

            #line 134 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 135 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            build_tm_17_2((TMHandlerT *)b_tm_handler2.data, tm_count2,
                          current_obt);

            #line 136 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler2, &status);

        } else
        {
            
            #line 142 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            status.__variant = Failure;
            #line 142 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 151 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (status.__variant == Success) {
        
        #line 153 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler3;
        #line 153 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler3.__variant = None;

        #line 154 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 158 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 156 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 160 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count3 = 0U;

            #line 161 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count3);

            #line 162 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 163 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &status, &ack_enabled);

            #line 165 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (ack_enabled) {
                
                #line 167 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (status.__variant == Success) {
                    
                    #line 169 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler3, &status);

                } else
                {
                    
                    #line 173 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                }

            } else
            {
                
                #line 179 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 185 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            status.__variant = Failure;
            #line 185 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 193 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return status;

}

void PUSService17__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 211 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PUSService17 * self = (PUSService17 *)__this;

    #line 211 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 213 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __status_int32_t status;
    #line 213 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    status.__variant = Success;

    #line 214 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 216 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 220 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 222 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 223 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 224 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 225 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else
        #line 228 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 230 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 232 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (subtype == 1U) {
                
                #line 234 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                status = PUSService17__exec17_1TC(__ev, self);

            } else
            {
                
                #line 238 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                status.__variant = Failure;
                #line 238 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 250 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (status.__variant == Success) {
        
        #line 252 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 248 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        int32_t error_code = status.Failure.__0;

        #line 257 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR) {
            
            #line 259 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).__variant = Success;

            #line 261 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __option_box_t tm_handler;
            #line 261 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            tm_handler.__variant = None;

            #line 262 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 266 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (tm_handler.__variant == Some) {
                
                #line 264 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 268 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                uint16_t tm_count = 0U;

                #line 269 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                MissionObt current_obt;
                #line 269 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                current_obt.finetime = 0U;
                #line 269 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                current_obt.seconds = 0U;

                #line 271 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 272 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 274 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 276 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     current_obt, &status);

                } else
                #line 279 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 281 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                                         current_obt, &status);

                } else
                {
                    

                }

                #line 291 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (status.__variant == Success) {
                    
                    #line 293 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 297 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 303 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                status.__variant = Failure;
                #line 303 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 309 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).__variant = Failure;
            #line 309 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 316 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 318 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 318 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return;

}
