
#include "tasks/bkgtcexec.h"

__status_int32_t PUSBKGTCExecutor__exec_tc(const __termina_event_t * const __ev,
                                           void * const __this,
                                           __termina_box_t tc_handler) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)__this;

    __status_int32_t res;
    res.__variant = Success;

    uint8_t tc_type = get_type((*(TCHandlerT *)tc_handler.data).tc_descriptor.tc_bytes);

    if (tc_type == 20U) {
        
        self->pus_service_20.exec_tc(__ev, self->pus_service_20.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else {
        
        MissionObt current_obt;
        current_obt.finetime = 0U;
        current_obt.seconds = 0U;

        __status_int32_t status;
        status.__variant = Success;

        __option_box_t tm_handler;
        tm_handler.__variant = None;

        self->a_tm_handler_pool.alloc(__ev, self->a_tm_handler_pool.__that,
                                      &tm_handler);

        if (tm_handler.__variant == Some) {
            
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            uint16_t tm_count = 0U;

            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            self->pus_service_9.get_current_obt(__ev,
                                                self->pus_service_9.__that,
                                                &current_obt);

            build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                             tm_count,
                                             (*(TCHandlerT *)tc_handler.data).packet_header.packet_id,
                                             (*(TCHandlerT *)tc_handler.data).packet_error_ctrl,
                                             current_obt, &status);

            if (status.__variant == Success) {
                
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, &status);

            } else {
                
                self->a_tm_handler_pool.free(__ev,
                                             self->a_tm_handler_pool.__that,
                                             b_tm_handler);

            }

        } else {
            
            status.__variant = Failure;
            status.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    self->a_tc_handler_pool.free(__ev, self->a_tc_handler_pool.__that,
                                 tc_handler);

    return res;

}

void __PUSBKGTCExecutor__termina_task(void * arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;

    int32_t status = 0L;

    __termina_event_t event;

    __status_int32_t result;
    result.__variant = Success;

    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &event, &status);

        if (status != 0L) {
            break;
        }

        switch (event.port_id) {
            
            case __PUSBKGTCExecutor__bkg_message_queue_input:

                __termina_msg_queue__recv(self->bkg_message_queue_input,
                                          (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->bkg_message_queue_input,
                                                           status);
                }

                result = PUSBKGTCExecutor__exec_tc(&event, self,
                                                   exec_tc__msg_data);

                if (result.__variant != Success) {
                    
                    ExceptSource source;
                    source.__variant = ExceptSource__Handler;
                    source.Task.__0 = self->__task_id;

                    __termina_except__action_failure(source,
                                                     __PUSBKGTCExecutor__bkg_message_queue_input,
                                                     result.Failure.__0);

                }

                break;

            default:

                __termina_exec__reboot();

                break;

        }

    }

    return;

}
