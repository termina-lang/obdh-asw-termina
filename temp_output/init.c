
#include <termina.h>

#include "app.h"

#include "handlers/uart_irq_handler.h"

#include "resources/system_data_pool.h"

#include "resources/uart.h"

#include "service_libraries/event_list.h"

#include "service_libraries/pus_services/pus_service1/pus_service1.h"

#include "service_libraries/pus_services/pus_service1/pus_service1_help.h"

#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

#include "service_libraries/pus_services/pus_service128.h"

#include "service_libraries/pus_services/pus_service19.h"

#include "service_libraries/pus_services/pus_service2.h"

#include "service_libraries/pus_services/pus_service3.h"

#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

#include "service_libraries/pus_services/pus_service9.h"

#include "service_libraries/queue_u8.h"

#include "service_libraries/tc_ccsds_pus_format.h"

#include "tasks/hk_fdir_mng/hk_fdir.h"

void __termina_app__init_globals() {
    
    hk_fdir_timer.period.tv_sec = 1U;
    hk_fdir_timer.period.tv_usec = 0U;
    for (size_t __i0 = 0U; __i0 < sdp_num_params; __i0 = __i0 + 1U) {
        system_data_pool.values[__i0] = 0U;
    }
    uart_drv.registers = (volatile UARTRegs *)4227862528U;
    uart_drv.rem_bytes = 0;
    for (size_t __i0 = 0U; __i0 < queue_max_noe; __i0 = __i0 + 1U) {
        uart_drv.uart_queue.elements[__i0] = 0U;
    }
    uart_drv.uart_queue.head_index = 0U;
    uart_drv.uart_queue.num_elements = 0U;
    telemetry_channel.a_tm_descriptor_pool = &tm_pool;
    telemetry_channel.uart.__that = &uart_drv;
    telemetry_channel.uart.send = UARTDriver__send;
    telemetry_counter.tm_count = 0U;
    pus_service_3.a_tm_descriptor_pool = &tm_pool;
    pus_service_3.hk_config_table[0U].SID = 0U;
    pus_service_3.hk_config_table[0U].enabled = 1;
    pus_service_3.hk_config_table[0U].interval = 2U;
    pus_service_3.hk_config_table[0U].interval_control = 0U;
    pus_service_3.hk_config_table[0U].num_params = 5U;
    pus_service_3.hk_config_table[0U].params_def[0U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[1U] = 1U;
    pus_service_3.hk_config_table[0U].params_def[2U] = 2U;
    pus_service_3.hk_config_table[0U].params_def[3U] = 3U;
    pus_service_3.hk_config_table[0U].params_def[4U] = 4U;
    pus_service_3.hk_config_table[0U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[0U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[1U].SID = 10U;
    pus_service_3.hk_config_table[1U].enabled = 0;
    pus_service_3.hk_config_table[1U].interval = 30U;
    pus_service_3.hk_config_table[1U].interval_control = 0U;
    pus_service_3.hk_config_table[1U].num_params = 3U;
    pus_service_3.hk_config_table[1U].params_def[0U] = 5U;
    pus_service_3.hk_config_table[1U].params_def[1U] = 6U;
    pus_service_3.hk_config_table[1U].params_def[2U] = 7U;
    pus_service_3.hk_config_table[1U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[1U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[2U].SID = 11U;
    pus_service_3.hk_config_table[2U].enabled = 0;
    pus_service_3.hk_config_table[2U].interval = 60U;
    pus_service_3.hk_config_table[2U].interval_control = 0U;
    pus_service_3.hk_config_table[2U].num_params = 3U;
    pus_service_3.hk_config_table[2U].params_def[0U] = 8U;
    pus_service_3.hk_config_table[2U].params_def[1U] = 9U;
    pus_service_3.hk_config_table[2U].params_def[2U] = 10U;
    pus_service_3.hk_config_table[2U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[2U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[3U].SID = 0U;
    pus_service_3.hk_config_table[3U].enabled = 0;
    pus_service_3.hk_config_table[3U].interval = 0U;
    pus_service_3.hk_config_table[3U].interval_control = 0U;
    pus_service_3.hk_config_table[3U].num_params = 0U;
    pus_service_3.hk_config_table[3U].params_def[0U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[1U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[2U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[3U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[4U].SID = 0U;
    pus_service_3.hk_config_table[4U].enabled = 0;
    pus_service_3.hk_config_table[4U].interval = 0U;
    pus_service_3.hk_config_table[4U].interval_control = 0U;
    pus_service_3.hk_config_table[4U].num_params = 0U;
    pus_service_3.hk_config_table[4U].params_def[0U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[1U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[2U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[4U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[5U].SID = 0U;
    pus_service_3.hk_config_table[5U].enabled = 0;
    pus_service_3.hk_config_table[5U].interval = 0U;
    pus_service_3.hk_config_table[5U].interval_control = 0U;
    pus_service_3.hk_config_table[5U].num_params = 0U;
    pus_service_3.hk_config_table[5U].params_def[0U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[1U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[2U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[5U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[6U].SID = 0U;
    pus_service_3.hk_config_table[6U].enabled = 0;
    pus_service_3.hk_config_table[6U].interval = 0U;
    pus_service_3.hk_config_table[6U].interval_control = 0U;
    pus_service_3.hk_config_table[6U].num_params = 0U;
    pus_service_3.hk_config_table[6U].params_def[0U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[1U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[2U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[6U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[7U].SID = 0U;
    pus_service_3.hk_config_table[7U].enabled = 0;
    pus_service_3.hk_config_table[7U].interval = 0U;
    pus_service_3.hk_config_table[7U].interval_control = 0U;
    pus_service_3.hk_config_table[7U].num_params = 0U;
    pus_service_3.hk_config_table[7U].params_def[0U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[1U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[2U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[3U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[4U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[5U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[6U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[7U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[8U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[9U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[10U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[11U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[12U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[13U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[14U] = 0U;
    pus_service_3.hk_config_table[7U].params_def[15U] = 0U;
    pus_service_3.system_data_pool = system_data_pool;
    pus_service_3.tm_channel.__that = &telemetry_channel;
    pus_service_3.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_3.tm_counter.__that = &telemetry_counter;
    pus_service_3.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_5.RID_enable_config[0U] = 0x7U;
    pus_service_5.RID_enable_config[1U] = 0xFU;
    pus_service_5.RID_enable_config[2U] = 0x0U;
    pus_service_5.RID_enable_config[3U] = 0xFFFFU;
    pus_service_5.a_tm_descriptor_pool = &tm_pool;
    pus_service_5.tm_channel.__that = &telemetry_channel;
    pus_service_5.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_5.tm_counter.__that = &telemetry_counter;
    pus_service_5.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_12.a_tm_descriptor_pool = &tm_pool;
    for (size_t __i0 = 0U; __i0 < max_num_pmon_ids; __i0 = __i0 + 1U) {
        pus_service_12.param_limit_check_definition[__i0].high_limit = 0U;
        pus_service_12.param_limit_check_definition[__i0].high_limit_rid = 0U;
        pus_service_12.param_limit_check_definition[__i0].low_limit = 0U;
        pus_service_12.param_limit_check_definition[__i0].low_limit_rid = 0U;
    }
    for (size_t __i0 = 0U; __i0 < max_num_pmon_ids; __i0 = __i0 + 1U) {
        pus_service_12.param_mon_config_table[__i0].PID = 0U;
        pus_service_12.param_mon_config_table[__i0].enabled = 0;
        pus_service_12.param_mon_config_table[__i0].interval = 1U;
        pus_service_12.param_mon_config_table[__i0].interval_control = 0U;
        pus_service_12.param_mon_config_table[__i0].prev_state.__variant = CheckState__MonitorUnselected;
        pus_service_12.param_mon_config_table[__i0].state.__variant = CheckState__MonitorUnselected;
        pus_service_12.param_mon_config_table[__i0].transitionY2K.tv_sec = 1U;
        pus_service_12.param_mon_config_table[__i0].transitionY2K.tv_usec = 0U;
    }
    pus_service_12.system_data_pool = system_data_pool;
    pus_service_12.tm_channel.__that = &telemetry_channel;
    pus_service_12.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_12.tm_counter.__that = &telemetry_counter;
    pus_service_12.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_19.a_tm_descriptor_pool = &tm_pool;
    for (size_t __i0 = 0U; __i0 < max_event_action_definitions; __i0 = __i0 + 1U) {
        pus_service_19.event_action_config[__i0].enabled = 0;
        pus_service_19.event_action_config[__i0].event_ID = 0U;
    }
    for (size_t __i0 = 0U; __i0 < max_event_action_definitions; __i0 = __i0 + 1U) {
        for (size_t __i1 = 0U; __i1 < max_tc_size; __i1 = __i1 + 1U) {
            pus_service_19.event_action_packets[__i0].tc_bytes[__i1] = 0U;
        }
        pus_service_19.event_action_packets[__i0].tc_num_bytes = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_head[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_number[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        for (size_t __i1 = 0U; __i1 < max_tc_size; __i1 = __i1 + 1U) {
            pus_service_19.pending_action_queue_1I[__i0].tc_bytes[__i1] = 0U;
        }
        pus_service_19.pending_action_queue_1I[__i0].tc_num_bytes = 0U;
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        for (size_t __i1 = 0U; __i1 < max_tc_size; __i1 = __i1 + 1U) {
            pus_service_19.pending_action_queue_2LS[__i0].tc_bytes[__i1] = 0U;
        }
        pus_service_19.pending_action_queue_2LS[__i0].tc_num_bytes = 0U;
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        for (size_t __i1 = 0U; __i1 < max_tc_size; __i1 = __i1 + 1U) {
            pus_service_19.pending_action_queue_3MS[__i0].tc_bytes[__i1] = 0U;
        }
        pus_service_19.pending_action_queue_3MS[__i0].tc_num_bytes = 0U;
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        for (size_t __i1 = 0U; __i1 < max_tc_size; __i1 = __i1 + 1U) {
            pus_service_19.pending_action_queue_4HS[__i0].tc_bytes[__i1] = 0U;
        }
        pus_service_19.pending_action_queue_4HS[__i0].tc_num_bytes = 0U;
    }
    pus_service_19.pus_service_5.__that = &pus_service_5;
    pus_service_19.pus_service_5.build_event_list_tms = PUSService5__build_event_list_tms;
    pus_service_19.pus_service_5.exec5_5TC = PUSService5__exec5_5TC;
    pus_service_19.pus_service_5.exec5_6TC = PUSService5__exec5_6TC;
    pus_service_19.pus_service_5.is_RID_enabled_ext = PUSService5__is_RID_enabled_ext;
    pus_service_19.tm_channel.__that = &telemetry_channel;
    pus_service_19.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_19.tm_counter.__that = &telemetry_counter;
    pus_service_19.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_20.a_tm_descriptor_pool = &tm_pool;
    pus_service_20.system_data_pool = system_data_pool;
    pus_service_20.tm_channel.__that = &telemetry_channel;
    pus_service_20.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_20.tm_counter.__that = &telemetry_counter;
    pus_service_20.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_17.a_tm_descriptor_pool = &tm_pool;
    pus_service_17.tm_channel.__that = &telemetry_channel;
    pus_service_17.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_17.tm_counter.__that = &telemetry_counter;
    pus_service_17.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    mng_tc_executor.a_tm_descriptor_pool = &tm_pool;
    mng_tc_executor.pus_service_17.__that = &pus_service_17;
    mng_tc_executor.pus_service_17.exec17_1TC = PUSService17__exec17_1TC;
    mng_tc_executor.tm_channel.__that = &telemetry_channel;
    mng_tc_executor.tm_channel.send_tm = TMChannel__send_tm;
    mng_tc_executor.tm_counter.__that = &telemetry_counter;
    mng_tc_executor.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    init.system_data_pool = system_data_pool;
    init.uart.__that = &uart_drv;
    init.uart.initialize = UARTDriver__initialize;
    uart_hdlr.byte_message_queue_output = &byte_message_queue;
    uart_hdlr.uart.__that = &uart_drv;
    uart_hdlr.uart.release_tx = UARTDriver__release_tx;
    uart_hdlr.uart_registers = (volatile UARTRegs *)4227862528U;
    tc_rx_bottom_half_task.RX_tc_length[0U] = 0U;
    tc_rx_bottom_half_task.RX_tc_length[1U] = 0U;
    tc_rx_bottom_half_task.a_tc_descriptor_pool = &tc_pool;
    tc_rx_bottom_half_task.aux_index = 0U;
    tc_rx_bottom_half_task.rx_status.__variant = RXStatus__SyncBytesRx;
    tc_rx_bottom_half_task.sync_word[0U] = 0xBEU;
    tc_rx_bottom_half_task.sync_word[1U] = 0xBAU;
    tc_rx_bottom_half_task.sync_word[2U] = 0xBEU;
    tc_rx_bottom_half_task.sync_word[3U] = 0xEFU;
    tc_rx_bottom_half_task.tc_message_queue_output = &tc_message_queue;
    for (size_t __i0 = 0U; __i0 < max_tc_size; __i0 = __i0 + 1U) {
        tc_rx_bottom_half_task.telecommand.tc_bytes[__i0] = 0U;
    }
    tc_rx_bottom_half_task.telecommand.tc_num_bytes = 0U;
    icu_manager.a_tc_descriptor_pool = &tc_pool;
    icu_manager.bkg_message_queue_output = &bkg_message_queue;
    icu_manager.hkfdir_message_queue_output = &hkfdir_message_queue;
    icu_manager.tc_executor.__that = &mng_tc_executor;
    icu_manager.tc_executor.PUS_prio_exec_tc = ManagerTCExecutor__PUS_prio_exec_tc;
    icu_manager.tc_executor.mng_tc_acceptation = ManagerTCExecutor__mng_tc_acceptation;
    icu_manager.tc_executor.mng_tc_rejection = ManagerTCExecutor__mng_tc_rejection;
    hk_fdir.a_tc_descriptor_pool = &tc_pool;
    hk_fdir.action_tc_message_queue_output = &action_tc_message_queue;
    hk_fdir.pus_service_12.__that = &pus_service_12;
    hk_fdir.pus_service_12.do_monitoring = PUSService12__do_monitoring;
    hk_fdir.pus_service_12.exec12_1TC = PUSService12__exec12_1TC;
    hk_fdir.pus_service_12.exec12_2TC = PUSService12__exec12_2TC;
    hk_fdir.pus_service_12.exec12_5TC = PUSService12__exec12_5TC;
    hk_fdir.pus_service_19.__that = &pus_service_19;
    hk_fdir.pus_service_19.exec19_1TC = PUSService19__exec19_1TC;
    hk_fdir.pus_service_19.exec19_2TC = PUSService19__exec19_2TC;
    hk_fdir.pus_service_19.exec19_4TC = PUSService19__exec19_4TC;
    hk_fdir.pus_service_19.exec19_5TC = PUSService19__exec19_5TC;
    hk_fdir.pus_service_19.manage_event_actions = PUSService19__manage_event_actions;
    hk_fdir.pus_service_19.get_pending_action_number = PUSService19__get_pending_action_number;
    hk_fdir.pus_service_19.extract_action = PUSService19__extract_action;
    hk_fdir.pus_service_3.__that = &pus_service_3;
    hk_fdir.pus_service_3.do_hk = PUSService3__do_hk;
    hk_fdir.pus_service_3.exec3_5TC = PUSService3__exec3_5TC;
    hk_fdir.pus_service_3.exec3_6TC = PUSService3__exec3_6TC;
    hk_fdir.pus_service_3.exec3_31TC = PUSService3__exec3_31TC;
    hk_fdir.pus_service_5.__that = &pus_service_5;
    hk_fdir.pus_service_5.build_event_list_tms = PUSService5__build_event_list_tms;
    hk_fdir.pus_service_5.exec5_5TC = PUSService5__exec5_5TC;
    hk_fdir.pus_service_5.exec5_6TC = PUSService5__exec5_6TC;
    hk_fdir.pus_service_5.is_RID_enabled_ext = PUSService5__is_RID_enabled_ext;
    pus_bkg_tc_executor.a_tc_descriptor_pool = &tc_pool;
    pus_bkg_tc_executor.pus_service_20.__that = &pus_service_20;
    pus_bkg_tc_executor.pus_service_20.exec20_1TC = PUSService20__exec20_1TC;
    pus_bkg_tc_executor.pus_service_20.exec20_3TC = PUSService20__exec20_3TC;

    return;

}
