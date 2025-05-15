
#include "service_libraries/crc.h"

uint16_t cal_crc_16(const uint8_t data[256U], size_t nbytes) {
    
    #line 5 "src/service_libraries/crc.fin"
    uint16_t crc_value = 0xFFFFU;

    #line 6 "src/service_libraries/crc.fin"
    size_t k = 0U;

    #line 8 "src/service_libraries/crc.fin"
    for (size_t i = 0U; i < 256U && k < nbytes; i = i + 1U) {
        
        #line 10 "src/service_libraries/crc.fin"
        crc_value = crc_value ^ (uint16_t)((uint16_t)data[__termina_array__index(256U,
                                                                                 i)] << 8U);

        #line 12 "src/service_libraries/crc.fin"
        for (uint16_t j = 0U; j < 8U; j = j + 1U) {
            
            #line 14 "src/service_libraries/crc.fin"
            if ((uint16_t)(crc_value & 0x8000U) != 0U) {
                
                #line 15 "src/service_libraries/crc.fin"
                crc_value = (uint16_t)(crc_value << 1U) ^ 0x1021U;

            } else
            {
                
                #line 17 "src/service_libraries/crc.fin"
                crc_value = crc_value << 1U;

            }

        }

        #line 21 "src/service_libraries/crc.fin"
        k = k + 1U;

    }

    #line 24 "src/service_libraries/crc.fin"
    return crc_value;

}
