
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

    #line 44 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 44 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 45 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 49 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 47 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 51 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 52 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 53 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        PUSService17__build_tm_17_2(self, (TMHandlerT *)b_tm_handler.data,
                                    tm_count);

        #line 54 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                 &result);

        #line 56 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Error) {
            
            #line 57 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 57 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Failure.__0 = TM_SEND_FAILURE;

        }

    } else
    {
        
        #line 62 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 62 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 68 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PS17ExecTCReqStatusUpdate PUSService17__get_TC_params(const PUSService17 * const self,
                                                      TCHandlerT * const tc_handler,
                                                      uint8_t * const subtype) {
    
    #line 73 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 75 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PS17ExecTCReqStatusUpdate tc_data;
    #line 75 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 75 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = 0U;

    #line 76 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 77 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 79 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService17__manage_error_in_acceptance(const PUSService17 * const self) {
    
    #line 85 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 85 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 86 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 86 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 88 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 88 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 88 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 90 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 90 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 91 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 95 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 93 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 97 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 98 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 100 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 101 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 104 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 106 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 108 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 109 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 109 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 113 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 114 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 114 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 119 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 119 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 123 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

PSExecTCReqStatus PUSService17__manage_tm_limit_app_data_reached(const PUSService17 * const self) {
    
    #line 128 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    PSExecTCReqStatus next_status;
    #line 128 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 129 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MyResult result;
    #line 129 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    result.__variant = MyResult__Ok;

    #line 131 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    MissionObt current_obt;
    #line 131 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.finetime = 0U;
    #line 131 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    current_obt.seconds = 0U;

    #line 133 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    __option_box_t tm_handler;
    #line 133 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    tm_handler.__variant = None;

    #line 134 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 138 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (tm_handler.__variant == Some) {
        
        #line 136 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 140 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 141 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 143 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 144 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 147 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 149 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 151 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 152 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 152 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 156 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 157 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 157 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 162 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 162 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 166 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    return next_status;

}

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    #line 171 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 173 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 177 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 179 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status_update = PUSService17__get_TC_params(self,
                                                                          tc_handler,
                                                                          &subtype);

            #line 180 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else
        #line 183 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 185 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (subtype == 1U) {
                
                #line 187 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__exec17_1TC(self);

            } else
            {
                
                #line 191 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 191 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 195 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 175 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 197 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 199 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 202 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__manage_error_in_acceptance(self);

            } else
            #line 204 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 207 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
                self->exec_tc_req_status = PUSService17__manage_tm_limit_app_data_reached(self);

            } else
            {
                

            }

        } else
        #line 217 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 175 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 219 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).__variant = Failure;
            #line 219 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 220 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 230 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 232 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    #line 235 "src/service_libraries/pus_services/pus_service17/pus_service17.fin"
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
