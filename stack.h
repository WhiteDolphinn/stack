#ifndef STACK_H
#define STACK_H
#define SIZE 15
#define NUM_OF_ERRORS 10
#define POISON 0xDED32DED

struct error{

char name[50];
unsigned int code;

};

typedef int element_t;

struct stack{
element_t *data;
int depth;
};

void stack_init(struct stack* stack);
void stack_delete(struct stack* stack);
void input_commands();
void stack_push(struct stack* stack, element_t i, int *error = nullptr);
element_t stack_pop(struct stack* stack);
void stack_add(struct stack* stack);
void stack_sub(struct stack* stack);
void stack_mul(struct stack* stack);
void stack_div(struct stack* stack);
void stack_print(struct stack* stack);
void stack_dump(struct stack* stack, const char* file, int line, const char* function);
struct error stack_test(struct stack* stack);
//void stack_check(struct stack* stack);
#endif
