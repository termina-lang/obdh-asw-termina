
#include "service_libraries/pus_services/pus_service9/pus_service9.h"

MissionObt PUSService9__inner_get_current_obt(const PUSService9 * const self) {
    
    #line 65 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint32_t fine_time_increment = 0U;

    #line 66 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal time_val_from_power_on;
    #line 66 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 66 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 70 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(&time_val_from_power_on);

    #line 71 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal interval;
    #line 71 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_sec = 0U;
    #line 71 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_usec = 0U;

    #line 76 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    #line 78 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    #line 79 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    #line 81 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 81 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = (uint16_t)(fine_time_increment & 0xFFFFU);
    #line 81 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    #line 86 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return current_obt;

}

void PUSService9__set_obt(PUSService9 * const self) {
    
    #line 28 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->ref_obt = self->exec_tc_req_status_update.next_OBT;

    #line 29 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal aux_time_val;
    #line 29 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    aux_time_val.tv_sec = 0U;
    #line 29 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    aux_time_val.tv_usec = 0U;

    #line 33 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(&aux_time_val);

    #line 34 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->ref_time_val_from_power_on = aux_time_val;

    #line 36 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return;

}

PSExecTCReqStatus PUSService9__exec9_129TC(PUSService9 * const self) {
    
    #line 119 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 119 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    _Bool ack_enabled = 0;

    #line 121 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 121 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 123 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 123 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 123 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 125 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 125 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 126 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 130 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 128 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 132 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 133 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 134 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 135 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &result, &ack_enabled);

        #line 137 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (ack_enabled) {
            
            #line 139 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 141 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                         &result);

                #line 143 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 148 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler);

                #line 149 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 149 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 154 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

        #line 157 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        PUSService9__set_obt(self);

        #line 159 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __option_box_t tm_handler2;
        #line 159 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        tm_handler2.__variant = None;

        #line 160 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 164 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 162 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 166 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            uint16_t tm_count2 = 0U;

            #line 167 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 168 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            current_obt = PUSService9__inner_get_current_obt(self);

            #line 169 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &result, &ack_enabled);

            #line 171 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (ack_enabled) {
                
                #line 173 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (result.__variant == MyResult__Ok) {
                    
                    #line 175 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->tm_channel.send_tm(self->tm_channel.__that,
                                             b_tm_handler2, &result);

                    #line 177 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    if (result.__variant == MyResult__Error) {
                        
                        #line 178 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                        next_status.__variant = PSExecTCReqStatus__Failure;
                        #line 178 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                        next_status.Failure.__0 = TM_SEND_FAILURE;

                    }

                } else
                {
                    
                    #line 182 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                    #line 183 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.__variant = PSExecTCReqStatus__Error;
                    #line 183 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.Error.__0 = BUILD_TM_ERROR;

                }

            } else
            {
                
                #line 188 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else
        {
            
            #line 192 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 192 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        
        #line 200 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 200 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 205 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PS9ExecTCReqStatusUpdate PUSService9__get_TC_params(const PUSService9 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    #line 93 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *subtype = tc_handler->df_header.subtype;

    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PS9ExecTCReqStatusUpdate tc_data;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.flags_ack = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.next_OBT.finetime = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.next_OBT.seconds = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_id = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.tc_num_bytes = 0U;

    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 106 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 107 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 108 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 109 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.next_OBT.seconds);

    #line 110 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &tc_data.next_OBT.finetime);

    #line 113 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService9__manage_error_in_acceptance(const PUSService9 * const self) {
    
    #line 254 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 254 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 255 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 255 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 257 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 257 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 257 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 259 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 259 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 260 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 264 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 262 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 266 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 267 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 269 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 270 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 273 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 275 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 277 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 278 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 278 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 282 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 288 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 288 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 292 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const PUSService9 * const self) {
    
    #line 212 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 212 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 213 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 213 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 215 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 215 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 215 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 217 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 217 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 218 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 222 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 220 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 224 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 225 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 227 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 228 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 231 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 233 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 235 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 236 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 240 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 241 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 241 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 245 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 245 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 249 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_tm_limit_app_data_reached(const PUSService9 * const self) {
    
    #line 297 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 297 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 298 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 298 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 300 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 300 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 300 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 302 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 302 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 303 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 307 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 305 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 309 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 310 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 312 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 313 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 316 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 318 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 320 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 321 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 321 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 325 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 326 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 326 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 335 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

void PUSService9__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService9 * self = (PUSService9 *)__this;

    #line 342 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 344 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 348 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 350 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            MyResult result;
            #line 350 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            result.__variant = MyResult__Ok;

            #line 351 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update = PUSService9__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 353 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 354 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 354 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 356 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 360 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 362 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (subtype == 129U) {
                
                #line 364 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__exec9_129TC(self);

            } else
            {
                
                #line 368 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 368 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 372 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 346 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 374 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 376 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 379 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_error_in_acceptance(self);

            } else
            #line 381 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 384 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_tm_limit_app_data_reached(self);

            } else
            #line 386 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 388 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 396 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 346 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 398 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).__variant = Failure;
            #line 398 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 399 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 408 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 410 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

    }

    #line 413 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
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

    #line 41 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint32_t fine_time_increment = 0U;

    #line 42 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal time_val_from_power_on;
    #line 42 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_sec = 0U;
    #line 42 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    time_val_from_power_on.tv_usec = 0U;

    #line 46 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->system_port.clock_get_uptime(&time_val_from_power_on);

    #line 47 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    TimeVal interval;
    #line 47 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_sec = 0U;
    #line 47 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval.tv_usec = 0U;

    #line 52 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    #line 54 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    #line 55 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    #line 57 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt->seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    #line 58 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt->finetime = (uint16_t)(fine_time_increment & 0xFFFFU);

    #line 60 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
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
