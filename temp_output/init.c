
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
    
    hk_fdir_timer.period.tv_sec = 1;
    hk_fdir_timer.period.tv_usec = 0;
    for (size_t __i0 = 0; __i0 < sdp_num_params; __i0 = __i0 + 1) {
        system_data_pool.values[__i0] = 0;
    }
    uart_drv.registers = (volatile UARTRegs *)0xFC001000;
    uart_drv.rem_bytes = 0;
    for (size_t __i0 = 0; __i0 < queue_max_noe; __i0 = __i0 + 1) {
        uart_drv.uart_queue.elements[__i0] = 0;
    }
    uart_drv.uart_queue.head_index = 0;
    uart_drv.uart_queue.num_elements = 0;
    telemetry_channel.a_tm_descriptor_pool = &tm_pool;
    telemetry_channel.uart.__that = &uart_drv;
    telemetry_channel.uart.send = UARTDriver__send;
    telemetry_counter.tm_count = 0;
    pus_service_3.a_tm_descriptor_pool = &tm_pool;
    pus_service_3.hk_config_table[0].SID = 0;
    pus_service_3.hk_config_table[0].enabled = 1;
    pus_service_3.hk_config_table[0].interval = 2;
    pus_service_3.hk_config_table[0].interval_control = 0;
    pus_service_3.hk_config_table[0].num_params = 5;
    pus_service_3.hk_config_table[0].params_def[0] = 0;
    pus_service_3.hk_config_table[0].params_def[1] = 1;
    pus_service_3.hk_config_table[0].params_def[2] = 2;
    pus_service_3.hk_config_table[0].params_def[3] = 3;
    pus_service_3.hk_config_table[0].params_def[4] = 4;
    pus_service_3.hk_config_table[0].params_def[5] = 0;
    pus_service_3.hk_config_table[0].params_def[6] = 0;
    pus_service_3.hk_config_table[0].params_def[7] = 0;
    pus_service_3.hk_config_table[0].params_def[8] = 0;
    pus_service_3.hk_config_table[0].params_def[9] = 0;
    pus_service_3.hk_config_table[0].params_def[10] = 0;
    pus_service_3.hk_config_table[0].params_def[11] = 0;
    pus_service_3.hk_config_table[0].params_def[12] = 0;
    pus_service_3.hk_config_table[0].params_def[13] = 0;
    pus_service_3.hk_config_table[0].params_def[14] = 0;
    pus_service_3.hk_config_table[0].params_def[15] = 0;
    pus_service_3.hk_config_table[1].SID = 10;
    pus_service_3.hk_config_table[1].enabled = 0;
    pus_service_3.hk_config_table[1].interval = 30;
    pus_service_3.hk_config_table[1].interval_control = 0;
    pus_service_3.hk_config_table[1].num_params = 3;
    pus_service_3.hk_config_table[1].params_def[0] = 5;
    pus_service_3.hk_config_table[1].params_def[1] = 6;
    pus_service_3.hk_config_table[1].params_def[2] = 7;
    pus_service_3.hk_config_table[1].params_def[3] = 0;
    pus_service_3.hk_config_table[1].params_def[4] = 0;
    pus_service_3.hk_config_table[1].params_def[5] = 0;
    pus_service_3.hk_config_table[1].params_def[6] = 0;
    pus_service_3.hk_config_table[1].params_def[7] = 0;
    pus_service_3.hk_config_table[1].params_def[8] = 0;
    pus_service_3.hk_config_table[1].params_def[9] = 0;
    pus_service_3.hk_config_table[1].params_def[10] = 0;
    pus_service_3.hk_config_table[1].params_def[11] = 0;
    pus_service_3.hk_config_table[1].params_def[12] = 0;
    pus_service_3.hk_config_table[1].params_def[13] = 0;
    pus_service_3.hk_config_table[1].params_def[14] = 0;
    pus_service_3.hk_config_table[1].params_def[15] = 0;
    pus_service_3.hk_config_table[2].SID = 11;
    pus_service_3.hk_config_table[2].enabled = 0;
    pus_service_3.hk_config_table[2].interval = 60;
    pus_service_3.hk_config_table[2].interval_control = 0;
    pus_service_3.hk_config_table[2].num_params = 3;
    pus_service_3.hk_config_table[2].params_def[0] = 8;
    pus_service_3.hk_config_table[2].params_def[1] = 9;
    pus_service_3.hk_config_table[2].params_def[2] = 10;
    pus_service_3.hk_config_table[2].params_def[3] = 0;
    pus_service_3.hk_config_table[2].params_def[4] = 0;
    pus_service_3.hk_config_table[2].params_def[5] = 0;
    pus_service_3.hk_config_table[2].params_def[6] = 0;
    pus_service_3.hk_config_table[2].params_def[7] = 0;
    pus_service_3.hk_config_table[2].params_def[8] = 0;
    pus_service_3.hk_config_table[2].params_def[9] = 0;
    pus_service_3.hk_config_table[2].params_def[10] = 0;
    pus_service_3.hk_config_table[2].params_def[11] = 0;
    pus_service_3.hk_config_table[2].params_def[12] = 0;
    pus_service_3.hk_config_table[2].params_def[13] = 0;
    pus_service_3.hk_config_table[2].params_def[14] = 0;
    pus_service_3.hk_config_table[2].params_def[15] = 0;
    pus_service_3.hk_config_table[3].SID = 0;
    pus_service_3.hk_config_table[3].enabled = 0;
    pus_service_3.hk_config_table[3].interval = 0;
    pus_service_3.hk_config_table[3].interval_control = 0;
    pus_service_3.hk_config_table[3].num_params = 0;
    pus_service_3.hk_config_table[3].params_def[0] = 0;
    pus_service_3.hk_config_table[3].params_def[1] = 0;
    pus_service_3.hk_config_table[3].params_def[2] = 0;
    pus_service_3.hk_config_table[3].params_def[3] = 0;
    pus_service_3.hk_config_table[3].params_def[4] = 0;
    pus_service_3.hk_config_table[3].params_def[5] = 0;
    pus_service_3.hk_config_table[3].params_def[6] = 0;
    pus_service_3.hk_config_table[3].params_def[7] = 0;
    pus_service_3.hk_config_table[3].params_def[8] = 0;
    pus_service_3.hk_config_table[3].params_def[9] = 0;
    pus_service_3.hk_config_table[3].params_def[10] = 0;
    pus_service_3.hk_config_table[3].params_def[11] = 0;
    pus_service_3.hk_config_table[3].params_def[12] = 0;
    pus_service_3.hk_config_table[3].params_def[13] = 0;
    pus_service_3.hk_config_table[3].params_def[14] = 0;
    pus_service_3.hk_config_table[3].params_def[15] = 0;
    pus_service_3.hk_config_table[4].SID = 0;
    pus_service_3.hk_config_table[4].enabled = 0;
    pus_service_3.hk_config_table[4].interval = 0;
    pus_service_3.hk_config_table[4].interval_control = 0;
    pus_service_3.hk_config_table[4].num_params = 0;
    pus_service_3.hk_config_table[4].params_def[0] = 0;
    pus_service_3.hk_config_table[4].params_def[1] = 0;
    pus_service_3.hk_config_table[4].params_def[2] = 0;
    pus_service_3.hk_config_table[4].params_def[3] = 0;
    pus_service_3.hk_config_table[4].params_def[4] = 0;
    pus_service_3.hk_config_table[4].params_def[5] = 0;
    pus_service_3.hk_config_table[4].params_def[6] = 0;
    pus_service_3.hk_config_table[4].params_def[7] = 0;
    pus_service_3.hk_config_table[4].params_def[8] = 0;
    pus_service_3.hk_config_table[4].params_def[9] = 0;
    pus_service_3.hk_config_table[4].params_def[10] = 0;
    pus_service_3.hk_config_table[4].params_def[11] = 0;
    pus_service_3.hk_config_table[4].params_def[12] = 0;
    pus_service_3.hk_config_table[4].params_def[13] = 0;
    pus_service_3.hk_config_table[4].params_def[14] = 0;
    pus_service_3.hk_config_table[4].params_def[15] = 0;
    pus_service_3.hk_config_table[5].SID = 0;
    pus_service_3.hk_config_table[5].enabled = 0;
    pus_service_3.hk_config_table[5].interval = 0;
    pus_service_3.hk_config_table[5].interval_control = 0;
    pus_service_3.hk_config_table[5].num_params = 0;
    pus_service_3.hk_config_table[5].params_def[0] = 0;
    pus_service_3.hk_config_table[5].params_def[1] = 0;
    pus_service_3.hk_config_table[5].params_def[2] = 0;
    pus_service_3.hk_config_table[5].params_def[3] = 0;
    pus_service_3.hk_config_table[5].params_def[4] = 0;
    pus_service_3.hk_config_table[5].params_def[5] = 0;
    pus_service_3.hk_config_table[5].params_def[6] = 0;
    pus_service_3.hk_config_table[5].params_def[7] = 0;
    pus_service_3.hk_config_table[5].params_def[8] = 0;
    pus_service_3.hk_config_table[5].params_def[9] = 0;
    pus_service_3.hk_config_table[5].params_def[10] = 0;
    pus_service_3.hk_config_table[5].params_def[11] = 0;
    pus_service_3.hk_config_table[5].params_def[12] = 0;
    pus_service_3.hk_config_table[5].params_def[13] = 0;
    pus_service_3.hk_config_table[5].params_def[14] = 0;
    pus_service_3.hk_config_table[5].params_def[15] = 0;
    pus_service_3.hk_config_table[6].SID = 0;
    pus_service_3.hk_config_table[6].enabled = 0;
    pus_service_3.hk_config_table[6].interval = 0;
    pus_service_3.hk_config_table[6].interval_control = 0;
    pus_service_3.hk_config_table[6].num_params = 0;
    pus_service_3.hk_config_table[6].params_def[0] = 0;
    pus_service_3.hk_config_table[6].params_def[1] = 0;
    pus_service_3.hk_config_table[6].params_def[2] = 0;
    pus_service_3.hk_config_table[6].params_def[3] = 0;
    pus_service_3.hk_config_table[6].params_def[4] = 0;
    pus_service_3.hk_config_table[6].params_def[5] = 0;
    pus_service_3.hk_config_table[6].params_def[6] = 0;
    pus_service_3.hk_config_table[6].params_def[7] = 0;
    pus_service_3.hk_config_table[6].params_def[8] = 0;
    pus_service_3.hk_config_table[6].params_def[9] = 0;
    pus_service_3.hk_config_table[6].params_def[10] = 0;
    pus_service_3.hk_config_table[6].params_def[11] = 0;
    pus_service_3.hk_config_table[6].params_def[12] = 0;
    pus_service_3.hk_config_table[6].params_def[13] = 0;
    pus_service_3.hk_config_table[6].params_def[14] = 0;
    pus_service_3.hk_config_table[6].params_def[15] = 0;
    pus_service_3.hk_config_table[7].SID = 0;
    pus_service_3.hk_config_table[7].enabled = 0;
    pus_service_3.hk_config_table[7].interval = 0;
    pus_service_3.hk_config_table[7].interval_control = 0;
    pus_service_3.hk_config_table[7].num_params = 0;
    pus_service_3.hk_config_table[7].params_def[0] = 0;
    pus_service_3.hk_config_table[7].params_def[1] = 0;
    pus_service_3.hk_config_table[7].params_def[2] = 0;
    pus_service_3.hk_config_table[7].params_def[3] = 0;
    pus_service_3.hk_config_table[7].params_def[4] = 0;
    pus_service_3.hk_config_table[7].params_def[5] = 0;
    pus_service_3.hk_config_table[7].params_def[6] = 0;
    pus_service_3.hk_config_table[7].params_def[7] = 0;
    pus_service_3.hk_config_table[7].params_def[8] = 0;
    pus_service_3.hk_config_table[7].params_def[9] = 0;
    pus_service_3.hk_config_table[7].params_def[10] = 0;
    pus_service_3.hk_config_table[7].params_def[11] = 0;
    pus_service_3.hk_config_table[7].params_def[12] = 0;
    pus_service_3.hk_config_table[7].params_def[13] = 0;
    pus_service_3.hk_config_table[7].params_def[14] = 0;
    pus_service_3.hk_config_table[7].params_def[15] = 0;
    pus_service_3.system_data_pool = system_data_pool;
    pus_service_3.tm_channel.__that = &telemetry_channel;
    pus_service_3.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_3.tm_counter.__that = &telemetry_counter;
    pus_service_3.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_5.RID_enable_config[0] = 0x7;
    pus_service_5.RID_enable_config[1] = 0xF;
    pus_service_5.RID_enable_config[2] = 0x0;
    pus_service_5.RID_enable_config[3] = 0xFFFF;
    pus_service_5.a_tm_descriptor_pool = &tm_pool;
    pus_service_5.tm_channel.__that = &telemetry_channel;
    pus_service_5.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_5.tm_counter.__that = &telemetry_counter;
    pus_service_5.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_12.a_tm_descriptor_pool = &tm_pool;
    for (size_t __i0 = 0; __i0 < max_num_pmon_ids; __i0 = __i0 + 1) {
        pus_service_12.param_limit_check_definition[__i0].high_limit = 0;
        pus_service_12.param_limit_check_definition[__i0].high_limit_rid = 0;
        pus_service_12.param_limit_check_definition[__i0].low_limit = 0;
        pus_service_12.param_limit_check_definition[__i0].low_limit_rid = 0;
    }
    for (size_t __i0 = 0; __i0 < max_num_pmon_ids; __i0 = __i0 + 1) {
        pus_service_12.param_mon_config_table[__i0].PID = 0;
        pus_service_12.param_mon_config_table[__i0].enabled = 0;
        pus_service_12.param_mon_config_table[__i0].interval = 1;
        pus_service_12.param_mon_config_table[__i0].interval_control = 0;
        pus_service_12.param_mon_config_table[__i0].prev_state.__variant = CheckState__MonitorUnselected;
        pus_service_12.param_mon_config_table[__i0].state.__variant = CheckState__MonitorUnselected;
        pus_service_12.param_mon_config_table[__i0].transitionY2K.tv_sec = 1;
        pus_service_12.param_mon_config_table[__i0].transitionY2K.tv_usec = 0;
    }
    pus_service_12.system_data_pool = system_data_pool;
    pus_service_12.tm_channel.__that = &telemetry_channel;
    pus_service_12.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_12.tm_counter.__that = &telemetry_counter;
    pus_service_12.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_19.a_tm_descriptor_pool = &tm_pool;
    for (size_t __i0 = 0; __i0 < max_event_action_definitions; __i0 = __i0 + 1) {
        pus_service_19.event_action_config[__i0].enabled = 0;
        pus_service_19.event_action_config[__i0].event_ID = 0;
    }
    for (size_t __i0 = 0; __i0 < max_event_action_definitions; __i0 = __i0 + 1) {
        for (size_t __i1 = 0; __i1 < max_tc_size; __i1 = __i1 + 1) {
            pus_service_19.event_action_packets[__i0].tc_bytes[__i1] = 0;
        }
        pus_service_19.event_action_packets[__i0].tc_num_bytes = 0;
    }
    for (size_t __i0 = 0; __i0 < 4; __i0 = __i0 + 1) {
        pus_service_19.pending_action_head[__i0] = 0;
    }
    for (size_t __i0 = 0; __i0 < 4; __i0 = __i0 + 1) {
        pus_service_19.pending_action_number[__i0] = 0;
    }
    for (size_t __i0 = 0; __i0 < event_action_queue_dimension; __i0 = __i0 + 1) {
        for (size_t __i1 = 0; __i1 < max_tc_size; __i1 = __i1 + 1) {
            pus_service_19.pending_action_queue_1I[__i0].tc_bytes[__i1] = 0;
        }
        pus_service_19.pending_action_queue_1I[__i0].tc_num_bytes = 0;
    }
    for (size_t __i0 = 0; __i0 < event_action_queue_dimension; __i0 = __i0 + 1) {
        for (size_t __i1 = 0; __i1 < max_tc_size; __i1 = __i1 + 1) {
            pus_service_19.pending_action_queue_2LS[__i0].tc_bytes[__i1] = 0;
        }
        pus_service_19.pending_action_queue_2LS[__i0].tc_num_bytes = 0;
    }
    for (size_t __i0 = 0; __i0 < event_action_queue_dimension; __i0 = __i0 + 1) {
        for (size_t __i1 = 0; __i1 < max_tc_size; __i1 = __i1 + 1) {
            pus_service_19.pending_action_queue_3MS[__i0].tc_bytes[__i1] = 0;
        }
        pus_service_19.pending_action_queue_3MS[__i0].tc_num_bytes = 0;
    }
    for (size_t __i0 = 0; __i0 < event_action_queue_dimension; __i0 = __i0 + 1) {
        for (size_t __i1 = 0; __i1 < max_tc_size; __i1 = __i1 + 1) {
            pus_service_19.pending_action_queue_4HS[__i0].tc_bytes[__i1] = 0;
        }
        pus_service_19.pending_action_queue_4HS[__i0].tc_num_bytes = 0;
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
    uart_hdlr.uart_registers = (volatile UARTRegs *)0xFC001000;
    tc_rx_bottom_half_task.RX_tc_length[0] = 0;
    tc_rx_bottom_half_task.RX_tc_length[1] = 0;
    tc_rx_bottom_half_task.a_tc_descriptor_pool = &tc_pool;
    tc_rx_bottom_half_task.aux_index = 0;
    tc_rx_bottom_half_task.rx_status.__variant = RXStatus__SyncBytesRx;
    tc_rx_bottom_half_task.sync_word[0] = 0xBE;
    tc_rx_bottom_half_task.sync_word[1] = 0xBA;
    tc_rx_bottom_half_task.sync_word[2] = 0xBE;
    tc_rx_bottom_half_task.sync_word[3] = 0xEF;
    tc_rx_bottom_half_task.tc_message_queue_output = &tc_message_queue;
    for (size_t __i0 = 0; __i0 < max_tc_size; __i0 = __i0 + 1) {
        tc_rx_bottom_half_task.telecommand.tc_bytes[__i0] = 0;
    }
    tc_rx_bottom_half_task.telecommand.tc_num_bytes = 0;
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
