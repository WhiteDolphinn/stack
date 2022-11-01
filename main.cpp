#include "stack.h"
#include <stdio.h>
#include <malloc.h>

int main()
{
  	struct stack stack;
	stack_init(&stack);
    stack_push(&stack, 3);
    stack_push(&stack, 4);
	stack_push(&stack, 5);
	int i = stack_pop(&stack);
    stack_print(&stack);
	printf("%d\n", i);

    return 0;
}
