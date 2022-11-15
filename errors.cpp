#include "errors.h"

int stack_test(struct stack* stack)
{
    int error = 0;
   // int is_any_error = 0;

    if(stack -> data == nullptr)     //ERR_DATA
        error |= (0x01 << 0);

    if(stack -> depth >= stack->size || stack->depth < 0)          //ERR_DEPTH
        error |= (0x01 << 1);

    if(stack -> is_init == 0)               //ERR_INIT
        error |= (0x01 << 2);

    if(stack->is_resized == 1)           //ERR_RESIZE
        error |= (0x01 << 3);

    return error;
}

void print_errors(FILE* file, int error)
{
  static struct error errors[NUM_OF_ERRORS];
    errors[0] = {.name = "OK", .code = 0};
    errors[1] = {.name = "ERR_DATA", .code = 1};
    errors[2] = {.name = "ERR_DEPTH", .code = 2};
    errors[3] = {.name = "ERR_INIT", .code = 3};
    errors[4] = {.name = "ERR_RESIZE", .code = 4};

    for(int i = 1; i <= NUM_OF_ERRORS; i++)
    {
        if((error | 1) == error)
        {
            fprintf(file, "\033[33mError!!!\t %s\t Code: %d\033[0m\n", errors[i].name, i);
        }
        error = error >> 1;
    }
}

/*void fix_errors(FILE* file, int error)
{
    if(error == 0)
        return void;

    if((error | 1) == error)  //fix ERR_DATA
    {
        fprintf(file, "I can't fix this problem");
        assert(0);
    }
    error = error >> 1;

    if((error | 1) == error)  //fix ERR_DEPTH
    {

    }

}*/