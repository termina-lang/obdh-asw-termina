
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
                        
                        #line 231 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_8_mem_access_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.mem_id,
                                                               current_obt);

                        #line 234 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 236 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 240 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    }

                } else
                {
                    
                    #line 247 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.__variant = Failure;
                    #line 247 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    } else
    {
        
        #line 257 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.__variant = Failure;
        #line 257 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 263 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
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
    
    #line 270 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool ack_enabled = 0;

    #line 271 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 271 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 273 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    MissionObt current_obt;
    #line 273 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.finetime = 0U;
    #line 273 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.seconds = 0U;

    #line 275 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __option_box_t tm_handler;
    #line 275 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    tm_handler.__variant = None;

    #line 276 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 280 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (tm_handler.__variant == Some) {
        
        #line 278 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 282 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        uint16_t tm_count = 0U;

        #line 283 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 285 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 287 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 288 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 291 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 293 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 297 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 304 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_address_valid(__ev, self) == 0) {
                
                #line 306 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 307 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.mem_id,
                                                            self->exec_tc_req_status_update.address,
                                                            current_obt);

                #line 310 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 312 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 316 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 321 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 322 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 324 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (ack_enabled) {
                    
                    #line 326 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 328 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 332 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 336 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 339 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__read_data(__ev, self);

                #line 341 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __option_box_t tm_handler2;
                #line 341 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                tm_handler2.__variant = None;

                #line 342 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 346 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 344 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 348 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    uint16_t tm_count2 = 0U;

                    #line 349 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 350 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 352 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 354 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_6_6((TMHandlerT *)b_tm_handler2.data,
                                              tm_count2, current_obt,
                                              &self->exec_tc_req_status_update);

                        #line 356 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 358 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 362 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                        #line 365 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        __option_box_t tm_handler3;
                        #line 365 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        tm_handler3.__variant = None;

                        #line 366 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler3);

                        #line 370 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (tm_handler3.__variant == Some) {
                            
                            #line 368 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                            #line 372 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            uint16_t tm_count3 = 0U;

                            #line 373 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count3);

                            #line 374 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 375 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler3.data,
                                                  tm_count3,
                                                  self->exec_tc_req_status_update.packet_id,
                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 377 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            if (ack_enabled) {
                                
                                #line 379 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 381 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler3,
                                                             &status);

                                } else
                                {
                                    
                                    #line 385 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler3);

                                }

                            } else
                            {
                                
                                #line 391 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler3);

                            }

                        } else
                        {
                            
                            #line 396 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            status.__variant = Failure;
                            #line 396 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 403 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_8_mem_access_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.mem_id,
                                                               current_obt);

                        #line 406 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 408 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 412 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    }

                } else
                {
                    
                    #line 419 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.__variant = Failure;
                    #line 419 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    } else
    {
        
        #line 429 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.__variant = Failure;
        #line 429 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 435 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

__status_int32_t PUSService6__exec6_9TC(const __termina_event_t * const __ev,
                                        PUSService6 * const self) {
    
    #line 442 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    _Bool ack_enabled = 0;

    #line 443 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 443 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 445 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    MissionObt current_obt;
    #line 445 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.finetime = 0U;
    #line 445 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    current_obt.seconds = 0U;

    #line 447 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __option_box_t tm_handler;
    #line 447 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    tm_handler.__variant = None;

    #line 448 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                  &tm_handler);

    #line 452 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (tm_handler.__variant == Some) {
        
        #line 450 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 454 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        uint16_t tm_count = 0U;

        #line 455 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 457 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status_update.N != 1U) {
            
            #line 459 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            #line 460 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = build_tm_1_4_num_of_instr_not_valid((TMHandlerT *)b_tm_handler.data,
                                                         tm_count,
                                                         self->exec_tc_req_status_update.packet_id,
                                                         self->exec_tc_req_status_update.packet_seq_ctrl,
                                                         self->exec_tc_req_status_update.N,
                                                         current_obt);

            #line 463 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 465 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else
            {
                
                #line 469 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else
        {
            
            #line 476 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (PUSService6__is_address_valid(__ev, self) == 0) {
                
                #line 478 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 479 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_4_mem_address_not_valid((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.mem_id,
                                                            self->exec_tc_req_status_update.address,
                                                            current_obt);

                #line 482 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 484 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 488 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 493 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 494 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = build_tm_1_3((TMHandlerT *)b_tm_handler.data, tm_count,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      current_obt, &ack_enabled);

                #line 496 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (ack_enabled) {
                    
                    #line 498 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 500 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                                 b_tm_handler, &status);

                    } else
                    {
                        
                        #line 504 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.free(__ev,
                                                     self->a_tm_handler_pool.__that,
                                                     b_tm_handler);

                    }

                } else
                {
                    
                    #line 508 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

                #line 511 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                uint16_t checksum = 0U;

                #line 512 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                checksum = PUSService6__check_data(__ev, self);

                #line 514 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __option_box_t tm_handler2;
                #line 514 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                tm_handler2.__variant = None;

                #line 515 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->a_tm_handler_pool.alloc(__ev,
                                              self->a_tm_handler_pool.__that,
                                              &tm_handler2);

                #line 519 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (tm_handler2.__variant == Some) {
                    
                    #line 517 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    __termina_box_t b_tm_handler2 = tm_handler2.Some.__0;

                    #line 521 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    uint16_t tm_count2 = 0U;

                    #line 522 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_counter.get_next_tm_count(__ev,
                                                       self->tm_counter.__that,
                                                       &tm_count2);

                    #line 523 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->pus_service_9.get_current_obt(__ev,
                                                        self->pus_service_9.__that,
                                                        &current_obt);

                    #line 525 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    if (status.__variant == Success) {
                        
                        #line 527 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_6_10((TMHandlerT *)b_tm_handler2.data,
                                               tm_count2, current_obt,
                                               &self->exec_tc_req_status_update,
                                               checksum);

                        #line 529 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 531 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 535 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                        #line 538 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        __option_box_t tm_handler3;
                        #line 538 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        tm_handler3.__variant = None;

                        #line 539 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        self->a_tm_handler_pool.alloc(__ev,
                                                      self->a_tm_handler_pool.__that,
                                                      &tm_handler3);

                        #line 543 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (tm_handler3.__variant == Some) {
                            
                            #line 541 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            __termina_box_t b_tm_handler3 = tm_handler3.Some.__0;

                            #line 545 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            uint16_t tm_count3 = 0U;

                            #line 546 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_counter.get_next_tm_count(__ev,
                                                               self->tm_counter.__that,
                                                               &tm_count3);

                            #line 547 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->pus_service_9.get_current_obt(__ev,
                                                                self->pus_service_9.__that,
                                                                &current_obt);

                            #line 548 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            status = build_tm_1_7((TMHandlerT *)b_tm_handler3.data,
                                                  tm_count3,
                                                  self->exec_tc_req_status_update.packet_id,
                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.flags_ack,
                                                  current_obt, &ack_enabled);

                            #line 550 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            if (ack_enabled) {
                                
                                #line 552 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                if (status.__variant == Success) {
                                    
                                    #line 554 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                    self->tm_channel.send_tm(__ev,
                                                             self->tm_channel.__that,
                                                             b_tm_handler3,
                                                             &status);

                                } else
                                {
                                    
                                    #line 558 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                    self->a_tm_handler_pool.free(__ev,
                                                                 self->a_tm_handler_pool.__that,
                                                                 b_tm_handler3);

                                }

                            } else
                            {
                                
                                #line 564 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                                self->a_tm_handler_pool.free(__ev,
                                                             self->a_tm_handler_pool.__that,
                                                             b_tm_handler3);

                            }

                        } else
                        {
                            
                            #line 569 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            status.__variant = Failure;
                            #line 569 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                        }

                    } else
                    {
                        
                        #line 577 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        status = build_tm_1_8_mem_access_error((TMHandlerT *)b_tm_handler2.data,
                                                               tm_count2,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.mem_id,
                                                               current_obt);

                        #line 580 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                        if (status.__variant == Success) {
                            
                            #line 582 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->tm_channel.send_tm(__ev,
                                                     self->tm_channel.__that,
                                                     b_tm_handler2, &status);

                        } else
                        {
                            
                            #line 586 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                            self->a_tm_handler_pool.free(__ev,
                                                         self->a_tm_handler_pool.__that,
                                                         b_tm_handler2);

                        }

                    }

                } else
                {
                    
                    #line 593 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.__variant = Failure;
                    #line 593 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

                }

            }

        }

    } else
    {
        
        #line 603 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.__variant = Failure;
        #line 603 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 609 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return status;

}

