#ifndef __SERVICE_LIBRARIES__EVENT_LIST_H__
#define __SERVICE_LIBRARIES__EVENT_LIST_H__

#include <termina.h>

#include "option.h"

extern const size_t event_aux_data_max_size;

extern const size_t max_num_events;

typedef enum {
    ListResult__Success,
    ListResult__ListFull
} __enum_ListResult_t;

typedef struct {
    __enum_ListResult_t __variant;
} ListResult;

typedef struct {
    uint16_t ev_RID;
    uint8_t ev_aux_data[event_aux_data_max_size];
    size_t ev_aux_data_size;
} EventInfo;

typedef struct {
    EventInfo events[max_num_events];
    size_t num_events;
} EventList;

_Bool is_list_full(const EventList * const list);

_Bool is_list_empty(const EventList * const list);

ListResult add_event(EventList * const list, EventInfo new_event);

void extract_event(EventList * const list,
                   __option_EventInfo_t * const ext_event);

void get_event_info(const EventList * const list, size_t index,
                    EventInfo * const event);

void clear_ev_list(EventList * const list);

#endif
