#ifndef STACK_CHECK_H
#define STACK_CHECK_H
#include "stack.h"
#include "errors.h"
//#include <assert.h>

#define stack_check(STRUCT) \
do\
{\
    FILE* file = get_log_file();\
    if(stack->data != nullptr)\
        stack_dump(file, stack, __FILE__, __LINE__, __func__);\
    if(stack_test(STRUCT))\
    {\
        FILE* file = get_log_file();\
        /*if(stack->data != nullptr)\
            stack_dump(file, stack, __FILE__, __LINE__, __func__);*/\
        int error = stack_test(STRUCT);\
        print_errors(file, error);\
        }\
    fclose(file);\
} while (0)

#endif
