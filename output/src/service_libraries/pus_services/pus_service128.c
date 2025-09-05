
#include "service_libraries/pus_services/pus_service128.h"

__status_int32_t PUSService128__exec128_1TC(const __termina_event_t * const __ev,
                                            PUSService128 * const self) {
    
    #line 22 "src/service_libraries/pus_services/pus_service128.fin"
    __status_int32_t status;
    #line 22 "src/service_libraries/pus_services/pus_service128.fin"
    status.__variant = Success;

    #line 24 "src/service_libraries/pus_services/pus_service128.fin"
    self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      &status);

    #line 30 "src/service_libraries/pus_services/pus_service128.fin"
    if (status.__variant == Success) {
        
        #line 31 "src/service_libraries/pus_services/pus_service128.fin"
        self->exec_tc_req_status_update.reebot_flag = 1;

        #line 32 "src/service_libraries/pus_services/pus_service128.fin"
        self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

    }

    #line 39 "src/service_libraries/pus_services/pus_service128.fin"
    return status;

}

void PUSService128__exec_tc(const __termina_event_t * const __ev,
                            void * const __this, TCHandler * const tc_handler,
                            __status_int32_t * const action_status,
                            _Bool * const reebot_flag) {
    
    #line 43 "src/service_libraries/pus_services/pus_service128.fin"
    PUSService128 * self = (PUSService128 *)__this;

    #line 43 "src/service_libraries/pus_services/pus_service128.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 45 "src/service_libraries/pus_services/pus_service128.fin"
    __status_int32_t status;
    #line 45 "src/service_libraries/pus_services/pus_service128.fin"
    status.__variant = Success;

    #line 46 "src/service_libraries/pus_services/pus_service128.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 48 "src/service_libraries/pus_services/pus_service128.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 49 "src/service_libraries/pus_services/pus_service128.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 50 "src/service_libraries/pus_services/pus_service128.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 52 "src/service_libraries/pus_services/pus_service128.fin"
    if (subtype == 1U) {
        
        #line 54 "src/service_libraries/pus_services/pus_service128.fin"
        status = PUSService128__exec128_1TC(__ev, self);

    } else
    {
        
        #line 58 "src/service_libraries/pus_services/pus_service128.fin"
        status.__variant = Failure;
        #line 58 "src/service_libraries/pus_services/pus_service128.fin"
        status.Failure.__0 = ACCEPTANCE_ERROR;

    }

    #line 64 "src/service_libraries/pus_services/pus_service128.fin"
    if (status.__variant == Success) {
        
        #line 66 "src/service_libraries/pus_services/pus_service128.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 62 "src/service_libraries/pus_services/pus_service128.fin"
        int32_t error_code = status.Failure.__0;

        #line 72 "src/service_libraries/pus_services/pus_service128.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 74 "src/service_libraries/pus_services/pus_service128.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                action_status);

        } else
        #line 79 "src/service_libraries/pus_services/pus_service128.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 81 "src/service_libraries/pus_services/pus_service128.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    action_status);

        } else
        {
            
            #line 88 "src/service_libraries/pus_services/pus_service128.fin"
            (*action_status).__variant = Failure;
            #line 88 "src/service_libraries/pus_services/pus_service128.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 95 "src/service_libraries/pus_services/pus_service128.fin"
    *reebot_flag = self->exec_tc_req_status_update.reebot_flag;

    #line 97 "src/service_libraries/pus_services/pus_service128.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 97 "src/service_libraries/pus_services/pus_service128.fin"
    return;

}
