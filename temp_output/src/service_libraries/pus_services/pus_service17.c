
#include "service_libraries/pus_services/pus_service17.h"

void build_tm_17_2(TMHandlerT * const p_tm_handler, uint16_t tm_seq_counter,
                   Result * const result) {
    
    startup_tm(p_tm_handler);

    close_tm(p_tm_handler, 17U, 2U, tm_seq_counter, result);

    return;

}

PSExecTCReqStatus PUSService17__exec17_1TC(PUSService17 * const self) {
    
    PSExecTCReqStatus next_status;
    next_status.__variant = PSExecTCReqStatus__Error;

    Result result;
    result.__variant = Result__Ok;

    __option_box_t tm_handler;
    tm_handler.__variant = None;

    (self->a_tm_handler_pool.alloc)(self->a_tm_handler_pool.__that,
                                    &tm_handler);

    if (tm_handler.__variant == Some) {
        
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        uint16_t tm_count = 0U;

        (self->tm_counter.get_next_tm_count)(self->tm_counter.__that,
                                             &tm_count);

        build_tm_17_2((TMHandlerT *)b_tm_handler.data, tm_count, &result);

        (self->tm_channel.send_tm)(self->tm_channel.__that, b_tm_handler,
                                   &result);

    } else {
        
        result.__variant = Result__Error;

    }

    if (result.__variant == Result__Ok) {
        
        next_status.__variant = PSExecTCReqStatus__Exit;

    } else {
        
        next_status.__variant = PSExecTCReqStatus__Error;

    }

    return next_status;

}

void PUSService17__exec_tc(void * const __this, TCHandlerT * const tc_handler,
                           Result * const result) {
    
    PUSService17 * self = (PUSService17 *)__this;

    uint8_t subtype = tc_handler->df_header.subtype;

    for (size_t i = 0U; i < 2U && self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit == 0; i = i + 1U) {
        
        if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Init) {
            

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__ExecTC) {
            
            if (subtype == 1U) {
                
                self->exec_tc_req_status = PUSService17__exec17_1TC(self);

            } else {
                
                self->exec_tc_req_status.__variant = PSExecTCReqStatus__Error;

            }

        } else if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Error) {
            
            (*result).__variant = Result__Error;

            self->exec_tc_req_status.__variant = PSExecTCReqStatus__Exit;

        } else {
            

        }

    }

    if (self->exec_tc_req_status.__variant == PSExecTCReqStatus__Exit) {
        
        self->exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;

    }

    return;

}

void PUSService17__exec_tc__mutex_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result) {
    
    PUSService17 * self = (PUSService17 *)__this;

    Status status;
    status.__variant = Status__Success;

    __termina_mutex__lock(self->__mutex_id, &status);
    PUSService17__exec_tc(self, tc_handler, result);
    __termina_mutex__unlock(self->__mutex_id, &status);

}

void PUSService17__exec_tc__task_lock(void * const __this,
                                      TCHandlerT * const tc_handler,
                                      Result * const result) {
    
    __termina_task_lock_t lock;

    lock = __termina_task__lock();
    PUSService17__exec_tc(__this, tc_handler, result);
    __termina_task__unlock(lock);

}

void PUSService17__exec_tc__event_lock(void * const __this,
                                       TCHandlerT * const tc_handler,
                                       Result * const result) {
    
    __termina_event_lock_t lock;

    lock = __termina_event__lock();
    PUSService17__exec_tc(__this, tc_handler, result);
    __termina_event__unlock(lock);

}
