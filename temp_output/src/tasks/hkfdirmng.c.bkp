
#include "tasks/hkfdirmng.h"

void HK_FDIR_MNG__trial(void * const __this, uint16_t data, Result * result) {
    
    HK_FDIR_MNG * self = (HK_FDIR_MNG *)__this;

    __termina_resource__lock(&self->__resource);

    (*result).__variant = Result__Error;

    if (data == self->hk_config_table[0].interval) {
        
        (*result).__variant = Result__Ok;

    }

    __termina_resource__unlock(&self->__resource);

    return;

}
