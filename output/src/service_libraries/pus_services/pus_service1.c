
#include "service_libraries/pus_services/pus_service1.h"

const uint8_t TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH = 1U;

const uint8_t TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR = 2U;

const uint8_t TM_1_4_TC_2_X_DEVICE_NOT_VALID = 3U;

const uint8_t TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID = 4U;

const uint8_t TM_1_4_TC_3_X_INVALID_SID = 5U;

const uint8_t TM_1_4_TC_4_7_PID_STATS_UNDEFINED = 6U;

const uint8_t TM_1_4_TC_5_X_INVALID_EV_ID = 7U;

const uint8_t TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS = 8U;

const uint8_t TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY = 9U;

const uint8_t TM_1_4_TC_6_X_OUT_OF_MEMORY_ID_LIMITS = 10U;

const uint8_t TM_1_4_TC_11_X_SCHED_TC_REJECTED = 11U;

const uint8_t TM_1_4_TC_11_X_INVALID_SCHED_TIME = 12U;

const uint8_t TM_1_4_TC_12_X_PMON_UNDEFINED = 13U;

const uint8_t TM_1_4_TC_12_X_PMON_DEFINED = 14U;

const uint8_t TM_1_4_TC_12_X_PMON_ENABLED = 15U;

const uint8_t TM_1_4_TC_12_X_INVALID_PMONID = 16U;

const uint8_t TM_1_4_TC_12_X_INVALID_PMON_DEFINITION = 17U;

const uint8_t TM_1_4_TC_15_X_INVALID_PACKET_STORE = 18U;

const uint8_t TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED = 19U;

const uint8_t TM_1_4_TC_19_1_EV_ACTION_REJECTED = 20U;

const uint8_t TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED = 21U;

const uint8_t TM_1_4_TC_20_X_INVALID_PID = 22U;

const uint8_t TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC = 23U;

const uint8_t TM_1_4_ERROR_IN_ACCEPTANCE = 24U;

const uint8_t TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA = 1U;

const uint8_t TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR = 2U;

const uint8_t TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG = 3U;

const uint8_t TM_1_8_TC_6_X_MEM_ACCESS_FAIL = 4U;

const uint8_t TM_1_8_TC_11_X_SCHED_TC_POOL_EMPTY = 5U;

const uint8_t TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED = 6U;

