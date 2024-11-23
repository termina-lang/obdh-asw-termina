
#include "service_libraries/pus_services/pus_service20.h"

void PUSService20__build_tm_20_2(const PUSService20 * const self, size_t PID,
                                 TMDescriptorT * const p_tm_descriptor,
                                 uint16_t tm_seq_counter) {
    
    CCSDSPUSTMPacketHeaderT tm_packet_header;
    tm_packet_header.packet_id = 0;
    tm_packet_header.packet_length = 0;
    tm_packet_header.packet_seq_ctrl = 0;

    CCSDSPUSTMDFHeaderT df_header;
    df_header.destinationID = 0;
    df_header.subtype = 0;
    df_header.type = 0;
    df_header.version = 0;

    tm_packet_header.packet_id = ccsds_pus_tm_build_packet_id(0x32C);

    tm_packet_header.packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3,
                                                                          tm_seq_counter);

    tm_packet_header.packet_length = 7;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1);

    df_header.type = 20;

    df_header.subtype = 2;

    df_header.destinationID = 0x78;

    ccsds_pus_tm_set_fields(&p_tm_descriptor->tm_bytes[0], &tm_packet_header,
                            &df_header);

    serialize_uint16((uint16_t)PID, &p_tm_descriptor->tm_bytes[14]);

    uint16_t param_value = 0;

    param_value = atomic_load(&self->system_data_pool[PID]);

    serialize_uint16(param_value, &p_tm_descriptor->tm_bytes[16]);

    p_tm_descriptor->tm_num_bytes = (size_t)(tm_packet_header.packet_length + 7);

    return;

}

void PUSService20__exec20_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter, Result * const res) {
    
    PUSService20 * self = (PUSService20 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t PID = (size_t)deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    if (PID < sdp_num_params) {
        
        __option_box_t tm_descriptor1;
        tm_descriptor1.__variant = None;

        __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor1);

        if (tm_descriptor1.__variant == Some) {
            
            __termina_box_t descriptor1 = tm_descriptor1.Some.__0;

            uint16_t tm_count = 0;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            PUSService20__build_tm_20_2(self, PID,
                                        (TMDescriptorT *)descriptor1.data,
                                        tm_count);

            (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor1,
                                       res);

        } else {
            

        }

        build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

    } else {
        
        build_tm_1_8_tc_20_X_PIDnotvalid(tm_descriptor, tm_seq_counter,
                                         (uint16_t)PID, tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}

void PUSService20__exec20_3TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              TMDescriptorT * const tm_descriptor,
                              uint16_t tm_seq_counter) {
    
    PUSService20 * self = (PUSService20 *)__this;

    __termina_resource__lock(&self->__resource);

    size_t PID = (size_t)deserialize_uint16(&tc_descriptor->tc_bytes[10]);

    uint16_t param_value = deserialize_uint16(&tc_descriptor->tc_bytes[12]);

    if (PID < sdp_num_params) {
        
        atomic_store(&self->system_data_pool[PID], param_value);

        build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

    } else {
        
        build_tm_1_8_tc_20_X_PIDnotvalid(tm_descriptor, tm_seq_counter,
                                         (uint16_t)PID, tc_descriptor);

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
