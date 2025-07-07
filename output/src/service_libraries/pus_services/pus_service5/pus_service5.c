
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status) {
    
    #line 312 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 312 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 315 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 319 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 317 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 321 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        startup_tm((TMHandlerT *)b_tm_handler.data);

        #line 322 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        *status = append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                           EvID_build_tm_error);

        #line 324 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 326 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 327 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 328 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MissionObt current_obt;
            #line 328 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 328 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            #line 331 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 336 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 340 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 340 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 344 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 344 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    #line 348 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 348 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 351 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 355 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 353 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        MissionObt current_obt;
        #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        current_obt.finetime = 0U;
        #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        current_obt.seconds = 0U;

        #line 360 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 363 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 364 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            *status = build_tm_5_x_param_out_of_limit((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      fault_value_info, evID,
                                                      current_obt);

        } else
        #line 366 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 367 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            *status = build_tm_5_x_param_check_value_fail((TMHandlerT *)b_tm_handler.data,
                                                          tm_count,
                                                          fault_value_info,
                                                          evID, current_obt);

        } else
        {
            

        }

        #line 374 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 376 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 380 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 386 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 386 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 390 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 390 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

__status_int32_t PUSService5__exec5_5TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 61 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 61 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 63 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 63 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 63 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 65 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 65 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 66 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 70 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 68 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 72 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 73 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 75 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 76 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 79 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 81 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 82 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 85 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 87 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 91 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 97 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 99 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 101 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 102 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 104 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 106 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (status.__variant == Success) {
                        
                        #line 108 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 112 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 116 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 119 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

                #line 121 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 121 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 122 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 126 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 124 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 130 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 131 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 133 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 135 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (status.__variant == Success) {
                            
                            #line 137 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 141 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 146 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 151 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.__variant = Failure;
                    #line 151 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 157 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 158 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.EvID,
                                                     current_obt);

                #line 161 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 163 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 167 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 176 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.__variant = Failure;
        #line 176 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 180 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return status;

}

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 187 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 187 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 189 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 189 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 189 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 191 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 191 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 192 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 196 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 194 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 198 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 199 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 201 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 202 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 205 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 207 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 208 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 211 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 213 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 217 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 224 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 226 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 228 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 229 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 231 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 233 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (status.__variant == Success) {
                        
                        #line 235 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 239 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 243 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 246 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

                #line 248 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 248 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 249 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 253 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 251 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 255 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 256 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 257 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 258 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 260 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 262 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (status.__variant == Success) {
                            
                            #line 264 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 268 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 272 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 276 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.__variant = Failure;
                    #line 276 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 282 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 283 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.EvID,
                                                     current_obt);

                #line 286 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 288 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 292 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 300 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.__variant = Failure;
        #line 300 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 304 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return status;

}

void PUSService5__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 396 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 396 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 398 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 398 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 399 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 401 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 405 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 407 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 408 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 409 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 410 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 411 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            #line 412 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 413 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.EvID);

            }

            #line 416 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 418 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 422 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 422 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 423 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 428 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 430 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 432 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 5U) {
                
                #line 434 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = PUSService5__exec5_5TC(__ev, self);

            } else
            #line 436 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 6U) {
                
                #line 438 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = PUSService5__exec5_6TC(__ev, self);

            } else
            {
                
                #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 442 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 453 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (status.__variant == Success) {
        
        #line 455 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 451 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        int32_t error_code = status.Failure.__0;

        #line 460 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 462 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Success;

            #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            __option_box_t tm_handler;
            #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            tm_handler.__variant = None;

            #line 465 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (tm_handler.__variant == Some) {
                
                #line 467 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 471 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                uint16_t tm_count = 0U;

                #line 472 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                MissionObt current_obt;
                #line 472 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                current_obt.finetime = 0U;
                #line 472 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                current_obt.seconds = 0U;

                #line 474 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 475 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 477 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 479 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 482 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 484 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 487 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 489 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 499 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 501 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 505 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 511 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 511 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 517 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 517 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 524 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 526 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 526 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

_Bool PUSService5__is_Ev_ID_enabled(const __termina_event_t * const __ev,
                                    const PUSService5 * const self,
                                    uint16_t Ev_ID) {
    
    #line 35 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool enabled = 0;

    #line 36 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    size_t index = get_Ev_ID_enable_config_index(Ev_ID);

    #line 37 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t offset = get_Ev_ID_enable_config_offset(Ev_ID);

    #line 39 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (index <= 4U) {
        
        #line 41 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t config_array_index = index - 1U;

        #line 42 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((uint32_t)((uint32_t)(self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                   config_array_index)] >> offset) & 0x1U) != 0U) {
            
            #line 43 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            enabled = 1;

        }

    }

    #line 47 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return enabled;

}

void PUSService5__is_Ev_ID_enabled_ext(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled) {
    
    #line 50 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 50 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 52 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *p_enabled = PUSService5__is_Ev_ID_enabled(__ev, self, Ev_ID);

    #line 54 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 54 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}
