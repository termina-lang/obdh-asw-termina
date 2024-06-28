#ifndef __TASKS__HKFDIRMNG_H__
#define __TASKS__HKFDIRMNG_H__

#include <termina.h>
#include "libraries/pus_services/pus_service3.h"

typedef struct {
    __termina_task_t __task;
    hk_configuration hk_config_table[max_num_of_SIDs];
} HK_FDIR_MNG;

void HK_FDIR_MNG__trial(void * const __this, uint16_t data, Result * result);

#endif
