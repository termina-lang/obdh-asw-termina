
#include "service_libraries/pus_services/pus_service5.h"

__status_int32_t PUSService5__exec5_5TC(const __termina_event_t * const __ev, PUSService5 * const self) {
    
    #line 88 "src/service_libraries/pus_services/pus_service5.fin"
    __status_int32_t status;
    #line 88 "src/service_libraries/pus_services/pus_service5.fin"
    status.__variant = Success;

    #line 90 "src/service_libraries/pus_services/pus_service5.fin"
    size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

    #line 91 "src/service_libraries/pus_services/pus_service5.fin"
    uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

    #line 93 "src/service_libraries/pus_services/pus_service5.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 95 "src/service_libraries/pus_services/pus_service5.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 100 "src/service_libraries/pus_services/pus_service5.fin"
    if (index > 4U) {
        
        #line 102 "src/service_libraries/pus_services/pus_service5.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.EvID, &status);

    } else
    {
        
        #line 109 "src/service_libraries/pus_services/pus_service5.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 115 "src/service_libraries/pus_services/pus_service5.fin"
        if (status.__variant == Success) {
            
            #line 117 "src/service_libraries/pus_services/pus_service5.fin"
            uint32_t mask = 0x1U << (uint8_t)(offset - 1U);

            #line 118 "src/service_libraries/pus_services/pus_service5.fin"
            self->Ev_ID_enable_config[__termina_array__index(4U, index - 1U)] = self->Ev_ID_enable_config[__termina_array__index(4U, index - 1U)] | mask;

            #line 120 "src/service_libraries/pus_services/pus_service5.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        }

    }

    #line 130 "src/service_libraries/pus_services/pus_service5.fin"
    return status;

}

__status_int32_t PUSService5__exec5_6TC(const __termina_event_t * const __ev, PUSService5 * const self) {
    
    #line 136 "src/service_libraries/pus_services/pus_service5.fin"
    __status_int32_t status;
    #line 136 "src/service_libraries/pus_services/pus_service5.fin"
    status.__variant = Success;

    #line 138 "src/service_libraries/pus_services/pus_service5.fin"
    size_t index = get_Ev_ID_enable_config_index(self->exec_tc_req_status_update.EvID);

    #line 139 "src/service_libraries/pus_services/pus_service5.fin"
    uint8_t offset = get_Ev_ID_enable_config_offset(self->exec_tc_req_status_update.EvID);

    #line 141 "src/service_libraries/pus_services/pus_service5.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 143 "src/service_libraries/pus_services/pus_service5.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.N, &status);

    } else
    #line 148 "src/service_libraries/pus_services/pus_service5.fin"
    if (index > 4U) {
        
        #line 150 "src/service_libraries/pus_services/pus_service5.fin"
        self->pus_service_1.send_tm_1_4_EvID_not_valid(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.EvID, &status);

    } else
    {
        
        #line 158 "src/service_libraries/pus_services/pus_service5.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        #line 164 "src/service_libraries/pus_services/pus_service5.fin"
        if (status.__variant == Success) {
            
            #line 166 "src/service_libraries/pus_services/pus_service5.fin"
            uint32_t mask = 0x1U << (uint8_t)(offset - 1U);

            #line 167 "src/service_libraries/pus_services/pus_service5.fin"
            self->Ev_ID_enable_config[__termina_array__index(4U, index - 1U)] = self->Ev_ID_enable_config[__termina_array__index(4U, index - 1U)] & (uint32_t)(0xFFFFFFFEU ^ mask);

            #line 169 "src/service_libraries/pus_services/pus_service5.fin"
            self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.flags_ack, &status);

        }

    }

    #line 178 "src/service_libraries/pus_services/pus_service5.fin"
    return status;

}

