#ifndef PARAM_CHECK_H
#define PARAM_CHECK_H


#include "stdint.h"
#include "limits.h"


/*
    Note. (void)0 prevents itself to be rvalue
*/
#define assert_param(expr) (expr)? (void)0 : assert_failed((uint8_t*) __FILE__, __LINE__)

void assert_failed(uint8_t* file_name, uint32_t line_num);

#endif









