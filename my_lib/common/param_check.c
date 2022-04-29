#include "param_check.h"
#include "stdio.h"


void assert_failed(uint8_t* file_name, uint32_t line_num) {
    printf("Error at %s, line %d", file_name, line_num);
    while(1){}
}