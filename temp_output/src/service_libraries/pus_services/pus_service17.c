
#include "service_libraries/pus_services/pus_service17.h"

void build_tm_17_2(TMDescriptorT * const tm_descriptor,
                   uint16_t tm_seq_counter) {
    
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

    tm_packet_header.packet_length = 3U;

    df_header.version = ccsds_pus_tm_build_df_header_version(0x1U);

    df_header.type = 17U;

    df_header.subtype = 2U;

    df_header.destinationID = 0x78U;

    ccsds_pus_tm_set_fields(&tm_descriptor->tm_bytes[0U], &tm_packet_header,
                            &df_header);

    tm_descriptor->tm_num_bytes = (size_t)tm_packet_header.packet_length + 7U;

    return;

}

void PUSService17__exec17_1TC(void * const __this,
                              const TCDescriptorT * const tc_descriptor,
                              Result * const result) {
    
    PUSService17 * self = (PUSService17 *)__this;

    __termina_resource__lock(&self->__resource);

    uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

    if (subtype == 1U) {
        
        __option_box_t tm_descriptor;
        tm_descriptor.__variant = None;

        __termina_pool__alloc(self->a_tm_descriptor_pool, &tm_descriptor);

        if (tm_descriptor.__variant == Some) {
            
            __termina_box_t descriptor = tm_descriptor.Some.__0;

            uint16_t tm_count = 0U;

            (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                                 &tm_count);

            build_tm_17_2((TMDescriptorT *)descriptor.data, tm_count);

            (self->tm_channel.send_tm)(self->tm_channel.__that, descriptor,
                                       result);

        } else {
            
            (*result).__variant = Result__Error;

        }

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
