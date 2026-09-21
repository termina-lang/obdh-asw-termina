
#include "tasks/obdh_manager/mng_tc_executor.h"

void CManagerTExecutor__PUS_prio_exec_tc(const termina__event_t * const termina__ev, void * const termina__this, TCHandler * const tc_handler, Status__i32 * const status, _Bool * const reebot_flag) {
    
    #line 59 "src/tasks/obdh_manager/mng_tc_executor.fin"
    CManagerTExecutor * self = (CManagerTExecutor *)termina__this;

    #line 59 "src/tasks/obdh_manager/mng_tc_executor.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 61 "src/tasks/obdh_manager/mng_tc_executor.fin"
    uint8_t tc_type = tc_handler->df_header.type;

    #line 63 "src/tasks/obdh_manager/mng_tc_executor.fin"
    if (tc_type == 17U) {
        
        #line 65 "src/tasks/obdh_manager/mng_tc_executor.fin"
        self->pus_service_17.exec_tc(termina__ev, self->pus_service_17._that, tc_handler, status);

    } else
    #line 67 "src/tasks/obdh_manager/mng_tc_executor.fin"
    if (tc_type == 2U) {
        
        #line 69 "src/tasks/obdh_manager/mng_tc_executor.fin"
        self->pus_service_2.exec_tc(termina__ev, self->pus_service_2._that, tc_handler, status);

    } else
    #line 71 "src/tasks/obdh_manager/mng_tc_executor.fin"
    if (tc_type == 9U) {
        
        #line 73 "src/tasks/obdh_manager/mng_tc_executor.fin"
        self->pus_service_9.exec_tc(termina__ev, self->pus_service_9._that, tc_handler, status);

    } else
    #line 75 "src/tasks/obdh_manager/mng_tc_executor.fin"
    if (tc_type == 128U) {
        
        #line 77 "src/tasks/obdh_manager/mng_tc_executor.fin"
        self->pus_service_128.exec_tc(termina__ev, self->pus_service_128._that, tc_handler, status, reebot_flag);

    } else
    {
        
        #line 81 "src/tasks/obdh_manager/mng_tc_executor.fin"
        self->pus_service_1.send_tm_1_4_error_in_acceptance(termina__ev, self->pus_service_1._that, tc_handler->packet_header.packet_id, tc_handler->packet_header.packet_seq_ctrl, status);

    }

    #line 88 "src/tasks/obdh_manager/mng_tc_executor.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 88 "src/tasks/obdh_manager/mng_tc_executor.fin"
    return;

}

void CManagerTExecutor__mng_tc_acceptation(const termina__event_t * const termina__ev, void * const termina__this, const TCHandler * const tc_handler, Status__i32 * const status) {
    
    #line 101 "src/tasks/obdh_manager/mng_tc_executor.fin"
    CManagerTExecutor * self = (CManagerTExecutor *)termina__this;

    #line 101 "src/tasks/obdh_manager/mng_tc_executor.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 103 "src/tasks/obdh_manager/mng_tc_executor.fin"
    self->pus_service_1.notify_tm_1_1(termina__ev, self->pus_service_1._that, tc_handler->packet_header.packet_id, tc_handler->packet_header.packet_seq_ctrl, tc_handler->df_header.flag_ver_ack, status);

    #line 109 "src/tasks/obdh_manager/mng_tc_executor.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 109 "src/tasks/obdh_manager/mng_tc_executor.fin"
    return;

}

void CManagerTExecutor__mng_tc_rejection(const termina__event_t * const termina__ev, void * const termina__this, const TCHandler * const tc_handler, const TCStatus * const tc_status, Status__i32 * const status) {
    
    #line 122 "src/tasks/obdh_manager/mng_tc_executor.fin"
    CManagerTExecutor * self = (CManagerTExecutor *)termina__this;

    #line 122 "src/tasks/obdh_manager/mng_tc_executor.fin"
    termina__lock_t termina__lock = termina__resource__lock(&termina__ev->owner, &self->_lock_type);

    #line 124 "src/tasks/obdh_manager/mng_tc_executor.fin"
    self->pus_service_1.send_tm_1_2(termina__ev, self->pus_service_1._that, tc_status, tc_handler, status);

    #line 126 "src/tasks/obdh_manager/mng_tc_executor.fin"
    termina__resource__unlock(&termina__ev->owner, &self->_lock_type, termina__lock);

    #line 126 "src/tasks/obdh_manager/mng_tc_executor.fin"
    return;

}
