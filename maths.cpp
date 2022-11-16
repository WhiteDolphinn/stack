#include "maths.h"
#include "stack.h"
#include "errors.h"
#include "stack_check.h"
#include "log.h"


void stack_add(struct stack* stack)
{
    stack_check(stack);
    if(is_error(stack, __func__))
        return;

    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y + x);

    stack_check(stack);
}

void stack_sub(struct stack* stack)
{
    stack_check(stack);
    if(is_error(stack, __func__))
        return;

    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y - x);

    stack_check(stack);
}

void stack_mul(struct stack* stack)
{
    stack_check(stack);
    if(is_error(stack, __func__))
        return;

    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y * x);

    stack_check(stack);
}

void stack_div(struct stack* stack)
{
    stack_check(stack);
    if(is_error(stack, __func__))
        return;

    int x = stack_pop(stack);
    int y = stack_pop(stack);
    stack_push(stack, y / x);

    stack_check(stack);
}
