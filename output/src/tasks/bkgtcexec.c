
#include "tasks/bkgtcexec.h"

void PUSBKGTCExecutor__manage_error_in_acceptance(const PUSBKGTCExecutor * const self,
                                                  const TCHandlerT * const tc_handler,
                                                  __status_int32_t * const ret) {
    
    #line 56 "src/tasks/bkgtcexec.fin"
    MyResult result;
    #line 56 "src/tasks/bkgtcexec.fin"
    result.__variant = MyResult__Ok;

    #line 58 "src/tasks/bkgtcexec.fin"
    MissionObt current_obt;
    #line 58 "src/tasks/bkgtcexec.fin"
    current_obt.finetime = 0U;
    #line 58 "src/tasks/bkgtcexec.fin"
    current_obt.seconds = 0U;

    #line 60 "src/tasks/bkgtcexec.fin"
    __option_box_t tm_handler;
    #line 60 "src/tasks/bkgtcexec.fin"
    tm_handler.__variant = None;

    #line 61 "src/tasks/bkgtcexec.fin"
    self->a_tm_handler_pool.alloc(self->a_tm_handler_pool.__that, &tm_handler);

    #line 65 "src/tasks/bkgtcexec.fin"
    if (tm_handler.__variant == Some) {
        
        #line 63 "src/tasks/bkgtcexec.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 67 "src/tasks/bkgtcexec.fin"
        uint16_t tm_count = 0U;

        #line 68 "src/tasks/bkgtcexec.fin"
        self->tm_counter.get_next_tm_count(self->tm_counter.__that, &tm_count);

        #line 70 "src/tasks/bkgtcexec.fin"
        self->pus_service_9.get_current_obt(self->pus_service_9.__that,
                                            &current_obt);

        #line 71 "src/tasks/bkgtcexec.fin"
        build_tm_1_4_error_in_acceptance((TMHandlerT *)b_tm_handler.data,
                                         tm_count,
                                         tc_handler->packet_header.packet_id,
                                         tc_handler->packet_error_ctrl,
                                         current_obt, &result);

        #line 74 "src/tasks/bkgtcexec.fin"
        if (result.__variant == MyResult__Ok) {
            
            #line 76 "src/tasks/bkgtcexec.fin"
            self->tm_channel.send_tm(self->tm_channel.__that, b_tm_handler,
                                     &result);

        } else
        {
            
            #line 79 "src/tasks/bkgtcexec.fin"
            self->a_tm_handler_pool.free(self->a_tm_handler_pool.__that,
                                         b_tm_handler);

        }

    } else
    {
        
        #line 85 "src/tasks/bkgtcexec.fin"
        (*ret).__variant = Failure;
        #line 85 "src/tasks/bkgtcexec.fin"
        (*ret).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 90 "src/tasks/bkgtcexec.fin"
    return;

}

__status_int32_t PUSBKGTCExecutor__exec_tc(void * const __this,
                                           __termina_box_t tc_handler) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)__this;

    #line 106 "src/tasks/bkgtcexec.fin"
    __status_int32_t res;
    #line 106 "src/tasks/bkgtcexec.fin"
    res.__variant = Success;

    #line 108 "src/tasks/bkgtcexec.fin"
    uint8_t tc_type = get_type((*(TCHandlerT *)tc_handler.data).tc_descriptor.tc_bytes);

    #line 110 "src/tasks/bkgtcexec.fin"
    if (tc_type == 20U) {
        
        #line 112 "src/tasks/bkgtcexec.fin"
        self->pus_service_20.exec_tc(self->pus_service_20.__that,
                                     (TCHandlerT *)tc_handler.data, &res);

    } else
    {
        
        #line 116 "src/tasks/bkgtcexec.fin"
        PUSBKGTCExecutor__manage_error_in_acceptance(self,
                                                     (TCHandlerT *)tc_handler.data,
                                                     &res);

    }

    #line 120 "src/tasks/bkgtcexec.fin"
    self->a_tc_handler_pool.free(self->a_tc_handler_pool.__that, tc_handler);

    #line 122 "src/tasks/bkgtcexec.fin"
    return res;

}

void __PUSBKGTCExecutor__termina_task(void * arg) {
    
    PUSBKGTCExecutor * self = (PUSBKGTCExecutor *)arg;

    int32_t status = 0L;

    uint32_t next_msg = 0U;

    __status_int32_t result;
    result.__variant = Success;

    __termina_box_t exec_tc__msg_data;

    for (;;) {
        
        __termina_msg_queue__recv(self->__task_msg_queue_id, &next_msg,
                                  &status);

        if (status != 0L) {
            break;
        }

        switch (next_msg) {
            
            case __PUSBKGTCExecutor__bkg_message_queue_input:

                __termina_msg_queue__recv(self->bkg_message_queue_input,
                                          (void *)&exec_tc__msg_data, &status);

                if (status != 0L) {
                    __termina_except__msg_queue_recv_error(self->bkg_message_queue_input,
                                                           status);
                }

                result = PUSBKGTCExecutor__exec_tc(self, exec_tc__msg_data);

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
