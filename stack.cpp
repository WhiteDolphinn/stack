#include "stack.h"
#include "errors.h"
#include "stack_check.h"
#include "log.h"
#include <stdio.h>
#include <malloc.h>
//#include <assert.h>
#include <execinfo.h>
#include <time.h>


void stack_init(struct stack* stack)
{
    stack->size = 10;
    stack->data = (element_t*)calloc(stack->size, sizeof(element_t));

    for(int i = 0; i < stack->size; i++)
        stack -> data[i] = POISON;

    stack->depth = 0;
    stack->error = 0;
    stack->is_init = 1;
    stack->is_resized = 0;

    stack_check(stack);
}

void stack_delete(struct stack* stack)
{
    fprintf(get_log_file(), "Stack was deleted!!!");
    stack_check(stack);
    stack->depth = -1;
    stack->size = 0;
    stack->error = 0;
    stack->is_init = 0;
    free(stack->data);
    stack->data = 0;
}

/*void input_commands()
{
    const char* push = "push";
    char command[30] = "";
    scanf("%s", command);
}*/

void stack_push(struct stack* stack, element_t i)
{
    stack_check(stack);
    if(is_error(stack, __func__))
        return;

    stack -> data[stack -> depth] = i;
    stack -> depth++;

    if(stack->depth + 3 == stack->size)
        stack_resize(stack, 5);

    stack_check(stack);
}

element_t stack_pop(struct stack* stack)
{
    stack_check(stack);
    if(is_error(stack, __func__))
        return POISON;

    element_t last_element = stack -> data[stack -> depth - 1];
    stack->data[stack->depth - 1] = POISON;
    stack -> depth--;
    /*if(stack->size - stack->depth == 10)
    {
        stack->size -= 5;
        stack_resize(stack);
    }*/
        stack_check(stack);
    return last_element;
}

void stack_print(FILE* file, struct stack* stack)
{
    fprintf(file, "\033[34m");
    fprintf(file, "========================\n");
    for(int i = 0; i < stack->size; i++)
    {
        if(stack->data[i] != POISON)
            fprintf(file, "%d:  %d\n", i, stack -> data[i]);
        else
            fprintf(file, "%d: %X\n", i, stack->data[i]);
    }
    fprintf(file, "========================\n\n");
    fprintf(file, "\033[0m");
}

void stack_dump(
                FILE* file,
                struct stack* stack,
                const char* filename,
                int line,
                const char* function
                )
{
    stack_print(file, stack);

    void* arr[10] = {0};
    size_t size = backtrace(arr, 10);
   // char** logs = (char**)calloc(size, sizeof(char*));

    char** logs = backtrace_symbols(arr, size);
    fprintf(file, "\033[31m");
    for(size_t i = 0; i < size; i++)
        fprintf(file, "%s\n", logs[i]);



    fprintf(file, "\n\033[0m");

    fprintf(file, "File: %s\nLine: %d\nFunction: %s\n\n", filename, line, function);
    free(logs);
}

void stack_resize(struct stack* stack, int extra_mem)
{
    stack->is_resized = 1;
   // printf("%d", stack->size);
    stack->data = (element_t*)realloc(stack->data, (stack->size + extra_mem) * sizeof(element_t));

    for(int i = 0; i < extra_mem; i++)
        stack->data[stack->size + i] = POISON;

    stack->size += extra_mem;

    if(stack->data != nullptr)
        stack->is_resized = 0;
}
