
#include "app.h"

 PeriodicTimer hk_fdir_timer;

 __termina_msg_queue_t byte_message_queue;

 __termina_msg_queue_t tc_message_queue;

 __termina_msg_queue_t hkfdir_message_queue;

 __termina_msg_queue_t bkg_message_queue;

 __termina_msg_queue_t action_tc_message_queue;

 __termina_pool_t tm_pool;

 __termina_pool_t tc_pool;

 _Atomic uint16_t system_data_pool[sdp_num_params];

 UARTDriver uart_drv;

 TMChannel telemetry_channel;

 TMCounter telemetry_counter;

 PUSService3 pus_service_3;

 PUSService5 pus_service_5;

 PUSService12 pus_service_12;

 PUSService19 pus_service_19;

 PUSService20 pus_service_20;

 PUSService17 pus_service_17;

 ManagerTCExecutor mng_tc_executor;

 Init init;

 UARTIrqHandler uart_hdlr;

 TCRXBottomHalfTask tc_rx_bottom_half_task;

 ICUManager icu_manager;

 HouseKeepingFDIR hk_fdir;

 PUSBKGTCExecutor pus_bkg_tc_executor;
