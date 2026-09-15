
#include "service_libraries/pus_services/pus_service6.h"

static __option_uint16_t CPUSService6__check_data(const __termina_event_t * const __ev, CPUSService6 * const self);

static _Bool CPUSService6__is_address_valid(const __termina_event_t * const __ev, const CPUSService6 * const self);

static _Bool CPUSService6__is_mem_id_write_enabled(const __termina_event_t * const __ev, const CPUSService6 * const self);

static __status_int32_t CPUSService6__write_data(const __termina_event_t * const __ev, CPUSService6 * const self);

static __status_int32_t CPUSService6__exec6_2TC(const __termina_event_t * const __ev, CPUSService6 * const self);

static __status_int32_t CPUSService6__read_data(const __termina_event_t * const __ev, CPUSService6 * const self);

static __status_int32_t CPUSService6__exec6_5TC(const __termina_event_t * const __ev, CPUSService6 * const self);

static __status_int32_t CPUSService6__exec6_9TC(const __termina_event_t * const __ev, CPUSService6 * const self);

static __option_uint16_t CPUSService6__check_data(const __termina_event_t * const __ev, CPUSService6 * const self) {
    
    (void)__ev;

    #line 86 "src/service_libraries/pus_services/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 87 "src/service_libraries/pus_services/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 88 "src/service_libraries/pus_services/pus_service6.fin"
    uint8_t data[256U] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U };

    #line 89 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t i = 0U; i < 256U && i < (size_t)self->exec_tc_req_status_update.length; i = i + 1U) {
        
        #line 90 "src/service_libraries/pus_services/pus_service6.fin"
        data[__termina_array__index(256U, i)] = self->memory[__termina_array__index(8U, bank_index)][__termina_array__index(16777216U, start_address + i)];

    }

    #line 93 "src/service_libraries/pus_services/pus_service6.fin"
    __option_uint16_t checksum = { .__variant = Some, .Some = { .__0 = cal_crc_16(data, (size_t)self->exec_tc_req_status_update.length) } };

    #line 96 "src/service_libraries/pus_services/pus_service6.fin"
    return checksum;

}

static _Bool CPUSService6__is_address_valid(const __termina_event_t * const __ev, const CPUSService6 * const self) {
    
    (void)__ev;

    #line 33 "src/service_libraries/pus_services/pus_service6.fin"
    _Bool is_valid = true;

    #line 35 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.mem_id >= banks_number) {
        
        #line 36 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = false;

    } else
    #line 37 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.address >= bank_size) {
        
        #line 38 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = false;

    } else
    #line 39 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)((size_t)self->exec_tc_req_status_update.address + (size_t)self->exec_tc_req_status_update.length) > bank_size) {
        
        #line 40 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = false;

    } else
    #line 41 "src/service_libraries/pus_services/pus_service6.fin"
    if ((size_t)self->exec_tc_req_status_update.length > max_num_of_bytes_memory_load) {
        
        #line 42 "src/service_libraries/pus_services/pus_service6.fin"
        is_valid = false;

    } else
    {
        

    }

    #line 47 "src/service_libraries/pus_services/pus_service6.fin"
    return is_valid;

}

static _Bool CPUSService6__is_mem_id_write_enabled(const __termina_event_t * const __ev, const CPUSService6 * const self) {
    
    (void)__ev;

    #line 53 "src/service_libraries/pus_services/pus_service6.fin"
    return self->mem_id_write_permissions[__termina_array__index(8U, (size_t)self->exec_tc_req_status_update.mem_id)] == true;

}

static __status_int32_t CPUSService6__write_data(const __termina_event_t * const __ev, CPUSService6 * const self) {
    
    (void)__ev;

    #line 59 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status = { .__variant = Success };

    #line 61 "src/service_libraries/pus_services/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 62 "src/service_libraries/pus_services/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 64 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t i = 0U; i < 256U && i < (size_t)self->exec_tc_req_status_update.length; i = i + 1U) {
        
        #line 65 "src/service_libraries/pus_services/pus_service6.fin"
        self->memory[__termina_array__index(8U, bank_index)][__termina_array__index(16777216U, start_address + i)] = self->exec_tc_req_status_update.data[__termina_array__index(256U, i)];

    }

    #line 68 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

static __status_int32_t CPUSService6__exec6_2TC(const __termina_event_t * const __ev, CPUSService6 * const self) {
    
    #line 101 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status = { .__variant = Success };

    #line 103 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 105 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 111 "src/service_libraries/pus_services/pus_service6.fin"
    if (CPUSService6__is_address_valid(__ev, self) == false) {
        
        #line 113 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_address_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, self->exec_tc_req_status_update.address, &status);

    } else
    #line 120 "src/service_libraries/pus_services/pus_service6.fin"
    if (CPUSService6__is_mem_id_write_enabled(__ev, self) == false) {
        
        #line 122 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_id_read_only(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, &status);

    } else
    {
        
        #line 130 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 136 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 137 "src/service_libraries/pus_services/pus_service6.fin"
            status = CPUSService6__write_data(__ev, self);

        }

        #line 140 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 142 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        } else
        {
            
            #line 150 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_mem_access_error(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, &status);

        }

    }

    #line 160 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

