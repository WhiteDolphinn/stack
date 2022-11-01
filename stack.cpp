#include "stack.h"
#include <stdio.h>
#include <malloc.h>

void stack_start(struct stack* stack)
{
    stack -> data = (stack_type*)calloc(SIZE, sizeof(stack_type));
    for(int i = 0; i < SIZE; i++)
        stack -> data[i] = 0;
    stack -> depth = 0;
}

void input_commands()
{
    const char* push = "push";
    char command[30];
    scanf("%s", command); // строки нельзя просто так сравнивать
}

void stack_push(struct stack* stack, int i)
{
    stack -> data[stack -> depth] = i;
    stack -> depth++;
}

void stack_add(struct stack* stack)
{
    stack -> data[stack -> depth - 2] += stack -> data[stack -> depth - 1];
    stack -> depth--;
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

int stack_test(struct stack* stack)
{
    if(stack -> depth < 0)
        return 0;

    if(stack -> depth >= SIZE)
        return 0;

    return 1;
}
