
#include "service_libraries/pus_services/pus_service6.h"

__option_uint16_t PUSService6__check_data(const __termina_event_t * const __ev,
                                          PUSService6 * const self) {
    
    #line 90 "src/service_libraries/pus_services/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 91 "src/service_libraries/pus_services/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 92 "src/service_libraries/pus_services/pus_service6.fin"
    uint8_t data[256U];
    #line 92 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 92 "src/service_libraries/pus_services/pus_service6.fin"
        data[__i0] = 0U;
    }

    #line 93 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t i = 0U;
         i < 256U && i < (size_t)self->exec_tc_req_status_update.length;
         i = i + 1U) {
        
        #line 94 "src/service_libraries/pus_services/pus_service6.fin"
        data[__termina_array__index(256U,
                                    i)] = self->memory[__termina_array__index(banks_number,
                                                                              bank_index)][__termina_array__index(bank_size,
                                                                                                                  start_address + i)];

    }

    #line 97 "src/service_libraries/pus_services/pus_service6.fin"
    __option_uint16_t checksum;
    #line 98 "src/service_libraries/pus_services/pus_service6.fin"
    checksum.__variant = Some;
    #line 97 "src/service_libraries/pus_services/pus_service6.fin"
    checksum.Some.__0 = cal_crc_16(data,
                                   (size_t)self->exec_tc_req_status_update.length);

    #line 100 "src/service_libraries/pus_services/pus_service6.fin"
    return checksum;

}

_Bool PUSService6__is_address_valid(const __termina_event_t * const __ev,
                                    const PUSService6 * const self) {
    
    #line 33 "src/service_libraries/pus_services/pus_service6.fin"
    _Bool is_valid = 1;

    #line 35 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.mem_id >= banks_number) {
        
        #line 36 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = 0;

    } else
    #line 37 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.address >= bank_size) {
        
        #line 38 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = 0;

    } else
    #line 39 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)((size_t)self->exec_tc_req_status_update.address + (size_t)self->exec_tc_req_status_update.length) > bank_size) {
        
        #line 40 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = 0;

    } else
    #line 41 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.length > max_num_of_bytes_memory_load) {
        
        #line 42 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = 0;

    } else
    {
        

    }

    #line 47 "src/service_libraries/pus_services/pus_service6.fin"
    return is_valid;

}

_Bool PUSService6__is_mem_id_write_enabled(const __termina_event_t * const __ev,
                                           const PUSService6 * const self) {
    
    #line 53 "src/service_libraries/pus_services/pus_service6.fin"
    _Bool is_enabled = 1;

    #line 54 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->mem_id_write_permisssions[__termina_array__index(banks_number,
                                                               (size_t)self->exec_tc_req_status_update.mem_id)] == 0) {
        
        #line 55 "src/service_libraries/pus_services/pus_service6.fin"
        is_enabled = 0;

    }

    #line 58 "src/service_libraries/pus_services/pus_service6.fin"
    return is_enabled;

}

