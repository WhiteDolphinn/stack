#include "stek.h"
#include <stdio.h>
#include <malloc.h>

int main()
{
    struct stek stek = stek_start();

    char* command = (char*)calloc(30, sizeof(char));

    input_commands();
  /*  stek_push(&stek, 3);
    stek_push(&stek, 4);
    stek_print(&stek);*/

    return 0;
}