void PUSService1__notify_tm_1_1(const __termina_event_t * const __ev,
                                void * const __this, uint16_t tc_packet_id,
                                uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                                __status_int32_t * const status) {
    
    #line 397 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 397 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 401 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 403 "src/service_libraries/pus_services/pus_service1.fin"
    if (is_tc_ack_accept_enabled(flags_ack)) {
        
        #line 405 "src/service_libraries/pus_services/pus_service1.fin"
        __option_box_t tm_handler;
        #line 405 "src/service_libraries/pus_services/pus_service1.fin"
        tm_handler.__variant = None;

        #line 407 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                    &tm_handler);

        #line 411 "src/service_libraries/pus_services/pus_service1.fin"
        if (tm_handler.__variant == Some) {
            
            #line 409 "src/service_libraries/pus_services/pus_service1.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 413 "src/service_libraries/pus_services/pus_service1.fin"
            MissionOBT current_obt;
            #line 413 "src/service_libraries/pus_services/pus_service1.fin"
            current_obt.finetime = 0U;
            #line 413 "src/service_libraries/pus_services/pus_service1.fin"
            current_obt.seconds = 0U;

            #line 417 "src/service_libraries/pus_services/pus_service1.fin"
            uint16_t tm_count = 0U;

            #line 419 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 420 "src/service_libraries/pus_services/pus_service1.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                              &current_obt);

            #line 422 "src/service_libraries/pus_services/pus_service1.fin"
            startup_tm((TMHandler *)b_tm_handler.data);

            #line 424 "src/service_libraries/pus_services/pus_service1.fin"
            *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                               tc_packet_id);

            #line 426 "src/service_libraries/pus_services/pus_service1.fin"
            if ((*status).__variant == Success) {
                
                #line 427 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                   tc_packet_seq_ctrl);

            }

            #line 430 "src/service_libraries/pus_services/pus_service1.fin"
            if ((*status).__variant == Success) {
                
                #line 431 "src/service_libraries/pus_services/pus_service1.fin"
                close_tm((TMHandler *)b_tm_handler.data, 1U, 1U, tm_count,
                         current_obt);

                #line 432 "src/service_libraries/pus_services/pus_service1.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else
            {
                
                #line 434 "src/service_libraries/pus_services/pus_service1.fin"
                self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                           b_tm_handler);

            }

        } else
        {
            
            #line 440 "src/service_libraries/pus_services/pus_service1.fin"
            (*status).__variant = Failure;
            #line 440 "src/service_libraries/pus_services/pus_service1.fin"
            (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 446 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 446 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__notify_tm_1_3(const __termina_event_t * const __ev,
                                void * const __this, uint16_t tc_packet_id,
                                uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                                __status_int32_t * const status) {
    
    #line 564 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 564 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 568 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 570 "src/service_libraries/pus_services/pus_service1.fin"
    if (is_tc_ack_start_exec_enabled(flags_ack)) {
        
        #line 572 "src/service_libraries/pus_services/pus_service1.fin"
        __option_box_t tm_handler;
        #line 572 "src/service_libraries/pus_services/pus_service1.fin"
        tm_handler.__variant = None;

        #line 574 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                    &tm_handler);

        #line 578 "src/service_libraries/pus_services/pus_service1.fin"
        if (tm_handler.__variant == Some) {
            
            #line 576 "src/service_libraries/pus_services/pus_service1.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 580 "src/service_libraries/pus_services/pus_service1.fin"
            MissionOBT current_obt;
            #line 580 "src/service_libraries/pus_services/pus_service1.fin"
            current_obt.finetime = 0U;
            #line 580 "src/service_libraries/pus_services/pus_service1.fin"
            current_obt.seconds = 0U;

            #line 584 "src/service_libraries/pus_services/pus_service1.fin"
            uint16_t tm_count = 0U;

            #line 586 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 587 "src/service_libraries/pus_services/pus_service1.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                              &current_obt);

            #line 589 "src/service_libraries/pus_services/pus_service1.fin"
            startup_tm((TMHandler *)b_tm_handler.data);

            #line 590 "src/service_libraries/pus_services/pus_service1.fin"
            *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                               tc_packet_id);

            #line 592 "src/service_libraries/pus_services/pus_service1.fin"
            if ((*status).__variant == Success) {
                
                #line 593 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                   tc_packet_seq_ctrl);

            }

            #line 596 "src/service_libraries/pus_services/pus_service1.fin"
            if ((*status).__variant == Success) {
                
                #line 597 "src/service_libraries/pus_services/pus_service1.fin"
                close_tm((TMHandler *)b_tm_handler.data, 1U, 3U, tm_count,
                         current_obt);

                #line 598 "src/service_libraries/pus_services/pus_service1.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else
            {
                
                #line 600 "src/service_libraries/pus_services/pus_service1.fin"
                self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                           b_tm_handler);

            }

        } else
        {
            
            #line 606 "src/service_libraries/pus_services/pus_service1.fin"
            (*status).__variant = Failure;
            #line 606 "src/service_libraries/pus_services/pus_service1.fin"
            (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 612 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 612 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__notify_tm_1_7(const __termina_event_t * const __ev,
                                void * const __this, uint16_t tc_packet_id,
                                uint16_t tc_packet_seq_ctrl, uint8_t flags_ack,
                                __status_int32_t * const status) {
    
    #line 1516 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1516 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1520 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1522 "src/service_libraries/pus_services/pus_service1.fin"
    if (is_tc_ack_completion_exec_enabled(flags_ack)) {
        
        #line 1524 "src/service_libraries/pus_services/pus_service1.fin"
        __option_box_t tm_handler;
        #line 1524 "src/service_libraries/pus_services/pus_service1.fin"
        tm_handler.__variant = None;

        #line 1526 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                    &tm_handler);

        #line 1530 "src/service_libraries/pus_services/pus_service1.fin"
        if (tm_handler.__variant == Some) {
            
            #line 1528 "src/service_libraries/pus_services/pus_service1.fin"
            __termina_box_t b_tm_handler = tm_handler.Some.__0;

            #line 1532 "src/service_libraries/pus_services/pus_service1.fin"
            MissionOBT current_obt;
            #line 1532 "src/service_libraries/pus_services/pus_service1.fin"
            current_obt.finetime = 0U;
            #line 1532 "src/service_libraries/pus_services/pus_service1.fin"
            current_obt.seconds = 0U;

            #line 1536 "src/service_libraries/pus_services/pus_service1.fin"
            uint16_t tm_count = 0U;

            #line 1538 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                               &tm_count);

            #line 1539 "src/service_libraries/pus_services/pus_service1.fin"
            self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                              &current_obt);

            #line 1541 "src/service_libraries/pus_services/pus_service1.fin"
            startup_tm((TMHandler *)b_tm_handler.data);

            #line 1542 "src/service_libraries/pus_services/pus_service1.fin"
            *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                               tc_packet_id);

            #line 1544 "src/service_libraries/pus_services/pus_service1.fin"
            if ((*status).__variant == Success) {
                
                #line 1545 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                   tc_packet_seq_ctrl);

            }

            #line 1548 "src/service_libraries/pus_services/pus_service1.fin"
            if ((*status).__variant == Success) {
                
                #line 1549 "src/service_libraries/pus_services/pus_service1.fin"
                close_tm((TMHandler *)b_tm_handler.data, 1U, 7U, tm_count,
                         current_obt);

                #line 1550 "src/service_libraries/pus_services/pus_service1.fin"
                self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                         b_tm_handler, status);

            } else
            {
                
                #line 1552 "src/service_libraries/pus_services/pus_service1.fin"
                self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                           b_tm_handler);

            }

        } else
        {
            
            #line 1558 "src/service_libraries/pus_services/pus_service1.fin"
            (*status).__variant = Failure;
            #line 1558 "src/service_libraries/pus_services/pus_service1.fin"
            (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

        }

    }

    #line 1564 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1564 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_2(const __termina_event_t * const __ev,
                              void * const __this,
                              const TCStatus * const tc_status,
                              const TCHandler * const tc_handler,
                              __status_int32_t * const status) {
    
    #line 450 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 450 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 453 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 455 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 455 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 457 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 461 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 459 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 463 "src/service_libraries/pus_services/pus_service1.fin"
        uint8_t error_code = 0U;

        #line 465 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 465 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 465 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 469 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 471 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 472 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 474 "src/service_libraries/pus_services/pus_service1.fin"
        startup_tm((TMHandler *)b_tm_handler.data);

        #line 475 "src/service_libraries/pus_services/pus_service1.fin"
        *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                           tc_handler->packet_header.packet_id);

        #line 477 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 478 "src/service_libraries/pus_services/pus_service1.fin"
            *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                               tc_handler->packet_error_ctrl);

        }

        #line 481 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 485 "src/service_libraries/pus_services/pus_service1.fin"
            if (tc_status->error_code.__variant == TCErrorType__CRCError) {
                
                #line 487 "src/service_libraries/pus_services/pus_service1.fin"
                error_code = 2U;

                #line 489 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                  error_code);

                #line 491 "src/service_libraries/pus_services/pus_service1.fin"
                uint16_t calculated_crc = cal_crc_16(tc_handler->tc_descriptor.tc_bytes,
                                                     tc_handler->tc_descriptor.tc_num_bytes - 2U);

                #line 495 "src/service_libraries/pus_services/pus_service1.fin"
                if ((*status).__variant == Success) {
                    
                    #line 496 "src/service_libraries/pus_services/pus_service1.fin"
                    *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                       tc_handler->packet_error_ctrl);

                }

                #line 499 "src/service_libraries/pus_services/pus_service1.fin"
                if ((*status).__variant == Success) {
                    
                    #line 500 "src/service_libraries/pus_services/pus_service1.fin"
                    *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                       calculated_crc);

                }

            } else
            #line 504 "src/service_libraries/pus_services/pus_service1.fin"
            if (tc_status->error_code.__variant == TCErrorType__APIDError) {
                
                #line 506 "src/service_libraries/pus_services/pus_service1.fin"
                error_code = 3U;

                #line 507 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                  error_code);

            } else
            #line 510 "src/service_libraries/pus_services/pus_service1.fin"
            if (tc_status->error_code.__variant == TCErrorType__SourceIDError) {
                
                #line 512 "src/service_libraries/pus_services/pus_service1.fin"
                error_code = 4U;

                #line 513 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                  error_code);

                #line 515 "src/service_libraries/pus_services/pus_service1.fin"
                if ((*status).__variant == Success) {
                    
                    #line 516 "src/service_libraries/pus_services/pus_service1.fin"
                    *status = append_u16_appdata_field((TMHandler *)b_tm_handler.data,
                                                       (uint16_t)tc_handler->df_header.sourceID);

                }

            } else
            #line 521 "src/service_libraries/pus_services/pus_service1.fin"
            if (tc_status->error_code.__variant == TCErrorType__TypeError) {
                
                #line 523 "src/service_libraries/pus_services/pus_service1.fin"
                error_code = 5U;

                #line 524 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                  error_code);

                #line 526 "src/service_libraries/pus_services/pus_service1.fin"
                if ((*status).__variant == Success) {
                    
                    #line 527 "src/service_libraries/pus_services/pus_service1.fin"
                    *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                      tc_handler->df_header.type);

                }

            } else
            #line 531 "src/service_libraries/pus_services/pus_service1.fin"
            if (tc_status->error_code.__variant == TCErrorType__SubTypeError) {
                
                #line 533 "src/service_libraries/pus_services/pus_service1.fin"
                error_code = 6U;

                #line 534 "src/service_libraries/pus_services/pus_service1.fin"
                *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                  error_code);

                #line 535 "src/service_libraries/pus_services/pus_service1.fin"
                if ((*status).__variant == Success) {
                    
                    #line 536 "src/service_libraries/pus_services/pus_service1.fin"
                    *status = append_u8_appdata_field((TMHandler *)b_tm_handler.data,
                                                      tc_handler->df_header.subtype);

                }

            } else
            {
                

            }

        }

        #line 546 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 547 "src/service_libraries/pus_services/pus_service1.fin"
            close_tm((TMHandler *)b_tm_handler.data, 1U, 2U, tm_count,
                     current_obt);

            #line 548 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 550 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 555 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 555 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 560 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 560 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_EvID_not_valid(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t EvID,
                                             __status_int32_t * const status) {
    
    #line 904 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 904 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 907 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 909 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 909 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 911 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 915 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 913 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 917 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 917 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 917 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 921 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 923 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 924 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 926 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 926 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 928 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_5_X_INVALID_EV_ID,
                                                EvID, current_obt);

        #line 932 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 933 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 935 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 941 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 941 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 946 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 946 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PID_not_valid(const __termina_event_t * const __ev,
                                            void * const __this,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_seq_ctrl,
                                            uint16_t PID,
                                            __status_int32_t * const status) {
    
    #line 952 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 952 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 955 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 957 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 957 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 959 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 963 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 961 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 965 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 965 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 965 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 969 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 971 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 972 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 974 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 974 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 976 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_20_X_INVALID_PID, PID,
                                                current_obt);

        #line 980 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 981 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 983 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 989 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 989 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 994 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 994 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PID_read_only_via_TC(const __termina_event_t * const __ev,
                                                   void * const __this,
                                                   uint16_t tc_packet_id,
                                                   uint16_t tc_packet_seq_ctrl,
                                                   uint16_t PID,
                                                   __status_int32_t * const status) {
    
    #line 1422 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1422 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1425 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1427 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1427 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1429 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1433 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1431 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1435 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1435 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1435 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1439 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1441 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1442 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1444 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1444 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1446 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_20_X_PID_READ_ONLY_VIA_TC,
                                                PID, current_obt);

        #line 1450 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1451 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1453 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1459 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1459 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1464 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1464 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PID_stats_undefined(const __termina_event_t * const __ev,
                                                  void * const __this,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  uint16_t PID,
                                                  __status_int32_t * const status) {
    
    #line 1375 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1375 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1378 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1380 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1380 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1382 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1386 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1384 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1388 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1388 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1388 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1392 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1394 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1395 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1397 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1397 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1399 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_4_7_PID_STATS_UNDEFINED,
                                                PID, current_obt);

        #line 1403 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1404 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1406 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1412 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1412 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1417 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1417 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PMONID_invalid(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t PMONID,
                                             __status_int32_t * const status) {
    
    #line 1140 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1140 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1143 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1145 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1145 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1147 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1151 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1149 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1153 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1153 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1153 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1157 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1159 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1160 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1162 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1162 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1164 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_12_X_INVALID_PMONID,
                                                PMONID, current_obt);

        #line 1168 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1169 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1171 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1177 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1177 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1182 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1182 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PMON_defined(const __termina_event_t * const __ev,
                                           void * const __this,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_seq_ctrl,
                                           uint16_t PMONID,
                                           __status_int32_t * const status) {
    
    #line 1046 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1046 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1049 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1051 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1051 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1053 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1057 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1055 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1059 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1059 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1059 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1063 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1065 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1066 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1068 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1068 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1070 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_12_X_PMON_DEFINED,
                                                PMONID, current_obt);

        #line 1074 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1075 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1077 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1083 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1083 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1088 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1088 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PMON_definition_invalid(const __termina_event_t * const __ev,
                                                      void * const __this,
                                                      uint16_t tc_packet_id,
                                                      uint16_t tc_packet_seq_ctrl,
                                                      uint16_t PMONID,
                                                      __status_int32_t * const status) {
    
    #line 1186 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1186 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1189 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1191 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1191 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1193 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1197 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1195 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1199 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1199 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1199 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1203 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1205 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1206 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1208 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1208 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1210 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_12_X_INVALID_PMON_DEFINITION,
                                                PMONID, current_obt);

        #line 1214 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1215 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1217 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1223 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1223 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1228 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1228 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PMON_enabled(const __termina_event_t * const __ev,
                                           void * const __this,
                                           uint16_t tc_packet_id,
                                           uint16_t tc_packet_seq_ctrl,
                                           uint16_t PMONID,
                                           __status_int32_t * const status) {
    
    #line 1093 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1093 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1096 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1098 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1098 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1100 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1104 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1102 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1106 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1106 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1106 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1110 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1112 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1113 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1115 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1115 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1117 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_12_X_PMON_ENABLED,
                                                PMONID, current_obt);

        #line 1121 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1122 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1124 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1130 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1130 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1135 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1135 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_PMON_undefined(const __termina_event_t * const __ev,
                                             void * const __this,
                                             uint16_t tc_packet_id,
                                             uint16_t tc_packet_seq_ctrl,
                                             uint16_t PMONID,
                                             __status_int32_t * const status) {
    
    #line 999 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 999 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1002 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1004 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1004 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1006 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1010 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1008 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1012 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1012 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1012 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1016 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1018 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1019 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1021 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1021 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1023 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_12_X_PMON_UNDEFINED,
                                                PMONID, current_obt);

        #line 1027 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1028 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1030 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1036 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1036 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1041 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1041 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_SID_not_valid(const __termina_event_t * const __ev,
                                            void * const __this,
                                            uint16_t tc_packet_id,
                                            uint16_t tc_packet_seq_ctrl,
                                            uint16_t SID,
                                            __status_int32_t * const status) {
    
    #line 760 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 760 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 763 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 765 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 765 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 767 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 771 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 769 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 773 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 773 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 773 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 777 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 779 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 780 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 782 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 782 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 784 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_3_X_INVALID_SID, SID,
                                                current_obt);

        #line 788 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 789 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 791 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 796 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 796 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 801 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 801 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_device_address_not_valid(const __termina_event_t * const __ev,
                                                       void * const __this,
                                                       uint16_t tc_packet_id,
                                                       uint16_t tc_packet_seq_ctrl,
                                                       uint32_t device_address,
                                                       __status_int32_t * const status) {
    
    #line 712 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 712 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 715 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 717 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 717 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 719 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 723 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 721 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 725 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 725 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 725 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 729 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 731 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 732 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 734 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 734 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 736 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u32_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_2_X_DEVICE_ADDRESS_NOT_VALID,
                                                device_address, current_obt);

        #line 741 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 742 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 744 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 750 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 750 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 755 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 755 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_error_in_acceptance(const __termina_event_t * const __ev,
                                                  void * const __this,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  __status_int32_t * const status) {
    
    #line 1469 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1469 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1472 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1474 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1474 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1476 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1480 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1478 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1482 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1482 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1482 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1486 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1488 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1489 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1491 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1491 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1493 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_no_failure_data((TMHandler *)b_tm_handler.data,
                                               tm_count, tc_packet_id,
                                               tc_packet_seq_ctrl, verify_stage,
                                               TM_1_4_ERROR_IN_ACCEPTANCE,
                                               current_obt);

        #line 1497 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1498 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1500 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1506 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1506 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1511 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1511 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_ev_action_enabled(const __termina_event_t * const __ev,
                                                void * const __this,
                                                uint16_t tc_packet_id,
                                                uint16_t tc_packet_seq_ctrl,
                                                uint16_t event_ID,
                                                __status_int32_t * const status) {
    
    #line 1233 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1233 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1236 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1238 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1238 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1240 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1244 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1242 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1246 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1246 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1246 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1250 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1252 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1253 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1255 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1255 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1257 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_19_X_EV_ACTION_IS_ENABLED,
                                                event_ID, current_obt);

        #line 1261 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1262 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1264 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1270 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1270 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1275 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1275 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_ev_action_rejected(const __termina_event_t * const __ev,
                                                 void * const __this,
                                                 uint16_t tc_packet_id,
                                                 uint16_t tc_packet_seq_ctrl,
                                                 uint16_t event_ID,
                                                 __status_int32_t * const status) {
    
    #line 1280 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1280 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1283 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1285 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1285 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1287 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1291 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1289 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1293 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1293 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1293 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1297 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1299 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1300 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1302 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1302 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1304 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_19_1_EV_ACTION_REJECTED,
                                                event_ID, current_obt);

        #line 1308 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1309 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1311 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1317 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1317 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1322 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1322 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_ev_action_undefined(const __termina_event_t * const __ev,
                                                  void * const __this,
                                                  uint16_t tc_packet_id,
                                                  uint16_t tc_packet_seq_ctrl,
                                                  uint16_t event_ID,
                                                  __status_int32_t * const status) {
    
    #line 1328 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1328 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1331 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1333 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1333 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1335 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1339 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1337 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1341 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1341 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1341 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1345 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1347 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1348 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1350 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1350 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 1352 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_19_X_EV_ACTION_NOT_DEFINED,
                                                event_ID, current_obt);

        #line 1356 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1357 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1359 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1365 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1365 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1370 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1370 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_mem_address_not_valid(const __termina_event_t * const __ev,
                                                    void * const __this,
                                                    uint16_t tc_packet_id,
                                                    uint16_t tc_packet_seq_ctrl,
                                                    uint8_t mem_id,
                                                    uint32_t mem_address,
                                                    __status_int32_t * const status) {
    
    #line 806 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 806 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 810 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 812 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 812 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 814 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 818 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 816 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 820 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 820 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 820 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 824 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 826 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 827 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 829 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 829 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 831 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u8_u32_failure_data((TMHandler *)b_tm_handler.data,
                                                   tm_count, tc_packet_id,
                                                   tc_packet_seq_ctrl,
                                                   verify_stage,
                                                   TM_1_4_TC_6_X_INVALID_MEMORY_ADDRESS,
                                                   mem_id, mem_address,
                                                   current_obt);

        #line 836 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 837 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 839 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 845 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 845 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 850 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 850 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_mem_id_read_only(const __termina_event_t * const __ev,
                                               void * const __this,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               uint8_t mem_id,
                                               __status_int32_t * const status) {
    
    #line 855 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 855 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 859 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 861 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 861 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 863 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 867 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 865 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 869 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 869 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 869 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 873 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 875 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 876 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 878 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 878 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 880 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u8_failure_data((TMHandler *)b_tm_handler.data,
                                               tm_count, tc_packet_id,
                                               tc_packet_seq_ctrl, verify_stage,
                                               TM_1_4_TC_6_X_MEMORY_ID_READ_ONLY,
                                               mem_id, current_obt);

        #line 885 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 886 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 888 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 894 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 894 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 899 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 899 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_num_of_instr_not_valid(const __termina_event_t * const __ev,
                                                     void * const __this,
                                                     uint16_t tc_packet_id,
                                                     uint16_t tc_packet_seq_ctrl,
                                                     uint8_t N,
                                                     __status_int32_t * const status) {
    
    #line 666 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 666 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 669 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 671 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 671 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 673 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 677 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 675 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 679 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 679 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 679 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 683 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 685 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 686 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 688 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 688 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 690 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u8_failure_data((TMHandler *)b_tm_handler.data,
                                               tm_count, tc_packet_id,
                                               tc_packet_seq_ctrl, verify_stage,
                                               TM_1_4_TC_X_Y_TC_NOT_VALID_NUM_OF_INSTR,
                                               N, current_obt);

        #line 694 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 695 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 697 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 702 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 702 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 707 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 707 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_4_short_pack_length(const __termina_event_t * const __ev,
                                                void * const __this,
                                                uint16_t tc_packet_id,
                                                uint16_t tc_packet_seq_ctrl,
                                                size_t tc_bytes,
                                                __status_int32_t * const status) {
    
    #line 616 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 616 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 620 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 622 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 622 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 624 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 628 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 626 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 630 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 630 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 630 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 634 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 636 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 637 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 639 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 639 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecStart;

        #line 640 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t failure_data = (uint16_t)tc_bytes;

        #line 642 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_4_TC_X_Y_TC_SHORT_PACK_LENGTH,
                                                failure_data, current_obt);

        #line 647 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 648 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 650 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 656 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 656 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 661 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 661 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_8_device_command_exec_error(const __termina_event_t * const __ev,
                                                        void * const __this,
                                                        uint16_t tc_packet_id,
                                                        uint16_t tc_packet_seq_ctrl,
                                                        uint32_t on_off_command,
                                                        __status_int32_t * const status) {
    
    #line 1664 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1664 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1667 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1669 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1669 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1671 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1675 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1673 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1677 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1677 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1677 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1681 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1683 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1684 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1686 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1686 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecCompletion;

        #line 1688 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u32_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_8_TM_2_1_DEV_COMMAND_EXEC_ERROR,
                                                on_off_command, current_obt);

        #line 1693 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1694 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1696 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1702 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1702 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1707 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1707 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_8_max_ev_actions_defined(const __termina_event_t * const __ev,
                                                     void * const __this,
                                                     uint16_t tc_packet_id,
                                                     uint16_t tc_packet_seq_ctrl,
                                                     uint16_t evID,
                                                     __status_int32_t * const status) {
    
    #line 1568 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1568 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1571 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1573 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1573 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1575 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1579 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1577 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1581 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1581 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1581 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1585 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1587 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1588 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1590 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1590 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecCompletion;

        #line 1592 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED,
                                                evID, current_obt);

        #line 1597 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1598 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1600 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1606 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1606 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1611 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1611 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_8_mem_access_error(const __termina_event_t * const __ev,
                                               void * const __this,
                                               uint16_t tc_packet_id,
                                               uint16_t tc_packet_seq_ctrl,
                                               uint8_t mem_ID,
                                               __status_int32_t * const status) {
    
    #line 1760 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1760 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1763 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1765 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1765 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1767 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1771 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1769 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1773 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1773 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1773 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1777 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1779 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1780 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1782 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1782 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecCompletion;

        #line 1784 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u8_failure_data((TMHandler *)b_tm_handler.data,
                                               tm_count, tc_packet_id,
                                               tc_packet_seq_ctrl, verify_stage,
                                               TM_1_8_TC_6_X_MEM_ACCESS_FAIL,
                                               mem_ID, current_obt);

        #line 1788 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1789 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1791 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1797 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1797 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1802 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1802 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_8_not_free_stats_config(const __termina_event_t * const __ev,
                                                    void * const __this,
                                                    uint16_t tc_packet_id,
                                                    uint16_t tc_packet_seq_ctrl,
                                                    uint16_t PID,
                                                    __status_int32_t * const status) {
    
    #line 1712 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1712 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1715 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1717 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1717 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1719 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1723 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1721 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1725 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1725 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1725 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1729 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1731 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1732 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1734 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1734 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecCompletion;

        #line 1736 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_u16_failure_data((TMHandler *)b_tm_handler.data,
                                                tm_count, tc_packet_id,
                                                tc_packet_seq_ctrl,
                                                verify_stage,
                                                TM_1_8_TC_4_1_NOT_FREE_PID_STATS_CONFIG,
                                                PID, current_obt);

        #line 1741 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1742 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1744 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1750 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1750 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1755 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1755 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}

