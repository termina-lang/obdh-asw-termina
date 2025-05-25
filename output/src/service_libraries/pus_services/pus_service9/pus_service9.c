
#include "service_libraries/pus_services/pus_service9/pus_service9.h"

MissionObt PUSService9__inner_get_current_obt(const PUSService9 * const self) {
    
    #line 104 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint32_t fine_time_increment = 0U;

    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal time_val_from_power_on;
    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 109 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(&time_val_from_power_on);

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

void PUSService9__set_obt(PUSService9 * const self) {
    
    #line 50 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->ref_obt = self->exec_tc_req_status_update.next_OBT;

    #line 51 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal aux_time_val;
    #line 51 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    aux_time_val.tv_sec = 0U;
    #line 51 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    aux_time_val.tv_usec = 0U;

    #line 55 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(&aux_time_val);

    #line 56 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->ref_time_val_from_power_on = aux_time_val;

    #line 58 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return;

}

PSExecTCReqStatus PUSService9__exec9_129TC(PUSService9 * const self) {
    
    #line 178 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 178 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 179 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    _Bool ack_enabled = 0;

    #line 180 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 180 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 182 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 182 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 182 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 184 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 184 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 185 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 189 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 187 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 191 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 192 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 193 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 194 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &result, &ack_enabled);

        #line 196 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (ack_enabled) {
            
            #line 198 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 200 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 202 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 203 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 203 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 207 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 208 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 208 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 213 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

        #line 216 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        PUSService9__set_obt(self);

        #line 218 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __option_box_t tm_handler2;
        #line 218 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        tm_handler2.__variant = None;

        #line 219 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 223 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 221 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 225 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            uint16_t tm_count2 = 0U;

            #line 226 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 227 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            current_obt = PUSService9__inner_get_current_obt(self);

            #line 228 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 230 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (ack_enabled) {
                
                #line 232 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 234 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler2, &result);

                    #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 237 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 237 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 241 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                    #line 242 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 242 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 247 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else
        {
            
            #line 251 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 251 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        
        #line 259 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 259 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 264 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PS9ExecTCReqStatusUpdate PUSService9__get_TC_params(const PUSService9 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 142 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PS9ExecTCReqStatusUpdate tc_data;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.flags_ack = 0U;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.next_OBT.finetime = 0U;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.next_OBT.seconds = 0U;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_id = 0U;
    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.tc_num_bytes = 0U;

    #line 154 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 155 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 156 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 157 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 158 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.next_OBT.seconds);

    #line 159 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &tc_data.next_OBT.finetime);

    #line 162 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService9__manage_error_in_acceptance(const PUSService9 * const self) {
    
    #line 328 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 328 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 329 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 329 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 333 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 333 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 334 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 338 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 336 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 340 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 341 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 343 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 344 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 347 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 349 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 351 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 352 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 352 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 356 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 357 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 357 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 362 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 362 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 366 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const PUSService9 * const self) {
    
    #line 278 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 278 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 279 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 279 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 281 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 281 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 281 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 284 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 288 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 286 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 290 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 291 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 293 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 294 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 297 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 299 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 301 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 302 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 302 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 306 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 307 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 307 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 311 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 311 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 315 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_tm_limit_app_data_reached(const PUSService9 * const self) {
    
    #line 379 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 379 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 380 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 380 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 382 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 382 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 382 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 384 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 384 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 385 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 389 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 387 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 391 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 392 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 394 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 395 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 398 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 400 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 402 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 403 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 403 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 407 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 408 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 408 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 413 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 413 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 417 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

void PUSService9__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService9 * self = (PUSService9 *)__this;

    #line 432 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 434 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 438 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 440 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            MyResult result;
            #line 440 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            result.__variant = MyResult__Ok;

            #line 441 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update = PUSService9__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 443 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 444 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 444 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 446 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 450 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 452 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (subtype == 129U) {
                
                #line 454 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__exec9_129TC(self);

            } else
            {
                
                #line 458 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 458 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 462 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 436 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 464 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 466 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 468 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_error_in_acceptance(self);

            } else
            #line 470 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 472 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_tm_limit_app_data_reached(self);

            } else
            #line 474 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 476 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 484 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 436 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 486 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).__variant = Failure;
            #line 486 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 487 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 496 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 498 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

    }

    #line 501 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return;

}

void PUSService9__exec_tc__mutex_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    PUSService9 * self = (PUSService9 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService9__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService9__exec_tc__task_lock(void * const __this,
                                     TCHandlerT * const tc_handler,
                                     __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService9__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService9__exec_tc__event_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService9__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}

void PUSService9__get_current_obt(void * const __this,
                                  MissionObt * const current_obt) {
    
    PUSService9 * self = (PUSService9 *)__this;

    #line 72 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint32_t fine_time_increment = 0U;

    #line 73 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal time_val_from_power_on;
    #line 73 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 73 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 77 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(&time_val_from_power_on);

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
    return;

}

void PUSService9__get_current_obt__mutex_lock(void * const __this,
                                              MissionObt * const current_obt) {
    
    PUSService9 * self = (PUSService9 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService9__get_current_obt(self, current_obt);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService9__get_current_obt__task_lock(void * const __this,
                                             MissionObt * const current_obt) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService9__get_current_obt(__this, current_obt);
    __termina_task__unlock(lock);

}

void PUSService9__get_current_obt__event_lock(void * const __this,
                                              MissionObt * const current_obt) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService9__get_current_obt(__this, current_obt);
    __termina_event__unlock(lock);

}
