
#include "service_libraries/pus_services/pus_service5/pus_service5.h"

_Bool PUSService5__is_RID_enabled(const PUSService5 * const self,
                                  uint16_t RID) {
    
    _Bool enabled = 0;

    size_t index = get_RID_enable_config_index(RID);

    uint8_t offset = get_RID_enable_config_offset(RID);

    if (index < 4) {
        
        if ((uint32_t)((uint32_t)(self->RID_enable_config[index] >> offset) & 0x1) != 0) {
            
            enabled = 1;

        }

    }

    return enabled;

}

void PUSService5__build_event_list_tms(void * const __this,
                                       EventList * const event_list,
                                       Result * const result) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    for (size_t i = 0; i < max_num_events && i < event_list->num_events; i = i + 1) {
        
        EventInfo event_info;
        event_info.ev_RID = 0;
        for (size_t __i0 = 0; __i0 < event_aux_data_max_size; __i0 = __i0 + 1) {
            event_info.ev_aux_data[__i0] = 0;
        }
        event_info.ev_aux_data_size = 0;

        get_event_info(&*event_list, i, &event_info);

        if (PUSService5__is_RID_enabled(self, event_info.ev_RID)) {
            
            size_t index = get_RID_enable_config_index(event_info.ev_RID);

            if (index < 4) {
                
                __option_box_t tm_descriptor;
                tm_descriptor.__variant = None;

                __termina_pool__alloc(self->a_tm_descriptor_pool,
                                      &tm_descriptor);

                if (tm_descriptor.__variant == Some) {
                    
                    __termina_box_t descriptor = tm_descriptor.Some.__0;

                    uint16_t tm_count = 0;

                    (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                         &tm_count);

                    build_tm_5_x((TMDescriptorT *)descriptor.data, tm_count,
                                 &event_info, index);

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

void PUSService5__exec5_5TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            Result * const result) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        uint16_t RID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

        size_t index = get_RID_enable_config_index(RID);

        uint8_t offset = get_RID_enable_config_offset(RID);

        if (index < 4) {
            
            self->RID_enable_config[index] = self->RID_enable_config[index] | (uint32_t)(1 << offset);

            build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                         tc_descriptor);

        } else {
            
            build_tm_1_8_tc_5_X_RIDunknown((TMDescriptorT *)descriptor.data,
                                           tm_count, RID, tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService5__exec5_6TC(void * const __this,
                            const TCDescriptorT * const tc_descriptor,
                            Result * const result) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    __option_box_t tm_descriptor;
    tm_descriptor.__variant = None;

    __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

    if (tm_descriptor.__variant == Some) {
        
        __termina_box_t descriptor = tm_descriptor.Some.__0;

        uint16_t tm_count = 0;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        uint16_t RID = deserialize_uint16(&tc_descriptor->tc_bytes[10]);

        size_t index = get_RID_enable_config_index(RID);

        uint8_t offset = get_RID_enable_config_offset(RID);

        if (index < 4) {
            
            self->RID_enable_config[index] = self->RID_enable_config[index] & (uint32_t)(0xFFFFFFFE << offset);

            build_tm_1_7((TMDescriptorT *)descriptor.data, tm_count,
                         tc_descriptor);

        } else {
            
            build_tm_1_8_tc_5_X_RIDunknown((TMDescriptorT *)descriptor.data,
                                           tm_count, RID, tc_descriptor);

        }

        (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor, result);

    } else {
        
        (*result).__variant = Result__Error;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService5__is_RID_enabled_ext(void * const __this, uint16_t RID,
                                     _Bool * const p_enabled) {
    
    PUSService5 * self = (PUSService5 *)__this;

    __termina_resource__lock(&self->__resource);

    *p_enabled = PUSService5__is_RID_enabled(self, RID);

    __termina_resource__unlock(&self->__resource);

    return;

}
