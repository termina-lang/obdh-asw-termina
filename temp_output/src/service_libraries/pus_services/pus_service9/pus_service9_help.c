
#include "service_libraries/pus_services/pus_service9/pus_service9_help.h"

TimeVal substract_TimeVal(TimeVal timeval1, TimeVal timeval2) {
    
    TimeVal result;
    result.tv_sec = 0U;
    result.tv_usec = 0U;

    result.tv_sec = timeval1.tv_sec - timeval2.tv_sec;

    result.tv_usec = timeval1.tv_usec - timeval2.tv_usec;

    if (result.tv_usec < 0U) {
        
        result.tv_sec = result.tv_sec - 1U;

        result.tv_usec = result.tv_usec + 1000000U;

    }

    return result;

}
