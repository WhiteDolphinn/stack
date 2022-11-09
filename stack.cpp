#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <execinfo.h>
#define stack_check(STRUCT) \
do\
{\
struct error err = stack_test(STRUCT);\
\
        if(err.code != 0)\
        {\
            \
            stack_dump(stack, __FILE__, __LINE__, __func__);\
            printf("Error!!!\n %s\n Code: %d\n", err.name, err.code);\
            assert(0);\
        }\
} while (0)

void stack_init(struct stack* stack)
{
    stack -> data = (element_t*)calloc(SIZE, sizeof(element_t));
    for(int i = 0; i < SIZE; i++)
        stack -> data[i] = POISON;
    stack -> depth = 0;

    stack_check(stack);
}

void stack_delete(struct stack* stack)
{
    stack -> depth = -1;
    free(stack -> data);
}

void input_commands()
{
    const char* push = "push";
    char command[30];
    scanf("%s", command); // строки нельзя просто так сравнивать
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

struct error stack_test(struct stack* stack)
{

    static struct error error[NUM_OF_ERRORS];
    error[0] = {.name = "OK", .code = 0};
    error[1] = {.name = "ERR_DATA", .code = 1};
    error[2] = {.name = "ERR_DEPTH", .code = 2};

     if(stack -> depth >= SIZE)
        return error[2];

    if(stack -> depth < 0)
        return error[2];

    if(stack -> data == nullptr)
        return error[1];



    return error[0];
}

/*void stack_check(struct stack* stack)
{
    struct error error = stack_test(stack);

        if(error.code != 0)
        {
            printf("Error!!!\n %s\n Code: %d\n", error.name, error.code);
            stack_dump();
            assert(0);
        }
}*/
