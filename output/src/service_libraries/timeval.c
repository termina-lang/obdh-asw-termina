
#include "service_libraries/timeval.h"

TimeVal substract_TimeVal(TimeVal timeval1, TimeVal timeval2) {
    
    #line 13 "src/service_libraries/timeval.fin"
    TimeVal result;
    #line 13 "src/service_libraries/timeval.fin"
    result.tv_sec = 0U;
    #line 13 "src/service_libraries/timeval.fin"
    result.tv_usec = 0U;

    #line 14 "src/service_libraries/timeval.fin"
    result.tv_sec = timeval1.tv_sec - timeval2.tv_sec;

    #line 15 "src/service_libraries/timeval.fin"
    result.tv_usec = timeval1.tv_usec - timeval2.tv_usec;

    #line 16 "src/service_libraries/timeval.fin"
    if (result.tv_usec < 0U) {
        
        #line 17 "src/service_libraries/timeval.fin"
        result.tv_sec = result.tv_sec - 1U;

        #line 18 "src/service_libraries/timeval.fin"
        result.tv_usec = result.tv_usec + 1000000U;

    }

    #line 20 "src/service_libraries/timeval.fin"
    return result;

}
