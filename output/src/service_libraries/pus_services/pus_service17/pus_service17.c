
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
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 100 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.status.__variant = Success;

    #line 101 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    _Bool ack_enabled = 0;

    #line 103 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 103 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 103 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 105 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler1;
    #line 105 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler1.__variant = None;

    #line 106 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler1);

    #line 110 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler1.__variant == Some) {
        
        #line 108 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler1 = tm_handler1.Some.__0;

        #line 112 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count1 = 0U;

        #line 113 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count1);

        #line 114 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 115 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &next_status.status, &ack_enabled);

        #line 117 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (ack_enabled) {
            
            #line 119 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (next_status.status.__variant == Success) {
                
                #line 121 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler1,
                                         &next_status.status);

            } else
            {
                
                #line 125 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler1);

            }

        } else
        {
            
            #line 130 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler1);

        }

    } else
    {
        
        #line 136 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.status.__variant = Failure;
        #line 136 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 142 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (next_status.status.__variant == Success) {
        
        #line 144 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler2;
        #line 144 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler2.__variant = None;

        #line 145 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 149 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 147 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 151 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count2 = 0U;

            #line 152 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 153 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            PUSService17__build_tm_17_2(self, (TMHandlerT *)b_tm_handler2.data,
                                        tm_count2);

            #line 154 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler2,
                                     &next_status.status);

        } else
        {
            
            #line 160 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.status.__variant = Failure;
            #line 160 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 169 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (next_status.status.__variant == Success) {
        
        #line 171 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __option_box_t tm_handler3;
        #line 171 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        tm_handler3.__variant = None;

        #line 172 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler3);

        #line 176 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (tm_handler3.__variant == Some) {
            
            #line 174 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

            #line 178 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            uint16_t tm_count3 = 0U;

            #line 179 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count3);

            #line 180 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                                &current_obt);

            #line 181 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler3.data, tm_count3,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &next_status.status, &ack_enabled);

            #line 183 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (ack_enabled) {
                
                #line 185 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 187 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler3,
                                             &next_status.status);

                } else
                {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler3);

                }

            } else
            {
                
                #line 197 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler3);

            }

        } else
        {
            
            #line 203 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.status.__variant = Failure;
            #line 203 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 211 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PSExecTCReqStatus PUSService17__manage_error_in_acceptance(const PUSService17 * const self) {
    
    #line 242 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 242 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 242 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.status.__variant = Success;

    #line 244 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 244 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 244 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 246 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 246 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 247 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 251 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 249 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 253 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 254 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 256 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 257 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 260 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (next_status.status.__variant == Success) {
            
            #line 262 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &next_status.status);

        } else
        {
            
            #line 266 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 272 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.status.__variant = Failure;
        #line 272 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 276 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PSExecTCReqStatus PUSService17__manage_tm_limit_app_data_reached(const PUSService17 * const self) {
    
    #line 287 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 287 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 287 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.status.__variant = Success;

    #line 289 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 289 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 289 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 291 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 291 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 292 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 296 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 294 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 298 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 299 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 301 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 302 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 305 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (next_status.status.__variant == Success) {
            
            #line 307 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &next_status.status);

        } else
        {
            
            #line 311 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 317 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.status.__variant = Failure;
        #line 317 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 321 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    #line 337 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 339 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 343 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 345 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 346 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 347 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 348 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

        } else
        #line 351 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 353 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (subtype == 1U) {
                
                #line 355 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__exec17_1TC(self);

            } else
            {
                
                #line 359 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 359 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 360 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 371 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 373 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 369 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 378 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 380 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status = PUSService17__manage_error_in_acceptance(self);

        } else
        #line 382 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 384 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status = PUSService17__manage_tm_limit_app_data_reached(self);

        } else
        {
            
            #line 389 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).__variant = Failure;
            #line 389 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 397 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 398 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 401 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
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

PS17ExecTCReqStatusUpdate PUSService17__get_TC_params(const PUSService17 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype) {
    
    #line 225 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 227 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PS17ExecTCReqStatusUpdate tc_data;
    #line 227 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.flags_ack = 0U;
    #line 227 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 227 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = 0U;

    #line 230 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return tc_data;

}
