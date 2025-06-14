
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status) {
    
    #line 311 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 311 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 313 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 313 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 318 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 320 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        startup_tm((TMHandlerT *)b_tm_handler.data);

        #line 321 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                 EvID_build_tm_error, status);

        #line 323 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 325 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 326 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 327 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MissionObt current_obt;
            #line 327 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 327 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 328 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 335 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 339 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 339 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 343 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 343 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    #line 347 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 347 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 349 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 349 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 354 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 352 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 356 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        MissionObt current_obt;
        #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        current_obt.finetime = 0U;
        #line 358 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        current_obt.seconds = 0U;

        #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 363 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_5_x_param_out_of_limit((TMHandlerT *)b_tm_handler.data,
                                            tm_count, fault_value_info, evID,
                                            current_obt, status);

        } else
        #line 365 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 366 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_5_x_param_check_value_fail((TMHandlerT *)b_tm_handler.data,
                                                tm_count, fault_value_info,
                                                evID, current_obt, status);

        } else
        {
            

        }

        #line 373 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 375 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 379 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 385 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 385 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 389 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

__status_int32_t PUSService5__exec5_5TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
    #line 59 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 60 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 62 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 62 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 62 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 64 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 64 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 65 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 69 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 67 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 71 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 72 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 74 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 75 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 78 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 80 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 81 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &status);

            #line 84 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 86 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 90 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 96 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 98 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 100 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 101 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &status, &ack_enabled);

                #line 103 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 105 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (status.__variant == Success) {
                        
                        #line 107 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 111 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 115 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 118 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] | (uint32_t)(1U << offset);

                #line 120 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 120 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 121 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 125 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 123 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 127 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 128 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 130 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &status, &ack_enabled);

                    #line 132 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 134 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (status.__variant == Success) {
                            
                            #line 136 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 140 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 145 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 150 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.__variant = Failure;
                    #line 150 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 156 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 157 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &status);

                #line 160 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 162 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 166 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 175 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.__variant = Failure;
        #line 175 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 179 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return status;

}

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
    #line 185 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 186 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 191 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 195 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 193 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 197 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 198 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 200 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 201 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 204 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 206 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 207 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                tm_count,
                                                self->exec_tc_req_status_update.packet_id,
                                                self->exec_tc_req_status_update.packet_error_ctrl,
                                                self->exec_tc_req_status_update.N,
                                                current_obt, &status);

            #line 210 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 212 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 216 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 223 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index < 4U;

            #line 225 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 227 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 228 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                             self->exec_tc_req_status_update.flags_ack,
                             current_obt, &status, &ack_enabled);

                #line 230 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 232 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (status.__variant == Success) {
                        
                        #line 234 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 238 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 242 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 245 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                            index)] & (uint32_t)(0xFFFFFFFEU << offset);

                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 248 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 252 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 250 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 254 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 255 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 256 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 257 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_7((TMHandlerT *)b_tm_handler2.data, tm_count2,
                                 self->exec_tc_req_status_update.flags_ack,
                                 current_obt, &status, &ack_enabled);

                    #line 259 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 261 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (status.__variant == Success) {
                            
                            #line 263 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 267 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 271 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.__variant = Failure;
                    #line 275 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 281 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 282 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                            tm_count,
                                            self->exec_tc_req_status_update.packet_id,
                                            self->exec_tc_req_status_update.packet_error_ctrl,
                                            self->exec_tc_req_status_update.EvID,
                                            current_obt, &status);

                #line 285 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 287 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 291 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 299 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.__variant = Failure;
        #line 299 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 303 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return status;

}

void PUSService5__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 395 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 395 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 397 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 397 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 398 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 400 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        #line 404 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 406 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 407 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_error_ctrl = tc_handler->packet_error_ctrl;

            #line 408 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 409 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 410 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            #line 411 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = tc_handler_get_u16_appdata_field(tc_handler,
                                                      &self->exec_tc_req_status_update.EvID);

            #line 413 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 415 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 419 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 419 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 420 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 427 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 429 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 5U) {
                
                #line 431 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = PUSService5__exec5_5TC(__ev, self);

            } else
            #line 433 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 6U) {
                
                #line 435 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = PUSService5__exec5_6TC(__ev, self);

            } else
            {
                
                #line 439 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 439 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 450 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (status.__variant == Success) {
        
        #line 452 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 448 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        int32_t error_code = status.Failure.__0;

        #line 457 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 459 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Success;

            #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            __option_box_t tm_handler;
            #line 461 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            tm_handler.__variant = None;

            #line 462 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 466 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (tm_handler.__variant == Some) {
                
                #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 468 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                uint16_t tm_count = 0U;

                #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                MissionObt current_obt;
                #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                current_obt.finetime = 0U;
                #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                current_obt.seconds = 0U;

                #line 471 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 472 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 474 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 476 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_error_ctrl,
                                                     current_obt, &status);

                } else
                #line 479 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 481 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_error_ctrl,
                                                         current_obt, &status);

                } else
                #line 484 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 486 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                   tm_count,
                                                   self->exec_tc_req_status_update.packet_id,
                                                   self->exec_tc_req_status_update.packet_error_ctrl,
                                                   self->exec_tc_req_status_update.tc_num_bytes,
                                                   current_obt, &status);

                } else
                {
                    

                }

                #line 496 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 498 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 502 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 508 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 508 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 514 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 514 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 521 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 523 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 523 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
    if (index < 4U) {
        
        #line 41 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((uint32_t)((uint32_t)(self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                   index)] >> offset) & 0x1U) != 0U) {
            
            #line 42 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            enabled = 1;

        }

    }

    #line 46 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return enabled;

}

void PUSService5__is_Ev_ID_enabled_ext(const __termina_event_t * const __ev,
                                       void * const __this, uint16_t Ev_ID,
                                       _Bool * const p_enabled) {
    
    #line 49 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 49 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 51 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    *p_enabled = PUSService5__is_Ev_ID_enabled(__ev, self, Ev_ID);

    #line 53 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 53 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}
