
#include "service_libraries/pus_services/pus_service6/pus_service6.h"

uint16_t PUSService6__check_data(const __termina_event_t * const __ev,
                                 PUSService6 * const self) {
    
    #line 96 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 97 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 98 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    uint8_t data[256U];
    #line 98 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 98 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        data[__i0] = 0U;
    }

    #line 99 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    for (size_t i = 0U;
         i < 256U && i < (size_t)self->exec_tc_req_status_update.length;
         i = i + 1U) {
        
        #line 100 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        data[__termina_array__index(256U,
                                    i)] = self->memory[__termina_array__index(banks_number,
                                                                              bank_index)][__termina_array__index(bank_size,
                                                                                                                  start_address + i)];

    }

    #line 103 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    uint16_t checksum = cal_crc_16(data,
                                   (size_t)self->exec_tc_req_status_update.length);

    #line 105 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return checksum;

}

_Bool PUSService6__is_address_valid(const __termina_event_t * const __ev,
                                    const PUSService6 * const self) {
    
    #line 36 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool is_valid = 1;

    #line 38 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.mem_id >= banks_number) {
        
        #line 39 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        is_valid = 0;

    } else
    #line 40 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.address >= bank_size) {
        
        #line 41 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        is_valid = 0;

    } else
    #line 42 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if ((size_t)((size_t)self->exec_tc_req_status_update.address + (size_t)self->exec_tc_req_status_update.length) > bank_size) {
        
        #line 43 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        is_valid = 0;

    } else
    #line 44 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.length > max_num_of_bytes_memory_load) {
        
        #line 45 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        is_valid = 0;

    } else
    {
        

    }

    #line 50 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return is_valid;

}

_Bool PUSService6__is_mem_id_write_enabled(const __termina_event_t * const __ev,
                                           const PUSService6 * const self) {
    
    #line 56 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool is_enabled = 1;

    #line 57 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (self->mem_id_write_permisssions[__termina_array__index(banks_number,
                                                               (size_t)self->exec_tc_req_status_update.mem_id)] == 0) {
        
        #line 58 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        is_enabled = 0;

    }

    #line 61 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return is_enabled;

}

