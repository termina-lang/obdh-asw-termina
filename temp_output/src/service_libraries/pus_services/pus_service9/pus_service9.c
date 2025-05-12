
#include "service_libraries/pus_services/pus_service9/pus_service9.h"

MissionObt PUSService9__inner_get_current_obt(const PUSService9 * const self) {
    
    uint32_t fine_time_increment = 0U;

    TimeVal time_val_from_power_on;
    time_val_from_power_on.tv_sec = 0U;
    time_val_from_power_on.tv_usec = 0U;

    self->system_port.clock_get_uptime(&time_val_from_power_on);

    TimeVal interval;
    interval.tv_sec = 0U;
    interval.tv_usec = 0U;

    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    MissionObt current_obt;
    current_obt.finetime = (uint16_t)(fine_time_increment & 0xFFFFU);
    current_obt.seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    return current_obt;

}

void PUSService9__set_obt(PUSService9 * const self) {
    
    self->ref_obt = self->exec_tc_req_status_update.next_OBT;

    TimeVal aux_time_val;
    aux_time_val.tv_sec = 0U;
    aux_time_val.tv_usec = 0U;

    self->system_port.clock_get_uptime(&aux_time_val);

    self->ref_time_val_from_power_on = aux_time_val;

    return;

}

PSExecTCReqStatus PUSService9__exec9_129TC(PUSService9 * const self) {
    
    MyResult result;
    result.__variant = MyResult__Ok;

    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        current_obt = PUSService9__inner_get_current_obt(self);

        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count, current_obt,
                     &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

        PUSService9__set_obt(self);

        __option_box_t tm_handler2;
        tm_handler2.__variant = None;

        self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        if (tm_handler2.__variant == Some) {
            
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            uint16_t tm_count2 = 0U;

            self->tm_counter.get_next_tm_count(self->tm_counter.__that,
                                               &tm_count2);

            current_obt = PUSService9__inner_get_current_obt(self);

            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         current_obt, &result);

            if (result.__variant == MyResult__Ok) {
                
                self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler2,
                                         &result);

                if (result.__variant == MyResult__Error) {
                    
                    next_status.__variant = PSExecTCReqStatus__Failure;
                    next_status.Failure.__0 = TM_SEND_FAILURE;

                }

            } else {
                
                self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

                next_status.__variant = PSExecTCReqStatus__Error;
                next_status.Error.__0 = BUILD_TM_ERROR;

            }

        } else {
            
            next_status.__variant = PSExecTCReqStatus__Failure;
            next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

PS9ExecTCReqStatusUpdate PUSService9__get_TC_params(const PUSService9 * const self,
                                                    TCHandlerT * const tc_handler,
                                                    uint8_t * const subtype,
                                                    MyResult * const result) {
    
    *subtype = tc_handler->df_header.subtype;

    PS9ExecTCReqStatusUpdate tc_data;
    tc_data.next_OBT.finetime = 0U;
    tc_data.next_OBT.seconds = 0U;
    tc_data.packet_error_ctrl = 0U;
    tc_data.packet_id = 0U;
    tc_data.tc_num_bytes = 0U;

    tc_data.packet_id = tc_handler->packet_header.packet_id;

    tc_data.packet_error_ctrl = tc_handler->packet_error_ctrl;

    tc_data.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    *result = tc_handler_get_u32_appdata_field(tc_handler,
                                               &tc_data.next_OBT.seconds);

    *result = tc_handler_get_u16_appdata_field(tc_handler,
                                               &tc_data.next_OBT.finetime);

    return tc_data;

}

PSExecTCReqStatus PUSService9__manage_short_pack_length_error(const PUSService9 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        current_obt = PUSService9__inner_get_current_obt(self);

        build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                       tm_count,
                                       self->exec_tc_req_status_update.packet_id,
                                       self->exec_tc_req_status_update.packet_error_ctrl,
                                       self->exec_tc_req_status_update.tc_num_bytes,
                                       current_obt, &result);

        if (result.__variant == MyResult__Ok) {
            
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

            if (result.__variant == MyResult__Error) {
                
                next_status.__variant = PSExecTCReqStatus__Failure;
                next_status.Failure.__0 = TM_SEND_FAILURE;

            }

        } else {
            
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

            next_status.__variant = PSExecTCReqStatus__Error;
            next_status.Error.__0 = BUILD_TM_ERROR;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

void PUSService9__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService9 * self = (PUSService9 *)__this;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            MyResult result;
            result.__variant = MyResult__Ok;

            self->exec_tc_req_status_update = PUSService9__get_TC_params(self,
                                                                         tc_handler,
                                                                         &subtype,
                                                                         &result);

            if (result.__variant == MyResult__Error) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = TC_DATA_OUT_OF_RANGE_ERROR;

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 129U) {
                
                self->exec_tc_req_status = PUSService9__exec9_129TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (error_code == ACCEPTANCE_ERROR) {
                

            } else if (error_code == BUILD_TM_ERROR) {
                

            } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                
                self->exec_tc_req_status = PUSService9__manage_short_pack_length_error(self);

            } else {
                

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = failure_code;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

    }

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

    uint32_t fine_time_increment = 0U;

    TimeVal time_val_from_power_on;
    time_val_from_power_on.tv_sec = 0U;
    time_val_from_power_on.tv_usec = 0U;

    self->system_port.clock_get_uptime(&time_val_from_power_on);

    TimeVal interval;
    interval.tv_sec = 0U;
    interval.tv_usec = 0U;

    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    current_obt->seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    current_obt->finetime = (uint16_t)(fine_time_increment & 0xFFFFU);

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
