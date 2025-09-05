
#include "service_libraries/pus_services/pus_service2.h"

__status_int32_t PUSService2__dev_drv_on_off(const __termina_event_t * const __ev,
                                             PUSService2 * const self) {
    
    #line 113 "src/service_libraries/pus_services/pus_service2.fin"
    __status_int32_t status;
    #line 113 "src/service_libraries/pus_services/pus_service2.fin"
    status.__variant = Success;

    #line 115 "src/service_libraries/pus_services/pus_service2.fin"
    uint8_t led = (uint8_t)((uint32_t)(self->exec_tc_req_status_update.dev_address & 0xF0000000U) >> 28U);

    #line 116 "src/service_libraries/pus_services/pus_service2.fin"
    uint8_t on_off = (uint8_t)(self->exec_tc_req_status_update.dev_address & 0xFU);

    #line 118 "src/service_libraries/pus_services/pus_service2.fin"
    self->gpio_driver.write_led(__ev, self->gpio_driver.__that, led, on_off,
                                &status);

    #line 120 "src/service_libraries/pus_services/pus_service2.fin"
    return status;

}

_Bool PUSService2__device_drv_is_on_off_address_valid(const __termina_event_t * const __ev,
                                                      const PUSService2 * const self) {
    
    #line 93 "src/service_libraries/pus_services/pus_service2.fin"
    _Bool is_valid = 0;

    #line 94 "src/service_libraries/pus_services/pus_service2.fin"
    uint32_t device_address = self->exec_tc_req_status_update.dev_address;

    #line 96 "src/service_libraries/pus_services/pus_service2.fin"
    if (device_address == 0x60000001U || device_address == 0x70000001U
        || device_address == 0x80000001U
        || device_address == 0x90000001U
        || device_address == 0x60000000U
        || device_address == 0x70000000U
        || device_address == 0x80000000U
        || device_address == 0x90000000U) {
        
        #line 104 "src/service_libraries/pus_services/pus_service2.fin"
        is_valid = 1;

    }

    #line 107 "src/service_libraries/pus_services/pus_service2.fin"
    return is_valid;

}

__status_int32_t PUSService2__exec2_1TC(const __termina_event_t * const __ev,
                                        PUSService2 * const self) {
    
    #line 38 "src/service_libraries/pus_services/pus_service2.fin"
    __status_int32_t status;
    #line 38 "src/service_libraries/pus_services/pus_service2.fin"
    status.__variant = Success;

    #line 40 "src/service_libraries/pus_services/pus_service2.fin"
    if (self->exec_tc_req_status_update.N != 1U) {
        
        #line 42 "src/service_libraries/pus_services/pus_service2.fin"
        self->pus_service_1.send_tm_1_4_num_of_instr_not_valid(__ev,
                                                               self->pus_service_1.__that,
                                                               self->exec_tc_req_status_update.packet_id,
                                                               self->exec_tc_req_status_update.packet_seq_ctrl,
                                                               self->exec_tc_req_status_update.N,
                                                               &status);

    } else
    #line 47 "src/service_libraries/pus_services/pus_service2.fin"
    if (PUSService2__device_drv_is_on_off_address_valid(__ev, self) == 0) {
        
        #line 49 "src/service_libraries/pus_services/pus_service2.fin"
        self->pus_service_1.send_tm_1_4_device_address_not_valid(__ev,
                                                                 self->pus_service_1.__that,
                                                                 self->exec_tc_req_status_update.packet_id,
                                                                 self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                 self->exec_tc_req_status_update.dev_address,
                                                                 &status);

    } else
    {
        
        #line 56 "src/service_libraries/pus_services/pus_service2.fin"
        self->pus_service_1.notify_tm_1_3(__ev, self->pus_service_1.__that,
                                          self->exec_tc_req_status_update.packet_id,
                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                          self->exec_tc_req_status_update.flags_ack,
                                          &status);

        #line 62 "src/service_libraries/pus_services/pus_service2.fin"
        if (status.__variant == Success) {
            
            #line 64 "src/service_libraries/pus_services/pus_service2.fin"
            status = PUSService2__dev_drv_on_off(__ev, self);

            #line 66 "src/service_libraries/pus_services/pus_service2.fin"
            if (status.__variant == Success) {
                
                #line 68 "src/service_libraries/pus_services/pus_service2.fin"
                self->pus_service_1.notify_tm_1_7(__ev,
                                                  self->pus_service_1.__that,
                                                  self->exec_tc_req_status_update.packet_id,
                                                  self->exec_tc_req_status_update.packet_seq_ctrl,
                                                  self->exec_tc_req_status_update.flags_ack,
                                                  &status);

            } else
            {
                
                #line 76 "src/service_libraries/pus_services/pus_service2.fin"
                self->pus_service_1.send_tm_1_8_device_command_exec_error(__ev,
                                                                          self->pus_service_1.__that,
                                                                          self->exec_tc_req_status_update.packet_id,
                                                                          self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                          self->exec_tc_req_status_update.dev_address,
                                                                          &status);

            }

        }

    }

    #line 88 "src/service_libraries/pus_services/pus_service2.fin"
    return status;

}

