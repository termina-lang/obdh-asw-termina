
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

PSExecTCReqStatus PUSService9__exec9_129TC(const __termina_event_t * const __ev,
                                           PUSService9 * const self) {
    
    #line 142 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    _Bool ack_enabled = 0;

    #line 143 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 143 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 143 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.status.__variant = Success;

    #line 145 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 145 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 145 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 147 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 147 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 148 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 152 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 150 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 154 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 155 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 156 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(__ev, self);

        #line 157 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &next_status.status, &ack_enabled);

        #line 159 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (ack_enabled) {
            
            #line 161 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (next_status.status.__variant == Success) {
                
                #line 163 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &next_status.status);

            } else
            {
                
                #line 167 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 172 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

        #line 175 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        PUSService9__set_obt(__ev, self);

        #line 177 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __option_box_t tm_handler2;
        #line 177 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        tm_handler2.__variant = None;

        #line 178 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 182 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 180 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 184 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            uint16_t tm_count2 = 0U;

            #line 185 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count2);

            #line 186 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            current_obt = PUSService9__inner_get_current_obt(__ev, self);

            #line 187 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &next_status.status, &ack_enabled);

            #line 189 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (ack_enabled) {
                
                #line 191 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (next_status.status.__variant == Success) {
                    
                    #line 193 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2,
                                             &next_status.status);

                } else
                {
                    
                    #line 197 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else
            {
                
                #line 203 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else
        {
            
            #line 207 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.status.__variant = Failure;
            #line 207 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        
        #line 215 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.__variant = Failure;
        #line 215 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 220 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_error_in_acceptance(const __termina_event_t * const __ev,
                                                          const PUSService9 * const self) {
    
    #line 280 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 280 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 280 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.status.__variant = Success;

    #line 282 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 282 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 282 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 284 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 284 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 285 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 289 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 287 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 291 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 292 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 294 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(__ev, self);

        #line 295 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &next_status.status);

        #line 298 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (next_status.status.__variant == Success) {
            
            #line 300 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 304 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 309 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.__variant = Failure;
        #line 309 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 313 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const __termina_event_t * const __ev,
                                                              const PUSService9 * const self) {
    
    #line 234 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 234 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 234 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.status.__variant = Success;

    #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 238 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 238 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 239 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 243 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 241 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 245 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 246 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 248 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(__ev, self);

        #line 249 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &next_status.status);

        #line 252 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (next_status.status.__variant == Success) {
            
            #line 254 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 258 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 263 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.__variant = Failure;
        #line 263 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 267 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_tm_limit_app_data_reached(const __termina_event_t * const __ev,
                                                                const PUSService9 * const self) {
    
    #line 326 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 326 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.exec_tc_status.__variant = PSReqStatus__Exit;
    #line 326 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.status.__variant = Success;

    #line 328 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 328 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 328 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 330 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 330 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 335 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 333 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 337 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 338 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 340 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(__ev, self);

        #line 341 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &next_status.status);

        #line 344 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (next_status.status.__variant == Success) {
            
            #line 346 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &next_status.status);

        } else
        {
            
            #line 350 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 356 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.__variant = Failure;
        #line 356 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 360 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

void PUSService9__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 373 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PUSService9 * self = (PUSService9 *)__this;

    #line 373 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 375 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 377 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Exit == 0; i = i + 1U) {
        
        #line 381 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__Init) {
            
            #line 383 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 384 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 385 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 386 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 387 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.status = tc_handler_get_u32_appdata_field(tc_handler,
                                                                               &self->exec_tc_req_status_update.next_OBT.seconds);

            #line 388 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.status = tc_handler_get_u16_appdata_field(tc_handler,
                                                                               &self->exec_tc_req_status_update.next_OBT.finetime);

            #line 390 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (self->exec_tc_req_status.status.__variant == Success) {
                
                #line 392 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__ExecTC;

            } else
            {
                
                #line 396 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        #line 401 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.exec_tc_status.__variant == PSReqStatus__ExecTC) {
            
            #line 403 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (subtype == 129U) {
                
                #line 405 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__exec9_129TC(__ev, self);

            } else
            {
                
                #line 409 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.status.__variant = Failure;
                #line 409 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 410 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Exit;

            }

        } else
        {
            

        }

    }

    #line 421 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (self->exec_tc_req_status.status.__variant == Success) {
        
        #line 423 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 419 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        int32_t error_code = self->exec_tc_req_status.status.Failure.__0;

        #line 428 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 430 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status = PUSService9__manage_error_in_acceptance(__ev,
                                                                               self);

        } else
        #line 432 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 434 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status = PUSService9__manage_tm_limit_app_data_reached(__ev,
                                                                                     self);

        } else
        #line 436 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 438 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status = PUSService9__manage_short_pack_length_error(__ev,
                                                                                   self);

        } else
        {
            
            #line 442 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).__variant = Failure;
            #line 442 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 450 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->exec_tc_req_status.exec_tc_status.__variant = PSReqStatus__Init;
    #line 451 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->exec_tc_req_status.status.__variant = Success;

    #line 455 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 455 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
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