__status_int32_t PUSService6__write_data(const __termina_event_t * const __ev,
                                         PUSService6 * const self) {
    
    #line 66 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 66 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 68 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 69 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 71 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    for (size_t i = 0U;
         i < 256U && i < (size_t)self->exec_tc_req_status_update.length;
         i = i + 1U) {
        
        #line 72 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->memory[__termina_array__index(banks_number,
                                            bank_index)][__termina_array__index(bank_size,
                                                                                start_address + i)] = self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                                                                                                                  i)];

    }

    #line 76 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_2TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 110 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool ack_enabled = 0;

    #line 111 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 111 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 113 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    MissionObt current_obt;
    #line 113 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.finetime = 0U;
    #line 113 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.seconds = 0U;

    #line 115 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __option_box_t tm_handler;
    #line 115 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    tm_handler.__variant = None;

    #line 116 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 120 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (tm_handler.__variant == Some) {
        
        #line 118 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 122 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        uint16_t tm_count = 0U;

        #line 123 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 125 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 127 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 128 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 131 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 133 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 137 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 144 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_address_valid(__ev, self) == 0) {
                
                #line 146 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 147 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.mem_id,
                                                            self->exec_tc_req_status_update.address,
                                                            current_obt);

                #line 150 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 152 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 156 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            #line 159 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_mem_id_write_enabled(__ev, self) == 0) {
                
                #line 161 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 162 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_id_read_only((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_seq_ctrl,
                                                       self->exec_tc_req_status_update.mem_id,
                                                       current_obt);

                #line 165 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 167 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 171 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 176 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 177 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 179 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (ack_enabled) {
                    
                    #line 181 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 183 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 187 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 191 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 194 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__write_data(__ev, self);

                #line 196 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __option_box_t tm_handler2;
                #line 196 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                tm_handler2.__variant = None;

                #line 197 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 201 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 199 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 203 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    uint16_t tm_count2 = 0U;

                    #line 204 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 205 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 207 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 209 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_7((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2,
                                              self->exec_tc_req_status_update.packet_id,
                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                              self->exec_tc_req_status_update.flags_ack,
                                              current_obt, &ack_enabled);

                        #line 211 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (ack_enabled) {
                            
                            #line 213 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            if (status.__variant == Success) {
                                
                                #line 215 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                self->tm_channel.send_tm(__ev,
                                                         self->tm_channel.__that,
                                                         b_tm_handler2,
                                                         &status);

                            } else
                            {
                                
                                #line 219 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler2);

                            }

                        } else
                        {
                            
                            #line 223 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 229 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_8_mem_access_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.mem_id,
                                                               current_obt);

                        #line 232 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 234 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 238 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    }

                } else
                {
                    
                    #line 245 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.__variant = Failure;
                    #line 245 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    } else
    {
        
        #line 255 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.__variant = Failure;
        #line 255 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 261 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__read_data(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 81 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 81 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 82 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 83 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 85 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    for (size_t i = 0U;
         i < 256U && i < (size_t)self->exec_tc_req_status_update.length;
         i = i + 1U) {
        
        #line 86 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                    i)] = self->memory[__termina_array__index(banks_number,
                                                                                                              bank_index)][__termina_array__index(bank_size,
                                                                                                                                                  start_address + i)];

    }

    #line 91 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_5TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 268 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool ack_enabled = 0;

    #line 269 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 269 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 271 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    MissionObt current_obt;
    #line 271 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.finetime = 0U;
    #line 271 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.seconds = 0U;

    #line 273 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __option_box_t tm_handler;
    #line 273 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    tm_handler.__variant = None;

    #line 274 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 278 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (tm_handler.__variant == Some) {
        
        #line 276 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 280 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        uint16_t tm_count = 0U;

        #line 281 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 283 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 285 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 286 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 289 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 291 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 295 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 302 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_address_valid(__ev, self) == 0) {
                
                #line 304 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 305 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.mem_id,
                                                            self->exec_tc_req_status_update.address,
                                                            current_obt);

                #line 308 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 310 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 314 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            #line 317 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_mem_id_write_enabled(__ev, self) == 0) {
                
                #line 319 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 320 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_id_read_only((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_seq_ctrl,
                                                       self->exec_tc_req_status_update.mem_id,
                                                       current_obt);

                #line 323 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 325 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 329 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 334 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 335 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 337 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (ack_enabled) {
                    
                    #line 339 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 341 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 345 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 349 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 352 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__read_data(__ev, self);

                #line 354 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __option_box_t tm_handler2;
                #line 354 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                tm_handler2.__variant = None;

                #line 355 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 359 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 357 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 361 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    uint16_t tm_count2 = 0U;

                    #line 362 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 363 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 365 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 367 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_6_6((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2, current_obt,
                                              &self->exec_tc_req_status_update);

                        #line 369 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 371 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 375 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 383 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_8_mem_access_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.mem_id,
                                                               current_obt);

                        #line 386 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 388 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 392 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    }

                } else
                {
                    
                    #line 399 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.__variant = Failure;
                    #line 399 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    } else
    {
        
        #line 409 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.__variant = Failure;
        #line 409 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 415 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_9TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 422 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool ack_enabled = 0;

    #line 423 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 423 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 425 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    MissionObt current_obt;
    #line 425 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.finetime = 0U;
    #line 425 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.seconds = 0U;

    #line 427 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __option_box_t tm_handler;
    #line 427 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    tm_handler.__variant = None;

    #line 428 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 432 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (tm_handler.__variant == Some) {
        
        #line 430 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 434 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        uint16_t tm_count = 0U;

        #line 435 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 437 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 439 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 440 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 443 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 445 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 449 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 456 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_address_valid(__ev, self) == 0) {
                
                #line 458 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 459 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.mem_id,
                                                            self->exec_tc_req_status_update.address,
                                                            current_obt);

                #line 462 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 464 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 468 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            #line 471 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_mem_id_write_enabled(__ev, self) == 0) {
                
                #line 473 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 474 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_id_read_only((TMHandlerT *)b_tm_handler.data,
                                                       tm_count,
                                                       self->exec_tc_req_status_update.packet_id,
                                                       self->exec_tc_req_status_update.packet_seq_ctrl,
                                                       self->exec_tc_req_status_update.mem_id,
                                                       current_obt);

                #line 477 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 479 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 483 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 488 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 489 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 491 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (ack_enabled) {
                    
                    #line 493 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 495 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 499 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 503 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 506 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                uint16_t checksum = 0U;

                #line 507 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                checksum = PUSService6__check_data(__ev, self);

                #line 509 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __option_box_t tm_handler2;
                #line 509 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                tm_handler2.__variant = None;

                #line 510 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 514 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 512 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 516 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    uint16_t tm_count2 = 0U;

                    #line 517 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 518 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 520 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 522 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_6_10((TMHandlerT *)b_tm_handler2.data,
                                               tm_count2, current_obt,
                                               &self->exec_tc_req_status_update,
                                               checksum);

                        #line 524 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 526 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 530 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    } else
                    {
                        
                        #line 536 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_8_mem_access_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.mem_id,
                                                               current_obt);

                        #line 539 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 541 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 545 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    }

                } else
                {
                    
                    #line 552 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.__variant = Failure;
                    #line 552 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    } else
    {
        
        #line 562 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.__variant = Failure;
        #line 562 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 568 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

void PUSService6__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 572 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    PUSService6 * self = (PUSService6 *)__this;

    #line 572 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 574 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 574 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 575 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 577 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 581 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 583 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 584 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 585 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 586 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 587 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.mem_id);

            #line 588 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 589 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.N);

            }

            #line 591 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 592 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.address);

            }

            #line 594 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 595 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.length);

            }

            #line 597 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 2U && status.__variant == Success) {
                
                #line 598 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                for (size_t j = 0U;
                     j < max_num_of_bytes_memory_load
                     && (j < (size_t)self->exec_tc_req_status_update.length
                         && status.__variant == Success);
                     j = j + 1U) {
                    
                    #line 599 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                                                                          j)]);

                }

            }

            #line 603 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 605 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 609 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.__variant = Failure;
                #line 609 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 610 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 615 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 617 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 619 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 2U) {
                
                #line 621 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__exec6_2TC(__ev, self);

            } else
            #line 623 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 5U) {
                
                #line 625 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__exec6_5TC(__ev, self);

            } else
            #line 627 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 9U) {
                
                #line 629 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__exec6_9TC(__ev, self);

            } else
            {
                
                #line 633 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.__variant = Failure;
                #line 633 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 644 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 646 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 642 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        int32_t error_code = status.Failure.__0;

        #line 651 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 653 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            (*action_status).__variant = Success;

            #line 655 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            __option_box_t tm_handler;
            #line 655 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            tm_handler.__variant = None;

            #line 656 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 660 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (tm_handler.__variant == Some) {
                
                #line 658 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 662 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                uint16_t tm_count = 0U;

                #line 663 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                MissionObt current_obt;
                #line 663 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                current_obt.finetime = 0U;
                #line 663 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                current_obt.seconds = 0U;

                #line 665 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 666 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 668 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 670 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 673 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 675 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 678 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 680 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 690 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 692 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 696 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 702 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.__variant = Failure;
                #line 702 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 708 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            (*action_status).__variant = Failure;
            #line 708 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 715 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 717 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 717 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return;

}
