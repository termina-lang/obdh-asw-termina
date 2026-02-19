
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

CTCChannel tc_channel;

CAPBUARTDriver uart_drv;

GPIODriver gpio_drv;

TMChannel telemetry_channel;

TMCounter telemetry_counter;

OBTManager obt_manager;

PUSService1 pus_service_1;

PUSService9 pus_service_9;

PUSService5 pus_service_5;

PUSService3 pus_service_3;

PUSService12 pus_service_12;

PUSService19 pus_service_19;

PUSService20 pus_service_20;

PUSService17 pus_service_17;

PUSService128 pus_service_128;

PUSService2 pus_service_2;

PUSService6 pus_service_6;

PUSService4 pus_service_4;

ManagerTCExecutor mng_tc_executor;

Init init;

CCharDevIRQHandler uart_hdlr;

TCRXBottomHalfTask tc_rx_bottom_half_task;

ICUManager icu_manager;

HouseKeepingFDIR hk_fdir;

PUSBKGTCExecutor pus_bkg_tc_executor;
