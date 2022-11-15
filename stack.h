#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define PRINT_IN_CONSOLE 1
//#define SIZE 15
#define POISON 0xDED32DED

typedef int element_t;

struct stack{
element_t *data;
int depth;
char is_init;
int size;
char is_resized;
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
void stack_print(FILE* file, struct stack* stack);
void stack_dump(FILE* file, struct stack* stack, const char* filename, int line, const char* function);

void stack_resize(struct stack* stack);
FILE* get_log_file();

#endif
