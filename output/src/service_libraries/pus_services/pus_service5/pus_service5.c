
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

void PUSService5__build_and_tx_tm_5_2(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status) {
    
    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 314 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 316 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 317 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 321 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 319 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 323 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        startup_tm((TMHandlerT *)b_tm_handler.data);

        #line 324 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        *status = append_u16_appdata_field((TMHandlerT *)b_tm_handler.data,
                                           EvID_build_tm_error);

        #line 326 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 328 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 329 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            MissionObt current_obt;
            #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 330 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 331 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 332 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            close_tm((TMHandlerT *)b_tm_handler.data, 5U, 2U, tm_count,
                     current_obt);

            #line 333 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 338 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 342 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 342 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 346 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return;

}

void PUSService5__build_and_tx_tm_5_x(const __termina_event_t * const __ev,
                                      void * const __this,
                                      __status_int32_t * const status,
                                      uint16_t evID, FaultInfo fault_info) {
    
    #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 350 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 352 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 352 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 353 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 357 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 355 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 359 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 360 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        MissionObt current_obt;
        #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        current_obt.finetime = 0U;
        #line 361 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        current_obt.seconds = 0U;

        #line 362 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->pus_service_9.get_current_obt(__ev, self->pus_service_9.__that,
                                            &current_obt);

        #line 365 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 364 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 366 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            *status = build_tm_5_x_param_out_of_limit((TMHandlerT *)b_tm_handler.data,
                                                      tm_count,
                                                      fault_value_info, evID,
                                                      current_obt);

        } else
        #line 368 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 364 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 369 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            *status = build_tm_5_x_param_check_value_fail((TMHandlerT *)b_tm_handler.data,
                                                          tm_count,
                                                          fault_value_info,
                                                          evID, current_obt);

        } else
        {
            

        }

        #line 376 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 378 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 382 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 388 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).__variant = Failure;
        #line 388 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 392 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 392 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
            _Bool is_valid_EvID = index <= 4U;

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
                uint32_t mask = 0x1U << (uint8_t)(offset - 1U);

                #line 120 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index - 1U)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                                 index - 1U)] | mask;

                #line 122 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 122 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 123 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 127 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 125 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 129 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 130 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 131 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 132 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 134 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 136 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (status.__variant == Success) {
                            
                            #line 138 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 142 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 147 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 152 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.__variant = Failure;
                    #line 152 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 158 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 159 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.EvID,
                                                     current_obt);

                #line 162 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 164 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 168 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 177 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.__variant = Failure;
        #line 177 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 181 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return status;

}

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev,
                                        PUSService5 * const self) {
    
    #line 187 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    _Bool ack_enabled = 0;

    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 188 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    MissionObt current_obt;
    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.finetime = 0U;
    #line 190 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    current_obt.seconds = 0U;

    #line 192 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __option_box_t tm_handler;
    #line 192 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    tm_handler.__variant = None;

    #line 193 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 197 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 195 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 199 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 200 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 202 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

        #line 203 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

        #line 206 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 208 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 209 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 212 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 214 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 218 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 225 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            _Bool is_valid_EvID = index <= 4U;

            #line 227 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (is_valid_EvID) {
                
                #line 229 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 230 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 232 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (ack_enabled) {
                    
                    #line 234 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (status.__variant == Success) {
                        
                        #line 236 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 240 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 244 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 247 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                uint32_t mask = 0x1U << (uint8_t)(offset - 1U);

                #line 248 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                 index - 1U)] = self->Ev_ID_enable_config[__termina_array__index(4U,
                                                                                                                                 index - 1U)] & (uint32_t)(0xFFFFFFFEU ^ mask);

                #line 250 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __option_box_t tm_handler2;
                #line 250 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                tm_handler2.__variant = None;

                #line 251 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 255 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 253 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 257 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    uint16_t tm_count2 = 0U;

                    #line 258 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 259 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 260 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                          tm_count2,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          current_obt, &ack_enabled);

                    #line 262 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    if (ack_enabled) {
                        
                        #line 264 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        if (status.__variant == Success) {
                            
                            #line 266 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 270 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 274 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler2);

                    }

                } else
                {
                    
                    #line 278 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.__variant = Failure;
                    #line 278 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            } else
            {
                
                #line 284 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 285 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = build_tm_1_4_EvID_not_valid((TMHandlerT *)b_tm_handler.data,
                                                     tm_count,
                                                     self->exec_tc_req_status_update.packet_id,
                                                     self->exec_tc_req_status_update.packet_seq_ctrl,
                                                     self->exec_tc_req_status_update.EvID,
                                                     current_obt);

                #line 288 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 290 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 294 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            }

        }

    } else
    {
        
        #line 302 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.__variant = Failure;
        #line 302 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 306 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    return status;

}

void PUSService5__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 398 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 398 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 400 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __status_int32_t status;
    #line 400 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    status.__variant = Success;

    #line 401 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 403 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 407 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 409 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 410 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 411 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 412 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 413 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.N);

            #line 414 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 415 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.EvID);

            }

            #line 418 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (status.__variant == Success) {
                
                #line 420 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 424 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 424 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 425 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 430 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 432 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 434 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 5U) {
                
                #line 436 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = PUSService5__exec5_5TC(__ev, self);

            } else
            #line 438 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (subtype == 6U) {
                
                #line 440 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status = PUSService5__exec5_6TC(__ev, self);

            } else
            {
                
                #line 444 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 444 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 455 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    if (status.__variant == Success) {
        
        #line 457 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 453 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        int32_t error_code = status.Failure.__0;

        #line 462 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 464 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Success;

            #line 466 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            __option_box_t tm_handler;
            #line 466 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            tm_handler.__variant = None;

            #line 467 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 471 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            if (tm_handler.__variant == Some) {
                
                #line 469 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 473 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                uint16_t tm_count = 0U;

                #line 474 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                MissionObt current_obt;
                #line 474 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                current_obt.finetime = 0U;
                #line 474 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                current_obt.seconds = 0U;

                #line 476 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 477 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 479 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 481 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 484 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 486 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 489 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 491 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 501 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                if (status.__variant == Success) {
                    
                    #line 503 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 507 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 513 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.__variant = Failure;
                #line 513 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 519 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 519 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 526 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 528 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 528 "src/service_libraries/pus_services/pus_service5/pus_service5.fin"
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
                                                                                   config_array_index)] >> (uint8_t)(offset - 1U)) & 0x1U) != 0U) {
            
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
