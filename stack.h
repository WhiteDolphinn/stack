#ifndef STACK_H
#define STACK_H
#define SIZE 15
#define NUM_OF_ERRORS 10

struct error{

char name[50];
unsigned int code;

};

typedef int stack_type;

struct stack{
stack_type *data;
int depth;
};

void stack_init(struct stack* stack);
void stack_delete(struct stack* stack);
void input_commands();
void stack_push(struct stack* stack, stack_type i);
stack_type stack_pop(struct stack* stack);
void stack_add(struct stack* stack);
void stack_print(struct stack* stack);
struct error stack_test(struct stack* stack);
void stack_check(struct stack* stack);
#endif
