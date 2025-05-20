
#include <termina.h>

#include "app.h"

#include "handlers/init.h"

#include "resources/system_data_pool.h"

#include "resources/uart.h"

#include "service_libraries/errors.h"

#include "service_libraries/pus_services/pus_service1/pus_service_1_build_tm_1_x.h"

#include "service_libraries/pus_services/pus_service12/pus_service12_help.h"

#include "service_libraries/pus_services/pus_service128.h"

#include "service_libraries/pus_services/pus_service17/pus_service17_help.h"

#include "service_libraries/pus_services/pus_service19/pus_service19_help.h"

#include "service_libraries/pus_services/pus_service2/pus_service2_help.h"

#include "service_libraries/pus_services/pus_service20/pus_service20_help.h"

#include "service_libraries/pus_services/pus_service3/pus_service3_help.h"

#include "service_libraries/pus_services/pus_service4/pus_service4_help.h"

#include "service_libraries/pus_services/pus_service5/pus_service5_help.h"

#include "service_libraries/pus_services/pus_service9/pus_service9_help.h"

#include "service_libraries/pus_tm_handler.h"

#include "service_libraries/tc_ccsds_pus_format.h"

#include "service_libraries/tm_ccsds_pus_format.h"

#include "tasks/hk_fdir_mng/hk_fdir.h"

