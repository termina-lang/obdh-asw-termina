# Siguiendo las recomendaciones de Óscar

## Cambio en el paradigma de programación - PS12

<img src="images/diagrama.png" alt="Diagrama de estados - PlantUML" width="1000"/>




```
procedure do_monitoring (&mut self, PMONID: u16, … ) {
    for i = 0 in 6 while status !Exit{
        match status {
            case Init=> {
                self->init_do_monitoring(); //method: store the variables needed for the monitoring --> PMONID, fault_info, EvID
            }
            case check_PMONID => {

                //choice point
                if (self->is_valid_PMONID(); //viewer) {
                    self->manage_interval_control(); //method 
                } else {
                    self->state = Exit;
                }
            }
            
            case do_monitoring => {
               
               //choice point
               if(self->is_limits_monitoring) {

                    self->state = do_limits_monitoring;

               } else if (self->is_expected_value_monitoring) {

                  self->state = do_expected_value_monitoring;

               }
               else {
                 self->state = exit;
               }
            } 
            case do_limits_monitoring =>{
                self->PID_status(); //method
                match limits_monitoring_status =>{
                    case out_of_high_limit(){
                        fault_info = self->manage_out_of_hl_state(); //method
                    }
                    case out_of_low_limit(){

                        fault_info = self->manage_out_of_ll_state(); //method

                    }
                    case within_limits() {

                        fault_info = self->manage_within_limits(); //method
                    }

                }
                    
            }
            case do_expected_value_montoring => {

                self->PID_status(); //method
                match exp_value_monitoring_status =>{
                    case unexpected{
                        fault_info = self->manage_unexpected(); //method
                    }
                    case expected{

                        fault_info = self->expected(); //method

                    }
                    

                }
            }
        }
    }

    return;
}
```
