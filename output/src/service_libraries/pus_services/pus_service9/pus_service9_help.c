
#include "service_libraries/pus_services/pus_service9/pus_service9_help.h"

TimeVal substract_TimeVal(TimeVal timeval1, TimeVal timeval2) {
    
    #line 18 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    TimeVal result;
    #line 18 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    result.tv_sec = 0U;
    #line 18 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    result.tv_usec = 0U;

    #line 19 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    result.tv_sec = timeval1.tv_sec - timeval2.tv_sec;

    #line 20 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    result.tv_usec = timeval1.tv_usec - timeval2.tv_usec;

    #line 21 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    if (result.tv_usec < 0U) {
        
        #line 22 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
        result.tv_sec = result.tv_sec - 1U;

        #line 23 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
        result.tv_usec = result.tv_usec + 1000000U;

    }

    #line 25 "src/service_libraries/pus_services/pus_service9/pus_service9_help.fin"
    return result;

}
