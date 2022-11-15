#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define SIZE 15
#define NUM_OF_ERRORS 10
#define POISON 0xDED32DED

struct error{

char name[50];
unsigned int code;
//char is_error;
};

typedef int element_t;

struct stack{
element_t *data;
int depth;
char is_init;
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
int stack_test(struct stack* stack);
void print_errors(FILE* file, int error);

FILE* get_log_file();

#endif
