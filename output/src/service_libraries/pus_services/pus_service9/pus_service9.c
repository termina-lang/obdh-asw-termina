
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
    
    #line 117 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 117 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 118 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 118 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 120 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 122 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 122 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 123 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 127 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 125 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 129 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 130 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 131 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 132 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count, current_obt,
                     &result);

        #line 134 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 136 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 138 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 139 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 139 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 143 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 144 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

        #line 147 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        PUSService9__set_obt(self);

        #line 149 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __option_box_t tm_handler2;
        #line 149 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        tm_handler2.__variant = None;

        #line 150 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        #line 154 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (tm_handler2.__variant == Some) {
            
            #line 152 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            #line 156 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            uint16_t tm_count2 = 0U;

            #line 157 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            #line 158 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            current_obt = PUSService9__inner_get_current_obt(self);

            #line 159 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         current_obt, &result);

            #line 161 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Ok) {
                
                #line 163 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler2,
                                         &result);

                #line 165 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                if (result.__variant == MyResult__Error) {
                    
                    #line 166 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    #line 166 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else
            {
                
                #line 170 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

                #line 171 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Error;
                #line 171 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else
        {
            
            #line 175 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Failure;
            #line 175 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else
    {
        
        #line 183 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 183 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 188 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
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
    tc_data.next_OBT.finetime = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.next_OBT.seconds = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_error_ctrl = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_id = 0U;
    #line 95 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.tc_num_bytes = 0U;

    #line 104 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_id = tc_handler->packet_header.packet_id;

    #line 105 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    #line 106 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 107 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.next_OBT.seconds);

    #line 108 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &tc_data.next_OBT.finetime);

    #line 111 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return tc_data;

}

PSExecTCReqStatus PUSService9__manage_error_in_acceptance(const PUSService9 * const self) {
    
    #line 237 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 237 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 238 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 238 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 240 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 240 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 240 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 242 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 242 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 243 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 247 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 245 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 249 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 250 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 252 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 253 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         self->exec_tc_req_status_update.packet_id,
                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                         current_obt, &result);

        #line 256 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 258 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 260 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 261 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 261 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 265 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 266 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 266 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 271 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 271 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 275 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const PUSService9 * const self) {
    
    #line 195 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 195 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 196 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 196 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 198 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 198 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 198 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 200 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 200 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 201 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 205 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 203 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 207 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 208 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 210 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 211 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        #line 214 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 216 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 218 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 219 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 219 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 223 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 224 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 224 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 228 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 228 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 232 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

PSExecTCReqStatus PUSService9__manage_tm_limit_app_data_reached(const PUSService9 * const self) {
    
    #line 280 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    PSExecTCReqStatus next_status;
    #line 280 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    next_status.__variant = PSExecTCReqStatus__Exit;

    #line 281 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MyResult result;
    #line 281 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    result.__variant = MyResult__Ok;

    #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    MissionObt current_obt;
    #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.finetime = 0U;
    #line 283 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    current_obt.seconds = 0U;

    #line 285 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    __option_box_t tm_handler;
    #line 285 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    tm_handler.__variant = None;

    #line 286 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 290 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (tm_handler.__variant == Some) {
        
        #line 288 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 292 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        uint16_t tm_count = 0U;

        #line 293 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 295 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        current_obt = PUSService9__inner_get_current_obt(self);

        #line 296 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             self->exec_tc_req_status_update.packet_id,
                                             self->exec_tc_req_status_update.packet_error_ctrl,
                                             current_obt, &result);

        #line 299 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 301 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            #line 303 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 304 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.__variant = PSExecTCReqStatus__Failure;
                #line 304 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else
        {
            
            #line 308 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            #line 309 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.__variant = PSExecTCReqStatus__Error;
            #line 309 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else
    {
        
        #line 314 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.__variant = PSExecTCReqStatus__Failure;
        #line 314 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 318 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    return next_status;

}

void PUSService9__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService9 * self = (PUSService9 *)__this;

    #line 325 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 327 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 331 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 333 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            MyResult result;
            #line 333 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            result.__variant = MyResult__Ok;

            #line 334 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status_update = PUSService9__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            #line 336 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (result.__variant == MyResult__Error) {
                
                #line 337 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 337 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else
            {
                
                #line 339 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else
        #line 343 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 345 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (subtype == 129U) {
                
                #line 347 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__exec9_129TC(self);

            } else
            {
                
                #line 351 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                #line 351 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else
        #line 355 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            #line 329 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            #line 357 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 359 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == ACCEPTANCE_ERROR) {
                
                #line 362 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_error_in_acceptance(self);

            } else
            #line 364 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == BUILD_TM_ERROR) {
                
                #line 367 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_tm_limit_app_data_reached(self);

            } else
            #line 369 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                #line 371 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
                self->exec_tc_req_status = PUSService9__manage_short_pack_length_error(self);

            } else
            {
                

            }

        } else
        #line 379 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            #line 329 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            #line 381 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).__variant = Failure;
            #line 381 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            (*action_status).Failure.__0 = failure_code;

            #line 382 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else
        {
            

        }

    }

    #line 391 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        #line 393 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

    }

    #line 396 "src/service_libraries/pus_services/pus_service9/pus_service9.fin"
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
