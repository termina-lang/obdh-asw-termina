
#include "service_libraries/pus_services/pus_service128/pus_service128.h"

__status_int32_t PUSService128__exec128_1TC(const __termina_event_t * const __ev,
                                            PUSService128 * const self) {
    
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __status_int32_t status;
    #line 26 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    status.__variant = Success;

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
        status = build_tm_1_3((TMHandlerT *)b_tm_handler1.data, tm_count1,
                              self->exec_tc_req_status_update.packet_id,
                              self->exec_tc_req_status_update.packet_seq_ctrl,
                              self->exec_tc_req_status_update.flags_ack,
                              current_obt, &ack_enabled);

        #line 43 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (ack_enabled) {
            
            #line 45 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (status.__variant == Success) {
                
                #line 47 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler1, &status);

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
        status.__variant = Failure;
        #line 64 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 70 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->exec_tc_req_status_update.reebot_flag = 1;

    #line 73 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (status.__variant == Success) {
        
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
            status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                  self->exec_tc_req_status_update.packet_id,
                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                  self->exec_tc_req_status_update.flags_ack,
                                  current_obt, &ack_enabled);

            #line 87 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (ack_enabled) {
                
                #line 89 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (status.__variant == Success) {
                    
                    #line 91 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2, &status);

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
            status.__variant = Failure;
            #line 107 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 116 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return status;

}

void PUSService128__exec_tc(const __termina_event_t * const __ev,
                            void * const __this, TCHandlerT * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag) {
    
    #line 124 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    PUSService128 * self = (PUSService128 *)__this;

    #line 124 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 126 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __status_int32_t status;
    #line 126 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    status.__variant = Success;

    #line 127 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 129 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 133 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 135 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 136 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 137 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 139 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

        } else
        #line 144 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 146 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 148 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            if (subtype == 1U) {
                
                #line 150 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                status = PUSService128__exec128_1TC(__ev, self);

            } else
            {
                
                #line 154 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                status.__variant = Failure;
                #line 154 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 166 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    if (status.__variant == Success) {
        
        #line 168 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 164 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        int32_t error_code = status.Failure.__0;

        #line 173 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR) {
            
            #line 175 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).__variant = Success;

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
                MissionObt current_obt;
                #line 185 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                current_obt.finetime = 0U;
                #line 185 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                current_obt.seconds = 0U;

                #line 187 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 188 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 190 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 192 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 195 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 197 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                {
                    

                }

                #line 207 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                if (status.__variant == Success) {
                    
                    #line 209 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 213 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 219 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                status.__variant = Failure;
                #line 219 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 225 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).__variant = Failure;
            #line 225 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 232 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 234 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    *reebot_flag = self->exec_tc_req_status_update.reebot_flag;

    #line 237 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 237 "src/service_libraries/pus_services/pus_service128/pus_service128.fin"
    return;

}