void PUSService1__send_tm_1_8_tm_exceed_limit_appdata(const __termina_event_t * const __ev,
                                                      void * const __this,
                                                      uint16_t tc_packet_id,
                                                      uint16_t tc_packet_seq_ctrl,
                                                      __status_int32_t * const status) {
    
    #line 1617 "src/service_libraries/pus_services/pus_service1.fin"
    PUSService1 * self = (PUSService1 *)__this;

    #line 1617 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 1620 "src/service_libraries/pus_services/pus_service1.fin"
    (*status).__variant = Success;

    #line 1622 "src/service_libraries/pus_services/pus_service1.fin"
    __option_box_t tm_handler;
    #line 1622 "src/service_libraries/pus_services/pus_service1.fin"
    tm_handler.__variant = None;

    #line 1624 "src/service_libraries/pus_services/pus_service1.fin"
    self->tm_handler_pool.alloc(__ev, self->tm_handler_pool.__that,
                                &tm_handler);

    #line 1628 "src/service_libraries/pus_services/pus_service1.fin"
    if (tm_handler.__variant == Some) {
        
        #line 1626 "src/service_libraries/pus_services/pus_service1.fin"
        __termina_box_t b_tm_handler = tm_handler.Some.__0;

        #line 1630 "src/service_libraries/pus_services/pus_service1.fin"
        MissionOBT current_obt;
        #line 1630 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.finetime = 0U;
        #line 1630 "src/service_libraries/pus_services/pus_service1.fin"
        current_obt.seconds = 0U;

        #line 1634 "src/service_libraries/pus_services/pus_service1.fin"
        uint16_t tm_count = 0U;

        #line 1636 "src/service_libraries/pus_services/pus_service1.fin"
        self->tm_counter.get_next_tm_count(__ev, self->tm_counter.__that,
                                           &tm_count);

        #line 1637 "src/service_libraries/pus_services/pus_service1.fin"
        self->obt_manager.get_current_obt(__ev, self->obt_manager.__that,
                                          &current_obt);

        #line 1639 "src/service_libraries/pus_services/pus_service1.fin"
        TCVerifyStage verify_stage;
        #line 1639 "src/service_libraries/pus_services/pus_service1.fin"
        verify_stage.__variant = TCVerifyStage__ExecCompletion;

        #line 1641 "src/service_libraries/pus_services/pus_service1.fin"
        *status = build_tm_1_X_no_failure_data((TMHandler *)b_tm_handler.data,
                                               tm_count, tc_packet_id,
                                               tc_packet_seq_ctrl, verify_stage,
                                               TM_1_8_TM_X_Y_TM_EXCEED_LIMIT_APPDATA,
                                               current_obt);

        #line 1645 "src/service_libraries/pus_services/pus_service1.fin"
        if ((*status).__variant == Success) {
            
            #line 1646 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_channel.send_tm(__ev, self->tm_channel.__that,
                                     b_tm_handler, status);

        } else
        {
            
            #line 1648 "src/service_libraries/pus_services/pus_service1.fin"
            self->tm_handler_pool.free(__ev, self->tm_handler_pool.__that,
                                       b_tm_handler);

        }

    } else
    {
        
        #line 1654 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).__variant = Failure;
        #line 1654 "src/service_libraries/pus_services/pus_service1.fin"
        (*status).Failure.__0 = TM_POOL_ALLOC_FAILURE;

    }

    #line 1659 "src/service_libraries/pus_services/pus_service1.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 1659 "src/service_libraries/pus_services/pus_service1.fin"
    return;

}
