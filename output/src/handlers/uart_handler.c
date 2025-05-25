
#include "handlers/uart_handler.h"

__status_int32_t UARTHandler__handle(void * const __this, uint32_t _vector) {
    
    UARTHandler * self = (UARTHandler *)__this;

    #line 61 "src/handlers/uart_handler.fin"
    __option_uint8_t result;
    #line 61 "src/handlers/uart_handler.fin"
    result.__variant = None;

    #line 62 "src/handlers/uart_handler.fin"
    __status_int32_t ret;
    #line 62 "src/handlers/uart_handler.fin"
    ret.__variant = Success;

    #line 63 "src/handlers/uart_handler.fin"
    uint8_t tc_frame[4U];
    #line 63 "src/handlers/uart_handler.fin"
    tc_frame[0U] = 0xBEU;
    #line 63 "src/handlers/uart_handler.fin"
    tc_frame[1U] = 0xBAU;
    #line 63 "src/handlers/uart_handler.fin"
    tc_frame[2U] = 0xBEU;
    #line 63 "src/handlers/uart_handler.fin"
    tc_frame[3U] = 0xEFU;

    #line 65 "src/handlers/uart_handler.fin"
    self->uart.getchar(self->uart.__that, &result);

    #line 67 "src/handlers/uart_handler.fin"
    for (size_t i = 0U; i < 256U && (result.__variant == Some && ret.__variant == Success && self->handler_state.__variant == UARTHandlerState__RXTelecommandFinished == 0); i = i + 1U) {
        
        #line 74 "src/handlers/uart_handler.fin"
        if (result.__variant == Some) {
            
            #line 72 "src/handlers/uart_handler.fin"
            uint8_t data = result.Some.__0;

            #line 78 "src/handlers/uart_handler.fin"
            if (self->handler_state.__variant == UARTHandlerState__RXFrameHeader) {
                
                #line 76 "src/handlers/uart_handler.fin"
                size_t current = self->handler_state.RXFrameHeader.__0;

                #line 80 "src/handlers/uart_handler.fin"
                if (tc_frame[__termina_array__index(4U, current)] == data) {
                    
                    #line 82 "src/handlers/uart_handler.fin"
                    if (current == 3U) {
                        
                        #line 83 "src/handlers/uart_handler.fin"
                        self->handler_state.__variant = UARTHandlerState__RXTelecommandSize;
                        #line 83 "src/handlers/uart_handler.fin"
                        self->handler_state.RXTelecommandSize.__0 = 1;

                    } else
                    {
                        
                        #line 85 "src/handlers/uart_handler.fin"
                        self->handler_state.__variant = UARTHandlerState__RXFrameHeader;
                        #line 85 "src/handlers/uart_handler.fin"
                        self->handler_state.RXFrameHeader.__0 = current + 1U;

                    }

                } else
                {
                    
                    #line 90 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = UARTHandlerState__RXFrameHeader;
                    #line 90 "src/handlers/uart_handler.fin"
                    self->handler_state.RXFrameHeader.__0 = 0U;

                }

            } else
            #line 96 "src/handlers/uart_handler.fin"
            if (self->handler_state.__variant == UARTHandlerState__RXTelecommandSize) {
                
                #line 76 "src/handlers/uart_handler.fin"
                _Bool first = self->handler_state.RXTelecommandSize.__0;

                #line 98 "src/handlers/uart_handler.fin"
                if (first == 1) {
                    
                    #line 99 "src/handlers/uart_handler.fin"
                    self->telecommand.tc_num_bytes = (size_t)data;

                    #line 100 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = UARTHandlerState__RXTelecommandSize;
                    #line 100 "src/handlers/uart_handler.fin"
                    self->handler_state.RXTelecommandSize.__0 = 0;

                } else
                {
                    
                    #line 102 "src/handlers/uart_handler.fin"
                    self->telecommand.tc_num_bytes = (size_t)(self->telecommand.tc_num_bytes << 8U) | (size_t)data;

                    #line 103 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = UARTHandlerState__RXTelecommand;
                    #line 103 "src/handlers/uart_handler.fin"
                    self->handler_state.RXTelecommand.__0 = 0U;

                }

            } else
            #line 108 "src/handlers/uart_handler.fin"
            if (self->handler_state.__variant == UARTHandlerState__RXTelecommand) {
                
                #line 76 "src/handlers/uart_handler.fin"
                size_t current = self->handler_state.RXTelecommand.__0;

                #line 110 "src/handlers/uart_handler.fin"
                self->telecommand.tc_bytes[__termina_array__index(256U,
                                                                  (size_t)current)] = data;

                #line 113 "src/handlers/uart_handler.fin"
                if (self->telecommand.tc_num_bytes == (size_t)(current + 1U)) {
                    
                    #line 114 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = UARTHandlerState__RXTelecommandFinished;

                } else
                {
                    
                    #line 116 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = UARTHandlerState__RXTelecommand;
                    #line 116 "src/handlers/uart_handler.fin"
                    self->handler_state.RXTelecommand.__0 = current + 1U;

                }

            } else
            {
                

            }

            #line 127 "src/handlers/uart_handler.fin"
            self->uart.getchar(self->uart.__that, &result);

        } else
        {
            

        }

    }

    #line 137 "src/handlers/uart_handler.fin"
    if (self->handler_state.__variant == UARTHandlerState__RXTelecommandFinished) {
        
        #line 139 "src/handlers/uart_handler.fin"
        __option_box_t tc_handler;
        #line 139 "src/handlers/uart_handler.fin"
        tc_handler.__variant = None;

        #line 140 "src/handlers/uart_handler.fin"
        self->a_tc_handler_pool.alloc(self->a_tc_handler_pool.__that,
                                      &tc_handler);

        #line 144 "src/handlers/uart_handler.fin"
        if (tc_handler.__variant == Some) {
            
            #line 142 "src/handlers/uart_handler.fin"
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            #line 146 "src/handlers/uart_handler.fin"
            tc_handler_build_from_descriptor((TCHandlerT *)b_tc_handler.data,
                                             &self->telecommand);

            #line 148 "src/handlers/uart_handler.fin"
            self->handler_state.__variant = UARTHandlerState__RXFrameHeader;
            #line 148 "src/handlers/uart_handler.fin"
            self->handler_state.RXFrameHeader.__0 = 0U;

            #line 149 "src/handlers/uart_handler.fin"
            __termina_out_port__send(self->tc_message_queue_output,
                                     (void *)&b_tc_handler);

        } else
        {
            
            #line 154 "src/handlers/uart_handler.fin"
            ret.__variant = Failure;
            #line 154 "src/handlers/uart_handler.fin"
            ret.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 160 "src/handlers/uart_handler.fin"
    return ret;

}
