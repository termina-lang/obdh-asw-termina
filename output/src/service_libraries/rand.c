
#include "service_libraries/rand.h"

uint32_t rand_r(uint32_t * const mutseed) {
    
    #line 13 "src/service_libraries/rand.fin"
    uint32_t next = *mutseed;

    #line 14 "src/service_libraries/rand.fin"
    uint32_t result = 0U;

    #line 16 "src/service_libraries/rand.fin"
    next = next * 1103515245U;

    #line 17 "src/service_libraries/rand.fin"
    next = next + 12345U;

    #line 18 "src/service_libraries/rand.fin"
    result = (uint32_t)(next / 65536U) % 2048U;

    #line 20 "src/service_libraries/rand.fin"
    next = next * 1103515245U;

    #line 21 "src/service_libraries/rand.fin"
    next = next + 12345U;

    #line 22 "src/service_libraries/rand.fin"
    result = result << 10U;

    #line 23 "src/service_libraries/rand.fin"
    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    #line 25 "src/service_libraries/rand.fin"
    next = next * 1103515245U;

    #line 26 "src/service_libraries/rand.fin"
    next = next + 12345U;

    #line 27 "src/service_libraries/rand.fin"
    result = result << 10U;

    #line 28 "src/service_libraries/rand.fin"
    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    #line 30 "src/service_libraries/rand.fin"
    *mutseed = next;

    #line 32 "src/service_libraries/rand.fin"
    return result;

}