static __status_int32_t CPUSService6__read_data(const __termina_event_t * const __ev, CPUSService6 * const self) {
    
    (void)__ev;

    #line 73 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status = { .__variant = Success };

    #line 74 "src/service_libraries/pus_services/pus_service6.fin"
    size_t bank_index = (size_t)self->exec_tc_req_status_update.mem_id;

    #line 75 "src/service_libraries/pus_services/pus_service6.fin"
    size_t start_address = (size_t)self->exec_tc_req_status_update.address;

    #line 77 "src/service_libraries/pus_services/pus_service6.fin"
    for (size_t i = 0U; i < 256U && i < (size_t)self->exec_tc_req_status_update.length; i = i + 1U) {
        
        #line 78 "src/service_libraries/pus_services/pus_service6.fin"
        self->exec_tc_req_status_update.data[__termina_array__index(256U, i)] = self->memory[__termina_array__index(8U, bank_index)][__termina_array__index(16777216U, start_address + i)];

    }

    #line 81 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

static __status_int32_t CPUSService6__exec6_5TC(const __termina_event_t * const __ev, CPUSService6 * const self) {
    
    #line 166 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status = { .__variant = Success };

    #line 168 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 170 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 176 "src/service_libraries/pus_services/pus_service6.fin"
    if (CPUSService6__is_address_valid(__ev, self) == false) {
        
        #line 178 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_address_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, self->exec_tc_req_status_update.address, &status);

    } else
    {
        
        #line 187 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 193 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 195 "src/service_libraries/pus_services/pus_service6.fin"
            status = CPUSService6__read_data(__ev, self);

        }

        #line 199 "src/service_libraries/pus_services/pus_service6.fin"
        if (status.__variant == Success) {
            
            #line 201 "src/service_libraries/pus_services/pus_service6.fin"
            __option_box_t tm_handler = { .__variant = None };

            #line 202 "src/service_libraries/pus_services/pus_service6.fin"
            self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that, &tm_handler);

            #line 206 "src/service_libraries/pus_services/pus_service6.fin"
            if (tm_handler.__variant == Some) {
                
                #line 206 "src/service_libraries/pus_services/pus_service6.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 208 "src/service_libraries/pus_services/pus_service6.fin"
                MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

                #line 209 "src/service_libraries/pus_services/pus_service6.fin"
                uint16_t tm_count = 0U;

                #line 211 "src/service_libraries/pus_services/pus_service6.fin"
                self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

                #line 212 "src/service_libraries/pus_services/pus_service6.fin"
                self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

                #line 214 "src/service_libraries/pus_services/pus_service6.fin"
                status = build_tm_6_6((TMHandler *)b_tm_handler.data, tm_count, current_obt, &self->exec_tc_req_status_update);

                #line 216 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 217 "src/service_libraries/pus_services/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, &status);

                } else
                {
                    
                    #line 219 "src/service_libraries/pus_services/pus_service6.fin"
                    self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that, b_tm_handler);

                }

                #line 222 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 224 "src/service_libraries/pus_services/pus_service6.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                }

            } else
            {
                
                #line 235 "src/service_libraries/pus_services/pus_service6.fin"
                status.__variant = Failure;
                #line 235 "src/service_libraries/pus_services/pus_service6.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 241 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_mem_access_error(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, &status);

        }

    }

    #line 251 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

