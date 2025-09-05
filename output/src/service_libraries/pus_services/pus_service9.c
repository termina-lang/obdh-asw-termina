
#include "service_libraries/pus_services/pus_service9.h"

__status_int32_t PUSService9__exec9_129TC(const __termina_event_t * const __ev,
                                          PUSService9 * const self) {
    
    #line 52 "src/service_libraries/pus_services/pus_service9.fin"
    __status_int32_t status;
    #line 52 "src/service_libraries/pus_services/pus_service9.fin"
    status.__variant = Success;

    #line 54 "src/service_libraries/pus_services/pus_service9.fin"
    self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      &status);

    #line 60 "src/service_libraries/pus_services/pus_service9.fin"
    if (status.__variant == Success) {
        
        #line 62 "src/service_libraries/pus_services/pus_service9.fin"
        self->obt_manager.set_obt(__ev, self->obt_manager.__that,
                                  self->exec_tc_req_status_update.next_OBT);

        #line 64 "src/service_libraries/pus_services/pus_service9.fin"
        self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

    }

    #line 72 "src/service_libraries/pus_services/pus_service9.fin"
    return status;

}

void PUSService9__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandler * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 85 "src/service_libraries/pus_services/pus_service9.fin"
    PUSService9 * self = (PUSService9 *)__this;

    #line 85 "src/service_libraries/pus_services/pus_service9.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 87 "src/service_libraries/pus_services/pus_service9.fin"
    __status_int32_t status;
    #line 87 "src/service_libraries/pus_services/pus_service9.fin"
    status.__variant = Success;

    #line 88 "src/service_libraries/pus_services/pus_service9.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 90 "src/service_libraries/pus_services/pus_service9.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 91 "src/service_libraries/pus_services/pus_service9.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 92 "src/service_libraries/pus_services/pus_service9.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 93 "src/service_libraries/pus_services/pus_service9.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 95 "src/service_libraries/pus_services/pus_service9.fin"
    status = tc_handler_get_u32_appdata_field(tc_handler,
                                              &self->exec_tc_req_status_update.next_OBT.seconds);

    #line 97 "src/service_libraries/pus_services/pus_service9.fin"
    if (status.__variant == Success) {
        
        #line 98 "src/service_libraries/pus_services/pus_service9.fin"
        status = tc_handler_get_u16_appdata_field(tc_handler,
                                                  &self->exec_tc_req_status_update.next_OBT.finetime);

    }

    #line 101 "src/service_libraries/pus_services/pus_service9.fin"
    if (status.__variant == Success) {
        
        #line 103 "src/service_libraries/pus_services/pus_service9.fin"
        if (subtype == 129U) {
            
            #line 105 "src/service_libraries/pus_services/pus_service9.fin"
            status = PUSService9__exec9_129TC(__ev, self);

        } else
        {
            
            #line 109 "src/service_libraries/pus_services/pus_service9.fin"
            status.__variant = Failure;
            #line 109 "src/service_libraries/pus_services/pus_service9.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 117 "src/service_libraries/pus_services/pus_service9.fin"
    if (status.__variant == Success) {
        
        #line 119 "src/service_libraries/pus_services/pus_service9.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 115 "src/service_libraries/pus_services/pus_service9.fin"
        int32_t error_code = status.Failure.__0;

        #line 124 "src/service_libraries/pus_services/pus_service9.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 126 "src/service_libraries/pus_services/pus_service9.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                action_status);

        } else
        #line 131 "src/service_libraries/pus_services/pus_service9.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 133 "src/service_libraries/pus_services/pus_service9.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    action_status);

        } else
        #line 138 "src/service_libraries/pus_services/pus_service9.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 140 "src/service_libraries/pus_services/pus_service9.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_num_bytes,
                                                              action_status);

        } else
        {
            
            #line 148 "src/service_libraries/pus_services/pus_service9.fin"
            (*action_status).__variant = Failure;
            #line 148 "src/service_libraries/pus_services/pus_service9.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 155 "src/service_libraries/pus_services/pus_service9.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 155 "src/service_libraries/pus_services/pus_service9.fin"
    return;

}
