
#include "service_libraries/pus_services/pus_service9/pus_service9.h"

MissionObt PUSService9__inner_get_current_obt(const __termina_event_t * const __ev,
                                              const PUSService9 * const self) {
    
    uint32_t fine_time_increment = 0U;

    TimeVal time_val_from_power_on;
    time_val_from_power_on.tv_sec = 0U;
    time_val_from_power_on.tv_usec = 0U;

    self->system_port.clock_get_uptime(__ev, &time_val_from_power_on);

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

void PUSService9__set_obt(const __termina_event_t * const __ev,
                          PUSService9 * const self) {
    
    self->ref_obt = self->exec_tc_req_status_update.next_OBT;

    TimeVal aux_time_val;
    aux_time_val.tv_sec = 0U;
    aux_time_val.tv_usec = 0U;

    self->system_port.clock_get_uptime(__ev, &aux_time_val);

    self->ref_time_val_from_power_on = aux_time_val;

    return;

}

__status_int32_t PUSService9__exec9_129TC(const __termina_event_t * const __ev,
                                          PUSService9 * const self) {
    
    __status_int32_t status;
    status.__variant = Success;

    _Bool ack_enabled = 0;

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        current_obt = PUSService9__inner_get_current_obt(__ev, self);

        build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                     self->exec_tc_req_status_update.flags_ack, current_obt,
                     &status, &ack_enabled);

        if (ack_enabled) {
            
            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

        PUSService9__set_obt(__ev, self);

        __option_box_t tm_handler2;
        tm_handler2.__variant = None;

        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler2);

        if (tm_handler2.__variant == Some) {
            
            __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

            uint16_t tm_count2 = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count2);

            current_obt = PUSService9__inner_get_current_obt(__ev, self);

            build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                         self->exec_tc_req_status_update.flags_ack, current_obt,
                         &status, &ack_enabled);

            if (ack_enabled) {
                
                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler2, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler2);

                }

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler2);

            }

        } else {
            
            status.__variant = Failure;
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    } else {
        
        status.__variant = Failure;
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return status;

}

void PUSService9__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    PUSService9 * self = (PUSService9 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    __status_int32_t status;
    status.__variant = Success;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            status = tc_handler_get_u32_appdata_field(tc_handler,
                                                      &self->exec_tc_req_status_update.next_OBT.seconds);

            if (status.__variant == Success) {
                
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.next_OBT.finetime);

            }

            if (status.__variant == Success) {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (subtype == 129U) {
                
                status = PUSService9__exec9_129TC(__ev, self);

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else {
            

        }

    }

    if (status.__variant == Success) {
        
        (*action_status).__variant = Success;

    } else {
        
        int32_t error_code = status.Failure.__0;

        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            (*action_status).__variant = Success;

            __option_box_t tm_handler;
            tm_handler.__variant = None;

            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            if (tm_handler.__variant == Some) {
                
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                uint16_t tm_count = 0U;

                MissionObt current_obt = PUSService9__inner_get_current_obt(__ev,
                                                                            self);

                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                if (error_code == ACCEPTANCE_ERROR) {
                    
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     current_obt, &status);

                } else if (error_code == BUILD_TM_ERROR) {
                    
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                                         current_obt, &status);

                } else if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.packet_id,
                                                   self->exec_tc_req_status_update.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_num_bytes,
                                                   current_obt, &status);

                } else {
                    

                }

                if (status.__variant == Success) {
                    
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else {
                    
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else {
                
                status.__variant = Failure;
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else {
            
            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = error_code;

        }

    }

    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}

void PUSService9__get_current_obt(const __termina_event_t * const __ev,
                                  void * const __this,
                                  MissionObt * const current_obt) {
    
    PUSService9 * self = (PUSService9 *)__this;

    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    uint32_t fine_time_increment = 0U;

    TimeVal time_val_from_power_on;
    time_val_from_power_on.tv_sec = 0U;
    time_val_from_power_on.tv_usec = 0U;

    self->system_port.clock_get_uptime(__ev, &time_val_from_power_on);

    TimeVal interval;
    interval.tv_sec = 0U;
    interval.tv_usec = 0U;

    interval = substract_TimeVal(time_val_from_power_on,
                                 self->ref_time_val_from_power_on);

    fine_time_increment = (uint32_t)self->ref_obt.finetime;

    fine_time_increment = fine_time_increment + (uint32_t)((uint32_t)(interval.tv_usec * 1000U) / 15259U);

    current_obt->seconds = (uint32_t)((uint32_t)(self->ref_obt.seconds + interval.tv_sec) + fine_time_increment) >> 16U;

    current_obt->finetime = (uint16_t)(fine_time_increment & 0xFFFFU);

    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    return;

}
