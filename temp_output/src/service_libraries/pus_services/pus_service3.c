
#include "service_libraries/pus_services/pus_service3.h"

void PUSService3__build_tm_3_25(const PUSService3 * const self,
                                TMDescriptorT * const p_tm_descriptor,
                                uint16_t tm_seq_counter, size_t index) {
    
    CCSDSPUSTMPacketHeaderT tm_packet_header;
    tm_packet_header.packet_id = 0U;
    tm_packet_header.packet_length = 0U;
    tm_packet_header.packet_seq_ctrl = 0U;

    CCSDSPUSTMDFHeaderT df_header;
    df_header.destinationID = 0U;
    df_header.subtype = 0U;
    df_header.type = 0U;
    df_header.version = 0U;

    tm_packet_header.packet_id = ccsds_pus_tm_build_packet_id(0x32CU);

    tm_packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3U,
                                                                          tm_seq_counter);

    tm_packet_header.packet_length = 4U + (uint16_t)(2U * (uint16_t)self->hk_config_table[index].num_params);

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1U);

    df_header.type = 3U;

    df_header.subtype = 25U;

    df_header.destinationID = 0x78U;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0U], &tm_packet_header,
                            &df_header);

    p_tm_descriptor->tm_bytes[10U] = self->hk_config_table[index].SID;

    size_t PID = 0U;

    uint16_t SDP_value = 0U;

    for (size_t j = 0U; j < max_params_per_SID && j < (size_t)self->hk_config_table[index].num_params; j = j + 1U) {
        
        PID = (size_t)self->hk_config_table[index].params_def[j];

        SDP_value = atomic_load(&self->system_data_pool[PID]);

        serialize_uint16(SDP_value, &p_tm_descriptor->tm_bytes[11U + j]);

    }

    p_tm_descriptor->tm_num_bytes = (size_t)tm_packet_header.packet_length + 7U;

    return;

}

void PUSService3__do_hk(void * const __this, Result * const result) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0U; i < max_num_of_SIDs; i = i + 1U) {
        
        if (self->hk_config_table[i].enabled == 1) {
            
            self->hk_config_table[i].interval_control = self->hk_config_table[i].interval_control + 1U;

            if (self->hk_config_table[i].interval_control >= self->hk_config_table[i].interval) {
                
                self->hk_config_table[i].interval_control = 0U;

                __option_box_t tm_descriptor;
                tm_descriptor.__variant = None;

                __termina_pool__alloc(self->a_tm_descriptor_pool,
                                      &tm_descriptor);

                if (tm_descriptor.__variant == Some) {
                    
                    __termina_box_t descriptor = tm_descriptor.Some.__0;

                    uint16_t tm_count = 0U;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count);

                    PUSService3__build_tm_3_25(self,
                                               (TMDescriptorT *)descriptor.data,
                                               tm_count, i);

                    (self->tm_channel.send_tm)(self->tm_channel.__that,
                                               descriptor, result);

                } else {
                    
                    (*result).__variant = Result__Error;

                }

            }

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

_Bool PUSService3__get_SIDindex(const PUSService3 * const self, uint8_t SID,
                                size_t * const index) {
    
    _Bool found = 0;

    for (size_t i = 0U; i < max_num_of_SIDs && found == 0; i = i + 1U) {
        
        if (SID == self->hk_config_table[i].SID) {
            
            *index = i;

            found = 1;

        }

    }

    return found;

}

void PUSService3__exec3_31TC(void * const __this,
                             const TCDescriptorT * const tc_descriptor,
                             Result * const result) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        uint8_t SID = tc_descriptor->tc_bytes[10U];

        size_t index = 0U;

        if (PUSService3__get_SIDindex(self, SID, &index)) {
            
            self->hk_config_table[index].interval = deserialize_uint16(&tc_descriptor->tc_bytes[11U]);

            self->hk_config_table[index].interval_control = 0U;

            build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                         tc_descriptor);

        } else {
            
            build_tm_1_8_tc_3_X_SIDnotvalid((TMDescriptorT *)descriptor.data,
                                            tm_count, (uint16_t)SID,
                                            tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService3__exec3_5TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            Result * const result) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = 0U;

        uint8_t SID = tc_descriptor->tc_bytes[10U];

        if (PUSService3__get_SIDindex(self, SID, &index)) {
            
            self->hk_config_table[index].enabled = 1;

            self->hk_config_table[index].interval_control = 0U;

            build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                         tc_descriptor);

        } else {
            
            build_tm_1_8_tc_3_X_SIDnotvalid((TMDescriptorT *)descriptor.data,
                                            tm_count, (uint16_t)SID,
                                            tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService3__exec3_6TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            Result * const result) {
    
    PUSService3 * self = (PUSService3 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        size_t index = 0U;

        uint8_t SID = tc_descriptor->tc_bytes[10U];

        if (PUSService3__get_SIDindex(self, SID, &index)) {
            
            self->hk_config_table[index].enabled = 0;

            self->hk_config_table[index].interval_control = 0U;

            build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                         tc_descriptor);

        } else {
            
            build_tm_1_8_tc_3_X_SIDnotvalid((TMDescriptorT *)descriptor.data,
                                            tm_count, (uint16_t)SID,
                                            tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
