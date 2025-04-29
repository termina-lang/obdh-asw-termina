
#include "service_libraries/crc.h"

uint16_t cal_crc_16(const uint8_t data[max_tc_size], size_t nbytes) {
    
    uint16_t crc_value = 0xFFFFU;

    size_t k = 0U;

    for (size_t i = 0U; i < max_tc_size && k < nbytes; i = i + 1U) {
        
        crc_value = crc_value ^ (uint16_t)((uint16_t)data[__termina_array__index(max_tc_size,
                                                                                 i)] << 8U);

        for (uint16_t j = 0U; j < 8U; j = j + 1U) {
            
            if ((uint16_t)(crc_value & 0x8000U) != 0U) {
                
                crc_value = (uint16_t)(crc_value << 1U) ^ 0x1021U;

            } else {
                
                crc_value = crc_value << 1U;

            }

        }

        k = k + 1U;

    }

    return crc_value;

}
