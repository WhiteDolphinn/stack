#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define PRINT_IN_CONSOLE 0
//#define SIZE 15
#define POISON 0xDED32DED

typedef int element_t;

struct stack{
element_t *data;
int depth;
int size;
int error;
char is_init;
char is_resized;
};

void stack_init(struct stack* stack);
void stack_delete(struct stack* stack);
void input_commands();
void stack_push(struct stack* stack, element_t i);
element_t stack_pop(struct stack* stack);
void stack_print(FILE* file, struct stack* stack);
void stack_dump(FILE* file, struct stack* stack, const char* filename, int line, const char* function);

void stack_resize(struct stack* stack);
FILE* get_log_file();

#endif