void PUSService2__exec_tc(const __termina_event_t * const __ev,
                          void * const __this, TCHandler * const tc_handler,
                          __status_int32_t * const action_status) {
    
    #line 123 "src/service_libraries/pus_services/pus_service2.fin"
    PUSService2 * self = (PUSService2 *)__this;

    #line 123 "src/service_libraries/pus_services/pus_service2.fin"
    __termina_lock_t __lock = __termina_resource__lock(&__ev->owner,
                                                       &self->__lock_type);

    #line 125 "src/service_libraries/pus_services/pus_service2.fin"
    __status_int32_t status;
    #line 125 "src/service_libraries/pus_services/pus_service2.fin"
    status.__variant = Success;

    #line 126 "src/service_libraries/pus_services/pus_service2.fin"
    uint8_t subtype = tc_handler->df_header.subtype;

    #line 128 "src/service_libraries/pus_services/pus_service2.fin"
    self->exec_tc_req_status_update.packet_id = tc_handler->packet_header.packet_id;

    #line 129 "src/service_libraries/pus_services/pus_service2.fin"
    self->exec_tc_req_status_update.packet_seq_ctrl = tc_handler->packet_header.packet_seq_ctrl;

    #line 130 "src/service_libraries/pus_services/pus_service2.fin"
    self->exec_tc_req_status_update.flags_ack = tc_handler->df_header.flag_ver_ack;

    #line 131 "src/service_libraries/pus_services/pus_service2.fin"
    self->exec_tc_req_status_update.tc_num_bytes = tc_handler->tc_descriptor.tc_num_bytes;

    #line 133 "src/service_libraries/pus_services/pus_service2.fin"
    status = tc_handler_get_u8_appdata_field(tc_handler,
                                             &self->exec_tc_req_status_update.N);

    #line 135 "src/service_libraries/pus_services/pus_service2.fin"
    if (status.__variant == Success) {
        
        #line 136 "src/service_libraries/pus_services/pus_service2.fin"
        status = tc_handler_get_u32_appdata_field(tc_handler,
                                                  &self->exec_tc_req_status_update.dev_address);

    }

    #line 139 "src/service_libraries/pus_services/pus_service2.fin"
    if (status.__variant == Success) {
        
        #line 141 "src/service_libraries/pus_services/pus_service2.fin"
        if (subtype == 1U) {
            
            #line 143 "src/service_libraries/pus_services/pus_service2.fin"
            status = PUSService2__exec2_1TC(__ev, self);

        } else
        {
            
            #line 147 "src/service_libraries/pus_services/pus_service2.fin"
            status.__variant = Failure;
            #line 147 "src/service_libraries/pus_services/pus_service2.fin"
            status.Failure.__0 = ACCEPTANCE_ERROR;

        }

    }

    #line 154 "src/service_libraries/pus_services/pus_service2.fin"
    if (status.__variant == Success) {
        
        #line 156 "src/service_libraries/pus_services/pus_service2.fin"
        (*action_status).__variant = Success;

    } else
    {
        
        #line 152 "src/service_libraries/pus_services/pus_service2.fin"
        int32_t error_code = status.Failure.__0;

        #line 161 "src/service_libraries/pus_services/pus_service2.fin"
        if (error_code == ACCEPTANCE_ERROR) {
            
            #line 163 "src/service_libraries/pus_services/pus_service2.fin"
            self->pus_service_1.send_tm_1_4_error_in_acceptance(__ev,
                                                                self->pus_service_1.__that,
                                                                self->exec_tc_req_status_update.packet_id,
                                                                self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                action_status);

        } else
        #line 168 "src/service_libraries/pus_services/pus_service2.fin"
        if (error_code == BUILD_TM_ERROR) {
            
            #line 170 "src/service_libraries/pus_services/pus_service2.fin"
            self->pus_service_1.send_tm_1_8_tm_exceed_limit_appdata(__ev,
                                                                    self->pus_service_1.__that,
                                                                    self->exec_tc_req_status_update.packet_id,
                                                                    self->exec_tc_req_status_update.packet_seq_ctrl,
                                                                    action_status);

        } else
        #line 175 "src/service_libraries/pus_services/pus_service2.fin"
        if (error_code == TC_DATA_OUT_OF_RANGE_ERROR) {
            
            #line 177 "src/service_libraries/pus_services/pus_service2.fin"
            self->pus_service_1.send_tm_1_4_short_pack_length(__ev,
                                                              self->pus_service_1.__that,
                                                              self->exec_tc_req_status_update.packet_id,
                                                              self->exec_tc_req_status_update.packet_seq_ctrl,
                                                              self->exec_tc_req_status_update.tc_num_bytes,
                                                              action_status);

        } else
        {
            
            #line 185 "src/service_libraries/pus_services/pus_service2.fin"
            (*action_status).__variant = Failure;
            #line 185 "src/service_libraries/pus_services/pus_service2.fin"
            (*action_status).Failure.__0 = error_code;

        }

    }

    #line 192 "src/service_libraries/pus_services/pus_service2.fin"
    __termina_resource__unlock(&__ev->owner, &self->__lock_type, __lock);

    #line 192 "src/service_libraries/pus_services/pus_service2.fin"
    return;

}
