
#include "service_libraries/event_list.h"

const size_t event_aux_data_max_size = 64U;

const size_t max_num_events = 16U;

_Bool is_list_full(const EventList * const list) {
    
    _Bool list_is_full = list->num_events == max_num_events;

    return list_is_full;

}

_Bool is_list_empty(const EventList * const list) {
    
    _Bool list_is_empty = list->num_events == 0U;

    return list_is_empty;

}

ListResult add_event(EventList * const list, EventInfo new_event) {
    
    _Bool full = is_list_full(&*list);

    ListResult result;
    result.__variant = ListResult__Success;

    if (0 == full) {
        
        list->events[__termina_array__index(max_num_events,
                                            list->num_events)].ev_RID = new_event.ev_RID;

        list->num_events = list->num_events + 1U;

        if (new_event.ev_aux_data_size > event_aux_data_max_size) {
            
            list->events[__termina_array__index(max_num_events,
                                                list->num_events)].ev_aux_data_size = event_aux_data_max_size;

        } else {
            
            list->events[__termina_array__index(max_num_events,
                                                list->num_events)].ev_aux_data_size = new_event.ev_aux_data_size;

        }

        for (size_t i = 0U; i < event_aux_data_max_size && i < list->events[__termina_array__index(max_num_events,
                                                                                                   list->num_events)].ev_aux_data_size; i = i + 1U) {
            
            list->events[__termina_array__index(max_num_events,
                                                list->num_events)].ev_aux_data[__termina_array__index(event_aux_data_max_size,
                                                                                                      i)] = new_event.ev_aux_data[__termina_array__index(event_aux_data_max_size,
                                                                                                                                                         i)];

        }

    } else {
        
        result.__variant = ListResult__ListFull;

    }

    return result;

}

void extract_event(EventList * const list,
                   __option_EventInfo_t * const ext_event) {
    
    _Bool empty = is_list_empty(&*list);

    if (0 == empty) {
        
        EventInfo event = list->events[0U];

        (*ext_event).__variant = Some;
        (*ext_event).Some.__0 = event;

        for (size_t i = 0U; i < max_num_events && i < list->num_events; i = i + 1U) {
            
            list->events[__termina_array__index(max_num_events,
                                                i)] = list->events[__termina_array__index(max_num_events,
                                                                                          i + 1U)];

        }

        list->num_events = list->num_events - 1U;

    } else {
        
        (*ext_event).__variant = None;

    }

    return;

}

void get_event_info(const EventList * const list, size_t index,
                    EventInfo * const event) {
    
    if (index < list->num_events) {
        
        *event = list->events[__termina_array__index(max_num_events, index)];

    }

    return;

}

void clear_ev_list(EventList * const list) {
    
    list->num_events = 0U;

    return;

}
