
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

uint32_t rand_r(uint32_t * const mutseed) {
    
    #line 30 "src/service_libraries/crc.fin"
    uint32_t next = *mutseed;

    #line 31 "src/service_libraries/crc.fin"
    uint32_t result = 0U;

    #line 33 "src/service_libraries/crc.fin"
    next = next * 1103515245U;

    #line 34 "src/service_libraries/crc.fin"
    next = next + 12345U;

    #line 35 "src/service_libraries/crc.fin"
    result = (uint32_t)(next / 65536U) % 2048U;

    #line 37 "src/service_libraries/crc.fin"
    next = next * 1103515245U;

    #line 38 "src/service_libraries/crc.fin"
    next = next + 12345U;

    #line 39 "src/service_libraries/crc.fin"
    result = result << 10U;

    #line 40 "src/service_libraries/crc.fin"
    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    #line 42 "src/service_libraries/crc.fin"
    next = next * 1103515245U;

    #line 43 "src/service_libraries/crc.fin"
    next = next + 12345U;

    #line 44 "src/service_libraries/crc.fin"
    result = result << 10U;

    #line 45 "src/service_libraries/crc.fin"
    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    #line 47 "src/service_libraries/crc.fin"
    *mutseed = next;

    #line 49 "src/service_libraries/crc.fin"
    return result;

}
