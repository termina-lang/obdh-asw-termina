
#include "service_libraries/pus_services/pus_service3.h"

_Bool get_SIDindex(const HKConfiguration hk_config_table[max_num_of_SIDs],
                   uint8_t SID, size_t * index) {
    
    _Bool found = 0;

    for (size_t i = 0; i < max_num_of_SIDs && found == 0; i = i + 1) {
        
        if (SID == hk_config_table[i].SID) {
            
            *index = i;

            found = 1;

        }

    }

    return found;

}

void enable_config(const TCDescriptorT * tc_descriptor,
                   TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                   HKConfiguration hk_config_table[max_num_of_SIDs],
                   _Bool new_enable_config) {
    
    size_t index = 0;

    uint8_t SID = tc_descriptor->tc_bytes[10];

    if (get_SIDindex(hk_config_table, SID, &index)) {
        
        hk_config_table[index].enabled = new_enable_config;

        hk_config_table[index].interval_control = 0;

        build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

    } else {
        
        build_tm_1_8_tc_3_X_SIDnotvalid(tm_descriptor, tm_seq_counter,
                                        (uint16_t)SID, tc_descriptor);

    }

    return;

}

void exec3_5TC(const TCDescriptorT * tc_descriptor,
               TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
               HKConfiguration hk_config_table[max_num_of_SIDs]) {
    
    enable_config(tc_descriptor, tm_descriptor, tm_seq_counter, hk_config_table,
                  1);

    return;

}

void exec3_6TC(const TCDescriptorT * tc_descriptor,
               TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
               HKConfiguration hk_config_table[max_num_of_SIDs]) {
    
    enable_config(tc_descriptor, tm_descriptor, tm_seq_counter, hk_config_table,
                  0);

    return;

}

void exec3_31TC(const TCDescriptorT * tc_descriptor,
                TMDescriptorT * tm_descriptor, uint16_t tm_seq_counter,
                HKConfiguration hk_config_table[max_num_of_SIDs]) {
    
    uint8_t SID = tc_descriptor->tc_bytes[10];

    size_t index = 0;

    if (get_SIDindex(hk_config_table, SID, &index)) {
        
        hk_config_table[index].interval = deserialize_uint16(&tc_descriptor->tc_bytes[11]);

        hk_config_table[index].interval_control = 0;

        build_tm_1_7(tm_descriptor, tm_seq_counter, tc_descriptor);

    } else {
        
        build_tm_1_8_tc_3_X_SIDnotvalid(tm_descriptor, tm_seq_counter,
                                        (uint16_t)SID, tc_descriptor);

    }

    return;

}

void PUS_service_3_execTC(const TCDescriptorT * tc_descriptor,
                          TMDescriptorT * tm_descriptor,
                          uint16_t tm_seq_counter,
                          HKConfiguration hk_config_table[max_num_of_SIDs]) {
    
    uint8_t subtype = get_subtype(tc_descriptor->tc_bytes);

    if (subtype == 5) {
        
        exec3_5TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                  hk_config_table);

    } else if (subtype == 6) {
        
        exec3_6TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                  hk_config_table);

    } else if (subtype == 31) {
        
        exec3_31TC(tc_descriptor, tm_descriptor, tm_seq_counter,
                   hk_config_table);

    } else {
        

    }

    return;

}
