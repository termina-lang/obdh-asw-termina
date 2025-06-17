
#include "service_libraries/serialize.h"

uint16_t deserialize_uint16(const uint8_t data_bytes[2U]) {
    
    uint16_t aux = 0U;

    aux = (uint16_t)data_bytes[0U];

    aux = aux << 8U;

    aux = aux | (uint16_t)data_bytes[1U];

    return aux;

}

uint32_t deserialize_uint32(const uint8_t data_bytes[4U]) {
    
    uint32_t aux = 0U;

    aux = (uint32_t)data_bytes[0U];

    aux = aux << 8U;

    aux = aux | (uint32_t)data_bytes[1U];

    aux = aux << 8U;

    aux = aux | (uint32_t)data_bytes[2U];

    aux = aux << 8U;

    aux = aux | (uint32_t)data_bytes[3U];

    return aux;

}

void serialize_uint16(uint16_t aux, uint8_t data_bytes[2U]) {
    
    data_bytes[0U] = (uint8_t)((uint16_t)(aux & 0xFF00U) >> 8U);

    data_bytes[1U] = (uint8_t)(aux & 0xFFU);

    return;

}

void serialize_uint32(uint32_t aux, uint8_t data_bytes[4U]) {
    
    data_bytes[0U] = (uint8_t)((uint32_t)(aux & 0xFF000000U) >> 24U);

    data_bytes[1U] = (uint8_t)((uint32_t)(aux & 0xFF0000U) >> 16U);

    data_bytes[2U] = (uint8_t)((uint32_t)(aux & 0xFF00U) >> 8U);

    data_bytes[3U] = (uint8_t)(aux & 0xFFU);

    return;

}
