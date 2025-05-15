
#include "handlers/uart_handler.h"

__status_int32_t CRISCVUARTHandler__handle(void * const __this,
                                           uint32_t _vector) {
    
    CRISCVUARTHandler * self = (CRISCVUARTHandler *)__this;

    #line 29 "src/handlers/uart_handler.fin"
    __option_uint8_t result;
    #line 29 "src/handlers/uart_handler.fin"
    result.__variant = None;

    #line 30 "src/handlers/uart_handler.fin"
    __status_int32_t ret;
    #line 30 "src/handlers/uart_handler.fin"
    ret.__variant = Success;

    #line 31 "src/handlers/uart_handler.fin"
    uint8_t tc_frame[4U];
    #line 31 "src/handlers/uart_handler.fin"
    tc_frame[0U] = 0xBEU;
    #line 31 "src/handlers/uart_handler.fin"
    tc_frame[1U] = 0xBAU;
    #line 31 "src/handlers/uart_handler.fin"
    tc_frame[2U] = 0xBEU;
    #line 31 "src/handlers/uart_handler.fin"
    tc_frame[3U] = 0xEFU;

    #line 33 "src/handlers/uart_handler.fin"
    self->uart.riscv_getchar(self->uart.__that, &result);

    #line 35 "src/handlers/uart_handler.fin"
    for (size_t i = 0U; i < 256U && (result.__variant == Some && ret.__variant == Success && self->handler_state.__variant == RISCVUARTHandlerState__RXTelecommandFinished == 0); i = i + 1U) {
        
        #line 42 "src/handlers/uart_handler.fin"
        if (result.__variant == Some) {
            
            #line 40 "src/handlers/uart_handler.fin"
            uint8_t data = result.Some.__0;

            #line 46 "src/handlers/uart_handler.fin"
            if (self->handler_state.__variant == RISCVUARTHandlerState__RXFrameHeader) {
                
                #line 44 "src/handlers/uart_handler.fin"
                size_t current = self->handler_state.RXFrameHeader.__0;

                #line 48 "src/handlers/uart_handler.fin"
                if (tc_frame[__termina_array__index(4U, current)] == data) {
                    
                    #line 51 "src/handlers/uart_handler.fin"
                    if (current == 3U) {
                        
                        #line 52 "src/handlers/uart_handler.fin"
                        self->handler_state.__variant = RISCVUARTHandlerState__RXTelecommandSize;
                        #line 52 "src/handlers/uart_handler.fin"
                        self->handler_state.RXTelecommandSize.__0 = 1;

                    } else
                    {
                        
                        #line 54 "src/handlers/uart_handler.fin"
                        self->handler_state.__variant = RISCVUARTHandlerState__RXFrameHeader;
                        #line 54 "src/handlers/uart_handler.fin"
                        self->handler_state.RXFrameHeader.__0 = current + 1U;

                    }

                } else
                {
                    
                    #line 59 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = RISCVUARTHandlerState__RXFrameHeader;
                    #line 59 "src/handlers/uart_handler.fin"
                    self->handler_state.RXFrameHeader.__0 = 0U;

                }

            } else
            #line 65 "src/handlers/uart_handler.fin"
            if (self->handler_state.__variant == RISCVUARTHandlerState__RXTelecommandSize) {
                
                #line 44 "src/handlers/uart_handler.fin"
                _Bool first = self->handler_state.RXTelecommandSize.__0;

                #line 67 "src/handlers/uart_handler.fin"
                if (first == 1) {
                    
                    #line 68 "src/handlers/uart_handler.fin"
                    self->telecommand.tc_num_bytes = (size_t)data;

                    #line 69 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = RISCVUARTHandlerState__RXTelecommandSize;
                    #line 69 "src/handlers/uart_handler.fin"
                    self->handler_state.RXTelecommandSize.__0 = 0;

                } else
                {
                    
                    #line 71 "src/handlers/uart_handler.fin"
                    self->telecommand.tc_num_bytes = (size_t)(self->telecommand.tc_num_bytes << 8U) | (size_t)data;

                    #line 72 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = RISCVUARTHandlerState__RXTelecommand;
                    #line 72 "src/handlers/uart_handler.fin"
                    self->handler_state.RXTelecommand.__0 = 0U;

                }

            } else
            #line 77 "src/handlers/uart_handler.fin"
            if (self->handler_state.__variant == RISCVUARTHandlerState__RXTelecommand) {
                
                #line 44 "src/handlers/uart_handler.fin"
                size_t current = self->handler_state.RXTelecommand.__0;

                #line 79 "src/handlers/uart_handler.fin"
                self->telecommand.tc_bytes[__termina_array__index(256U,
                                                                  (size_t)current)] = data;

                #line 82 "src/handlers/uart_handler.fin"
                if (self->telecommand.tc_num_bytes == (size_t)(current + 1U)) {
                    
                    #line 83 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = RISCVUARTHandlerState__RXTelecommandFinished;

                } else
                {
                    
                    #line 85 "src/handlers/uart_handler.fin"
                    self->handler_state.__variant = RISCVUARTHandlerState__RXTelecommand;
                    #line 85 "src/handlers/uart_handler.fin"
                    self->handler_state.RXTelecommand.__0 = current + 1U;

                }

            } else
            {
                

            }

            #line 96 "src/handlers/uart_handler.fin"
            self->uart.riscv_getchar(self->uart.__that, &result);

        } else
        {
            

        }

    }

    #line 106 "src/handlers/uart_handler.fin"
    if (self->handler_state.__variant == RISCVUARTHandlerState__RXTelecommandFinished) {
        
        #line 110 "src/handlers/uart_handler.fin"
        __option_box_t tc_handler;
        #line 110 "src/handlers/uart_handler.fin"
        tc_handler.__variant = None;

        #line 111 "src/handlers/uart_handler.fin"
        self->a_tc_handler_pool.alloc(self->a_tc_handler_pool.__that,
                                      &tc_handler);

        #line 115 "src/handlers/uart_handler.fin"
        if (tc_handler.__variant == Some) {
            
            #line 113 "src/handlers/uart_handler.fin"
            __termina_box_t b_tc_handler = tc_handler.Some.__0;

            #line 117 "src/handlers/uart_handler.fin"
            tc_handler_build_from_descriptor((TCHandlerT *)b_tc_handler.data,
                                             &self->telecommand);

            #line 119 "src/handlers/uart_handler.fin"
            self->handler_state.__variant = RISCVUARTHandlerState__RXFrameHeader;
            #line 119 "src/handlers/uart_handler.fin"
            self->handler_state.RXFrameHeader.__0 = 0U;

            #line 120 "src/handlers/uart_handler.fin"
            __termina_out_port__send(self->tc_message_queue_output,
                                     (void *)&b_tc_handler);

        } else
        {
            
            #line 125 "src/handlers/uart_handler.fin"
            ret.__variant = Failure;
            #line 125 "src/handlers/uart_handler.fin"
            ret.Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 131 "src/handlers/uart_handler.fin"
    return ret;

}