void __termina_app__init_globals() {
    
    hk_fdir_timer.period.tv_sec = 1U;
    hk_fdir_timer.period.tv_usec = 0U;
    for (size_t __i0 = 0U; __i0 < 12U; __i0 = __i0 + 1U) {
        atomic_store(&u32_system_data_pool[__i0], 0U);
    }
    for (size_t __i0 = 0U; __i0 < 18U; __i0 = __i0 + 1U) {
        atomic_store(&u8_system_data_pool[__i0], 0U);
    }
    uart_driver.uart_regs = (volatile UARTRegs *)2147483904U;
    gpio_drv.registers = (volatile GPIO_registers *)4228395008U;
    telemetry_channel.a_tm_handler_pool.__that = &tm_pool;
    telemetry_channel.a_tm_handler_pool.alloc = __termina_pool__alloc;
    telemetry_channel.a_tm_handler_pool.free = __termina_pool__free;
    telemetry_channel.uart.__that = &uart_driver;
    #line 58 "app/app.fin"
    telemetry_channel.uart.riscv_uart_tf_is_empty = CRISCVUARTDriver__riscv_uart_tf_is_empty;
    #line 58 "app/app.fin"
    telemetry_channel.uart.riscv_putchar = CRISCVUARTDriver__riscv_putchar;
    telemetry_counter.tm_count = 0U;
    pus_service_9.a_tm_handler_pool.__that = &tm_pool;
    pus_service_9.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_9.a_tm_handler_pool.free = __termina_pool__free;
    #line 72 "app/app.fin"
    pus_service_9.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_9.exec_tc_req_status_update.next_OBT.finetime = 0U;
    pus_service_9.exec_tc_req_status_update.next_OBT.seconds = 0U;
    pus_service_9.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_9.exec_tc_req_status_update.packet_id = 0U;
    pus_service_9.exec_tc_req_status_update.tc_num_bytes = 0U;
    pus_service_9.ref_obt.finetime = 0U;
    pus_service_9.ref_obt.seconds = 0U;
    pus_service_9.ref_time_val_from_power_on.tv_sec = 0U;
    pus_service_9.ref_time_val_from_power_on.tv_usec = 0U;
    #line 69 "app/app.fin"
    pus_service_9.system_port.clock_get_uptime = SystemEntry__clock_get_uptime;
    pus_service_9.tm_channel.__that = &telemetry_channel;
    #line 69 "app/app.fin"
    pus_service_9.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_9.tm_counter.__that = &telemetry_counter;
    #line 69 "app/app.fin"
    pus_service_9.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    #line 81 "app/app.fin"
    pus_service_5.Ev_ID_enable_config[0U] = 0x7U;
    #line 81 "app/app.fin"
    pus_service_5.Ev_ID_enable_config[1U] = 0x0U;
    #line 81 "app/app.fin"
    pus_service_5.Ev_ID_enable_config[2U] = 0x0U;
    #line 81 "app/app.fin"
    pus_service_5.Ev_ID_enable_config[3U] = 0x7U;
    pus_service_5.a_tm_handler_pool.__that = &tm_pool;
    pus_service_5.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_5.a_tm_handler_pool.free = __termina_pool__free;
    #line 82 "app/app.fin"
    pus_service_5.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_5.exec_tc_req_status_update.EvID = 0U;
    pus_service_5.exec_tc_req_status_update.N = 0U;
    pus_service_5.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_5.exec_tc_req_status_update.packet_id = 0U;
    pus_service_5.exec_tc_req_status_update.tc_num_bytes = 0U;
    pus_service_5.pus_service_9.__that = &pus_service_9;
    #line 80 "app/app.fin"
    pus_service_5.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_5.tm_channel.__that = &telemetry_channel;
    #line 80 "app/app.fin"
    pus_service_5.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_5.tm_counter.__that = &telemetry_counter;
    #line 80 "app/app.fin"
    pus_service_5.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_3.a_tm_handler_pool.__that = &tm_pool;
    pus_service_3.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_3.a_tm_handler_pool.free = __termina_pool__free;
    #line 100 "app/app.fin"
    pus_service_3.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_3.exec_tc_req_status_update.index.found = 0;
    pus_service_3.exec_tc_req_status_update.index.index = 0U;
    pus_service_3.exec_tc_req_status_update.tc_data.N = 0U;
    pus_service_3.exec_tc_req_status_update.tc_data.SID = 0U;
    pus_service_3.exec_tc_req_status_update.tc_data.collection_interval = 0U;
    pus_service_3.exec_tc_req_status_update.tc_data.packet_error_ctrl = 0U;
    pus_service_3.exec_tc_req_status_update.tc_data.packet_id = 0U;
    pus_service_3.exec_tc_req_status_update.tc_data.tc_num_bytes = 0U;
    pus_service_3.hk_config_table[0U].SID = 0U;
    pus_service_3.hk_config_table[0U].enabled = 1;
    pus_service_3.hk_config_table[0U].interval = 2U;
    pus_service_3.hk_config_table[0U].interval_control = 0U;
    pus_service_3.hk_config_table[0U].num_params = 5U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[0U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[1U] = 1U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[2U] = 2U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[3U] = 3U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[4U] = 4U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[5U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[6U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[7U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[8U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[9U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[10U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[11U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[12U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[13U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[14U] = 0U;
    #line 92 "app/app.fin"
    pus_service_3.hk_config_table[0U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[1U].SID = 10U;
    pus_service_3.hk_config_table[1U].enabled = 0;
    pus_service_3.hk_config_table[1U].interval = 30U;
    pus_service_3.hk_config_table[1U].interval_control = 0U;
    pus_service_3.hk_config_table[1U].num_params = 3U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[0U] = 5U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[1U] = 6U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[2U] = 7U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[3U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[4U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[5U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[6U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[7U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[8U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[9U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[10U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[11U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[12U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[13U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[14U] = 0U;
    #line 93 "app/app.fin"
    pus_service_3.hk_config_table[1U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[2U].SID = 11U;
    pus_service_3.hk_config_table[2U].enabled = 0;
    pus_service_3.hk_config_table[2U].interval = 60U;
    pus_service_3.hk_config_table[2U].interval_control = 0U;
    pus_service_3.hk_config_table[2U].num_params = 3U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[0U] = 8U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[1U] = 9U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[2U] = 10U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[3U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[4U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[5U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[6U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[7U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[8U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[9U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[10U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[11U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[12U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[13U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[14U] = 0U;
    #line 94 "app/app.fin"
    pus_service_3.hk_config_table[2U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[3U].SID = 0U;
    pus_service_3.hk_config_table[3U].enabled = 0;
    pus_service_3.hk_config_table[3U].interval = 0U;
    pus_service_3.hk_config_table[3U].interval_control = 0U;
    pus_service_3.hk_config_table[3U].num_params = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[0U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[1U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[2U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[3U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[4U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[5U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[6U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[7U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[8U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[9U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[10U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[11U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[12U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[13U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[14U] = 0U;
    #line 95 "app/app.fin"
    pus_service_3.hk_config_table[3U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[4U].SID = 0U;
    pus_service_3.hk_config_table[4U].enabled = 0;
    pus_service_3.hk_config_table[4U].interval = 0U;
    pus_service_3.hk_config_table[4U].interval_control = 0U;
    pus_service_3.hk_config_table[4U].num_params = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[0U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[1U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[2U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[3U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[4U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[5U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[6U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[7U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[8U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[9U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[10U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[11U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[12U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[13U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[14U] = 0U;
    #line 96 "app/app.fin"
    pus_service_3.hk_config_table[4U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[5U].SID = 0U;
    pus_service_3.hk_config_table[5U].enabled = 0;
    pus_service_3.hk_config_table[5U].interval = 0U;
    pus_service_3.hk_config_table[5U].interval_control = 0U;
    pus_service_3.hk_config_table[5U].num_params = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[0U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[1U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[2U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[3U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[4U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[5U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[6U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[7U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[8U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[9U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[10U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[11U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[12U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[13U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[14U] = 0U;
    #line 97 "app/app.fin"
    pus_service_3.hk_config_table[5U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[6U].SID = 0U;
    pus_service_3.hk_config_table[6U].enabled = 0;
    pus_service_3.hk_config_table[6U].interval = 0U;
    pus_service_3.hk_config_table[6U].interval_control = 0U;
    pus_service_3.hk_config_table[6U].num_params = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[0U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[1U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[2U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[3U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[4U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[5U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[6U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[7U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[8U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[9U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[10U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[11U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[12U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[13U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[14U] = 0U;
    #line 98 "app/app.fin"
    pus_service_3.hk_config_table[6U].params_def[15U] = 0U;
    pus_service_3.hk_config_table[7U].SID = 0U;
    pus_service_3.hk_config_table[7U].enabled = 0;
    pus_service_3.hk_config_table[7U].interval = 0U;
    pus_service_3.hk_config_table[7U].interval_control = 0U;
    pus_service_3.hk_config_table[7U].num_params = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[0U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[1U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[2U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[3U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[4U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[5U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[6U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[7U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[8U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[9U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[10U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[11U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[12U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[13U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[14U] = 0U;
    #line 99 "app/app.fin"
    pus_service_3.hk_config_table[7U].params_def[15U] = 0U;
    pus_service_3.pus_service_5.__that = &pus_service_5;
    #line 91 "app/app.fin"
    pus_service_3.pus_service_5.build_and_tx_tm_5_2 = PUSService5__build_and_tx_tm_5_2;
    pus_service_3.pus_service_9.__that = &pus_service_9;
    #line 91 "app/app.fin"
    pus_service_3.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_3.random_seed = 42U;
    pus_service_3.system_data_pool_u32 = u32_system_data_pool;
    pus_service_3.system_data_pool_u8 = u8_system_data_pool;
    pus_service_3.tm_channel.__that = &telemetry_channel;
    #line 91 "app/app.fin"
    pus_service_3.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_3.tm_counter.__that = &telemetry_counter;
    #line 91 "app/app.fin"
    pus_service_3.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_12.a_tm_handler_pool.__that = &tm_pool;
    pus_service_12.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_12.a_tm_handler_pool.free = __termina_pool__free;
    #line 119 "app/app.fin"
    pus_service_12.do_monitoring_req_status.__variant = DoMonitoringReqStatus__Init;
    pus_service_12.do_monitoring_req_status_update.EvID = 0U;
    pus_service_12.do_monitoring_req_status_update.PMONID = 0U;
    #line 118 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.do_monitoring_req_status_update.current_monitor_definition.__variant = MonitorDefinition__Unselected;
    pus_service_12.do_monitoring_req_status_update.event_triggered = 0;
    #line 119 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.do_monitoring_req_status_update.fault_info.__variant = FaultInfo__Empty;
    #line 120 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.do_monitoring_req_status_update.new_status.__variant = CheckState__Unselected;
    #line 121 "app/app.fin"
    pus_service_12.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_12.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_12.exec_tc_req_status_update.packet_id = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_1_2_6.N = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_1_2_6.PMONID = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.N = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.PMONID = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.PID = 0U;
    #line 178 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.current_state.__variant = CheckState__Unselected;
    #line 171 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.definition.__variant = MonitorDefinition__Unselected;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.enabled = 0;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.interval = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.interval_control = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.repetition = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.repetition_control = 0U;
    #line 177 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.temp_state.__variant = CheckState__Unselected;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.transition_obt.finetime = 0U;
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.transition_obt.seconds = 0U;
    #line 169 "src/service_libraries/pus_services/pus_service12/pus_service12_help.fin"
    pus_service_12.exec_tc_req_status_update.tc_data_5.mon_config.type.__variant = MonitorCheckType__Free;
    pus_service_12.exec_tc_req_status_update.tc_num_bytes = 0U;
    pus_service_12.monitoring_transition_counter = 0U;
    for (size_t __i0 = 0U; __i0 < 8U; __i0 = __i0 + 1U) {
        pus_service_12.param_mon_config_table[__i0].PID = 0U;
        #line 124 "app/app.fin"
        pus_service_12.param_mon_config_table[__i0].current_state.__variant = CheckState__Unselected;
        #line 123 "app/app.fin"
        pus_service_12.param_mon_config_table[__i0].definition.__variant = MonitorDefinition__Unselected;
        pus_service_12.param_mon_config_table[__i0].enabled = 0;
        pus_service_12.param_mon_config_table[__i0].interval = 0U;
        pus_service_12.param_mon_config_table[__i0].interval_control = 0U;
        pus_service_12.param_mon_config_table[__i0].repetition = 0U;
        pus_service_12.param_mon_config_table[__i0].repetition_control = 0U;
        #line 124 "app/app.fin"
        pus_service_12.param_mon_config_table[__i0].temp_state.__variant = CheckState__Unselected;
        pus_service_12.param_mon_config_table[__i0].transition_obt.finetime = 0U;
        pus_service_12.param_mon_config_table[__i0].transition_obt.seconds = 0U;
        #line 123 "app/app.fin"
        pus_service_12.param_mon_config_table[__i0].type.__variant = MonitorCheckType__Free;
    }
    for (size_t __i0 = 0U; __i0 < 1U; __i0 = __i0 + 1U) {
        pus_service_12.param_mon_transitions_table[__i0].PID = 0U;
        pus_service_12.param_mon_transitions_table[__i0].PMONID = 0U;
        pus_service_12.param_mon_transitions_table[__i0].limit_value = 0U;
        pus_service_12.param_mon_transitions_table[__i0].mask_value = 0U;
        #line 127 "app/app.fin"
        pus_service_12.param_mon_transitions_table[__i0].new_status.__variant = CheckState__Unselected;
        pus_service_12.param_mon_transitions_table[__i0].new_value = 0U;
        #line 127 "app/app.fin"
        pus_service_12.param_mon_transitions_table[__i0].prev_status.__variant = CheckState__Unselected;
        pus_service_12.param_mon_transitions_table[__i0].trans_obt.finetime = 0U;
        pus_service_12.param_mon_transitions_table[__i0].trans_obt.seconds = 0U;
        #line 126 "app/app.fin"
        pus_service_12.param_mon_transitions_table[__i0].type.__variant = MonitorCheckType__Free;
    }
    pus_service_12.pus_service_9.__that = &pus_service_9;
    #line 118 "app/app.fin"
    pus_service_12.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_12.system_data_pool_u32 = u32_system_data_pool;
    pus_service_12.system_data_pool_u8 = u8_system_data_pool;
    pus_service_12.tm_channel.__that = &telemetry_channel;
    #line 118 "app/app.fin"
    pus_service_12.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_12.tm_counter.__that = &telemetry_counter;
    #line 118 "app/app.fin"
    pus_service_12.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_19.a_tm_handler_pool.__that = &tm_pool;
    pus_service_19.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_19.a_tm_handler_pool.free = __termina_pool__free;
    for (size_t __i0 = 0U; __i0 < 16U; __i0 = __i0 + 1U) {
        pus_service_19.event_action_config[__i0].enabled = 0;
        pus_service_19.event_action_config[__i0].event_ID = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 16U; __i0 = __i0 + 1U) {
        #line 141 "app/app.fin"
        pus_service_19.event_action_packets[__i0] = tc_handler_init();
    }
    #line 138 "app/app.fin"
    pus_service_19.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 50 "src/service_libraries/pus_services/pus_service19/pus_service19_help.fin"
        pus_service_19.exec_tc_req_status_update.action_tc_packet.tc_bytes[__i0] = 0U;
    }
    pus_service_19.exec_tc_req_status_update.action_tc_packet.tc_num_bytes = 0U;
    pus_service_19.exec_tc_req_status_update.ev_action_ID.ev_action_index = 0U;
    pus_service_19.exec_tc_req_status_update.ev_action_ID.found = 0;
    pus_service_19.exec_tc_req_status_update.tc_data.EvID = 0U;
    pus_service_19.exec_tc_req_status_update.tc_data.N = 0U;
    pus_service_19.exec_tc_req_status_update.tc_data.packet_error_ctrl = 0U;
    pus_service_19.exec_tc_req_status_update.tc_data.packet_id = 0U;
    pus_service_19.exec_tc_req_status_update.tc_data.tc_num_bytes = 0U;
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 147 "app/app.fin"
        pus_service_19.pending_action_head[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 146 "app/app.fin"
        pus_service_19.pending_action_number[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 8U; __i0 = __i0 + 1U) {
        #line 142 "app/app.fin"
        pus_service_19.pending_action_queue_1I[__i0] = tc_handler_init();
    }
    for (size_t __i0 = 0U; __i0 < 8U; __i0 = __i0 + 1U) {
        #line 143 "app/app.fin"
        pus_service_19.pending_action_queue_2LS[__i0] = tc_handler_init();
    }
    for (size_t __i0 = 0U; __i0 < 8U; __i0 = __i0 + 1U) {
        #line 144 "app/app.fin"
        pus_service_19.pending_action_queue_3MS[__i0] = tc_handler_init();
    }
    for (size_t __i0 = 0U; __i0 < 8U; __i0 = __i0 + 1U) {
        #line 145 "app/app.fin"
        pus_service_19.pending_action_queue_4HS[__i0] = tc_handler_init();
    }
    pus_service_19.pus_service_9.__that = &pus_service_9;
    #line 137 "app/app.fin"
    pus_service_19.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_19.tm_channel.__that = &telemetry_channel;
    #line 137 "app/app.fin"
    pus_service_19.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_19.tm_counter.__that = &telemetry_counter;
    #line 137 "app/app.fin"
    pus_service_19.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_20.a_tm_handler_pool.__that = &tm_pool;
    pus_service_20.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_20.a_tm_handler_pool.free = __termina_pool__free;
    #line 156 "app/app.fin"
    pus_service_20.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_20.exec_tc_req_status_update.N = 0U;
    pus_service_20.exec_tc_req_status_update.PID = 0U;
    pus_service_20.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_20.exec_tc_req_status_update.packet_id = 0U;
    pus_service_20.exec_tc_req_status_update.tc_20_3_data.PID_value_u32 = 0U;
    pus_service_20.exec_tc_req_status_update.tc_20_3_data.PID_value_u8 = 0U;
    pus_service_20.exec_tc_req_status_update.tc_num_bytes = 0U;
    pus_service_20.pus_service_9.__that = &pus_service_9;
    #line 155 "app/app.fin"
    pus_service_20.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_20.system_data_pool_u32 = u32_system_data_pool;
    pus_service_20.system_data_pool_u8 = u8_system_data_pool;
    pus_service_20.tm_channel.__that = &telemetry_channel;
    #line 155 "app/app.fin"
    pus_service_20.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_20.tm_counter.__that = &telemetry_counter;
    #line 155 "app/app.fin"
    pus_service_20.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_17.a_tm_handler_pool.__that = &tm_pool;
    pus_service_17.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_17.a_tm_handler_pool.free = __termina_pool__free;
    #line 168 "app/app.fin"
    pus_service_17.exec_tc_req_status.__variant = PSExecTCReqStatus__ExecTC;
    pus_service_17.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_17.exec_tc_req_status_update.packet_id = 0U;
    pus_service_17.pus_service_9.__that = &pus_service_9;
    #line 167 "app/app.fin"
    pus_service_17.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_17.tm_channel.__that = &telemetry_channel;
    #line 167 "app/app.fin"
    pus_service_17.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_17.tm_counter.__that = &telemetry_counter;
    #line 167 "app/app.fin"
    pus_service_17.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_2.a_tm_handler_pool.__that = &tm_pool;
    pus_service_2.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_2.a_tm_handler_pool.free = __termina_pool__free;
    #line 177 "app/app.fin"
    pus_service_2.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_2.exec_tc_req_status_update.N = 0U;
    pus_service_2.exec_tc_req_status_update.dev_address = 0U;
    pus_service_2.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_2.exec_tc_req_status_update.packet_id = 0U;
    pus_service_2.exec_tc_req_status_update.tc_num_bytes = 0U;
    pus_service_2.gpio_driver.__that = &gpio_drv;
    #line 176 "app/app.fin"
    pus_service_2.gpio_driver.write_led = GPIODriver__write_led;
    pus_service_2.pus_service_9.__that = &pus_service_9;
    #line 176 "app/app.fin"
    pus_service_2.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    pus_service_2.tm_channel.__that = &telemetry_channel;
    #line 176 "app/app.fin"
    pus_service_2.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_2.tm_counter.__that = &telemetry_counter;
    #line 176 "app/app.fin"
    pus_service_2.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    pus_service_4.a_tm_handler_pool.__that = &tm_pool;
    pus_service_4.a_tm_handler_pool.alloc = __termina_pool__alloc;
    pus_service_4.a_tm_handler_pool.free = __termina_pool__free;
    #line 187 "app/app.fin"
    pus_service_4.exec_tc_req_status.__variant = PSExecTCReqStatus__Init;
    pus_service_4.exec_tc_req_status_update.N = 0U;
    pus_service_4.exec_tc_req_status_update.PID = 0U;
    pus_service_4.exec_tc_req_status_update.packet_error_ctrl = 0U;
    pus_service_4.exec_tc_req_status_update.packet_id = 0U;
    pus_service_4.exec_tc_req_status_update.tc_num_bytes = 0U;
    pus_service_4.exec_tc_req_status_update.valid_index = 0U;
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pus_service_4.param_stats[__i0].max = 0U;
        pus_service_4.param_stats[__i0].max_obt.finetime = 0U;
        pus_service_4.param_stats[__i0].max_obt.seconds = 0U;
        pus_service_4.param_stats[__i0].mean_value = 0U;
        pus_service_4.param_stats[__i0].min = 0U;
        pus_service_4.param_stats[__i0].min_obt.finetime = 0U;
        pus_service_4.param_stats[__i0].min_obt.seconds = 0U;
        pus_service_4.param_stats[__i0].samples = 0U;
    }
    pus_service_4.pus_service_9.__that = &pus_service_9;
    #line 186 "app/app.fin"
    pus_service_4.pus_service_9.get_current_obt = PUSService9__get_current_obt;
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 190 "app/app.fin"
        pus_service_4.stats_config_table.PID[__i0] = 0U;
    }
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        #line 190 "app/app.fin"
        pus_service_4.stats_config_table.defined[__i0] = 0;
    }
    for (size_t __i0 = 0U; __i0 < 4U; __i0 = __i0 + 1U) {
        pus_service_4.stats_config_table.start_time[__i0].finetime = 0U;
        pus_service_4.stats_config_table.start_time[__i0].seconds = 0U;
    }
    pus_service_4.system_data_pool_u32 = u32_system_data_pool;
    pus_service_4.system_data_pool_u8 = u8_system_data_pool;
    pus_service_4.tm_channel.__that = &telemetry_channel;
    #line 186 "app/app.fin"
    pus_service_4.tm_channel.send_tm = TMChannel__send_tm;
    pus_service_4.tm_counter.__that = &telemetry_counter;
    #line 186 "app/app.fin"
    pus_service_4.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    mng_tc_executor.a_tm_handler_pool.__that = &tm_pool;
    mng_tc_executor.a_tm_handler_pool.alloc = __termina_pool__alloc;
    mng_tc_executor.a_tm_handler_pool.free = __termina_pool__free;
    mng_tc_executor.pus_service_17.__that = &pus_service_17;
    #line 201 "app/app.fin"
    mng_tc_executor.pus_service_17.exec_tc = PUSService17__exec_tc;
    mng_tc_executor.pus_service_2.__that = &pus_service_2;
    #line 201 "app/app.fin"
    mng_tc_executor.pus_service_2.exec_tc = PUSService2__exec_tc;
    mng_tc_executor.pus_service_9.__that = &pus_service_9;
    #line 201 "app/app.fin"
    mng_tc_executor.pus_service_9.exec_tc = PUSService9__exec_tc;
    mng_tc_executor.tm_channel.__that = &telemetry_channel;
    #line 201 "app/app.fin"
    mng_tc_executor.tm_channel.send_tm = TMChannel__send_tm;
    mng_tc_executor.tm_counter.__that = &telemetry_counter;
    #line 201 "app/app.fin"
    mng_tc_executor.tm_counter.get_next_tm_count = TMCounter__get_next_tm_count;
    init.gpio_driver.__that = &gpio_drv;
    #line 211 "app/app.fin"
    init.gpio_driver.init_gpio = GPIODriver__init_gpio;
    init.system_data_pool_u32 = u32_system_data_pool;
    init.system_data_pool_u8 = u8_system_data_pool;
    init.uart.__that = &uart_driver;
    #line 211 "app/app.fin"
    init.uart.riscv_uart_enable_TX = CRISCVUARTDriver__riscv_uart_enable_TX;
    #line 211 "app/app.fin"
    init.uart.riscv_uart_enable_RX = CRISCVUARTDriver__riscv_uart_enable_RX;
    #line 211 "app/app.fin"
    init.uart.riscv_uart_enable_RI = CRISCVUARTDriver__riscv_uart_enable_RI;
    uart_handler.a_tc_handler_pool.__that = &tc_pool;
    uart_handler.a_tc_handler_pool.alloc = __termina_pool__alloc;
    uart_handler.a_tc_handler_pool.free = __termina_pool__free;
    #line 230 "app/app.fin"
    uart_handler.handler_state.__variant = RISCVUARTHandlerState__RXFrameHeader;
    uart_handler.handler_state.RXFrameHeader.__0 = 0U;
    uart_handler.tc_message_queue_output = &tc_message_queue;
    for (size_t __i0 = 0U; __i0 < 256U; __i0 = __i0 + 1U) {
        #line 227 "app/app.fin"
        uart_handler.telecommand.tc_bytes[__i0] = 0U;
    }
    uart_handler.telecommand.tc_num_bytes = 0U;
    uart_handler.uart.__that = &uart_driver;
    #line 220 "app/app.fin"
    uart_handler.uart.riscv_getchar = CRISCVUARTDriver__riscv_getchar;
    icu_manager.a_tc_handler_pool.__that = &tc_pool;
    icu_manager.a_tc_handler_pool.alloc = __termina_pool__alloc;
    icu_manager.a_tc_handler_pool.free = __termina_pool__free;
    icu_manager.bkg_message_queue_output = &bkg_message_queue;
    icu_manager.hkfdir_message_queue_output = &hkfdir_message_queue;
    icu_manager.tc_executor.__that = &mng_tc_executor;
    #line 235 "app/app.fin"
    icu_manager.tc_executor.PUS_prio_exec_tc = ManagerTCExecutor__PUS_prio_exec_tc;
    #line 235 "app/app.fin"
    icu_manager.tc_executor.mng_tc_acceptation = ManagerTCExecutor__mng_tc_acceptation;
    #line 235 "app/app.fin"
    icu_manager.tc_executor.mng_tc_rejection = ManagerTCExecutor__mng_tc_rejection;
    hk_fdir.a_tc_handler_pool.__that = &tc_pool;
    hk_fdir.a_tc_handler_pool.alloc = __termina_pool__alloc;
    hk_fdir.a_tc_handler_pool.free = __termina_pool__free;
    hk_fdir.action_tc_message_queue_output = &action_tc_message_queue;
    hk_fdir.pus_service_12.__that = &pus_service_12;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_12.exec_tc = PUSService12__exec_tc;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_12.do_monitoring = PUSService12__do_monitoring;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_12.is_PMON_enabled = PUSService12__is_PMON_enabled;
    hk_fdir.pus_service_19.__that = &pus_service_19;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_19.exec_tc = PUSService19__exec_tc;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_19.manage_event_action = PUSService19__manage_event_action;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_19.get_pending_action_number = PUSService19__get_pending_action_number;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_19.extract_action = PUSService19__extract_action;
    hk_fdir.pus_service_3.__that = &pus_service_3;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_3.do_hk = PUSService3__do_hk;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_3.exec_tc = PUSService3__exec_tc;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_3.update_params = PUSService3__update_params;
    hk_fdir.pus_service_4.__that = &pus_service_4;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_4.exec_tc = PUSService4__exec_tc;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_4.update_all_stats = PUSService4__update_all_stats;
    hk_fdir.pus_service_5.__that = &pus_service_5;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_5.exec_tc = PUSService5__exec_tc;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_5.is_Ev_ID_enabled_ext = PUSService5__is_Ev_ID_enabled_ext;
    #line 246 "app/app.fin"
    hk_fdir.pus_service_5.build_and_tx_tm_5_x = PUSService5__build_and_tx_tm_5_x;
    pus_bkg_tc_executor.a_tc_handler_pool.__that = &tc_pool;
    pus_bkg_tc_executor.a_tc_handler_pool.alloc = __termina_pool__alloc;
    pus_bkg_tc_executor.a_tc_handler_pool.free = __termina_pool__free;
    pus_bkg_tc_executor.pus_service_20.__that = &pus_service_20;
    #line 260 "app/app.fin"
    pus_bkg_tc_executor.pus_service_20.exec_tc = PUSService20__exec_tc;

    return;

}