void PUSService5__exec_tc(const __termina_event_t * const __ev, void * const __this, TCHandler * const tc_handler, __status_int32_t * const action_status) {
    
    #line 262 "src/service_libraries/pus_services/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 262 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 264 "src/service_libraries/pus_services/pus_service5.fin"
    __status_int32_t status;
    #line 264 "src/service_libraries/pus_services/pus_service5.fin"
    status.__variant = Success;

    #line 265 "src/service_libraries/pus_services/pus_service5.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 267 "src/service_libraries/pus_services/pus_service5.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 268 "src/service_libraries/pus_services/pus_service5.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 269 "src/service_libraries/pus_services/pus_service5.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 270 "src/service_libraries/pus_services/pus_service5.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 271 "src/service_libraries/pus_services/pus_service5.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler, &self->exec_tc_req_status_update.N);

    #line 273 "src/service_libraries/pus_services/pus_service5.fin"
    if (status.__variant == Success) {
        
        #line 274 "src/service_libraries/pus_services/pus_service5.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler, &self->exec_tc_req_status_update.EvID);

    }

    #line 277 "src/service_libraries/pus_services/pus_service5.fin"
    if (status.__variant == Success) {
        
        #line 279 "src/service_libraries/pus_services/pus_service5.fin"
        if (subtype == 5U) {
            
            #line 281 "src/service_libraries/pus_services/pus_service5.fin"
            status = PUSService5__exec5_5TC(__ev, self);

        } else
        #line 283 "src/service_libraries/pus_services/pus_service5.fin"
        if (subtype == 6U) {
            
            #line 285 "src/service_libraries/pus_services/pus_service5.fin"
            status = PUSService5__exec5_6TC(__ev, self);

        } else
        {
            
            #line 289 "src/service_libraries/pus_services/pus_service5.fin"
            status.__variant = Failure;
            #line 289 "src/service_libraries/pus_services/pus_service5.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 296 "src/service_libraries/pus_services/pus_service5.fin"
    if (status.__variant == Success) {
        
        #line 298 "src/service_libraries/pus_services/pus_service5.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 301 "src/service_libraries/pus_services/pus_service5.fin"
        int32_t error_code = status.Failure.__0;

        #line 303 "src/service_libraries/pus_services/pus_service5.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 305 "src/service_libraries/pus_services/pus_service5.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 310 "src/service_libraries/pus_services/pus_service5.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 312 "src/service_libraries/pus_services/pus_service5.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, action_status);

        } else
        #line 317 "src/service_libraries/pus_services/pus_service5.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 319 "src/service_libraries/pus_services/pus_service5.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev, self->pus_service_1.__that, self->exec_tc_req_status_update.packet_id, self->exec_tc_req_status_update.packet_seq_ctrl, self->exec_tc_req_status_update.tc_num_bytes, action_status);

        } else
        {
            
            #line 327 "src/service_libraries/pus_services/pus_service5.fin"
            (*action_status).__variant = Failure;
            #line 327 "src/service_libraries/pus_services/pus_service5.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 334 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 334 "src/service_libraries/pus_services/pus_service5.fin"
    return;

}

_Bool PUSService5__is_Ev_ID_enabled(const __termina_event_t * const __ev, const PUSService5 * const self, uint16_t Ev_ID) {
    
    #line 64 "src/service_libraries/pus_services/pus_service5.fin"
    _Bool enabled = 0;

    #line 65 "src/service_libraries/pus_services/pus_service5.fin"
    size_t index = get_Ev_ID_enable_config_index(Ev_ID);

    #line 66 "src/service_libraries/pus_services/pus_service5.fin"
    uint8_t offset = get_Ev_ID_enable_config_offset(Ev_ID);

    #line 68 "src/service_libraries/pus_services/pus_service5.fin"
    if (index <= 4U) {
        
        #line 70 "src/service_libraries/pus_services/pus_service5.fin"
        size_t config_array_index = index - 1U;

        #line 71 "src/service_libraries/pus_services/pus_service5.fin"
        if ((uint32_t)((uint32_t)(self->Ev_ID_enable_config[__termina_array__index(4U, config_array_index)] >> (uint8_t)(offset - 1U)) & 0x1U) != 0U) {
            
            #line 72 "src/service_libraries/pus_services/pus_service5.fin"
            enabled = 1;

        }

    }

    #line 76 "src/service_libraries/pus_services/pus_service5.fin"
    return enabled;

}

void PUSService5__is_Ev_ID_enabled_ext(const __termina_event_t * const __ev, void * const __this, uint16_t Ev_ID, _Bool * const p_enabled) {
    
    #line 79 "src/service_libraries/pus_services/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 79 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 81 "src/service_libraries/pus_services/pus_service5.fin"
    *p_enabled = PUSService5__is_Ev_ID_enabled(__ev, self, Ev_ID);

    #line 83 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 83 "src/service_libraries/pus_services/pus_service5.fin"
    return;

}

void PUSService5__send_tm_5_2(const __termina_event_t * const __ev, void * const __this, __status_int32_t * const status) {
    
    #line 182 "src/service_libraries/pus_services/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 182 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 184 "src/service_libraries/pus_services/pus_service5.fin"
    __option_box_t tm_handler;
    #line 184 "src/service_libraries/pus_services/pus_service5.fin"
    tm_handler.__variant = None;

    #line 185 "src/service_libraries/pus_services/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that, &tm_handler);

    #line 189 "src/service_libraries/pus_services/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 189 "src/service_libraries/pus_services/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 191 "src/service_libraries/pus_services/pus_service5.fin"
        startup_tm((TMHandler *)b_tm_handler.data);

        #line 192 "src/service_libraries/pus_services/pus_service5.fin"
        *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data, EvID_build_tm_error);

        #line 194 "src/service_libraries/pus_services/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 196 "src/service_libraries/pus_services/pus_service5.fin"
            MissionOBT current_obt;
            #line 196 "src/service_libraries/pus_services/pus_service5.fin"
            current_obt.finetime = 0U;
            #line 196 "src/service_libraries/pus_services/pus_service5.fin"
            current_obt.seconds = 0U;

            #line 197 "src/service_libraries/pus_services/pus_service5.fin"
            uint16_t tm_count = 0U;

            #line 199 "src/service_libraries/pus_services/pus_service5.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

            #line 200 "src/service_libraries/pus_services/pus_service5.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

            #line 202 "src/service_libraries/pus_services/pus_service5.fin"
            close_tm((TMHandler *)b_tm_handler.data, 5U, 2U, tm_count, current_obt);

            #line 204 "src/service_libraries/pus_services/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, status);

        } else
        {
            
            #line 208 "src/service_libraries/pus_services/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that, b_tm_handler);

        }

    } else
    {
        
        #line 212 "src/service_libraries/pus_services/pus_service5.fin"
        (*status).__variant = Failure;
        #line 212 "src/service_libraries/pus_services/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 216 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 216 "src/service_libraries/pus_services/pus_service5.fin"
    return;

}