__status_int32_t PUSService6__write_data(const __termina_event_t * const __ev,
                                         PUSService6 * const self) {
    
    #line 63 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status;
    #line 63 "src/service_libraries/pus_services/pus_service6.fin"
    status.__variant = Success;

    #line 65 "src/service_libraries/pus_services/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 66 "src/service_libraries/pus_services/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 68 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t i = 0U;
         i < 256U && i < (size_t)self->exec_tc_req_status_update.length;
         i = i + 1U) {
        
        #line 69 "src/service_libraries/pus_services/pus_service6.fin"
        self->memory[__termina_array__index(banks_number,
                                            bank_index)][__termina_array__index(bank_size,
                                                                                start_address + i)] = self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                                                                                                                  i)];

    }

    #line 72 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_2TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 105 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status;
    #line 105 "src/service_libraries/pus_services/pus_service6.fin"
    status.__variant = Success;

    #line 107 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 109 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 115 "src/service_libraries/pus_services/pus_service6.fin"
    if (PUSService6__is_address_valid(__ev, self) == 0) {
        
        #line 117 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_address_not_valid(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.mem_id,
                                                              self->exec_tc_req_status_update.address,
                                                              &status);

    } else
    #line 124 "src/service_libraries/pus_services/pus_service6.fin"
    if (PUSService6__is_mem_id_write_enabled(__ev, self) == 0) {
        
        #line 126 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_id_read_only(__ev,
                                                         self->pus_service_1.__that,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.mem_id,
                                                         &status);

    } else
    {
        
        #line 134 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 140 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 141 "src/service_libraries/pus_services/pus_service6.fin"
            status = PUSService6__write_data(__ev, self);

        }

        #line 144 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 146 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              &status);

        } else
        {
            
            #line 154 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_mem_access_error(__ev,
                                                             self->pus_service_1.__that,
                                                             self->exec_tc_req_status_update.packet_id,
                                                             self->exec_tc_req_status_update.packet_seq_ctrl,
                                                             self->exec_tc_req_status_update.mem_id,
                                                             &status);

        }

    }

    #line 164 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__read_data(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 77 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status;
    #line 77 "src/service_libraries/pus_services/pus_service6.fin"
    status.__variant = Success;

    #line 78 "src/service_libraries/pus_services/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 79 "src/service_libraries/pus_services/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 81 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t i = 0U;
         i < 256U && i < (size_t)self->exec_tc_req_status_update.length;
         i = i + 1U) {
        
        #line 82 "src/service_libraries/pus_services/pus_service6.fin"
        self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                    i)] = self->memory[__termina_array__index(banks_number,
                                                                                                              bank_index)][__termina_array__index(bank_size,
                                                                                                                                                  start_address + i)];

    }

    #line 85 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_5TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 170 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status;
    #line 170 "src/service_libraries/pus_services/pus_service6.fin"
    status.__variant = Success;

    #line 172 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 174 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 180 "src/service_libraries/pus_services/pus_service6.fin"
    if (PUSService6__is_address_valid(__ev, self) == 0) {
        
        #line 182 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_address_not_valid(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.mem_id,
                                                              self->exec_tc_req_status_update.address,
                                                              &status);

    } else
    {
        
        #line 191 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 197 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 199 "src/service_libraries/pus_services/pus_service6.fin"
            status = PUSService6__read_data(__ev, self);

        }

        #line 203 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 205 "src/service_libraries/pus_services/pus_service6.fin"
            __option_box_t tm_handler;
            #line 205 "src/service_libraries/pus_services/pus_service6.fin"
            tm_handler.__variant = None;

            #line 206 "src/service_libraries/pus_services/pus_service6.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 210 "src/service_libraries/pus_services/pus_service6.fin"
            if (tm_handler.__variant == Some) {
                
                #line 208 "src/service_libraries/pus_services/pus_service6.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 212 "src/service_libraries/pus_services/pus_service6.fin"
                MissionOBT current_obt;
                #line 212 "src/service_libraries/pus_services/pus_service6.fin"
                current_obt.finetime = 0U;
                #line 212 "src/service_libraries/pus_services/pus_service6.fin"
                current_obt.seconds = 0U;

                #line 213 "src/service_libraries/pus_services/pus_service6.fin"
                uint16_t tm_count = 0U;

                #line 215 "src/service_libraries/pus_services/pus_service6.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 216 "src/service_libraries/pus_services/pus_service6.fin"
                self->obt_manager.get_current_obt(__ev,
                                                  self->obt_manager.__that,
                                                  &current_obt);

                #line 218 "src/service_libraries/pus_services/pus_service6.fin"
                status = build_tm_6_6((TMHandler *)b_tm_handler.data, tm_count,
                                      current_obt,
                                      &self->exec_tc_req_status_update);

                #line 220 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 221 "src/service_libraries/pus_services/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 223 "src/service_libraries/pus_services/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 226 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 228 "src/service_libraries/pus_services/pus_service6.fin"
                    self->pus_service_1.notify_tm_1_7(__ev,
                                                      self->pus_service_1.__that,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.flags_ack,
                                                      &status);

                }

            } else
            {
                
                #line 239 "src/service_libraries/pus_services/pus_service6.fin"
                status.__variant = Failure;
                #line 239 "src/service_libraries/pus_services/pus_service6.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 245 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_mem_access_error(__ev,
                                                             self->pus_service_1.__that,
                                                             self->exec_tc_req_status_update.packet_id,
                                                             self->exec_tc_req_status_update.packet_seq_ctrl,
                                                             self->exec_tc_req_status_update.mem_id,
                                                             &status);

        }

    }

    #line 255 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_9TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 261 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status;
    #line 261 "src/service_libraries/pus_services/pus_service6.fin"
    status.__variant = Success;

    #line 263 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 265 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 271 "src/service_libraries/pus_services/pus_service6.fin"
    if (PUSService6__is_address_valid(__ev, self) == 0) {
        
        #line 273 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_address_not_valid(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.mem_id,
                                                              self->exec_tc_req_status_update.address,
                                                              &status);

    } else
    {
        
        #line 282 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 287 "src/service_libraries/pus_services/pus_service6.fin"
        __option_uint16_t option_checksum;
        #line 287 "src/service_libraries/pus_services/pus_service6.fin"
        option_checksum.__variant = None;

        #line 288 "src/service_libraries/pus_services/pus_service6.fin"
        option_checksum = PUSService6__check_data(__ev, self);

        #line 292 "src/service_libraries/pus_services/pus_service6.fin"
        if (option_checksum.__variant == Some) {
            
            #line 290 "src/service_libraries/pus_services/pus_service6.fin"
            uint16_t checksum = option_checksum.Some.__0;

            #line 294 "src/service_libraries/pus_services/pus_service6.fin"
            __option_box_t tm_handler;
            #line 294 "src/service_libraries/pus_services/pus_service6.fin"
            tm_handler.__variant = None;

            #line 295 "src/service_libraries/pus_services/pus_service6.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 299 "src/service_libraries/pus_services/pus_service6.fin"
            if (tm_handler.__variant == Some) {
                
                #line 297 "src/service_libraries/pus_services/pus_service6.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 301 "src/service_libraries/pus_services/pus_service6.fin"
                MissionOBT current_obt;
                #line 301 "src/service_libraries/pus_services/pus_service6.fin"
                current_obt.finetime = 0U;
                #line 301 "src/service_libraries/pus_services/pus_service6.fin"
                current_obt.seconds = 0U;

                #line 302 "src/service_libraries/pus_services/pus_service6.fin"
                uint16_t tm_count = 0U;

                #line 303 "src/service_libraries/pus_services/pus_service6.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 304 "src/service_libraries/pus_services/pus_service6.fin"
                self->obt_manager.get_current_obt(__ev,
                                                  self->obt_manager.__that,
                                                  &current_obt);

                #line 306 "src/service_libraries/pus_services/pus_service6.fin"
                status = build_tm_6_10((TMHandler *)b_tm_handler.data, tm_count,
                                       current_obt,
                                       &self->exec_tc_req_status_update,
                                       checksum);

                #line 308 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 309 "src/service_libraries/pus_services/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 311 "src/service_libraries/pus_services/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 314 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 316 "src/service_libraries/pus_services/pus_service6.fin"
                    self->pus_service_1.notify_tm_1_7(__ev,
                                                      self->pus_service_1.__that,
                                                      self->exec_tc_req_status_update.packet_id,
                                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                                      self->exec_tc_req_status_update.flags_ack,
                                                      &status);

                }

            } else
            {
                
                #line 327 "src/service_libraries/pus_services/pus_service6.fin"
                status.__variant = Failure;
                #line 327 "src/service_libraries/pus_services/pus_service6.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 333 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_mem_access_error(__ev,
                                                             self->pus_service_1.__that,
                                                             self->exec_tc_req_status_update.packet_id,
                                                             self->exec_tc_req_status_update.packet_seq_ctrl,
                                                             self->exec_tc_req_status_update.mem_id,
                                                             &status);

        }

    }

    #line 345 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

