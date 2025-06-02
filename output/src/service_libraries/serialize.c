
#include "service_libraries/serialize.h"

uint16_t deserialize_uint16(const uint8_t data_bytes[2U]) {
    
    #line 14 "src/service_libraries/serialize.fin"
    uint16_t aux = 0U;

    #line 16 "src/service_libraries/serialize.fin"
    aux = (uint16_t)data_bytes[0U];

    #line 17 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 18 "src/service_libraries/serialize.fin"
    aux = aux | (uint16_t)data_bytes[1U];

    #line 20 "src/service_libraries/serialize.fin"
    return aux;

}

uint32_t deserialize_uint32(const uint8_t data_bytes[4U]) {
    
    #line 36 "src/service_libraries/serialize.fin"
    uint32_t aux = 0U;

    #line 38 "src/service_libraries/serialize.fin"
    aux = (uint32_t)data_bytes[0U];

    #line 39 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 40 "src/service_libraries/serialize.fin"
    aux = aux | (uint32_t)data_bytes[1U];

    #line 41 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 42 "src/service_libraries/serialize.fin"
    aux = aux | (uint32_t)data_bytes[2U];

    #line 43 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 44 "src/service_libraries/serialize.fin"
    aux = aux | (uint32_t)data_bytes[3U];

    #line 46 "src/service_libraries/serialize.fin"
    return aux;

}

void serialize_uint16(uint16_t aux, uint8_t data_bytes[2U]) {
    
    #line 60 "src/service_libraries/serialize.fin"
    data_bytes[0U] = (uint8_t)((uint16_t)(aux & 0xFF00U) >> 8U);

    #line 61 "src/service_libraries/serialize.fin"
    data_bytes[1U] = (uint8_t)(aux & 0xFFU);

    #line 63 "src/service_libraries/serialize.fin"
    return;

}

void serialize_uint32(uint32_t aux, uint8_t data_bytes[4U]) {
    
    #line 77 "src/service_libraries/serialize.fin"
    data_bytes[0U] = (uint8_t)((uint32_t)(aux & 0xFF000000U) >> 24U);

    #line 78 "src/service_libraries/serialize.fin"
    data_bytes[1U] = (uint8_t)((uint32_t)(aux & 0xFF0000U) >> 16U);

    #line 79 "src/service_libraries/serialize.fin"
    data_bytes[2U] = (uint8_t)((uint32_t)(aux & 0xFF00U) >> 8U);

    #line 80 "src/service_libraries/serialize.fin"
    data_bytes[3U] = (uint8_t)(aux & 0xFFU);

    #line 82 "src/service_libraries/serialize.fin"
    return;

}
