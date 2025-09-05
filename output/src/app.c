
#include "app.h"

PeriodicTimer hk_fdir_timer;

__termina_msg_queue_t rx_task_message_queue;

__termina_msg_queue_t tc_message_queue;

__termina_msg_queue_t hkfdir_message_queue;

__termina_msg_queue_t bkg_message_queue;

__termina_msg_queue_t action_tc_message_queue;

__termina_pool_t tm_pool;

__termina_pool_t tc_pool;

_Atomic uint32_t u32_system_data_pool[12U];

_Atomic uint8_t u8_system_data_pool[18U];

UARTDriver uart_drv;

GPIODriver gpio_drv;

TMChannel telemetry_channel;

TMCounter telemetry_counter;

OBTManager obt_manager;

PUSService1 pus_service_9_service_1;

PUSService9 pus_service_9;

PUSService1 pus_service_5_service_1;

PUSService5 pus_service_5;

PUSService1 pus_service_3_service_1;

PUSService3 pus_service_3;

PUSService1 pus_service_12_service_1;

PUSService12 pus_service_12;

PUSService1 pus_service_19_service_1;

PUSService19 pus_service_19;

PUSService1 pus_service_20_service_1;

PUSService20 pus_service_20;

PUSService1 pus_service_17_service_1;

PUSService17 pus_service_17;

PUSService1 pus_service_128_service_1;

PUSService128 pus_service_128;

PUSService1 pus_service_2_service_1;

PUSService2 pus_service_2;

PUSService1 pus_service_6_service_1;

PUSService6 pus_service_6;

PUSService1 pus_service_4_service_1;

PUSService4 pus_service_4;

PUSService1 mng_tc_executor_service_1;

ManagerTCExecutor mng_tc_executor;

Init init;

UARTIrqHandler uart_hdlr;

TCRXBottomHalfTask tc_rx_bottom_half_task;

ICUManager icu_manager;

PUSService1 hk_fdir_service_1;

HouseKeepingFDIR hk_fdir;

PUSService1 pus_bkg_tc_executor_service_1;

PUSBKGTCExecutor pus_bkg_tc_executor;
