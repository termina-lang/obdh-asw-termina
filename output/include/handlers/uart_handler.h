#ifndef __HANDLERS__UART_HANDLER_H__
#define __HANDLERS__UART_HANDLER_H__

#include <termina.h>

#include "resources/uart.h"
#include "service_libraries/pus_tc_handler.h"
#include "service_libraries/serialize.h"
#include "service_libraries/tc_ccsds_pus_format.h"

#include "option.h"

typedef enum {
    UARTHandlerState__RXFrameHeader,
    UARTHandlerState__RXTelecommandSize,
    UARTHandlerState__RXTelecommand,
    UARTHandlerState__RXTelecommandFinished
} __enum_UARTHandlerState_t;

typedef struct {
    size_t __0;
} __enum_UARTHandlerState__RXFrameHeader_params_t;

typedef struct {
    _Bool __0;
} __enum_UARTHandlerState__RXTelecommandSize_params_t;

typedef struct {
    size_t __0;
} __enum_UARTHandlerState__RXTelecommand_params_t;

typedef struct {
    __enum_UARTHandlerState_t __variant;
    union {
        __enum_UARTHandlerState__RXFrameHeader_params_t RXFrameHeader;
        __enum_UARTHandlerState__RXTelecommandSize_params_t RXTelecommandSize;
        __enum_UARTHandlerState__RXTelecommand_params_t RXTelecommand;
    };
} UARTHandlerState;

typedef struct {
    __termina_id_t __handler_id;
    UARTHandlerState handler_state;
    TCDescriptorT telecommand;
    __termina_allocator_t a_tc_handler_pool;
    struct {
        void * __that;
        void (* getchar)(void * const, __option_uint8_t * const);
    } uart;
    __termina_out_port_t tc_message_queue_output;
} UARTHandler;

__status_int32_t UARTHandler__handle(void * const __this, uint32_t _vector);

#endif
