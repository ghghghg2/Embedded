#ifndef PUBLIC_H
#define PUBLIC_H


#include "stdint.h"
#include "param_check.h"

#define DEBUG


#ifndef DEBUG
#define check_type(type, val) (void)0
#else
/*
    @brief If val is not the type, compiler will pop up a warning or error.
*/
#define check_type(type, val) do { \
    typedef void (*type_func_t)(type); \
    type_func_t dummy_func = (type_func_t)0; \
    if(0) dummy_func(val);\
} while(0)

#endif


#endif