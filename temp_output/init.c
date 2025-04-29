
#include <termina.h>

#include "app.h"

#include "handlers/uart_irq_handler.h"

#include "resources/system_data_pool.h"

#include "resources/uart.h"

#include "service_libraries/event_list.h"

#include "service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.h"

#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

#include "service_libraries/pus_services/pus_service128.h"

#include "service_libraries/pus_services/pus_service19/pus_service19_help.h"

#include "service_libraries/pus_services/pus_service2.h"

#include "service_libraries/pus_services/pus_service3/pus_service3_help.h"

#include "service_libraries/pus_services/pus_service4/pus_service4_utils.h"

#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

#include "service_libraries/pus_services/pus_service9.h"

#include "service_libraries/pus_tm_handler.h"

#include "service_libraries/queue_u8.h"

#include "service_libraries/tc_ccsds_pus_format.h"

#include "tasks/hk_fdir_mng/hk_fdir.h"

void __termina_app__init_globals() {
    
    hk_fdir_timer.period.tv_sec = 1U;
    hk_fdir_timer.period.tv_usec = 0U;
    for (size_t __i0 = 0U; __i0 < sdp_num_u32_params; __i0 = __i0 + 1U) {
        u32_system_data_pool.values[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < sdp_num_u8_params; __i0 = __i0 + 1U) {
        u8_system_data_pool.values[__i0] = 0U;
    }
    uart_drv.registers = (volatile UARTRegs *)4227862528U;
    uart_drv.rem_bytes = 0;
    for (size_t __i0 = 0U; __i0 < queue_max_noe; __i0 = __i0 + 1U) {
        uart_drv.uart_queue.elements[__i0] = 0U;
    }
    uart_drv.uart_queue.head_index = 0U;
    uart_drv.uart_queue.num_elements = 0U;
    gpio_drv.registers = (volatile GPIO_registers *)4228395008U;
    telemetry_channel.a_tm_handler_pool.__that = &tm_pool;
    telemetry_channel.a_tm_handler_pool.alloc = __termina_pool__alloc;
    telemetry_channel.a_tm_handler_pool.free = __termina_pool__free;
    telemetry_channel.uart.__that = &uart_drv;
    telemetry_channel.uart.send = UARTDriver__send;
    telemetry_counter.tm_count = 0U;
    pus_service_3.a_tm_handler_pool.__that = &tm_pool;
    pus_service_3.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_3.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_3.exec_tc_req_status.__variant = PS3ExecTCReqStatus__Init;
    pus_service_3.exec_tc_req_status_update = ps3_init_tc_req_status_update();
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
    pus_service_3.system_data_pool_u32 = u32_system_data_pool;
    pus_service_3.system_data_pool_u8 = u8_system_data_pool;
    pus_service_3.tm_channel.__that = &telemetry_channel;
    pus_service_3.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_3.tm_counter.__that = &telemetry_counter;
    pus_service_3.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_5.Ev_ID_enable_config[0U] = 0x7U;
    pus_service_5.Ev_ID_enable_config[1U] = 0x0U;
    pus_service_5.Ev_ID_enable_config[2U] = 0x0U;
    pus_service_5.Ev_ID_enable_config[3U] = 0x7U;
    pus_service_5.a_tm_handler_pool.__that = &tm_pool;
    pus_service_5.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_5.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_5.exec_tc_req_status.__variant = PS5ExecTCReqStatus__Init;
    pus_service_5.exec_tc_req_status_update = ps5_init_tc_req_status_update();
    pus_service_5.tm_channel.__that = &telemetry_channel;
    pus_service_5.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_5.tm_counter.__that = &telemetry_counter;
    pus_service_5.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_12.a_tm_handler_pool.__that = &tm_pool;
    pus_service_12.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_12.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_12.do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;
    pus_service_12.do_monitoring_req_status_update = ps12_init_do_monitoring_req_status_update();
    pus_service_12.exec_tc_req_status.__variant = PS12ExecTCReqStatus__Init;
    pus_service_12.exec_tc_req_status_update = ps12_init_tc_req_status_update();
    pus_service_12.monitoring_transition_counter = 0U;
    for (size_t __i0 = 0U; __i0 < max_num_pmon_ids; __i0 = __i0 + 1U) {
        pus_service_12.param_mon_config_table[__i0].PID = 0U;
        pus_service_12.param_mon_config_table[__i0].current_state.__variant = CheckState__Unselected;
        pus_service_12.param_mon_config_table[__i0].definition.__variant = MonitorDefinition__Unselected;
        pus_service_12.param_mon_config_table[__i0].enabled = 0;
        pus_service_12.param_mon_config_table[__i0].interval = 0U;
        pus_service_12.param_mon_config_table[__i0].interval_control = 0U;
        pus_service_12.param_mon_config_table[__i0].repetition = 0U;
        pus_service_12.param_mon_config_table[__i0].repetition_control = 0U;
        pus_service_12.param_mon_config_table[__i0].temp_state.__variant = CheckState__Unselected;
        pus_service_12.param_mon_config_table[__i0].transition_obt.tv_sec = 0U;
        pus_service_12.param_mon_config_table[__i0].transition_obt.tv_usec = 0U;
        pus_service_12.param_mon_config_table[__i0].type.__variant = MonitorCheckType__Free;
    }
    for (size_t __i0 = 0U; __i0 < max_num_transitions; __i0 = __i0 + 1U) {
        pus_service_12.param_mon_transitions_table[__i0].PID = 0U;
        pus_service_12.param_mon_transitions_table[__i0].PMONID = 0U;
        pus_service_12.param_mon_transitions_table[__i0].limit_value = 0U;
        pus_service_12.param_mon_transitions_table[__i0].mask_value = 0U;
        pus_service_12.param_mon_transitions_table[__i0].new_status.__variant = CheckState__Unselected;
        pus_service_12.param_mon_transitions_table[__i0].new_value = 0U;
        pus_service_12.param_mon_transitions_table[__i0].prev_status.__variant = CheckState__Unselected;
        pus_service_12.param_mon_transitions_table[__i0].trans_obt.tv_sec = 0U;
        pus_service_12.param_mon_transitions_table[__i0].trans_obt.tv_usec = 0U;
        pus_service_12.param_mon_transitions_table[__i0].type.__variant = MonitorCheckType__Free;
    }
    pus_service_12.system_data_pool_u32 = u32_system_data_pool;
    pus_service_12.system_data_pool_u8 = u8_system_data_pool;
    pus_service_12.tm_channel.__that = &telemetry_channel;
    pus_service_12.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_12.tm_counter.__that = &telemetry_counter;
    pus_service_12.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_19.a_tm_handler_pool.__that = &tm_pool;
    pus_service_19.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_19.a_tm_handler_pool.free = __termina_pool__free;
    for (size_t __i0 = 0U; __i0 < max_event_action_definitions; __i0 = __i0 + 1U) {
        pus_service_19.event_action_config[__i0].enabled = 0;
        pus_service_19.event_action_config[__i0].event_ID = 0U;
    }
    for (size_t __i0 = 0U; __i0 < max_event_action_definitions; __i0 = __i0 + 1U) {
        pus_service_19.event_action_packets[__i0] = tc_handler_init();
    }
    pus_service_19.exec_tc_req_status.__variant = PS19ExecTCReqStatus__Init;
    pus_service_19.exec_tc_req_status_update = ps19_init_tc_req_status_update();
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_head[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_number[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_queue_1I[__i0] = tc_handler_init();
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_queue_2LS[__i0] = tc_handler_init();
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_queue_3MS[__i0] = tc_handler_init();
    }
    for (size_t __i0 = 0U; __i0 < event_action_queue_dimension; __i0 = __i0 + 1U) {
        pus_service_19.pending_action_queue_4HS[__i0] = tc_handler_init();
    }
    pus_service_19.tm_channel.__that = &telemetry_channel;
    pus_service_19.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_19.tm_counter.__that = &telemetry_counter;
    pus_service_19.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_20.a_tm_handler_pool.__that = &tm_pool;
    pus_service_20.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_20.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_20.exec_tc_req_status.__variant = PS20ExecTCReqStatus__Init;
    pus_service_20.exec_tc_req_status_update = ps20_init_tc_req_status_update();
    pus_service_20.system_data_pool_u32 = u32_system_data_pool;
    pus_service_20.system_data_pool_u8 = u8_system_data_pool;
    pus_service_20.tm_channel.__that = &telemetry_channel;
    pus_service_20.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_20.tm_counter.__that = &telemetry_counter;
    pus_service_20.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_17.a_tm_handler_pool.__that = &tm_pool;
    pus_service_17.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_17.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_17.exec_tc_req_status.__variant = PS17ExecTCReqStatus__ExecTC;
    pus_service_17.tm_channel.__that = &telemetry_channel;
    pus_service_17.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_17.tm_counter.__that = &telemetry_counter;
    pus_service_17.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_2.a_tm_handler_pool.__that = &tm_pool;
    pus_service_2.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_2.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_2.exec_tc_req_status.__variant = PS2ExecTCReqStatus__Init;
    pus_service_2.exec_tc_req_status_update = ps2_init_tc_req_status_update();
    pus_service_2.gpio_driver.__that = &gpio_drv;
    pus_service_2.gpio_driver.write_led = GPIODriver__write_led;
    pus_service_2.tm_channel.__that = &telemetry_channel;
    pus_service_2.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_2.tm_counter.__that = &telemetry_counter;
    pus_service_2.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_4.a_tm_handler_pool.__that = &tm_pool;
    pus_service_4.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_4.a_tm_handler_pool.free = __termina_pool__free;
    pus_service_4.exec_tc_req_status.__variant = PS4ExecTCReqStatus__Init;
    pus_service_4.exec_tc_req_status_update = ps4_init_tc_req_status_update();
    for (size_t __i0 = 0U; __i0 < max_num_of_stats; __i0 = __i0 + 1U) {
        pus_service_4.param_stats[__i0].max = 0U;
        pus_service_4.param_stats[__i0].max_obt.tv_sec = 0U;
        pus_service_4.param_stats[__i0].max_obt.tv_usec = 0U;
        pus_service_4.param_stats[__i0].mean_value = 0U;
        pus_service_4.param_stats[__i0].min = 0U;
        pus_service_4.param_stats[__i0].min_obt.tv_sec = 0U;
        pus_service_4.param_stats[__i0].min_obt.tv_usec = 0U;
        pus_service_4.param_stats[__i0].samples = 0U;
    }
    for (size_t __i0 = 0U; __i0 < max_num_of_stats; __i0 = __i0 + 1U) {
        pus_service_4.stats_config_table.PID[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < max_num_of_stats; __i0 = __i0 + 1U) {
        pus_service_4.stats_config_table.defined[__i0] = 0;
    }
    for (size_t __i0 = 0U; __i0 < max_num_of_stats; __i0 = __i0 + 1U) {
        pus_service_4.stats_config_table.start_time[__i0].tv_sec = 0U;
        pus_service_4.stats_config_table.start_time[__i0].tv_usec = 0U;
    }
    pus_service_4.system_data_pool_u32 = u32_system_data_pool;
    pus_service_4.system_data_pool_u8 = u8_system_data_pool;
    pus_service_4.system_port.clock_get_uptime = SystemEntry__clock_get_uptime;
    pus_service_4.tm_channel.__that = &telemetry_channel;
    pus_service_4.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_4.tm_counter.__that = &telemetry_counter;
    pus_service_4.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    mng_tc_executor.a_tm_handler_pool.__that = &tm_pool;
    mng_tc_executor.a_tm_handler_pool.alloc = __termina_pool__alloc;
    mng_tc_executor.a_tm_handler_pool.free = __termina_pool__free;
    mng_tc_executor.pus_service_17.__that = &pus_service_17;
    mng_tc_executor.pus_service_17.exec_tc = PUSService17__exec_tc;
    mng_tc_executor.pus_service_2.__that = &pus_service_2;
    mng_tc_executor.pus_service_2.exec_tc = PUSService2__exec_tc;
    mng_tc_executor.tm_channel.__that = &telemetry_channel;
    mng_tc_executor.tm_channel.send_tm = TMChannel__send_tm;
    mng_tc_executor.tm_counter.__that = &telemetry_counter;
    mng_tc_executor.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    init.gpio_driver.__that = &gpio_drv;
    init.gpio_driver.init_gpio = GPIODriver__init_gpio;
    init.system_data_pool_u32 = u32_system_data_pool;
    init.system_data_pool_u8 = u8_system_data_pool;
    init.uart.__that = &uart_drv;
    init.uart.initialize = UARTDriver__initialize;
    uart_hdlr.byte_message_queue_output = &byte_message_queue;
    uart_hdlr.uart.__that = &uart_drv;
    uart_hdlr.uart.release_tx = UARTDriver__release_tx;
    uart_hdlr.uart_registers = (volatile UARTRegs *)4227862528U;
    tc_rx_bottom_half_task.RX_tc_length[0U] = 0U;
    tc_rx_bottom_half_task.RX_tc_length[1U] = 0U;
    tc_rx_bottom_half_task.a_tc_handler_pool.__that = &tc_pool;
    tc_rx_bottom_half_task.a_tc_handler_pool.alloc = __termina_pool__alloc;
    tc_rx_bottom_half_task.a_tc_handler_pool.free = __termina_pool__free;
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
    icu_manager.a_tc_handler_pool.__that = &tc_pool;
    icu_manager.a_tc_handler_pool.alloc = __termina_pool__alloc;
    icu_manager.a_tc_handler_pool.free = __termina_pool__free;
    icu_manager.bkg_message_queue_output = &bkg_message_queue;
    icu_manager.hkfdir_message_queue_output = &hkfdir_message_queue;
    icu_manager.tc_executor.__that = &mng_tc_executor;
    icu_manager.tc_executor.PUS_prio_exec_tc = ManagerTCExecutor__PUS_prio_exec_tc;
    hk_fdir.a_tc_handler_pool.__that = &tc_pool;
    hk_fdir.a_tc_handler_pool.alloc = __termina_pool__alloc;
    hk_fdir.a_tc_handler_pool.free = __termina_pool__free;
    hk_fdir.action_tc_message_queue_output = &action_tc_message_queue;
    hk_fdir.pus_service_12.__that = &pus_service_12;
    hk_fdir.pus_service_12.do_monitoring = PUSService12__do_monitoring;
    hk_fdir.pus_service_12.is_PMON_enabled = PUSService12__is_PMON_enabled;
    hk_fdir.pus_service_19.__that = &pus_service_19;
    hk_fdir.pus_service_19.manage_event_action = PUSService19__manage_event_action;
    hk_fdir.pus_service_3.__that = &pus_service_3;
    hk_fdir.pus_service_3.exec_tc = PUSService3__exec_tc;
    hk_fdir.pus_service_4.__that = &pus_service_4;
    hk_fdir.pus_service_4.exec_tc = PUSService4__exec_tc;
    hk_fdir.pus_service_5.__that = &pus_service_5;
    hk_fdir.pus_service_5.is_Ev_ID_enabled_ext = PUSService5__is_Ev_ID_enabled_ext;
    hk_fdir.pus_service_5.build_and_tx_tm_5_x = PUSService5__build_and_tx_tm_5_x;
    pus_bkg_tc_executor.a_tc_handler_pool.__that = &tc_pool;
    pus_bkg_tc_executor.a_tc_handler_pool.alloc = __termina_pool__alloc;
    pus_bkg_tc_executor.a_tc_handler_pool.free = __termina_pool__free;
    pus_bkg_tc_executor.pus_service_20.__that = &pus_service_20;
    pus_bkg_tc_executor.pus_service_20.exec_tc = PUSService20__exec_tc;

    return;

}
