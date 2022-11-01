#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void stack_init(struct stack* stack)
{
    stack -> data = (stack_type*)calloc(SIZE, sizeof(stack_type));
    for(int i = 0; i < SIZE; i++)
        stack -> data[i] = 0;
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

void stack_push(struct stack* stack, stack_type i)
{
    stack_check(stack);
    stack -> data[stack -> depth] = i;
    stack -> depth++;
    stack_check(stack);
}

void stack_add(struct stack* stack)
{
    stack_check(stack);
    stack -> data[stack -> depth - 2] += stack -> data[stack -> depth - 1];
    stack -> depth--;
    stack_check(stack);
}

void stack_print(struct stack* stack)
{
    printf("========================\n");
    for(int i = 0; i < stack -> depth; i++)
    {

        printf("%d:  %d\n", i, stack -> data[i]);
    }
    printf("========================\n");
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
        return error[1];

    return error[0];
}

void stack_check(struct stack* stack)
{
    struct error error = stack_test(stack);

        if(error.code != 0)
        {
            printf("Error!!!\n %s\n Code: %d", error.name, error.code);
            assert(0);
        }
}