void PUSService6__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandlerT * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 613 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    PUSService6 * self = (PUSService6 *)__this;

    #line 613 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 615 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __status_int32_t status;
    #line 615 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    status.__variant = Success;

    #line 616 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 618 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    for (size_t i = 0U;
         i < 3U
         && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0;
         i = i + 1U) {
        
        #line 622 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            
            #line 624 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

            #line 625 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

            #line 626 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

            #line 627 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

            #line 628 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler,
                                                     &self->exec_tc_req_status_update.mem_id);

            #line 629 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 630 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = tc_handler_get_u8_appdata_field(tc_handler,
                                                         &self->exec_tc_req_status_update.N);

            }

            #line 632 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 633 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = tc_handler_get_u32_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.address);

            }

            #line 635 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 636 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = tc_handler_get_u16_appdata_field(tc_handler,
                                                          &self->exec_tc_req_status_update.length);

            }

            #line 638 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 2U && status.__variant == Success) {
                
                #line 639 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                for (size_t j = 0U;
                     j < max_num_of_bytes_memory_load
                     && (j < (size_t)self->exec_tc_req_status_update.length
                         && status.__variant == Success);
                     j = j + 1U) {
                    
                    #line 640 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = tc_handler_get_u8_appdata_field(tc_handler,
                                                             &self->exec_tc_req_status_update.data[__termina_array__index(max_num_of_bytes_memory_load,
                                                                                                                          j)]);

                }

            }

            #line 644 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (status.__variant == Success) {
                
                #line 646 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

            } else
            {
                
                #line 650 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.__variant = Failure;
                #line 650 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

                #line 651 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            }

        } else
        #line 656 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            #line 658 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            #line 660 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 2U) {
                
                #line 662 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__exec6_2TC(__ev, self);

            } else
            #line 664 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 5U) {
                
                #line 666 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__exec6_5TC(__ev, self);

            } else
            #line 668 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (subtype == 9U) {
                
                #line 670 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status = PUSService6__exec6_9TC(__ev, self);

            } else
            {
                
                #line 674 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.__variant = Failure;
                #line 674 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.Failure.__0 = ACCEPTANCE_ERROR;

            }

        } else
        {
            

        }

    }

    #line 685 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 687 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 683 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        int32_t error_code = status.Failure.__0;

        #line 692 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
        if (error_code == ACCEPTANCE_ERROR || error_code == BUILD_TM_ERROR
            || error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 694 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            (*action_status).__variant = Success;

            #line 696 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            __option_box_t tm_handler;
            #line 696 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            tm_handler.__variant = None;

            #line 697 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                          &tm_handler);

            #line 701 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            if (tm_handler.__variant == Some) {
                
                #line 699 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 703 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                uint16_t tm_count = 0U;

                #line 704 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                MissionObt current_obt;
                #line 704 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                current_obt.finetime = 0U;
                #line 704 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                current_obt.seconds = 0U;

                #line 706 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->tm_counter.get_next_tm_count(__ev,
                                                   self->tm_counter.__that,
                                                   &tm_count);

                #line 707 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                self->pus_service_9.get_current_obt(__ev,
                                                    self->pus_service_9.__that,
                                                    &current_obt);

                #line 709 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (error_code == ACCEPTANCE_ERROR) {
                    
                    #line 711 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                                              tm_count,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              current_obt);

                } else
                #line 714 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (error_code == BUILD_TM_ERROR) {
                    
                    #line 716 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = build_tm_1_8_tm_exceed_limit_appdata((TMHandlerT *)b_tm_handler.data,
                                                                  tm_count,
                                                                  self->exec_tc_req_status_update.packet_id,
                                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                  current_obt);

                } else
                #line 719 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
                    
                    #line 721 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    status = build_tm_1_4_short_pack_length((TMHandlerT *)b_tm_handler.data,
                                                            tm_count,
                                                            self->exec_tc_req_status_update.packet_id,
                                                            self->exec_tc_req_status_update.packet_seq_ctrl,
                                                            self->exec_tc_req_status_update.tc_num_bytes,
                                                            current_obt);

                } else
                {
                    

                }

                #line 731 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 733 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                             b_tm_handler, &status);

                } else
                {
                    
                    #line 737 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                    self->a_tm_handler_pool.free(__ev,
                                                 self->a_tm_handler_pool.__that,
                                                 b_tm_handler);

                }

            } else
            {
                
                #line 743 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.__variant = Failure;
                #line 743 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 749 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            (*action_status).__variant = Failure;
            #line 749 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 756 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    #line 758 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 758 "src/service_libraries/pus_services/pus_service6/pus_service6.fin"
    return;

}