void PUSService6__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandler * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 349 "src/service_libraries/pus_services/pus_service6.fin"
    PUSService6 * self = (PUSService6 *)__this;

    #line 349 "src/service_libraries/pus_services/pus_service6.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 351 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status;
    #line 351 "src/service_libraries/pus_services/pus_service6.fin"
    status.__variant = Success;

    #line 352 "src/service_libraries/pus_services/pus_service6.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 354 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 355 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 356 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 357 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 359 "src/service_libraries/pus_services/pus_service6.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler,
                                             &self->exec_tc_req_status_update.mem_id);

    #line 361 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 362 "src/service_libraries/pus_services/pus_service6.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler,
                                                 &self->exec_tc_req_status_update.N);

    }

    #line 365 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 366 "src/service_libraries/pus_services/pus_service6.fin"
        status = tc_handler_get_u32_appdata_field(tc_handler,
                                                  &self->exec_tc_req_status_update.address);

    }

    #line 369 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 370 "src/service_libraries/pus_services/pus_service6.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler,
                                                  &self->exec_tc_req_status_update.length);

    }

    #line 373 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success && subtype == 2U) {
        
        #line 374 "src/service_libraries/pus_services/pus_service6.fin"
        for (size_t j = 0U;
             j < max_num_of_bytes_memory_load
             && (j < (size_t)self->exec_tc_req_status_update.length
                 && status.__variant == Success);
             j = j + 1U) {
            
            #line 375 "src/service_libraries/pus_services/pus_service6.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                                                                  j)]);

        }

    }

    #line 379 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 381 "src/service_libraries/pus_services/pus_service6.fin"
        if (subtype == 2U) {
            
            #line 383 "src/service_libraries/pus_services/pus_service6.fin"
            status = PUSService6__exec6_2TC(__ev, self);

        } else
        #line 385 "src/service_libraries/pus_services/pus_service6.fin"
        if (subtype == 5U) {
            
            #line 387 "src/service_libraries/pus_services/pus_service6.fin"
            status = PUSService6__exec6_5TC(__ev, self);

        } else
        #line 389 "src/service_libraries/pus_services/pus_service6.fin"
        if (subtype == 9U) {
            
            #line 391 "src/service_libraries/pus_services/pus_service6.fin"
            status = PUSService6__exec6_9TC(__ev, self);

        } else
        {
            
            #line 395 "src/service_libraries/pus_services/pus_service6.fin"
            status.__variant = Failure;
            #line 395 "src/service_libraries/pus_services/pus_service6.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 402 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 404 "src/service_libraries/pus_services/pus_service6.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 400 "src/service_libraries/pus_services/pus_service6.fin"
        int32_t error_code = status.Failure.__0;

        #line 409 "src/service_libraries/pus_services/pus_service6.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 411 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                action_status);

        } else
        #line 416 "src/service_libraries/pus_services/pus_service6.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 418 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    action_status);

        } else
        #line 423 "src/service_libraries/pus_services/pus_service6.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 425 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_num_bytes,
                                                              action_status);

        } else
        {
            
            #line 433 "src/service_libraries/pus_services/pus_service6.fin"
            (*action_status).__variant = Failure;
            #line 433 "src/service_libraries/pus_services/pus_service6.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 440 "src/service_libraries/pus_services/pus_service6.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 440 "src/service_libraries/pus_services/pus_service6.fin"
    return;

}
