#ifndef __OPTION_H__
#define __OPTION_H__

#include <termina.h>

typedef struct {
    uint8_t __0;
} __option_uint8__Some_params_t;

typedef struct {
    __option_uint8__Some_params_t Some;
    __enum_option_t __variant;
} __option_uint8_t;

typedef struct {
    size_t __0;
} __option_size__Some_params_t;

typedef struct {
    __option_size__Some_params_t Some;
    __enum_option_t __variant;
} __option_size_t;

#endif
