#ifndef __APP_H__
#define __APP_H__

#include <termina.h>

#include "handlers/init.h"
#include "handlers/uart_irq_handler.h"
#include "resources/gpio_driver.h"
#include "resources/obt_manager.h"
#include "resources/tm_counter.h"
#include "resources/uart.h"
#include "service_libraries/pus_services/pus_service1.h"
#include "service_libraries/pus_services/pus_service12.h"
#include "service_libraries/pus_services/pus_service17.h"
#include "service_libraries/pus_services/pus_service19.h"
#include "service_libraries/pus_services/pus_service2.h"
#include "service_libraries/pus_services/pus_service20.h"
#include "service_libraries/pus_services/pus_service3.h"
#include "service_libraries/pus_services/pus_service4.h"
#include "service_libraries/pus_services/pus_service5.h"
#include "service_libraries/pus_services/pus_service6.h"
#include "service_libraries/pus_services/pus_service9.h"
#include "tasks/bkgtcexec.h"
#include "tasks/hk_fdir_mng/hk_fdir.h"
#include "tasks/icu_manager/icu_manager.h"
#include "tasks/tc_rx.h"

#include "option.h"

extern PeriodicTimer hk_fdir_timer;

extern __termina_msg_queue_t rx_task_message_queue;

extern __termina_msg_queue_t tc_message_queue;

extern __termina_msg_queue_t hkfdir_message_queue;

extern __termina_msg_queue_t bkg_message_queue;

extern __termina_msg_queue_t action_tc_message_queue;

extern __termina_pool_t tm_pool;

extern __termina_pool_t tc_pool;

extern _Atomic uint32_t u32_system_data_pool[12U];

extern _Atomic uint8_t u8_system_data_pool[18U];

extern UARTDriver uart_drv;

extern GPIODriver gpio_drv;

extern TMChannel telemetry_channel;

extern TMCounter telemetry_counter;

extern OBTManager obt_manager;

extern PUSService1 pus_service_9_service_1;

extern PUSService9 pus_service_9;

extern PUSService1 pus_service_5_service_1;

extern PUSService5 pus_service_5;

extern PUSService1 pus_service_3_service_1;

extern PUSService3 pus_service_3;

extern PUSService1 pus_service_12_service_1;

extern PUSService12 pus_service_12;

extern PUSService1 pus_service_19_service_1;

extern PUSService19 pus_service_19;

extern PUSService1 pus_service_20_service_1;

extern PUSService20 pus_service_20;

extern PUSService1 pus_service_17_service_1;

extern PUSService17 pus_service_17;

extern PUSService1 pus_service_128_service_1;

extern PUSService128 pus_service_128;

extern PUSService1 pus_service_2_service_1;

extern PUSService2 pus_service_2;

extern PUSService1 pus_service_6_service_1;

extern PUSService6 pus_service_6;

extern PUSService1 pus_service_4_service_1;

extern PUSService4 pus_service_4;

extern PUSService1 mng_tc_executor_service_1;

extern ManagerTCExecutor mng_tc_executor;

extern Init init;

extern UARTIrqHandler uart_hdlr;

extern TCRXBottomHalfTask tc_rx_bottom_half_task;

extern ICUManager icu_manager;

extern PUSService1 hk_fdir_service_1;

extern HouseKeepingFDIR hk_fdir;

extern PUSService1 pus_bkg_tc_executor_service_1;

extern PUSBKGTCExecutor pus_bkg_tc_executor;

#endif
