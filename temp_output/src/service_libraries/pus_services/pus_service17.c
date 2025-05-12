
#include "service_libraries/pus_services/pus_service17.h"

void PUSService17__build_tm_17_2(const PUSService17 * const self,
                                 TMHandlerT * const p_tm_handler,
                                 uint16_t tm_seq_counter) {
    
    startup_tm(p_tm_handler);

    MissionObt current_obt;
    current_obt.finetime = 0U;
    current_obt.seconds = 0U;

    self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                        &current_obt);

    close_tm(p_tm_handler, 17U, 2U, tm_seq_counter, current_obt);

    return;

}

PSExecTCReqStatus PUSService17__exec17_1TC(PUSService17 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Exit;

    MyResult result;
    result.__variant = MyResult__Ok;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        PUSService17__build_tm_17_2(self, (TMHandlerT *)b_tm_handler.data,
                                    tm_count);

        self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                 &result);

        if (result.__variant == MyResult__Error) {
            
            next_status.__variant = PSExecTCReqStatus__Failure;
            next_status.Failure.__0 = TM_SEND_FAILURE;

        }

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Failure;
        next_status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    return next_status;

}

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 3U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 1U) {
                
                self->exec_tc_req_status = PUSService17__exec17_1TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;
                self->exec_tc_req_status.Error.__0 = ACCEPTANCE_ERROR;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            int32_t error_code = self->exec_tc_req_status.Error.__0;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

            if (error_code == ACCEPTANCE_ERROR) {
                

            } else if (error_code == BUILD_TM_ERROR) {
                

            } else {
                

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Failure) {
            
            int32_t failure_code = self->exec_tc_req_status.Failure.__0;

            (*action_status).__variant = Failure;
            (*action_status).Failure.__0 = failure_code;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__Init;

    }

    return;

}

void PUSService17__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    PUSService17 * self = (PUSService17 *)__this;

    int32_t __status = 0L;

    __termina_mutex__lock(self->__mutex_id, &__status);
    PUSService17__exec_tc(self, tc_handler, action_status);
    __termina_mutex__unlock(self->__mutex_id, &__status);

}

void PUSService17__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      __status_int32_t * const action_status) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService17__exec_tc(__this, tc_handler, action_status);
    __termina_task__unlock(lock);

}

void PUSService17__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       __status_int32_t * const action_status) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService17__exec_tc(__this, tc_handler, action_status);
    __termina_event__unlock(lock);

}
