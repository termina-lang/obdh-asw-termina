
#include "tasks/hk_fdir_mng/hk_fdir.h"

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

    size_t pending_actions[4];
    for (size_t __i0 = 0; __i0 < 4; __i0 = __i0 + 1) {
        pending_actions[__i0] = 0;
    }

    (self->pus_service_19.get_pending_action_number)(self->pus_service_19.__that,
                                                     pending_actions);

    size_t n = 4;

    if (pending_actions[3] > 0) {
        
        n = 3;

    } else if (pending_actions[2] > 0) {
        
        n = 2;

    } else if (pending_actions[1] > 0) {
        
        n = 1;

    } else if (pending_actions[0] > 0) {
        
        n = 0;

    } else {
        

    }

    if (n < 4) {
        
        __option_box_t tc_descriptor;
        tc_descriptor.__variant = None;

        __termina_pool__alloc(self->a_tc_descriptor_pool, &tc_descriptor);

        if (tc_descriptor.__variant == Some) {
            
            __termina_box_t descriptor = tc_descriptor.Some.__0;

            (self->pus_service_19.extract_action)(self->pus_service_19.__that,
                                                  n,
                                                  (TCDescriptorT *)descriptor.data);

            __termina_msg_queue__send(self->action_tc_message_queue_output,
                                      (void *)&descriptor);

        } else {
            

        }

    } else {
        

    }

    return res;

}

Result HouseKeepingFDIR__exec_tc(HouseKeepingFDIR * const self,
                                 __termina_box_t tc_descriptor) {
    
    Result res;
    res.__variant = Result__Ok;

    uint8_t tc_type = get_type((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

    uint8_t subtype = get_subtype((*(TCDescriptorT *)tc_descriptor.data).tc_bytes);

    if (tc_type == 3) {
        
        if (subtype == 5) {
            
            (self->pus_service_3.exec3_5TC)(self->pus_service_3.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else if (subtype == 6) {
            
            (self->pus_service_3.exec3_6TC)(self->pus_service_3.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else if (subtype == 31) {
            
            (self->pus_service_3.exec3_31TC)(self->pus_service_3.__that,
                                             (TCDescriptorT *)tc_descriptor.data,
                                             &res);

        } else {
            

        }

    } else if (tc_type == 5) {
        
        if (subtype == 5) {
            
            (self->pus_service_5.exec5_5TC)(self->pus_service_5.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else if (subtype == 6) {
            
            (self->pus_service_5.exec5_6TC)(self->pus_service_5.__that,
                                            (TCDescriptorT *)tc_descriptor.data,
                                            &res);

        } else {
            

        }

    } else if (tc_type == 12) {
        
        if (subtype == 1) {
            
            (self->pus_service_12.exec12_1TC)(self->pus_service_12.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 2) {
            
            (self->pus_service_12.exec12_2TC)(self->pus_service_12.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 5) {
            
            (self->pus_service_12.exec12_5TC)(self->pus_service_12.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else {
            

        }

    } else if (tc_type == 19) {
        
        if (subtype == 1) {
            
            (self->pus_service_19.exec19_1TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 2) {
            
            (self->pus_service_19.exec19_2TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 4) {
            
            (self->pus_service_19.exec19_4TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else if (subtype == 5) {
            
            (self->pus_service_19.exec19_5TC)(self->pus_service_19.__that,
                                              (TCDescriptorT *)tc_descriptor.data,
                                              &res);

        } else {
            

        }

    } else {
        

    }

    __termina_pool__free(self->a_tc_descriptor_pool, tc_descriptor);

    return res;

}
