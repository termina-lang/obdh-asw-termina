
#include "libraries/crc.h"

uint16_t cal_crc_16(const uint8_t data[max_tc_size], size_t nbytes) {
    
    uint16_t crc_value = 0xFFFF;

    size_t k = 0;

    for (size_t i = 0; i < max_tc_size && k < nbytes; i = i + 1) {
        
        crc_value = crc_value ^ (uint16_t)((uint16_t)data[i] << 8);

        for (uint16_t j = 0; j < 8; j = j + 1) {
            
            if ((uint16_t)(crc_value & 0x8000) != 0) {
                
                crc_value = (uint16_t)(crc_value << 1) ^ 0x1021;

            } else {
                
                crc_value = crc_value << 1;

            }

        }

        k = k + 1;

    }

    return crc_value;

}
