
#include "service_libraries/pus_services/pus_service9/pus_service9.h"

MissionObt PUSService9__inner_get_current_obt(const __termina_event_t * const __ev,
                                              const PUSService9 * const self) {
    
    #line 104 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint32_t fine_time_increment = 0U;

    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal time_val_from_power_on;
    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 109 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(__ev, &time_val_from_power_on);

    #line 110 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal interval;
    #line 110 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_sec = 0U;
    #line 110 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_usec = 0U;

    #line 115 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    #line 117 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    #line 118 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = (uint16_t)(fine_time_increment & 0xFFFFU);
    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    #line 125 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return current_obt;

}

void PUSService9__set_obt(const __termina_event_t * const __ev,
                          PUSService9 * const self) {
    
    #line 50 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->ref_obt = self->exec_tc_req_status_update.next_OBT;

    #line 51 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal aux_time_val;
    #line 51 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    aux_time_val.tv_sec = 0U;
    #line 51 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    aux_time_val.tv_usec = 0U;

    #line 55 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(__ev, &aux_time_val);

    #line 56 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->ref_time_val_from_power_on = aux_time_val;

    #line 58 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return;

}

__status_int32_t PUSService9__exec9_129TC(const __termina_event_t * const __ev,
                                          PUSService9 * const self) {
    
    #line 142 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __status_int32_t status;
    #line 142 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    status.__variant = Success;

    #line 143 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    _Bool ack_enabled = 0;

    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 146 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 146 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 147 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 151 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 149 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 153 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 154 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 155 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(__ev, self);

        #line 156 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &status, &ack_enabled);

        #line 158 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (ack_enabled) {
            
            #line 160 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (status.__variant == Success) {
                
                #line 162 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 166 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 171 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

        #line 174 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        PUSService9__set_obt(__ev, self);

        #line 176 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __option_box_t tm_handler2;
        #line 176 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        tm_handler2.__variant = None;

        #line 177 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 181 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 179 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 183 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            uint16_t tm_count2 = 0U;

            #line 184 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count2);

            #line 185 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            current_obt = PUSService9__inner_get_current_obt(__ev, self);

            #line 186 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &status, &ack_enabled);

            #line 188 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (ack_enabled) {
                
                #line 190 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (status.__variant == Success) {
                    
                    #line 192 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2, &status);

                } else
                {
                    
                    #line 196 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else
            {
                
                #line 202 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else
        {
            
            #line 206 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            status.__variant = Failure;
            #line 206 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        
        #line 214 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        status.__variant = Failure;
        #line 214 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 219 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return status;

}

void PUSService9__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PUSService9 * self = (PUSService9 *)__this;

    #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 238 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __status_int32_t status;
    #line 238 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    status.__variant = Success;

    #line 239 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 241 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 245 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 247 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 248 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 249 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 250 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 251 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                      &self->exec_tc_req_status_update.next_OBT.seconds);

            #line 252 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (status.__variant == Success) {
                
                #line 253 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.next_OBT.finetime);

            }

            #line 257 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (status.__variant == Success) {
                
                #line 259 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 263 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 268 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 270 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 272 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (subtype == 129U) {
                
                #line 274 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                status = PUSService9__exec9_129TC(__ev, self);

            } else
            {
                
                #line 278 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                status.__variant = Failure;
                #line 278 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 290 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (status.__variant == Success) {
        
        #line 292 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 288 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        int32_t error_code = status.Failure.__0;

        #line 297 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 299 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).__variant = Success;

            #line 301 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            __option_box_t tm_handler;
            #line 301 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            tm_handler.__variant = None;

            #line 302 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 307 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (tm_handler.__variant == Some) {
                
                #line 305 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 309 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                uint16_t tm_count = 0U;

                #line 310 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                MissionObt current_obt = PUSService9__inner_get_current_obt(__ev,
                                                                            self);

                #line 312 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 315 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 317 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     current_obt, &status);

                } else
                #line 320 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 322 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                                         current_obt, &status);

                } else
                #line 325 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 327 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.packet_id,
                                                   self->exec_tc_req_status_update.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_num_bytes,
                                                   current_obt, &status);

                } else
                {
                    

                }

                #line 337 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (status.__variant == Success) {
                    
                    #line 339 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 343 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 349 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                status.__variant = Failure;
                #line 349 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 355 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).__variant = Failure;
            #line 355 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 362 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 365 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 365 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return;

}

void PUSService9__get_current_obt(const __termina_event_t * const __ev,
                                  void * const __this,
                                  MissionObt * const current_obt) {
    
    #line 70 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PUSService9 * self = (PUSService9 *)__this;

    #line 70 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 72 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint32_t fine_time_increment = 0U;

    #line 73 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal time_val_from_power_on;
    #line 73 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 73 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 77 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(__ev, &time_val_from_power_on);

    #line 78 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal interval;
    #line 78 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_sec = 0U;
    #line 78 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_usec = 0U;

    #line 83 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    #line 85 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    #line 86 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    #line 88 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt->seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    #line 89 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt->finetime = (uint16_t)(fine_time_increment & 0xFFFFU);

    #line 91 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 91 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return;

}
