#ifndef STACK_H
#define STACK_H
#define SIZE 15
typedef int stack_type;
struct stack{
stack_type *data;
int depth;
};
void stack_init(struct stack* stack);
void input_commands();
void stack_push(struct stack* stack, int i);
void stack_add(struct stack* stack);
void stack_print(struct stack* stack);
int stack_test(struct stack* stack);
#endif
