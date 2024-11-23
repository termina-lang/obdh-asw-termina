
#include "tasks/hk_fdir_mng/hk_fdir.h"

void HouseKeepingFDIR__manage_actions(HouseKeepingFDIR * const self) {
    
    size_t pending_actions[4];
    for (size_t __i0 = 0; __i0 < 4; __i0 = __i0 + 1) {
        pending_actions[__i0] = 0;
    }

    (self->pus_service_19.get_pending_action_number)(self->pus_service_19.__that,
                                                     pending_actions);

    uint8_t n = 0;

    for (size_t i = 0; i < 3 && n < 2; i = i + 1) {
        
        if (pending_actions[3 - i] >= 2) {
            
            __option_box_t tc_descriptor1;
            tc_descriptor1.__variant = None;

            __termina_pool__alloc(self->a_tc_descriptor_pool, &tc_descriptor1);

            if (tc_descriptor1.__variant == Some) {
                
                __termina_box_t descriptor = tc_descriptor1.Some.__0;

                (self->pus_service_19.extract_action)(self->pus_service_19.__that,
                                                      3 - i,
                                                      (TCDescriptorT *)descriptor.data);

                __termina_msg_queue__send(self->action_tc_message_queue_output,
                                          (void *)&descriptor);

                n = n + 1;

            } else {
                

            }

            __option_box_t tc_descriptor2;
            tc_descriptor2.__variant = None;

            __termina_pool__alloc(self->a_tc_descriptor_pool, &tc_descriptor2);

            if (tc_descriptor2.__variant == Some) {
                
                __termina_box_t descriptor = tc_descriptor2.Some.__0;

                (self->pus_service_19.extract_action)(self->pus_service_19.__that,
                                                      3 - i,
                                                      (TCDescriptorT *)descriptor.data);

                __termina_msg_queue__send(self->action_tc_message_queue_output,
                                          (void *)&descriptor);

                n = n + 1;

            } else {
                

            }

        } else if (pending_actions[3 - i] == 1) {
            
            __option_box_t tc_descriptor;
            tc_descriptor.__variant = None;

            __termina_pool__alloc(self->a_tc_descriptor_pool, &tc_descriptor);

            if (tc_descriptor.__variant == Some) {
                
                __termina_box_t descriptor = tc_descriptor.Some.__0;

                (self->pus_service_19.extract_action)(self->pus_service_19.__that,
                                                      3 - i,
                                                      (TCDescriptorT *)descriptor.data);

                __termina_msg_queue__send(self->action_tc_message_queue_output,
                                          (void *)&descriptor);

                n = n + 1;

            } else {
                

            }

        } else {
            

        }

    }

    return;

}

Result HouseKeepingFDIR__do_hk_fdir(HouseKeepingFDIR * const self,
                                    TimeVal _current_time) {
    
    EventList event_list;
    for (size_t __i0 = 0; __i0 < max_num_events; __i0 = __i0 + 1) {
        event_list.events[__i0].ev_RID = 0;
        for (size_t __i1 = 0; __i1 < event_aux_data_max_size; __i1 = __i1 + 1) {
            event_list.events[__i0].ev_aux_data[__i1] = 0;
        }
        event_list.events[__i0].ev_aux_data_size = 0;
    }
    event_list.num_events = 0;

    Result res;
    res.__variant = Result__Ok;

    (self->pus_service_3.do_hk)(self->pus_service_3.__that, &res);

    (self->pus_service_12.do_monitoring)(self->pus_service_12.__that,
                                         &event_list, &res);

    (self->pus_service_5.build_event_list_tms)(self->pus_service_5.__that,
                                               &event_list, &res);

    (self->pus_service_19.manage_event_actions)(self->pus_service_19.__that,
                                                &event_list);

    HouseKeepingFDIR__manage_actions(self);

    return res;

}
