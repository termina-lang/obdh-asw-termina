
#include "service_libraries/serialize.h"

uint16_t deserialize_uint16(const uint8_t data_bytes[2U]) {
    
    #line 11 "src/service_libraries/serialize.fin"
    uint16_t aux = 0U;

    #line 13 "src/service_libraries/serialize.fin"
    aux = (uint16_t)data_bytes[0U];

    #line 14 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 15 "src/service_libraries/serialize.fin"
    aux = aux | (uint16_t)data_bytes[1U];

    #line 17 "src/service_libraries/serialize.fin"
    return aux;

}

uint32_t deserialize_uint32(const uint8_t data_bytes[4U]) {
    
    #line 31 "src/service_libraries/serialize.fin"
    uint32_t aux = 0U;

    #line 33 "src/service_libraries/serialize.fin"
    aux = (uint32_t)data_bytes[0U];

    #line 34 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 35 "src/service_libraries/serialize.fin"
    aux = aux | (uint32_t)data_bytes[1U];

    #line 36 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 37 "src/service_libraries/serialize.fin"
    aux = aux | (uint32_t)data_bytes[2U];

    #line 38 "src/service_libraries/serialize.fin"
    aux = aux << 8U;

    #line 39 "src/service_libraries/serialize.fin"
    aux = aux | (uint32_t)data_bytes[3U];

    #line 41 "src/service_libraries/serialize.fin"
    return aux;

}

void serialize_uint16(uint16_t aux, uint8_t data_bytes[2U]) {
    
    #line 54 "src/service_libraries/serialize.fin"
    data_bytes[0U] = (uint8_t)((uint16_t)(aux & 0xFF00U) >> 8U);

    #line 55 "src/service_libraries/serialize.fin"
    data_bytes[1U] = (uint8_t)(aux & 0xFFU);

    #line 57 "src/service_libraries/serialize.fin"
    return;

}

void serialize_uint32(uint32_t aux, uint8_t data_bytes[4U]) {
    
    #line 70 "src/service_libraries/serialize.fin"
    data_bytes[0U] = (uint8_t)((uint32_t)(aux & 0xFF000000U) >> 24U);

    #line 71 "src/service_libraries/serialize.fin"
    data_bytes[1U] = (uint8_t)((uint32_t)(aux & 0xFF0000U) >> 16U);

    #line 72 "src/service_libraries/serialize.fin"
    data_bytes[2U] = (uint8_t)((uint32_t)(aux & 0xFF00U) >> 8U);

    #line 73 "src/service_libraries/serialize.fin"
    data_bytes[3U] = (uint8_t)(aux & 0xFFU);

    #line 75 "src/service_libraries/serialize.fin"
    return;

}
