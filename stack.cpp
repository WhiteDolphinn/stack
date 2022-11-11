#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <execinfo.h>
#define stack_check(STRUCT) \
do\
{\
        if(stack_test(STRUCT))\
        {\
            stack_dump(stack, __FILE__, __LINE__, __func__);\
            print_errors(stack_test(STRUCT));\
            assert(0);\
        }\
} while (0)

void stack_init(struct stack* stack)
{
    stack -> data = (element_t*)calloc(SIZE, sizeof(element_t));

    for(int i = 0; i < SIZE; i++)
        stack -> data[i] = POISON;

    stack -> depth = 0;
    stack -> is_init = 1;

    stack_check(stack);
}

void stack_delete(struct stack* stack)
{
    stack -> depth = -1;
    stack -> is_init = 0;
    free(stack -> data);
}

void input_commands()
{
    const char* push = "push";
    char command[30];
    scanf("%s", command);
}

void stack_push(struct stack* stack, element_t i, int *error)
{
    stack_check(stack);
    stack -> data[stack -> depth] = i;
    stack -> depth++;
    stack_check(stack);
}

element_t stack_pop(struct stack* stack)
{
    stack_check(stack);
    element_t last_element = stack -> data[stack -> depth - 1];
    stack->data[stack->depth - 1] = POISON;
    stack -> depth--;
    stack_check(stack);
    return last_element;
}

void stack_add(struct stack* stack)
{
    stack_check(stack);
    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y + x);
    stack_check(stack);
}

void stack_sub(struct stack* stack)
{
    stack_check(stack);
    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y - x);
    stack_check(stack);
}

void stack_mul(struct stack* stack)
{
    stack_check(stack);
    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y * x);
    stack_check(stack);
}

void stack_div(struct stack* stack)
{
    stack_check(stack);
    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y / x);
    stack_check(stack);
}

void stack_print(struct stack* stack)
{
    printf("\033[34m");
    printf("========================\n");
    for(int i = 0; i < SIZE; i++)
    {
        if(stack->data[i] != POISON)
            printf("%d:  %d\n", i, stack -> data[i]);
        else
            printf("%d: %X\n", i, stack->data[i]);
    }
    printf("========================\n");
    printf("\033[0m");
}

void stack_dump(struct stack* stack, const char* file, int line, const char* function)
{
    stack_print(stack);


    void* arr[10];
    size_t size = backtrace(arr, 10);
    char** logs = (char**)calloc(size, sizeof(char*));

    logs = backtrace_symbols(arr, size);
    printf("\033[31m");
    for(size_t i = 0; i < size; i++)
        printf("%s\n", logs[i]);

    printf("\033[0m");

    printf("File: %s\nLine: %d\nFunction: %s\n", file, line, function);
    free(logs);
}

int stack_test(struct stack* stack)
{
    int error = 0;
   // int is_any_error = 0;

    if(stack -> data == nullptr)
        error |= (0x01 << 0);

    if(stack -> depth >= SIZE || stack->depth < 0)
        error |= (0x01 << 1);

    if(stack -> is_init == 0)
        error |= (0x01 << 2);

    return error;
}

void print_errors(int error)
{
  static struct error errors[NUM_OF_ERRORS];
    errors[0] = {.name = "OK", .code = 0};
    errors[1] = {.name = "ERR_DATA", .code = 1};
    errors[2] = {.name = "ERR_DEPTH", .code = 2};
    errors[3] = {.name = "ERR_INIT", .code = 3};

    for(int i = 1; i <= NUM_OF_ERRORS; i++)
    {
        if((error | 1) == error)
        {
            printf("\033[33mError!!!\t %s\t Code: %d\033[0m\n", errors[i].name, i);
        }
        error = error >> 1;
    }
}
