
#include "service_libraries/rand.h"

uint32_t rand_r(uint32_t * const mutseed) {
    
    #line 13 "src/service_libraries/rand.fin"
    uint32_t next = *mutseed;

    #line 15 "src/service_libraries/rand.fin"
    next = next * 1103515245U;

    #line 16 "src/service_libraries/rand.fin"
    next = next + 12345U;

    #line 17 "src/service_libraries/rand.fin"
    uint32_t result = (uint32_t)(next / 65536U) % 2048U;

    #line 19 "src/service_libraries/rand.fin"
    next = next * 1103515245U;

    #line 20 "src/service_libraries/rand.fin"
    next = next + 12345U;

    #line 21 "src/service_libraries/rand.fin"
    result = result << 10U;

    #line 22 "src/service_libraries/rand.fin"
    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    #line 24 "src/service_libraries/rand.fin"
    next = next * 1103515245U;

    #line 25 "src/service_libraries/rand.fin"
    next = next + 12345U;

    #line 26 "src/service_libraries/rand.fin"
    result = result << 10U;

    #line 27 "src/service_libraries/rand.fin"
    result = result ^ (uint32_t)((uint32_t)(next / 65536U) % 1024U);

    #line 29 "src/service_libraries/rand.fin"
    *mutseed = next;

    #line 31 "src/service_libraries/rand.fin"
    return result;

}
