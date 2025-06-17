
#include "service_libraries/rand.h"

uint32_t rand_r(uint32_t * const mutseed) {
    
    uint32_t next = *mutseed;

    uint32_t result = 0U;

    next = next * 1103515245U;

    next = next + 12345U;

    result = (uint32_t)(next / 65536U) % 2048U;

    next = next * 1103515245U;

    next = next + 12345U;

    result = result << 10U;

    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    next = next * 1103515245U;

    next = next + 12345U;

    result = result << 10U;

    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    *mutseed = next;

    return result;

}
