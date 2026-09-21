#ifndef OPTION_H__
#define OPTION_H__

#include <termina.h>

typedef struct {
    uint8_t _0;
} termina__enum__Option__u8__Some_params_t;

typedef struct {
    termina__enum__Option__u8__Some_params_t Some;
    termina__enum__Option_t _variant;
} Option__u8;

typedef struct {
    size_t _0;
} termina__enum__Option__usize__Some_params_t;

typedef struct {
    termina__enum__Option__usize__Some_params_t Some;
    termina__enum__Option_t _variant;
} Option__usize;

#endif