void PUSService5__send_tm_5_x(const __termina_event_t * const __ev, void * const __this, uint16_t evID, FaultInfo fault_info, __status_int32_t * const status) {
    
    #line 220 "src/service_libraries/pus_services/pus_service5.fin"
    PUSService5 * self = (PUSService5 *)__this;

    #line 220 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner, &self->__lock_type);

    #line 222 "src/service_libraries/pus_services/pus_service5.fin"
    __option_box_t tm_handler;
    #line 222 "src/service_libraries/pus_services/pus_service5.fin"
    tm_handler.__variant = None;

    #line 223 "src/service_libraries/pus_services/pus_service5.fin"
    self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that, &tm_handler);

    #line 227 "src/service_libraries/pus_services/pus_service5.fin"
    if (tm_handler.__variant == Some) {
        
        #line 227 "src/service_libraries/pus_services/pus_service5.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 229 "src/service_libraries/pus_services/pus_service5.fin"
        MissionOBT current_obt;
        #line 229 "src/service_libraries/pus_services/pus_service5.fin"
        current_obt.finetime = 0U;
        #line 229 "src/service_libraries/pus_services/pus_service5.fin"
        current_obt.seconds = 0U;

        #line 230 "src/service_libraries/pus_services/pus_service5.fin"
        uint16_t tm_count = 0U;

        #line 232 "src/service_libraries/pus_services/pus_service5.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that, &tm_count);

        #line 233 "src/service_libraries/pus_services/pus_service5.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that, &current_obt);

        #line 236 "src/service_libraries/pus_services/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamOutOfLimit) {
            
            #line 236 "src/service_libraries/pus_services/pus_service5.fin"
            ParamOutOfLimitInfo fault_value_info = fault_info.ParamOutOfLimit.__0;

            #line 237 "src/service_libraries/pus_services/pus_service5.fin"
            *status = build_tm_5_x_param_out_of_limit((TMHandler *)b_tm_handler.data, tm_count, fault_value_info, evID, current_obt);

        } else
        #line 239 "src/service_libraries/pus_services/pus_service5.fin"
        if (fault_info.__variant == FaultInfo__ParamFaultValue) {
            
            #line 239 "src/service_libraries/pus_services/pus_service5.fin"
            ParamFaultValueInfo fault_value_info = fault_info.ParamFaultValue.__0;

            #line 240 "src/service_libraries/pus_services/pus_service5.fin"
            *status = build_tm_5_x_param_check_value_fail((TMHandler *)b_tm_handler.data, tm_count, fault_value_info, evID, current_obt);

        } else
        {
            

        }

        #line 247 "src/service_libraries/pus_services/pus_service5.fin"
        if ((*status).__variant == Success) {
            
            #line 248 "src/service_libraries/pus_services/pus_service5.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that, b_tm_handler, status);

        } else
        {
            
            #line 250 "src/service_libraries/pus_services/pus_service5.fin"
            self->a_tm_handler_pool.free(__ev, self->a_tm_handler_pool.__that, b_tm_handler);

        }

    } else
    {
        
        #line 255 "src/service_libraries/pus_services/pus_service5.fin"
        (*status).__variant = Failure;
        #line 255 "src/service_libraries/pus_services/pus_service5.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 259 "src/service_libraries/pus_services/pus_service5.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 259 "src/service_libraries/pus_services/pus_service5.fin"
    return;

}