static __status_int32_t CPUSService6__exec6_9TC(const __termina_event_t * const __ev, CPUSService6 * const self) {
    
    #line 257 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status = { .__variant = Success };

    #line 259 "src/service_libraries/pus_services/pus_service6.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 261 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 267 "src/service_libraries/pus_services/pus_service6.fin"
    if (CPUSService6__is_address_valid(__ev, self) == false) {
        
        #line 269 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.send_tm_1_4_mem_address_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, self->exec_tc_req_status_update.address, &status);

    } else
    {
        
        #line 278 "src/service_libraries/pus_services/pus_service6.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 283 "src/service_libraries/pus_services/pus_service6.fin"
        __option_uint16_t option_checksum = CPUSService6__check_data(__ev, self);

        #line 287 "src/service_libraries/pus_services/pus_service6.fin"
        if (option_checksum.__variant == Some) {
            
            #line 287 "src/service_libraries/pus_services/pus_service6.fin"
            uint16_t checksum = option_checksum.Some.__0;

            #line 289 "src/service_libraries/pus_services/pus_service6.fin"
            __option_box_t tm_handler = { .__variant = None };

            #line 290 "src/service_libraries/pus_services/pus_service6.fin"
            self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that, &tm_handler);

            #line 294 "src/service_libraries/pus_services/pus_service6.fin"
            if (tm_handler.__variant == Some) {
                
                #line 294 "src/service_libraries/pus_services/pus_service6.fin"
                __termina_box_t b_tm_handler = tm_handler.Some.__0;

                #line 296 "src/service_libraries/pus_services/pus_service6.fin"
                MissionOBT current_obt = { .finetime = 0U, .seconds = 0U };

                #line 297 "src/service_libraries/pus_services/pus_service6.fin"
                uint16_t tm_count = 0U;

                #line 298 "src/service_libraries/pus_services/pus_service6.fin"
                self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

                #line 299 "src/service_libraries/pus_services/pus_service6.fin"
                self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

                #line 301 "src/service_libraries/pus_services/pus_service6.fin"
                status = build_tm_6_10((TMHandler *)b_tm_handler.data, tm_count, current_obt, &self->exec_tc_req_status_update, checksum);

                #line 303 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 304 "src/service_libraries/pus_services/pus_service6.fin"
                    self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, &status);

                } else
                {
                    
                    #line 306 "src/service_libraries/pus_services/pus_service6.fin"
                    self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that, b_tm_handler);

                }

                #line 309 "src/service_libraries/pus_services/pus_service6.fin"
                if (status.__variant == Success) {
                    
                    #line 311 "src/service_libraries/pus_services/pus_service6.fin"
                    self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

                }

            } else
            {
                
                #line 322 "src/service_libraries/pus_services/pus_service6.fin"
                status.__variant = Failure;
                #line 322 "src/service_libraries/pus_services/pus_service6.fin"
                status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

            }

        } else
        {
            
            #line 328 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_mem_access_error(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.mem_id, &status);

        }

    }

    #line 340 "src/service_libraries/pus_services/pus_service6.fin"
    return status;

}

void CPUSService6__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 344 "src/service_libraries/pus_services/pus_service6.fin"
    CPUSService6 * self = (CPUSService6 *)__this;

    #line 344 "src/service_libraries/pus_services/pus_service6.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 346 "src/service_libraries/pus_services/pus_service6.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 348 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 349 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 350 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 351 "src/service_libraries/pus_services/pus_service6.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 353 "src/service_libraries/pus_services/pus_service6.fin"
    __status_int32_t status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.mem_id);

    #line 355 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 356 "src/service_libraries/pus_services/pus_service6.fin"
        status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.N);

    }

    #line 359 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 360 "src/service_libraries/pus_services/pus_service6.fin"
        status = tc_handler_get_u32_appdata_field(tc_handler, &self->exec_tc_req_status_update.address);

    }

    #line 363 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 364 "src/service_libraries/pus_services/pus_service6.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.length);

    }

    #line 367 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success && subtype == 2U) {
        
        #line 368 "src/service_libraries/pus_services/pus_service6.fin"
        for (size_t j = 0U; j < max_num_of_bytes_memory_load && (j < (size_t)self->exec_tc_req_status_update.length && status.__variant == Success); j = j + 1U) {
            
            #line 369 "src/service_libraries/pus_services/pus_service6.fin"
            status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.data[__termina_array__index(256U, j)]);

        }

    }

    #line 373 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 375 "src/service_libraries/pus_services/pus_service6.fin"
        if (subtype == 2U) {
            
            #line 377 "src/service_libraries/pus_services/pus_service6.fin"
            status = CPUSService6__exec6_2TC(__ev, self);

        } else
        #line 379 "src/service_libraries/pus_services/pus_service6.fin"
        if (subtype == 5U) {
            
            #line 381 "src/service_libraries/pus_services/pus_service6.fin"
            status = CPUSService6__exec6_5TC(__ev, self);

        } else
        #line 383 "src/service_libraries/pus_services/pus_service6.fin"
        if (subtype == 9U) {
            
            #line 385 "src/service_libraries/pus_services/pus_service6.fin"
            status = CPUSService6__exec6_9TC(__ev, self);

        } else
        {
            
            #line 389 "src/service_libraries/pus_services/pus_service6.fin"
            status.__variant = Failure;
            #line 389 "src/service_libraries/pus_services/pus_service6.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 396 "src/service_libraries/pus_services/pus_service6.fin"
    if (status.__variant == Success) {
        
        #line 398 "src/service_libraries/pus_services/pus_service6.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 401 "src/service_libraries/pus_services/pus_service6.fin"
        int32_t error_code = status.Failure.__0;

        #line 403 "src/service_libraries/pus_services/pus_service6.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 405 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 410 "src/service_libraries/pus_services/pus_service6.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 412 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 417 "src/service_libraries/pus_services/pus_service6.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 419 "src/service_libraries/pus_services/pus_service6.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_num_bytes, action_status);

        } else
        {
            
            #line 427 "src/service_libraries/pus_services/pus_service6.fin"
            (*action_status).__variant = Failure;
            #line 427 "src/service_libraries/pus_services/pus_service6.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 434 "src/service_libraries/pus_services/pus_service6.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 434 "src/service_libraries/pus_services/pus_service6.fin"
    return;

}
