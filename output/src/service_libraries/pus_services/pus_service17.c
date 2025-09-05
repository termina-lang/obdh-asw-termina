
#include "service_libraries/pus_services/pus_service17.h"

__status_int32_t PUSService17__exec17_1TC(const __termina_event_t * const __ev,
                                          PUSService17 * const self) {
    
    #line 76 "src/service_libraries/pus_services/pus_service17.fin"
    __status_int32_t status;
    #line 76 "src/service_libraries/pus_services/pus_service17.fin"
    status.__variant = Success;

    #line 78 "src/service_libraries/pus_services/pus_service17.fin"
    self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                      self->exec_tc_req_status_update.packet_id,
                                      self->exec_tc_req_status_update.packet_seq_ctrl,
                                      self->exec_tc_req_status_update.flags_ack,
                                      &status);

    #line 85 "src/service_libraries/pus_services/pus_service17.fin"
    if (status.__variant == Success) {
        
        #line 87 "src/service_libraries/pus_services/pus_service17.fin"
        MissionOBT current_obt;
        #line 87 "src/service_libraries/pus_services/pus_service17.fin"
        current_obt.finetime = 0U;
        #line 87 "src/service_libraries/pus_services/pus_service17.fin"
        current_obt.seconds = 0U;

        #line 88 "src/service_libraries/pus_services/pus_service17.fin"
        uint16_t tm_count = 0U;

        #line 90 "src/service_libraries/pus_services/pus_service17.fin"
        __option_box_t tm_handler;
        #line 90 "src/service_libraries/pus_services/pus_service17.fin"
        tm_handler.__variant = None;

        #line 91 "src/service_libraries/pus_services/pus_service17.fin"
        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        #line 95 "src/service_libraries/pus_services/pus_service17.fin"
        if (tm_handler.__variant == Some) {
            
            #line 93 "src/service_libraries/pus_services/pus_service17.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 97 "src/service_libraries/pus_services/pus_service17.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 98 "src/service_libraries/pus_services/pus_service17.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                              &current_obt);

            #line 99 "src/service_libraries/pus_services/pus_service17.fin"
            build_tm_17_2((TMHandler *)b_tm_handler.data, tm_count,
                          current_obt);

            #line 100 "src/service_libraries/pus_services/pus_service17.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, &status);

        } else
        {
            
            #line 105 "src/service_libraries/pus_services/pus_service17.fin"
            status.__variant = Failure;
            #line 105 "src/service_libraries/pus_services/pus_service17.fin"
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 113 "src/service_libraries/pus_services/pus_service17.fin"
    if (status.__variant == Success) {
        
        #line 115 "src/service_libraries/pus_services/pus_service17.fin"
        self->pus_service_1.notify_tm_1_7(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

    }

    #line 123 "src/service_libraries/pus_services/pus_service17.fin"
    return status;

}

void PUSService17__exec_tc(const __termina_event_t * const __ev,
                           void * const __this, TCHandler * const tc_handler,
                           __status_int32_t * const action_status) {
    
    #line 135 "src/service_libraries/pus_services/pus_service17.fin"
    PUSService17 * self = (PUSService17 *)__this;

    #line 135 "src/service_libraries/pus_services/pus_service17.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 137 "src/service_libraries/pus_services/pus_service17.fin"
    __status_int32_t status;
    #line 137 "src/service_libraries/pus_services/pus_service17.fin"
    status.__variant = Success;

    #line 138 "src/service_libraries/pus_services/pus_service17.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 140 "src/service_libraries/pus_services/pus_service17.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 141 "src/service_libraries/pus_services/pus_service17.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 142 "src/service_libraries/pus_services/pus_service17.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 145 "src/service_libraries/pus_services/pus_service17.fin"
    if (subtype == 1U) {
        
        #line 147 "src/service_libraries/pus_services/pus_service17.fin"
        status = PUSService17__exec17_1TC(__ev, self);

    } else
    {
        
        #line 151 "src/service_libraries/pus_services/pus_service17.fin"
        status.__variant = Failure;
        #line 151 "src/service_libraries/pus_services/pus_service17.fin"
        status.Failure.__0 = ACCEPTANCE_ERROR;

    }

    #line 157 "src/service_libraries/pus_services/pus_service17.fin"
    if (status.__variant == Success) {
        
        #line 159 "src/service_libraries/pus_services/pus_service17.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 155 "src/service_libraries/pus_services/pus_service17.fin"
        int32_t error_code = status.Failure.__0;

        #line 165 "src/service_libraries/pus_services/pus_service17.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 167 "src/service_libraries/pus_services/pus_service17.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                action_status);

        } else
        #line 172 "src/service_libraries/pus_services/pus_service17.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 174 "src/service_libraries/pus_services/pus_service17.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    action_status);

        } else
        {
            
            #line 181 "src/service_libraries/pus_services/pus_service17.fin"
            (*action_status).__variant = Failure;
            #line 181 "src/service_libraries/pus_services/pus_service17.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 188 "src/service_libraries/pus_services/pus_service17.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 188 "src/service_libraries/pus_services/pus_service17.fin"
    return;

}
